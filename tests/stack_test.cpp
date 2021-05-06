/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:33:20 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/06 14:49:29 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/Stack.hpp"
#include <stack>
#include <list>
#include <unistd.h>

# define COL_STANDART "\033[1;34m" //blue
# define COL_MY "\033[0;35m" //purple
# define COL_END "\033[0m"

template <class Cont>
void    print_container(Cont &stack)
{
    typename Cont::iterator begin;
    for (begin = stack.begin(); begin != stack.end(); begin++)
        std::cout << *begin << " ";
    std::cout << std::endl;
}

void    constr_default()
{
    std::cout << COL_STANDART << "Standart not empty list" << COL_END << std::endl;
    std::list<int> st_list(3, 7);
    std::cout << COL_STANDART << "Size: " << COL_END << st_list.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_list.empty() << std::endl;
    std::cout << COL_STANDART << "Standart stack (list)" << COL_END << std::endl;
    std::stack<int, std::list<int> > st_stack(st_list);
    std::cout << COL_STANDART << "Size: " << COL_END << st_stack.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_stack.empty() << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My not empty list" << COL_END << std::endl;
    ft::List<int> my_list(3, 7);
    std::cout << COL_MY << "Size: " << COL_END << my_list.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_list.empty() << std::endl;
    std::cout << COL_MY << "My stack (list)" << COL_END << std::endl;
    ft::Stack<int> my_stack(my_list);
    std::cout << COL_MY << "Size: " << COL_END << my_stack.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_stack.empty() << std::endl;
    std::cout << std::endl;

    std::cout << COL_STANDART << "Standart empty list" << COL_END << std::endl;
    std::list<int> st_list_2;
    std::cout << COL_STANDART << "Size: " << COL_END << st_list_2.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_list_2.empty() << std::endl;
    std::cout << COL_STANDART << "Standart stack (list)" << COL_END << std::endl;
    std::stack<int, std::list<int> > st_stack_2(st_list_2);
    std::cout << COL_STANDART << "Size: " << COL_END << st_stack_2.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_stack_2.empty() << std::endl;
    std::cout << std::endl;
    
    std::cout << COL_MY << "My empty list" << COL_END << std::endl;
    ft::List<int> my_list_2;
    std::cout << COL_MY << "Size: " << COL_END << my_list_2.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_list_2.empty() << std::endl;
    std::cout << COL_MY << "My stack (list)" << COL_END << std::endl;
    ft::Stack<int> my_stack_2(my_list_2);
    std::cout << COL_MY << "Size: " << COL_END << my_stack_2.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_stack_2.empty() << std::endl;
}

void    top()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::list<std::string> st_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::list<std::string> >(st_list);
    std::cout << COL_STANDART << "St list" << COL_END << std::endl;
    std::cout << COL_STANDART << "Top: " << COL_END << st_list.back() << std::endl;
    std::cout << COL_STANDART << "St stack: " << COL_END << std::endl;
    std::stack<std::string, std::list<std::string> > st_stack(st_list);
    std::cout << COL_STANDART << "Top: " << COL_END << st_stack.top() << std::endl;
    std::cout << std::endl;

    print_container<std::list<std::string> >(st_list);
    std::cout << COL_MY << "My list: " << COL_END << std::endl;
    ft::List<std::string> my_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    std::cout << COL_MY << "Top: " << COL_END << my_list.back() << std::endl;
    std::cout << COL_MY << "My stack: " << COL_END << std::endl;
    ft::Stack<std::string> my_stack(my_list);
    std::cout << COL_MY << "Top: " << COL_END << my_stack.top() << std::endl;
}

