/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:19:58 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/13 17:50:43 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include <iostream>

namespace ft
{
    /**************************/
    /*                        */
    /*     Struct of node     */
    /*                        */
    /**************************/
    template <typename T>
    struct node
    {
        T       content;
        node    *next;
        node    *prev;        
    };

    /********************/
    /*                  */
    /*     Iterator     */
    /*                  */
    /********************/
    template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class iterator
    {
        public:
            /************************/
            /*     Member types     */
            /************************/
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;

            /****************************/
            /*     Member functions     */
            /****************************/

            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
            iterator(){};
            iterator(ft::node<value_type> *current_node) : _current_node(current_node) {}
            iterator(iterator const &copy) : _current_node(copy._current_node) {}

            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            iterator &operator=(iterator const &b)
            {
                if (this != &b)
                    _current_node = b._current_node;
                return (*this);
            }

            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            virtual ~iterator() {}

            /***************************************************************************/
            /*** overloads --------------------------------------------------------- ***/
            reference   operator*() { return (_current_node->content);}
            pointer     operator->() { return (&(this->_current_node->content));}
            iterator    &operator++() //++i
            {
                if (_current_node && _current_node->next)
                    _current_node = _current_node->next;
                return (*this);
            }
            iterator    operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
            {
                iterator tmp(*this);
                operator++();
                return (tmp);
            }
            iterator    &operator--()
            {
                if (_current_node && _current_node->prev)
                    _current_node = _current_node->prev;
                return (*this);
            }
            iterator    operator--(int)
            {
                iterator tmp(*this);
                operator--();
                return (tmp);
            }

            /****************************/
            /*     Friend functions     */
            /****************************/
            friend bool operator==(ft::iterator<T> const &a, ft::iterator<T> const &b)
            {
                if (a._current_node == b._current_node)
                    return (true);
                return (false);
            }
            friend bool operator!=(ft::iterator<T> const &a, ft::iterator<T> const &b)
            {
                if (a._current_node != b._current_node)
                    return (true);
                return (false);
            }

        private:
            ft::node<value_type>    *_current_node;
    };

    /**************************/
    /*                        */
    /*     Const_iterator     */
    /*                        */
    /**************************/
    template <class T>
    class const_iterator : public ft::iterator<T> 
    {
        public:
            /****************************/
            /*     Member functions     */
            /****************************/

            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
            const_iterator() {};
            const_iterator(ft::node<T> *current_node) : ft::iterator<T>(current_node) {}
            const_iterator(const_iterator const &copy) : ft::iterator<T>(copy) {}

            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            const_iterator &operator=(const_iterator const &b) const
            {
                if (this != &b)
                    ft::iterator<T>::operator=(b);
                return (*this);
            }

            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~const_iterator() {}

            /***************************************************************************/
            /*** overloads --------------------------------------------------------- ***/
            // reference   operator*() { return (_current_node->content);}
            // pointer     operator->() { return (&(this->_current_node->content));}
            // iterator    &operator++() //++i
            // {
            //     if (_current_node && _current_node->next)
            //         _current_node = _current_node->next;
            //     return (*this);
            // }
            // iterator    operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
            // {
            //     iterator tmp(*this);
            //     operator++();
            //     return (tmp);
            // }
            // iterator    &operator--()
            // {
            //     if (_current_node && _current_node->prev)
            //         _current_node = _current_node->prev;
            //     return (*this);
            // }
            // iterator    operator--(int)
            // {
            //     iterator tmp(*this);
            //     operator--();
            //     return (tmp);
            // }

            /****************************/
            /*     Friend functions     */
            /****************************/
            friend bool operator==(ft::const_iterator<T> const &a, ft::const_iterator<T> const &b)
            {
                if (a._current_node == b._current_node)
                    return (true);
                return (false);
            }
            friend bool operator!=(ft::const_iterator<T> const &a, ft::const_iterator<T> const &b)
            {
                if (a._current_node != b._current_node)
                    return (true);
                return (false);
            }
    };

    // template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    // class const_iterator
    // {
    //     public:
    //         /************************/
    //         /*     Member types     */
    //         /************************/
    //         typedef T         value_type;
    //         typedef Distance  difference_type;
    //         typedef Pointer   pointer;
    //         typedef Reference reference;

    //         /****************************/
    //         /*     Member functions     */
    //         /****************************/

    //         /***************************************************************************/
    //         /*** constructors ------------------------------------------------------ ***/
    //         const_iterator(){};
    //         const_iterator(ft::node<value_type> *current_node) : _current_node(current_node) {}
    //         const_iterator(const_iterator const &copy) : _current_node(copy._current_node) {}

    //         /***************************************************************************/
    //         /*** operator= --------------------------------------------------------- ***/
    //         const_iterator &operator=(const_iterator const &b)
    //         {
    //             if (this != &b)
    //                 _current_node = b._current_node;
    //             return (*this);
    //         }

    //         /***************************************************************************/
    //         /*** destructor -------------------------------------------------------- ***/
    //         virtual ~const_iterator() {}

    //         /***************************************************************************/
    //         /*** overloads --------------------------------------------------------- ***/
    //         reference   operator*() { return (_current_node->content);}
    //         pointer     operator->() { return (&(this->_current_node->content));}
    //         const_iterator    &operator++() //++i
    //         {
    //             if (_current_node && _current_node->next)
    //                 _current_node = _current_node->next;
    //             return (*this);
    //         }
    //         const_iterator    operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
    //         {
    //             const_iterator tmp(*this);
    //             operator++();
    //             return (tmp);
    //         }
    //         const_iterator    &operator--()
    //         {
    //             if (_current_node && _current_node->prev)
    //                 _current_node = _current_node->prev;
    //             return (*this);
    //         }
    //         const_iterator    operator--(int)
    //         {
    //             const_iterator tmp(*this);
    //             operator--();
    //             return (tmp);
    //         }

    //         /****************************/
    //         /*     Friend functions     */
    //         /****************************/
    //         friend bool operator==(ft::const_iterator<T> const &a, ft::const_iterator<T> const &b)
    //         {
    //             if (a._current_node == b._current_node)
    //                 return (true);
    //             return (false);
    //         }
    //         friend bool operator!=(ft::const_iterator<T> const &a, ft::const_iterator<T> const &b)
    //         {
    //             if (a._current_node != b._current_node)
    //                 return (true);
    //             return (false);
    //         }

    //     private:
    //         ft::node<value_type>    *_current_node;
    // };
}

#endif
