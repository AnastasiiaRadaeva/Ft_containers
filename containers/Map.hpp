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
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef typename map::iterator<key_type, mapped_type>               iterator;
            typedef typename map::const_iterator<key_type, mapped_type>         const_iterator;
            typedef typename map::reverse_iterator<key_type, mapped_type>       reverse_iterator;
            typedef typename map::const_reverse_iterator<key_type, mapped_type> const_reverse_iterator;
            typedef size_t                                                      size_type;

            class value_compare
            {
                public:
                    value_compare(key_compare c) : _comp(c) {}

                    bool operator()(const value_type& x, const value_type& y) const
                    {
                        return _comp(x.first, y.first);
                    }
                    key_compare _comp;
            };

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

            /***************************************************************************/
            /*** operator= --------------------------------------------------------- ***/
            Map &operator=(const Map& x)
            {
                if (this != &x)
                {
                    clear();
                    _alloc = x._alloc;
                    _key_comp = x._key_comp;
                    insert(x.begin(), x.end());
                }
                return(*this);
            }
            
            /***************************************************************************/
            /*** destructor -------------------------------------------------------- ***/
            ~Map()
            {
                clear();
                destroy_deallocate_node(_head);
                destroy_deallocate_node(_tail);
            }

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

                key_compare tmp_comp;
                tmp_comp = _key_comp;
                _key_comp = x._key_comp;
                x._key_comp = tmp_comp;
            }
            void                        clear()
            {
                erase(this->begin(), this->end());
            }
            
            /***************************************************************************/
            /*** Observers --------------------------------------------------------- ***/
            key_compare key_comp() const
            {
                return (_key_comp);
            }
            value_compare value_comp() const
            {
                value_compare value_comp(_key_comp);
                return (value_comp);
            }

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
            iterator        lower_bound (const key_type& k)
            {
                iterator it = this->begin();
                for (; it != this->end(); it++)
                {
                    if (!(_key_comp(it->first, k)))
                        return (it);
                }
                return (it);
            }
            const_iterator  lower_bound (const key_type& k) const
            {
                const_iterator it = this->begin();
                for (; it != this->end(); it++)
                {
                    if (!(_key_comp(it->first, k)))
                        return (it);
                }
                return (it);
            }
            iterator upper_bound (const key_type& k)
            {
                iterator it = this->begin();
                for (; it != this->end(); it++)
                {
                    if (_key_comp(k, it->first))
                        return (it);
                }
                return (it);
            }
            const_iterator upper_bound (const key_type& k) const
            {
                const_iterator it = this->begin();
                for (; it != this->end(); it++)
                {
                    if (_key_comp(k, it->first))
                        return (it);
                }
                return (it);
            }
            std::pair<const_iterator,const_iterator>    equal_range(const key_type& k) const
            {
                return (std::make_pair(lower_bound(k), upper_bound(k)));
            }
            std::pair<iterator,iterator>                equal_range(const key_type& k)
            {
                return (std::make_pair(lower_bound(k), upper_bound(k)));
            }

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

            /***************************************************************************/
            /*** Secondary functions ----------------------------------------------- ***/
            map_node<key_type, mapped_type> *grandparent(map_node<key_type, mapped_type> *current_node)
            {
                if (current_node != 0 && current_node->parent != 0)
                    return (current_node->parent->parent);
                return (0);
            }
            map_node<key_type, mapped_type> *uncle(map_node<key_type, mapped_type> *current_node)
            {
                map_node<key_type, mapped_type> *grandpa = grandparent(current_node);
                if (grandpa == 0)
                    return (0);
                if (current_node->parent == grandpa->left)
                    return (grandpa->right);
                else
                    return (grandpa->left);
            }
            map_node<key_type, mapped_type> *brother(map_node<key_type, mapped_type> *current_node)
            {
                if (!current_node || !current_node->parent)
                    return (0);
                if (current_node == current_node->parent->left)
                    return (current_node->parent->right);
                return (current_node->parent->left);
            }
            map_node<key_type, mapped_type> *minimum(map_node<key_type, mapped_type> *current_node)
            {
                if (!current_node)
                    return (0);
                while (current_node->left && current_node->left != _head)
                    current_node = current_node->left;
                return (current_node);                
            }
            map_node<key_type, mapped_type> *maximum(map_node<key_type, mapped_type> *current_node)
            {
                if (!current_node)
                    return (0);
                while (current_node->right && current_node->right != _tail)
                    current_node = current_node->right;
                return (current_node);                
            }
            void                            left_rotation(map_node<key_type, mapped_type> *current_node)
            {
                if (current_node->right == _tail) //защита на случай, если правым окажется хвост
                    return ;
                map_node<key_type, mapped_type> *mate_node = current_node->right;
                mate_node->parent = current_node->parent;
                if (current_node->parent == 0)
                    _root = mate_node;
                else
                {
                    if (current_node == current_node->parent->left)
                        current_node->parent->left = mate_node;
                    else
                        current_node->parent->right = mate_node;
                }
                current_node->right = mate_node->left;
                if (mate_node->left)
                    mate_node->left->parent = current_node;
                current_node->parent = mate_node;
                mate_node->left = current_node;
            }
            void                            right_rotation(map_node<key_type, mapped_type> *current_node)
            {
                if (current_node->left == _head)
                    return ;
                map_node<key_type, mapped_type> *mate_node = current_node->left;
                mate_node->parent = current_node->parent;
                if (current_node->parent == 0)
                    _root = mate_node;
                else
                {
                    if (current_node == current_node->parent->left)
                        current_node->parent->left = mate_node;
                    else 
                        current_node->parent->right = mate_node;
                }
                current_node->left = mate_node->right;
                if (mate_node->right)
                    mate_node->right->parent = current_node;
                current_node->parent = mate_node;
                mate_node->right = current_node;
            }

            map_node<key_type, mapped_type> *find_node(const key_type &key, map_node<key_type, mapped_type> *current_node) const
            {
                if (current_node != _root)
                    while (current_node)
                    {
                        if (current_node->content.first == key)
                                return(current_node);
                        else if (_key_comp(current_node->content.first, key))
                            current_node = current_node->right;
                        else
                            current_node = current_node->left;
                    }
                current_node = _root;
                while (current_node)
                {
                    if (current_node->content.first == key)
                        return(current_node);
                    else if (_key_comp(current_node->content.first, key))
                        current_node = current_node->right;
                    else
                        current_node = current_node->left;
                }
                return (0);
            }

            /***************************************************************************/
            /*** Insertion --------------------------------------------------------- ***/
            map_node<key_type, mapped_type> *create_node(value_type content = value_type())
            {
                try
                {
                    node_pointer l_pointer = _alloc_for_node.allocate(1);
                    map_node<key_type, mapped_type> new_node;
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
            map_node<key_type, mapped_type> *add_new_node(value_type content)
            {
                _current_size++;
                if (_root == 0)
                {
                    _root = create_node(content);
                    _root->right = _tail;
                    _root->left = _head;
                    _tail->parent = _root;
                    _head->parent = _root;
                    return (_root);
                }
                map_node<key_type, mapped_type> *current_node = _root, *parent_node, *new_node;
                size_type                       branch = 0;
                while (current_node && current_node != _tail && current_node != _head)
                {
                    parent_node = current_node;
                    if (_key_comp(current_node->content.first, content.first))
                    {
                        current_node = current_node->right;
                        branch = RIGHT;
                    }
                    else
                    {
                        current_node = current_node->left;
                        branch = LEFT;
                    }
                }
                new_node = create_node(content);
                new_node->color = RED;
                if (branch == LEFT)
                {
                    parent_node->left = new_node;
                    new_node->parent = parent_node;
                    if (current_node == _head)
                    {
                        new_node->left = _head;
                        _head->parent = new_node;
                    }
                }
                else
                {
                    parent_node->right = new_node;
                    new_node->parent = parent_node;
                    if (current_node == _tail)
                    {
                        new_node->right = _tail;
                        _tail->parent = new_node;
                    }
                }
                balancing_after_insertion(new_node);
                return(new_node);
            }
            void                            balancing_after_insertion(map_node<key_type, mapped_type> *new_node)
            {
                while (new_node->parent && new_node->parent->color == RED)
                {
                    map_node<key_type, mapped_type> *uncle_node = uncle(new_node);
                    map_node<key_type, mapped_type> *grandpa_node = grandparent(new_node);
                    if (uncle_node && uncle_node->color == RED)
                    {
                        uncle_node->color = BLACK;
                        new_node->parent->color = BLACK;
                        grandpa_node->color = RED;
                        new_node = grandpa_node;
                    }
                    else
                    {
                        if (new_node == new_node->parent->right && new_node->parent == grandpa_node->left)
                        {
                            left_rotation(new_node->parent);
                            new_node = new_node->left;
                        }
                        else if (new_node == new_node->parent->left && new_node->parent == grandpa_node->right)
                        {
                            right_rotation(new_node->parent);
                            new_node = new_node->right;
                        } //привели к варианту, когда новая новая ищется или по максимуму или по минимуму от дедушки
                        if (new_node->parent == grandpa_node->left)
                            right_rotation(grandpa_node);
                        else
                            left_rotation(grandpa_node);
                        new_node->parent->color = BLACK;
                        grandpa_node->color = RED;
                    }
                }
                _root->color = BLACK;
            }

            /***************************************************************************/
            /*** Deletion ---------------------------------------------------------- ***/
            void    destroy_deallocate_node(map_node<key_type, mapped_type> *node_for_del)
            {
                node_pointer l_pointer = _alloc_for_node.address(*node_for_del);
                _alloc_for_node.destroy(l_pointer);
                _alloc_for_node.deallocate(l_pointer, 1);
                node_for_del = 0;
            }
            void    transplant(map_node<key_type, mapped_type> *first, map_node<key_type, mapped_type> *second)
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
            void    delete_node(map_node<key_type, mapped_type> *node_for_del)
            {
                if (node_for_del == _tail || node_for_del == _head)
                    return ;
                size_type                       color = node_for_del->color;
                size_type                       branch;
                map_node<key_type, mapped_type> *node_for_balancing;
                map_node<key_type, mapped_type> *minimum_node;
                map_node<key_type, mapped_type> *parent;

                _current_size--;
                if (_current_size == 0)
                {
                    destroy_deallocate_node(node_for_del);
                    _tail->parent = _head;
                    _head->parent = _tail;
                    _root = 0;
                    return ;
                }
                if (node_for_del->left && (node_for_del->right && node_for_del->right != _tail))
                {
                    minimum_node = minimum(node_for_del->right);
                    color = minimum_node->color;
                    node_for_balancing = minimum_node->right;
                    branch = RIGHT;
                    parent = minimum_node;
                    if (minimum_node->parent != node_for_del)
                    {
                        transplant(minimum_node, node_for_balancing);
                        minimum_node->right = node_for_del->right;
                        node_for_del->right->parent = minimum_node;
                        branch = LEFT;
                        parent = minimum_node->parent;
                    }
                    transplant(node_for_del, minimum_node);
                    minimum_node->left = node_for_del->left;
                    node_for_del->left->parent = minimum_node;
                    minimum_node->color = node_for_del->color;
                }
                else if (node_for_del == _root)
                {
                    node_for_del->left->right = _tail;
                    _tail->parent = node_for_del->left;
                    node_for_del->left->parent = 0;
                    _root = node_for_del->left;
                    _root->color = BLACK;
                    destroy_deallocate_node(node_for_del);
                    return ;
                }
                else
                {
                    parent = node_for_del->parent;
                    node_for_balancing = (node_for_del->left == 0) ? node_for_del->right : node_for_del->left;
                    if (node_for_del == parent->left)
                        branch = LEFT;
                    else
                        branch = RIGHT;
                    transplant(node_for_del, node_for_balancing);
                    if (node_for_del->left && node_for_del->right && node_for_del->right == _tail)
                    {
                        node_for_balancing->right = _tail;
                        _tail->parent = node_for_balancing;
                    }
                }
                if (color == BLACK)
                    balancing_after_deletion(parent, branch);
                destroy_deallocate_node(node_for_del);
            }
            void    balancing_after_deletion(map_node<key_type, mapped_type> *parent_of_cur_node, size_type branch)
            {
                map_node<key_type, mapped_type> *current_node = (branch == LEFT) ? parent_of_cur_node->left : parent_of_cur_node->right;
                map_node<key_type, mapped_type> *brother_node = (branch == LEFT) ? parent_of_cur_node->right : parent_of_cur_node->left;
                size_type                       loop = 1;
                if (current_node && current_node->color == RED)
                {
                    current_node->color = BLACK;
                    return ;
                }
                while (parent_of_cur_node != 0 && loop == 1)
                {
                    loop = 0;
                    if (brother_node->color == RED)
                    {
                        parent_of_cur_node->color = RED;
                        brother_node->color = BLACK;
                        if (brother_node == parent_of_cur_node->left)
                        {
                            right_rotation(parent_of_cur_node);
                            brother_node = parent_of_cur_node->left;
                        }
                        else
                        {
                            left_rotation(parent_of_cur_node);
                            brother_node = parent_of_cur_node->right;
                        }
                    }
                    if (parent_of_cur_node->color == BLACK && brother_node->color == BLACK && (brother_node->right == 0 || brother_node->right->color == BLACK)
                        && (brother_node->left == 0 || brother_node->left->color == BLACK))
                    {
                        brother_node->color = RED;
                        current_node = parent_of_cur_node;
                        parent_of_cur_node = current_node->parent;
                        brother_node = brother(current_node);
                        loop = 1;
                    }
                    else{ 
                    if (parent_of_cur_node->color == RED && brother_node->color == BLACK && (brother_node->right == 0 || brother_node->right->color == BLACK)
                        && (brother_node->left == 0 || brother_node->left->color == BLACK))
                    {
                        brother_node->color = RED;
                        parent_of_cur_node->color = BLACK;
                    }
                    else
                    {
                        if (brother_node->color == BLACK)
                        {
                            if (brother_node == parent_of_cur_node->right && (brother_node->left && brother_node->left->color == RED)
                                && (brother_node->right == 0 || brother_node->right->color == BLACK))
                            {
                                brother_node->color = RED;
                                brother_node->left->color = BLACK;
                                right_rotation(brother_node);
                            }
                            else if (brother_node == parent_of_cur_node->left && (brother_node->right && brother_node->right->color == RED)
                                && (brother_node->left == 0 || brother_node->left->color == BLACK))
                            {
                                brother_node->color = RED;
                                brother_node->right->color = BLACK;
                                left_rotation(brother_node);
                            }
                            brother_node = brother(current_node);
                            parent_of_cur_node = current_node->parent;
                        }
                        brother_node->color = parent_of_cur_node->color;
                        parent_of_cur_node->color = BLACK;
                        if (brother_node == parent_of_cur_node->right && brother_node->right && brother_node->left->color == RED)
                        {
                            brother_node->right->color = BLACK;
                            left_rotation(parent_of_cur_node);
                        }
                        else if (brother_node == parent_of_cur_node->left && brother_node->left && brother_node->left->color == RED)
                        {
                            brother_node->left->color = BLACK;
                            right_rotation(parent_of_cur_node);
                        }
                    }
                    }
                }
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
