/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:20:19 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/06 14:50:20 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/Queue.hpp"
#include <queue>
#include <list>
#include <unistd.h>

# define COL_STANDART "\033[0;33m" //yellow
# define COL_MY "\033[0;36m" //blue
# define COL_END "\033[0m"

template <class Cont>
void    print_container(Cont &queue)
{
    typename Cont::iterator begin;
    for (begin = queue.begin(); begin != queue.end(); begin++)
        std::cout << *begin << " ";
    std::cout << std::endl;
}

void    constr_default()
{
    std::cout << COL_STANDART << "Standart not empty list" << COL_END << std::endl;
    std::list<int> st_list(3, 7);
    std::cout << COL_STANDART << "Size: " << COL_END << st_list.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_list.empty() << std::endl;
    std::cout << COL_STANDART << "Standart queue (list)" << COL_END << std::endl;
    std::queue<int, std::list<int> > st_queue(st_list);
    std::cout << COL_STANDART << "Size: " << COL_END << st_queue.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_queue.empty() << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My not empty list" << COL_END << std::endl;
    ft::List<int> my_list(3, 7);
    std::cout << COL_MY << "Size: " << COL_END << my_list.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_list.empty() << std::endl;
    std::cout << COL_MY << "My queue (list)" << COL_END << std::endl;
    ft::Queue<int> my_queue(my_list);
    std::cout << COL_MY << "Size: " << COL_END << my_queue.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_queue.empty() << std::endl;
    std::cout << std::endl;

    std::cout << COL_STANDART << "Standart empty list" << COL_END << std::endl;
    std::list<int> st_list_2;
    std::cout << COL_STANDART << "Size: " << COL_END << st_list_2.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_list_2.empty() << std::endl;
    std::cout << COL_STANDART << "Standart queue (list)" << COL_END << std::endl;
    std::queue<int, std::list<int> > st_queue_2(st_list_2);
    std::cout << COL_STANDART << "Size: " << COL_END << st_queue_2.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_queue_2.empty() << std::endl;
    std::cout << std::endl;
    
    std::cout << COL_MY << "My empty list" << COL_END << std::endl;
    ft::List<int> my_list_2;
    std::cout << COL_MY << "Size: " << COL_END << my_list_2.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_list_2.empty() << std::endl;
    std::cout << COL_MY << "My queue (list)" << COL_END << std::endl;
    ft::Queue<int> my_queue_2(my_list_2);
    std::cout << COL_MY << "Size: " << COL_END << my_queue_2.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_queue_2.empty() << std::endl;
}

void    front_back()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::list<std::string> st_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::list<std::string> >(st_list);
    std::cout << COL_STANDART << "St list" << COL_END << std::endl;
    std::cout << COL_STANDART << "Front: " << COL_END << st_list.front() << std::endl;
    std::cout << COL_STANDART << "Back: " << COL_END << st_list.back() << std::endl;
    std::cout << COL_STANDART << "St queue: " << COL_END << std::endl;
    std::queue<std::string, std::list<std::string> > st_queue(st_list);
    std::cout << COL_STANDART << "Front: " << COL_END << st_queue.front() << std::endl;
    std::cout << COL_STANDART << "Back: " << COL_END << st_queue.back() << std::endl;
    std::cout << std::endl;

    print_container<std::list<std::string> >(st_list);
    std::cout << COL_MY << "My list: " << COL_END << std::endl;
    ft::List<std::string> my_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    std::cout << COL_MY << "Front: " << COL_END << my_list.front() << std::endl;
    std::cout << COL_MY << "Back: " << COL_END << my_list.back() << std::endl;
    std::cout << COL_MY << "My queue: " << COL_END << std::endl;
    ft::Queue<std::string> my_queue(my_list);
    std::cout << COL_MY << "Front: " << COL_END << my_queue.front() << std::endl;
    std::cout << COL_MY << "Back: " << COL_END << my_queue.back() << std::endl;
}

