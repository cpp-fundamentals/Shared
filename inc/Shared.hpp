#pragma once
#include <cstddef>

struct CountBlock
{   
    int weak;
    int shared;
} ;

template <typename T>
class Shared
{
public:
    Shared() = default;

    explicit Shared(T* p): _ptr(p)
    {
        _b_ptr->weak = 0;
        _b_ptr->shared = 0;
    }

    Shared(const Shared& obj): _ptr(obj.p), _b_ptr(obj._b_ptr)
    {
        if(_b_ptr->shared)
        {
            ++_b_ptr->shared;  
        }
        
    }

    Shared(Shared&& obj): _ptr(obj.p), _b_ptr(obj._b_ptr)
    {
        obj._ptr = nullptr;
        obj->shared = nullptr;
    }

    Shared& operator=(const Shared& obj)
    {
        if(this == &obj)
        {
            _ptr = obj._ptr;
            _b_ptr = obj._b_ptr;

            if(_b_ptr->shared)
            {
                ++_b_ptr->shared;
            }
            
            return this;
        }
    }
    Shared& operator=(Shared&& obj)
    {
        _ptr = obj._ptr;
        _b_ptr = obj._b_ptr;
       
        obj._ptr = nullptr;
        obj._b_ptr->shared = nullptr;
        return this;
    }

    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }

    T* get()
    {
        return _ptr;
    }

    ~Shared();
private:
    T* _ptr;
    CountBlock* _b_ptr;
    void a_clean()
    {

    }
};
