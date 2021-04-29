/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:19:58 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/29 16:14:36 by kbatwoma         ###   ########.fr       */
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
    namespace list
    {
        /**************************/
        /*                        */
        /*     Const_iterator     */
        /*                        */
        /**************************/
        template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
        class const_iterator
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
                const_iterator() {};
                const_iterator(node<value_type> *current_node) : _current_node(current_node) {}
                const_iterator(const_iterator const &copy) : _current_node(copy._current_node) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                const_iterator &operator=(const_iterator const &b) const
                {
                    if (this != &b)
                        _current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                virtual ~const_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type const    &operator*() { return (_current_node->content);}
                value_type const    *operator->() { return (&(this->_current_node->content));}
                const_iterator      &operator++() //++i
                {
                    if (_current_node && _current_node->next)
                        _current_node = _current_node->next;
                    return (*this);
                }
                const_iterator      operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
                {
                    const_iterator tmp(*this);
                    operator++();
                    return (tmp);
                }
                const_iterator      &operator--()
                {
                    if (_current_node && _current_node->prev)
                        _current_node = _current_node->prev;
                    return (*this);
                }
                const_iterator      operator--(int)
                {
                    const_iterator tmp(*this);
                    operator--();
                    return (tmp);
                }

                /***************************************************************************/
                /*** getters ----------------------------------------------------------- ***/
                node<value_type>    *get_node() { return (_current_node);}

                /****************************/
                /*     Friend functions     */
                /****************************/
                template <class A>
                    friend bool operator==(const_iterator<A> const &a, const_iterator<A> const &b);
                template <class A>
                    friend bool operator!=(const_iterator<A> const &a, const_iterator<A> const &b);

                protected:
                    node<value_type>    *_current_node;
        };

        /********************/
        /*                  */
        /*     Iterator     */
        /*                  */
        /********************/
        template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
        class iterator : public const_iterator<T>
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
                iterator(node<value_type> *current_node) : const_iterator<value_type>(current_node) {}
                iterator(iterator const &copy) : const_iterator<value_type>(copy) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                iterator &operator=(iterator const &b)
                {
                    if (this != &b)
                        this->_current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                ~iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                reference   operator*() { return (this->_current_node->content);}
                pointer     operator->() { return (&(this->_current_node->content));}
                iterator    &operator++() //++i
                {
                    if (this->_current_node && this->_current_node->next)
                        this->_current_node = this->_current_node->next;
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
                    if (this->_current_node && this->_current_node->prev)
                        this->_current_node = this->_current_node->prev;
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
                template <class A>
                    friend bool operator==(const_iterator<A> const &a, const_iterator<A> const &b);
                template <class A>
                    friend bool operator!=(const_iterator<A> const &a, const_iterator<A> const &b);
        };

        /**********************************/
        /*                                */
        /*     Const_reverse_iterator     */
        /*                                */
        /**********************************/
        template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
        class const_reverse_iterator
        {
            public:
                /************************/
                /*     Member types     */
                /************************/
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;

                /****************************/
                /*     Member functions     */
                /****************************/

                /***************************************************************************/
                /*** constructors ------------------------------------------------------ ***/
                const_reverse_iterator() {};
                const_reverse_iterator(node<value_type> *current_node) : _current_node(current_node) {} //возможно, нужно будет убрать в приватную зону, чтобы к нему не было доступа
                const_reverse_iterator(const_reverse_iterator const &copy) : _current_node(copy._current_node) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                const_reverse_iterator &operator=(const_reverse_iterator const &b) const
                {
                    if (this != &b)
                        _current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                virtual ~const_reverse_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type const        &operator*() { return (this->_current_node->content);}
                value_type const        *operator->() { return (&(this->_current_node->content));}
                const_reverse_iterator  &operator++() //++i
                {
                    if (_current_node && _current_node->prev)
                        _current_node = _current_node->prev;
                    return (*this);
                }
                const_reverse_iterator  operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
                {
                    const_reverse_iterator tmp(*this);
                    operator++();
                    return (tmp);
                }
                const_reverse_iterator  &operator--()
                {
                    if (_current_node && _current_node->next)
                        _current_node = _current_node->next;
                    return (*this);
                }
                const_reverse_iterator  operator--(int)
                {
                    const_reverse_iterator tmp(*this);
                    operator--();
                    return (tmp);
                }

                /****************************/
                /*     Friend functions     */
                /****************************/
                template <class A>
                    friend bool operator==(const_reverse_iterator<A> const &a, const_reverse_iterator<A> const &b);
                template <class A>
                    friend bool operator!=(const_reverse_iterator<A> const &a, const_reverse_iterator<A> const &b);

                protected:
                    node<value_type>    *_current_node;
        };

        /****************************/
        /*                          */
        /*     Reverse_iterator     */
        /*                          */
        /****************************/
        template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
        class reverse_iterator : public const_reverse_iterator<T>
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
                reverse_iterator(){};
                reverse_iterator(node<value_type> *current_node) : const_reverse_iterator<value_type>(current_node) {}
                reverse_iterator(reverse_iterator const &copy) : const_reverse_iterator<value_type>(copy) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                reverse_iterator &operator=(reverse_iterator const &b)
                {
                    if (this != &b)
                        this->_current_node = b._current_node;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                ~reverse_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                reference           operator*() { return (this->_current_node->content);}
                pointer             operator->() { return (&(this->_current_node->content));}
                reverse_iterator    &operator++() //++i
                {
                    if (this->_current_node && this->_current_node->prev)
                        this->_current_node = this->_current_node->prev;
                    return (*this);
                }
                reverse_iterator    operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
                {
                    reverse_iterator tmp(*this);
                    operator++();
                    return (tmp);
                }
                reverse_iterator    &operator--()
                {
                    if (this->_current_node && this->_current_node->next)
                        this->_current_node = this->_current_node->next;
                    return (*this);
                }
                reverse_iterator    operator--(int)
                {
                    reverse_iterator tmp(*this);
                    operator--();
                    return (tmp);
                }

                /****************************/
                /*     Friend functions     */
                /****************************/            
                template <class A>
                    friend bool operator==(const_reverse_iterator<A> const &a, const_reverse_iterator<A> const &b);
                template <class A>
                    friend bool operator!=(const_reverse_iterator<A> const &a, const_reverse_iterator<A> const &b);
        };

        /*****************************************/
        /*                                       */
        /*     Non-member function overloads     */
        /*                                       */
        /*****************************************/
        template <class T>
        bool operator==(const_iterator<T> const &a, const_iterator<T> const &b)
        {
            return (a._current_node == b._current_node);
        }
        template <class T>
        bool operator!=(const_iterator<T> const &a, const_iterator<T> const &b)
        {
            return (a._current_node != b._current_node);
        }
        template <class T>
        bool operator==(const_reverse_iterator<T> const &a, const_reverse_iterator<T> const &b)
        {
            return (a._current_node == b._current_node);
        }
        template <class T>
        bool operator!=(const_reverse_iterator<T> const &a, const_reverse_iterator<T> const &b)
        {
            return (a._current_node != b._current_node);
        }
    }
}

#endif
