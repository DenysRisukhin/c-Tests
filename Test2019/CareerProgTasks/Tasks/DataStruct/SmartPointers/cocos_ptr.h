//
//  cocos_ptr.h
//  Test2019
//
//  Created by Denys Risukhin on 8/1/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef cocos_ptr_h
#define cocos_ptr_h

// class Ref - base class for Node and another
// this class has basic methods which we use for work with memory

// autorelease() - object automatically destroys him self after his scope finished
// вроде как использует слабые ссылки

// retain() - object never distroy him self automatically. Only if user call method
// release() for this object
// вроде как использует сильные ссылки

// need check all this info about memory


template<typename T>
class SharedRef {
public:
    SharedRef() {}
    
    SharedRef(T* obj) {
        updateObject(obj);
    }
    
    SharedRef(const SharedRef& rhs): SharedRef(rhs.m_obj) {
        // do nothing
    }
    
    SharedRef(SharedRef&& rhs) noexcept:
    m_obj(std::exchange(rhs.m_obj, nullptr)) {
        // do nothing
    }
    
    SharedRef& operator=(const SharedRef& rhs) {
        updateObject(rhs.m_obj);
        return *this;
    }
    
    SharedRef& operator=(SharedRef&& rhs) noexcept {
        std::swap(m_obj, rhs.m_obj);
        return *this;
    }
    
    ~SharedRef() {
        updateObject(nullptr);
    }
    
    void reset() {
        updateObject(nullptr);
    }
    
    void updateObject(T* obj) {
        if (m_obj != obj) {
            if (m_obj) { m_obj->release(); }
            m_obj = obj;
            if (m_obj) { m_obj->retain(); }
        }
    }
    
    operator bool() const {
        return m_obj != nullptr;
    }
    
    T* operator->() const {
        return m_obj;
    }
    
    bool operator==(T* rhs) const {
        return m_obj == rhs;
    }
    
    bool operator!=(T* rhs) const {
        return m_obj != rhs;
    }
    
    T* get() const { return m_obj; }
    
private:
    T* m_obj = nullptr;
};

#endif /* cocos_ptr_h */
