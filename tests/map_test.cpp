/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:14:33 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/16 17:25:05 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../containers/Map.hpp"
#include <map>
#include <unistd.h>

# define COL_ST "\033[0;34m"
# define COL_MY "\033[0;35m"
# define COL_END "\033[0m"

#define PARAMS_ON 1
#define PARAMS_OFF 0

template <class Cont>
void    print_container(Cont &map, int params, std::string color)
{
    typename Cont::iterator begin;
    for (begin = map.begin(); begin != map.end(); begin++)
        std::cout << (*begin).first << ":" << (*begin).second << " ";
    std::cout << std::endl;
    if (params == 1)
        std::cout << color << "Size: " << COL_END << map.size() << std::endl;
}

void    constr_default()
{
    std::cout << COL_ST << "Standart map" << COL_END << std::endl;
    std::map<int, std::string> st_map;
    std::cout << COL_ST << "Size: " << COL_END << st_map.size() << std::endl;
    std::cout << COL_ST << "Max size: " << COL_END << st_map.max_size() << std::endl;
    std::cout << COL_ST << "Empty: " << COL_END << st_map.empty() << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map" << COL_END << std::endl;
    ft::Map<int, std::string> my_map;
    std::cout << COL_MY << "Size: " << COL_END << my_map.size() << std::endl;
    std::cout << COL_MY << "Max size: " << COL_END << my_map.max_size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_map.empty() << std::endl;
}

void    constr_range()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;
    first['l']=30;
    first['g']=50;
    first['h']=70;
    first['d']=10;
    first['j']=30;
    first['k']=50;
    first['f']=70;
    std::cout << COL_ST << "St map: " << COL_END;
    print_container<std::map<char, int> >(first, PARAMS_ON, COL_ST);
    std::cout << std::endl;

    std::map<char,int> second (first.begin(),first.end());
    std::cout << COL_ST << "St new map: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    std::cout << std::endl;

    std::cout << COL_MY << "My new map: " << COL_END;
    ft::Map<char,int> second_my(first.begin(),first.end());
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
}

void    constr_copy()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;
    std::cout << std::endl;

    std::map<char,int> second (first.begin(),first.end());
    std::cout << COL_ST << "St map: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    std::cout << std::endl;
    std::map<char,int> second_copy (second);
    std::cout << COL_ST << "St copy of map: " << COL_END;
    print_container<std::map<char, int> >(second_copy, PARAMS_ON, COL_ST);
    std::cout << std::endl;

    std::cout << COL_MY << "My map: " << COL_END;
    ft::Map<char,int> second_my(first.begin(),first.end());
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
    std::cout << std::endl;
    std::cout << COL_MY << "My copy of map: " << COL_END;
    ft::Map<char,int> second_my_copy(second_my);
    print_container<ft::Map<char, int> >(second_my_copy, PARAMS_ON, COL_MY);
}

