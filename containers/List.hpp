/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:31:59 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/07 11:57:31 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <iterator>

// #include <list>
// std::list<int> list_;

namespace ft
{
    template <typename value_type, typename Alloc = std::allocator<value_type> >
    class List
    {
        public:
            List();
            List(List const &);
            List &operator=(List const &);
            ~List();

            typedef typename Alloc                              allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;

            typedef typename std::iterator<std::bidirectional_iterator_tag, value_type> *iterator;
            typedef typename value_type                   *const_iterator;
            typedef typename reverse_iterator<iterator>         *reverse_iterator;
            typedef typename reverse_iterator<const_iterator>   *const_reverese_iterator;
 






            

        private:
            value_type      _content;
            List            _next;
            List            _previous;

            

    };
}

#endif
