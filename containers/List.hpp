/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:31:59 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/02 16:33:19 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <cstddef>
# include <memory>
# include <new>
# include <limits>
# include "List_iterator.hpp"

namespace ft
{
    /**********************/
    /*                    */
    /*     Class List     */
    /*                    */
    /**********************/
    template <class T, class Alloc = std::allocator<T> >
    class List
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
            typedef typename list::iterator<value_type>                 iterator;
            typedef typename list::const_iterator<value_type>           const_iterator;
            typedef typename list::reverse_iterator<value_type>         reverse_iterator;
            typedef typename list::const_reverse_iterator<value_type>   const_reverse_iterator;
            typedef size_t                                              size_type;
            
            /****************************/
            /*     Member functions     */
            /****************************/

            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
            explicit List(const allocator_type& alloc = allocator_type()) : _current_size(0)
            {
                _alloc = alloc;
                _tail_of_node_list = create_node();
                _tail_of_node_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = _tail_of_node_list;
                // _tail_of_node_list->content = _current_size;
            }

            explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _current_size(n)
            {
                _alloc = alloc;
                _tail_of_node_list = create_node();
                _tail_of_node_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = _tail_of_node_list;
                // _tail_of_node_list->content = _current_size;
                node<value_type> *tmp_list_1;
                node<value_type> *tmp_list_2;
                tmp_list_1 = _tail_of_node_list;
                for (size_type i = 0; i < n; i++)
                {
                    tmp_list_1->next = create_node(val);
                    tmp_list_2 = tmp_list_1->next;
                    tmp_list_2->prev = tmp_list_1;
                    tmp_list_1 = tmp_list_2;
                }
                tmp_list_1->next = _tail_of_node_list;
                _tail_of_node_list->prev = tmp_list_1;
            }

            template <class InputIterator>
            List(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                    typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) //numeric_limits::is_specialized - true for all arithmetic types
            {
                _alloc = alloc;
                _tail_of_node_list = create_node();
                _tail_of_node_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = _tail_of_node_list;
                node<value_type> *tmp_list = _tail_of_node_list;
                size_type i = 0;
                while (first != last)
                {
                    tmp_list->next = create_node(*first);
                    tmp_list->next->prev = tmp_list;
                    tmp_list = tmp_list->next;
                    first++;
                    i++;
                }
                tmp_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = tmp_list;
                _current_size = i;
                // _tail_of_node_list->content = _current_size;
            }

            List(List const &copy)
            {
                _tail_of_node_list = create_node();
                _tail_of_node_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = _tail_of_node_list;
                node<value_type> *tmp_list_1 = _tail_of_node_list;
                node<value_type> *tmp_copy_list = copy._tail_of_node_list->next;
                while (tmp_copy_list != copy._tail_of_node_list)
                {
                    tmp_list_1->next = create_node(tmp_copy_list->content);
                    tmp_list_1->next->prev = tmp_list_1;
                    tmp_list_1 = tmp_list_1->next;
                    tmp_copy_list = tmp_copy_list->next;
                }
                tmp_list_1->next = _tail_of_node_list;
                _tail_of_node_list->prev = tmp_list_1;
                //_tail_of_node_list->content = copy._current_size;
                _current_size = copy._current_size;
            }

            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            List &operator=(List const &b)
            {
                if (this != &b)
                {
                    clear();
                    node<value_type> *tmp_list_1 = _tail_of_node_list;
                    node<value_type> *tmp_b_list = b._tail_of_node_list->next;
                    while (tmp_b_list != b._tail_of_node_list)
                    {
                        tmp_list_1->next = create_node(tmp_b_list->content);
                        tmp_list_1->next->prev = tmp_list_1;
                        tmp_list_1 = tmp_list_1->next;
                        tmp_b_list = tmp_b_list->next;
                    }
                    tmp_list_1->next = _tail_of_node_list;
                    _tail_of_node_list->prev = tmp_list_1;
                    //_tail_of_node_list->content = b._current_size;
                    _current_size = b._current_size;
                }
                return (*this);
            }
            
            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~List()
            {
                clear();
                delete_node(_tail_of_node_list);
            }

