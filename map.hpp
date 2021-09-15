/* ************************************************************************** */
/*					        */
/*					     :::      ::::::::   */
/*   ft_map.hpp					       :+:      :+:    :+:   */
/*					 +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*					              +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:28:07 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/28 16:31:35 by gdupont          ###   ########.fr       */
/*					        */
/* ************************************************************************** */
    
#include <functional>
#include "ft_pair.hpp"
#include "ft_reverse_iterator.hpp"
#include <memory>
#include "ft_avl_tree.hpp"
#include <algorithm>
#include <stdexcept>
#include "ft_lexicographical_compare.hpp"
#include <string.h>
#include <iostream>
#include <limits>

namespace ft {

	template < class Key,
           class T,
           class compare = std::less<Key>,
           class alloc = std::allocator<ft::pair<const Key,T> >
           >
    class map {
        
        public:

			typedef	Key										key_type;
			typedef	T										mapped_type;
			typedef	ft::pair<const Key, T>                	value_type;
			typedef	std::size_t					            size_type;
			typedef	std::ptrdiff_t							difference_type;
			typedef	compare									key_compare;
			typedef	alloc									allocator_type;
			typedef	value_type&								reference;
			typedef	const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef	const value_type*						const_pointer;
			typedef struct s_node<value_type>				t_node;
			typedef	typename alloc::template rebind<t_node>::other	new_alloc;				
        
		public:
			/* #########################  ITERATORS  ######################## */ 
		
			class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
				
				public:

					iterator() : _node(NULL) {}
					iterator(const iterator & rhs) : _node(rhs._node) {}

					iterator& operator=(iterator const & rhs)
								{	this->_node = rhs._node; return (*this); }

					~iterator() { }

					friend bool operator==(const iterator &lhs, const iterator &rhs) { return (lhs._node == rhs._node);}
					friend bool operator!=(const iterator &lhs, const iterator &rhs) { return !(lhs._node == rhs._node); }

					reference operator*() { return *(_node->data); }
					const_reference operator*() const { return (*(_node->_data)); }
					
					pointer operator->() { return (_node->data); }
					const_pointer operator->() const { return (_node->data); }

					iterator operator++(int)
					{

						iterator it = *this;
						++(*this);
						return (it);
					}

					iterator& operator++() {  //pre inc
						compare comp;
						_node = getUpperNode(_node, comp);
						return (*this);
					}

					iterator& operator--()
					{
						compare comp;

						if (isEndNode(node))                                  /* special case for end_node */ 				
							_node = _node->parent;
						else
							_node = getLowerNode(_node, comp);
						return (*this);
					}
					
					iterator operator--(int) 
					{
						iterator iterator = *this;
						--(*this);
						return (iterator);
					}
					
					iterator& operator=(const_reference & lhs) { _node = lhs._node; return (*this); }

				protected:
					t_node*		_node;

				private:
					iterator(t_node * node) : _node(node) { }

				friend class const_iterator;
				friend class map;
			}; 

			/* #########################  END ITERATORS  ######################## */ 

			/* ######################### CONST ITERATORS ######################## */ 

			class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
				
				public:

					typedef const value_type&		reference;
					typedef const value_type*		pointer;

					const_iterator() { }
					const_iterator(const iterator & rhs) : _node(rhs._node) { }

					const_iterator& operator=(const_iterator const & rhs)
								{	this->_node = rhs._node; return (*this); }

					~const_iterator() { }

					friend bool operator==(const const_iterator &lhs, const const_iterator &rhs) { return (lhs._node == rhs._node);}
					friend bool operator!=(const const_iterator &lhs, const const_iterator &rhs) { return !(lhs._node == rhs._node); }

					reference operator*() { return *(this->_node->data); }
					const_reference operator*() const { return (*(this->_node->data)); }
					
					pointer operator->() { return (this->_node->data); }
					const_pointer operator->() const { return (this->_node->data); }

					const_iterator operator++(int) 
					{
						const_iterator it = *this;
						++(*this);
						return (it);
					}

					const_iterator& operator++() {  //pre inc
						compare comp;

						this->_node = getUpperNode(this->_node, comp);
						return (*this);
					}

					const_iterator& operator--()
					{
						compare comp;

						if (isEndNode(_node))                                   /* special case for end_node */ 				
							this->_node = this->_node->parent;
						else
							this->_node = getLowerNode(this->_node, comp);
						return (*this);
					}
					
					const_iterator operator--(int) 
					{
						const_iterator const_iterator = *this;
						--(*this);
						return (const_iterator);
					}
					