void    push_pop()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::list<std::string> st_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::list<std::string> >(st_list);
    std::cout << COL_STANDART << "St list" << COL_END << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_list.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_list.empty() << std::endl << std::endl;
    std::cout << COL_STANDART << "St queue: " << COL_END << std::endl;
    std::queue<std::string, std::list<std::string> > st_queue(st_list);
    std::cout << COL_STANDART << "Back: " << COL_END << st_queue.back() << std::endl;
    std::cout << COL_STANDART << "Front: " << COL_END << st_queue.front() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_queue.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_queue.empty() << std::endl;
    st_queue.push("Monday");
    std::cout << COL_STANDART << "St queue after push \"Monday\"" << COL_END << std::endl;
    std::cout << COL_STANDART << "Back: " << COL_END << st_queue.back() << std::endl;
    std::cout << COL_STANDART << "Front: " << COL_END << st_queue.front() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_queue.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_queue.empty() << std::endl;
    st_queue.push("Friday");
    std::cout << COL_STANDART << "St queue after push \"Friday\"" << COL_END << std::endl;
    std::cout << COL_STANDART << "Back: " << COL_END << st_queue.back() << std::endl;
    std::cout << COL_STANDART << "Front: " << COL_END << st_queue.front() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_queue.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_queue.empty() << std::endl;
    st_queue.pop();
    std::cout << COL_STANDART << "St queue after pop" << COL_END << std::endl;
    std::cout << COL_STANDART << "Back: " << COL_END << st_queue.back() << std::endl;
    std::cout << COL_STANDART << "Front: " << COL_END << st_queue.front() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_queue.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_queue.empty() << std::endl;
    st_queue.pop();
    std::cout << COL_STANDART << "St queue after pop" << COL_END << std::endl;
    std::cout << COL_STANDART << "Back: " << COL_END << st_queue.back() << std::endl;
    std::cout << COL_STANDART << "Front: " << COL_END << st_queue.front() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_queue.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_queue.empty() << std::endl;
    std::cout << std::endl;
    
    ft::List<std::string> my_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::List<std::string> >(my_list);
    std::cout << COL_MY << "St list" << COL_END << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_list.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_list.empty() << std::endl << std::endl;
    std::cout << COL_MY << "St queue: " << COL_END << std::endl;
    ft::Queue<std::string> my_queue(my_list);
    std::cout << COL_MY << "Back: " << COL_END << my_queue.back() << std::endl;
    std::cout << COL_MY << "Front: " << COL_END << my_queue.front() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_queue.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_queue.empty() << std::endl;
    my_queue.push("Monday");
    std::cout << COL_MY << "St queue after push \"Monday\"" << COL_END << std::endl;
    std::cout << COL_MY << "Back: " << COL_END << my_queue.back() << std::endl;
    std::cout << COL_MY << "Front: " << COL_END << my_queue.front() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_queue.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_queue.empty() << std::endl;
    my_queue.push("Friday");
    std::cout << COL_MY << "St queue after push \"Friday\"" << COL_END << std::endl;
    std::cout << COL_MY << "Back: " << COL_END << my_queue.back() << std::endl;
    std::cout << COL_MY << "Front: " << COL_END << my_queue.front() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_queue.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_queue.empty() << std::endl;
    my_queue.pop();
    std::cout << COL_MY << "St queue after pop" << COL_END << std::endl;
    std::cout << COL_MY << "Back: " << COL_END << my_queue.back() << std::endl;
    std::cout << COL_MY << "Front: " << COL_END << my_queue.front() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_queue.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_queue.empty() << std::endl;
    my_queue.pop();
    std::cout << COL_MY << "St queue after pop" << COL_END << std::endl;
    std::cout << COL_MY << "Back: " << COL_END << my_queue.back() << std::endl;
    std::cout << COL_MY << "Front: " << COL_END << my_queue.front() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_queue.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_queue.empty() << std::endl;
}