            /***************************************************************************/
            /*** iterators --------------------------------------------------------- ***/
            iterator                begin() { return (iterator(_tail_of_node_list->next));}
            const_iterator          begin() const { return (const_iterator(_tail_of_node_list->next));}
            iterator                end() { return (iterator(_tail_of_node_list));}
            const_iterator          end() const { return (const_iterator(_tail_of_node_list));}
            reverse_iterator        rbegin() { return (reverse_iterator(_tail_of_node_list->prev));}
            const_reverse_iterator  rbegin() const { return (const_reverse_iterator(_tail_of_node_list->prev));}
            reverse_iterator        rend() { return (reverse_iterator(_tail_of_node_list));}
            const_reverse_iterator  rend() const { return (const_reverse_iterator(_tail_of_node_list));}

            /***************************************************************************/
            /*** Capacity ---------------------------------------------------------- ***/
            bool        empty() const {return (_current_size == 0 ? true : false);}
            size_type   size() const {return (_current_size);}
            size_type   max_size() const {node_alloc node; return(node.max_size());}

            /***************************************************************************/
            /*** Element access ---------------------------------------------------- ***/
            reference       front() { return (_tail_of_node_list->next->content);}
            const_reference front() const { return (_tail_of_node_list->next->content);}
            reference       back() { return (_tail_of_node_list->prev->content);}
            const_reference back() const { return (_tail_of_node_list->prev->content);}

