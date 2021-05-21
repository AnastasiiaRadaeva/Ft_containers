/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:14:33 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/18 19:12:01 by kbatwoma         ###   ########.fr       */
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
    std::cout << COL_ST << "Empty: " << COL_END << (st_map.empty() ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map" << COL_END << std::endl;
    ft::Map<int, std::string> my_map;
    std::cout << COL_MY << "Size: " << COL_END << my_map.size() << std::endl;
    std::cout << COL_MY << "Max size: " << COL_END << my_map.max_size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << (my_map.empty() ? "yes" : "no") << std::endl;
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

void    assignation_operator()
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
    std::map<char,int> second_copy = second;
    std::cout << COL_ST << "St map after operator=: " << COL_END;
    print_container<std::map<char, int> >(second_copy, PARAMS_ON, COL_ST);
    std::cout << std::endl;

    std::cout << COL_MY << "My map: " << COL_END;
    ft::Map<char,int> second_my(first.begin(),first.end());
    print_container<ft::Map<char, int> >(second_my, PARAMS_ON, COL_MY);
    std::cout << std::endl;
    std::cout << COL_MY << "My map after operator=: " << COL_END;
    ft::Map<char,int> second_my_copy = second_my;
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
    std::cout << COL_ST << "Size: " COL_END << first_st.size() << std::endl;
    std::cout << COL_ST << "rbegin: " << COL_END << (*(first_st.rbegin())).first << ":" << (*(first_st.rbegin())).second << COL_ST << " | --end: " << COL_END << (*(--(first_st.rend()))).first << ":" << (*(--(first_st.rend()))).second << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map: " << COL_END;
    ft::Map<char,int>::reverse_iterator begin_my;
    for (begin_my = first_my.rbegin(); begin_my != first_my.rend(); begin_my++)
        std::cout << (*begin_my).first << ":" << (*begin_my).second << " ";
    std::cout << std::endl;
    std::cout << COL_MY << "Size: " COL_END << first_my.size() << std::endl;
    std::cout << COL_MY << "rbegin: " << COL_END << (*(first_my.rbegin())).first << ":" << (*(first_my.rbegin())).second << COL_MY << " | --end: " << COL_END << (*(--(first_my.rend()))).first << ":" << (*(--(first_my.rend()))).second << std::endl;
}

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
    std::cout << COL_MY << "My map after insert \"c\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*(check_my.first)).first << COL_MY << " | In map: " << COL_END << (check_my.second ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    check_st = second.insert(elem_3);
    std::cout << COL_ST << "St map after insert \"r\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*(check_st.first)).first << COL_ST << " | In map: " << COL_END << (check_st.second ? "yes" : "no") << std::endl;
    check_my = second_my.insert(elem_3);
    std::cout << COL_MY << "My map after insert \"r\": " << COL_END;
    print_container<ft::Map<char, int> >(second_my, PARAMS_OFF, COL_MY);
    std::cout << COL_MY << "Size: " << COL_END << second_my.size() << COL_MY << " | Returned element: " << COL_END << (*(check_my.first)).first << COL_MY << " | In map: " << COL_END << (check_my.second ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    check_st = second.insert(elem_4);
    std::cout << COL_ST << "St map after insert \"h\": " << COL_END;
    print_container<std::map<char, int> >(second, PARAMS_OFF, COL_ST);
    std::cout << COL_ST << "Size: " << COL_END << second.size() << COL_ST << " | Returned element: " << COL_END << (*(check_st.first)).first << COL_ST << " | In map: " << COL_END << (check_st.second ? "yes" : "no") << std::endl;
    check_my = second_my.insert(elem_4);
    std::cout << COL_MY << "My map after insert \"h\": " << COL_END;
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

void    erase_single()
{
    std::cout << COL_ST << "St map before erase: " << COL_END;
    std::map<char,int> first_st;
    first_st['a']=10;
    first_st['b']=30;
    first_st['c']=50;
    first_st['i']=70;
    first_st['a']=20;
    first_st['e']=10;
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase b: " << COL_END;
    first_st.erase(++(first_st.begin()));
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase i: " << COL_END;
    first_st.erase(--(first_st.end()));
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase c: " << COL_END;
    first_st.erase(++(first_st.begin()));
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase e: " << COL_END;
    first_st.erase(++(first_st.begin()));
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase a: " << COL_END;
    first_st.erase(first_st.begin());
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << std::endl;

    std::cout << COL_MY << "My map before erase: " << COL_END;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['a']=20;
    first_my['e']=10;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase b: " << COL_END;
    first_my.erase(++(first_my.begin()));
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase i: " << COL_END;
    first_my.erase(--(first_my.end()));
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase c: " << COL_END;
    first_my.erase(++(first_my.begin()));
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase e: " << COL_END;
    first_my.erase(++(first_my.begin()));
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase a: " << COL_END;
    first_my.erase(first_my.begin());
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
}

void    erase_key()
{
    std::cout << COL_ST << "St map before erase: " << COL_END;
    std::map<char,int> first_st;
    first_st['a']=10;
    first_st['b']=30;
    first_st['c']=50;
    first_st['i']=70;
    first_st['a']=20;
    first_st['e']=10;
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase b: " << COL_END;
    std::cout << "Erase returns: " << (first_st.erase('b')) << " | ";
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase i: " << COL_END;
    std::cout << "Erase returns: " << (first_st.erase('i')) << " | ";
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase m: " << COL_END;
    std::cout << "Erase returns: " << (first_st.erase('m')) << " | ";
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase c: " << COL_END;
    std::cout << "Erase returns: " << (first_st.erase('c')) << " | ";
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase e: " << COL_END;
    std::cout << "Erase returns: " << (first_st.erase('e')) << " | ";
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase a: " << COL_END;
    std::cout << "Erase returns: " << (first_st.erase('a')) << " | ";
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << std::endl;

    std::cout << COL_MY << "My map before erase: " << COL_END;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['a']=20;
    first_my['e']=10;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase b: " << COL_END;
    std::cout << "Erase returns: " << (first_my.erase('b')) << " | ";
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase i: " << COL_END;
    std::cout << "Erase returns: " << (first_my.erase('i')) << " | ";
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase m: " << COL_END;
    std::cout << "Erase returns: " << (first_my.erase('m')) << " | ";
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase c: " << COL_END;
    std::cout << "Erase returns: " << (first_my.erase('c')) << " | ";
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase e: " << COL_END;
    std::cout << "Erase returns: " << (first_my.erase('e')) << " | ";
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase a: " << COL_END;
    std::cout << "Erase returns: " << (first_my.erase('a')) << " | ";
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
}

void    erase_range()
{
    std::cout << COL_ST << "St map before erase: " << COL_END;
    std::map<char,int> first_st;
    first_st['a']=10;
    first_st['b']=30;
    first_st['c']=50;
    first_st['i']=70;
    first_st['a']=20;
    first_st['e']=10;
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase from c to i: " << COL_END;
    first_st.erase(++(++(first_st.begin())), --(first_st.end()));
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after erase from a to end: " << COL_END;
    first_st.erase(first_st.begin(), first_st.end());
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << std::endl;

    std::cout << COL_MY << "My map before erase: " << COL_END;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['a']=20;
    first_my['e']=10;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase from c to i: " << COL_END;
    first_my.erase(++(++(first_my.begin())), --(first_my.end()));
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after erase from a to end: " << COL_END;
    first_my.erase(first_my.begin(), first_my.end());
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
}


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

void    clear()
{
    std::cout << COL_ST << "St map before clear: " << COL_END;
    std::map<char,int> first_st;
    first_st['a']=10;
    first_st['b']=30;
    first_st['c']=50;
    first_st['i']=70;
    first_st['a']=20;
    first_st['e']=10;
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "St map after clear: " << COL_END;
    first_st.clear();
    print_container<std::map<char, int> >(first_st, PARAMS_ON, COL_ST);
    std::cout << COL_ST << "Empty: " << COL_END << ((first_st.empty()) ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My map before clear: " << COL_END;
    ft::Map<char,int> first_my;
    first_my['a']=10;
    first_my['b']=30;
    first_my['c']=50;
    first_my['i']=70;
    first_my['a']=20;
    first_my['e']=10;
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "My map after clear: " << COL_END;
    first_my.clear();
    print_container<ft::Map<char, int> >(first_my, PARAMS_ON, COL_MY);
    std::cout << COL_MY << "Empty: " << COL_END << ((first_my.empty()) ? "yes" : "no") << std::endl;
}

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

    std::cout << "__________________________________" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|     Erase | Single element     |" << std::endl;
    std::cout << "|________________________________|" << std::endl << std::endl;
    erase_single();
    std::cout << std::endl;

    std::cout << "_______________________" << std::endl;
    std::cout << "|                     |" << std::endl;
    std::cout << "|     Erase | Key     |" << std::endl;
    std::cout << "|_____________________|" << std::endl << std::endl;
    erase_key();
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

    // sleep(10000);
    return (0);
}