void    equal()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_STANDART << "St not equivalent: " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::queue<int, std::list<int> > st_queue(st_list);
    std::list<int> st_list_2(myints, myints + 2);
    std::queue<int, std::list<int> > st_queue_2(st_list_2);
    std::cout << (st_queue == st_queue_2) << std::endl;
    std::cout << COL_STANDART << "St equivalent: " << COL_END;
    st_list.pop_back();
    st_list.pop_back();
    std::queue<int, std::list<int> > st_queue_3(st_list);
    std::cout << (st_queue_3 == st_queue_2) << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My not equivalent: " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Queue<int> my_queue(my_list);
    ft::List<int> my_list_2(myints, myints + 2);
    ft::Queue<int> my_queue_2(my_list_2);
    std::cout << (my_queue == my_queue_2) << std::endl;
    std::cout << COL_MY << "My equivalent: " << COL_END;
    my_list.pop_back();
    my_list.pop_back();
    ft::Queue<int> my_queue_3(my_list);
    std::cout << (my_queue_3 == my_queue_2) << std::endl;
}

void    not_equal()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_STANDART << "St not equivalent: " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::queue<int, std::list<int> > st_queue(st_list);
    std::list<int> st_list_2(myints, myints + 2);
    std::queue<int, std::list<int> > st_queue_2(st_list_2);
    std::cout << (st_queue != st_queue_2) << std::endl;
    std::cout << COL_STANDART << "St equivalent: " << COL_END;
    st_list.pop_back();
    st_list.pop_back();
    std::queue<int, std::list<int> > st_queue_3(st_list);
    std::cout << (st_queue_3 != st_queue_2) << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My not equivalent: " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Queue<int> my_queue(my_list);
    ft::List<int> my_list_2(myints, myints + 2);
    ft::Queue<int> my_queue_2(my_list_2);
    std::cout << (my_queue != my_queue_2) << std::endl;
    std::cout << COL_MY << "My equivalent: " << COL_END;
    my_list.pop_back();
    my_list.pop_back();
    ft::Queue<int> my_queue_3(my_list);
    std::cout << (my_queue_3 != my_queue_2) << std::endl;
}

