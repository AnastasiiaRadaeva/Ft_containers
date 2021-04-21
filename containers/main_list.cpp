/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:49:38 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/04/20 17:43:25 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <list>

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

    return (0);
}