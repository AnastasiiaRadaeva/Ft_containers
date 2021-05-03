/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:30:48 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/02 16:30:49 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/Vector.hpp"
#include <vector>

int main()
{
    std::cout << "_________________________________" << std::endl;
    std::cout << "|                               |" << std::endl;
    std::cout << "|     Constructor | Default     |" << std::endl;
    std::cout << "|_______________________________|" << std::endl << std::endl;

    std::cout << "Standart vector" << std::endl;
    std::vector<int> st_vect;
    std::cout << "Size: " << st_vect.size() << std::endl;
    std::cout << "Max size: " << st_vect.max_size() << std::endl;
    std::cout << "Capacity: " << st_vect.capacity() << std::endl;
    std::cout << "Empty: " << st_vect.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "My vector" << std::endl;
    ft::Vector<int> my_vect;
    std::cout << "Size: " << my_vect.size() << std::endl;
    std::cout << "Max size: " << my_vect.max_size() << std::endl;
    std::cout << "Capacity: " << my_vect.capacity() << std::endl;
    std::cout << "Empty: " << my_vect.empty() << std::endl;
    std::cout << std::endl;


}