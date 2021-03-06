//
//  shared_ptr.h
//  Test2019
//
//  Created by Denys Risukhin on 6/27/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef shared_ptr_h
#define shared_ptr_h

#pragma mark - reference counter

template <typename T>
class ref_count {
public:
    explicit ref_count(T *ref) noexcept : m_count(1), m_ptr(ref) {}
    
    void add_ref() noexcept {
        ++m_count;
    }
    
    void release() noexcept {
        --m_count;
        
        if (m_count == 0) {
            delete m_ptr;
            delete this;
        }
    }
    
    size_t use_count() const noexcept {
        return m_count.load();
    }
    
private:
    std::atomic<size_t> m_count;
    T* m_ptr = nullptr;
};

#pragma mark - shared_ptr

// m_refCount - это и есть тот указатель который мы создаем в динамич памяти
// из переданного в конструктор указателя

// m_ptr - указывает на ту же область памяти что и переданный в конструктор указатель

template <typename T>
class shared_ptr {
public:
    
    // c-tor by default
    shared_ptr() noexcept : m_ptr(nullptr), m_refCount(nullptr) {}
    
    // exception safe c-tor
    // задать T* m_ptr
    // задать ref_count<T>* m_refCount для инициализировать счетчика ссылок в 1
    
    // get() - возвр указатель в сыром виде
    // reset() - указатель становится пустым и затирает данные на которые он указывает
    // release() - указатель становится пустым, но данные не затираются и остаются в памяти
    
    explicit shared_ptr(T *ref) {
        std::unique_ptr<T> holder(ref);
        // new может кинуть исключение, и, если p не передать в unique_ptr,
        // память под p потеряется
        m_refCount = new ref_count<T>(holder.get());
        m_ptr = holder.release();
    }
    
    // d-tor
    // уничтожение ссылки на объект
    // уменьшение m_refCount
    // если m_refCount = 0 освободить память и уничтожить объект
    ~shared_ptr() noexcept {
        release();
    }
    
    // copy c-tor
    shared_ptr(const shared_ptr<T>& ref) noexcept: m_ptr(ref.m_ptr), m_refCount(ref.m_refCount) {
        add_ref();
    }
    
    // c-tor moving
    shared_ptr(T&& ref) noexcept: m_ptr(ref.m_ptr), m_refCount(ref.m_refCount) {
        ref.m_ptr = nullptr;
        ref.m_refCount = nullptr;
        
        add_ref();
    }
    
    // ссылки могут создаваться присваиванием объекту smartPointer другого объекта smartPointer
    // 1. если "other" имеет существующее значение, уменьшить счетчик ссылок
    // 2. скопировать указатель на m_refCount и m_ptr
    // 3. увеличить m_refCount т к мы создали новую ссылку
    
    // при присваивании одного смарта другому должно происходить обновление счетчика ссылок
    // старого указателя
    shared_ptr<T>& operator=(const shared_ptr<T>& ref) noexcept {
        if (this == &ref) {
            return* this;
        }
        
        // Освобождаем владение предыдущим указателем
        release();
        
        // Выполняем присваивание
        m_ptr = ref.m_ptr;
        m_refCount = ref.m_refCount;
        
        // Устанавливаем владение новым указателем
        add_ref();
        
        // Ура! Я не забыл вернуть *this!
        return *this;
    }
    
    // shifting operator=
    shared_ptr<T>& operator=(shared_ptr<T>&& ref) noexcept {
        if (this == &ref) {
            return* this;
        }
        
        // Освобождаем владение предыдущим указателем
        release();
        
        m_ptr = ref.m_ptr;
        m_refCount = ref.m_refCount;
        
        ref.m_ptr = nullptr;
        ref.m_refCount = nullptr;
        
        // Устанавливаем владение новым указателем
        add_ref();
        
        return *this;
    }
    
    // standart stuff
    T* get() const noexcept {
        return m_ptr;
    }
    
    size_t use_count() const noexcept {
        return m_refCount != nullptr ? m_refCount->use_count() : 0;
    }
        
