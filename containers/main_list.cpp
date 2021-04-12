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
    ft::List<std::string> list(3, "Hello");
    std::cout << list.getList() << std::endl;
    std::cout << "size: " << list.size() << std::endl;
    std::cout << "empty: " << list.empty() << std::endl;
    std::cout << "max size: " << list.max_size() << std::endl;
    std::cout << "content front: " << list.front() << std::endl;
    std::cout << "content back: " << list.back() << std::endl;
    std::cout << std::endl;

    ft::List<std::string> list_1;
    std::cout << list_1.getList() << std::endl;
    std::cout << "size: " << list_1.size() << std::endl;
    std::cout << "empty: " << list_1.empty() << std::endl;
    std::cout << "max size: " << list_1.max_size() << std::endl;
    std::cout << "content front: " << list_1.front() << std::endl;
    std::cout << "content back: " << list_1.back() << std::endl;
    list_1.push_back("went");
    list_1.push_back("gone");
    list_1.push_front("go");
    list_1.reverse();
    std::cout << std::endl;
    std::cout << list_1.getList() << std::endl;
    std::cout << "size: " << list_1.size() << std::endl;
    std::cout << "empty: " << list_1.empty() << std::endl;
    std::cout << "max size: " << list_1.max_size() << std::endl;
    std::cout << "content front: " << list_1.front() << std::endl;
    std::cout << "content back: " << list_1.back() << std::endl;




     
    return (0);
}