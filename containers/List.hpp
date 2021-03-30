/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:31:59 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/03/30 15:55:29 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>

// #include <list>
// std::list<int> list_;

namespace ft
{
    template <typename Content_type>
    class List
    {
        public:
            List();
            List(List const &);
            List &operator=(List const &);
            ~List();
            

        private:
            Content_type    content;
            

    };
}

#endif