            /***************************************************************************/
            /*** Modifiers --------------------------------------------------------- ***/
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            {
                clear();
                node<value_type> *tmp_list = _tail_of_node_list;
                size_type i = 0;
                while (first != last)
                {
                    tmp_list->next = create_node(*first);
                    tmp_list->next->prev = tmp_list;
                    tmp_list = tmp_list->next;
                    first++;
                    i++;
                }
                tmp_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = tmp_list;
                _current_size = i;
                //_tail_of_node_list->content = _current_size;
            }
            void assign (size_type n, const value_type& val)
            {
                clear();
                _current_size = n;
                //_tail_of_node_list->content = _current_size;
                node<value_type> *tmp_list_1;
                node<value_type> *tmp_list_2;
                tmp_list_1 = _tail_of_node_list;
                for (size_type i = 0; i < n; i++)
                {
                    tmp_list_1->next = create_node(val);
                    tmp_list_2 = tmp_list_1->next;
                    tmp_list_2->prev = tmp_list_1;
                    tmp_list_1 = tmp_list_2;
                }
                tmp_list_1->next = _tail_of_node_list;
                _tail_of_node_list->prev = tmp_list_1;
            }
            void push_front (const value_type& val)
            {
                node<value_type> *new_node = create_node(val);
                new_node->next = _tail_of_node_list->next;
                new_node->prev = _tail_of_node_list;
                _tail_of_node_list->next->prev = new_node;
                _tail_of_node_list->next = new_node;
                ++_current_size;
                //_tail_of_node_list->content = _current_size;
            }
            void pop_front()
            {
                if (_tail_of_node_list->next == _tail_of_node_list)
                {
                    std::cerr << "You try to delete empty list" << std::endl;
                    return;
                }
                node<value_type> *tmp;
                tmp = _tail_of_node_list->next->next;
                delete_node(_tail_of_node_list->next);
                _tail_of_node_list->next = tmp;
                tmp->prev = _tail_of_node_list;
                --_current_size;
                //_tail_of_node_list->content = _current_size;
            }
            void push_back (const value_type& val)
            {
                node<value_type> *new_node = create_node(val);
                new_node->prev = _tail_of_node_list->prev;
                new_node->next = _tail_of_node_list;
                _tail_of_node_list->prev->next = new_node;
                _tail_of_node_list->prev = new_node;
                ++_current_size;
                //_tail_of_node_list->content = _current_size;
            }
            void pop_back()
            {
                if (_tail_of_node_list->next == _tail_of_node_list)
                {
                    std::cerr << "You try to delete empty list" << std::endl;
                    return;
                }
                node<value_type> *tmp;
                tmp = _tail_of_node_list->prev->prev;
                delete_node(_tail_of_node_list->prev);
                _tail_of_node_list->prev = tmp;
                tmp->next = _tail_of_node_list;
                --_current_size;
                //_tail_of_node_list->content = _current_size;
            }
            iterator insert (iterator position, const value_type& val)
            {
                node<value_type> *tmp_next = position.get_node();
                node<value_type> *tmp_prev = tmp_next->prev;
                tmp_prev->next = create_node(val);
                tmp_prev->next->prev = tmp_prev;
                tmp_next->prev = tmp_prev->next;
                tmp_prev->next->next = tmp_next;
                ++_current_size;
                //_tail_of_node_list->content++;
                return (tmp_prev->next);
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                node<value_type> *tmp_next = position.get_node();
                node<value_type> *tmp_prev = tmp_next->prev;
                for (size_type i = 0; i < n; i++)
                {
                    tmp_prev->next = create_node(val);
                    tmp_prev->next->prev = tmp_prev;
                    tmp_next->prev = tmp_prev->next;
                    tmp_prev->next->next = tmp_next;
                    //_tail_of_node_list->content++;
                    tmp_next = tmp_prev->next;
                }
                _current_size += n;
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
                        typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            {
                node<value_type> *tmp_next = position.get_node();
                node<value_type> *tmp_prev = tmp_next->prev;
                for (; first != last; first++)
                {
                    tmp_prev->next = create_node(*first);
                    tmp_prev->next->prev = tmp_prev;
                    tmp_next->prev = tmp_prev->next;
                    tmp_prev->next->next = tmp_next;
                    //_tail_of_node_list->content++;
                    _current_size++;
                    tmp_prev = tmp_prev->next;
                    tmp_next = tmp_prev->next;
                }
            }
            iterator erase (iterator position)
            {
                if (position.get_node() != _tail_of_node_list)
                {
                    node<value_type> *to_del = position.get_node();
                    node<value_type> *prev_lst = to_del->prev;
                    prev_lst->next = to_del->next;
                    to_del->next->prev = prev_lst;
                    delete_node(to_del);
                    _current_size--;
                    // (_tail_of_node_list->content)--;
                    return (prev_lst->next);
                }
                return (0);
            }
            iterator erase (iterator first, iterator last)
            {
                node<value_type> *to_del = first.get_node();
                node<value_type> *prev_lst = to_del->prev;
                node<value_type> *pos;
                while (first != last && to_del != _tail_of_node_list)
                {
                    prev_lst->next = to_del->next;
                    to_del->next->prev = prev_lst;
                    delete_node(to_del);
                    pos = prev_lst->next;
                    _current_size--;
                    // (_tail_of_node_list->content)--;
                    first++;
                    to_del = first.get_node();
                    prev_lst = to_del->prev;
                }
                return (pos);
            }
            void swap (List& x)
            {
                List<value_type> tmp(x);
                x.assign(this->begin(), this->end());
                x._current_size = _current_size;
                // x._tail_of_node_list->content = _current_size;
                this->assign(tmp.begin(), tmp.end());
                _current_size = tmp._current_size;
                //_tail_of_node_list->content = _current_size;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (_current_size < n)
                {
                    node<value_type>    *tmp = _tail_of_node_list->prev;
                    while (_current_size < n)
                    {
                        tmp->next = create_node(val);
                        tmp->next->prev = tmp;
                        tmp = tmp->next;
                        _current_size++;
                    }
                    tmp->next = _tail_of_node_list;
                    _tail_of_node_list->prev = tmp;
                    //_tail_of_node_list->content = _current_size;
                }
                if (_current_size > n)
                {
                    node<value_type>    *tmp = _tail_of_node_list;
                    _current_size = n;
                    while (n-- > 0)
                        tmp = tmp->next; // на выходе я стою на последнем элементе, который должен существовать
                    node<value_type> *tmp_2 = tmp->next->next;
                    while (tmp_2->prev != _tail_of_node_list)
                    {
                        delete_node(tmp->next);
                        tmp->next = tmp_2;
                        tmp_2->prev = tmp;
                        tmp_2 = tmp_2->next;
                    }
                    //_tail_of_node_list->content = _current_size;
                }
            }
            void clear()
            {
                node<value_type> *tmp = _tail_of_node_list->next->next;
                while (tmp->prev != _tail_of_node_list)
                {
                    delete_node(_tail_of_node_list->next);
                    _tail_of_node_list->next = tmp;
                    tmp->prev = _tail_of_node_list;
                    tmp = tmp->next;
                }
                _current_size = 0;
            }

            /***************************************************************************/
            /*** Operations -------------------------------------------------------- ***/
            void splice (iterator position, List& x)
            {
                node<value_type> *next_lst = position.get_node();
                node<value_type> *prev_lst = next_lst->prev;
                prev_lst->next = x._tail_of_node_list->next;
                x._tail_of_node_list->next->prev = prev_lst;
                next_lst->prev = x._tail_of_node_list->prev;
                x._tail_of_node_list->prev->next = next_lst;
                _current_size += x._current_size;
                //_tail_of_node_list->content = static_cast<value_type>(_current_size);

                x._tail_of_node_list->next = x._tail_of_node_list;
                x._tail_of_node_list->prev = x._tail_of_node_list;
                x._current_size = 0;
                //x._tail_of_node_list->content = 0;
            }	
            void splice (iterator position, List& x, iterator i)
            {
                node<value_type> *next_lst = position.get_node();
                node<value_type> *prev_lst = next_lst->prev;
                node<value_type> *new_lst = i.get_node();
                new_lst->prev->next = new_lst->next;
                new_lst->next->prev = new_lst->prev;
                prev_lst->next = new_lst;
                new_lst->prev = prev_lst;
                next_lst->prev = new_lst;
                new_lst->next = next_lst;
                _current_size++;
                // (_tail_of_node_list->content)++;
                x._current_size--;
                // (x._tail_of_node_list->content)--;
            }
            void splice (iterator position, List& x, iterator first, iterator last)
            {
                node<value_type> *next_lst = position.get_node();
                node<value_type> *prev_lst = next_lst->prev;
                node<value_type> *new_lst = first.get_node();
                while (first++ != last)
                {
                    new_lst->prev->next = new_lst->next;
                    new_lst->next->prev = new_lst->prev;
                    prev_lst->next = new_lst;
                    new_lst->prev = prev_lst;
                    next_lst->prev = new_lst;
                    new_lst->next = next_lst;
                    _current_size++;
                    // (_tail_of_node_list->content)++;
                    x._current_size--;
                    // (x._tail_of_node_list->content)--;
                    prev_lst = prev_lst->next;
                    new_lst = first.get_node();
                }
            }
            void remove (const value_type& val)
            {
                node<value_type> *tmp = _tail_of_node_list->next;
                node<value_type> *node_after_del;
                while (tmp != _tail_of_node_list)
                {
                    if (tmp->content == val)
                    {
                        tmp = tmp->prev;
                        node_after_del = tmp->next->next;
                        delete_node(tmp->next);
                        tmp->next = node_after_del;
                        node_after_del->prev = tmp;
                        _current_size--;
                    }
                    tmp = tmp->next;
                }
                //_tail_of_node_list->content = _current_size;
            }
            template <class Predicate>
            void remove_if (Predicate pred)
            {
                node<value_type> *tmp = _tail_of_node_list->next;
                node<value_type> *node_after_del;
                while (tmp != _tail_of_node_list)
                {
                    if (pred(tmp->content))
                    {
                        tmp = tmp->prev;
                        node_after_del = tmp->next->next;
                        delete_node(tmp->next);
                        tmp->next = node_after_del;
                        node_after_del->prev = tmp;
                        _current_size--;
                    }
                    tmp = tmp->next;
                }
                //_tail_of_node_list->content = _current_size;
            }
            void unique()
            {
                node<value_type> *tmp = _tail_of_node_list->next->next;
                node<value_type> *node_after_del;
                while (tmp != _tail_of_node_list)
                {
                    if (tmp->content == tmp->prev->content)
                    {
                        tmp = tmp->prev;
                        node_after_del = tmp->next->next;
                        delete_node(tmp->next);
                        tmp->next = node_after_del;
                        node_after_del->prev = tmp;
                        _current_size--;
                    }
                    tmp = tmp->next;
                }
                //_tail_of_node_list->content = _current_size;
            }
            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred)
            {
                node<value_type> *tmp = _tail_of_node_list->next->next;
                node<value_type> *node_after_del;
                while (tmp != _tail_of_node_list)
                {
                    if (binary_pred(tmp->prev->content, tmp->content))
                    {
                        tmp = tmp->prev;
                        node_after_del = tmp->next->next;
                        delete_node(tmp->next);
                        tmp->next = node_after_del;
                        node_after_del->prev = tmp;
                        _current_size--;
                    }
                    tmp = tmp->next;
                }
                //_tail_of_node_list->content = _current_size;
            }
            void merge (List& x)
            {
                if (this != &x)
                {
                    iterator pos_in_my_list, pos_in_x;
                    pos_in_my_list = begin();
                    pos_in_x = x.begin();
                    while (pos_in_my_list != end())
                    {
                        while (pos_in_x != x.end() && *pos_in_x < *pos_in_my_list)
                        {
                            splice(pos_in_my_list, x, pos_in_x);
                            pos_in_x = x.begin();
                        }
                        pos_in_my_list++;
                    }
                    if (pos_in_x != x.end())
                        splice (pos_in_my_list, x, pos_in_x, x.end());
                }
            }
            template <class Compare>
            void merge (List& x, Compare comp)
            {
                if (this != &x)
                {
                    iterator pos_in_my_list, pos_in_x;
                    pos_in_my_list = begin();
                    pos_in_x = x.begin();
                    while (pos_in_my_list != end())
                    {
                        while (pos_in_x != x.end() && comp(*pos_in_x, *pos_in_my_list))
                        {
                            splice(pos_in_my_list, x, pos_in_x);
                            pos_in_x = x.begin();
                        }
                        pos_in_my_list++;
                    }
                    if (pos_in_x != x.end())
                        splice (pos_in_my_list, x, pos_in_x, x.end());
                }
            }
            void sort()
            {
                node<value_type> *tmp_first;
                node<value_type> *tmp_second;
                node<value_type> *tmp_help;
                for (size_type i = 0; i < (_current_size - 1); i++)
                {
                    tmp_first = _tail_of_node_list->next;
                    tmp_second = _tail_of_node_list->next->next;
                    for (size_type j = 0; j < (_current_size - 1) - i; j++)
                    {
                        if (tmp_first->content > tmp_second->content)
                        {
                            tmp_help = tmp_first->prev;
                            tmp_help->next = tmp_second;

                            tmp_first->prev = tmp_second;
                            tmp_first->next = tmp_second->next;
                            
                            tmp_second->next = tmp_first;
                            tmp_second->prev = tmp_help;

                            tmp_first = tmp_first->prev;
                            tmp_second = tmp_first->next;

                            tmp_second->next->prev = tmp_second;
                        }
                        tmp_first = tmp_first->next;
                        tmp_second = tmp_second->next;
                    }
                }
            }
            template <class Compare>
            void sort (Compare comp)
            {
                node<value_type> *tmp_first;
                node<value_type> *tmp_second;
                node<value_type> *tmp_help;
                for (size_type i = 0; i < (_current_size - 1); i++)
                {
                    tmp_first = _tail_of_node_list->next;
                    tmp_second = _tail_of_node_list->next->next;
                    for (size_type j = 0; j < (_current_size - 1) - i; j++)
                    {
                        if (comp(tmp_second->content, tmp_first->content))
                        {
                            tmp_help = tmp_first->prev;
                            tmp_help->next = tmp_second;

                            tmp_first->prev = tmp_second;
                            tmp_first->next = tmp_second->next;
                            
                            tmp_second->next = tmp_first;
                            tmp_second->prev = tmp_help;

                            tmp_first = tmp_first->prev;
                            tmp_second = tmp_first->next;

                            tmp_second->next->prev = tmp_second;
                        }
                        tmp_first = tmp_first->next;
                        tmp_second = tmp_second->next;
                    }
                }      
            }
            void reverse()
            {
                if (!_tail_of_node_list)
                    return;
                node<value_type> *tmp = _tail_of_node_list;
                node<value_type> *tmp_buff = _tail_of_node_list->next;
                while (tmp_buff != _tail_of_node_list)
                {
                    tmp_buff = tmp->next;
                    tmp->next = tmp->prev;
                    tmp->prev = tmp_buff;
                    tmp = tmp_buff;
                }
            }