void    less()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::queue<int, std::list<int> > st_queue(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::queue<int, std::list<int> > st_queue_2(st_list_2);
    std::cout << (st_queue < st_queue_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::queue<int, std::list<int> > st_queue_3(st_list_2);
    std::cout << (st_queue < st_queue_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::queue<int, std::list<int> > st_queue_4(st_list_2);
    std::cout << (st_queue < st_queue_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::queue<int, std::list<int> > st_queue_5(st_list_2);
    std::cout << (st_queue < st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_6(st_list);
    std::cout << (st_queue_6 < st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_7(st_list);
    std::cout << (st_queue_7 < st_queue_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Queue<int> my_queue(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Queue<int> my_queue_2(my_list_2);
    std::cout << (my_queue < my_queue_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Queue<int> my_queue_3(my_list_2);
    std::cout << (my_queue < my_queue_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Queue<int> my_queue_4(my_list_2);
    std::cout << (my_queue < my_queue_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Queue<int> my_queue_5(my_list_2);
    std::cout << (my_queue < my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_6(my_list);
    std::cout << (my_queue_6 < my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_7(my_list);
    std::cout << (my_queue_7 < my_queue_5) << std::endl;
}

void    less_or_equal()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::queue<int, std::list<int> > st_queue(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::queue<int, std::list<int> > st_queue_2(st_list_2);
    std::cout << (st_queue <= st_queue_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::queue<int, std::list<int> > st_queue_3(st_list_2);
    std::cout << (st_queue <= st_queue_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::queue<int, std::list<int> > st_queue_4(st_list_2);
    std::cout << (st_queue <= st_queue_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::queue<int, std::list<int> > st_queue_5(st_list_2);
    std::cout << (st_queue <= st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_6(st_list);
    std::cout << (st_queue_6 <= st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_7(st_list);
    std::cout << (st_queue_7 <= st_queue_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Queue<int> my_queue(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Queue<int> my_queue_2(my_list_2);
    std::cout << (my_queue <= my_queue_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Queue<int> my_queue_3(my_list_2);
    std::cout << (my_queue <= my_queue_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Queue<int> my_queue_4(my_list_2);
    std::cout << (my_queue <= my_queue_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Queue<int> my_queue_5(my_list_2);
    std::cout << (my_queue <= my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_6(my_list);
    std::cout << (my_queue_6 <= my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_7(my_list);
    std::cout << (my_queue_7 <= my_queue_5) << std::endl;
}

void    greater()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::queue<int, std::list<int> > st_queue(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::queue<int, std::list<int> > st_queue_2(st_list_2);
    std::cout << (st_queue > st_queue_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::queue<int, std::list<int> > st_queue_3(st_list_2);
    std::cout << (st_queue > st_queue_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::queue<int, std::list<int> > st_queue_4(st_list_2);
    std::cout << (st_queue > st_queue_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::queue<int, std::list<int> > st_queue_5(st_list_2);
    std::cout << (st_queue > st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_6(st_list);
    std::cout << (st_queue_6 > st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_7(st_list);
    std::cout << (st_queue_7 > st_queue_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Queue<int> my_queue(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Queue<int> my_queue_2(my_list_2);
    std::cout << (my_queue > my_queue_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Queue<int> my_queue_3(my_list_2);
    std::cout << (my_queue > my_queue_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Queue<int> my_queue_4(my_list_2);
    std::cout << (my_queue > my_queue_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Queue<int> my_queue_5(my_list_2);
    std::cout << (my_queue > my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_6(my_list);
    std::cout << (my_queue_6 > my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_7(my_list);
    std::cout << (my_queue_7 > my_queue_5) << std::endl;
}

void    greater_or_equal()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::queue<int, std::list<int> > st_queue(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::queue<int, std::list<int> > st_queue_2(st_list_2);
    std::cout << (st_queue >= st_queue_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::queue<int, std::list<int> > st_queue_3(st_list_2);
    std::cout << (st_queue >= st_queue_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::queue<int, std::list<int> > st_queue_4(st_list_2);
    std::cout << (st_queue >= st_queue_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::queue<int, std::list<int> > st_queue_5(st_list_2);
    std::cout << (st_queue >= st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_6(st_list);
    std::cout << (st_queue_6 >= st_queue_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::queue<int, std::list<int> > st_queue_7(st_list);
    std::cout << (st_queue_7 >= st_queue_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Queue<int> my_queue(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Queue<int> my_queue_2(my_list_2);
    std::cout << (my_queue >= my_queue_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Queue<int> my_queue_3(my_list_2);
    std::cout << (my_queue >= my_queue_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Queue<int> my_queue_4(my_list_2);
    std::cout << (my_queue >= my_queue_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Queue<int> my_queue_5(my_list_2);
    std::cout << (my_queue >= my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_6(my_list);
    std::cout << (my_queue_6 >= my_queue_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Queue<int> my_queue_7(my_list);
    std::cout << (my_queue_7 >= my_queue_5) << std::endl;
}

int main()
{
    std::cout << "________________________________________________" << std::endl;
    std::cout << "|                                              |" << std::endl;
    std::cout << "|     Constructor (Default) | Size | Empty     |" << std::endl;
    std::cout << "|______________________________________________|" << std::endl << std::endl;
    constr_default();
    std::cout << std::endl;

    std::cout << "________________________" << std::endl;
    std::cout << "|                      |" << std::endl;
    std::cout << "|     Front | Back     |" << std::endl;
    std::cout << "|______________________|" << std::endl << std::endl;
    front_back();
    std::cout << std::endl;

    std::cout << "______________________" << std::endl;
    std::cout << "|                    |" << std::endl;
    std::cout << "|     Push | Pop     |" << std::endl;
    std::cout << "|____________________|" << std::endl << std::endl;
    push_pop();
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
    less_or_equal();
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

    // sleep(10000);
    return (0);
}