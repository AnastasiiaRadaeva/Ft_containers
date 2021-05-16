/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:14:01 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/16 17:24:40 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <cstddef>
# include <memory>
# include <new>
# include <limits>
# include <utility>
# include "Map_iterator.hpp"

# define RIGHT 2
# define LEFT 3

namespace ft
{
    /*********************/
    /*                   */
    /*     Class Map     */
    /*                   */
    /*********************/
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class Map
    {
        public:
            /************************/
            /*     Member types     */
            /************************/
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef std::pair<const key_type, mapped_type>                      value_type;
            typedef Compare                                                     key_compare;
            //value_compare`
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef typename map::iterator<key_type, mapped_type>               iterator;
            typedef typename map::const_iterator<key_type, mapped_type>         const_iterator;
            typedef typename map::reverse_iterator<key_type, mapped_type>       reverse_iterator;
            typedef typename map::const_reverse_iterator<key_type, mapped_type> const_reverse_iterator;
            //difference_type
            typedef size_t                                                      size_type;
            
            /****************************/
            /*     Member functions     */
            /****************************/

            /***************************************************************************/
            /*** constructors ------------------------------------------------------ ***/
            explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(0), _current_size(0), _alloc(alloc), _key_comp(comp)
            {
                _head = create_node();
                _head->parent = create_node();

                _tail = _head->parent;
                _tail->parent = _head;
            }

            template <class InputIterator>
            Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
                typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) : _root(0), _current_size(0), _alloc(alloc), _key_comp(comp)
            {
                _head = create_node();
                _head->parent = create_node();
                _tail = _head->parent;
                _tail->parent = _head;

                while (first != last)
                    add_new_node(*(first++));
            }

            Map (const Map &x) : _root(0), _current_size(0), _alloc(x._alloc), _key_comp(x._key_comp)
            {
                _head = create_node();
                _head->parent = create_node();
                _tail = _head->parent;
                _tail->parent = _head;

                for (const_iterator it = x.begin(); it != x.end(); it++)
                    add_new_node(*it);
            }

        //     /***************************************************************************/
        //     /*** operator= --------------------------------------------------------- ***/
        //     List &operator=(List const &b)
        //     {
        //         if (this != &b)
        //         {
        //             clear();
        //             node<value_type> *tmp_list_1 = _tail_of_node_list;
        //             node<value_type> *tmp_b_list = b._tail_of_node_list->next;
        //             while (tmp_b_list != b._tail_of_node_list)
        //             {
        //                 tmp_list_1->next = create_node(tmp_b_list->content);
        //                 tmp_list_1->next->prev = tmp_list_1;
        //                 tmp_list_1 = tmp_list_1->next;
        //                 tmp_b_list = tmp_b_list->next;
        //             }
        //             tmp_list_1->next = _tail_of_node_list;
        //             _tail_of_node_list->prev = tmp_list_1;
        //             _current_size = b._current_size;
        //         }
        //         return (*this);
        //     }
            
            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            // ~Map()
            // {
            //     // clear();
            //     delete_node(_head);
            //     delete_node(_tail);
            // }

            /***************************************************************************/
            /*** iterators --------------------------------------------------------- ***/
            iterator                begin() { return (iterator(_head->parent));}
            const_iterator          begin() const { return (const_iterator(_head->parent));}
            iterator                end() { return (iterator(_tail));}
            const_iterator          end() const { return (const_iterator(_tail));}
            reverse_iterator        rbegin() { return (reverse_iterator(_tail->parent));}
            const_reverse_iterator  rbegin() const { return (const_reverse_iterator(_tail->parent));}
            reverse_iterator        rend() { return (reverse_iterator(_head));}
            const_reverse_iterator  rend() const { return (const_reverse_iterator(_head));}

            /***************************************************************************/
            /*** Capacity ---------------------------------------------------------- ***/
            bool        empty() const {return (_current_size == 0 ? true : false);}
            size_type   size() const {return (_current_size);}
            size_type   max_size() const {node_alloc node; return(node.max_size());}

            /***************************************************************************/
            /*** Element access ---------------------------------------------------- ***/
            mapped_type &operator[](const key_type& k)
            {
                return ((*(insert(std::make_pair(k, mapped_type()))).first).second);
            }

