/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:19:58 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/15 19:11:20 by kbatwoma         ###   ########.fr       */
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
            const_iterator(ft::node<value_type> *current_node) : _current_node(current_node) {}
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
            reference   operator*() { return (_current_node->content);}
            pointer     operator->() { return (&(this->_current_node->content));}
            const_iterator    &operator++() //++i
            {
                if (_current_node && _current_node->next)
                    _current_node = _current_node->next;
                return (*this);
            }
            const_iterator    operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
            {
                const_iterator tmp(*this);
                operator++();
                return (tmp);
            }
            const_iterator    &operator--()
            {
                if (_current_node && _current_node->prev)
                    _current_node = _current_node->prev;
                return (*this);
            }
            const_iterator    operator--(int)
            {
                const_iterator tmp(*this);
                operator--();
                return (tmp);
            }

            /****************************/
            /*     Friend functions     */
            /****************************/
            template <class iter_first, class iter_second>
                friend bool operator==(iter_first const &a, iter_second const &b);
            template <class iter_first, class iter_second>
                friend bool operator!=(iter_first const &a, iter_second const &b);

            private:
                ft::node<value_type>    const *_current_node;
    };

    /********************/
    /*                  */
    /*     Iterator     */
    /*                  */
    /********************/
    template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class iterator : public ft::const_iterator<T>
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
            ~iterator() {}

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
            template <class iter_first, class iter_second>
                friend bool operator==(iter_first const &a, iter_second const &b);
            template <class iter_first, class iter_second>
                friend bool operator!=(iter_first const &a, iter_second const &b);

        private:
            ft::node<value_type>    *_current_node;
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
            const_reverse_iterator(ft::node<value_type> *current_node) : _current_node(current_node) {} //возможно, нужно будет убрать в приватную зону, чтобы к нему не было доступа
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
            reference   operator*() { return (_current_node->content);}
            pointer     operator->() { return (&(this->_current_node->content));}
            const_reverse_iterator    &operator++() //++i
            {
                if (_current_node && _current_node->prev)
                    _current_node = _current_node->prev;
                return (*this);
            }
            const_reverse_iterator    operator++(int) //i++ возвращаем сам объект, так как локальный объект исчезнет после выхода из функции
            {
                const_reverse_iterator tmp(*this);
                operator++();
                return (tmp);
            }
            const_reverse_iterator    &operator--()
            {
                if (_current_node && _current_node->next)
                    _current_node = _current_node->next;
                return (*this);
            }
            const_reverse_iterator    operator--(int)
            {
                const_reverse_iterator tmp(*this);
                operator--();
                return (tmp);
            }

            /****************************/
            /*     Friend functions     */
            /****************************/
            template <class iter_first, class iter_second>
                friend bool operator==(iter_first const &a, iter_second const &b);
            template <class iter_first, class iter_second>
                friend bool operator!=(iter_first const &a, iter_second const &b);

            private:
                ft::node<value_type>    const *_current_node;
    };

    /****************************/
    /*                          */
    /*     Reverse_iterator     */
    /*                          */
    /****************************/
    template <class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class reverse_iterator : public ft::const_reverse_iterator<T>
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
            reverse_iterator(ft::node<value_type> *current_node) : _current_node(current_node) {}
            reverse_iterator(reverse_iterator const &copy) : _current_node(copy._current_node) {}

            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            reverse_iterator &operator=(reverse_iterator const &b)
            {
                if (this != &b)
                    _current_node = b._current_node;
                return (*this);
            }

            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~reverse_iterator() {}

            /***************************************************************************/
            /*** overloads --------------------------------------------------------- ***/
            reference   operator*() { return (_current_node->content);}
            pointer     operator->() { return (&(this->_current_node->content));}
            reverse_iterator    &operator++() //++i
            {
                if (_current_node && _current_node->prev)
                    _current_node = _current_node->prev;
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
                if (_current_node && _current_node->next)
                    _current_node = _current_node->next;
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
            template <class iter_first, class iter_second>
                friend bool operator==(iter_first const &a, iter_second const &b);
            template <class iter_first, class iter_second>
                friend bool operator!=(iter_first const &a, iter_second const &b);

        private:
            ft::node<value_type>    *_current_node;
    };

    template <class iter_first, class iter_second>
    bool operator==(iter_first const &a, iter_second const &b)
    {
        return (a._current_node == b._current_node);
    }
    template <class iter_first, class iter_second>
    bool operator!=(iter_first const &a, iter_second const &b)
    {
        return (a._current_node != b._current_node);
    }
}

#endif
