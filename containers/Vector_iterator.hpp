/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:27:06 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/04 12:10:40 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>

# define flag 1

namespace ft
{
    namespace vector
    {
        // # if flag < 0
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
                const_iterator(value_type *current_elem) : _current_elem(current_elem) {}
                const_iterator(const_iterator const &copy) : _current_elem(copy._current_elem) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                const_iterator &operator=(const_iterator const &b) const
                {
                    if (this != &b)
                        _current_elem = b._current_elem;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                virtual ~const_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type const    &operator*() { return (*_current_elem);}
                // value_type const    *operator->() { return (&(this->_current_elem));}
                const_iterator      &operator++() //++i
                {
                    if (_current_elem && _current_elem + 1)
                        _current_elem = ++_current_elem;
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
                    if (_current_elem && _current_elem - 1)
                        _current_elem = --_current_elem;
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
                value_type    *get_elem() { return (_current_elem);}

                /****************************/
                /*     Friend functions     */
                /****************************/
                template <class A>
                    friend bool operator==(const_iterator<A> const &a, const_iterator<A> const &b);
                template <class A>
                    friend bool operator!=(const_iterator<A> const &a, const_iterator<A> const &b);

                protected:
                    value_type  *_current_elem;
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
                iterator(value_type *current_elem) : const_iterator<value_type>(current_elem) {}
                iterator(iterator const &copy) : const_iterator<value_type>(copy) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                iterator &operator=(iterator const &b)
                {
                    if (this != &b)
                        this->_current_elem = b._current_elem;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                ~iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                reference   operator*() { return (*(this->_current_elem));}
                // pointer     operator->() { return (&(this->_current_elem->content));}
                iterator    &operator++() //++i
                {
                    if (this->_current_elem && this->_current_elem + 1)
                        this->_current_elem = ++(this->_current_elem);
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
                    if (this->_current_elem && this->_current_elem - 1)
                        this->_current_elem = --(this->_current_elem);
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
                const_reverse_iterator(value_type *current_elem) : _current_elem(current_elem) {}
                const_reverse_iterator(const_reverse_iterator const &copy) : _current_elem(copy._current_elem) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                const_reverse_iterator &operator=(const_reverse_iterator const &b) const
                {
                    if (this != &b)
                        _current_elem = b._current_elem;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                virtual ~const_reverse_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                value_type const        &operator*() { return (*(this->_current_elem));}
                // value_type const        *operator->() { return (&(this->_current_elem->content));}
                const_reverse_iterator  &operator++() //++i
                {
                    if (_current_elem && _current_elem - 1)
                        _current_elem = --_current_elem;
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
                    if (_current_elem && _current_elem + 1)
                        _current_elem = ++_current_elem;
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
                    value_type    *_current_elem;
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
                reverse_iterator(value_type *current_elem) : const_reverse_iterator<value_type>(current_elem) {}
                reverse_iterator(reverse_iterator const &copy) : const_reverse_iterator<value_type>(copy) {}

                /***************************************************************************/
                /*** operator= --------------------------------------------------------- ***/
                reverse_iterator &operator=(reverse_iterator const &b)
                {
                    if (this != &b)
                        this->_current_elem = b._current_elem;
                    return (*this);
                }

                /***************************************************************************/
                /*** destructor -------------------------------------------------------- ***/
                ~reverse_iterator() {}

                /***************************************************************************/
                /*** overloads --------------------------------------------------------- ***/
                reference           operator*() { return (*(this->_current_elem));}
                // pointer             operator->() { return (&(this->_current_elem->content));}
                reverse_iterator    &operator++() //++i
                {
                    if (this->_current_elem && this->_current_elem - 1)
                        this->_current_elem = --(this->_current_elem);
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
                    if (this->_current_elem && this->_current_elem + 1)
                        this->_current_elem = ++(this->_current_elem);
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
            return (a._current_elem == b._current_elem);
        }
        template <class T>
        bool operator!=(const_iterator<T> const &a, const_iterator<T> const &b)
        {
            return (a._current_elem != b._current_elem);
        }
        template <class T>
        bool operator==(const_reverse_iterator<T> const &a, const_reverse_iterator<T> const &b)
        {
            return (a._current_elem == b._current_elem);
        }
        template <class T>
        bool operator!=(const_reverse_iterator<T> const &a, const_reverse_iterator<T> const &b)
        {
            return (a._current_elem != b._current_elem);
        }

        // #endif
    }
}

#endif