void  iterators()
{
    std::cout << "--- Direct order ---" << std::endl;
    std::cout << COL_ST << "St map: " << COL_END;
    std::map<char,int> first_st;
    first_st['a']=10;
    first_st['b']=30;
    first_st['c']=50;
    first_st['i']=70;
    first_st['e']=10;
    std::map<char,int>::iterator it_st = first_st.begin();
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "begin: " << COL_END << (*it_st).first << ":" << (*it_st).second << COL_ST << " | --end: " << COL_END << (*(--(first_st.end()))).first << ":" << (*(--(first_st.end()))).second << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map: " << COL_END;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['e']=10;
    ft::Map<char,int>::iterator it_my = first_my.begin();
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "begin: " << COL_END << (*it_my).first << ":" << (*it_my).second << COL_ST << " | --end: " << COL_END << (*(--(first_my.end()))).first << ":" << (*(--(first_my.end()))).second << std::endl;
    std::cout << std::endl;

    std::cout << "--- Reverse order ---" << std::endl;
    std::cout << COL_ST << "St map: " << COL_END;
    std::map<char,int>::reverse_iterator begin;
    for (begin = first_st.rbegin(); begin != first_st.rend(); begin++)
        std::cout << (*begin).first << ":" << (*begin).second << " ";
    std::cout << std::endl;
    std::cout << COL_ST << "rbegin: " << COL_END << (*(first_st.rbegin())).first << ":" << (*(first_st.rbegin())).second << COL_ST << " | --end: " << COL_END << (*(--(first_st.rend()))).first << ":" << (*(--(first_st.rend()))).second << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map: " << COL_END;
    ft::Map<char,int>::reverse_iterator begin_my;
    for (begin_my = first_my.rbegin(); begin_my != first_my.rend(); begin_my++)
        std::cout << (*begin_my).first << ":" << (*begin_my).second << " ";
    std::cout << std::endl;
    std::cout << COL_MY << "rbegin: " << COL_END << (*(first_my.rbegin())).first << ":" << (*(first_my.rbegin())).second << COL_MY << " | --end: " << COL_END << (*(--(first_my.rend()))).first << ":" << (*(--(first_my.rend()))).second << std::endl;

    // std::cout << COL_MY << "My map: " << COL_END;
    // ft::Map<char,int> first_my;
    // first_my['a']=10;
    // first_my['b']=30;
    // first_my['c']=50;
    // first_my['i']=70;
    // first_my['e']=10;
    // ft::Map<char,int>::iterator it_my = first_my.begin();
    // print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    // std::cout << COL_MY << "begin: " << COL_END << (*it_my).first << ":" << (*it_my).second << COL_ST << " | --end: " << COL_END << (*(--(first_my.end()))).first << ":" << (*(--(first_my.end()))).second << std::endl;
    // std::cout << std::endl;


    // std::cout << COL_MY << "My map after operator[]: " << COL_END;
    // print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    // std::cout << COL_MY << "a: " << COL_END << first_my['a'] << COL_MY << " | b: " << COL_END << first_my['b'] << COL_MY << " | c: " << COL_END << first_my['c'] << std::endl;


    // std::map<char,int> first;
    // first['a']=10;
    // first['b']=30;
    // first['c']=50;
    // first['d']=70;


    // std::cout << COL_ST << "St map: " << COL_END;
    // std::map<char,int>::reverse_iterator  begin;
    // for (begin = first.rbegin(); begin != first.rend(); begin++)
    //     std::cout << (*begin).first << ":" << (*begin).second << " ";
    // std::cout << std::endl;
    // std::cout << COL_ST << "Size: " << COL_END << first.size() << std::endl;
    // std::cout << std::endl;

    // std::map<char,int> second (first.begin(),first.end());
    // std::cout << COL_ST << "St new map: " << COL_END;
    // for (begin = second.rbegin(); begin != second.rend(); begin++)
    //     std::cout << (*begin).first << ":" << (*begin).second << " ";
    // std::cout << std::endl;
    // std::cout << COL_ST << "Size: " << COL_END << second.size() << std::endl;
    // std::cout << std::endl;

    // std::cout << COL_MY << "My new map: " << COL_END;
    // ft::Map<char,int> second_my(first.begin(),first.end());
    // ft::Map<char,int>::reverse_iterator my_begin;
    // for (my_begin = second_my.rbegin(); my_begin != second_my.rend(); my_begin++)
    //     std::cout << (*my_begin).first << ":" << (*my_begin).second << " ";
    // std::cout << std::endl;
    // std::cout << COL_MY << "Size: " << COL_END << second_my.size() << std::endl;
}

// void    assignation_operator()
// {
//     int myints[] = { 16, 2, 77, 29 };

//     std::cout << COL_ST << "St vector 1: " << COL_END;
//     std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
//     print_container<std::vector<int> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector 2: " << COL_END;
//     std::vector<int> st_vect_2(myints, myints + sizeof(myints) / sizeof(int));
//     st_vect_2.push_back(5);
//     st_vect_2.push_back(1);
//     print_container<std::vector<int> >(st_vect_2, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector 1 after operator=: " << COL_END;
//     st_vect = st_vect_2;
//     print_container<std::vector<int> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << std::endl;

//     std::cout << COL_MY << "My vector 1: " << COL_END;
//     ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
//     print_container<ft::Vector<int> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My vector 2: " << COL_END;
//     ft::Vector<int> my_vect_2(myints, myints + sizeof(myints) / sizeof(int));
//     my_vect_2.push_back(5);
//     my_vect_2.push_back(1);
//     print_container<ft::Vector<int> >(my_vect_2, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My vector 1 after operator=: " << COL_END;
//     my_vect = my_vect_2;
//     print_container<ft::Vector<int> >(my_vect, PARAMS_ON, COL_MY);
// }

// void    iterators()
// {
//     std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

//     std::cout << COL_ST << "St vector with help begin and end: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_OFF, COL_ST);
//     std::cout  << COL_ST << "St vector with help rbegin and rend: " << COL_END;
//     std::vector<std::string>::reverse_iterator rbegin;
//     for (rbegin = st_vect.rbegin(); rbegin != st_vect.rend(); rbegin++)
//         std::cout << *rbegin << " ";
//     std::cout << std::endl;
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector with help begin and end: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_OFF, COL_MY);
//     std::cout  << COL_MY << "My vector with help rbegin and rend: " << COL_END;
//     ft::Vector<std::string>::reverse_iterator my_rbegin;
//     for (my_rbegin = my_vect.rbegin(); my_rbegin != my_vect.rend(); my_rbegin++)
//         std::cout << *my_rbegin << " ";
//     std::cout << std::endl;
// }

// void    sizes()
// {
//     std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

