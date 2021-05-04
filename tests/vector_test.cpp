/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:30:48 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/04 17:44:46 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/Vector.hpp"
#include <vector>

# define COL_AQUAMARINE "\033[0;36m"
# define COL_GREEN "\033[0;32m"
# define COL_END "\033[0m"

#define PARAMS_ON 1
#define PARAMS_OFF 0

template <class Cont>
void    print_container(Cont &vector, int params, std::string color)
{
    typename Cont::iterator begin;
    for (begin = vector.begin(); begin != vector.end(); begin++)
        std::cout << *begin << " ";
    std::cout << std::endl;
    if (params == 1)
    {
        std::cout << color << "Size: " << COL_END << vector.size();
        std::cout << color << " | Capacity: " << COL_END << vector.capacity() << std::endl;
    }
}

void    constr_default()
{
    std::cout << COL_AQUAMARINE << "Standart vector" << COL_END << std::endl;
    std::vector<int> st_vect;
    std::cout << COL_AQUAMARINE << "Size: " << COL_END << st_vect.size() << std::endl;
    std::cout << COL_AQUAMARINE << "Max size: " << COL_END << st_vect.max_size() << std::endl;
    std::cout << COL_AQUAMARINE << "Capacity: " << COL_END << st_vect.capacity() << std::endl;
    std::cout << COL_AQUAMARINE << "Empty: " << COL_END << st_vect.empty() << std::endl;
    std::cout << std::endl;

    std::cout << COL_GREEN << "My vector" << COL_END << std::endl;
    ft::Vector<int> my_vect;
    std::cout << COL_GREEN << "Size: " << COL_END << my_vect.size() << std::endl;
    std::cout << COL_GREEN << "Max size: " << COL_END << my_vect.max_size() << std::endl;
    std::cout << COL_GREEN << "Capacity: " << COL_END << my_vect.capacity() << std::endl;
    std::cout << COL_GREEN << "Empty: " << COL_END << my_vect.empty() << std::endl;
    std::cout << std::endl;
}

void    constr_fill()
{
    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<int> st_vect(5, 7);
    print_container<std::vector<int> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<int> my_vect(5, 7);
    print_container<ft::Vector<int> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << std::endl;
}

void    constr_range()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    print_container<std::vector<int> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    print_container<ft::Vector<int> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << std::endl;
}

void    constr_copy()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    print_container<ft::Vector<int> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << std::endl;
    std::cout << COL_GREEN << "My copy of vector: " << COL_END;
    ft::Vector<int> my_copy_vect(my_vect);
    print_container<ft::Vector<int> >(my_copy_vect, PARAMS_ON, COL_GREEN);
    std::cout << std::endl;
}

void    assignation_operator()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_AQUAMARINE << "St vector 1: " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    print_container<std::vector<int> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector 2: " << COL_END;
    std::vector<int> st_vect_2(myints, myints + sizeof(myints) / sizeof(int));
    st_vect_2.push_back(5);
    st_vect_2.push_back(1);
    print_container<std::vector<int> >(st_vect_2, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector 1 after operator=: " << COL_END;
    st_vect = st_vect_2;
    print_container<std::vector<int> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout << COL_GREEN << "My vector 1: " << COL_END;
    ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    print_container<ft::Vector<int> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector 2: " << COL_END;
    ft::Vector<int> my_vect_2(myints, myints + sizeof(myints) / sizeof(int));
    my_vect_2.push_back(5);
    my_vect_2.push_back(1);
    print_container<ft::Vector<int> >(my_vect_2, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector 1 after operator=: " << COL_END;
    my_vect = my_vect_2;
    print_container<ft::Vector<int> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << std::endl;
}

void    iterators()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::cout << COL_AQUAMARINE << "St vector with help begin and end: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_OFF, COL_AQUAMARINE);
    std::cout  << COL_AQUAMARINE << "St vector with help rbegin and rend: " << COL_END;
    std::vector<std::string>::reverse_iterator rbegin;
    for (rbegin = st_vect.rbegin(); rbegin != st_vect.rend(); rbegin++)
        std::cout << *rbegin << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector with help begin and end: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_OFF, COL_GREEN);
    std::cout  << COL_GREEN << "My vector with help rbegin and rend: " << COL_END;
    ft::Vector<std::string>::reverse_iterator my_rbegin;
    for (my_rbegin = my_vect.rbegin(); my_rbegin != my_vect.rend(); my_rbegin++)
        std::cout << *my_rbegin << " ";
    std::cout << std::endl;
}

