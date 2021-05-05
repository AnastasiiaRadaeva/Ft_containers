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

void    assign()
{
    std::string mystr[] = { "Hello", "I'm", "glad" };
    std::string mystr_2[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(5, "Nastya");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after assign range (less than vector): " << COL_END;
    st_vect.assign(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after assign range (greater than vector): " << COL_END;
    st_vect.assign(mystr_2, mystr_2 + sizeof(mystr_2) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(5, "Nastya");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after assign range (less than vector): " << COL_END;
    my_vect.assign(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after assign range (greater than vector): " << COL_END;
    my_vect.assign(mystr_2, mystr_2 + sizeof(mystr_2) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;  


    std::cout << COL_AQUAMARINE << "St vector after assign fill (less than vector): " << COL_END;
    st_vect.assign(1, "Nastya");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after assign fill (greater than vector): " << COL_END;
    st_vect.assign(8, "Happiness");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout << COL_GREEN << "My vector after assign fill (less than vector): " << COL_END;
    my_vect.assign(1, "Nastya");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after assign fill (greater than vector): " << COL_END;
    my_vect.assign(8, "Happiness");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
}

void    push_back()
{
    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(3, "Hello");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    st_vect.clear();
    std::cout << COL_AQUAMARINE << "St vector after clear and push_back \"Hi\": " << COL_END;
    st_vect.push_back("Hi");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after clear and push_back \"you are awesome\": " << COL_END;
    st_vect.push_back("you");
    st_vect.push_back("are");
    st_vect.push_back("awesome");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(3, "Hello");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    my_vect.clear();
    std::cout << COL_GREEN << "My vector after clear and push_back \"Hi\": " << COL_END;
    my_vect.push_back("Hi");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after clear and push_back \"you are awesome\": " << COL_END;
    my_vect.push_back("you");
    my_vect.push_back("are");
    my_vect.push_back("awesome");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
}

void    pop_back()
{
    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(3, "Hello");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after 2 pop_back " << COL_END;
    st_vect.pop_back();
    st_vect.pop_back();
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(3, "Hello");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after 2 pop_back: " << COL_END;
    my_vect.pop_back();
    my_vect.pop_back();
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
}

void    insert_single()
{
    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(3, "Hello");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after insert \"Peer\" in position 3: " << COL_END;
    std::vector<std::string>::iterator it_st = --(st_vect.end());
    it_st = st_vect.insert(it_st, "Peer");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St insert position: " << COL_END << *it_st << std::endl;
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(3, "Hello");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after insert \"Peer\" in position 3: " << COL_END;
    ft::Vector<std::string>::iterator it_my = --(my_vect.end());
    it_my = my_vect.insert(it_my, "Peer");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My insert position: " << COL_END << *it_my << std::endl;
}

void    insert_fill()
{
    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(3, "Hello");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after insert 5 \"Peer\" in position 2: " << COL_END;
    std::vector<std::string>::iterator it_st = ++(st_vect.begin());
    st_vect.insert(it_st, 5, "Peer");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(3, "Hello");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after insert 5 \"Peer\" in position 2: " << COL_END;
    ft::Vector<std::string>::iterator it_my = ++(my_vect.begin());
    my_vect.insert(it_my, 5, "Peer");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
}

void    insert_range()
{
    std::string mystr[] = { "I'm", "glad", "to", "see", "you" };

    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(3, "Hello");
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after insert in position 2: " << COL_END;
    std::vector<std::string>::iterator it_st = ++(st_vect.begin());
    st_vect.insert(it_st, mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(3, "Hello");
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after insert in position 2: " << COL_END;
    ft::Vector<std::string>::iterator it_my = ++(my_vect.begin());
    my_vect.insert(it_my, mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
}

void    erase_single()
{
    std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after erase in position 2: " << COL_END;
    std::vector<std::string>::iterator it_st = ++(st_vect.begin());
    it_st = st_vect.erase(it_st);
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St erase position: " << COL_END << *it_st << std::endl;
    std::cout << COL_AQUAMARINE << "St vector after erase in position 4: " << COL_END;
    it_st = --(st_vect.end());
    it_st = st_vect.erase(it_st);
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St erase position: " << COL_END << *it_st << std::endl;
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after erase in position 2: " << COL_END;
    ft::Vector<std::string>::iterator it_my = ++(my_vect.begin());
    it_my = my_vect.erase(it_my);
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My erase position: " << COL_END << *it_my << std::endl;
    std::cout << COL_GREEN << "My vector after erase in position 4: " << COL_END;
    it_my = --(my_vect.end());
    it_my = my_vect.erase(it_my);
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My erase position: " << COL_END << *it_my << std::endl;
}

void    erase_range()
{
    std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
    std::cout << COL_AQUAMARINE << "St vector: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector after erase in range 2 - 4: " << COL_END;
    std::vector<std::string>::iterator it_st = ++(st_vect.begin());
    it_st = st_vect.erase(it_st, --(st_vect.end()));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St erase position: " << COL_END << *it_st << std::endl;
    std::cout << COL_AQUAMARINE << "St vector after erase in range 2 - 3: " << COL_END;
    it_st = ++(st_vect.begin());
    it_st = st_vect.erase(it_st, st_vect.end());
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St erase position: " << COL_END << *it_st << std::endl;
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My vector after erase in range 2 - 4: " << COL_END;
    ft::Vector<std::string>::iterator it_my = ++(my_vect.begin());
    it_my = my_vect.erase(it_my, --(my_vect.end()));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My erase position: " << COL_END << *it_my << std::endl;
    std::cout << COL_GREEN << "My vector after erase in range 2 - 3: " << COL_END;
    it_my = ++(my_vect.begin());
    it_my = my_vect.erase(it_my, my_vect.end());
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "My erase position: " << COL_END << *it_my << std::endl;
}

void    swap()
{
    std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
    std::cout << COL_AQUAMARINE << "St vector 1: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector 2: " << COL_END;
    std::vector<std::string> st_vect_2(3, "Hello");
    print_container<std::vector<std::string> >(st_vect_2, PARAMS_ON, COL_AQUAMARINE);
    st_vect.swap(st_vect_2);
    std::cout << COL_AQUAMARINE << "St vector 1 after swap: " << COL_END;
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector 2 after swap: " << COL_END;
    print_container<std::vector<std::string> >(st_vect_2, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector 1: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector 2: " << COL_END;
    ft::Vector<std::string> my_vect_2(3, "Hello");
    print_container<ft::Vector<std::string> >(my_vect_2, PARAMS_ON, COL_GREEN);
    my_vect.swap(my_vect_2);
    std::cout  << COL_GREEN << "My vector 1 after swap: " << COL_END;
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector 2 after swap: " << COL_END;
    print_container<ft::Vector<std::string> >(my_vect_2, PARAMS_ON, COL_GREEN);
}

void    clear()
{
    std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
    std::cout << COL_AQUAMARINE << "St vector 1: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "Empty: " << COL_END << st_vect.empty() << std::endl;
    st_vect.clear();
    std::cout << COL_AQUAMARINE << "St vector after clear: " << COL_END;
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "Empty: " << COL_END << st_vect.empty() << std::endl;
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "Empty: " << COL_END << my_vect.empty() << std::endl;
    my_vect.clear();
    std::cout  << COL_GREEN << "My vector after clear: " << COL_END;
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout << COL_GREEN << "Empty: " << COL_END << my_vect.empty() << std::endl;
}

void    equal()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_AQUAMARINE << "St not equivalent: " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> st_vect_2(myints, myints + 2);
    std::cout << (st_vect == st_vect_2) << std::endl;
    std::cout << COL_AQUAMARINE << "St equivalent: " << COL_END;
    st_vect.pop_back();
    st_vect.pop_back();
    std::cout << (st_vect == st_vect_2) << std::endl;
    std::cout << std::endl;

    std::cout << COL_GREEN << "My not equivalent: " << COL_END;
    std::vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> my_vect_2(myints, myints + 2);
    std::cout << (my_vect == my_vect_2) << std::endl;
    std::cout << COL_GREEN << "My equivalent: " << COL_END;
    my_vect.pop_back();
    my_vect.pop_back();
    std::cout << (my_vect == my_vect_2) << std::endl;
}

void    not_equal()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_AQUAMARINE << "St not equivalent: " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> st_vect_2(myints, myints + 2);
    std::cout << (st_vect != st_vect_2) << std::endl;
    std::cout << COL_AQUAMARINE << "St equivalent: " << COL_END;
    st_vect.pop_back();
    st_vect.pop_back();
    std::cout << (st_vect != st_vect_2) << std::endl;
    std::cout << std::endl;

    std::cout << COL_GREEN << "My not equivalent: " << COL_END;
    std::vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> my_vect_2(myints, myints + 2);
    std::cout << (my_vect != my_vect_2) << std::endl;
    std::cout << COL_GREEN << "My equivalent: " << COL_END;
    my_vect.pop_back();
    my_vect.pop_back();
    std::cout << (my_vect != my_vect_2) << std::endl;
}

void    less()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> st_vect_2(myints, myints + 3);
    std::cout << (st_vect < st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_vect_2.push_back(29);
    st_vect_2.push_back(34);
    st_vect_2.push_back(0);
    std::cout << (st_vect < st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
    std::cout << (st_vect < st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.push_back(1);
    st_vect_2.push_back(1);
    std::cout << (st_vect < st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.assign(1, 21);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect < st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect < st_vect_2) << std::endl;
    std::cout << std::endl;



    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    ft::Vector<int> my_vect_2(myints, myints + 3);
    std::cout << (my_vect < my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_vect_2.push_back(29);
    my_vect_2.push_back(34);
    my_vect_2.push_back(0);
    std::cout << (my_vect < my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
    std::cout << (my_vect < my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.push_back(1);
    my_vect_2.push_back(1);
    std::cout << (my_vect < my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.assign(1, 21);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect < my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect < my_vect_2) << std::endl;
}

void    less_or_egual()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> st_vect_2(myints, myints + 3);
    std::cout << (st_vect<=st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_vect_2.push_back(29);
    st_vect_2.push_back(34);
    st_vect_2.push_back(0);
    std::cout << (st_vect<=st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
    std::cout << (st_vect<=st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.push_back(1);
    st_vect_2.push_back(1);
    std::cout << (st_vect<=st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.assign(1, 21);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect<=st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect<=st_vect_2) << std::endl;
    std::cout << std::endl;



    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    ft::Vector<int> my_vect_2(myints, myints + 3);
    std::cout << (my_vect<=my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_vect_2.push_back(29);
    my_vect_2.push_back(34);
    my_vect_2.push_back(0);
    std::cout << (my_vect<=my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
    std::cout << (my_vect<=my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.push_back(1);
    my_vect_2.push_back(1);
    std::cout << (my_vect<=my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.assign(1, 21);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect<=my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect<=my_vect_2) << std::endl;
}

void    greater()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> st_vect_2(myints, myints + 3);
    std::cout << (st_vect > st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_vect_2.push_back(29);
    st_vect_2.push_back(34);
    st_vect_2.push_back(0);
    std::cout << (st_vect > st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
    std::cout << (st_vect > st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.push_back(1);
    st_vect_2.push_back(1);
    std::cout << (st_vect > st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.assign(1, 21);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect > st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect > st_vect_2) << std::endl;
    std::cout << std::endl;



    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    ft::Vector<int> my_vect_2(myints, myints + 3);
    std::cout << (my_vect > my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_vect_2.push_back(29);
    my_vect_2.push_back(34);
    my_vect_2.push_back(0);
    std::cout << (my_vect > my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
    std::cout << (my_vect > my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.push_back(1);
    my_vect_2.push_back(1);
    std::cout << (my_vect > my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.assign(1, 21);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect > my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect > my_vect_2) << std::endl;
}

void    greater_or_equal()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
    std::vector<int> st_vect_2(myints, myints + 3);
    std::cout << (st_vect >= st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_vect_2.push_back(29);
    st_vect_2.push_back(34);
    st_vect_2.push_back(0);
    std::cout << (st_vect >= st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
    std::cout << (st_vect >= st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    st_vect_2.assign(1, 20);
    st_vect_2.push_back(1);
    st_vect_2.push_back(1);
    std::cout << (st_vect >= st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.assign(1, 21);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect >= st_vect_2) << std::endl;

    std::cout << COL_AQUAMARINE << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    st_vect.push_back(1);
    std::cout << (st_vect >= st_vect_2) << std::endl;
    std::cout << std::endl;



    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
    ft::Vector<int> my_vect_2(myints, myints + 3);
    std::cout << (my_vect >= my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_vect_2.push_back(29);
    my_vect_2.push_back(34);
    my_vect_2.push_back(0);
    std::cout << (my_vect >= my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
    std::cout << (my_vect >= my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
    my_vect_2.assign(1, 20);
    my_vect_2.push_back(1);
    my_vect_2.push_back(1);
    std::cout << (my_vect >= my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.assign(1, 21);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect >= my_vect_2) << std::endl;

    std::cout << COL_GREEN << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    my_vect.push_back(1);
    std::cout << (my_vect >= my_vect_2) << std::endl;
}

void    ft_swap()
{
    std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
    std::cout << COL_AQUAMARINE << "St vector 1: " << COL_END;
    std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector 2: " << COL_END;
    std::vector<std::string> st_vect_2(3, "Hello");
    print_container<std::vector<std::string> >(st_vect_2, PARAMS_ON, COL_AQUAMARINE);
    std::swap(st_vect, st_vect_2);
    std::cout << COL_AQUAMARINE << "St vector 1 after swap: " << COL_END;
    print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_AQUAMARINE);
    std::cout << COL_AQUAMARINE << "St vector 2 after swap: " << COL_END;
    print_container<std::vector<std::string> >(st_vect_2, PARAMS_ON, COL_AQUAMARINE);
    std::cout << std::endl;

    std::cout  << COL_GREEN << "My vector 1: " << COL_END;
    ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector 2: " << COL_END;
    ft::Vector<std::string> my_vect_2(3, "Hello");
    print_container<ft::Vector<std::string> >(my_vect_2, PARAMS_ON, COL_GREEN);
    ft::swap(my_vect, my_vect_2);
    std::cout  << COL_GREEN << "My vector 1 after swap: " << COL_END;
    print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_GREEN);
    std::cout  << COL_GREEN << "My vector 2 after swap: " << COL_END;
    print_container<ft::Vector<std::string> >(my_vect_2, PARAMS_ON, COL_GREEN);
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

    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Assign     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;
    assign();
    std::cout << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Push_back     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;
    push_back();
    std::cout << std::endl;

    std::cout << "____________________" << std::endl;
    std::cout << "|                  |" << std::endl;
    std::cout << "|     Pop_back     |" << std::endl;
    std::cout << "|__________________|" << std::endl << std::endl;
    pop_back();
    std::cout << std::endl;

    std::cout << "___________________________________" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "|     Insert | Single element     |" << std::endl;
    std::cout << "|_________________________________|" << std::endl << std::endl;
    insert_single();
    std::cout << std::endl;

    std::cout << "_________________________" << std::endl;
    std::cout << "|                       |" << std::endl;
    std::cout << "|     Insert | Fill     |" << std::endl;
    std::cout << "|_______________________|" << std::endl << std::endl;
    insert_fill();
    std::cout << std::endl;

    std::cout << "__________________________" << std::endl;
    std::cout << "|                        |" << std::endl;
    std::cout << "|     Insert | Range     |" << std::endl;
    std::cout << "|________________________|" << std::endl << std::endl;
    insert_range();
    std::cout << std::endl;

    std::cout << "__________________________________" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|     Erase | Single element     |" << std::endl;
    std::cout << "|________________________________|" << std::endl << std::endl;
    erase_single();
    std::cout << std::endl;

    std::cout << "_________________________" << std::endl;
    std::cout << "|                       |" << std::endl;
    std::cout << "|     Erase | Range     |" << std::endl;
    std::cout << "|_______________________|" << std::endl << std::endl;
    erase_range();
    std::cout << std::endl;

    std::cout << "________________" << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|     Swap     |" << std::endl;
    std::cout << "|______________|" << std::endl << std::endl;
    swap();
    std::cout << std::endl;

    std::cout << "_________________" << std::endl;
    std::cout << "|               |" << std::endl;
    std::cout << "|     Clear     |" << std::endl;
    std::cout << "|_______________|" << std::endl << std::endl;
    clear();
    std::cout << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator==     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;
    equal();
    std::cout << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator!=     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;
    not_equal();
    std::cout << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Operator<     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;
    less();
    std::cout << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator<=     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;
    less_or_egual();
    std::cout << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Operator>     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;
    greater();
    std::cout << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator>=     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;
    greater_or_equal();
    std::cout << std::endl;

    std::cout << "____________________" << std::endl;
    std::cout << "|                  |" << std::endl;
    std::cout << "|     ft::swap     |" << std::endl;
    std::cout << "|__________________|" << std::endl << std::endl;
    ft_swap();
    std::cout << std::endl;

}