//     std::cout << COL_ST << "St vector: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after resize (decrement): " << COL_END;
//     st_vect.resize(5);
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after resize (increment): " << COL_END;
//     st_vect.resize(7, "Nastya");
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after reserve (decrement - 5): " << COL_END;
//     st_vect.reserve(5);
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after reserve (increment - 14): " << COL_END;
//     st_vect.reserve(14);
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "Empty: " << COL_END << st_vect.empty() << std::endl;
//     std::cout << COL_ST << "St vector is empty: " << COL_END << std::endl;
//     st_vect.clear();
//     std::cout << COL_ST << "Empty: " << COL_END << st_vect.empty() << std::endl;
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout  << COL_MY << "My vector after resize (decrement): " << COL_END;
//     my_vect.resize(5);
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout  << COL_MY << "My vector after resize (increment): " << COL_END;
//     my_vect.resize(7, "Nastya");
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout  << COL_MY << "My vector after reserve (decrement - 5): " << COL_END;
//     my_vect.reserve(5);
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout  << COL_MY << "My vector after reserve (increment - 14`): " << COL_END;
//     my_vect.reserve(14);
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "Empty: " << COL_END << my_vect.empty() << std::endl;
//     std::cout  << COL_MY << "My vector is empty: " << COL_END << std::endl;
//     my_vect.clear();
//     std::cout << COL_MY << "Empty: " << COL_END << my_vect.empty() << std::endl;
// }

// void    at()
// {
//     std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

//     std::cout << COL_ST << "St vector: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_OFF, COL_ST);
//     std::cout << COL_ST << "At 2: " << COL_END << st_vect.at(2) << std::endl;
//     std::cout << COL_ST << "At 5: " << COL_END << st_vect.at(5) << std::endl;
//     try
//     {
//         std::cout << COL_ST << "At 6: " << COL_END << st_vect.at(6) << std::endl;
//     }
//     catch(const std::out_of_range& e)
//     {
//         std::cerr << "Out or range error: " << e.what() << std::endl;
//     }
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_OFF, COL_MY);
//     std::cout << COL_MY << "At 2: " << COL_END << my_vect.at(2) << std::endl;
//     std::cout << COL_MY << "At 5: " << COL_END << my_vect.at(5) << std::endl;
//     try
//     {
//         std::cout << COL_MY << "At 6: " << COL_END << my_vect.at(6) << std::endl;
//     }
//     catch(const std::out_of_range& e)
//     {
//         std::cerr << "Out or range error: " << e.what() << std::endl;
//     }
// }

// void    front_back()
// {
//     std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

//     std::cout << COL_ST << "St vector: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_OFF, COL_ST);
//     std::cout << COL_ST << "Front: " << COL_END << st_vect.front() << std::endl;
//     std::cout << COL_ST << "Back: " << COL_END << st_vect.back() << std::endl;
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_OFF, COL_MY);
//     std::cout << COL_MY << "Front: " << COL_END << my_vect.front() << std::endl;
//     std::cout << COL_MY << "Back: " << COL_END << my_vect.back() << std::endl;
// }

// void    assign()
// {
//     std::string mystr[] = { "Hello", "I'm", "glad" };
//     std::string mystr_2[] = { "Hello", "I'm", "glad", "to", "see", "you" };

//     std::cout << COL_ST << "St vector: " << COL_END;
//     std::vector<std::string> st_vect(5, "Nastya");
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after assign range (less than vector): " << COL_END;
//     st_vect.assign(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after assign range (greater than vector): " << COL_END;
//     st_vect.assign(mystr_2, mystr_2 + sizeof(mystr_2) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector: " << COL_END;
//     ft::Vector<std::string> my_vect(5, "Nastya");
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My vector after assign range (less than vector): " << COL_END;
//     my_vect.assign(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My vector after assign range (greater than vector): " << COL_END;
//     my_vect.assign(mystr_2, mystr_2 + sizeof(mystr_2) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;  


//     std::cout << COL_ST << "St vector after assign fill (less than vector): " << COL_END;
//     st_vect.assign(1, "Nastya");
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after assign fill (greater than vector): " << COL_END;
//     st_vect.assign(8, "Happiness");
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << std::endl;

//     std::cout << COL_MY << "My vector after assign fill (less than vector): " << COL_END;
//     my_vect.assign(1, "Nastya");
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My vector after assign fill (greater than vector): " << COL_END;
//     my_vect.assign(8, "Happiness");
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
// }

void    operator_access()
{
    std::cout << COL_ST << "St map before operator[]: " << COL_END;
    std::map<char,int> first_st;
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    first_st['a']=10;
    first_st['b']=30;
    first_st['c']=50;
    first_st['i']=70;
    first_st['a']=20;
    first_st['e']=10;
    std::cout << COL_ST << "St map after operator[]: " << COL_END;
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "a: " << COL_END << first_st['a'] << COL_ST << " | b: " << COL_END << first_st['b'] << COL_ST << " | c: " << COL_END << first_st['c'] << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map before operator[]: " << COL_END;
    ft::Map<char,int> first_my;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['a']=20;
    first_my['e']=10;

    std::cout << COL_MY << "My map after operator[]: " << COL_END;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "a: " << COL_END << first_my['a'] << COL_MY << " | b: " << COL_END << first_my['b'] << COL_MY << " | c: " << COL_END << first_my['c'] << std::endl;
}

