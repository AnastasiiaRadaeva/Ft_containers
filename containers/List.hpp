/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:31:59 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/20 18:05:32 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <cstddef>
# include <memory>
# include <new>
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
            typedef T                                               value_type;
            typedef Alloc                                           allocator_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef typename ft::iterator<value_type>               iterator;
            typedef typename ft::const_iterator<value_type>         const_iterator;
            typedef typename ft::reverse_iterator<value_type>       reverse_iterator;
            typedef typename ft::const_reverse_iterator<value_type> const_reverse_iterator;
            // typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef size_t                                          size_type;
            
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
                _tail_of_node_list->content = _current_size;
            }

            explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _current_size(n)
            {
                _alloc = alloc;
                _tail_of_node_list = create_node();
                _tail_of_node_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = _tail_of_node_list;
                _tail_of_node_list->content = _current_size;
                ft::node<value_type> *tmp_list_1;
                ft::node<value_type> *tmp_list_2;
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

            // template <class InputIterator> // тут нужно показать, что мы можем брать именно итераторы
            // List(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            // {
            //     _alloc = alloc;
            //     _tail_of_node_list = create_node();
            //     _tail_of_node_list->next = _tail_of_node_list;
            //     _tail_of_node_list->prev = _tail_of_node_list;
            //     ft::node<value_type> *tmp_list_1;
            //     size_type i = 0;
            //     while (first != last)
            //     {
            //         tmp_list_1->next = create_node(*first);
            //         tmp_list_1->next->prev = tmp_list_1;
            //         tmp_list_1 = tmp_list_1->next;
            //         i++;
            //     }
            //     tmp_list_1->next = _tail_of_node_list;
            //     _tail_of_node_list->prev = tmp_list_1;
            //     _current_size = i;
            //     _tail_of_node_list->content = _current_size;
            // }

            List(List const &copy)
            {
                _tail_of_node_list = create_node();
                _tail_of_node_list->next = _tail_of_node_list;
                _tail_of_node_list->prev = _tail_of_node_list;
                ft::node<value_type> *tmp_list_1 = _tail_of_node_list;
                ft::node<value_type> *tmp_copy_list = copy._tail_of_node_list->next;
                while (tmp_copy_list != copy._tail_of_node_list)
                {
                    tmp_list_1->next = create_node(tmp_copy_list->content);
                    tmp_list_1->next->prev = tmp_list_1;
                    tmp_list_1 = tmp_list_1->next;
                    tmp_copy_list = tmp_copy_list->next;
                }
                tmp_list_1->next = _tail_of_node_list;
                _tail_of_node_list->prev = tmp_list_1;
                _tail_of_node_list->content = copy._current_size;
                _current_size = copy._current_size;
            }

            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            List &operator=(List const &b)
            {
                if (this != &b)
                {
                    clear();
                    ft::node<value_type> *tmp_list_1 = _tail_of_node_list;
                    ft::node<value_type> *tmp_b_list = b._tail_of_node_list->next;
                    while (tmp_b_list != b._tail_of_node_list)
                    {
                        tmp_list_1->next = create_node(tmp_b_list->content);
                        tmp_list_1->next->prev = tmp_list_1;
                        tmp_list_1 = tmp_list_1->next;
                        tmp_b_list = tmp_b_list->next;
                    }
                    tmp_list_1->next = _tail_of_node_list;
                    _tail_of_node_list->prev = tmp_list_1;
                    _tail_of_node_list->content = b._current_size;
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

            // /* Iterators */
            iterator                begin() { return (iterator(_tail_of_node_list->next));}
            const_iterator          begin() const { return (const_iterator(_tail_of_node_list->next));}
            iterator                end() { return (iterator(_tail_of_node_list));}
            const_iterator          end() const { return (const_iterator(_tail_of_node_list));}
            reverse_iterator        rbegin() { return (reverse_iterator(_tail_of_node_list->prev));}
            const_reverse_iterator  rbegin() const { return (const_reverse_iterator(_tail_of_node_list->prev));}
            reverse_iterator        rend() { return (reverse_iterator(_tail_of_node_list->next));}
            const_reverse_iterator  rend() const { return (const_reverse_iterator(_tail_of_node_list->next));}

            /* --- Capacity --- */
            bool        empty() const {return (_current_size == 0 ? true : false);}
            size_type   size() const {return (_current_size);}
            size_type   max_size() const {node_alloc node; return(node.max_size());}

            /* --- Element access --- */
            reference       front() { return (_tail_of_node_list->next->content);}
            const_reference front() const { return (_tail_of_node_list->next->content);}
            reference       back() { return (_tail_of_node_list->prev->content);}
            const_reference back() const { return (_tail_of_node_list->prev->content);}

            // /* Modifiers */
            // template <class InputIterator> // тут нужно показать, что мы можем брать именно итераторы
            // void assign (InputIterator first, InputIterator last)
            // {

            // }
            void assign (size_type n, const value_type& val)
            {
                clear();
                _current_size = n;
                _tail_of_node_list->content = _current_size;
                ft::node<value_type> *tmp_list_1;
                ft::node<value_type> *tmp_list_2;
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
                ft::node<value_type> *new_node = create_node(val);
                new_node->next = _tail_of_node_list->next;
                new_node->prev = _tail_of_node_list;
                _tail_of_node_list->next->prev = new_node;
                _tail_of_node_list->next = new_node;
                _tail_of_node_list->content = ++_current_size;
            }
            void pop_front()
            {
                if (_tail_of_node_list->next == _tail_of_node_list)
                {
                    std::cerr << "You try to delete empty list" << std::endl;
                    return;
                }
                ft::node<value_type> *tmp;
                tmp = _tail_of_node_list->next->next;
                delete_node(_tail_of_node_list->next);
                _tail_of_node_list->next = tmp;
                tmp->prev = _tail_of_node_list;
                _tail_of_node_list->content = --_current_size;
            }
            void push_back (const value_type& val)
            {
                ft::node<value_type> *new_node = create_node(val);
                new_node->prev = _tail_of_node_list->prev;
                new_node->next = _tail_of_node_list;
                _tail_of_node_list->prev->next = new_node;
                _tail_of_node_list->prev = new_node;
                _tail_of_node_list->content = ++_current_size;
            }
            void pop_back()
            {
                if (_tail_of_node_list->next == _tail_of_node_list)
                {
                    std::cerr << "You try to delete empty list" << std::endl;
                    return;
                }
                ft::node<value_type> *tmp;
                tmp = _tail_of_node_list->prev->prev;
                delete_node(_tail_of_node_list->prev);
                _tail_of_node_list->prev = tmp;
                tmp->next = _tail_of_node_list;
                _tail_of_node_list->content = --_current_size;
            }
            // iterator insert (iterator position, const value_type& val);
            // void insert (iterator position, size_type n, const value_type& val);
            // template <class InputIterator> // тут нужно показать, что мы можем брать именно итераторы
            // void insert (iterator position, InputIterator first, InputIterator last);
            // iterator erase (iterator position);
            // iterator erase (iterator first, iterator last);
            void swap (List& x)
            {
                List<value_type> tmp(x);
                
            }
            // void resize (size_type n, value_type val = value_type());
            void clear()
            {
                ft::node<value_type> *tmp = _tail_of_node_list->next->next;
                while (tmp->prev != _tail_of_node_list)
                {
                    delete_node(_tail_of_node_list->next);
                    _tail_of_node_list->next = tmp;
                    tmp->prev = _tail_of_node_list;
                    tmp = tmp->next;
                }
            }

            // /* Operations */
            // void splice (iterator position, list& x);	
            // void splice (iterator position, list& x, iterator i);
            // void splice (iterator position, list& x, iterator first, iterator last);
            // void remove (const value_type& val);
            // template <class Predicate>
            // void remove_if (Predicate pred);
            // void unique();
            // template <class BinaryPredicate>
            // void unique (BinaryPredicate binary_pred);
            // void merge (List& x);
            // template <class Compare>
            // void merge (List& x, Compare comp);
            // void sort();
            // void sort (Compare comp);
            void reverse()
            {
                if (!_tail_of_node_list)
                    return;
                ft::node<value_type> *tmp;
                ft::node<value_type> *tmp_buff;
                tmp = _tail_of_node_list;
                tmp_buff = _tail_of_node_list->next;
                while (tmp_buff != _tail_of_node_list)
                {
                    tmp_buff = tmp->next;
                    tmp->next = tmp->prev;
                    tmp->prev = tmp_buff;
                    tmp = tmp_buff;
                }
            }

            private:
                
                //types
                typedef typename allocator_type::template rebind<ft::node<value_type> >::other  node_alloc; //equivalent allocator fot type node
                typedef typename node_alloc::pointer                                            node_pointer;
                typedef typename node_alloc::const_reference                                    node_const_reference;
                
                //for node
                ft::node<value_type>    *_tail_of_node_list;
                size_type               _current_size;
                node_alloc              _alloc_for_node;
                allocator_type          _alloc;

                node<value_type>    *create_node(value_type value = value_type())
                {
                    try
                    {
                        node_pointer n_pointer = _alloc_for_node.allocate(1);
                        typename ft::node<value_type> new_node;
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
                    _alloc_for_node.deallocate(n_pointer, 1);//не очень понятно, остается ли указатель в нормальном состоянии.
                }
    };

    /* --- Non-member function overloads --- */
    // template <class T, class Alloc>
    // bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    // }
    
    // template <class T, class Alloc>
    // bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
    
    // template <class T, class Alloc>
    // bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

    // template <class T, class Alloc>
    // bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
    
    // template <class T, class Alloc>
    // bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

    // template <class T, class Alloc>
    // bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

    // template <class T, class Alloc>
    // void swap (List<T,Alloc>& x, List<T,Alloc>& y);
}

#endif
