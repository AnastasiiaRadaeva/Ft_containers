/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:27:21 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/04 17:49:10 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <memory>
# include <new>
# include <limits>
# include <stdexcept> //for out_of_range
# include "Vector_iterator.hpp"

# define TAKE_NUMBER 1

namespace ft
{
    // # if flag < 0
    /************************/
    /*                      */
    /*     Class Vector     */
    /*                      */
    /************************/
    template <class T, class Alloc = std::allocator<T> >
    class Vector
    {
        public:
            /************************/
            /*     Member types     */
            /************************/
            typedef T                                                   value_type;
            typedef Alloc                                               allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef typename vector::iterator<value_type>                 iterator;
            typedef typename vector::const_iterator<value_type>           const_iterator;
            typedef typename vector::reverse_iterator<value_type>         reverse_iterator;
            typedef typename vector::const_reverse_iterator<value_type>   const_reverse_iterator;
            // typedef ptrdiff_t                                           difference_type;
            typedef size_t                                              size_type;
            
            /****************************/
            /*     Member functions     */
            /****************************/

            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
            explicit Vector(const allocator_type& alloc = allocator_type()) : _start(0), _array_finish(0), _storage_finish(0), _capacity(0), _size(0), _alloc(alloc)
            {

            }
            explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _capacity(n), _size(n), _alloc(alloc)
            {
                create_array(n);
                for (size_type i = 0; i < n; i++)
                {
                    _alloc.construct(_array_finish, val);
                    _array_finish++;
                }
            }
            template <class InputIterator>
            Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
                        typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) : _alloc(alloc)
            {
                InputIterator tmp = first;
                size_type n = 0;
                while (tmp++ != last)
                    n++;
                _capacity = n;
                _size = n;
                create_array(n);
                while (first != last)
                {
                    _alloc.construct(_array_finish, *first);
                    _array_finish++;
                    first++;
                }
            }
            Vector(const Vector & x) : _capacity(x._capacity), _size(x._size), _alloc(x._alloc)
            {
                create_array(_capacity);
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(_array_finish, x.operator[](i));
                    _array_finish++;
                }
            }
            
            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            Vector& operator=(const Vector& x)
            {
                if (this != &x)
                {
                    clear();
                    _alloc.deallocate(_start, _capacity);
                    _capacity = x._size;
                    _size = x._size;
                    create_array(_capacity);
                    for (size_type i = 0; i < _size; i++)
                    {
                        _alloc.construct(_array_finish, x.operator[](i));
                        _array_finish++;
                    }
                }
                return (*this);
            }
            
            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~Vector()
            {
                if (_start != 0 && _array_finish != 0 && _storage_finish != 0)
                {
                    clear();
                    _alloc.deallocate(_start, _capacity);
                }
            }

            // /***************************************************************************/
            // /*** iterators --------------------------------------------------------- ***/
            iterator                begin() { return (iterator(_start));}
            const_iterator          begin() const { return (const_iterator(_start));}
            iterator                end() { return (iterator(_array_finish));}
            const_iterator          end() const { return (const_iterator(_array_finish));}
            reverse_iterator        rbegin() { return (reverse_iterator(_array_finish - 1));}
            const_reverse_iterator  rbegin() const { return (const_reverse_iterator(_array_finish - 1));}
            reverse_iterator        rend() { return (reverse_iterator(_start - 1));}
            const_reverse_iterator  rend() const { return (const_reverse_iterator(_start - 1));}

            /***************************************************************************/
            /*** Capacity ---------------------------------------------------------- ***/
            size_type   size() const {return(_size);}
            size_type   max_size() const {return(_alloc.max_size());}
            void        resize (size_type n, value_type val = value_type())
            {
                if (n < _size)
                {
                    for (size_t i = _size; i > n; i--)
                        _alloc.destroy(--_array_finish);
                    _size = n;
                }
                if (n > _size)
                {
                    if (n > _capacity)
                        resize_array(n);
                    for (size_t i = _size; i < n; i++)
                        _alloc.construct(_array_finish++, val);
                    _size = n;
                }
            }
            size_type   capacity() const {return(_capacity);}
            bool        empty() const {return(_size == 0 ? true : false);}
            void        reserve (size_type n)
            {
                if (n > _capacity)
                    resize_array(n, TAKE_NUMBER);
            }

            /***************************************************************************/
            /*** Element access ---------------------------------------------------- ***/
            reference       operator[](size_type n)
            {
                iterator begin = this->begin();
                for (; n > 0; n--)
                    begin++;
                return (*begin);
            }
            const_reference operator[](size_type n) const
            {
                const_iterator begin = this->begin();
                for (; n > 0; n--)
                    begin++;
                return (*begin);
            }
            reference       at (size_type n)
            {
                if (n >= _size)
                    throw std::out_of_range("vector");
                return (operator[](n));
            }
            const_reference at (size_type n) const
            {
                if (n >= _size)
                    throw std::out_of_range("vector");
                return (operator[](n));
            }
            reference       front() { return (*_start);}
            const_reference front() const { return (*_start);}
            reference       back() { return (*(_array_finish - 1));}
            const_reference back() const { return (*(_array_finish - 1));}

            /***************************************************************************/
            /*** Modifiers --------------------------------------------------------- ***/
            template <class InputIterator>
            void        assign (InputIterator first, InputIterator last, typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            {
                clear();
                InputIterator tmp = first;
                size_type n = 0;
                while (tmp++ != last)
                    n++;
                if (n > _capacity)
                    resize_array(n, TAKE_NUMBER);
                _size = n;
                while (first != last)
                {
                    _alloc.construct(_array_finish, *first);
                    _array_finish++;
                    first++;
                }
            }
            void        assign (size_type n, const value_type& val)
            {
                clear();
                if (n > _capacity)
                    resize_array(n, TAKE_NUMBER);
                _size = n;
                for (; n > 0; n--)
                {
                    _alloc.construct(_array_finish, val);
                    _array_finish++;
                }
            }
            void        push_back (const value_type& val)
            {
                if (_capacity - _size == 0)
                    resize_array(_size + 1);
                _alloc.construct(_array_finish++, val);
                ++_size;
            }
            void        pop_back()
            {
                _alloc.destroy(--_array_finish);
                --_size;
            }
            iterator    insert (iterator position, const value_type& val)
            {
                if (_capacity - _size == 0)
                {
                    size_type i = 0;
                    for (iterator it = begin(); it != position; it++)
                        i++;
                    resize_array(_size + 1);
                    position = iterator(&(_start[i]));
                }
                Vector<value_type> tmp;
                iterator add_pos = position;
                for (; add_pos != end(); add_pos++)
                    tmp.push_back(*add_pos);
                add_pos = position;
                while (add_pos != end())
                {
                    _alloc.destroy(--_array_finish);
                    --_size;
                }
                _alloc.construct(_array_finish++, val);
                ++_size;
                add_values(++position, tmp);
                return (--position);
            }
            void        insert (iterator position, size_type n, const value_type& val)
            {
                if (_size + n > _capacity)
                {
                    size_type i = 0;
                    for (iterator it = begin(); it != position; it++)
                        i++;
                    resize_array(_size + n, TAKE_NUMBER);
                    position = iterator(&(_start[i]));
                }
                Vector<value_type> tmp;
                iterator add_pos = position;
                for (; add_pos != end(); add_pos++)
                    tmp.push_back(*add_pos);
                add_pos = position;
                while (add_pos != end())
                {
                    _alloc.destroy(--_array_finish);
                    --_size;
                }
                for (size_type i = 0; i < n; i++)
                {
                    _alloc.construct(_array_finish++, val);
                    ++_size;
                    ++position;
                }
                add_values(position, tmp);
            }
            template <class InputIterator>
            void        insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            {
                size_type n = 0;
                InputIterator tmp_pos = first;
                while (tmp_pos++ != last)
                    n++;
                if (_size + n > _capacity)
                {
                    size_type i = 0;
                    for (iterator it = begin(); it != position; it++)
                        i++;
                    resize_array(_size + n, TAKE_NUMBER);
                    position = iterator(&(_start[i]));
                }
                Vector<value_type> tmp;
                iterator add_pos = position;
                for (; add_pos != end(); add_pos++)
                    tmp.push_back(*add_pos);
                add_pos = position;
                while (add_pos != end())
                {
                    _alloc.destroy(--_array_finish);
                    --_size;
                }
                for (; first != last; first++)
                {
                    _alloc.construct(_array_finish++, *first);
                    ++_size;
                    ++position;
                }
                add_values(position, tmp);
            }
            iterator    erase (iterator position)
            {
                Vector<value_type> tmp;
                iterator add_pos = ++position;
                for (; add_pos != end(); add_pos++)
                    tmp.push_back(*add_pos);
                add_pos = --position;
                while (add_pos != end())
                {
                    _alloc.destroy(--_array_finish);
                    --_size;
                }
                add_values(position, tmp);
                return (position);
            }
            iterator    erase (iterator first, iterator last)
            {
                Vector<value_type> tmp;
                iterator add_pos = last;
                for (; add_pos != end(); add_pos++)
                    tmp.push_back(*add_pos);
                add_pos = first;
                while (add_pos != end())
                {
                    _alloc.destroy(--_array_finish);
                    --_size;
                }
                add_values(first, tmp);
                return (first);
            }
            void        swap (Vector& x)
            {
                value_type *tmp;
                tmp = _start;
                _start = x._start;
                x._start = tmp;

                tmp = _array_finish;
                _array_finish = x._array_finish;
                x._array_finish = tmp;

                tmp = _storage_finish;
                _storage_finish = x._storage_finish;
                x._storage_finish = tmp;

                size_type tmp_size;
                tmp_size = _size;
                _size = x._size;
                x._size = tmp_size;

                tmp_size = _capacity;
                _capacity = x._capacity;
                x._capacity = tmp_size;
            }
            void        clear()
            {
                for (size_t i = _size; i > 0; i--)
                    _alloc.destroy(--_array_finish);
                _size = 0;
            }

        private:
                
            /*************************************/
            /*     Members for node | private    */
            /*************************************/
            pointer         _start;
            pointer         _array_finish;
            pointer         _storage_finish;
            size_type       _capacity;
            size_type       _size;
            allocator_type  _alloc;

            /*************************************/
            /*     Member functions | private    */
            /*************************************/
            void    create_array(size_type n)
            {
                try
                {    
                    _start = _alloc.allocate(n);
                    _array_finish = _start;
                    _storage_finish = _start + n;
                }
                catch(const std::exception& ba)
                {
                    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
                }
            }

            void    resize_array(size_type n, int take_number = 0)
            {
                Vector<value_type> tmp(*this);
                size_type size = _size;
                clear();
                _alloc.deallocate(_start, _capacity);
                if (take_number == TAKE_NUMBER || _capacity == 0)
                    _capacity = n;
                else
                    while (n > _capacity)
                    {
                        _size = (size == 0) ? 1 : size * 2;
                        _capacity = _size;
                    }
                _size = tmp._size;
                create_array(_capacity);
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(_array_finish, tmp.operator[](i));
                    _array_finish++;
                }
            }

            void    add_values(iterator position, Vector &add)
            {
                for (iterator it = add.begin(); it != add.end(); it++)
                {
                    _alloc.construct(&(*position), *it);
                    position++;
                    _array_finish++;
                    _size++;
                }
            }
    };

    /*****************************************/
    /*                                       */
    /*     Non-member function overloads     */
    /*                                       */
    /*****************************************/
    template <class T, class Alloc>
    bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        vector::const_iterator<T> lhs_it = lhs.begin();
        vector::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        return (lhs_it == lhs.end() && rhs_it == rhs.end());
    }

    template <class T, class Alloc>
    bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        vector::const_iterator<T> lhs_it = lhs.begin();
        vector::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        return (lhs_it != lhs.end() || rhs_it != rhs.end());
    }

    template <class T, class Alloc>
    bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        vector::const_iterator<T> lhs_it = lhs.begin();
        vector::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        if (rhs_it == rhs.end() || (*lhs_it > *rhs_it && lhs_it != lhs.end()))
            return (false);
        return (true);
    }

    template <class T, class Alloc>
    bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {

        vector::const_iterator<T> lhs_it = lhs.begin();
        vector::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        if ((rhs_it == rhs.end() && lhs_it != lhs.end()) || (*lhs_it > *rhs_it && lhs_it != lhs.end()))
            return (false);
        return (true);
    }

    template <class T, class Alloc>
    bool operator> (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        vector::const_iterator<T> lhs_it = lhs.begin();
        vector::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        if (lhs_it == lhs.end() || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
            return (false);
        return (true);
    }

    template <class T, class Alloc>
    bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        vector::const_iterator<T> lhs_it = lhs.begin();
        vector::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        if ((lhs_it == lhs.end() && rhs_it != rhs.end()) || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
            return (false);
        return (true);
    }

    template <class T, class Alloc>
    void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
    {
        x.swap(y);
    }

    //template <class Alloc>
    // class Vector<bool,Alloc>;
}

#endif