void    insert_single()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;

    std::pair<char, int> elem_1 = std::make_pair('d', 25);
    std::pair<char, int> elem_2 = std::make_pair('c', 25);
    std::pair<char, int> elem_3 = std::make_pair('r', 47);
    std::pair<char, int> elem_4 = std::make_pair('h', 25);
    std::pair<std::map<char, int>::iterator, bool> check_st;
    std::pair<ft::Map<char, int>::iterator, bool> check_my;

    std::map<char,int> second (first.begin(),first.end());
    std::cout << COL_ST << "St map before insert: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    std::cout << COL_MY << "My map before insert: " << COL_END;
    ft::Map<char,int> second_my(first.begin(),first.end());
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
    std::cout << std::endl;

    check_st = second.insert(elem_1);
    std::cout << COL_ST << "St map after insert \"d\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*(check_st.first)).first << COL_ST << " | In map: " << COL_END << (check_st.second ? "yes" : "no") << std::endl;
    check_my = second_my.insert(elem_1);
    std::cout << COL_MY << "My map after insert \"d\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*(check_my.first)).first << COL_MY << " | In map: " << COL_END << (check_my.second ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    check_st = second.insert(elem_2);
    std::cout << COL_ST << "St map after insert \"c\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*(check_st.first)).first << COL_ST << " | In map: " << COL_END << (check_st.second ? "yes" : "no") << std::endl;
    check_my = second_my.insert(elem_2);
    std::cout << COL_MY << "My map after insert \"d\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*(check_my.first)).first << COL_MY << " | In map: " << COL_END << (check_my.second ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    check_st = second.insert(elem_3);
    std::cout << COL_ST << "St map after insert \"r\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*(check_st.first)).first << COL_ST << " | In map: " << COL_END << (check_st.second ? "yes" : "no") << std::endl;
    check_my = second_my.insert(elem_3);
    std::cout << COL_MY << "My map after insert \"d\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*(check_my.first)).first << COL_MY << " | In map: " << COL_END << (check_my.second ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    check_st = second.insert(elem_4);
    std::cout << COL_ST << "St map after insert \"h\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*(check_st.first)).first << COL_ST << " | In map: " << COL_END << (check_st.second ? "yes" : "no") << std::endl;
    check_my = second_my.insert(elem_4);
    std::cout << COL_MY << "My map after insert \"d\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*(check_my.first)).first << COL_MY << " | In map: " << COL_END << (check_my.second ? "yes" : "no") << std::endl;
}

void    insert_with_hint()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;

    std::pair<char, int> elem_1 = std::make_pair('d', 25);
    std::pair<char, int> elem_2 = std::make_pair('c', 25);
    std::pair<char, int> elem_3 = std::make_pair('r', 47);
    std::pair<char, int> elem_4 = std::make_pair('h', 25);

    std::map<char,int> second (first.begin(),first.end());
    std::map<char, int>::iterator it_st = second.begin();
    it_st++;
    it_st++; //на c
    std::cout << COL_ST << "St map before insert: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    std::cout << COL_MY << "My map before insert: " << COL_END;
    ft::Map<char,int> second_my(first.begin(),first.end());
    ft::Map<char,int>::iterator it_my = second_my.begin();
    it_my++;
    it_my++;//c
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
    std::cout << std::endl;

    it_st = second.insert(it_st, elem_1);
    std::cout << COL_ST << "St map after insert \"d\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*it_st).first << COL_END << std::endl;
    it_my = second_my.insert(it_my, elem_1);
    std::cout << COL_MY << "My map after insert \"d\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*it_my).first << std::endl;
    std::cout << std::endl;

    it_st = second.insert(it_st, elem_2);
    std::cout << COL_ST << "St map after insert \"c\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*it_st).first << COL_END << std::endl;
    it_my = second_my.insert(it_my, elem_2);
    std::cout << COL_MY << "My map after insert \"c\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*it_my).first << std::endl;
    std::cout << std::endl;

    it_st = second.insert(it_st, elem_3);
    std::cout << COL_ST << "St map after insert \"r\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*it_st).first << COL_END << std::endl;
    it_my = second_my.insert(it_my, elem_3);
    std::cout << COL_MY << "My map after insert \"r\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*it_my).first << std::endl;
    std::cout << std::endl;

    it_st = second.insert(it_st, elem_4);
    std::cout << COL_ST << "St map after insert \"h\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*it_st).first << COL_END << std::endl;
    it_my = second_my.insert(it_my, elem_4);
    std::cout << COL_MY << "My map after insert \"h\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*it_my).first << std::endl;
}