					const_iterator& operator=(const_reference & lhs) { this->_node = lhs._node; return (*this); }
				
				protected:
					t_node*		_node;
				
				private:
					const_iterator(t_node * node) : _node(node) { }

				friend class map;

			}; 			
		/* #########################  END CONST ITERATORS  ###################### */ 

        
		class value_compare {
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
				
					bool operator()( const value_type& lhs, const value_type& rhs ) const { return (comp(lhs.first, rhs.first));}
				
					compare comp;
					value_compare(compare c) : comp(c) { }
			};
		
        typedef	ft::reverse_iterator<iterator>				reverse_iterator;
        typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;

        map() : _tree(setUpNode(NULL, NULL)), _size(0) { _endNode = _tree; }
		
        explicit map( const compare& comp, const allocator_type& a = alloc() ) : _tree(setUpNode(NULL, NULL)), _alloc(a), _comp(comp), _size(0) 
					{ _endNode = _tree; }
        
		template < class inputIt >
		map( inputIt first, inputIt last, const compare& comp = compare(), const allocator_type& allocator = allocator_type() )
			:	_tree(setUpNode(NULL, NULL)), _size(0), _comp(comp), _alloc(allocator){
				_endNode = _tree;
				for (; first != last; first++)
					insert(*first);
	
		}

		map( const map& other ) : _tree(setUpNode(NULL, NULL)) { *this = other; }

		~map() { deleteSubTree(_tree); };

		map& operator=( const map& other ) { 
			deleteSubTree(_tree);
			_tree = NULL;
			_size = other._size;
			copyNode(&_tree, other._tree, NULL);
			_endNode = getRightExtremNode(_tree);
			if (_endNode->right)
				_endNode = _endNode->right;
			return (*this);
		};

	private:

		void	copyNode(t_node **dst, t_node *src, t_node *parent) {
			if (!src)
				return ;
			*dst = setUpNode(src->data, parent);
			copyNode(&((*dst)->left), src->left, *dst);
			copyNode(&((*dst)->right), src->right, *dst);
		}

	public: // only for display purpose, can be set private without affecting map functionnalities;
		void	printTree() {
			this->printTree(NULL, 0);
		}

		void	printTree(t_node *current, int depth) {
			if (depth == 0)
				current = this->_tree;
			if (!current || !current->data)
				return ;
			//std::cout << depth << " | Key: " << current->data->first << " Height : " << current->height << " Balance factor " << current->balanceFactor << std::endl;
			std::cout << "Depth: " << depth << " |  Key: " << current->data->first << " | Value: " << current->data->second << std::endl;
			
			printTree(current->left, depth + 1);
			printTree(current->right, depth + 1);
			if (depth == 0)
				std::cout << std::endl;
		}

	public:

		allocator_type get_allocator() const { return (_alloc); }

		T& at( const Key& key ) {
			for (iterator it = this->begin() ; it != this->end(); it++)
				if (key == it->first)
					return (*it);
			throw std::out_of_range("Out of range exeption");
		}
		
		const T& at( const Key& key ) const { return (at(key)); }

		T& operator[]( const Key& key ) {
			value_type val(key, T());
			t_node *target = getNode(_tree, val, _comp);
			if (isEndNode(target) || !target)
				return ((insert(ft::make_pair(key, T()))).first->second);
			return (target->data->second);
		}
		
		public:

			iterator 				begin() {	return(iterator(getLeftExtremNode(_tree))); }

			const_iterator 			begin() const { return (const_iterator(getLeftExtremNode(_tree))); }
			
			iterator 				end() { return (iterator(this->_endNode)); }

			const_iterator			end() const { return (const_iterator(this->_endNode)); }

			reverse_iterator 		rbegin() { return (reverse_iterator(end())); }

			const_reverse_iterator 	rbegin() const { return (reverse_iterator(end())); }

			reverse_iterator 		rend() { return (reverse_iterator(begin())); }
			
			const_reverse_iterator	rend() const { return (reverse_iterator(begin())); }

			size_type 				size() const { return _size; }

			bool 					empty() const { return (!_size); }

			size_type 				max_size() const { new_alloc a; return a.max_size(); }

			void clear(void) {
				if (_size == 0)
					return ;
				t_node *end_node = getRightExtremNode(_tree)->right;
				end_node->parent->right = NULL;
				end_node->parent = NULL;
				deleteSubTree(_tree);
				_tree = end_node;
				_endNode = _tree;
				_size = 0;
			}

			ft::pair<iterator, bool> insert( const value_type& value ) {
				ft::pair<t_node *, int> nodeCreated;
				if (isEndNode(_tree)) 
				{
					nodeCreated.first = setUpNode(&value, NULL);
					nodeCreated.first->right = _endNode;
					_endNode->parent = nodeCreated.first;
					_tree = nodeCreated.first;
					nodeCreated.second = 1;
				}												
				else
				{
					nodeCreated = findValuePlace(value, _tree);
					if (nodeCreated.second == 1)
						computeBalanceFactorNRebalance(_tree);
				}
				if (nodeCreated.second)
					_size++;
				iterator it = iterator(nodeCreated.first);
				return ft::pair<iterator, int>(it, nodeCreated.second);
			}

			template< class inputIt >
			void insert( inputIt first, inputIt last) {
				for(; first != last; first++)
					this->insert(*first);
			}

			iterator insert( iterator hint, const value_type& value ) {
				(void)hint;
				return (iterator(insert(value).first));
			}

			void erase(iterator pos) {
				key_compare comp;
				if (pos == end())
					return ;
				value_type value(pos->first, pos->second);
				t_node *target = getNode<value_type, key_compare>(_tree, value, comp);
				if (!target)
					return ;
				if (isEndNode(target->right))
					eraseMaxNode(target);
				else if (target->left && target->right)
					eraseFullNode(target);
				else if (!target->left && !target->right)
					eraseLeaf(target);
				else
					eraseOnlyOneChildNode(target);
				computeBalanceFactorNRebalance(_tree);
				_size--;
			}

			void erase( iterator first, iterator last ) {
				for(iterator it = first; it != last; )
				{
					it++;
					this->erase(first);
					first = it;
				}
			}

			size_type erase( const key_type& key ) {
				size_type sizeBefore = _size;
				value_type value(key, T());
				t_node *target = getNode(_tree, value,_comp);
				if (!target)
					return (0);
				erase(iterator(target));
				return (sizeBefore - _size);
			}
			
			void swap( map& other ) {
				t_node *tempTree = other._tree;
				t_node *tempEndNode = other._endNode;
				int		tempSize = other._size;

				other._tree = _tree;
				other._endNode = _endNode;
				other._size = _size;
				
				_tree = tempTree;
				_endNode = tempEndNode;
				_size = tempSize;
				}

			size_type count( const Key& key ) const {
				value_type		target(key, mapped_type());
				if (getNode(_tree, target, _comp))
					return (1);
				return (0);
			}

			iterator find( const Key& key ) {
				value_type		target(key, mapped_type());
				t_node	*targetNode = getNode(_tree, target, _comp);

				if (targetNode)
					return (targetNode);
				else
					return (this->end());
			}

			const_iterator find( const Key& key ) const {
				value_type		target(key, mapped_type());
				t_node	*targetNode = getNode(_tree, target, _comp);

				if (targetNode)
					return (targetNode);
				else
					return (this->end());
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ) {
				ft::pair<iterator,iterator> range(lower_bound(key), upper_bound(key));
				return (range);
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
				ft::pair<const_iterator, const_iterator> range(lower_bound(key), upper_bound(key));
				return (range);
			}
			
			iterator lower_bound( const Key& key ) {
				iterator	current = iterator(_tree);
				iterator	save = this->end();

				while (1) {
					if (current == end())
						return (current);
					if ((!_comp(key, current->first) && !_comp(current->first, key)))
						return (current);
					else if (_comp(current->first, key) && save != this->end())
						return (save);
					else if (_comp(current->first, key))
						current++;
					else
					{
						save = current;
						if (current == begin())
							return (save);
						current--;
					}
				}
				return (end());
			}

			const_iterator lower_bound( const Key& key ) const {
				const_iterator	current = iterator(_tree);
				const_iterator	save = this->end();

				while (1) {
					if (current == this->end())
						return (current);
					if ((!_comp(key, current->first) && !_comp(current->first, key)))
						return (current);
					else if (_comp(current->first, key) && save != this->end())
						return (save);
					else if (_comp(current->first, key))
						current++;
					else
					{
						save = current;
						if (current == begin())
							return (save);
						current--;
					}
				}
				return (end());
			}

			iterator upper_bound( const Key& key ) {
				iterator	low_bound = lower_bound(key);
				if (low_bound == end())
					return (low_bound);
				if (!_comp(low_bound->first, key) && !_comp(key, low_bound->first))
					return (++low_bound);
				return (low_bound);
			}

			const_iterator upper_bound( const Key& key ) const {
				const_iterator	low_bound = lower_bound(key);
				if (low_bound == end())
					return (low_bound);
				if (!_comp(low_bound->first, key) && !_comp(key, low_bound->first))
					return (++low_bound);
				return (low_bound);
			}

			key_compare key_comp() const { return (_comp); }
			value_compare value_comp() const { return (value_compare(_comp)); }

			friend	bool operator==( const ft::map<Key,T,compare,alloc>& lhs, const ft::map<Key,T,compare,alloc>& rhs ) {
				if (lhs._size != rhs._size)
					return (0);
				return (compare2NodesNchilds(lhs._tree, rhs._tree, compare())); }
			
			
			friend	bool operator!=( const ft::map<Key,T,compare,alloc>& lhs,
			const ft::map<Key,T,compare,alloc>& rhs ) { return !(lhs == rhs); }
					
			friend	bool operator<( const ft::map<Key,T,compare,alloc>& lhs,
					const ft::map<Key,T,compare,alloc>& rhs ) {
				const_iterator first1 = lhs.begin();
				const_iterator first2 = rhs.begin();
				const_iterator last1 = lhs.end();
				const_iterator last2 = rhs.end();

				for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
					if (*first1 < *first2) return true;
					if (*first2 < *first1) return false;
				}
				return ((first1 == last1) && (first2 != last2));
			}
		
			friend bool operator<=( const ft::map<Key,T,compare,alloc>& lhs,
						const ft::map<Key,T,compare,alloc>& rhs ) {
							return (lhs == rhs || lhs < rhs); }
					
			friend bool operator>( const ft::map<Key,T,compare,alloc>& lhs,
					const ft::map<Key,T,compare,alloc>& rhs ) {
						return (! (lhs <= rhs)); }

			friend bool operator>=( const ft::map<Key,T,compare,alloc>& lhs,
					const ft::map<Key,T,compare,alloc>& rhs ) {
						return (lhs == rhs || lhs > rhs); }
				
				typedef std::allocator<t_node> nodeAlloc;


		private:
			int computeBalanceFactorNRebalance(t_node *current) {
				if (!current || isEndNode(current))
					return (0);
				if (!current->left && (!current->right || isEndNode(current->right))  // if leaf
					return (1);
				int leftHeight = computeBalanceFactorNRebalance(current->left);
				int rightHeight = computeBalanceFactorNRebalance(current->right);
				current->balanceFactor = leftHeight - rightHeight;
				if (current->balanceFactor > 1 || current->balanceFactor < -1)
				{
					rebalanceTree(current);
					leftHeight = computeBalanceFactorNRebalance(current->left);
					rightHeight = computeBalanceFactorNRebalance(current->right);
					current->balanceFactor = leftHeight - rightHeight;
				}
				current->height = std::max(leftHeight, rightHeight) + 1;
				return (current->height);
			}

			int getNodeHeight(t_node *current) {
				if (!current || isEndNode(current))
					return (0);
				else
				{
					int leftHeight = getNodeHeight(current->left);
					int rightHeight = getNodeHeight(current->right);
					current->height = std::max(leftHeight, rightHeight) + 1;
					current->balanceFactor = leftHeight - rightHeight;
				}
				return (current->height);
			}

			void	rebalanceTree(t_node *current)
			{
				if (current->balanceFactor < 0 && current->right && current->right->balanceFactor <= 0)
					doLeftRotation(current);
				else if (current->balanceFactor > 0 && current->left && current->left->balanceFactor > 0)
					doRightRotation(current);
				else if (current->balanceFactor < 0 && current->right && current->right->balanceFactor > 0)
					doRightLeftRotation(current);
				else if (current->balanceFactor > 0 && current->left && current->left->balanceFactor <= 0)
					doLeftRightRotation(current);
			}

			void	doRightRotation(t_node *c)
			{
				t_node *b = c->left;
				
				c->left = b->right;
				if (c->left)
					c->left->parent = c;
				b->right = c;
				b->parent = c->parent;
				c->parent = b;
				if (b->parent && b->parent->left == c)
					b->parent->left = b;
				else if (b->parent)
				 	b->parent->right = b;
				else
					_tree = b;
			}

			void	doLeftRotation(t_node *c)
			{
				t_node *b = c->right;

				c->right = b->left;
				if (c->right)
					c->right->parent = c;
				b->left = c;
				b->parent = c->parent;
				c->parent = b;
				if (b->parent && b->parent->left == c)
					b->parent->left = b;
				else if (b->parent)
				 	b->parent->right = b;
				else
					_tree = b;
			}

			void	doLeftRightRotation(t_node *c)
			{
				doLeftRotation(c->left);
				doRightRotation(c);
			}

			void	doRightLeftRotation(t_node *c)
			{
				doRightRotation(c->right);
				doLeftRotation(c);
			}
		
			t_node *setUpNode(const value_type* value, t_node *parent) {
				t_node *node = this->_nodeAlloc.allocate(1);

				this->_nodeAlloc.construct(node, t_node());
				bzero(reinterpret_cast<char *>(node), sizeof(t_node));
				node->parent = parent;
				node->left = NULL;
				node->right = NULL;
				node->height = 0;
				node->balanceFactor = 0;
				node->data = NULL;
				if (!value)
					return (node);
				node->data = this->_alloc.allocate(1);
				this->_alloc.construct(node->data, *value);
				return (node);
			}
		
			ft::pair<t_node *, bool>	findValuePlace(const value_type& value, t_node *current) {
				ft::pair<t_node *, bool> ret(NULL, true); 

				if (!_comp(value.first, current->data->first) && !_comp(current->data->first, value.first))
					return ft::pair<t_node *, int>(current, false);
				else if (this->_comp(value.first, current->data->first))
				{
					if (!current->left)
						ret.first = current->left = setUpNode(&value, current);
					else
						ret = findValuePlace(value, current->left);
				}
				else
				{
					if (!current->right)
						ret.first = current->right = setUpNode(&value, current);
					else if (isEndNode(current->right))
					{
						current->right = setUpNode(&value, current);
						current->right->right = this->_endNode;
						ret.first = current->right->right->parent = current->right;
					}
					else
						ret = findValuePlace(value, current->right);
				}
				if (ret.second)
					current->height += 1;
				return ret;

			}

			void	deleteSubTree(t_node *node) {
				if (!node)
					return ;
				t_node *left = node->left;
				t_node *right = node->right;
				destroyNdeallocateData(node->data);
				destroyNdeallocateNode(node);
				deleteSubTree(left);
				deleteSubTree(right);
			}

			void	destroyNdeallocateData(pointer data) {
				if (!data)
					return ;
				_alloc.destroy(data);
				_alloc.deallocate(data, 1);
			}

			void	destroyNdeallocateNode(t_node *node) {
				_nodeAlloc.destroy(node);
				_nodeAlloc.deallocate(node, 1);
			}

			void eraseMaxNode(t_node *target) {
				t_node *left = target->left;
				t_node *right = target->right;
				t_node *parent = target->parent;

				if (!parent)
				{
					if (left)
					{
						_tree = left;
						getRightExtremNode(left)->right = right;
						left->parent = NULL;
					}
					else
					{
						_tree = right;
						right->parent = NULL;
					}
				}
				else if (left)
				{					
					parent->right = left;
					left->parent = parent;
					left->right = right;
					right->parent = left;
				}
				else
				{
					right->parent = parent;
					parent->right = right; 
				}
				target->left = NULL;
				target->right = NULL;
				deleteSubTree(target);
			}

			void eraseFullNode(t_node *target) {
				t_node *left = target->left;
				t_node *right = target->right;
				t_node *parent = target->parent;

				if (!parent)
				{
					findLeftNodePlace(left, right);
					_tree = right;
					right->parent = NULL;
				}
				else
				{
					if (parent->right == target)
						parent->right = right;
					else
						parent->left = right;
					right->parent = parent;
					findLeftNodePlace(left, right);
				}
				target->right = NULL;
				target->left = NULL;
				deleteSubTree(target);
			}

			void eraseLeaf(t_node *target) {
				if (target == target->parent->left)
					target->parent->left = NULL;
				else
					target->parent->right = NULL;
				deleteSubTree(target);
				
			}

			void findLeftNodePlace(t_node* toPlace, t_node *current) {
				if (current->left)
					findLeftNodePlace(toPlace, current->left);
				else
				{
					current->left = toPlace;
					toPlace->parent = current;
				}
			}

			void eraseOnlyOneChildNode(t_node *target) {

				t_node *child = (target->left ? target->left : target->right);
				t_node *parent = target->parent;
				if (!parent)
				{
					_tree = child;
					child->parent = NULL;
				}
				else if (parent->left == target)
					parent->left = child;
				else
					parent->right = child;
				child->parent = parent;
				target->right = NULL;
				target->left = NULL;
				deleteSubTree(target);
			}

		private:
			t_node 							*_tree;
			t_node							*_endNode;
			size_type						_size;
			compare							_comp;
			alloc							_alloc;
			nodeAlloc						_nodeAlloc;

			
    };

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs,
          map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }
		
	
	
	
} /* NAMESPACE FT */