            /***************************************************************************/
            /*** Modifiers --------------------------------------------------------- ***/
            std::pair<iterator, bool>   insert(const value_type& val)
            {
                map_node<key_type, mapped_type> *new_node;
                if ((new_node = find_node(val.first, _root)) != 0)
                {
                    iterator it(new_node);
                    return (std::make_pair(it, false));
                }
                new_node = add_new_node(val);
                iterator it(new_node);
                return (std::make_pair(it, true));
            }
            iterator                    insert(iterator position, const value_type& val)
            {
                map_node<key_type, mapped_type> *new_node;
                if ((new_node = find_node(val.first, position.get_node())) != 0)
                {
                    iterator it(new_node);
                    return (it);
                }
                iterator it(add_new_node(val));
                return (it);
            }
            template <class InputIterator>
            void                        insert(InputIterator first, InputIterator last, typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
            {
                map_node<key_type, mapped_type> *new_node;
                for (; first != last; first++)
                {
                    if ((new_node = find_node((*first).first, _root)) != 0)
                        continue;
                    new_node = add_new_node(*first);
                }
            }

            // void erase (iterator position)
            // {
            //     map_node<key_type, mapped_type> *node_for_del = position.get_node();
            //     size_type original_color = node_for_del->color;
            //     if (node_for_del->left == 0 || node_for_del->left == _head)
            //     {
                    

            //     }

            // }
            // size_type erase (const key_type& k);
            // void erase (iterator first, iterator last);
        //     iterator erase (iterator position)
        //     {
        //         if (position.get_node() != _tail_of_node_list)
        //         {
        //             node<value_type> *to_del = position.get_node();
        //             node<value_type> *prev_lst = to_del->prev;
        //             prev_lst->next = to_del->next;
        //             to_del->next->prev = prev_lst;
        //             delete_node(to_del);
        //             _current_size--;
        //             return (prev_lst->next);
        //         }
        //         return (0);
        //     }
        //     iterator erase (iterator first, iterator last)
        //     {
        //         node<value_type> *to_del = first.get_node();
        //         node<value_type> *prev_lst = to_del->prev;
        //         node<value_type> *pos;
        //         while (first != last && to_del != _tail_of_node_list)
        //         {
        //             prev_lst->next = to_del->next;
        //             to_del->next->prev = prev_lst;
        //             delete_node(to_del);
        //             pos = prev_lst->next;
        //             _current_size--;
        //             first++;
        //             to_del = first.get_node();
        //             prev_lst = to_del->prev;
        //         }
        //         return (pos);
        //     }
            void                            swap(Map& x)
            {
                map_node<key_type, mapped_type>  *tmp;
                tmp = _root;
                _root = x._root;
                x._root = tmp;

                tmp = _tail;
                _tail = x._tail;
                x._tail = tmp;

                tmp = _head;
                _head = x._head;
                x._head = tmp;

                size_type   tmp_size;
                tmp_size = _current_size;
                _current_size = x._current_size;
                x._current_size = tmp_size;

                //_key_comp
                //_map_comp
            }
            // void clear()
            // {
            //     map_node<key_type, mapped_type> tmp;
            //     for (iterator it_b = begin(); it_b != end(); it_b++)
            //         erase(it_b);
            // }

            /***************************************************************************/
            /*** Operations -------------------------------------------------------- ***/
            iterator        find(const key_type& k)
            {
                map_node<key_type, mapped_type> *tmp;
                if ((tmp = find_node(k, _root)) == 0)
                    return (this->end());
                iterator it(tmp);
                return (it);
            }
            const_iterator  find(const key_type& k) const
            {
                map_node<key_type, mapped_type> *tmp;
                if ((tmp = find_node(k, _root)) == 0)
                    return (this->end());
                const_iterator it(tmp);
                return (it);
            }
            size_type       count(const key_type& k) const
            {
                map_node<key_type, mapped_type> *tmp = find_node(k, _root);
                return (tmp == 0 ? 0 : 1);
            }

        //     void splice (iterator position, List& x)
        //     {
        //         node<value_type> *next_lst = position.get_node();
        //         node<value_type> *prev_lst = next_lst->prev;
        //         prev_lst->next = x._tail_of_node_list->next;
        //         x._tail_of_node_list->next->prev = prev_lst;
        //         next_lst->prev = x._tail_of_node_list->prev;
        //         x._tail_of_node_list->prev->next = next_lst;
        //         _current_size += x._current_size;

        //         x._tail_of_node_list->next = x._tail_of_node_list;
        //         x._tail_of_node_list->prev = x._tail_of_node_list;
        //         x._current_size = 0;
        //     }	
        //     void splice (iterator position, List& x, iterator i)
        //     {
        //         node<value_type> *next_lst = position.get_node();
        //         node<value_type> *prev_lst = next_lst->prev;
        //         node<value_type> *new_lst = i.get_node();
        //         new_lst->prev->next = new_lst->next;
        //         new_lst->next->prev = new_lst->prev;
        //         prev_lst->next = new_lst;
        //         new_lst->prev = prev_lst;
        //         next_lst->prev = new_lst;
        //         new_lst->next = next_lst;
        //         _current_size++;
        //         x._current_size--;
        //     }
        //     void splice (iterator position, List& x, iterator first, iterator last)
        //     {
        //         node<value_type> *next_lst = position.get_node();
        //         node<value_type> *prev_lst = next_lst->prev;
        //         node<value_type> *new_lst = first.get_node();
        //         while (first++ != last)
        //         {
        //             new_lst->prev->next = new_lst->next;
        //             new_lst->next->prev = new_lst->prev;
        //             prev_lst->next = new_lst;
        //             new_lst->prev = prev_lst;
        //             next_lst->prev = new_lst;
        //             new_lst->next = next_lst;
        //             _current_size++;
        //             x._current_size--;
        //             prev_lst = prev_lst->next;
        //             new_lst = first.get_node();
        //         }
        //     }
        //     void remove (const value_type& val)
        //     {
        //         node<value_type> *tmp = _tail_of_node_list->next;
        //         node<value_type> *node_after_del;
        //         while (tmp != _tail_of_node_list)
        //         {
        //             if (tmp->content == val)
        //             {
        //                 tmp = tmp->prev;
        //                 node_after_del = tmp->next->next;
        //                 delete_node(tmp->next);
        //                 tmp->next = node_after_del;
        //                 node_after_del->prev = tmp;
        //                 _current_size--;
        //             }
        //             tmp = tmp->next;
        //         }
        //     }
        //     template <class Predicate>
        //     void remove_if (Predicate pred)
        //     {
        //         node<value_type> *tmp = _tail_of_node_list->next;
        //         node<value_type> *node_after_del;
        //         while (tmp != _tail_of_node_list)
        //         {
        //             if (pred(tmp->content))
        //             {
        //                 tmp = tmp->prev;
        //                 node_after_del = tmp->next->next;
        //                 delete_node(tmp->next);
        //                 tmp->next = node_after_del;
        //                 node_after_del->prev = tmp;
        //                 _current_size--;
        //             }
        //             tmp = tmp->next;
        //         }
        //     }
        //     void unique()
        //     {
        //         node<value_type> *tmp = _tail_of_node_list->next->next;
        //         node<value_type> *node_after_del;
        //         while (tmp != _tail_of_node_list)
        //         {
        //             if (tmp->content == tmp->prev->content)
        //             {
        //                 tmp = tmp->prev;
        //                 node_after_del = tmp->next->next;
        //                 delete_node(tmp->next);
        //                 tmp->next = node_after_del;
        //                 node_after_del->prev = tmp;
        //                 _current_size--;
        //             }
        //             tmp = tmp->next;
        //         }
        //     }
        //     template <class BinaryPredicate>
        //     void unique (BinaryPredicate binary_pred)
        //     {
        //         node<value_type> *tmp = _tail_of_node_list->next->next;
        //         node<value_type> *node_after_del;
        //         while (tmp != _tail_of_node_list)
        //         {
        //             if (binary_pred(tmp->prev->content, tmp->content))
        //             {
        //                 tmp = tmp->prev;
        //                 node_after_del = tmp->next->next;
        //                 delete_node(tmp->next);
        //                 tmp->next = node_after_del;
        //                 node_after_del->prev = tmp;
        //                 _current_size--;
        //             }
        //             tmp = tmp->next;
        //         }
        //     }
        //     void merge (List& x)
        //     {
        //         if (this != &x)
        //         {
        //             iterator pos_in_my_list, pos_in_x;
        //             pos_in_my_list = begin();
        //             pos_in_x = x.begin();
        //             while (pos_in_my_list != end())
        //             {
        //                 while (pos_in_x != x.end() && *pos_in_x < *pos_in_my_list)
        //                 {
        //                     splice(pos_in_my_list, x, pos_in_x);
        //                     pos_in_x = x.begin();
        //                 }
        //                 pos_in_my_list++;
        //             }
        //             if (pos_in_x != x.end())
        //                 splice (pos_in_my_list, x, pos_in_x, x.end());
        //         }
        //     }
        //     template <class Compare>
        //     void merge (List& x, Compare comp)
        //     {
        //         if (this != &x)
        //         {
        //             iterator pos_in_my_list, pos_in_x;
        //             pos_in_my_list = begin();
        //             pos_in_x = x.begin();
        //             while (pos_in_my_list != end())
        //             {
        //                 while (pos_in_x != x.end() && comp(*pos_in_x, *pos_in_my_list))
        //                 {
        //                     splice(pos_in_my_list, x, pos_in_x);
        //                     pos_in_x = x.begin();
        //                 }
        //                 pos_in_my_list++;
        //             }
        //             if (pos_in_x != x.end())
        //                 splice (pos_in_my_list, x, pos_in_x, x.end());
        //         }
        //     }
        //     void sort()
        //     {
        //         node<value_type> *tmp_first;
        //         node<value_type> *tmp_second;
        //         node<value_type> *tmp_help;
        //         for (size_type i = 0; i < (_current_size - 1); i++)
        //         {
        //             tmp_first = _tail_of_node_list->next;
        //             tmp_second = _tail_of_node_list->next->next;
        //             for (size_type j = 0; j < (_current_size - 1) - i; j++)
        //             {
        //                 if (tmp_first->content > tmp_second->content)
        //                 {
        //                     tmp_help = tmp_first->prev;
        //                     tmp_help->next = tmp_second;

        //                     tmp_first->prev = tmp_second;
        //                     tmp_first->next = tmp_second->next;
                            
        //                     tmp_second->next = tmp_first;
        //                     tmp_second->prev = tmp_help;

        //                     tmp_first = tmp_first->prev;
        //                     tmp_second = tmp_first->next;

        //                     tmp_second->next->prev = tmp_second;
        //                 }
        //                 tmp_first = tmp_first->next;
        //                 tmp_second = tmp_second->next;
        //             }
        //         }
        //     }
        //     template <class Compare>
        //     void sort (Compare comp)
        //     {
        //         node<value_type> *tmp_first;
        //         node<value_type> *tmp_second;
        //         node<value_type> *tmp_help;
        //         for (size_type i = 0; i < (_current_size - 1); i++)
        //         {
        //             tmp_first = _tail_of_node_list->next;
        //             tmp_second = _tail_of_node_list->next->next;
        //             for (size_type j = 0; j < (_current_size - 1) - i; j++)
        //             {
        //                 if (comp(tmp_second->content, tmp_first->content))
        //                 {
        //                     tmp_help = tmp_first->prev;
        //                     tmp_help->next = tmp_second;

        //                     tmp_first->prev = tmp_second;
        //                     tmp_first->next = tmp_second->next;
                            
        //                     tmp_second->next = tmp_first;
        //                     tmp_second->prev = tmp_help;

        //                     tmp_first = tmp_first->prev;
        //                     tmp_second = tmp_first->next;

        //                     tmp_second->next->prev = tmp_second;
        //                 }
        //                 tmp_first = tmp_first->next;
        //                 tmp_second = tmp_second->next;
        //             }
        //         }      
        //     }
        //     void reverse()
        //     {
        //         if (!_tail_of_node_list)
        //             return;
        //         node<value_type> *tmp = _tail_of_node_list;
        //         node<value_type> *tmp_buff = _tail_of_node_list->next;
        //         while (tmp_buff != _tail_of_node_list)
        //         {
        //             tmp_buff = tmp->next;
        //             tmp->next = tmp->prev;
        //             tmp->prev = tmp_buff;
        //             tmp = tmp_buff;
        //         }
        //     }

        //     /***************************************************************************/
        //     /*** Allocator --------------------------------------------------------- ***/
        //     allocator_type get_allocator() const { return (_alloc); }

            private:
                
                /*********************************/
                /*     Member types | private    */
                /*********************************/
                typedef typename allocator_type::template rebind<map_node<key_type, mapped_type> >::other   node_alloc; //equivalent allocator fot type node
                typedef typename node_alloc::pointer                                                        node_pointer;
                typedef typename node_alloc::const_reference                                                node_const_reference;
                
                /****************************/
                /*     Members | private    */
                /****************************/
                map_node<key_type, mapped_type> *_tail;
                map_node<key_type, mapped_type> *_head;
                map_node<key_type, mapped_type> *_root;
                size_type                       _current_size;
                node_alloc                      _alloc_for_node;
                allocator_type                  _alloc;
                key_compare                     _key_comp;

                /*************************************/
                /*     Member functions | private    */
                /*************************************/
                map_node<key_type, mapped_type> *create_node(value_type content = value_type())
                {
                    try
                    {
                        node_pointer l_pointer = _alloc_for_node.allocate(1);
                        map_node<key_type, mapped_type> new_node;
                        // new_node.content = std::make_pair(key_value, map_value);
                        new_node.content = content;
                        new_node.color = BLACK;
                        new_node.left = 0;
                        new_node.right = 0;
                        new_node.parent = 0;
                        node_const_reference ref_node = new_node;
                        _alloc_for_node.construct(l_pointer, ref_node);
                        return (l_pointer);
                    }
                    catch(const std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    }
                    return (0);
                }

                void                            delete_node(map_node<key_type, mapped_type> *node_for_del)
                {
                    node_pointer l_pointer = _alloc_for_node.address(*node_for_del);
                    _alloc_for_node.destroy(l_pointer);
                    _alloc_for_node.deallocate(l_pointer, 1);
                }

                map_node<key_type, mapped_type> *add_new_node(value_type content)
                {
                    map_node<key_type, mapped_type> *current_node = _root, *parent_node = 0;
                    size_type   branch = 0;
                    while (current_node != 0 && current_node != _tail && current_node != _head) //ищем нужно место для вставки
                    {
                        parent_node = current_node;
                        if (content.first > current_node->content.first)
                            {current_node = current_node->right; branch = RIGHT;}
                        else
                            {current_node = current_node->left;  branch = LEFT;}
                    }
                    current_node = create_node(content);
                    _current_size++;
                    if (_root == 0) // если корня нет, то создаем и помещяем между головой и хвостом
                    {
                        _root = current_node;
                        _root->left = _head;
                        _root->right = _tail;
                        _head->parent = _root;
                        _tail->parent = _root;
                        return (current_node);
                    }
                    if (branch == RIGHT) // в правую ветку
                    {
                        if (parent_node->right == _tail)
                        {
                            _tail->parent = current_node;
                            current_node->right = _tail;
                        }
                        parent_node->right = current_node;
                        current_node->parent = parent_node;
                    }
                    else if (branch == LEFT) // в левую ветку
                    {
                        if (parent_node->left == _head)
                        {
                            _head->parent = current_node;
                            current_node->left = _head;
                        }
                        parent_node->left = current_node;
                        current_node->parent = parent_node;
                    }
                    current_node->color = RED;
                    if (current_node->parent != _root)
                        balancing_after_insertion(current_node); //делаем так, тк балансировка нужна только для уровней глубже, чем ребенок корня
                    return (current_node);
                }

                void                            left_rotate(map_node<key_type, mapped_type> *current_node)
                {
                    map_node<key_type, mapped_type> *tmp_node = current_node->right;
                    current_node->right = tmp_node->left;
                    //head остался 
                    if (tmp_node->left != 0)
                        tmp_node->left->parent = current_node;
                    tmp_node->parent = current_node->parent;
                    if (current_node->parent == 0)
                        _root = tmp_node;
                    else
                    {
                        if (current_node == current_node->parent->left)
                            current_node->parent->left = tmp_node;
                        else
                            current_node->parent->right = tmp_node;
                    }
                    tmp_node->left = current_node;
                    current_node->parent = tmp_node;
                }
                void                            right_rotate(map_node<key_type, mapped_type> *current_node)
                {
                    map_node<key_type, mapped_type> *tmp_node = current_node->left;
                    current_node->left = tmp_node->right;
                    if (tmp_node->right != 0)
                        tmp_node->right->parent = current_node;
                    tmp_node->parent = current_node->parent;
                    if (current_node->parent == 0)
                        _root = tmp_node;
                    else
                    {
                        if (current_node == current_node->parent->right)
                            current_node->parent->right = tmp_node;
                        else
                            current_node->parent->left = tmp_node;
                    }
                    tmp_node->right = current_node;
                    current_node->parent = tmp_node;
                }
                void                            balancing_after_insertion(map_node<key_type, mapped_type> *new_node)
                {
                    map_node<key_type, mapped_type> *tmp;
                    while (new_node->parent->color == RED)
                    {
                        if (new_node->parent == new_node->parent->parent->left)
                        {
                            tmp = new_node->parent->parent->right;
                            if (tmp && tmp->color == RED)
                            {
                                new_node->parent->parent->color = RED;
                                tmp->color = BLACK;
                                new_node->parent->color = BLACK;
                                new_node = new_node->parent->parent;
                            }
                            else
                            {
                                if (new_node == new_node->parent->right)
                                {
                                    new_node = new_node->parent;
                                    left_rotate(new_node);
                                }
                                new_node->parent->color = BLACK;
                                new_node->parent->parent->color = RED;
                                right_rotate(new_node->parent->parent);
                            }
                        }
                        else
                        {
                            tmp = new_node->parent->parent->left;
                            if (tmp && tmp->color == RED)
                            {
                                new_node->parent->parent->color = RED;
                                tmp->color = BLACK;
                                new_node->parent->color = BLACK;
                                new_node = new_node->parent->parent;
                            }
                            else
                            {
                                if (new_node == new_node->parent->left)
                                {
                                    new_node = new_node->parent;
                                    right_rotate(new_node);
                                }
                                new_node->parent->color = BLACK;
                                new_node->parent->parent->color = RED;
                                left_rotate(new_node->parent->parent);
                            }
                        }
                        if (new_node == _root)
                            break;
                    }
                    _root->color = BLACK;
                }
                map_node<key_type, mapped_type> *find_node(const key_type &key, map_node<key_type, mapped_type> *current_node) const
                {
                    if (current_node != _root)
                        while (current_node)
                        {
                            if (current_node->content.first == key)
                                return(current_node);
                            else if (current_node->content.first < key)
                                current_node = current_node->right;
                            else
                                current_node = current_node->left;
                        }
                    current_node = _root;
                    while (current_node)
                    {
                        if (current_node->content.first == key)
                            return(current_node);
                        else if (current_node->content.first < key)
                            current_node = current_node->right;
                        else
                            current_node = current_node->left;
                    }
                    return (current_node);
                }
    };

