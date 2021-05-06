/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:29:50 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/06 14:50:40 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/List.hpp"
#include <list>
#include <cmath>
#include <unistd.h>

#define flag 0


bool mycomparison (double first, double second)
{
    return (int(first)<int(second));
}

bool    is_it(std::string const &str)
{
    return (str == "My");
}

bool    uniqueness(int a, int b)
{
    return (a == b/2);
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
    std::cout << "_________________________________" << std::endl;
    std::cout << "|                               |" << std::endl;
    std::cout << "|     Constructor | Default     |" << std::endl;
    std::cout << "|_______________________________|" << std::endl << std::endl;

    std::list<std::string> standart_list_str;
    std::cout << "Standart list - size: " << standart_list_str.size() << std::endl;
    std::cout << "Standart list - empty: " << standart_list_str.empty() << std::endl;
    std::cout << std::endl;

    ft::List<std::string> my_list_str;
    std::cout << "My list - size: " << my_list_str.size() << std::endl;
    std::cout << "My list - empty: " << my_list_str.empty() << std::endl;
    std::cout << std::endl;


    std::cout << "______________________________" << std::endl;
    std::cout << "|                            |" << std::endl;
    std::cout << "|     Constructor | Fill     |" << std::endl;
    std::cout << "|____________________________|" << std::endl << std::endl;

    std::list<std::string>::iterator it_str_st;
    std::list<std::string> standart_list_str_1(5, "Hello");
    std::cout << "St list: ";
    for (it_str_st = standart_list_str_1.begin(); it_str_st != standart_list_str_1.end(); ++it_str_st)
        std::cout << ' ' << *it_str_st;
    std::cout << std::endl;
    std::cout << "Standart list - size: " << standart_list_str_1.size() << std::endl;
    std::cout << "Standart list - empty: " << standart_list_str_1.empty() << std::endl;
    std::cout << std::endl;

    ft::List<std::string>::iterator it_str_my;
    ft::List<std::string> my_list_str_1(5, "Hello");
    std::cout << "My list: ";
    for (it_str_my = my_list_str_1.begin(); it_str_my != my_list_str_1.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "My list - size: " << my_list_str_1.size() << std::endl;
    std::cout << "My list - empty: " << my_list_str_1.empty() << std::endl;
    std::cout << std::endl;


    std::cout << "____________________________" << std::endl;
    std::cout << "|                          |" << std::endl;
    std::cout << "|     Constructor Iter     |" << std::endl;
    std::cout << "|__________________________|" << std::endl << std::endl;
    std::cout << "List for copy from 2 to 4: ";
    for (it_str_my = my_list_str_1.begin(); it_str_my != my_list_str_1.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_str_1.size() << std::endl;
    ft::List<std::string>::iterator b_iter = ++(my_list_str_1.begin());
    ft::List<std::string>::iterator e_iter = --(my_list_str_1.end());
    
    ft::List<std::string> new_my_list(b_iter, e_iter);
    std::cout << "New list: ";
    for (it_str_my = new_my_list.begin(); it_str_my != new_my_list.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << new_my_list.size() << std::endl;
    std::cout << std::endl;

    ft::List<std::string> my_str_list;
    my_str_list.push_back("Hello");
    my_str_list.push_back("I'm");
    my_str_list.push_back("glad");
    my_str_list.push_back("to");
    my_str_list.push_back("see");
    my_str_list.push_back("you");
    std::cout << "List for copy from 2 to 5: ";
    for (it_str_my = my_str_list.begin(); it_str_my != my_str_list.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_str_list.size() << std::endl;
    b_iter = ++(my_str_list.begin());
    e_iter = --(my_str_list.end());

    ft::List<std::string> new_my_list_1(b_iter, e_iter);
    std::cout << "New list: ";
    for (it_str_my = new_my_list_1.begin(); it_str_my != new_my_list_1.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << new_my_list_1.size() << std::endl;
    std::cout << std::endl;


    std::cout << "____________________________" << std::endl;
    std::cout << "|                          |" << std::endl;
    std::cout << "|     Copy constructor     |" << std::endl;
    std::cout << "|__________________________|" << std::endl << std::endl;

    std::cout << "List for copy: ";
    for (it_str_my = my_str_list.begin(); it_str_my != my_str_list.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_str_list.size() << std::endl;
    
    ft::List<std::string> copy_my_str_list(my_str_list);
    std::cout << "New list: ";
    for (it_str_my = copy_my_str_list.begin(); it_str_my != copy_my_str_list.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << copy_my_str_list.size() << std::endl;
    std::cout << std::endl;


    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Operator=     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    std::cout << "My list 1: ";
    for (it_str_my = my_list_str_1.begin(); it_str_my != my_list_str_1.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_str_1.size() << std::endl;

    std::cout << "My list 2: ";
    for (it_str_my = my_str_list.begin(); it_str_my != my_str_list.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_str_list.size() << std::endl;

    my_list_str_1 = my_str_list;
    std::cout << "My list 1 after operator=: ";
    for (it_str_my = my_list_str_1.begin(); it_str_my != my_list_str_1.end(); ++it_str_my)
        std::cout << ' ' << *it_str_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_str_1.size() << std::endl;
    std::cout << std::endl;


    std::cout << "_______________________________________" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|     Begin | Rbegin | End | Rend     |" << std::endl;
    std::cout << "|_____________________________________|" << std::endl << std::endl;

    int myints[] = {1, 2, 3, 4, 5, 6, 15};
    std::list<int>::iterator it_int;
    std::list<int> list_int(myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "St list: ";
    for (it_int = list_int.begin(); it_int != list_int.end(); ++it_int)
        std::cout << ' ' << *it_int;
    std::cout << std::endl;
    std::cout << "Size: " << list_int.size() << std::endl;

    ft::List<int> my_list_int(myints, myints + sizeof(myints) / sizeof(int));
    ft::List<int>::iterator it_int_my;
    std::cout << "My list: ";
    for (it_int_my = my_list_int.begin(); it_int_my != my_list_int.end(); ++it_int_my)
        std::cout << ' ' << *it_int_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int.size() << std::endl;
    std::cout << std::endl;

    std::cout << "St begin of list: " << *(list_int.begin()) << std::endl;
    std::cout << "My begin of list: " << *(my_list_int.begin()) << std::endl;
    std::cout << std::endl;
    std::cout << "St rbegin of list: " << *(list_int.rbegin()) << std::endl;
    std::cout << "My rbegin of list: " << *(list_int.rbegin()) << std::endl;
    std::cout << std::endl;
    std::cout << "St end->next of list: " << *(++(list_int.end())) << std::endl;
    std::cout << "My end->next of list: " << *(++(my_list_int.end())) << std::endl;
    std::cout << std::endl;
    std::cout << "St rend->next of list: " << *(++(list_int.rend())) << std::endl;
    std::cout << "My rend->next of list: " << *(++(my_list_int.rend())) << std::endl;
    std::cout << std::endl;


    std::cout << "___________________________________" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "|     Empty | Size | Max_size     |" << std::endl;
    std::cout << "|_________________________________|" << std::endl << std::endl;

    std::list<int> empty_l;
    std::cout << "St empty list: " << empty_l.empty() << " | Size: " << empty_l.size() << std::endl;
    std::cout << "Max size: " << empty_l.max_size() << std::endl;
    ft::List<int> empty_l_my;
    std::cout << "My empty list: " << empty_l_my.empty() << " | Size: " << empty_l_my.size() << std::endl;
    std::cout << "Max size: " << empty_l_my.max_size() << std::endl;

    std::cout << "St full list: ";
    for (it_int = list_int.begin(); it_int != list_int.end(); ++it_int)
        std::cout << ' ' << *it_int;
    std::cout << std::endl << "Empty: " << list_int.empty() << " | Size: " << list_int.size() << std::endl;
    std::cout << "My full list: ";
    for (it_int_my = my_list_int.begin(); it_int_my != my_list_int.end(); ++it_int_my)
        std::cout << ' ' << *it_int_my;
    std::cout << std::endl << "Empty: " << my_list_int.empty() << " | Size: " << my_list_int.size() << std::endl;
    std::cout << std::endl;


    std::cout << "________________________" << std::endl;
    std::cout << "|                      |" << std::endl;
    std::cout << "|     Front | Back     |" << std::endl;
    std::cout << "|______________________|" << std::endl << std::endl;
    std::cout << "Front of last st list: " << list_int.front() << std::endl;
    std::cout << "Front of last my list: " << my_list_int.front() << std::endl;
    std::cout << "Back of last st list: " << list_int.back() << std::endl;
    std::cout << "Back of last my list: " << my_list_int.back() << std::endl << std::endl;


   std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Assign     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    std::list<int> list_assign(5, 9);
    std::list<int>::iterator b = list_assign.begin();
    std::cout << "St list before assign: ";
    for (; b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;
    list_assign.assign(3, 7);
    std::cout << "St list after assign: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;

    ft::List<int> my_list_assign(5, 9);
    ft::List<int>::iterator b_my = my_list_assign.begin();
    std::cout << "My list before assign: ";
    for (; b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    my_list_assign.assign(3, 7);
    std::cout << "My list after assign: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                     |" << std::endl;
    std::cout << "|     Assign iter     |" << std::endl;
    std::cout << "|_____________________|" << std::endl << std::endl;

    std::cout << "St list before assign: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;
    list_assign.assign(list_int.begin(), list_int.end());
    std::cout << "St list after assign: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;

    std::cout << "My list before assign: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    my_list_assign.assign(my_list_int.begin(), my_list_int.end());
    std::cout << "My list after assign: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;


    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Push_front     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;

    list_assign.push_front(8);
    std::cout << "Last st list after push_front(8): ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;
    
    my_list_assign.push_front(8);
    std::cout << "Last my list after push_front(8): ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;


    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Pop_front     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    list_assign.pop_front();
    std::cout << "Last st list after pop_front: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;
    
    my_list_assign.pop_front();
    std::cout << "Last my list after pop_front: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;


    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Push_back     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    list_assign.push_back(8);
    std::cout << "Last st list after push_back(8): ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;
    
    my_list_assign.push_back(8);
    std::cout << "Last my list after push_back(8): ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;


    std::cout << "____________________" << std::endl;
    std::cout << "|                  |" << std::endl;
    std::cout << "|     Pop_back     |" << std::endl;
    std::cout << "|__________________|" << std::endl << std::endl;

    list_assign.pop_back();
    std::cout << "Last st list after pop_back: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << std::endl;
    std::cout << "Size: " << list_assign.size() << std::endl;
    
    my_list_assign.pop_back();
    std::cout << "Last my list after pop_back: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << std::endl;
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;


    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Insert     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;
    
    std::cout << "St list before insert: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl;
    b = list_assign.begin();
    list_assign.insert(++b,10);
    std::cout << "St list after insert | single element: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl;
    b = list_assign.end();
    list_assign.insert(--b, 3, 7);
    std::cout << "St list after insert | fill: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl;    
    std::list<int> st_add_lst;
    st_add_lst.push_back(9);
    st_add_lst.push_back(8);
    st_add_lst.push_back(7);
    list_assign.insert(++(list_assign.begin()), st_add_lst.begin(), st_add_lst.end());
    std::cout << "St list after insert | range: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl;
    std::cout << std::endl;

    std::cout << "My list before insert: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    b_my = my_list_assign.begin();
    my_list_assign.insert(++b_my,10);
    std::cout << "My list after insert | single element: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    b_my = my_list_assign.end();
    my_list_assign.insert(--b_my, 3, 7);
    std::cout << "My list after insert | fill: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    ft::List<int> my_add_lst;
    my_add_lst.push_back(9);
    my_add_lst.push_back(8);
    my_add_lst.push_back(7);
    my_list_assign.insert(++(my_list_assign.begin()), my_add_lst.begin(), my_add_lst.end());
    std::cout << "My list after insert | range: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;


    std::cout << "______________________________" << std::endl;
    std::cout << "|                            |" << std::endl;
    std::cout << "|     Erase | one element    |" << std::endl;
    std::cout << "|____________________________|" << std::endl << std::endl;

    std::cout << "St list before erase: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl;
    b = list_assign.erase(++(list_assign.begin()));
    std::cout << "Elem in erase position: " << *b << std::endl;
    std::cout << "St list after erase: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl;
    b = list_assign.erase(--(list_assign.end()));
    std::cout << "Elem in erase position: " << *b << std::endl;
    std::cout << "St list after erase end of list: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl << std::endl;
    
    std::cout << "My list before erase: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    b_my = my_list_assign.erase(++(my_list_assign.begin()));
    std::cout << "Elem in erase position: " << *b_my << std::endl;
    std::cout << "My list after erase: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    b_my = my_list_assign.erase(--(my_list_assign.end()));
    std::cout << "Elem in erase position: " << *b_my << std::endl;
    std::cout << "My list after erase end of list: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
       

    std::cout << "_______________________" << std::endl;
    std::cout << "|                     |" << std::endl;
    std::cout << "|     Erase | list    |" << std::endl;
    std::cout << "|_____________________|" << std::endl << std::endl;

    std::cout << "St list before erase: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl;
    b = list_assign.erase(++(list_assign.begin()), --(list_assign.end()));
    std::cout << "Elem in erase position: " << *b << std::endl;
    std::cout << "St list after erase: ";
    for (b = list_assign.begin(); b != list_assign.end(); ++b)
        std::cout << ' ' << *b;
    std::cout << '\n';
    std::cout << "Size: " << list_assign.size() << std::endl << std::endl;
    
    std::cout << "My list before erase: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    b_my = my_list_assign.erase(++(my_list_assign.begin()), --(my_list_assign.end()));
    std::cout << "Elem in erase position: " << *b_my << std::endl;
    std::cout << "My list after erase: ";
    for (b_my = my_list_assign.begin(); b_my != my_list_assign.end(); ++b_my)
        std::cout << ' ' << *b_my;
    std::cout << '\n';
    std::cout << "Size: " << my_list_assign.size() << std::endl;
    std::cout << std::endl;


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
    std::cout << "St list a: ";
    while (b_i_swap != e_i_swap)
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    std::list<std::string> swap_st_list_2;
    swap_st_list_2.push_back("My");
    swap_st_list_2.push_back("name");
    swap_st_list_2.push_back("is");
    swap_st_list_2.push_back("Nastya");
    std::list<std::string>::iterator b_i_swap_2 = swap_st_list_2.begin();
    std::list<std::string>::iterator e_i_swap_2 = swap_st_list_2.end();
    std::cout << "St list b: ";
    b_i_swap_2 = swap_st_list_2.begin();
    e_i_swap_2 = swap_st_list_2.end();
    while (b_i_swap_2 != e_i_swap_2)
    {
        std::cout << *b_i_swap_2 << " ";
        ++b_i_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list_2.size() << std::endl;
    swap_st_list.swap(swap_st_list_2);
    b_i_swap = swap_st_list.begin();
    e_i_swap = swap_st_list.end();
    std::cout << "St list a: ";
    while (b_i_swap != e_i_swap)
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    std::cout << "St list b: ";
    b_i_swap_2 = swap_st_list_2.begin();
    e_i_swap_2 = swap_st_list_2.end();
    while (b_i_swap_2 != e_i_swap_2)
    {
        std::cout << *b_i_swap_2 << " ";
        ++b_i_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list_2.size() << std::endl << std::endl;

    ft::List<std::string> swap_my_list;
    swap_my_list.push_back("Hello");
    swap_my_list.push_back("I'm");
    swap_my_list.push_back("glad");
    swap_my_list.push_back("to");
    swap_my_list.push_back("see");
    swap_my_list.push_back("you");
    ft::List<std::string>::iterator b_my_swap = swap_my_list.begin();
    ft::List<std::string>::iterator e_my_swap = swap_my_list.end();
    std::cout << "My list a: ";
    while (b_my_swap != e_my_swap)
    {
        std::cout << *b_my_swap << " ";
        ++b_my_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    ft::List<std::string> swap_my_list_2;
    swap_my_list_2.push_back("My");
    swap_my_list_2.push_back("name");
    swap_my_list_2.push_back("is");
    swap_my_list_2.push_back("Nastya");
    ft::List<std::string>::iterator b_my_swap_2 = swap_my_list_2.begin();
    ft::List<std::string>::iterator e_my_swap_2 = swap_my_list_2.end();
    std::cout << "My list b: ";
    b_my_swap_2 = swap_my_list_2.begin();
    e_my_swap_2 = swap_my_list_2.end();
    while (b_my_swap_2 != e_my_swap_2)
    {
        std::cout << *b_my_swap_2 << " ";
        ++b_my_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list_2.size() << std::endl;
    swap_my_list.swap(swap_my_list_2);
    b_my_swap = swap_my_list.begin();
    e_my_swap = swap_my_list.end();
    std::cout << "My list a: ";
    while (b_my_swap != e_my_swap)
    {
        std::cout << *b_my_swap << " ";
        ++b_my_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    std::cout << "My list b: ";
    b_my_swap_2 = swap_my_list_2.begin();
    e_my_swap_2 = swap_my_list_2.end();
    while (b_my_swap_2 != e_my_swap_2)
    {
        std::cout << *b_my_swap_2 << " ";
        ++b_my_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list_2.size() << std::endl;
    
 
    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Resize     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    std::cout << "St list before resize: ";
    for (b_i_swap_2 = swap_st_list_2.begin(); b_i_swap_2 != swap_st_list_2.end(); b_i_swap_2++)
        std::cout << *b_i_swap_2 << " ";
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list_2.size() << std::endl;
    swap_st_list_2.resize(2);
    std::cout << "Standart decrement: ";
    b_i_swap_2 = swap_st_list_2.begin();
    e_i_swap_2 = swap_st_list_2.end();
    while (b_i_swap_2 != e_i_swap_2)
    {
        std::cout << *b_i_swap_2 << " ";
        ++b_i_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list_2.size() << std::endl;
    swap_st_list_2.resize(7, "Nastya");    
    b_i_swap_2 = swap_st_list_2.begin();
    e_i_swap_2 = swap_st_list_2.end();
    std::cout << "Standart increment: ";
    while (b_i_swap_2 != e_i_swap_2)
    {
        std::cout << *b_i_swap_2 << " ";
        ++b_i_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list_2.size() << std::endl << std::endl;

   std::cout << "My list before resize: ";
    for (b_my_swap_2 = swap_my_list_2.begin(); b_my_swap_2 != swap_my_list_2.end(); b_my_swap_2++)
        std::cout << *b_my_swap_2 << " ";
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list_2.size() << std::endl;
    swap_my_list_2.resize(2);
    std::cout << "My decrement: ";
    b_my_swap_2 = swap_my_list_2.begin();
    e_my_swap_2 = swap_my_list_2.end();
    while (b_my_swap_2 != e_my_swap_2)
    {
        std::cout << *b_my_swap_2 << " ";
        ++b_my_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list_2.size() << std::endl;
    swap_my_list_2.resize(7, "Nastya");    
    b_my_swap_2 = swap_my_list_2.begin();
    e_my_swap_2 = swap_my_list_2.end();
    std::cout << "My increment: ";
    while (b_my_swap_2 != e_my_swap_2)
    {
        std::cout << *b_my_swap_2 << " ";
        ++b_my_swap_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list_2.size() << std::endl;


    std::cout << "_________________" << std::endl;
    std::cout << "|               |" << std::endl;
    std::cout << "|     Clear     |" << std::endl;
    std::cout << "|_______________|" << std::endl << std::endl;

    std::cout << "St list before clear: ";
    for (b_i_swap_2 = swap_st_list_2.begin(); b_i_swap_2 != swap_st_list_2.end(); b_i_swap_2++)
        std::cout << *b_i_swap_2 << " ";
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list_2.size() << std::endl;
    swap_st_list_2.clear();
    std::cout << "St list after clear: ";
    for (b_i_swap_2 = swap_st_list_2.begin(); b_i_swap_2 != swap_st_list_2.end(); b_i_swap_2++)
        std::cout << *b_i_swap_2 << " ";
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list_2.size() << std::endl;
    
    std::cout << "My list before clear: ";
    for (b_my_swap_2 = swap_my_list_2.begin(); b_my_swap_2 != swap_my_list_2.end(); b_my_swap_2++)
        std::cout << *b_my_swap_2 << " ";
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list_2.size() << std::endl;
    swap_my_list_2.clear();
    std::cout << "My list after clear: ";
    for (b_my_swap_2 = swap_my_list_2.begin(); b_my_swap_2 != swap_my_list_2.end(); b_my_swap_2++)
        std::cout << *b_my_swap_2 << " ";
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list_2.size() << std::endl;


    std::cout << "________________________________" << std::endl;
    std::cout << "|                              |" << std::endl;
    std::cout << "|     Splice | entire list     |" << std::endl;
    std::cout << "|______________________________|" << std::endl << std::endl;

    double mydoubles_1[]={ 2.72, 2.2, 2.57};
    std::list<double> mylist_add;
    mylist_add.push_back(7.1);
    mylist_add.push_back(7.3);
    mylist_add.push_back(7.5);
    std::list<double>::iterator it_st;
    std::list<double> mylist (mydoubles_1, mydoubles_1 + 3);
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
    ft::List<double>::iterator it_my;
    ft::List<double> mylist_1(mydoubles_1, mydoubles_1 + 3);
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
        

    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Remove     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    b_i_swap = swap_st_list.begin();
    std::cout << "St list: ";
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    swap_st_list.remove("Nastya");
    std::cout << "St list after remove \"Nastya\": ";
    b_i_swap = swap_st_list.begin();
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl << std::endl;
    
    b_my_swap = swap_my_list.begin();
    std::cout << "My list: ";
    while (b_my_swap != swap_my_list.end())
    {
        std::cout << *b_my_swap << " ";
        ++b_my_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    swap_my_list.remove("Nastya");
    std::cout << "My list after remove \"Nastya\": ";
    b_my_swap = swap_my_list.begin();
    while (b_my_swap != swap_my_list.end())
    {
        std::cout << *b_my_swap << " ";
        ++b_my_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl << std::endl;


    std::cout << "_____________________" << std::endl;
    std::cout << "|                   |" << std::endl;
    std::cout << "|     Remove_if     |" << std::endl;
    std::cout << "|___________________|" << std::endl << std::endl;

    b_i_swap = swap_st_list.begin();
    std::cout << "St list: ";
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    swap_st_list.remove_if(is_it);
    std::cout << "St list after remove_if \"My\": ";
    b_i_swap = swap_st_list.begin();
    while (b_i_swap != swap_st_list.end())
    {
        std::cout << *b_i_swap << " ";
        ++b_i_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl << std::endl;
    
    b_my_swap = swap_my_list.begin();
    std::cout << "My list: ";
    while (b_my_swap != swap_my_list.end())
    {
        std::cout << *b_my_swap << " ";
        ++b_my_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_my_list.size() << std::endl;
    std::cout << "My list after remove_if \"My\": ";
    swap_my_list.remove_if(is_it);
    b_my_swap = swap_my_list.begin();
    while (b_my_swap != swap_my_list.end())
    {
        std::cout << *b_my_swap << " ";
        ++b_my_swap;
    }
    std::cout << std::endl;
    std::cout << "Size: " << swap_st_list.size() << std::endl;
    std::cout << std::endl;


    std::cout << "__________________" << std::endl;
    std::cout << "|                |" << std::endl;
    std::cout << "|     Unique     |" << std::endl;
    std::cout << "|________________|" << std::endl << std::endl;

    std::list<int> standart_list_int;
    standart_list_int.push_back(1);
    standart_list_int.push_back(2);
    standart_list_int.push_back(3);
    standart_list_int.push_back(4);
    standart_list_int.push_back(5);
    standart_list_int.resize(7, 21);
    standart_list_int.resize(8, 4);
    std::list<int>::iterator b_iter_st_list_int = standart_list_int.begin();
    std::cout << "St list: ";
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl;
    standart_list_int.unique();
    std::cout << "St list after unique: ";
    b_iter_st_list_int = standart_list_int.begin();
    while (b_iter_st_list_int != standart_list_int.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << standart_list_int.size() << std::endl << std::endl;
    
    ft::List<int> my_list_int_2;
    my_list_int_2.push_back(1);
    my_list_int_2.push_back(2);
    my_list_int_2.push_back(3);
    my_list_int_2.push_back(4);
    my_list_int_2.push_back(5);
    my_list_int_2.resize(7, 21);
    my_list_int_2.resize(8, 4);
    ft::List<int>::iterator b_iter_my_list_int_2 = my_list_int_2.begin();
    std::cout << "My list: ";
    while (b_iter_my_list_int_2 != my_list_int_2.end())
    {
        std::cout << *b_iter_my_list_int_2 << " ";
        ++b_iter_my_list_int_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int_2.size() << std::endl;
    my_list_int_2.unique();
    std::cout << "My list after unique: ";
    b_iter_my_list_int_2 = my_list_int_2.begin();
    while (b_iter_my_list_int_2 != my_list_int_2.end())
    {
        std::cout << *b_iter_my_list_int_2 << " ";
        ++b_iter_my_list_int_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int_2.size() << std::endl << std::endl;


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
    std::cout << "Size: " << standart_list_int.size() << std::endl << std::endl;
    
    my_list_int_2.resize(3, 10);
    my_list_int_2.resize(5, 32);
    b_iter_my_list_int_2 = my_list_int_2.begin();
    std::cout << "My list: ";
    while (b_iter_my_list_int_2 != my_list_int_2.end())
    {
        std::cout << *b_iter_my_list_int_2 << " ";
        ++b_iter_my_list_int_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int_2.size() << std::endl;
    my_list_int_2.unique(uniqueness);
    std::cout << "My list after unique: ";
    
    b_iter_my_list_int_2 = my_list_int_2.begin();
    while (b_iter_my_list_int_2 != my_list_int_2.end())
    {
        std::cout << *b_iter_my_list_int_2 << " ";
        ++b_iter_my_list_int_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_list_int_2.size() << std::endl;


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
    std::cout << std::endl;


    std::cout << "___________________" << std::endl;
    std::cout << "|                 |" << std::endl;
    std::cout << "|     Sort | 1    |" << std::endl;
    std::cout << "|_________________|" << std::endl << std::endl;

    int int_sort[] = {1, 2, 3, 5, 2, 8, 15, 0, 9};
    std::list<int> st_sort(int_sort, int_sort + 9);
    b_iter_st_list_int = st_sort.begin();
    st_sort.push_back(4);
    st_sort.push_back(3);
    st_sort.push_back(0);
    std::cout << "St list: ";
    while (b_iter_st_list_int != st_sort.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << st_sort.size() << std::endl;
    st_sort.sort();
    b_iter_st_list_int = st_sort.begin();
    std::cout << "St list after sort: ";
    while (b_iter_st_list_int != st_sort.end())
    {
        std::cout << *b_iter_st_list_int << " ";
        ++b_iter_st_list_int;
    }
    std::cout << std::endl;
    std::cout << "Size: " << st_sort.size() << std::endl << std::endl;

    ft::List<int> my_sort(int_sort, int_sort + 9);
    b_iter_my_list_int_2 = my_sort.begin();
    my_sort.push_back(4);
    my_sort.push_back(3);
    my_sort.push_back(0);
    std::cout << "My list: ";
    while (b_iter_my_list_int_2 != my_sort.end())
    {
        std::cout << *b_iter_my_list_int_2 << " ";
        ++b_iter_my_list_int_2;
    }
    std::cout << std::endl;
    std::cout << "Size: " << my_sort.size() << std::endl;
    my_sort.sort();
    std::cout << "My list after sort: ";
    for (b_iter_my_list_int_2 = my_sort.begin(); b_iter_my_list_int_2 != my_sort.end(); b_iter_my_list_int_2++)
        std::cout << *b_iter_my_list_int_2 << " ";
    std::cout << std::endl;
    std::cout << "Size: " << my_sort.size() << std::endl << std::endl;


    std::cout << "_________________________" << std::endl;
    std::cout << "|                       |" << std::endl;
    std::cout << "|     Sort with comp    |" << std::endl;
    std::cout << "|_______________________|" << std::endl << std::endl;

    std::list<std::string> mylist_2;
    std::list<std::string>::iterator it_2;
    mylist_2.push_back("one");
    mylist_2.push_back ("two");
    mylist_2.push_back ("two");
    mylist_2.push_back ("two");
    mylist_2.push_back ("Three");
    mylist_2.push_back ("two");
    std::cout << "St list before sort contains:";
    for (it_2 = mylist_2.begin(); it_2 != mylist_2.end(); ++it_2)
        std::cout << ' ' << *it_2;
    std::cout << '\n';
    std::cout << "Size: " << mylist_2.size() << std::endl;
    mylist_2.sort();
    std::cout << "St list after < sort contains:";
    for (it_2 = mylist_2.begin(); it_2 != mylist_2.end(); ++it_2)
        std::cout << ' ' << *it_2;
    std::cout << '\n';
    std::cout << "Size: " << mylist_2.size() << std::endl;
    mylist_2.sort(compare_nocase);
    std::cout << "St list after comp sort contains:";
    for (it_2 = mylist_2.begin(); it_2!=mylist_2.end(); ++it_2)
        std::cout << ' ' << *it_2;
    std::cout << std::endl;
    std::cout << "Size: " << mylist_2.size() << std::endl << std::endl;

    ft::List<std::string> mylist_3;
    ft::List<std::string>::iterator it_3;
    mylist_3.push_back("one");
    mylist_3.push_back ("two");
    mylist_3.push_back ("two");
    mylist_3.push_back ("two");
    mylist_3.push_back ("Three");
    mylist_3.push_back ("two");
    std::cout << "My list before sort contains:";
    for (it_3 = mylist_3.begin(); it_3 != mylist_3.end(); ++it_3)
        std::cout << ' ' << *it_3;
    std::cout << '\n';
    std::cout << "Size: " << mylist_3.size() << std::endl;
    mylist_3.sort();
    std::cout << "My list after < sort contains:";
    for (it_3 = mylist_3.begin(); it_3 != mylist_3.end(); ++it_3)
        std::cout << ' ' << *it_3;
    std::cout << '\n';
    std::cout << "Size: " << mylist_3.size() << std::endl;
    mylist_3.sort(compare_nocase);
    std::cout << "My list after comp sort contains:";
    for (it_3 = mylist_3.begin(); it_3!=mylist_3.end(); ++it_3)
        std::cout << ' ' << *it_3;
    std::cout << std::endl;
    std::cout << "Size: " << mylist_3.size() << std::endl << std::endl;


    std::cout << "___________________" << std::endl;
    std::cout << "|                 |" << std::endl;
    std::cout << "|     Reverse     |" << std::endl;
    std::cout << "|_________________|" << std::endl << std::endl;

    std::cout << "St list before reverse:";
    for (it_2 = mylist_2.begin(); it_2 != mylist_2.end(); ++it_2)
        std::cout << ' ' << *it_2;
    std::cout << '\n';
    std::cout << "Size: " << mylist_2.size() << std::endl;
    mylist_2.reverse();
    std::cout << "St list after reverse:";
    for (it_2 = mylist_2.begin(); it_2 != mylist_2.end(); ++it_2)
        std::cout << ' ' << *it_2;
    std::cout << '\n';
    std::cout << "Size: " << mylist_2.size() << std::endl << std::endl;

    std::cout << "My list before reverse:";
    for (it_3 = mylist_3.begin(); it_3 != mylist_3.end(); ++it_3)
        std::cout << ' ' << *it_3;
    std::cout << '\n';
    std::cout << "Size: " << mylist_3.size() << std::endl;
    mylist_3.reverse();
    std::cout << "St list after reverse:";
    for (it_3 = mylist_3.begin(); it_3 != mylist_3.end(); ++it_3)
        std::cout << ' ' << *it_3;
    std::cout << '\n';
    std::cout << "Size: " << mylist_3.size() << std::endl << std::endl;


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
    std::cout << "Size: " << my_bar.size() << std::endl << std::endl;
    
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

# if flag > 0
    
    // sleep(1000);
#endif

    
    return (0);
}