void    push_pop()
{
    std::string mystr[] = { "Hello", "I'm", "glad", "to", "see", "you" };

    std::list<std::string> st_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<std::list<std::string> >(st_list);
    std::cout << COL_STANDART << "St list" << COL_END << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_list.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_list.empty() << std::endl << std::endl;
    std::cout << COL_STANDART << "St stack: " << COL_END << std::endl;
    std::stack<std::string, std::list<std::string> > st_stack(st_list);
    std::cout << COL_STANDART << "Top: " << COL_END << st_stack.top() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_stack.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_stack.empty() << std::endl;
    st_stack.push("Monday");
    std::cout << COL_STANDART << "St stack after push \"Monday\"" << COL_END << std::endl;
    std::cout << COL_STANDART << "Top: " << COL_END << st_stack.top() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_stack.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_stack.empty() << std::endl;
    st_stack.push("Friday");
    std::cout << COL_STANDART << "St stack after push \"Friday\"" << COL_END << std::endl;
    std::cout << COL_STANDART << "Top: " << COL_END << st_stack.top() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_stack.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_stack.empty() << std::endl;
    st_stack.pop();
    std::cout << COL_STANDART << "St stack after pop" << COL_END << std::endl;
    std::cout << COL_STANDART << "Top: " << COL_END << st_stack.top() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_stack.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_stack.empty() << std::endl;
    st_stack.pop();
    std::cout << COL_STANDART << "St stack after pop" << COL_END << std::endl;
    std::cout << COL_STANDART << "Top: " << COL_END << st_stack.top() << std::endl;
    std::cout << COL_STANDART << "Size: " << COL_END << st_stack.size() << std::endl;
    std::cout << COL_STANDART << "Empty: " << COL_END << st_stack.empty() << std::endl;
    std::cout << std::endl;
    
    ft::List<std::string> my_list(mystr, mystr + sizeof(mystr) / sizeof(std::string));
    print_container<ft::List<std::string> >(my_list);
    std::cout << COL_MY << "St list" << COL_END << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_list.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_list.empty() << std::endl << std::endl;
    std::cout << COL_MY << "St stack: " << COL_END << std::endl;
    ft::Stack<std::string> my_stack(my_list);
    std::cout << COL_MY << "Top: " << COL_END << my_stack.top() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_stack.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_stack.empty() << std::endl;
    my_stack.push("Monday");
    std::cout << COL_MY << "St stack after push \"Monday\"" << COL_END << std::endl;
    std::cout << COL_MY << "Top: " << COL_END << my_stack.top() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_stack.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_stack.empty() << std::endl;
    my_stack.push("Friday");
    std::cout << COL_MY << "St stack after push \"Friday\"" << COL_END << std::endl;
    std::cout << COL_MY << "Top: " << COL_END << my_stack.top() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_stack.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_stack.empty() << std::endl;
    my_stack.pop();
    std::cout << COL_MY << "St stack after pop" << COL_END << std::endl;
    std::cout << COL_MY << "Top: " << COL_END << my_stack.top() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_stack.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_stack.empty() << std::endl;
    my_stack.pop();
    std::cout << COL_MY << "St stack after pop" << COL_END << std::endl;
    std::cout << COL_MY << "Top: " << COL_END << my_stack.top() << std::endl;
    std::cout << COL_MY << "Size: " << COL_END << my_stack.size() << std::endl;
    std::cout << COL_MY << "Empty: " << COL_END << my_stack.empty() << std::endl;
}

void    equal()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_STANDART << "St not equivalent: " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::stack<int, std::list<int> > st_stack(st_list);
    std::list<int> st_list_2(myints, myints + 2);
    std::stack<int, std::list<int> > st_stack_2(st_list_2);
    std::cout << (st_stack == st_stack_2) << std::endl;
    std::cout << COL_STANDART << "St equivalent: " << COL_END;
    st_list.pop_back();
    st_list.pop_back();
    std::stack<int, std::list<int> > st_stack_3(st_list);
    std::cout << (st_stack_3 == st_stack_2) << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My not equivalent: " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Stack<int> my_stack(my_list);
    ft::List<int> my_list_2(myints, myints + 2);
    ft::Stack<int> my_stack_2(my_list_2);
    std::cout << (my_stack == my_stack_2) << std::endl;
    std::cout << COL_MY << "My equivalent: " << COL_END;
    my_list.pop_back();
    my_list.pop_back();
    ft::Stack<int> my_stack_3(my_list);
    std::cout << (my_stack_3 == my_stack_2) << std::endl;
}

