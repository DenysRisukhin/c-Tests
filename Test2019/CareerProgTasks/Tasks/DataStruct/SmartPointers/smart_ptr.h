//
//  smart_ptr.h
//  Test2019
//
//  Created by Denys Risukhin on 7/1/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef smart_ptr_h
#define smart_ptr_h

// simple shared_ptr

template<class T>
class shared_ptr
{
public:
    
    // c-tor
    // задать T* m_ptr и инициализировать счетчик ссылок в 1
    explicit shared_ptr(T* ref)
    {
        m_ref = ref;
        m_refCount = new unsigned();
        *m_refCount = 1;
    }
    
    // c-tor
    // Создает новый умный указатель для существующего объекта
    // 1) Сначала присваиваем m_ptr и m_refCount указателя на
    // m_ptr и m_refCount ptr
    // 2) Затем т к создается новая ссылка на m_ptr нужно увеличить m_refCount
    shared_ptr(shared_ptr<T>& ref)
    {
        m_ref = ref.m_ref;
        m_refCount = ref.m_refCount;
        ++(*m_refCount);
    }
    
    // copy c-tor
//    shared_ptr(const shared_ptr<T>& ref)
//    {
//        m_ref = ref.m_ref;
//        m_refCount = ref.m_refCount;
//        ++(*m_refCount);
//    }
    
    // ссылки могут создаваться присваиванием объекту SmartPointer другого объекта smartPointer
    // если ptr имеет существующее значение, уменьшить счетчик ссылок
    // затем скопировать указатель на m_refCount и m_ptr
    // увеличить m_refCount т к мы создали новую ссылку
    
    // при присваивании одного смарта другому должно происходить обновление счетчика ссылок
    // старого указателя
    shared_ptr<T>& operator=(const shared_ptr<T>& ref) {
        if (this == &ref) {
            return* this;
        }
        
        // если счетчик сылок положителен, удалить одну ссылку
        if (*m_refCount > 0) {
            remove();
        }
        
        m_ref = ref.m_ref;
        m_refCount = ref.m_refCount;
        
        ++(*m_refCount);
        
        return *this;
    }
    
    // уничтожение ссылки на объект
    // уменьшение m_refCount
    // если m_refCount = 0 освободить память и уничтожить объект
    ~shared_ptr() {
        remove(); // удалить одну ссылку на объект
    }
    
    T getValue() { return* m_ref; }
    
    T* operator->() { return m_ref; }
    T& operator*() { return* m_ref; }
    
    bool operator == (const shared_ptr <T>& p) { return m_ref == p.m_ref; }
    bool operator != (const shared_ptr <T>& p) { return m_ref!= p.m_ref; }
    
    
protected:
    void remove() {
        --(*m_refCount);
        
        if (*m_refCount == 0) {
            delete m_ref;
            delete m_refCount;
            
            m_ref = nullptr;
            m_refCount = nullptr;
        }
    }
    
    // Оба должны быть указателями, т к суть smart_ponter
    // закл в использовании счетчика ссылок в нескольких экземплярах смарт поинтера на один объект
    
    // указатель на объект
    T* m_ref = nullptr;
    
    // указатель на счетчик
    unsigned* m_refCount = nullptr;
};


#endif /* smart_ptr_h */
