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
                    resize_array(n, 1);
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
            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            // {
            //     clear();
            //     node<value_type> *tmp_list = _tail_of_node_list;
            //     size_type i = 0;
            //     while (first != last)
            //     {
            //         tmp_list->next = create_node(*first);
            //         tmp_list->next->prev = tmp_list;
            //         tmp_list = tmp_list->next;
            //         first++;
            //         i++;
            //     }
            //     tmp_list->next = _tail_of_node_list;
            //     _tail_of_node_list->prev = tmp_list;
            //     _current_size = i;
            //     //_tail_of_node_list->content = _current_size;
            // }
            // void assign (size_type n, const value_type& val)
            // {
            //     clear();
            //     _current_size = n;
            //     //_tail_of_node_list->content = _current_size;
            //     node<value_type> *tmp_list_1;
            //     node<value_type> *tmp_list_2;
            //     tmp_list_1 = _tail_of_node_list;
            //     for (size_type i = 0; i < n; i++)
            //     {
            //         tmp_list_1->next = create_node(val);
            //         tmp_list_2 = tmp_list_1->next;
            //         tmp_list_2->prev = tmp_list_1;
            //         tmp_list_1 = tmp_list_2;
            //     }
            //     tmp_list_1->next = _tail_of_node_list;
            //     _tail_of_node_list->prev = tmp_list_1;
            // }
            void push_back (const value_type& val)
            {
                if (_capacity - _size == 0)
                    resize_array(_capacity * 2);
                _alloc.construct(_array_finish++, val);
                _size++;
            }
            // void pop_back()
            // {
            //     if (_tail_of_node_list->next == _tail_of_node_list)
            //     {
            //         std::cerr << "You try to delete empty list" << std::endl;
            //         return;
            //     }
            //     node<value_type> *tmp;
            //     tmp = _tail_of_node_list->prev->prev;
            //     delete_node(_tail_of_node_list->prev);
            //     _tail_of_node_list->prev = tmp;
            //     tmp->next = _tail_of_node_list;
            //     --_current_size;
            //     //_tail_of_node_list->content = _current_size;
            // }
            // iterator insert (iterator position, const value_type& val)
            // {
            //     node<value_type> *tmp_next = position.get_node();
            //     node<value_type> *tmp_prev = tmp_next->prev;
            //     tmp_prev->next = create_node(val);
            //     tmp_prev->next->prev = tmp_prev;
            //     tmp_next->prev = tmp_prev->next;
            //     tmp_prev->next->next = tmp_next;
            //     ++_current_size;
            //     //_tail_of_node_list->content++;
            //     return (tmp_prev->next);
            // }
            // void insert (iterator position, size_type n, const value_type& val)
            // {
            //     node<value_type> *tmp_next = position.get_node();
            //     node<value_type> *tmp_prev = tmp_next->prev;
            //     for (size_type i = 0; i < n; i++)
            //     {
            //         tmp_prev->next = create_node(val);
            //         tmp_prev->next->prev = tmp_prev;
            //         tmp_next->prev = tmp_prev->next;
            //         tmp_prev->next->next = tmp_next;
            //         //_tail_of_node_list->content++;
            //         tmp_next = tmp_prev->next;
            //     }
            //     _current_size += n;
            // }
            // template <class InputIterator>
            // void insert (iterator position, InputIterator first, InputIterator last,
            //             typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            // {
            //     node<value_type> *tmp_next = position.get_node();
            //     node<value_type> *tmp_prev = tmp_next->prev;
            //     for (; first != last; first++)
            //     {
            //         tmp_prev->next = create_node(*first);
            //         tmp_prev->next->prev = tmp_prev;
            //         tmp_next->prev = tmp_prev->next;
            //         tmp_prev->next->next = tmp_next;
            //         //_tail_of_node_list->content++;
            //         _current_size++;
            //         tmp_prev = tmp_prev->next;
            //         tmp_next = tmp_prev->next;
            //     }
            // }
            // iterator erase (iterator position)
            // {
            //     if (position.get_node() != _tail_of_node_list)
            //     {
            //         node<value_type> *to_del = position.get_node();
            //         node<value_type> *prev_lst = to_del->prev;
            //         prev_lst->next = to_del->next;
            //         to_del->next->prev = prev_lst;
            //         delete_node(to_del);
            //         _current_size--;
            //         // (_tail_of_node_list->content)--;
            //         return (prev_lst->next);
            //     }
            //     return (0);
            // }
            // iterator erase (iterator first, iterator last)
            // {
            //     node<value_type> *to_del = first.get_node();
            //     node<value_type> *prev_lst = to_del->prev;
            //     node<value_type> *pos;
            //     while (first != last && to_del != _tail_of_node_list)
            //     {
            //         prev_lst->next = to_del->next;
            //         to_del->next->prev = prev_lst;
            //         delete_node(to_del);
            //         pos = prev_lst->next;
            //         _current_size--;
            //         // (_tail_of_node_list->content)--;
            //         first++;
            //         to_del = first.get_node();
            //         prev_lst = to_del->prev;
            //     }
            //     return (pos);
            // }
            // void swap (List& x)
            // {
            //     List<value_type> tmp(x);
            //     x.assign(this->begin(), this->end());
            //     x._current_size = _current_size;
            //     // x._tail_of_node_list->content = _current_size;
            //     this->assign(tmp.begin(), tmp.end());
            //     _current_size = tmp._current_size;
            //     //_tail_of_node_list->content = _current_size;
            // }
            void clear()
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
                clear();
                if (take_number == 1)
                    _capacity = n;
                else
                    while (n > _capacity)
                        _capacity *= 2;
                _size = tmp._size;
                create_array(_capacity);
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(_array_finish, tmp.operator[](i));
                    _array_finish++;
                }
            }
    };

    // /*****************************************/
    // /*                                       */
    // /*     Non-member function overloads     */
    // /*                                       */
    // /*****************************************/
    // template <class T, class Alloc>
    // bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     return (lhs_it == lhs.end() && rhs_it == rhs.end());
    // }
    
    // template <class T, class Alloc>
    // bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     return (lhs_it != lhs.end() || rhs_it != rhs.end());
    // }
    
    // template <class T, class Alloc>
    // bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // // Если значения одинаковы, то сравнивается длина списка
    // // Если значения отличаются, то сравниваются значения
    // // Сравнивает до первого не равного числа
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if (rhs_it == rhs.end() || (*lhs_it > *rhs_it && lhs_it != lhs.end()))
    //         return (false);
    //     // if (lhs_it == lhs.end() || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
    //     //     return (true);
    //     return (true);
    // }

    // template <class T, class Alloc>
    // bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if ((rhs_it == rhs.end() && lhs_it != lhs.end()) || (*lhs_it > *rhs_it && lhs_it != lhs.end()))
    //         return (false);
    //     return (true);
    // }
    
    // template <class T, class Alloc>
    // bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if (lhs_it == lhs.end() || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
    //         return (false);
    //     // if (rhs_it == rhs.end() || (*lhs_it < *rhs_it && lhs_it != lhs.end()))
    //     //     return (true);
    //     return (true);
    // }

    // template <class T, class Alloc>
    // bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if ((lhs_it == lhs.end() && rhs_it != rhs.end()) || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
    //         return (false);
    //     return (true);

    // }

    // template <class T, class Alloc>
    // void swap (List<T,Alloc>& x, List<T,Alloc>& y)
    // {
    //     x.swap(y);
    // }

    //template <class Alloc>
    // class Vector<bool,Alloc>;
}

#endif