void    not_equal()
{
    int myints[] = { 16, 2, 77, 29 };

    std::cout << COL_STANDART << "St not equivalent: " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::stack<int, std::list<int> > st_stack(st_list);
    std::list<int> st_list_2(myints, myints + 2);
    std::stack<int, std::list<int> > st_stack_2(st_list_2);
    std::cout << (st_stack != st_stack_2) << std::endl;
    std::cout << COL_STANDART << "St equivalent: " << COL_END;
    st_list.pop_back();
    st_list.pop_back();
    std::stack<int, std::list<int> > st_stack_3(st_list);
    std::cout << (st_stack_3 != st_stack_2) << std::endl;
    std::cout << std::endl;

    std::cout << COL_MY << "My not equivalent: " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Stack<int> my_stack(my_list);
    ft::List<int> my_list_2(myints, myints + 2);
    ft::Stack<int> my_stack_2(my_list_2);
    std::cout << (my_stack != my_stack_2) << std::endl;
    std::cout << COL_MY << "My equivalent: " << COL_END;
    my_list.pop_back();
    my_list.pop_back();
    ft::Stack<int> my_stack_3(my_list);
    std::cout << (my_stack_3 != my_stack_2) << std::endl;
}

void    less()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::stack<int, std::list<int> > st_stack(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::stack<int, std::list<int> > st_stack_2(st_list_2);
    std::cout << (st_stack < st_stack_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::stack<int, std::list<int> > st_stack_3(st_list_2);
    std::cout << (st_stack < st_stack_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::stack<int, std::list<int> > st_stack_4(st_list_2);
    std::cout << (st_stack < st_stack_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::stack<int, std::list<int> > st_stack_5(st_list_2);
    std::cout << (st_stack < st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_6(st_list);
    std::cout << (st_stack_6 < st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_7(st_list);
    std::cout << (st_stack_7 < st_stack_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Stack<int> my_stack(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Stack<int> my_stack_2(my_list_2);
    std::cout << (my_stack < my_stack_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Stack<int> my_stack_3(my_list_2);
    std::cout << (my_stack < my_stack_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Stack<int> my_stack_4(my_list_2);
    std::cout << (my_stack < my_stack_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Stack<int> my_stack_5(my_list_2);
    std::cout << (my_stack < my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_6(my_list);
    std::cout << (my_stack_6 < my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_7(my_list);
    std::cout << (my_stack_7 < my_stack_5) << std::endl;
}

void    less_or_equal()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::stack<int, std::list<int> > st_stack(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::stack<int, std::list<int> > st_stack_2(st_list_2);
    std::cout << (st_stack <= st_stack_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::stack<int, std::list<int> > st_stack_3(st_list_2);
    std::cout << (st_stack <= st_stack_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::stack<int, std::list<int> > st_stack_4(st_list_2);
    std::cout << (st_stack <= st_stack_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::stack<int, std::list<int> > st_stack_5(st_list_2);
    std::cout << (st_stack <= st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_6(st_list);
    std::cout << (st_stack_6 <= st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_7(st_list);
    std::cout << (st_stack_7 <= st_stack_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Stack<int> my_stack(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Stack<int> my_stack_2(my_list_2);
    std::cout << (my_stack <= my_stack_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Stack<int> my_stack_3(my_list_2);
    std::cout << (my_stack <= my_stack_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Stack<int> my_stack_4(my_list_2);
    std::cout << (my_stack <= my_stack_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Stack<int> my_stack_5(my_list_2);
    std::cout << (my_stack <= my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_6(my_list);
    std::cout << (my_stack_6 <= my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_7(my_list);
    std::cout << (my_stack_7 <= my_stack_5) << std::endl;
}

void    greater()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::stack<int, std::list<int> > st_stack(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::stack<int, std::list<int> > st_stack_2(st_list_2);
    std::cout << (st_stack > st_stack_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::stack<int, std::list<int> > st_stack_3(st_list_2);
    std::cout << (st_stack > st_stack_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::stack<int, std::list<int> > st_stack_4(st_list_2);
    std::cout << (st_stack > st_stack_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::stack<int, std::list<int> > st_stack_5(st_list_2);
    std::cout << (st_stack > st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_6(st_list);
    std::cout << (st_stack_6 > st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_7(st_list);
    std::cout << (st_stack_7 > st_stack_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Stack<int> my_stack(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Stack<int> my_stack_2(my_list_2);
    std::cout << (my_stack > my_stack_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Stack<int> my_stack_3(my_list_2);
    std::cout << (my_stack > my_stack_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Stack<int> my_stack_4(my_list_2);
    std::cout << (my_stack > my_stack_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Stack<int> my_stack_5(my_list_2);
    std::cout << (my_stack > my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_6(my_list);
    std::cout << (my_stack_6 > my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_7(my_list);
    std::cout << (my_stack_7 > my_stack_5) << std::endl;
}

void    greater_or_equal()
{
    int myints[] = { 16, 2, 77, 29, 34 };

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    std::list<int> st_list(myints, myints + sizeof(myints) / sizeof(int));
    std::stack<int, std::list<int> > st_stack(st_list);
    std::list<int> st_list_2(myints, myints + 3);
    std::stack<int, std::list<int> > st_stack_2(st_list_2);
    std::cout << (st_stack >= st_stack_2) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    st_list_2.push_back(29);
    st_list_2.push_back(34);
    st_list_2.push_back(0);
    std::stack<int, std::list<int> > st_stack_3(st_list_2);
    std::cout << (st_stack >= st_stack_3) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.insert(st_list_2.end(), myints + 1, myints + 5);
    std::stack<int, std::list<int> > st_stack_4(st_list_2);
    std::cout << (st_stack >= st_stack_4) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    st_list_2.assign(1, 20);
    st_list_2.push_back(1);
    st_list_2.push_back(1);
    std::stack<int, std::list<int> > st_stack_5(st_list_2);
    std::cout << (st_stack >= st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    st_list.assign(1, 21);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_6(st_list);
    std::cout << (st_stack_6 >= st_stack_5) << std::endl;

    std::cout << COL_STANDART << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    st_list.push_back(1);
    std::stack<int, std::list<int> > st_stack_7(st_list);
    std::cout << (st_stack_7 >= st_stack_5) << std::endl;
    std::cout << std::endl;


    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (numbers are equivalent): " << COL_END;
    ft::List<int> my_list(myints, myints + sizeof(myints) / sizeof(int));
    ft::Stack<int> my_stack(my_list);
    ft::List<int> my_list_2(myints, myints + 3);
    ft::Stack<int> my_stack_2(my_list_2);
    std::cout << (my_stack >= my_stack_2) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (numbers are equivalent): " << COL_END;
    my_list_2.push_back(29);
    my_list_2.push_back(34);
    my_list_2.push_back(0);
    ft::Stack<int> my_stack_3(my_list_2);
    std::cout << (my_stack >= my_stack_3) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 6 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.insert(my_list_2.end(), myints + 1, myints + 5);
    ft::Stack<int> my_stack_4(my_list_2);
    std::cout << (my_stack >= my_stack_4) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 2 is greater): " << COL_END;
    my_list_2.assign(1, 20);
    my_list_2.push_back(1);
    my_list_2.push_back(1);
    ft::Stack<int> my_stack_5(my_list_2);
    std::cout << (my_stack >= my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 3 elem (first elem in list 1 is greater): " << COL_END;
    my_list.assign(1, 21);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_6(my_list);
    std::cout << (my_stack_6 >= my_stack_5) << std::endl;

    std::cout << COL_MY << "St 1 - 5 elem, 2 - 7 elem (first elem in list 1 is greater): " << COL_END;
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    my_list.push_back(1);
    ft::Stack<int> my_stack_7(my_list);
    std::cout << (my_stack_7 >= my_stack_5) << std::endl;
}

int main()
{
    std::cout << "________________________________________________" << std::endl;
    std::cout << "|                                              |" << std::endl;
    std::cout << "|     Constructor (Default) | Size | Empty     |" << std::endl;
    std::cout << "|______________________________________________|" << std::endl << std::endl;
    constr_default();
    std::cout << std::endl;

    std::cout << "_______________" << std::endl;
    std::cout << "|             |" << std::endl;
    std::cout << "|     Top     |" << std::endl;
    std::cout << "|_____________|" << std::endl << std::endl;
    top();
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