/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:31:59 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/06 14:29:04 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../containers/List.hpp"

namespace ft
{
    /***********************/
    /*                     */
    /*     Class Stack     */
    /*                     */
    /***********************/
    template <class T, class Container = List<T> >
    class Stack
    {
        public:
            /************************/
            /*     Member types     */
            /************************/
            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;

            /****************************/
            /*     Member functions     */
            /****************************/

            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
            explicit Stack (const container_type& ctnr = container_type()) : _ctnr(ctnr)
            {
            }


            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~Stack()
            {
            }

            /***************************************************************************/
            /*** other functions --------------------------------------------------- ***/
            bool                empty() const { return (_ctnr.empty()); }
            size_type           size() const { return (_ctnr.size()); }
            value_type          &top() { return (_ctnr.back()); }
            const value_type    &top() const { return (_ctnr.back()); }
            void                push (const value_type& val) { _ctnr.push_back(val); }
            void                pop() { _ctnr.pop_back(); }

            Container const     &getCont() const { return (_ctnr); }
  
        private:
            /*************************************/
            /*     Members for node | private    */
            /*************************************/
            container_type  _ctnr;
    };

    /*****************************************/
    /*                                       */
    /*     Non-member function overloads     */
    /*                                       */
    /*****************************************/
    template <class T, class Container>
    bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) { return (lhs.getCont() == rhs.getCont()); }

    template <class T, class Container>
    bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) { return (lhs.getCont() != rhs.getCont()); }

    template <class T, class Container>
    bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) { return (lhs.getCont() < rhs.getCont()); }

    template <class T, class Container>
    bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) { return (lhs.getCont() <= rhs.getCont()); }

    template <class T, class Container>
    bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) { return (lhs.getCont() > rhs.getCont()); }

    template <class T, class Container>
    bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) { return (lhs.getCont() >= rhs.getCont()); }
}

#endif