    /*****************************************/
    /*                                       */
    /*     Non-member function overloads     */
    /*                                       */
    /*****************************************/
    // template <class T, class Alloc>
    // bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     return (lhs_it == lhs.end() && rhs_it == rhs.end());
    // }
    
    // template <class T, class Alloc>
    // bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     return (lhs_it != lhs.end() || rhs_it != rhs.end());
    // }
    
    // template <class T, class Alloc>
    // bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // // Если значения одинаковы, то сравнивается длина списка
    // // Если значения отличаются, то сравниваются значения
    // // Сравнивает до первого не равного числа
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if (rhs_it == rhs.end() || (*lhs_it > *rhs_it && lhs_it != lhs.end()))
    //         return (false);
    //     return (true);
    // }

    // template <class T, class Alloc>
    // bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if ((rhs_it == rhs.end() && lhs_it != lhs.end()) || (*lhs_it > *rhs_it && lhs_it != lhs.end()))
    //         return (false);
    //     return (true);
    // }
    
    // template <class T, class Alloc>
    // bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if (lhs_it == lhs.end() || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
    //         return (false);
    //     return (true);
    // }

    // template <class T, class Alloc>
    // bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
    // {
    //     list::const_iterator<T> lhs_it = lhs.begin();
    //     list::const_iterator<T> rhs_it = rhs.begin();
    //     while (lhs_it != lhs.end() && rhs_it != rhs.end() && *lhs_it == *rhs_it)
    //     {
    //         lhs_it++;
    //         rhs_it++;
    //     }
    //     if ((lhs_it == lhs.end() && rhs_it != rhs.end()) || (*lhs_it < *rhs_it && rhs_it != rhs.end()))
    //         return (false);
    //     return (true);
    // }

    // template <class T, class Alloc>
    // void swap (List<T,Alloc>& x, List<T,Alloc>& y)
    // {
    //     x.swap(y);
    // }
}

#endif