void    sizes()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after resize (decrement): " << COL_END;
    st_vect.resize(5);
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after resize (increment): " << COL_END;
    st_vect.resize(7, "Nastya");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after reserve (decrement - 5): " << COL_END;
    st_vect.reserve(5);
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after reserve (increment - 14): " << COL_END;
    st_vect.reserve(14);
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "Empty: " << COL_END << st_vect.empty() << std::endl;
    std::cout << COL_AQUAMARINE << "St vector is empty: " << COL_END << std::endl;
    st_vect.clear();
    std::cout << COL_AQUAMARINE << "Empty: " << COL_END << st_vect.empty() << std::endl;
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector after resize (decrement): " << COL_END;
    my_vect.resize(5);
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector after resize (increment): " << COL_END;
    my_vect.resize(7, "Nastya");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector after reserve (decrement - 5): " << COL_END;
    my_vect.reserve(5);
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector after reserve (increment - 14`): " << COL_END;
    my_vect.reserve(14);
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "Empty: " << COL_END << my_vect.empty() << std::endl;
    std::cout  << COL_GREEN << "My vector is empty: " << COL_END << std::endl;
    my_vect.clear();
    std::cout << COL_GREEN << "Empty: " << COL_END << my_vect.empty() << std::endl;
}

void    at()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_OFF, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "At 2: " << COL_END << st_vect.at(2) << std::endl;
    std::cout << COL_AQUAMARINE << "At 5: " << COL_END << st_vect.at(5) << std::endl;
    try
    {
        std::cout << COL_AQUAMARINE << "At 6: " << COL_END << st_vect.at(6) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Out or range error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_OFF, COL_GREEN);
    std::cout << COL_GREEN << "At 2: " << COL_END << my_vect.at(2) << std::endl;
    std::cout << COL_GREEN << "At 5: " << COL_END << my_vect.at(5) << std::endl;
    try
    {
        std::cout << COL_GREEN << "At 6: " << COL_END << my_vect.at(6) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Out or range error: " << e.what() << std::endl;
    }
}

void    front_back()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_OFF, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "Front: " << COL_END << st_vect.front() << std::endl;
    std::cout << COL_AQUAMARINE << "Back: " << COL_END << st_vect.back() << std::endl;
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_OFF, COL_GREEN);
    std::cout << COL_GREEN << "Front: " << COL_END << my_vect.front() << std::endl;
    std::cout << COL_GREEN << "Back: " << COL_END << my_vect.back() << std::endl;
}

int main()
{
    std::cout << "_________________________________" << std::endl;
    std::cout << "|                               |" << std::endl;
    std::cout << "|     Constructor | Default     |" << std::endl;
    std::cout << "|_______________________________|" << std::endl << std::endl;
    constr_default();
    std::cout << std::endl;

    std::cout << "______________________________" << std::endl;
    std::cout << "|                            |" << std::endl;
    std::cout << "|     Constructor | Fill     |" << std::endl;
    std::cout << "|____________________________|" << std::endl << std::endl;
    constr_fill();
    std::cout << std::endl;

    std::cout << "_______________________________" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|     Constructor | Range     |" << std::endl;
    std::cout << "|_____________________________|" << std::endl << std::endl;
    constr_range();
    std::cout << std::endl;

    std::cout << "______________________________" << std::endl;
    std::cout << "|                            |" << std::endl;
    std::cout << "|     Constructor | Copy     |" << std::endl;
    std::cout << "|____________________________|" << std::endl << std::endl;
    constr_copy();
    std::cout << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Operator=     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;
    assignation_operator();
    std::cout << std::endl;

    std::cout << "_______________________________________" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|     Begin | End | Rbegin | Rend     |" << std::endl;
    std::cout << "|_____________________________________|" << std::endl << std::endl;
    iterators();
    std::cout << std::endl;

    std::cout << "_________________________________________________________________" << std::endl;
    std::cout << "|                                                               |" << std::endl;
    std::cout << "|     Size | Max_size | Resize | Capacity | Empty | Reserve     |" << std::endl;
    std::cout << "|_______________________________________________________________|" << std::endl << std::endl;
    sizes();
    std::cout << std::endl;

    std::cout << "______________" << std::endl;
    std::cout << "|            |" << std::endl;
    std::cout << "|     At     |" << std::endl;
    std::cout << "|____________|" << std::endl << std::endl;
    at();
    std::cout << std::endl;
    
    std::cout << "________________________" << std::endl;
    std::cout << "|                      |" << std::endl;
    std::cout << "|     Front | Back     |" << std::endl;
    std::cout << "|______________________|" << std::endl << std::endl;
    front_back();
    std::cout << std::endl;
}