    bool operator!=(T* ref) const {
        return m_ptr != ref;
    }
    
    bool operator==(T* ref) const {
        return m_ptr == ref;
    }
        
    operator bool() const {
        return m_ptr != nullptr;
    }
    
    private:
        // Оба должны быть указателями, т к суть smart_ponter
        // закл в использовании счетчика ссылок в нескольких экземплярах смарт поинтера на один объект
        
        // указатель на объект
        T* m_ptr = nullptr;
        // указатель на счетчик
        ref_count<T>* m_refCount = nullptr;
        
        // если счетчик сылок положителен, добавить одну ссылку
        void add_ref() {
            if (m_refCount) {
                m_refCount->add_ref();
            }
        }
        
        // если счетчик сылок положителен, удалить одну ссылку
        void release() {
            if (m_refCount) {
                m_refCount->release();
            }
        }
    };

#endif /* shared_ptr_h */
    
//  tests for own shared_pointer

//struct MediaAsset
//{
//    virtual ~MediaAsset() = default; // make it polymorphic
//};
//
//struct Song : public MediaAsset
//{
//    Song(const std::wstring& artist_, const std::wstring& title_)
//    : artist{ artist_ }, title{ title_ } {}
//
//    std::wstring artist;
//    std::wstring title;
//};
//
//struct Photo : public MediaAsset
//{
//    Photo(const std::wstring& date_,
//          const std::wstring& location_,
//          const std::wstring& subject_)
//    : date{ date_ }, location{ location_ }, subject{ subject_ } {}
//
//    std::wstring date;
//    std::wstring location;
//    std::wstring subject;
//};

// main

//    shared_ptr<int> p1;
//    shared_ptr<int> p2 (nullptr);
//    shared_ptr<C> p4 (new C);
//    shared_ptr<int> p3 (new int);
//    shared_ptr<int> p6 (p3);
//    shared_ptr<int> p7 (std::move(p6));
//
//
//
//    std::cout << "use_count:\n";
//    std::cout << "p1: " << p1.use_count() << '\n';
//    std::cout << "p2: " << p2.use_count() << '\n';
//    std::cout << "p3: " << p3.use_count() << '\n';
//    std::cout << "p4: " << p4.use_count() << '\n';
//    std::cout << "p6: " << p6.use_count() << '\n';
//    std::cout << "p7: " << p7.use_count() << '\n';
//
    
//  tests for stl shared_pointer
    
//    //    Указатели shared_ptr также полезны при использовании алгоритмов копирования элементов в контейнеры стандартной библиотеки C++. Элемент можно заключить в указатель shared_ptr, а затем копировать его в другие контейнеры, учитывая при этом, что выделенная область памяти доступна только до тех пор, пока она требуется. В приведенном ниже примере показано, как использовать алгоритм remove_copy_if применительно к экземплярам shared_ptr в векторе.
//
//    std::vector<shared_ptr<Song>> v;
//
//    v.push_back(shared_ptr<Song>(new Song(L"Bob Dylan", L"The Times They Are A Changing")));
//    v.push_back(shared_ptr<Song>(new Song(L"Penaz Masani", L"Tu Dil De De")));
//    v.push_back(shared_ptr<Song>(new Song(L"Aretha Franklin", L"Bridge Over Troubled Water")));
//
//    std::vector<shared_ptr<Song>> v2;
//    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s)
//                   {
//                       return s.get()->artist.compare(L"Penaz Masani") == 0;
//                   });
//
//    for (const auto& s : v2)
//    {
//        std::wcout << s.get()->artist << L":" << s.get()->title << std::endl;
//    }
//
//    // This will create 10 integers, but will deleter only 1 which will result in memory leaks despite of using shared_ptr
//    std::shared_ptr<int> sp(new int[10]);
//
//    //The default_delete will make sure that delete[] is called to clean up the memory occupied by the array.
//    std::shared_ptr<int> sp1(new int[10], std::default_delete<int[]>());
//
//    std::shared_ptr<int> sp3 (new int);
//    *sp3 = 100;  // Using the shared_ptr
//    std::cout << *sp3 << std::endl;
    
