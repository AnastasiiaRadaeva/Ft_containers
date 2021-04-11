/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:49:38 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/11 17:14:34 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

int main()
{
    ft::List<std::string> list(5, "Hello");
    // for (int i = 0; i < 5; i++)
    //     std::cout << list.getList() << std::endl; 
    return (0);
}