            private:
                
                /*********************************/
                /*     Member types | private    */
                /*********************************/
                typedef typename allocator_type::template rebind<node<value_type> >::other  node_alloc; //equivalent allocator fot type node
                typedef typename node_alloc::pointer                                        node_pointer;
                typedef typename node_alloc::const_reference                                node_const_reference;
                
                /*************************************/
                /*     Members for node | private    */
                /*************************************/
                node<value_type>    *_tail_of_node_list;
                size_type           _current_size;
                node_alloc          _alloc_for_node;
                allocator_type      _alloc;

                /*************************************/
                /*     Member functions | private    */
                /*************************************/
                node<value_type>    *create_node(value_type value = value_type())
                {
                    try
                    {
                        node_pointer n_pointer = _alloc_for_node.allocate(1);
                        node<value_type> new_node;
                        new_node.content = value;
                        new_node.next = 0;
                        new_node.prev = 0;
                        node_const_reference ref_node = new_node;
                        _alloc_for_node.construct(n_pointer, ref_node);
                        return (n_pointer);
                    }
                    catch(const std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    }
                    return (0);
                }

                void                delete_node(node<value_type> *node_for_del)
                {
                    node_pointer n_pointer = _alloc_for_node.address(*node_for_del);
                    _alloc_for_node.destroy(n_pointer);
                    _alloc_for_node.deallocate(n_pointer, 1);
                }
    };

    /*****************************************/
    /*                                       */
    /*     Non-member function overloads     */
    /*                                       */
    /*****************************************/
    template <class T, class Alloc>
    bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    {
        list::const_iterator<T> lhs_it = lhs.begin();
        list::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        return (lhs_it == lhs.end() && rhs_it == rhs.end());
    }
    
    template <class T, class Alloc>
    bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    {
        list::const_iterator<T> lhs_it = lhs.begin();
        list::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        return (lhs_it != lhs.end() || rhs_it != rhs.end());
    }
    
    template <class T, class Alloc>
    bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // Если значения одинаковы, то сравнивается длина списка
    // Если значения отличаются, то сравниваются значения
    // Сравнивает до первого не равного числа
    {
        list::const_iterator<T> lhs_it = lhs.begin();
        list::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        if (rhs_it == rhs.end() || (*lhs_it > *rhs_it && lhs_it != lhs.end()))
            return (false);
        // if (lhs_it == lhs.end() || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
        //     return (true);
        return (true);
    }

    template <class T, class Alloc>
    bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    {
        list::const_iterator<T> lhs_it = lhs.begin();
        list::const_iterator<T> rhs_it = rhs.begin();
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
    bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    {
        list::const_iterator<T> lhs_it = lhs.begin();
        list::const_iterator<T> rhs_it = rhs.begin();
        while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
        {
            lhs_it++;
            rhs_it++;
        }
        if (lhs_it == lhs.end() || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
            return (false);
        // if (rhs_it == rhs.end() || (*lhs_it < *rhs_it && lhs_it != lhs.end()))
        //     return (true);
        return (true);
    }

    template <class T, class Alloc>
    bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    {
        list::const_iterator<T> lhs_it = lhs.begin();
        list::const_iterator<T> rhs_it = rhs.begin();
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
    void swap (List<T,Alloc>& x, List<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif
