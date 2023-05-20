#ifndef MYVEC_H
#define MYVEC_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <iterator>

template <class T>
class Vector 
{
    public:
    //member types
        using value_type = T; 
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = value_type*;
        using const_iterator = const value_type*;
        using reverse_iterator = std::reverse_iterator<typename Vector<value_type>::iterator>; 
        using const_reverse_iterator = std::reverse_iterator<const typename Vector<value_type>::iterator>; 
        using difference_type = ptrdiff_t;
        using size_type = size_t;
        using allocator_type = std::allocator<value_type>;
    
    private:
        size_type size_=0;
        size_type capacity_=0;
        iterator data_=nullptr;
        allocator_type alloc;

        void create()
        {size_=capacity_=0; data_=nullptr;}
        void create(size_type wsize)
        {
            data_ = alloc.allocate(wsize);
            size_=0;
            capacity_=wsize;
        }
        void create(const iterator i, const iterator j)
        {
            size_=std::distance(i,j);
            data_=alloc.allocate(size_);
            capacity_=size_;
           std::uninitialized_copy(i, j, data_);
        }
        void create(size_type count, const_reference value)
        {
            data_=alloc.allocate(count);
            size_=capacity_=count;
            std::uninitialized_fill(data_, data_+count, value);
        }
    
        void uncreate()
        {
            if (data_)
            {
                iterator it = data_+size_-1;
                while (it!=data_)
                {
                    alloc.destroy(it);
                    --it;
                }
                alloc.deallocate(data_, capacity_);
            }
            data_=nullptr; size_=capacity_=0;
        }
    
        void unchecked_append(const T& val)
         {alloc.construct(data_+size_, val);}

        void grow() 
        {
            size_type new_cap = std::max(static_cast<size_type>(2 * capacity_), static_cast<size_type>(1));
            size_type new_size=size_;
            iterator new_data = alloc.allocate(new_cap);
            std::uninitialized_copy(data_, (data_+size_), new_data);
            uncreate();
            data_ = new_data;
            capacity_=new_cap;
            size_=new_size;
        }

        void grow(size_type n)
        {
            capacity_=n;
            iterator new_data = alloc.allocate(capacity_);
            size_type new_size=size_;
            std::uninitialized_copy(data_, data_+size_, new_data);
            uncreate();
            data_=new_data;
            capacity_=n;
            size_=new_size;
        }

    public:
    //======KONSTRUKTORIAI======
        Vector()
        {create();} 
        Vector (int wsize)
        { create(wsize);}
        Vector (Vector &v)
        { create(v.begin(), v.end()); }
        Vector(std::initializer_list<value_type> elem)
        {
            data_=alloc.allocate(elem.size());
            size_=capacity_=elem.size();
            size_type i=0;
            for (const auto &e:elem)
            {
                data_[i]=e;
                i++;
            }
        };
        Vector& operator=(Vector& v) 
        {
            if (this!=&v)
            {
                uncreate();
                create(v.begin(), v.end());
            }
            return *this;
        }
        Vector& operator=(const Vector& v)
        {
            if (this!=&v)
            {
                uncreate();
                create(v.begin(), v.end());
            }
            return *this;
        }
        void assign (size_type count, const T& value)
        {create(count, value);}

    //======ELEMENT ACCESS=====
        reference at(size_type pos)
        {
            if (pos>=size_||pos<0) { throw std::out_of_range("out_of_range (Vector:at)");}
            return data_[pos];
        }
        reference at (size_type pos) const
        {
            if (pos>=size_||pos<0) { throw std::out_of_range("out_of_range (Vector:at)");}
            return data_[pos];
        }
        reference operator[](size_type pos)
        {return data_[pos];}
        reference operator[] (size_type pos) const
        {return data_[pos];}
        reference front()
        {return *data_;}
        reference front() const
        {return *data_;}
        reference back()
        {return *(data_+size_-1);}
        reference back() const
        {return *(data_+size_-1);}
        iterator data()
        { return data_;}
        iterator data() const
        {return data_;}
    
    //========ITERATORS========
        iterator begin() noexcept
        { return data_;}
        iterator begin() const noexcept
        { return data_;}
        iterator end() noexcept
        { return data_+size_;}
        iterator end() const noexcept  
        { return data_+size_;}
        reverse_iterator rbegin() noexcept
        {return std::reverse_iterator(end());}
        reverse_iterator rbegin() const noexcept
        {return std::reverse_iterator(end());}
        reverse_iterator rend() noexcept
        {return std::reverse_iterator(begin());}
        reverse_iterator rend() const noexcept
        {return std::reverse_iterator(begin());}
       
    //=======CAPACITY==========
        bool empty() const noexcept
        {
            if (size_==0) {return true;}
            else {return false;}
        }
        size_type size() const noexcept
        {return size_;}
        size_type max_size() const noexcept 
        { return std::numeric_limits<difference_type>::max() / sizeof(value_type);}
        void reserve( size_type new_cap)
        {
            if (new_cap>capacity_)
            { grow(new_cap);}
        }
        size_type capacity() const noexcept
        {return capacity_;}
        void shrink_to_fit()
        {
            if (size_==0) {uncreate(); create();}
            else if (size_ < capacity_)
            {
                iterator data2 = alloc.allocate(size_);
                size_type ns = size_;
                std::uninitialized_copy(data_, data_ + size_, data2);
                uncreate();
                data_ = data2;
                capacity_ = ns;
                size_=ns;
            }
        }
    
    //======MODIFIERS=======
        void clear() noexcept 
        {  uncreate(); }         
        iterator erase(const_iterator pos)
        {
            if (pos<begin()) {throw std::out_of_range("out_of_range(Vector::erase)");}
            iterator poss=const_cast<iterator>(pos);
            alloc.destroy(poss);
            std::move(poss+1, data_+size_, poss);
            size_--;
            return poss;
        }
        iterator erase(const_iterator pos1, const_iterator pos2)
        {
            iterator poss1 = const_cast<iterator>(pos1);
            iterator poss2 = const_cast<iterator>(pos2);
            size_type index = poss2 - poss1;

            for (size_type i = 0; i < index; i++)
            {
                alloc.destroy(poss1 + i);
            }

            iterator poss = std::move(poss2, end(), poss1);
            size_ -= index;
            return poss;
        }
        void push_back(const T& value)
        {
            if (size_+1>capacity_)
            {grow();}
            unchecked_append(value);
            size_++;
        }
        void pop_back()
        {
            if (size_<1) {throw std::out_of_range("out_of_range (Vector::pop_back)");}
            size_--;
            iterator it=data_+size_;
            alloc.destroy(it);
        }
        void resize(size_type count)
        {
            if (count>size_)
            {
                if (count>capacity_) 
                {
                    grow(count);
                    capacity_=count;
                }
            }
            else if (count<size_)
            {
                iterator it=data_+size_;
                for (size_type i=0; i<size_-count; i++)
                {

                    alloc.destroy(--it);
                }
                size_=count;
                capacity_=count;
            }
        }
        void swap(Vector& other) noexcept
        {
            std::swap(data_, other.data_);
            std::swap(size_, other.size_);
            std::swap(capacity_, other.capacity_);
        }

        //======DESTRUCTOR=====
        ~Vector() 
        {uncreate();}

};

template<class T> class allocator 
{
    public:
    T* allocate(size_t n)
    {return static_cast<T*>(::operator new(n * sizeof(T)));}
    void deallocate(T* p, size_t n)
    {::operator delete(p, n * sizeof(T));}
    void construct(T* p, const T& val) 
    {new (p) T(val);}
    void destroy(T* p)
    {p->~T();}
};

template <typename T>
void swap(Vector<T>& lhs, Vector<T>& rhs)
{lhs.swap(rhs);}

//=======OPERATORS========
template <typename T> bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
{
    if (lhs.size()!=rhs.size()) {return false;}
    for (size_t i=0; i<lhs.size(); i++)
    {
        if (lhs.at(i)!=lhs.at(i)) {return false;}
    }
    return true;
}
template <typename T> bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
{
    if (lhs.size()!=rhs.size()) {return true;}
    for (size_t i=0; i<lhs.size(); i++)
    {
        if (lhs.at(i)!=lhs.at(i)) {return true;}
    }
    return false;
}
template <typename T> bool operator<(const Vector<T>& lhs, const Vector<T>& rhs)
{
    for (size_t i=0; i<std::min(lhs.size(), rhs.size()); i++)
    {
        if (lhs.at(i)<rhs.at(i)) {return true;}
    }
    return false;
}
template <typename T> bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs)
{
    for (size_t i=0; i<std::min(lhs.size(), rhs.size()); i++)
    {
        if (lhs.at(i)<=rhs.at(i)) {return true;}
    }
    return false;
}
template <typename T> bool operator>(const Vector<T>& lhs, const Vector<T>& rhs)
{
    for (size_t i=0; i<std::min(lhs.size(), rhs.size()); i++)
    {
        if (lhs.at(i)>rhs.at(i)) {return true;}
    }
    return false;
}
template <typename T> bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs)
{
    for (size_t i=0; i<std::min(lhs.size(), rhs.size()); i++)
    {
        if (lhs.at(i)>=rhs.at(i)) {return true;}
    }
    return false;
}

        
#endif