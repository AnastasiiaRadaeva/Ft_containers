/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:49:38 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/29 16:36:58 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/List.hpp"
#include <list>
#include <cmath>

bool mycomparison (double first, double second)
{
    return (int(first)<int(second));
}

bool    is_it(std::string const &str)
{
    return (str == "Hello");
}

bool    uniqueness(int a, int b)
{
    return (a == b/2);
}

bool same_integral_part (double first, double second)
{
    return ( int(first)==int(second) );
}

struct is_near
{
    bool operator() (double first, double second)
    {
        return (fabs(first-second)<5.0);
    }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
    unsigned int i=0;
    while ( (i<first.length()) && (i<second.length()) )
    {
        if (tolower(first[i])<tolower(second[i])) return true;
        else if (tolower(first[i])>tolower(second[i])) return false;
        ++i;
    }
    return ( first.length() < second.length() );
}

int main()
{
    std::cout << "_______________________________" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|     Default constructor     |" << std::endl;
    std::cout << "|_____________________________|" << std::endl << std::endl;

    ft::List<std::string> my_list_str;
    std::cout << "My list - size: " << my_list_str.size() << std::endl;
    std::cout << "My list - empty: " << my_list_str.empty() << std::endl;
    std::cout << std::endl;

    std::list<std::string> standart_list_str;
    std::cout << "Standart list - size: " << standart_list_str.size() << std::endl;
    std::cout << "Standart list - empty: " << standart_list_str.empty() << std::endl;
    std::cout << std::endl;

    // std::cout << "max size: " << my_list.max_size() << std::endl;
    // std::cout << "content front: " << my_list.front() << std::endl;
    // std::cout << "content back: " << my_list.back() << std::endl;
    

    // ft::List<std::string> list(3, "Hello");
    // std::cout << list.getList() << std::endl;
    // std::cout << "size: " << list.size() << std::endl;
    // std::cout << "empty: " << list.empty() << std::endl;
    // std::cout << "max size: " << list.max_size() << std::endl;
    // std::cout << "content front: " << list.front() << std::endl;
    // std::cout << "content back: " << list.back() << std::endl;
    // std::cout << std::endl;

    // ft::List<std::string> list_1;
    // std::cout << list_1.getList() << std::endl;
    // std::cout << "size: " << list_1.size() << std::endl;
    // std::cout << "empty: " << list_1.empty() << std::endl;
    // std::cout << "max size: " << list_1.max_size() << std::endl;
    // std::cout << "content front: " << list_1.front() << std::endl;
    // std::cout << "content back: " << list_1.back() << std::endl;
    // list_1.push_back("went");
    // list_1.push_back("gone");
    // list_1.push_front("go");
    // list_1.reverse();
    // std::cout << std::endl;
    // std::cout << list_1.getList() << std::endl;
    // std::cout << "size: " << list_1.size() << std::endl;
    // std::cout << "empty: " << list_1.empty() << std::endl;
    // std::cout << "max size: " << list_1.max_size() << std::endl;
    // std::cout << "content front: " << list_1.front() << std::endl;
    // std::cout << "content back: " << list_1.back() << std::endl;

    // std::list<std::string> l1(3, "Hello");
    // std::list<std::string>::iterator iter_l1 = l1.begin();
    // std::cout << *iter_l1 << std::endl;

    // // std::list<int> l2(3, 7);
    // // std::list<int>::iterator iter_l2 = l2.begin();

    // // std::cout << (iter_l1 == iter_l2) << std::endl;
    // // (&iter_l1)->
    // // iter_l1++;
    // // std::cout << *iter_l1 << std::endl;
    // // iter_l1++;
    // // std::cout << *iter_l1 << std::endl;
    // // iter_l1++;
    // // std::cout << *iter_l1 << std::endl;
    // // iter_l1++;
    // // std::cout << *iter_l1 << std::endl;
    // // iter_l1++;
    // // std::cout << *iter_l1 << std::endl;
    


    
    // /* operator== */
    // ft::List<int> list_int;
    // list_int.push_back(5);
    // list_int.push_back(7);
    // list_int.push_back(9);
    // ft::List<int>::iterator iter_list_int = list_int.begin();

    // ft::List<int> list_int_2(3, 5);
    // ft::List<int>::iterator iter_list_int_2 = list_int_2.begin();

    // std::cout << (iter_list_int == iter_list_int_2) << std::endl;
    // std::cout << (iter_list_int == iter_list_int) << std::endl;
    // std::cout << (iter_list_int != iter_list_int_2) << std::endl;
    // std::cout << (iter_list_int != iter_list_int) << std::endl;
    // std::cout << *iter_list_int << std::endl;

    // // (&iter_list_int);



    std::cout << "________________________" << std::endl;
    std::cout << "|                      |" << std::endl;
    std::cout << "|     Operator++()     |" << std::endl;
    std::cout << "|______________________|" << std::endl << std::endl;

    ft::List<int>   my_list_int;
    my_list_int.push_back(2);
    my_list_int.push_back(4);
    my_list_int.push_back(16);
    ft::List<int>::iterator b_iter_my_list_int = my_list_int.begin();
    ft::List<int>::iterator e_iter_my_list_int = my_list_int.end();

    std::cout << "My list: ";
    while (b_iter_my_list_int != e_iter_my_list_int)
    {
        std::cout << *b_iter_my_list_int << " ";
        ++b_iter_my_list_int;
    }
    std::cout << std::endl;
    std::cout << "Tail: " << *b_iter_my_list_int << std::endl;
    std::cout << "First element: " << *(++b_iter_my_list_int) << " " << std::endl << std::endl;

    std::list<int>   standart_list_int;
    standart_list_int.push_back(2);
    standart_list_int.push_back(4);
    standart_list_int.push_back(16);
    std::list<int>::iterator b_iter_st_list_int = standart_list_int.begin();
    std::list<int>::iterator e_iter_st_list_int = standart_list_int.end();
    
    std::cout << "Standart list: ";
    while (b_iter_st_list_int != e_iter_st_list_int)
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Tail: " << *b_iter_st_list_int << std::endl;
    std::cout << "First element: " << *(++b_iter_st_list_int) << " " << std::endl << std::endl;
    


    std::cout << "________________________" << std::endl;
    std::cout << "|                      |" << std::endl;
    std::cout << "|     Operator--()     |" << std::endl;
    std::cout << "|______________________|" << std::endl << std::endl;

    std::cout << "My list: ";
    while (e_iter_my_list_int != b_iter_my_list_int)
        std::cout << *(--e_iter_my_list_int) << " ";
    std::cout << std::endl;
    std::cout << "Tail: " << *(--e_iter_my_list_int) << std::endl;
    std::cout << "Final element: " << *(--e_iter_my_list_int) << " " << std::endl << std::endl;
    ++e_iter_my_list_int;

    std::cout << "Standart list: ";
    while (e_iter_st_list_int != b_iter_st_list_int)
        std::cout << *(--e_iter_st_list_int) << " ";
    std::cout << std::endl;
    std::cout << "Tail: " << *(--e_iter_st_list_int) << std::endl;
    std::cout << "Final element: " << *(--e_iter_st_list_int) << " " << std::endl << std::endl;
    ++e_iter_st_list_int;



    std::cout << "___________________________" << std::endl;
    std::cout << "|                         |" << std::endl;
    std::cout << "|     Operator++(int)     |" << std::endl;
    std::cout << "|_________________________|" << std::endl << std::endl;

    std::cout << "My list: ";
    while (b_iter_my_list_int != e_iter_my_list_int)
        std::cout << *(b_iter_my_list_int++) << " ";
    std::cout << std::endl;
    std::cout << "Tail: " << *(b_iter_my_list_int++) << std::endl;
    std::cout << "First element: " << *b_iter_my_list_int << " " << std::endl << std::endl;

    std::cout << "Standart list: ";
    while (b_iter_st_list_int != e_iter_st_list_int)
        std::cout << *(b_iter_st_list_int++) << " ";
    std::cout << std::endl;
    std::cout << "Tail: " << *(b_iter_st_list_int++) << std::endl;
    std::cout << "First element: " << *b_iter_st_list_int << " " << std::endl << std::endl;
    


    std::cout << "___________________________" << std::endl;
    std::cout << "|                         |" << std::endl;
    std::cout << "|     Operator--(int)     |" << std::endl;
    std::cout << "|_________________________|" << std::endl << std::endl;

    std::cout << "My list: ";
    while (e_iter_my_list_int != b_iter_my_list_int)
    {
        e_iter_my_list_int--;
        std::cout << *e_iter_my_list_int << " ";
    }
    std::cout << std::endl;
    e_iter_my_list_int--;
    std::cout << "Tail: " << *(e_iter_my_list_int--) << std::endl;
    std::cout << "Final element: " << *e_iter_my_list_int << " " << std::endl << std::endl;

    std::cout << "Standart list: ";
    while (e_iter_st_list_int != b_iter_st_list_int)
    {
        e_iter_st_list_int--;
        std::cout << *e_iter_st_list_int << " ";
    }
    std::cout << std::endl;
    e_iter_st_list_int--;
    std::cout << "Tail: " << *(e_iter_st_list_int--) << std::endl;
    std::cout << "Final element: " << *e_iter_st_list_int << " " << std::endl << std::endl;
    
    

    std::cout << "Const_iterator" << std::endl;
    
    const std::list<int> standart_const_list_int(3, 8);
    std::list<int>::const_iterator b_iter_st_const_list_int = standart_const_list_int.begin();
    std::cout << (b_iter_st_list_int == b_iter_st_const_list_int) << std::endl;

    const ft::List<int>   my_const_list_int(3, 5);
    ft::List<int>::const_iterator b_iter_my_const_list_int = my_const_list_int.begin();
    std::cout << (b_iter_my_list_int == b_iter_my_const_list_int) << std::endl;

    std::cout << "_____________________________________________________" << std::endl;
    std::cout << "|                                                   |" << std::endl;
    std::cout << "|     Reverse_iterator / Const_reverse_iterator     |" << std::endl;
    std::cout << "|___________________________________________________|" << std::endl << std::endl;
    
    std::list<int>::const_reverse_iterator b_st_const_rev_list_int = standart_const_list_int.rend();
    // *b_st_const_rev_list_int = 5;
    std::cout << *b_st_const_rev_list_int << "\n";
    // std::cout << *b_st_const_rev_list_int << "\n";
    // std::cout << (b_iter_st_list_int == b_st_const_rev_list_int) << std::endl;

    ft::List<int>::const_reverse_iterator it_c = my_const_list_int.rbegin();
    ft::List<int>::const_reverse_iterator it = my_const_list_int.rend();
    std::cout << (it_c == it) << std::endl;
    
    // *it_c = 4;
    std::cout << *it_c;

    // ft::List<int>::reverse_iterator b_iter_my_const_rev_list_int;
    // b_iter_my_const_list_int = my_const_list_int.rbegin();
    
    // std::cout << (b_iter_my_const_rev_list_int == b_iter_my_const_list_int) << std::endl;

    std::cout << "____________________________" << std::endl;
    std::cout << "|                          |" << std::endl;
    std::cout << "|     Copy constructor     |" << std::endl;
    std::cout << "|__________________________|" << std::endl << std::endl;

    ft::List<int> copy_my_const_list_int(my_const_list_int);
    ft::List<int>::iterator b_copy = copy_my_const_list_int.begin();
    ft::List<int>::iterator e_copy = copy_my_const_list_int.end();

    std::cout << "My list: ";
    while (b_copy != e_copy)
    {
        std::cout << *b_copy << " ";
        ++b_copy;
    }
    std::cout << std::endl;
    copy_my_const_list_int.push_back(7);
    std::cout << "Size of list: " << *b_copy << std::endl;
    b_copy++;
    std::cout << "My list: ";
    while (b_copy != e_copy)
    {
        std::cout << *b_copy << " ";
        ++b_copy;
    }
    std::cout << std::endl;
    copy_my_const_list_int.pop_front();
    std::cout << "Size of list: " << *b_copy << std::endl;
    ++b_copy;
    std::cout << "My list: ";
    while (b_copy != e_copy)
    {
        std::cout << *b_copy << " ";
        ++b_copy;
    }
    std::cout << std::endl;

    copy_my_const_list_int.pop_back();
    std::cout << "Size of list: " << *b_copy << std::endl;
    ++b_copy;
    std::cout << "My list: ";
    while (b_copy != e_copy)
    {
        std::cout << *b_copy << " ";
        ++b_copy;
    }
    std::cout << std::endl;

    copy_my_const_list_int.pop_back();
    std::cout << "Size of list: " << *b_copy << std::endl;
    ++b_copy;
    std::cout << "My list: ";
    while (b_copy != e_copy)
    {
        std::cout << *b_copy << " ";
        ++b_copy;
    }
    std::cout << std::endl;

    copy_my_const_list_int.pop_back();
    std::cout << "Size of list: " << *b_copy << std::endl;
    ++b_copy;
    std::cout << "My list: ";
    while (b_copy != e_copy)
    {
        std::cout << *b_copy << " ";
        ++b_copy;
    }
    std::cout << std::endl;
    copy_my_const_list_int.pop_back();
    copy_my_const_list_int.pop_back();


    // std::list<int> l;
    // std::list<int>::iterator b_i = l.begin();
    // std::list<int>::iterator e_i = l.end();
    // std::cout << "Standart list: ";
    // while (b_i != e_i)
    // {
    //     std::cout << *b_i << " ";
    //     ++b_i;
    // }
    // std::cout << std::endl;
    // l.pop_back();
    // copy_my_const_list_int.push_back(7);
    // std::cout << "Size of list: " << *b_copy << std::endl;
    // b_copy++;
    // std::cout << "My list: ";
    // while (b_copy != e_copy)
    // {
    //     std::cout << *b_copy << " ";
    //     ++b_copy;
    // }
    // std::cout << std::endl;
    // copy_my_const_list_int.pop_front();
    // std::cout << "Size of list: " << *b_copy << std::endl;
    // ++b_copy;
    // std::cout << "My list: ";
    // while (b_copy != e_copy)
    // {
    //     std::cout << *b_copy << " ";
    //     ++b_copy;
    // }
    // std::cout << std::endl;

    // copy_my_const_list_int.pop_back();
    // std::cout << "Size of list: " << *b_copy << std::endl;
    // ++b_copy;
    // std::cout << "My list: ";
    // while (b_copy != e_copy)
    // {
    //     std::cout << *b_copy << " ";
    //     ++b_copy;
    // }
    // std::cout << std::endl;

    // copy_my_const_list_int.pop_back();
    // std::cout << "Size of list: " << *b_copy << std::endl;
    // ++b_copy;
    // std::cout << "My list: ";
    // while (b_copy != e_copy)
    // {
    //     std::cout << *b_copy << " ";
    //     ++b_copy;
    // }
    // std::cout << std::endl;

    // copy_my_const_list_int.pop_back();
    // std::cout << "Size of list: " << *b_copy << std::endl;
    // ++b_copy;
    // std::cout << "My list: ";
    // while (b_copy != e_copy)
    // {
    //     std::cout << *b_copy << " ";
    //     ++b_copy;
    // }
    // std::cout << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Operator=     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    ft::List<int> oper_my_const_list_int = copy_my_const_list_int;
    ft::List<int>::iterator b_oper = oper_my_const_list_int.begin();
    ft::List<int>::iterator e_oper = oper_my_const_list_int.end();

    std::cout << "My list: ";
    while (b_oper != e_oper)
    {
        std::cout << *b_oper << " ";
        ++b_oper;
    }
    std::cout << std::endl;
    std::cout << "Size of list: " << *b_oper << std::endl;

    oper_my_const_list_int.push_back(7);
    b_oper++;
    std::cout << "My list: ";
    while (b_oper != e_oper)
    {
        std::cout << *b_oper << " ";
        ++b_oper;
    }
    std::cout << "Size of list: " << *b_oper << std::endl;

    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Assign     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    std::list<int> list_assign(5, 9);
    list_assign.assign(3, 7);
    std::list<int>::iterator b = list_assign.begin();
    std::list<int>::iterator e = list_assign.end();
    std::cout << "Standart list: ";
    while (b != e)
    {
        std::cout << *b << " ";
        ++b;
    }
    std::cout << std::endl;
    std::cout << "Size of list: " << *b << std::endl;

    ft::List<int> my_list_assign(5, 9);
    my_list_assign.assign(3, 7);
    ft::List<int>::iterator my_b = my_list_assign.begin();
    ft::List<int>::iterator my_e = my_list_assign.end();
    std::cout << "My list: ";
    while (my_b != my_e)
    {
        std::cout << *my_b << " ";
        ++my_b;
    }
    std::cout << std::endl;
    std::cout << "Size of list: " << my_list_assign.size() << std::endl;

    std::cout << "____________________________" << std::endl;
    std::cout << "|                          |" << std::endl;
    std::cout << "|     Constructor Iter     |" << std::endl;
    std::cout << "|__________________________|" << std::endl << std::endl;

    ft::List<int>::const_iterator b_iter = my_const_list_int.begin();
    ft::List<int>::const_iterator e_iter = my_const_list_int.end();
    ft::List<int> iter_my_const_list_int(b_iter, e_iter);
    ft::List<int>::iterator b_my_it = iter_my_const_list_int.begin();
    ft::List<int>::iterator e_my_it = iter_my_const_list_int.end();

    std::cout << "My list: ";
    while (b_iter != e_iter)
    {
        std::cout << *b_iter << " ";
        ++b_iter;
    }
    std::cout << std::endl;
    std::cout << "My construct iter: ";
    while (b_my_it != e_my_it)
    {
        std::cout << *b_my_it << " ";
        ++b_my_it;
    }
    std::cout << std::endl;

    ft::List<std::string> my_str_list;
    my_str_list.push_back("Hello");
    my_str_list.push_back("I'm");
    my_str_list.push_back("glad");
    my_str_list.push_back("to");
    my_str_list.push_back("see");
    my_str_list.push_back("you");
    ft::List<std::string>::iterator begin = my_str_list.begin();
    ft::List<std::string>::iterator end = my_str_list.end();
    ft::List<std::string> iter_my_list_str(begin, end);
    ft::List<std::string>::iterator c_begin = iter_my_list_str.begin();
    ft::List<std::string>::iterator c_end = iter_my_list_str.end();

    std::cout << "My string list: ";
    while (begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
    ++begin;
    std::cout << std::endl;
    std::cout << "My construct string iter: ";
    while (c_begin != c_end)
    {
        std::cout << *c_begin << " ";
        ++c_begin;
    }
    std::cout << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                     |" << std::endl;
    std::cout << "|     Assign iter     |" << std::endl;
    std::cout << "|_____________________|" << std::endl << std::endl;

    ft::List<std::string> assign_list_iter(4, "We");
    ft::List<std::string>::iterator a_begin = assign_list_iter.begin();
    ft::List<std::string>::iterator a_end = assign_list_iter.end();

    std::cout << "My string list: ";
    while (a_begin != a_end)
    {
        std::cout << *a_begin << " ";
        ++a_begin;
    }
    std::cout << std::endl;
    assign_list_iter.assign(begin, end);
    std::cout << "My assign string iter: ";
    a_begin = assign_list_iter.begin();
    a_end = assign_list_iter.end();
    while (a_begin != a_end)
    {
        std::cout << *a_begin << " ";
        ++a_begin;
    }
    std::cout << std::endl;

    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Resize     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    std::list<std::string> resize_st_list;
    resize_st_list.push_back("Hello");
    resize_st_list.push_back("I'm");
    resize_st_list.push_back("glad");
    resize_st_list.push_back("to");
    resize_st_list.push_back("see");
    resize_st_list.push_back("you");
    resize_st_list.resize(2);
    std::list<std::string>::iterator b_i_resize = resize_st_list.begin();
    std::list<std::string>::iterator e_i_resize = resize_st_list.end();
    resize_st_list.resize(2);
    std::cout << "Size: " << resize_st_list.size() << std::endl;
    std::cout << "Standart decrement: ";
    while (b_i_resize != e_i_resize)
    {
        std::cout << *b_i_resize << " ";
        ++b_i_resize;
    }
    std::cout << std::endl;
    std::cout << "Size: " << resize_st_list.size() << std::endl;
    resize_st_list.resize(7, "Nastya");    
    b_i_resize = resize_st_list.begin();
    e_i_resize = resize_st_list.end();
    std::cout << "Standart increment: ";
    while (b_i_resize != e_i_resize)
    {
        std::cout << *b_i_resize << " ";
        ++b_i_resize;
    }
    std::cout << std::endl;
    std::cout << "Size: " << resize_st_list.size() << std::endl;

    assign_list_iter.resize(2);
    a_begin = assign_list_iter.begin();
    a_end = assign_list_iter.end();
    std::cout << "Size: " << assign_list_iter.size() << std::endl;
    std::cout << "My decrement: ";
    while (a_begin != a_end)
    {
        std::cout << *a_begin << " ";
        ++a_begin;
    }
    std::cout << std::endl;
    std::cout << "Size: " << assign_list_iter.size() << std::endl;

    assign_list_iter.resize(7, "Nastya");
    a_begin = assign_list_iter.begin();
    a_end = assign_list_iter.end();
    std::cout << "My increment: ";
    while (a_begin != a_end)
    {
        std::cout << *a_begin << " ";
        ++a_begin;
    }
    std::cout << std::endl;
    std::cout << "Size: " << assign_list_iter.size() << std::endl;

    std::cout << "________________" << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|     Swap     |" << std::endl;
    std::cout << "|______________|" << std::endl << std::endl;

    std::list<std::string> swap_st_list;
    swap_st_list.push_back("Hello");
    swap_st_list.push_back("I'm");
    swap_st_list.push_back("glad");
    swap_st_list.push_back("to");
    swap_st_list.push_back("see");
    swap_st_list.push_back("you");
    std::list<std::string>::iterator b_i_swap = swap_st_list.begin();
    std::list<std::string>::iterator e_i_swap = swap_st_list.end();
    std::cout << "Standart list a: ";
    while (b_i_swap != e_i_swap)
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    std::cout << "Standart list b: ";
    b_i_resize = resize_st_list.begin();
    e_i_resize = resize_st_list.end();
    while (b_i_resize != e_i_resize)
    {
        std::cout << *b_i_resize << " ";
        ++b_i_resize;
    }
    std::cout << std::endl;
    std::cout << "Size: " << resize_st_list.size() << std::endl;
    
    swap_st_list.swap(resize_st_list);
    b_i_swap = swap_st_list.begin();
    e_i_swap = swap_st_list.end();
    std::cout << "Standart list a: ";
    while (b_i_swap != e_i_swap)
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    std::cout << "Standart list b: ";
    b_i_resize = resize_st_list.begin();
    e_i_resize = resize_st_list.end();
    while (b_i_resize != e_i_resize)
    {
        std::cout << *b_i_resize << " ";
        ++b_i_resize;
    }
    std::cout << std::endl;
    std::cout << "Size: " << resize_st_list.size() << std::endl;

    ft::List<std::string> swap_my_list;
    swap_my_list.push_back("Hello");
    swap_my_list.push_back("I'm");
    swap_my_list.push_back("glad");
    swap_my_list.push_back("to");
    swap_my_list.push_back("see");
    swap_my_list.push_back("you");
    ft::List<std::string>::iterator begin_swap = swap_my_list.begin();
    ft::List<std::string>::iterator end_swap = swap_my_list.end();
    std::cout << "My list a: ";
    while (begin_swap != end_swap)
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    std::cout << "My list b: ";
    begin_swap = assign_list_iter.begin();
    end_swap = assign_list_iter.end();
    while (begin_swap != end_swap)
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << assign_list_iter.size() << std::endl;
    
    swap_my_list.swap(assign_list_iter);
    begin_swap = swap_my_list.begin();
    end_swap = swap_my_list.end();
    std::cout << "My list a: ";
    while (begin_swap != end_swap)
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    std::cout << "My list b: ";
    begin_swap = assign_list_iter.begin();
    end_swap = assign_list_iter.end();
    while (begin_swap != end_swap)
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << assign_list_iter.size() << std::endl;

    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Remove     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    b_i_swap = swap_st_list.begin();
    std::cout << "Standart list: ";
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    swap_st_list.remove("Nastya");
    std::cout << "Standart list after remove \"Nastya\": ";
    b_i_swap = swap_st_list.begin();
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    
    begin_swap = swap_my_list.begin();
    std::cout << "My list: ";
    while (begin_swap != swap_my_list.end())
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    swap_my_list.remove("Nastya");
    std::cout << "My list after remove \"Nastya\": ";
    begin_swap = swap_my_list.begin();
    while (begin_swap != swap_my_list.end())
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Remove_if     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    b_i_swap = swap_st_list.begin();
    std::cout << "Standart list: ";
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    swap_st_list.remove_if(is_it);
    std::cout << "Standart list after remove_if \"Hello\": ";
    b_i_swap = swap_st_list.begin();
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    
    begin_swap = swap_my_list.begin();
    std::cout << "My list: ";
    while (begin_swap != swap_my_list.end())
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    std::cout << "My list after remove_if \"Hello\": ";
    swap_my_list.remove_if(is_it);
    begin_swap = swap_my_list.begin();
    while (begin_swap != swap_my_list.end())
    {
        std::cout << *begin_swap << " ";
        ++begin_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;

    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Unique     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    standart_list_int.resize(7, 21);
    standart_list_int.resize(8, 4);
    b_iter_st_list_int = standart_list_int.begin();
    std::cout << "Standart list: ";
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl;
    standart_list_int.unique();
    std::cout << "Standart list after unique: ";
    
    b_iter_st_list_int = standart_list_int.begin();
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl;
    
    my_list_int.resize(7, 21);
    my_list_int.resize(8, 4);
    b_iter_my_list_int = my_list_int.begin();
    std::cout << "My list: ";
    while (b_iter_my_list_int != my_list_int.end())
    {
        std::cout << *b_iter_my_list_int << " ";
        ++b_iter_my_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int.size() << std::endl;
    my_list_int.unique();
    std::cout << "My list after unique: ";
    
    b_iter_my_list_int = my_list_int.begin();
    while (b_iter_my_list_int != my_list_int.end())
    {
        std::cout << *b_iter_my_list_int << " ";
        ++b_iter_my_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int.size() << std::endl;

    std::cout << "_______________________________" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|     Unique - unuqueness     |" << std::endl;
    std::cout << "|_____________________________|" << std::endl << std::endl;

    standart_list_int.resize(3, 10);
    standart_list_int.resize(5, 32);
    b_iter_st_list_int = standart_list_int.begin();
    std::cout << "Standart list: ";
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl;
    standart_list_int.unique(uniqueness);
    std::cout << "Standart list after unique: ";
    
    b_iter_st_list_int = standart_list_int.begin();
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl;
    
    my_list_int.resize(3, 10);
    my_list_int.resize(5, 32);
    b_iter_my_list_int = my_list_int.begin();
    std::cout << "My list: ";
    while (b_iter_my_list_int != my_list_int.end())
    {
        std::cout << *b_iter_my_list_int << " ";
        ++b_iter_my_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int.size() << std::endl;
    my_list_int.unique(uniqueness);
    std::cout << "My list after unique: ";
    
    b_iter_my_list_int = my_list_int.begin();
    while (b_iter_my_list_int != my_list_int.end())
    {
        std::cout << *b_iter_my_list_int << " ";
        ++b_iter_my_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int.size() << std::endl;

    double mydoubles[]={ 2.72,  3.14, 12.15, 12.77, 12.77,
                                15.3,  72.25, 72.25, 73.0,  73.35 };
    std::list<double> mylist (mydoubles,mydoubles+10);
    mylist.unique();
    mylist.unique (same_integral_part);
    mylist.unique (is_near());
    std::cout << "stlist contains:";
    for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    ft::List<double> mylist_1 (mydoubles,mydoubles+10);
    mylist_1.unique();
    mylist_1.unique (same_integral_part);
    mylist_1.unique (is_near());
    std::cout << "mylist contains:";
    for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "________________" << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|     Sort     |" << std::endl;
    std::cout << "|______________|" << std::endl << std::endl;

    b_iter_st_list_int = standart_list_int.begin();
    standart_list_int.push_back(4);
    standart_list_int.push_back(3);
    standart_list_int.push_back(0);
    std::cout << "Standart list: ";
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl;

    standart_list_int.sort();

    b_iter_st_list_int = standart_list_int.begin();
    std::cout << "Standart list after sort: ";
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl;

    b_iter_my_list_int = my_list_int.begin();
    my_list_int.push_back(4);
    my_list_int.push_back(3);
    my_list_int.push_back(0);
    std::cout << "My list: ";
    while (b_iter_my_list_int != my_list_int.end())
    {
        std::cout << *b_iter_my_list_int << " ";
        ++b_iter_my_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int.size() << std::endl;

    my_list_int.sort();
    
    std::cout << "My list after sort: ";
    b_iter_my_list_int = my_list_int.begin();
    while (b_iter_my_list_int != my_list_int.end())
    {
        std::cout << *b_iter_my_list_int << " ";
        ++b_iter_my_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int.size() << std::endl;

    std::cout << "_________________________" << std::endl;
    std::cout << "|                       |" << std::endl;
    std::cout << "|     Sort with comp    |" << std::endl;
    std::cout << "|_______________________|" << std::endl << std::endl;

    std::list<std::string> mylist_2;
    std::list<std::string>::iterator it_2;
    mylist_2.push_back("one");
    mylist_2.push_back ("two");
    mylist_2.push_back ("Three");
    mylist_2.sort();
    std::cout << "stlist after < sort contains:";
    for (it_2 = mylist_2.begin(); it_2 != mylist_2.end(); ++it_2)
        std::cout << ' ' << *it_2;
    std::cout << '\n';
    mylist_2.sort(compare_nocase);
    std::cout << "stlist after comp sort contains:";
    for (it_2 = mylist_2.begin(); it_2!=mylist_2.end(); ++it_2)
        std::cout << ' ' << *it_2;
    std::cout << '\n';

    ft::List<std::string> mylist_3;
    ft::List<std::string>::iterator it_3;
    mylist_3.push_back("one");
    mylist_3.push_back ("two");
    mylist_3.push_back ("Three");
    mylist_3.sort();

    std::cout << "mylist after < sort contains:";
    for (it_3 = mylist_3.begin(); it_3 != mylist_3.end(); ++it_3)
        std::cout << ' ' << *it_3;
    std::cout << '\n';

    mylist_3.sort(compare_nocase);

    std::cout << "mylist after comp sort contains:";
    for (it_3 = mylist_3.begin(); it_3!=mylist_3.end(); ++it_3)
        std::cout << ' ' << *it_3;
    std::cout << '\n';

    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Insert     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;
    
    std::list<double>::iterator it_st;
    
    for (int i=1; i<=5; ++i) mylist.push_back(i);
    std::cout << "stlist before insert: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    it_st = mylist.begin();
    ++it_st;
    mylist.insert(it_st,10);
    std::cout << "stlist after insert: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    it_st = mylist.begin();
    it_st++;
    mylist.insert(it_st, 3, 7.5);
    std::cout << "stlist after multiple insert: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;

    std::list<double> st_add_lst;
    st_add_lst.push_back(8.6);
    st_add_lst.push_back(3.1);
    st_add_lst.push_back(5.8);
    mylist.insert(++(mylist.begin()), st_add_lst.begin(), st_add_lst.end());
    std::cout << "stlist after insert from other list: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << std::endl;


    ft::List<double>::iterator it_my;
    for (int i=1; i<=5; ++i) mylist_1.push_back(i);
    std::cout << "My list before insert: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    it_my = mylist_1.begin();
    ++it_my;
    mylist_1.insert(it_my,10);
    std::cout << "My list after insert: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    it_my = mylist_1.begin();
    it_my++;
    mylist_1.insert(it_my, 3, 7.5);
    std::cout << "My list after multiple insert: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;

    ft::List<double> my_add_list;
    my_add_list.push_back(8.6);
    my_add_list.push_back(3.1);
    my_add_list.push_back(5.8);
    mylist_1.insert(++(mylist_1.begin()), my_add_list.begin(), my_add_list.end());
    std::cout << "My list after insert from other list: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "______________________________" << std::endl;
    std::cout << "|                            |" << std::endl;
    std::cout << "|     Erase | one element    |" << std::endl;
    std::cout << "|____________________________|" << std::endl << std::endl;

    std::cout << "St list before erase: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    it_st = mylist.erase(++(mylist.begin()));
    std::cout << "Elem in erase position: " << *it_st << std::endl;
    std::cout << "St list after erase: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    it_st = mylist.erase(--(mylist.end()));
    std::cout << "Elem in erase position: " << *it_st << std::endl;
    std::cout << "St list after erase end of list: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl << std::endl;

    std::cout << "My list before erase: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    it_my = mylist_1.erase(++(mylist_1.begin()));
    std::cout << "Elem in erase position: " << *it_my << std::endl;
    std::cout << "My list after erase: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    it_my = mylist_1.erase(--(mylist_1.end()));
    std::cout << "Elem in erase position: " << *it_my << std::endl;
    std::cout << "My list after erase end of list: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
   
    std::cout << "_______________________" << std::endl;
    std::cout << "|                     |" << std::endl;
    std::cout << "|     Erase | list    |" << std::endl;
    std::cout << "|_____________________|" << std::endl << std::endl;

    std::cout << "St list before erase: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    it_st = mylist.erase(++(mylist.begin()), --(mylist.end()));
    std::cout << "Elem in erase position: " << *it_st << std::endl;
    std::cout << "St list after erase: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    it_st = mylist.erase(++(mylist.begin()), mylist.end());
    std::cout << "Elem in erase position: " << *it_st << std::endl;
    std::cout << "St list after erase end of list: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl << std::endl;

    std::cout << "My list before erase: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    it_my = mylist_1.erase(++(mylist_1.begin()), --(mylist_1.end()));
    std::cout << "Elem in erase position: " << *it_my << std::endl;
    std::cout << "My list after erase: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    it_my = mylist_1.erase(++(mylist_1.begin()), mylist_1.end());
    std::cout << "Elem in erase position: " << *it_my << std::endl;
    std::cout << "My list after erase end of list: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
   
    std::cout << "______________________________" << std::endl;
    std::cout << "|                            |" << std::endl;
    std::cout << "|     Splice | full list     |" << std::endl;
    std::cout << "|____________________________|" << std::endl << std::endl;

    std::list<double> mylist_add;
    mylist_add.push_back(7.1);
    mylist_add.push_back(7.3);
    mylist_add.push_back(7.5);
    mylist.push_back(7.9);
    std::cout << "St list 1 before splice: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << "St list 2 before splice: ";
    for (it_st = mylist_add.begin(); it_st != mylist_add.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist_add.size() << std::endl;
    mylist.splice(++(mylist.begin()), mylist_add);
    std::cout << "St list 1 after splice: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << "St list 2 after splice: ";
    for (it_st = mylist_add.begin(); it_st != mylist_add.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist_add.size() << std::endl << std::endl;

    ft::List<double> mylist_1_add;
    mylist_1_add.push_back(7.1);
    mylist_1_add.push_back(7.3);
    mylist_1_add.push_back(7.5);
    mylist_1.push_back(7.9);
    std::cout << "My list 1 before splice: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    std::cout << "My list 2 before splice: ";
    for (it_my = mylist_1_add.begin(); it_my != mylist_1_add.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1_add.size() << std::endl;
    mylist_1.splice(++(mylist_1.begin()), mylist_1_add);
    std::cout << "My list 1 after splice: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    std::cout << "My list 2 after splice: ";
    for (it_my = mylist_1_add.begin(); it_my != mylist_1_add.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1_add.size() << std::endl << std::endl;


    std::cout << "___________________________________" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "|     Splice | single element     |" << std::endl;
    std::cout << "|_________________________________|" << std::endl << std::endl;

    mylist_add.push_back(8.1);
    mylist_add.push_back(8.3);
    mylist_add.push_back(8.5);
    std::cout << "St list 1 before splice: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << "St list 2 before splice: ";
    for (it_st = mylist_add.begin(); it_st != mylist_add.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist_add.size() << std::endl;
    mylist.splice(++(mylist.begin()), mylist_add, ++(mylist_add.begin()));
    std::cout << "St list 1 after splice: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << "St list 2 after splice: ";
    for (it_st = mylist_add.begin(); it_st != mylist_add.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist_add.size() << std::endl << std::endl;

    mylist_1_add.push_back(8.1);
    mylist_1_add.push_back(8.3);
    mylist_1_add.push_back(8.5);
    std::cout << "My list 1 before splice: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    std::cout << "My list 2 before splice: ";
    for (it_my = mylist_1_add.begin(); it_my != mylist_1_add.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1_add.size() << std::endl;
    mylist_1.splice(++(mylist_1.begin()), mylist_1_add, ++(mylist_1_add.begin()));
    std::cout << "My list 1 after splice: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    std::cout << "My list 2 after splice: ";
    for (it_my = mylist_1_add.begin(); it_my != mylist_1_add.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1_add.size() << std::endl << std::endl;
       
    std::cout << "__________________________________" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|     Splice | element range     |" << std::endl;
    std::cout << "|________________________________|" << std::endl << std::endl;

    mylist_add.push_back(9.1);
    mylist_add.push_back(9.3);
    mylist_add.push_back(9.5);
    std::cout << "St list 1 before splice: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << "St list 2 before splice: ";
    for (it_st = mylist_add.begin(); it_st != mylist_add.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist_add.size() << std::endl;
    mylist.splice(mylist.end(), mylist_add, ++(mylist_add.begin()), --(mylist_add.end()));
    std::cout << "St list 1 after splice: ";
    for (it_st = mylist.begin(); it_st != mylist.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << "St list 2 after splice: ";
    for (it_st = mylist_add.begin(); it_st != mylist_add.end(); ++it_st)
        std::cout << ' ' << *it_st;
    std::cout << '\n';
    std::cout << "Size: " << mylist_add.size() << std::endl << std::endl;

    mylist_1_add.push_back(9.1);
    mylist_1_add.push_back(9.3);
    mylist_1_add.push_back(9.5);
    std::cout << "My list 1 before splice: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    std::cout << "My list 2 before splice: ";
    for (it_my = mylist_1_add.begin(); it_my != mylist_1_add.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1_add.size() << std::endl;
    mylist_1.splice(mylist_1.end(), mylist_1_add, ++(mylist_1_add.begin()), --(mylist_1_add.end()));
    std::cout << "My list 1 after splice: ";
    for (it_my = mylist_1.begin(); it_my != mylist_1.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1.size() << std::endl;
    std::cout << "My list 2 after splice: ";
    for (it_my = mylist_1_add.begin(); it_my != mylist_1_add.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << mylist_1_add.size() << std::endl << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Merge | 1     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    std::list<double> first, second;
    first.push_back (3.1);
    first.push_back (2.2);
    first.push_back (2.9);
    second.push_back (3.7);
    second.push_back (7.1);
    second.push_back (1.4);
    first.sort();
    std::cout << "St first before merge:";
    for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << first.size() << std::endl;
    second.sort();
    std::cout << "St second before merge:";
    for (std::list<double>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << second.size() << std::endl;
    first.merge(second);
    std::cout << "St first after merge:";
    for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << first.size() << std::endl;
    std::cout << "St second after merge:";
    for (std::list<double>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << second.size() << std::endl << std::endl;

    ft::List<double> first_my, second_my;
    first_my.push_back (3.1);
    first_my.push_back (2.2);
    first_my.push_back (2.9);
    second_my.push_back (3.7);
    second_my.push_back (7.1);
    second_my.push_back (1.4);
    first_my.sort();
    std::cout << "My first before merge:";
    for (it_my = first_my.begin(); it_my != first_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << first_my.size() << std::endl;
    second_my.sort();
    std::cout << "My second before merge:";
    for (it_my = second_my.begin(); it_my != second_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << second_my.size() << std::endl;
    first_my.merge(second_my);
    std::cout << "My first after merge:";
    for (it_my=first_my.begin(); it_my!=first_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << first_my.size() << std::endl;
    std::cout << "My second after merge:";
    for (it_my = second_my.begin(); it_my != second_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << second_my.size() << std::endl;

    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Merge | 2     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    second.push_back(2.1);
    std::cout << "St first before merge:";
    for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << first.size() << std::endl;
    std::cout << "St second before merge:";
    for (std::list<double>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << second.size() << std::endl;
    first.merge(second, mycomparison);
    std::cout << "St first after merge:";
    for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << first.size() << std::endl;
    std::cout << "St second after merge:";
    for (std::list<double>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << second.size() << std::endl << std::endl;

    second_my.push_back(2.1);
    std::cout << "My first before merge:";
    for (it_my = first_my.begin(); it_my != first_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << first_my.size() << std::endl;
    std::cout << "My second before merge:";
    for (it_my = second_my.begin(); it_my != second_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << second_my.size() << std::endl;
    first_my.merge(second_my, mycomparison);
    std::cout << "My first after merge:";
    for (it_my=first_my.begin(); it_my!=first_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << first_my.size() << std::endl;
    std::cout << "My second after merge:";
    for (it_my = second_my.begin(); it_my != second_my.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << second_my.size() << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator==     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;

    std::cout << "Standart not equivalent: " << (first == second) << std::endl;
    std::list<double> first_copy(first);
    std::cout << "Standart equivalent: " << (first == first_copy) << std::endl << std::endl;

    std::cout << "My not equivalent: " << (first_my == second_my) << std::endl;
    ft::List<double> first_my_copy(first_my);
    std::cout << "My equivalent: " << (first_my == first_my_copy) << std::endl << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator!=     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;

    std::cout << "Standart not equivalent: " << (first != second) << std::endl;
    std::cout << "Standart equivalent: " << (first != first_copy) << std::endl << std::endl;

    std::cout << "My not equivalent: " << (first_my != second_my) << std::endl;
    std::cout << "My equivalent: " << (first_my != first_my_copy) << std::endl << std::endl;


    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Operator<     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    std::list<int> st_less;
    st_less.push_back(2);
    st_less.push_back(3);
    st_less.push_back(4);
    st_less.push_back(5);
    st_less.push_back(6);
    std::list<int> st_greater;
    st_greater.push_back(2);
    st_greater.push_back(3);
    st_greater.push_back(4);

    ft::List<int> my_less;
    my_less.push_back(2);
    my_less.push_back(3);
    my_less.push_back(4);
    my_less.push_back(5);
    my_less.push_back(6);
    ft::List<int> my_greater;
    my_greater.push_back(2);
    my_greater.push_back(3);
    my_greater.push_back(4);

    std::cout << "|   1 - 5 elem, 2 - 3 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less < st_greater) << std::endl;
    std::cout << "My list : " << (my_less < my_greater) << std::endl << std::endl;
    st_greater.push_back(5);
    st_greater.push_back(6);
    st_greater.push_back(7);

    my_greater.push_back(5);
    my_greater.push_back(6);
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 6 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less < st_greater) << std::endl;
    std::cout << "My list : " << (my_less < my_greater) << std::endl << std::endl;
    std::cout << "|   Lists are equivalent   |" << std::endl;
    std::cout << "Standart: " << (first < first_copy) << std::endl;
    std::cout << "My list : " << (first_my < first_my_copy) << std::endl << std::endl;
    st_greater.push_front(5);
    my_greater.push_front(5);
    std::cout << "|   1 - 5 elem, 2 - 7 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less < st_greater) << std::endl;
    std::cout << "My list : " << (my_less < my_greater) << std::endl << std::endl;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));

    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less < st_greater) << std::endl;
    std::cout << "My list : " << (my_less < my_greater) << std::endl << std::endl;
    
    st_greater = st_less;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.push_back(7);

    my_greater = my_less;
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 4 elem. Last number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less < st_greater) << std::endl;
    std::cout << "My list : " << (my_less < my_greater) << std::endl << std::endl;

    st_greater.erase(--(st_greater.end()));
    st_less.erase(st_less.begin());
    st_less.push_front(9);

    my_greater.erase(--(my_greater.end()));
    my_less.erase(my_less.begin());
    my_less.push_front(9);
    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 1 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less < st_greater) << std::endl;
    std::cout << "My list : " << (my_less < my_greater) << std::endl << std::endl;

    std::cout << "_______________________" << std::endl;
    std::cout << "|                     |" << std::endl;
    std::cout << "|     Operator <=     |" << std::endl;
    std::cout << "|_____________________|" << std::endl << std::endl;

    std::list<int> less;
    less.push_back(2);
    less.push_back(3);
    less.push_back(4);
    less.push_back(5);
    less.push_back(6);
    st_less = less;
    std::list<int> greater;
    greater.push_back(2);
    greater.push_back(3);
    greater.push_back(4);
    st_greater = greater;

    ft::List<int> my_l;
    my_l.push_back(2);
    my_l.push_back(3);
    my_l.push_back(4);
    my_l.push_back(5);
    my_l.push_back(6);
    my_less = my_l;
    ft::List<int> my_g;
    my_g.push_back(2);
    my_g.push_back(3);
    my_g.push_back(4);
    my_greater = my_g;  

    std::cout << "|   1 - 5 elem, 2 - 3 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less <= st_greater) << std::endl;
    std::cout << "My list : " << (my_less <= my_greater) << std::endl << std::endl;
    st_greater.push_back(5);
    st_greater.push_back(6);
    st_greater.push_back(7);

    my_greater.push_back(5);
    my_greater.push_back(6);
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 6 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less <= st_greater) << std::endl;
    std::cout << "My list : " << (my_less <= my_greater) << std::endl << std::endl;
    std::cout << "|   Lists are equivalent   |" << std::endl;
    std::cout << "Standart: " << (first <= first_copy) << std::endl;
    std::cout << "My list : " << (first_my <= first_my_copy) << std::endl << std::endl;
    st_greater.push_front(5);
    my_greater.push_front(5);
    std::cout << "|   1 - 5 elem, 2 - 7 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less <= st_greater) << std::endl;
    std::cout << "My list : " << (my_less <= my_greater) << std::endl << std::endl;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));

    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less <= st_greater) << std::endl;
    std::cout << "My list : " << (my_less <= my_greater) << std::endl << std::endl;
    
    st_greater = st_less;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.push_back(7);

    my_greater = my_less;
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 4 elem. Last number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less <= st_greater) << std::endl;
    std::cout << "My list : " << (my_less <= my_greater) << std::endl << std::endl;

    st_greater.erase(--(st_greater.end()));
    st_less.erase(st_less.begin());
    st_less.push_front(9);

    my_greater.erase(--(my_greater.end()));
    my_less.erase(my_less.begin());
    my_less.push_front(9);
    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 1 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less <= st_greater) << std::endl;
    std::cout << "My list : " << (my_less <= my_greater) << std::endl << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Operator >     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;

    st_less = less;
    st_greater = greater;

    my_less = my_l;
    my_greater = my_g;  

    std::cout << "|   1 - 5 elem, 2 - 3 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less > st_greater) << std::endl;
    std::cout << "My list : " << (my_less > my_greater) << std::endl << std::endl;
    st_greater.push_back(5);
    st_greater.push_back(6);
    st_greater.push_back(7);

    my_greater.push_back(5);
    my_greater.push_back(6);
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 6 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less > st_greater) << std::endl;
    std::cout << "My list : " << (my_less > my_greater) << std::endl << std::endl;
    std::cout << "|   Lists are equivalent   |" << std::endl;
    std::cout << "Standart: " << (first > first_copy) << std::endl;
    std::cout << "My list : " << (first_my > first_my_copy) << std::endl << std::endl;
    st_greater.push_front(5);
    my_greater.push_front(5);
    std::cout << "|   1 - 5 elem, 2 - 7 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less > st_greater) << std::endl;
    std::cout << "My list : " << (my_less > my_greater) << std::endl << std::endl;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));

    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less > st_greater) << std::endl;
    std::cout << "My list : " << (my_less > my_greater) << std::endl << std::endl;
    
    st_greater = st_less;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.push_back(7);

    my_greater = my_less;
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 4 elem. Last number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less > st_greater) << std::endl;
    std::cout << "My list : " << (my_less > my_greater) << std::endl << std::endl;

    st_greater.erase(--(st_greater.end()));
    st_less.erase(st_less.begin());
    st_less.push_front(9);

    my_greater.erase(--(my_greater.end()));
    my_less.erase(my_less.begin());
    my_less.push_front(9);
    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 1 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less > st_greater) << std::endl;
    std::cout << "My list : " << (my_less > my_greater) << std::endl << std::endl;

    std::cout << "_______________________" << std::endl;
    std::cout << "|                     |" << std::endl;
    std::cout << "|     Operator >=     |" << std::endl;
    std::cout << "|_____________________|" << std::endl << std::endl;

    st_less = less;
    st_greater = greater;

    my_less = my_l;
    my_greater = my_g;  

    std::cout << "|   1 - 5 elem, 2 - 3 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less >= st_greater) << std::endl;
    std::cout << "My list : " << (my_less >= my_greater) << std::endl << std::endl;
    st_greater.push_back(5);
    st_greater.push_back(6);
    st_greater.push_back(7);

    my_greater.push_back(5);
    my_greater.push_back(6);
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 6 elem (numbers are equivalent)   |" << std::endl;
    std::cout << "Standart: " << (st_less >= st_greater) << std::endl;
    std::cout << "My list : " << (my_less >= my_greater) << std::endl << std::endl;
    std::cout << "|   Lists are equivalent   |" << std::endl;
    std::cout << "Standart: " << (first >= first_copy) << std::endl;
    std::cout << "My list : " << (first_my >= first_my_copy) << std::endl << std::endl;
    st_greater.push_front(5);
    my_greater.push_front(5);
    std::cout << "|   1 - 5 elem, 2 - 7 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less >= st_greater) << std::endl;
    std::cout << "My list : " << (my_less >= my_greater) << std::endl << std::endl;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));

    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less >= st_greater) << std::endl;
    std::cout << "My list : " << (my_less >= my_greater) << std::endl << std::endl;
    
    st_greater = st_less;
    st_greater.erase(--(st_greater.end()));
    st_greater.erase(--(st_greater.end()));
    st_greater.push_back(7);

    my_greater = my_less;
    my_greater.erase(--(my_greater.end()));
    my_greater.erase(--(my_greater.end()));
    my_greater.push_back(7);
    std::cout << "|   1 - 5 elem, 2 - 4 elem. Last number in 2 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less >= st_greater) << std::endl;
    std::cout << "My list : " << (my_less >= my_greater) << std::endl << std::endl;

    st_greater.erase(--(st_greater.end()));
    st_less.erase(st_less.begin());
    st_less.push_front(9);

    my_greater.erase(--(my_greater.end()));
    my_less.erase(my_less.begin());
    my_less.push_front(9);
    std::cout << "|   1 - 5 elem, 2 - 3 elem. First number in 1 is greater   |" << std::endl;
    std::cout << "Standart: " << (st_less >= st_greater) << std::endl;
    std::cout << "My list : " << (my_less >= my_greater) << std::endl << std::endl;

    std::cout << "____________________" << std::endl;
    std::cout << "|                  |" << std::endl;
    std::cout << "|     ft::swap     |" << std::endl;
    std::cout << "|__________________|" << std::endl << std::endl;
    std::list<int> foo (3,100);
    ft::List<int> my_foo(3, 100);
    std::list<int> bar (5,200);
    ft::List<int> my_bar (5,200);

    std::cout << "St foo contains:";
    for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << foo.size() << std::endl;
    std::cout << "My foo contains:";
    for (ft::List<int>::iterator it_my = my_foo.begin(); it_my != my_foo.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << my_foo.size() << std::endl;
    std::cout << "St bar contains:";
    for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << bar.size() << std::endl;
    std::cout << "My bar contains:";
    for (ft::List<int>::iterator it_my = my_bar.begin(); it_my!=my_bar.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << my_bar.size() << std::endl;
    
    std::cout << "|   After swap   |" << std::endl;
    std::swap(foo, bar);
    ft::swap(my_foo, my_bar);

    std::cout << "St foo contains:";
    for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << foo.size() << std::endl;
    std::cout << "My foo contains:";
    for (ft::List<int>::iterator it_my = my_foo.begin(); it_my != my_foo.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << my_foo.size() << std::endl;
    std::cout << "St bar contains:";
    for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "Size: " << bar.size() << std::endl;
    std::cout << "My bar contains:";
    for (ft::List<int>::iterator it_my = my_bar.begin(); it_my!=my_bar.end(); ++it_my)
        std::cout << ' ' << *it_my;
    std::cout << '\n';
    std::cout << "Size: " << my_bar.size() << std::endl << std::endl;
    

    return (0);
}