/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:31:59 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/11 17:17:57 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <cstddef>
# include <memory>
# include <new>
# include "iterator.hpp"

// #include <list>
// std::list<int> list_;

namespace ft
{
    /* --- Struct of node --*/
    template <typename T>
    struct node
    {
        T       _content;
        node    *_next;
        node    *_prev;        
    };

    /* --- Class List ___ */
    template <class T, class Alloc = std::allocator<T> >
    class List
    {
        private:
            typedef     typename Alloc::template rebind<ft::node<T> >::other    node_alloc; //equivalent allocator fot type node
            typedef     typename node_alloc::pointer                            node_pointer;
            typedef     typename node_alloc::const_reference                    node_const_reference;
            ft::node<T> *_tail_of_node_list;
            size_t      _current_size;
            node_alloc  _alloc_for_node;
            Alloc       _alloc;

            node<T> *create_node(T value = T())
            {
                try
                {
                    node_pointer n_pointer = _alloc_for_node.allocate(1);
                    typename ft::node<T> new_node;
                    new_node._content = value;
                    new_node._next = 0;
                    new_node._prev = 0;
                    node_const_reference ref_node = new_node;
                    _alloc_for_node.construct(n_pointer, ref_node);
                    return (n_pointer);
                }
                catch(const std::bad_alloc& ba)
                {
                    std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                }
                return(0);
            }       

        public:
            /* --- Member types --- */
            typedef T                                                 value_type;
            typedef Alloc                                             allocator_type;
            typedef typename allocator_type::reference                 reference;
            typedef typename allocator_type::const_reference           const_reference;
            typedef typename allocator_type::pointer                   pointer;
            typedef typename allocator_type::const_pointer             const_pointer;
            // typedef typename ft::iterator<std::bidir>                       iterator;
            // typedef typename ft::const_iterator<std::bidir>                 const_iterator;
            // typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
            // typedef typename ft::reverse_iterator<const_iterator>           const_reverese_iterator;
            // typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef size_t                                                  size_type;
            
            /* --- Member functions --- */
            

            std::string &getList()
            {
                _tail_of_node_list->_content = "Hello";
                return(_tail_of_node_list->_content);
            }

            /* constructors */
            explicit List(const allocator_type& alloc = allocator_type()) : _current_size(0)
            {
                _alloc = alloc;
                _tail_of_node_list = create_node();
            }

            // explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _current_size(n)
            // {
            //     _alloc = alloc;
            //     _tail_of_node_list = create_node(0);
            //     _tail_of_node_list->_next = _tail_of_node_list;
            //     _tail_of_node_list->_prev = _tail_of_node_list;
            //     ft::node<value_type> *tmp_list_1;
            //     ft::node<value_type> *tmp_list_2;
            //     tmp_list_1 = _tail_of_node_list;
            //     for (size_type i = 0; i < n; i++)
            //     {
            //         tmp_list_1->_next = create_node(val);
            //         tmp_list_2 = tmp_list_1->_next;
            //         tmp_list_2->_prev = tmp_list_1;
            //         tmp_list_1 = tmp_list_1->_next;
            //     }
            //     tmp_list_1->_next = _tail_of_node_list;
            //     _tail_of_node_list->_prev = tmp_list_1;

            //     tmp_list_1 = _tail_of_node_list->_next;
            //     while (tmp_list_1 != _tail_of_node_list)
            //     {
            //         std::cout << tmp_list_1->_content << std::endl;
            //         tmp_list_1 = tmp_list_1->_next;
            //     }
                
            // }

            // template <class InputIterator>
            // List(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            // List(List const &);
            
            // /* operator= */
            // List &operator=(List const &);
            
            /* destructor */
            ~List()
            {
                //clear

            }

            // /* Iterators */
            // // iterator                begin();
            // // const_iterator          begin() const;
            // // iterator                end();
            // // const_iterator          end() const;
            // // reverse_iterator        rbegin();
            // // const_reverse_iterator  rbegin() const;
            // // reverse_iterator        rend();
            // // const_reverse_iterator  rend() const;

            // /* Capacity */
            // bool        empty() const;
            // size_type   size() const;
            // size_type   max_size() const;

            // /* Element access */
            // reference       front();
            // const_reference front() const;
            // reference       back();
            // const_reference back() const;

            // /* Modifiers */
            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last);
            // void assign (size_type n, const value_type& val);
            // void push_front (const value_type& val);
            // void pop_front();
            // void push_back (const value_type& val);
            // void pop_back();
            // // iterator insert (iterator position, const value_type& val);
            // // void insert (iterator position, size_type n, const value_type& val);
            // // void insert (iterator position, InputIterator first, InputIterator last);
            // // iterator erase (iterator position);
            // // iterator erase (iterator first, iterator last);
            // void swap (List& x);
            // void resize (size_type n, value_type val = value_type());
            // void clear();

            // /* Operations */
            // // void splice (iterator position, list& x);	
            // // void splice (iterator position, list& x, iterator i);
            // // void splice (iterator position, list& x, iterator first, iterator last);
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
            // void reverse();

    };

    /* --- Non-member function overloads --- */
    // template <class T, class Alloc>
    // bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
    
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
