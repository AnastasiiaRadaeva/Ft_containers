/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:23:17 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/06 13:19:47 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../containers/List.hpp"

namespace ft
{
    /***********************/
    /*                     */
    /*     Class Queue     */
    /*                     */
    /***********************/
    template <class T, class Container = List<T> >
    class Queue
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
            explicit Queue (const container_type& ctnr = container_type()) : _ctnr(ctnr)
            {
            }

            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~Queue()
            {
            }

            /***************************************************************************/
            /*** other functions --------------------------------------------------- ***/
            bool                empty() const { return (_ctnr.empty()); }
            size_type           size() const { return (_ctnr.size()); }
            value_type          &front() { return (_ctnr.front()); }
            const value_type    &front() const { return (_ctnr.front()); }
            value_type          &back() { return (_ctnr.back());} 
            const value_type    &back() const { return (_ctnr.back()); }
            void                push (const value_type& val) { _ctnr.push_back(val); }
            void                pop() { _ctnr.pop_front(); }

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
    bool operator== (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) { return (lhs.getCont() == rhs.getCont()); }

    template <class T, class Container>
    bool operator!= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) { return (lhs.getCont() != rhs.getCont()); }

    template <class T, class Container>
    bool operator<  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) { return (lhs.getCont() < rhs.getCont()); }

    template <class T, class Container>
    bool operator<= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) { return (lhs.getCont() <= rhs.getCont()); }

    template <class T, class Container>
    bool operator>  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) { return (lhs.getCont() > rhs.getCont()); }

    template <class T, class Container>
    bool operator>= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) { return (lhs.getCont() >= rhs.getCont()); }
}

#endif