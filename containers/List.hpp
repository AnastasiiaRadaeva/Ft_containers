/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:31:59 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/08 18:20:11 by kbatwoma         ###   ########.fr       */
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
    template <typename T>
    struct node
    {
        T       _content;
        node    *_next;
        node    *_prev;
    };
    template <typename T, typename Alloc = std::allocator<T> >
    class List
    {
        private:
            typedef typename Alloc::rebind<ft::node<T> >::other node_alloc;
            ft::node<T> *_node_list;
            size_t      _current_size;
            node_alloc  _node_alloc;

        public:
            /* --- Member types --- */
            typedef typename T                                              value_type;
            typedef typename Alloc                                          allocator_type;
            typedef typename std::allocator_type::reference                 reference;
            typedef typename std::allocator_type::const_reference           const_reference;
            typedef typename std::allocator_type::pointer                   pointer;
            typedef typename std::allocator_type::const_pointer             const_pointer;
            // typedef typename ft::iterator<std::bidir>                       iterator;
            // typedef typename ft::const_iterator<std::bidir>                 const_iterator;
            // typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
            // typedef typename ft::reverse_iterator<const_iterator>           const_reverese_iterator;
            // typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef size_t                                                  size_type;
            
            /* --- Member functions --- */
            
            /* constructor */
            explicit List(const allocator_type& alloc = allocator_type()) : _current_size(0)
            {
                try
                {
                    _data_list = _node_alloc::allocate(1);
                }
                catch(const std::bad_alloc& ba)
                {
                    std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                }
                

                

                
                



            }
            explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            template <class InputIterator>
            List(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            List(List const &);
            
            /* operator= */
            List &operator=(List const &);
            
            /* destructor */
            ~List();

            /* Iterators */
            // iterator                begin();
            // const_iterator          begin() const;
            // iterator                end();
            // const_iterator          end() const;
            // reverse_iterator        rbegin();
            // const_reverse_iterator  rbegin() const;
            // reverse_iterator        rend();
            // const_reverse_iterator  rend() const;

            /* Capacity */
            bool        empty() const;
            size_type   size() const;
            size_type   max_size() const;

            /* Element access */
            reference       front();
            const_reference front() const;
            reference       back();
            const_reference back() const;

            /* Modifiers */
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last);
            void assign (size_type n, const value_type& val);
            void push_front (const value_type& val);
            void pop_front();
            void push_back (const value_type& val);
            void pop_back();
            // iterator insert (iterator position, const value_type& val);
            // void insert (iterator position, size_type n, const value_type& val);
            // void insert (iterator position, InputIterator first, InputIterator last);
            // iterator erase (iterator position);
            // iterator erase (iterator first, iterator last);
            void swap (List& x);
            void resize (size_type n, value_type val = value_type());
            void clear();

            /* Operations */
            // void splice (iterator position, list& x);	
            // void splice (iterator position, list& x, iterator i);
            // void splice (iterator position, list& x, iterator first, iterator last);
            void remove (const value_type& val);
            template <class Predicate>
            void remove_if (Predicate pred);
            void unique();
            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred);
            void merge (List& x);
            template <class Compare>
            void merge (List& x, Compare comp);
            void sort();
            void sort (Compare comp);
            void reverse();

    };

    /* --- Non-member function overloads --- */
    template <class T, class Alloc>
    bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
    
    template <class T, class Alloc>
    bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
    
    template <class T, class Alloc>
    bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
    
    template <class T, class Alloc>
    bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

    template <class T, class Alloc>
    bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

    template <class T, class Alloc>
    void swap (List<T,Alloc>& x, List<T,Alloc>& y);
}

#endif
