//
//  weak_ptr.h
//  Test2019
//
//  Created by Denys Risukhin on 9/4/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef weak_ptr_h
#define weak_ptr_h

//#include "shared_ptr.h"
#include "memory.h"

// std::atomic - позволяет определить переменную с которой операции будут атомарные
// определен только для целочисленных всторенных типов
// std::atomic если один поток записывает на атомный объект, а другой поток читает его, поведение определено корректно.

// std:: atomic - Извлекает значение из объекта.

#pragma once - link counter

//В объект счётчика ссылок добавляется счётчик слабых ссылок. weak_ptr увеличивает этот счётчик при создании и копировании. При этом объект счётчика ссылок не удаляется до тех пор, пока есть хотя бы один shared_ptr или один weak_ptr, т.к. weak_ptr необходимо обращаться к счётчику ссылок даже если нет ни одного живого shared_ptr. Но сам объект, на который указывает shared_ptr, может быть удалён, если больше не осталось живых shared_ptr.

//Вопрос: почему вызов add_ref_lock безопасен? Ведь в другом потоке shared_ptr в деструкторе может удалить объект sp_counted, и обращение к переменной shared_count будет некорректным.
//Ответ: потому что деструктор shared_ptr не удалит объект sp_counted, т.к. есть живая слабая ссылка (weak_count != 0).

template <typename T>
class ref_count {
public:
    explicit ref_count(T *p) noexcept
    : m_shared_count(1),
    m_weak_count(1),
    m_ptr(p) {}
    
    void add_ref() noexcept {
        ++m_shared_count;
    }
    
    void release() noexcept {
        if (!--m_shared_count) {
            // Если последний shared_ptr удалился, удаляем объект
            delete m_ptr;
            if (!--m_weak_count) {
                // Если нет слабых ссылок, удаляем объект счётчика
                destroy();
            }
        }
    }
    
    void add_ref_weak() noexcept {
        ++m_weak_count;
    }
    
    void release_weak() noexcept {
        if (!--m_weak_count) {
            // Если последний weak_ptr удалился, удаляем объект счётчика.
            // Т.к. shared_ptr тоже увеличивает m_weak_count при создании,
            // нет необходимости проверять значение m_shared_count
            destroy();
        }
    }
    
    size_t use_count() const noexcept {
        return m_shared_count.load();
    }
    
    // Попытка увеличить счётчик shared_count из weak_ptr
    // Потокобезопасен, lock-free
    void add_ref_lock() {
        // Сохраняем текущее значение shared_count
        size_t cur_value(m_shared_count.load());
        do {
            // Если счётчик сильных ссылок равен нулю (т.е. нет больше живых shared_ptr),
            // то новый shared_ptr создавать не из чего.
            if (!cur_value) {
                throw std::bad_weak_ptr();
            }
            // Пытаемся увеличить счётчик shared_count на единицу
            // Если в промежутке между сохранением m_shared_count в cur_value, shared_count изменился,
            // то операция compare_exchange_weak вернёт false, запишет новое значение shared_count в cur_value,
            // и цикл повторится
        } while (m_shared_count.compare_exchange_weak(cur_value, cur_value + 1));
    }
    
private:
    // Счётчик ссылок shared_ptr
    std::atomic<size_t> m_shared_count;
    // Счётчик ссылок weak_ptr
    std::atomic<size_t> m_weak_count;
    
    T* m_ptr;
    
    void destroy() noexcept {
        delete this;
    }
};

#pragma once - weak_ptr

template <typename T>
class weak_ptr {
public:
    weak_ptr() noexcept : m_ptr(nullptr), m_counted(nullptr) {}
    
    weak_ptr(const weak_ptr& other) noexcept : m_ptr(other.m_ptr), m_counted(other.m_counted) {
        add_ref_weak();
    }
    
    weak_ptr(const shared_ptr<T>& p) noexcept : m_ptr(p.m_ptr), m_counted(p.m_counted) {
        add_ref_weak();
    }
    
    weak_ptr& operator=(const weak_ptr& other) noexcept {
        release_weak();
        
        m_ptr = other.m_ptr;
        m_counted = other.m_counted;
        
        add_ref_weak();
        
        return *this;
    }
    
    weak_ptr& operator=(const shared_ptr<T>& p) {
        release_weak();
        
        m_ptr = p.ptr;
        m_counted = p.m_counted;
        
        add_ref_weak();
        
        return *this;
    }
    
    // Пытаемся сделать shared_ptr. Для этого вызывается конструктор shared_ptr(const weak_ptr &amp)
    // В случае невозможности создать shared_ptr возвращается пустой объект
    shared_ptr<T> lock() noexcept {
        try {
            return shared_ptr<T>(*this);
        } catch (const std::bad_weak_ptr &) {
            return shared_ptr<T>();
        }
    }
    
    size_t use_count() const noexcept {
        return m_counted != nullptr ? m_counted->use_count() : 0;
        }
        
private:
    friend class shared_ptr<T>;
        
    T* m_ptr = nullptr;
    ref_count<T>* m_counted = nullptr;
        
    void add_ref_weak() noexcept {
        if (m_counted) {
            m_counted->add_ref_weak();
        }
    }
        
    void release_weak() noexcept {
        if (m_counted) {
            m_counted->release_weak();
        }
    }
};

    
#programe mark - shared_ptr
    
// В код shared_ptr добавляется конструктор shared_ptr(const weak_ptr &p):
    template <typename T>
    class weak_ptr;
    
    template <typename T>
    class shared_ptr {
        friend class weak_ptr<T>;
    public:
        shared_ptr() noexcept : ptr(nullptr), counted(nullptr) {}
        
        // excaption safe конструктор
        explicit shared_ptr(T *p) {
            std::unique_ptr<T> holder(p);
            // new может кинуть исключение, и если p не передать в unique_ptr,
            // память под p потеряется
            counted = new sp_counted<T>(holder.get());
            ptr = holder.release();
        }
        
        ~shared_ptr() noexcept {
            release();
        }
        
        shared_ptr(const shared_ptr<T> &other) noexcept : ptr(other.ptr), counted(other.counted) {
            add_ref();
        }
        
        shared_ptr(const weak_ptr<T> &p) : ptr(p.ptr), counted(p.counted) {
            if (counted) {
                // Пытаемся увеличить счётчик ссылок объекта
                // В случае неудачи сгенерируется исключение std::bad_weak_ptr()
                counted->add_ref_lock();
            } else {
                throw std::bad_weak_ptr();
            }
        }
        
        shared_ptr &operator=(const shared_ptr<T> &other) noexcept {
            // Освобождаем владение предыдущим указателем
            release();
            
            // Выполняем присваивание
            ptr = other.ptr;
            counted = other.counted;
            
            // Устанавливаем владение новым указателем
            add_ref();
            
            // Ура! Я не забыл вернуть *this!
            return *this;
        }
        
        T *get() const noexcept {
            return ptr;
        }
        
        size_t use_count() const noexcept {
            return counted != nullptr ? counted->use_count() : 0;
        }
        
    private:
        void add_ref() noexcept {
            if (counted) {
                counted->add_ref();
            }
        }
        
        void release() noexcept {
            if (counted) {
                counted->release();
            }
        }
        
    private:
        T *ptr;
        ref_count<T> *counted;
    };
    
#endif /* weak_ptr_h */