void    insert_range()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;
    std::cout << COL_ST << "Map 1: " << COL_END;
    print_container<std::map<char, int> >(first, PARAMS_ON, COL_ST);

    std::map<char,int> first_2;
    first_2['z']=10;
    first_2['d']=30;
    first_2['w']=50;
    first_2['y']=70;
    first_2['e']=10;
    std::cout << COL_ST << "Map 2: " << COL_END;
    print_container<std::map<char, int> >(first_2, PARAMS_ON, COL_ST);
    std::cout << std::endl;
    
    std::map<char,int> second (first.begin(),first.end());
    std::cout << COL_ST << "St map before insert: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    std::cout << COL_MY << "My map before insert: " << COL_END;
    ft::Map<char,int> second_my(first.begin(),first.end());
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
    std::cout << std::endl;

    second.insert(first_2.begin(), first_2.end());
    std::cout << COL_ST << "St map after insert: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    
    second_my.insert(first_2.begin(), first_2.end());
    std::cout << COL_MY << "My map after insert: " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
    std::cout << std::endl;

    second.insert(++(second.begin()), --(second.end()));
    std::cout << COL_ST << "St map after insert from herself: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    
    second_my.insert(++(second_my.begin()), --(second_my.end()));
    std::cout << COL_MY << "My map after insert from herself: " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
}

// void    erase_single()
// {
//     std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
//     std::cout << COL_ST << "St vector: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after erase in position 2: " << COL_END;
//     std::vector<std::string>::iterator it_st = ++(st_vect.begin());
//     it_st = st_vect.erase(it_st);
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St erase position: " << COL_END << *it_st << std::endl;
//     std::cout << COL_ST << "St vector after erase in position 4: " << COL_END;
//     it_st = --(st_vect.end());
//     it_st = st_vect.erase(it_st);
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St erase position: " << COL_END << *it_st << std::endl;
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My vector after erase in position 2: " << COL_END;
//     ft::Vector<std::string>::iterator it_my = ++(my_vect.begin());
//     it_my = my_vect.erase(it_my);
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My erase position: " << COL_END << *it_my << std::endl;
//     std::cout << COL_MY << "My vector after erase in position 4: " << COL_END;
//     it_my = --(my_vect.end());
//     it_my = my_vect.erase(it_my);
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My erase position: " << COL_END << *it_my << std::endl;
// }

// void    erase_range()
// {
//     std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
//     std::cout << COL_ST << "St vector: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector after erase in range 2 - 4: " << COL_END;
//     std::vector<std::string>::iterator it_st = ++(st_vect.begin());
//     it_st = st_vect.erase(it_st, --(st_vect.end()));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St erase position: " << COL_END << *it_st << std::endl;
//     std::cout << COL_ST << "St vector after erase in range 2 - 3: " << COL_END;
//     it_st = ++(st_vect.begin());
//     it_st = st_vect.erase(it_st, st_vect.end());
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St erase position: " << COL_END << *it_st << std::endl;
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My vector after erase in range 2 - 4: " << COL_END;
//     ft::Vector<std::string>::iterator it_my = ++(my_vect.begin());
//     it_my = my_vect.erase(it_my, --(my_vect.end()));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My erase position: " << COL_END << *it_my << std::endl;
//     std::cout << COL_MY << "My vector after erase in range 2 - 3: " << COL_END;
//     it_my = ++(my_vect.begin());
//     it_my = my_vect.erase(it_my, my_vect.end());
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "My erase position: " << COL_END << *it_my << std::endl;
// }

