/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:14:01 by kbatwoma          #+#    #+#             */
/*   Updated: 2021/05/18 19:06:05 by kbatwoma         ###   ########.fr       */
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
# include "Vector.hpp"

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
            //     clear();
            //     destroy_deallocate_node(_head);
            //     destroy_deallocate_node(_tail);
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

            void                        erase (iterator position)
            {
                delete_node(position.get_node());
            }
            size_type                   erase (const key_type& k)
            {
                iterator position;
                if ((position = find(k)) == _tail)
                    return (0);
                delete_node(position.get_node());
                return (1);
            }
            void                        erase (iterator first, iterator last)
            {
                Vector<key_type> tmp;
                for (; first != last; first++)
                    tmp.push_back(first->first);
                iterator position;
                while (!tmp.empty())
                {
                    position = find(tmp.back());
                    delete_node(position.get_node());
                    tmp.pop_back();
                }
            }
            void                        swap(Map& x)
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
            void                        clear()
            {
                erase(this->begin(), this->end());
            }
            
            /***************************************************************************/
            /*** Observers --------------------------------------------------------- ***/
            // key_compare key_comp() const;
            // value_compare value_comp() const;

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
            // iterator lower_bound (const key_type& k);
            // const_iterator lower_bound (const key_type& k) const;
            // iterator upper_bound (const key_type& k);
            // const_iterator upper_bound (const key_type& k) const;
            // std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            // std::pair<iterator,iterator>             equal_range (const key_type& k);

            /***************************************************************************/
            /*** Allocator --------------------------------------------------------- ***/
            allocator_type get_allocator() const { return (_alloc); }

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

                void                            destroy_deallocate_node(map_node<key_type, mapped_type> *node_for_del)
                {
                    node_pointer l_pointer = _alloc_for_node.address(*node_for_del);
                    _alloc_for_node.destroy(l_pointer);
                    _alloc_for_node.deallocate(l_pointer, 1);
                    node_for_del = 0;
                }
                void                            transplant(map_node<key_type, mapped_type> *first, map_node<key_type, mapped_type> *second)
                {
                    if (first->parent == 0)
                        _root = second;
                    else if (first == first->parent->left)
                        first->parent->left = second;
                    else if (first == first->parent->right)
                        first->parent->right = second;
                    if (second)
                        second->parent = first->parent;
                }
                void                            delete_node(map_node<key_type, mapped_type> *node_for_del)
                {
                    if (node_for_del == _head || node_for_del == _tail)
                        return ;
                    size_type   original_color = node_for_del->color;
                    map_node<key_type, mapped_type> *tmp_x, *tmp_y;
                    tmp_y = node_for_del;
                    if (node_for_del->left == 0 || node_for_del->left == _head)
                    {
                        tmp_x = node_for_del->right;
                        transplant(node_for_del, tmp_x);
                        if (node_for_del->left == _head)
                        {
                            if (tmp_x)
                            {
                                _head->parent = tmp_x;
                                if (tmp_x == _tail)
                                {
                                    _tail->parent = _head;
                                    _root = 0;
                                }
                                else
                                    tmp_x->left = _head;
                            }
                            else
                            {
                                _head->parent = node_for_del->parent;
                                node_for_del->parent->left = _head;
                            }
                        }
                    }
                    else if (node_for_del->right == 0 || node_for_del->right == _tail)
                    {
                        tmp_x = node_for_del->left;
                        transplant(node_for_del, tmp_x);
                        if (node_for_del->right == _tail)
                        {
                            if (tmp_x)
                            {
                                _tail->parent = tmp_x;
                                tmp_x->right = _tail;
                            }
                            else
                            {
                                _tail->parent = node_for_del->parent;
                                node_for_del->parent->right = _tail;
                            }
                        }
                    }
                    else
                    {
                        tmp_y = node_for_del->right;
                        while (tmp_y->left)
                            tmp_y = tmp_y->left;
                        original_color = tmp_y->color;
                        tmp_x = tmp_y->right;
                        if (tmp_y->parent != node_for_del)
                        {
                            transplant(tmp_y, tmp_x);
                            tmp_y->right = node_for_del->right;
                            tmp_y->right->parent = tmp_y;
                        }
                        transplant(node_for_del, tmp_y);
                        tmp_y->left = node_for_del->left;
                        tmp_y->left->parent = tmp_y;
                        tmp_y->color = node_for_del->color;
                    }
                    destroy_deallocate_node(node_for_del);
                    if (original_color == BLACK && tmp_x != 0)
                        balancing_after_deletion(tmp_x);
                    _current_size--;
                }
                void                            balancing_after_deletion(map_node<key_type, mapped_type> *current_node)
                {
                    map_node<key_type, mapped_type> *tmp_node;
                    while (current_node != _root && current_node->color == BLACK && current_node != _tail && current_node != _head)
                    {
                        if (current_node == current_node->parent->left)
                        {
                            tmp_node = current_node->parent->right;
                            if (tmp_node && tmp_node->color == RED)
                            {
                                tmp_node->color = BLACK;
                                current_node->parent->color = RED;
                                left_rotate(current_node->parent);
                                tmp_node = current_node->parent->right;
                            }
                            if (tmp_node && (tmp_node->left && tmp_node->left->color == BLACK) && (tmp_node->right && tmp_node->right->color == BLACK))
                            {
                                tmp_node->color = RED;
                                current_node = current_node->parent;
                            }
                            else
                            {
                                if (tmp_node->right && tmp_node->right->color == BLACK)
                                {
                                    tmp_node->left->color = BLACK;
                                    tmp_node->color = RED;
                                    right_rotate(tmp_node);
                                    tmp_node = current_node->parent->right;
                                }
                                if (tmp_node)
                                    tmp_node->color = current_node->parent->color;
                                current_node->parent->color = BLACK;
                                if (tmp_node && tmp_node->right)
                                    tmp_node->right->color = BLACK;
                                left_rotate(current_node);
                                current_node = _root;
                            }
                        }
                        else
                        {
                            tmp_node = current_node->parent->left;
                            if (tmp_node && tmp_node->color == RED)
                            {
                                tmp_node->color = BLACK;
                                current_node->parent->color = RED;
                                right_rotate(current_node->parent);
                                tmp_node = current_node->parent->left;
                            }
                            if (tmp_node && (tmp_node->right && tmp_node->right->color == BLACK) && (tmp_node->left && tmp_node->left->color == BLACK))
                            {
                                tmp_node->color = RED;
                                current_node = current_node->parent->left;
                            }
                            else if (tmp_node && tmp_node->left)
                            {
                                if (tmp_node->left->color == BLACK && tmp_node->right)
                                {
                                    tmp_node->right->color = BLACK;
                                    tmp_node->color = RED;
                                    left_rotate(tmp_node);
                                    tmp_node = current_node->parent->left;
                                }
                                tmp_node->color = current_node->parent->color;
                                current_node->parent->color = BLACK;
                                tmp_node->left->color = BLACK;
                                right_rotate(current_node->parent);
                                current_node = _root;
                            }
                        }
                    }
                current_node->color = BLACK;
                }

                map_node<key_type, mapped_type> *add_new_node(value_type content)
                {
                    map_node<key_type, mapped_type> *current_node = _root, *parent_node = 0;
                    size_type   branch = 0;
                    while (current_node != 0 && current_node != _tail && current_node != _head) //ищем нужно место для вставки
                    {
                        parent_node = current_node;
                        if (!(_key_comp(content.first, current_node->content.first)))
                        // if ( content.first > current_node->content.first)
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
                    if (current_node == _root || current_node->parent == _root)
                        return ;
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
                    if (current_node == _root || current_node->parent == _root)
                        return ;
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