void    swap()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;
    std::map<char,int> second;
    second['z']=10;
    second['d']=30;
    second['w']=50;
    second['y']=70;
    second['e']=10;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['e']=10;
    ft::Map<char,int> second_my;
    second_my['z']=10;
    second_my['d']=30;
    second_my['w']=50;
    second_my['y']=70;
    second_my['e']=10;
    std::cout << COL_ST << "St map 1 before swap: " << COL_END;
    print_container<std::map<char, int> >(first, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map 2 before swap: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    std::cout << COL_MY << "My map 1 before swap: " << COL_END;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map 2 before swap: " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
    std::cout << std::endl;
    first.swap(second);
    first_my.swap(second_my);
    std::cout << COL_ST << "St map 1 after swap: " << COL_END;
    print_container<std::map<char, int> >(first, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map 2 after swap: " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_ON, COL_ST);
    std::cout << COL_MY << "My map 1 after swap: " << COL_END;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map 2 after swap: " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
}

// void    clear()
// {
//     std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
//     std::cout << COL_ST << "St vector: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "Empty: " << COL_END << st_vect.empty() << std::endl;
//     st_vect.clear();
//     std::cout << COL_ST << "St vector after clear: " << COL_END;
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "Empty: " << COL_END << st_vect.empty() << std::endl;
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "Empty: " << COL_END << my_vect.empty() << std::endl;
//     my_vect.clear();
//     std::cout  << COL_MY << "My vector after clear: " << COL_END;
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout << COL_MY << "Empty: " << COL_END << my_vect.empty() << std::endl;
// }

void    find()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['e']=10;

    std::cout << COL_ST << "St map: " << COL_END;
    print_container<std::map<char, int> >(first, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Find b: " << COL_END << (*(first.find('b'))).first << ":" << (*(first.find('b'))).second << COL_ST << " | Find i: " << COL_END << (*(first.find('i'))).first << ":" << (*(first.find('i'))).second << COL_ST << " | Find m: " << COL_END << (*(first.find('m'))).first << ":" << (*(first.find('m'))).second << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map: " << COL_END;
    print_container<ft::Map<char, int> >(first_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Find b: " << COL_END << (*(first_my.find('b'))).first << ":" << (*(first_my.find('b'))).second << COL_MY << " | Find i: " << COL_END << (*(first_my.find('i'))).first << ":" << (*(first_my.find('i'))).second << COL_ST << " | Find m: " << COL_END << (*(first.find('m'))).first << ":" << (*(first.find('m'))).second << std::endl;
}

void    count()
{
    std::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['i']=70;
    first['e']=10;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['e']=10;

    std::cout << COL_ST << "St map: " << COL_END;
    print_container<std::map<char, int> >(first, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Count b: " << COL_END << first.count('b') << COL_ST << " | Count i: " << COL_END << first.count('i') << COL_ST << " | Count m: " << COL_END << first.count('m') << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map: " << COL_END;
    print_container<ft::Map<char, int> >(first_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Count b: " << COL_END << first_my.count('b') << COL_MY << " | Count i: " << COL_END << first_my.count('i') << COL_MY << " | Count m: " << COL_END << first_my.count('m') << std::endl;
    }

// void    equal()
// {
//     int myints[] = { 16, 2, 77, 29 };

//     std::cout << COL_ST << "St not equivalent: " << COL_END;
//     std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> st_vect_2(myints, myints + 2);
//     std::cout << (st_vect == st_vect_2) << std::endl;
//     std::cout << COL_ST << "St equivalent: " << COL_END;
//     st_vect.pop_back();
//     st_vect.pop_back();
//     std::cout << (st_vect == st_vect_2) << std::endl;
//     std::cout << std::endl;

//     std::cout << COL_MY << "My not equivalent: " << COL_END;
//     std::vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> my_vect_2(myints, myints + 2);
//     std::cout << (my_vect == my_vect_2) << std::endl;
//     std::cout << COL_MY << "My equivalent: " << COL_END;
//     my_vect.pop_back();
//     my_vect.pop_back();
//     std::cout << (my_vect == my_vect_2) << std::endl;
// }

// void    not_equal()
// {
//     int myints[] = { 16, 2, 77, 29 };

//     std::cout << COL_ST << "St not equivalent: " << COL_END;
//     std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> st_vect_2(myints, myints + 2);
//     std::cout << (st_vect != st_vect_2) << std::endl;
//     std::cout << COL_ST << "St equivalent: " << COL_END;
//     st_vect.pop_back();
//     st_vect.pop_back();
//     std::cout << (st_vect != st_vect_2) << std::endl;
//     std::cout << std::endl;

//     std::cout << COL_MY << "My not equivalent: " << COL_END;
//     std::vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> my_vect_2(myints, myints + 2);
//     std::cout << (my_vect != my_vect_2) << std::endl;
//     std::cout << COL_MY << "My equivalent: " << COL_END;
//     my_vect.pop_back();
//     my_vect.pop_back();
//     std::cout << (my_vect != my_vect_2) << std::endl;
// }

// void    less()
// {
//     int myints[] = { 16, 2, 77, 29, 34 };

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> st_vect_2(myints, myints + 3);
//     std::cout << (st_vect < st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     st_vect_2.push_back(29);
//     st_vect_2.push_back(34);
//     st_vect_2.push_back(0);
//     std::cout << (st_vect < st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (st_vect < st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.push_back(1);
//     st_vect_2.push_back(1);
//     std::cout << (st_vect < st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.assign(1, 21);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect < st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect < st_vect_2) << std::endl;
//     std::cout << std::endl;



//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
//     ft::Vector<int> my_vect_2(myints, myints + 3);
//     std::cout << (my_vect < my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     my_vect_2.push_back(29);
//     my_vect_2.push_back(34);
//     my_vect_2.push_back(0);
//     std::cout << (my_vect < my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (my_vect < my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.push_back(1);
//     my_vect_2.push_back(1);
//     std::cout << (my_vect < my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.assign(1, 21);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect < my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect < my_vect_2) << std::endl;
// }

// void    less_or_egual()
// {
//     int myints[] = { 16, 2, 77, 29, 34 };

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> st_vect_2(myints, myints + 3);
//     std::cout << (st_vect<=st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     st_vect_2.push_back(29);
//     st_vect_2.push_back(34);
//     st_vect_2.push_back(0);
//     std::cout << (st_vect<=st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (st_vect<=st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.push_back(1);
//     st_vect_2.push_back(1);
//     std::cout << (st_vect<=st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.assign(1, 21);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect<=st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect<=st_vect_2) << std::endl;
//     std::cout << std::endl;



//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
//     ft::Vector<int> my_vect_2(myints, myints + 3);
//     std::cout << (my_vect<=my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     my_vect_2.push_back(29);
//     my_vect_2.push_back(34);
//     my_vect_2.push_back(0);
//     std::cout << (my_vect<=my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (my_vect<=my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.push_back(1);
//     my_vect_2.push_back(1);
//     std::cout << (my_vect<=my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.assign(1, 21);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect<=my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect<=my_vect_2) << std::endl;
// }

// void    greater()
// {
//     int myints[] = { 16, 2, 77, 29, 34 };

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> st_vect_2(myints, myints + 3);
//     std::cout << (st_vect > st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     st_vect_2.push_back(29);
//     st_vect_2.push_back(34);
//     st_vect_2.push_back(0);
//     std::cout << (st_vect > st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (st_vect > st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.push_back(1);
//     st_vect_2.push_back(1);
//     std::cout << (st_vect > st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.assign(1, 21);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect > st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect > st_vect_2) << std::endl;
//     std::cout << std::endl;



//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
//     ft::Vector<int> my_vect_2(myints, myints + 3);
//     std::cout << (my_vect > my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     my_vect_2.push_back(29);
//     my_vect_2.push_back(34);
//     my_vect_2.push_back(0);
//     std::cout << (my_vect > my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (my_vect > my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.push_back(1);
//     my_vect_2.push_back(1);
//     std::cout << (my_vect > my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.assign(1, 21);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect > my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect > my_vect_2) << std::endl;
// }

// void    greater_or_equal()
// {
//     int myints[] = { 16, 2, 77, 29, 34 };

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     std::vector<int> st_vect(myints, myints + sizeof(myints) / sizeof(int));
//     std::vector<int> st_vect_2(myints, myints + 3);
//     std::cout << (st_vect >= st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     st_vect_2.push_back(29);
//     st_vect_2.push_back(34);
//     st_vect_2.push_back(0);
//     std::cout << (st_vect >= st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.insert(st_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (st_vect >= st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     st_vect_2.assign(1, 20);
//     st_vect_2.push_back(1);
//     st_vect_2.push_back(1);
//     std::cout << (st_vect >= st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.assign(1, 21);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect >= st_vect_2) << std::endl;

//     std::cout << COL_ST << "St 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     st_vect.push_back(1);
//     std::cout << (st_vect >= st_vect_2) << std::endl;
//     std::cout << std::endl;



//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
//     ft::Vector<int> my_vect(myints, myints + sizeof(myints) / sizeof(int));
//     ft::Vector<int> my_vect_2(myints, myints + 3);
//     std::cout << (my_vect >= my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
//     my_vect_2.push_back(29);
//     my_vect_2.push_back(34);
//     my_vect_2.push_back(0);
//     std::cout << (my_vect >= my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 6 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.insert(my_vect_2.end(), myints + 1, myints + 5);
//     std::cout << (my_vect >= my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 2 is greater): " << COL_END;
//     my_vect_2.assign(1, 20);
//     my_vect_2.push_back(1);
//     my_vect_2.push_back(1);
//     std::cout << (my_vect >= my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 3 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.assign(1, 21);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect >= my_vect_2) << std::endl;

//     std::cout << COL_MY << "My 1 - 5 elem, 2 - 7 elem (first elem in vector 1 is greater): " << COL_END;
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     my_vect.push_back(1);
//     std::cout << (my_vect >= my_vect_2) << std::endl;
// }

// void    ft_swap()
// {
//     std::string mystr[] = { "I'm", "glad", "to", "see", "you" };
    
//     std::cout << COL_ST << "St vector 1: " << COL_END;
//     std::vector<std::string> st_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector 2: " << COL_END;
//     std::vector<std::string> st_vect_2(3, "Hello");
//     print_container<std::vector<std::string> >(st_vect_2, PARAMS_ON, COL_ST);
//     std::swap(st_vect, st_vect_2);
//     std::cout << COL_ST << "St vector 1 after swap: " << COL_END;
//     print_container<std::vector<std::string> >(st_vect, PARAMS_ON, COL_ST);
//     std::cout << COL_ST << "St vector 2 after swap: " << COL_END;
//     print_container<std::vector<std::string> >(st_vect_2, PARAMS_ON, COL_ST);
//     std::cout << std::endl;

//     std::cout  << COL_MY << "My vector 1: " << COL_END;
//     ft::Vector<std::string> my_vect(mystr, mystr + sizeof(mystr) / sizeof(std::string));
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout  << COL_MY << "My vector 2: " << COL_END;
//     ft::Vector<std::string> my_vect_2(3, "Hello");
//     print_container<ft::Vector<std::string> >(my_vect_2, PARAMS_ON, COL_MY);
//     ft::swap(my_vect, my_vect_2);
//     std::cout  << COL_MY << "My vector 1 after swap: " << COL_END;
//     print_container<ft::Vector<std::string> >(my_vect, PARAMS_ON, COL_MY);
//     std::cout  << COL_MY << "My vector 2 after swap: " << COL_END;
//     print_container<ft::Vector<std::string> >(my_vect_2, PARAMS_ON, COL_MY);
// }


int main()
{
    std::cout << "___________________________________________________________" << std::endl;
    std::cout << "|                                                         |" << std::endl;
    std::cout << "|     Constructor | Default + Size | Max_size | Empty     |" << std::endl;
    std::cout << "|_________________________________________________________|" << std::endl << std::endl;
    constr_default();
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

    // std::cout << "_____________________" << std::endl;
    // std::cout << "|                   |" << std::endl;
    // std::cout << "|     Operator=     |" << std::endl;
    // std::cout << "|___________________|" << std::endl << std::endl;
    // assignation_operator();
    // std::cout << std::endl;

    std::cout << "_______________________________________" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|     Begin | End | Rbegin | Rend     |" << std::endl;
    std::cout << "|_____________________________________|" << std::endl << std::endl;
    iterators();
    std::cout << std::endl;
    
    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator[]     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;
    operator_access();
    std::cout << std::endl;

    std::cout << "___________________________________" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "|     Insert | Single element     |" << std::endl;
    std::cout << "|_________________________________|" << std::endl << std::endl;
    insert_single();
    std::cout << std::endl;

    std::cout << "______________________________" << std::endl;
    std::cout << "|                            |" << std::endl;
    std::cout << "|     Insert | With hint     |" << std::endl;
    std::cout << "|____________________________|" << std::endl << std::endl;
    insert_with_hint();
    std::cout << std::endl;

    std::cout << "__________________________" << std::endl;
    std::cout << "|                        |" << std::endl;
    std::cout << "|     Insert | Range     |" << std::endl;
    std::cout << "|________________________|" << std::endl << std::endl;
    insert_range();
    std::cout << std::endl;

    // std::cout << "__________________________________" << std::endl;
    // std::cout << "|                                |" << std::endl;
    // std::cout << "|     Erase | Single element     |" << std::endl;
    // std::cout << "|________________________________|" << std::endl << std::endl;
    // erase_single();
    // std::cout << std::endl;

    // std::cout << "_________________________" << std::endl;
    // std::cout << "|                       |" << std::endl;
    // std::cout << "|     Erase | Range     |" << std::endl;
    // std::cout << "|_______________________|" << std::endl << std::endl;
    // erase_range();
    // std::cout << std::endl;

    std::cout << "________________" << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|     Swap     |" << std::endl;
    std::cout << "|______________|" << std::endl << std::endl;
    swap();
    std::cout << std::endl;

    // std::cout << "_________________" << std::endl;
    // std::cout << "|               |" << std::endl;
    // std::cout << "|     Clear     |" << std::endl;
    // std::cout << "|_______________|" << std::endl << std::endl;
    // clear();
    // std::cout << std::endl;

    std::cout << "________________" << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|     Find     |" << std::endl;
    std::cout << "|______________|" << std::endl << std::endl;
    find();
    std::cout << std::endl;

    std::cout << "_________________" << std::endl;
    std::cout << "|               |" << std::endl;
    std::cout << "|     Count     |" << std::endl;
    std::cout << "|_______________|" << std::endl << std::endl;
    count();
    std::cout << std::endl;

    // std::cout << "______________________" << std::endl;
    // std::cout << "|                    |" << std::endl;
    // std::cout << "|     Operator==     |" << std::endl;
    // std::cout << "|____________________|" << std::endl << std::endl;
    // equal();
    // std::cout << std::endl;

    // std::cout << "______________________" << std::endl;
    // std::cout << "|                    |" << std::endl;
    // std::cout << "|     Operator!=     |" << std::endl;
    // std::cout << "|____________________|" << std::endl << std::endl;
    // not_equal();
    // std::cout << std::endl;

    // std::cout << "_____________________" << std::endl;
    // std::cout << "|                   |" << std::endl;
    // std::cout << "|     Operator<     |" << std::endl;
    // std::cout << "|___________________|" << std::endl << std::endl;
    // less();
    // std::cout << std::endl;

    // std::cout << "______________________" << std::endl;
    // std::cout << "|                    |" << std::endl;
    // std::cout << "|     Operator<=     |" << std::endl;
    // std::cout << "|____________________|" << std::endl << std::endl;
    // less_or_egual();
    // std::cout << std::endl;

    // std::cout << "_____________________" << std::endl;
    // std::cout << "|                   |" << std::endl;
    // std::cout << "|     Operator>     |" << std::endl;
    // std::cout << "|___________________|" << std::endl << std::endl;
    // greater();
    // std::cout << std::endl;

    // std::cout << "______________________" << std::endl;
    // std::cout << "|                    |" << std::endl;
    // std::cout << "|     Operator>=     |" << std::endl;
    // std::cout << "|____________________|" << std::endl << std::endl;
    // greater_or_equal();
    // std::cout << std::endl;

    // std::cout << "____________________" << std::endl;
    // std::cout << "|                  |" << std::endl;
    // std::cout << "|     ft::swap     |" << std::endl;
    // std::cout << "|__________________|" << std::endl << std::endl;
    // ft_swap();
    // std::cout << std::endl;

    // sleep(10000);
    return (0);
}