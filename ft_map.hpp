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
#include "ft_avlNode.hpp"
#include <algorithm>
#include <stdexcept>


namespace ft {
	
	template < class Key,					   // map::key_type
           class T,					     // map::mapped_type
           class compare = std::less<Key>,					    // map::key_compare
           class alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           >
    class map {
        
        public:

        typedef	Key										key_type;
        typedef	T										mapped_type;
        typedef	ft::pair<const Key, T>                		value_type;
        typedef	std::size_t					            size_type;
        typedef	std::ptrdiff_t							difference_type;
        typedef	compare									key_compare;
        typedef	alloc									allocator_type;
        typedef	value_type&								reference;
        typedef	const value_type&					    const_reference;
        typedef	typename alloc::pointer  	     		pointer;
        typedef	typename alloc::const_pointer           const_pointer;
		typedef struct s_node<value_type>				t_node; 						
       	//typedef	LegacyBidirectionalIterator to value_type	iterator;
        //typedef	LegacyBidirectionalIterator to const value_type	const_iterator	;
        
		
		class value_compare {
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
			
				bool operator()( const value_type& lhs, const value_type& rhs ) const { return (comp(lhs.first, rhs.first));}
			
			protected:
				compare comp;
				value_compare(compare c) : comp(c) { }
		};
		
		public:
		
        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
			
			public:

				iterator() : _node(NULL) {}
				iterator(const iterator & rhs) : _node(rhs._node) {}
				iterator(t_node * node)  { _node = node; }

				iterator& operator=(iterator const & rhs)
							{	this->_node = rhs._node; return (*this); }

				~iterator() { }

				bool operator==( const iterator &rhs) const { return (this->_node == rhs._node);}
				bool operator!=(const iterator &rhs) const { return !(*this == rhs); }

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

					if (!_node->data)                                       /* special case for end_node */ 				
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


			private:

				t_node*		_node;
        }; // iterator class
        
        typedef	ft::reverse_iterator<iterator>				reverse_iterator;
        typedef const iterator								const_iterator;
        typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;

        map() : _tree(NULL), _size(0) { }
		
        explicit map( const compare& comp, const allocator_type& a = alloc() ) : _tree(NULL), _alloc(a), _comp(comp), _size(0) { _vComp(comp); }
        
		~map() { deleteSubTree(_tree); };
		
		void	printTree(t_node *current, int depth) {
			if (depth == 0)
				current = this->_tree;
			if (!current || !current->data)
				return ;
			std::cout << depth << " | Key: " << current->data->first << " Height : " << current->height << " Balance factor " << current->balanceFactor << std::endl;
			printTree(current->left, depth + 1);
			printTree(current->right, depth + 1);
			if (depth == 0)
				std::cout << std::endl;
		}



		// map& operator=( const map& other ) { }; 
		allocator_type get_allocator() const { return (_alloc); }

		T& at( const Key& key ) {
			for (iterator it = this->begin() ; it != this->end(); it++)
				if (key == it->first)
					return (*it);
			throw std::out_of_range("Out of range exeption");
		}
		
		const T& at( const Key& key ) const { return (at(key)); }

		T& operator[]( const Key& key ) {
			iterator it = this->begin();
			for (; it != this->end(); it++)
			{
				if (key == it->first)
					return (*it);
			}
			return ((insert(key, T())).first->second);
		}
		
		public:

			iterator 				begin() { return (iterator(getLeftExtremNode(_tree))); }

			const_iterator 			begin() const { return (begin()); }
			
			iterator 				end() { return (iterator(getRightExtremNode(_tree)->right)); }

			const_iterator 			end() const { return (end()); }

			reverse_iterator 		rbegin() { return (reverse_iterator(begin())); }

			const_reverse_iterator 	rbegin() const {	return (reverse_iterator(begin())); }

			reverse_iterator 		rend() { return (reverse_iterator(end())); }
			
			const_reverse_iterator rend() const { return (reverse_iterator(end())); }

			size_type 				size() const { return _size; }

			bool 					empty() const { return (!_size); }

			size_type 				max_size() const { return (_alloc.max_size());}
			
			void clear(void) {
				t_node *end_node = getRightExtremNode(_tree)->right;
				end_node->parent->right = NULL;
				end_node->parent = NULL;
				deleteSubTree(_tree);
				_tree = end_node;
			}

			ft::pair<iterator, bool> insert( const value_type& value ) {
				t_node *nodeCreated = NULL;

				if (!_tree)
				{
					_tree = setUpNode(value, NULL);
					_tree->right = this->_nodeAlloc.allocate(1);
					this->_nodeAlloc.construct(_tree->right, t_node());  	// for the first insertion we had a end_node, 
					_tree->right->parent = _tree;					// that is empty and that we will use later for our iterators
					nodeCreated = _tree;							// this node is always the right child of the biggest element regarding the key
				}
				else if (!_tree->data)
				{
					nodeCreated = setUpNode(value, NULL);
					nodeCreated->right = _tree;
					_tree->parent = nodeCreated;
					_tree = nodeCreated;
				}												
				else
				{
					nodeCreated = findNodePlace(value, _tree);
					if (nodeCreated)
						computeBalanceFactorNRebalance(_tree);
				}
				if (nodeCreated)
					_size++;
				return ft::pair<iterator, bool>(iterator(nodeCreated), nodeCreated != NULL);
			}

		private:
			int computeBalanceFactorNRebalance(t_node *current) {
				if (!current)
					return (0);
				if (!current->left && (!current->right || !current->right->data))
					return (1);
				current->balanceFactor = computeBalanceFactorNRebalance(current->left) - computeBalanceFactorNRebalance(current->right);
				if (current->balanceFactor > 1 || current->balanceFactor < -1)
				{
					rebalanceTree(current);
				}
				current->height = std::max(computeBalanceFactorNRebalance(current->left), computeBalanceFactorNRebalance(current->right)) + 1;
				return (current->height);
			}

			void	rebalanceTree(t_node *current)
			{
				if (current->balanceFactor < 0 && current->right && current->right->balanceFactor < 0)
					doLeftRotation(current);
				else if (current->balanceFactor > 0 && current->left && current->left->balanceFactor > 0)
					doRightRotation(current);
				else if (current->balanceFactor < 0 && current->right && current->right->balanceFactor > 0)
					doRightLeftRotation(current);
				else if (current->balanceFactor > 0 && current->left && current->left->balanceFactor < 0)
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
		
			t_node *setUpNode(const value_type& value, t_node *parent) {
				t_node *node = this->_nodeAlloc.allocate(1);

				this->_nodeAlloc.construct(node, t_node());
				node->parent = parent;
				node->data = this->_alloc.allocate(1);
				this->_alloc.construct(node->data, value);
				node->left = NULL;
				node->right = NULL;
				node->height = 0;
				node->balanceFactor = 0;								//to potentially delete
				return (node);
			}
		
			t_node	*findNodePlace(const value_type& value, t_node *current) {
				t_node *ret = NULL;
				
				if (!_comp(value.first, current->data->first) && !_comp(current->data->first, value.first))
					return NULL;
				else if (this->_comp(value.first, current->data->first))
				{
					if (!current->left)
						ret = current->left = setUpNode(value, current);
					else
						ret = findNodePlace(value, current->left);
				}
				else
				{
					if (!current->right)
						ret = current->right = setUpNode(value, current);
					else if (!current->right->data) //if we reached the end element of the tree, see insert(const value_type& value)
					{
						current->right->right = setUpNode(value, current);
						std::swap(current->right->data, current->right->right->data);
						ret = current->right->right->parent = current->right;
					}
					else
						ret = findNodePlace(value, current->right);
				}
				if (ret)
					current->height += 1;
				return (ret);
			}

			void	deleteSubTree(t_node *node) {
				if (!node)
					return ;
				
				t_node *left = node->left;
				t_node *right = node->right;
				std::cout << node->data->first << " ";
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

		public:

			template< class inputIt >
			void insert( inputIt first, inputIt last) {
				for(; first != last; first++)
					this->insert(*first);
			}
		
			void erase(iterator pos) {
				key_compare comp;
				value_type value(pos->first, pos->second);
				t_node *target = getNode<value_type, key_compare>(_tree, value, comp);
				printTree(_tree, 0);
				putTargetInLeaf(target, comp);
				//printTree(_tree, 0);
			}

		// void erase( iterator first, iterator last );
		// size_type erase( const key_type& key );
		
		// void swap( map& other );

		// size_type count( const Key& key ) const;

		// iterator find( const Key& key );
		// const_iterator find( const Key& key ) const;

		// ft::pair<iterator,iterator> equal_range( const Key& key );
		// ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		
		// iterator lower_bound( const Key& key ); 
		// const_iterator lower_bound( const Key& key ) const;

		// iterator upper_bound( const Key& key );
		// const_iterator upper_bound( const Key& key ) const;

		key_compare key_comp() const { return (_comp); }
		map::value_compare value_comp() const { return (_vComp); }

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
        //          const ft::map<Key,T,Compare,Alloc>& rhs );

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
        //          const ft::map<Key,T,Compare,Alloc>& rhs ) { return !(lhs == rhs); }
				 
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
        //         const ft::map<Key,T,Compare,Alloc>& rhs );
				
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
        //          const ft::map<Key,T,Compare,Alloc>& rhs );
				 
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
        //         const ft::map<Key,T,Compare,Alloc>& rhs );

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
        //          const ft::map<Key,T,Compare,Alloc>& rhs );
			typedef std::allocator<t_node> nodeAlloc;

		private:


			t_node 							*_tree;
			size_type						_size;
			compare							_comp;
			value_compare					_vComp(compare c);
			alloc							_alloc;
			nodeAlloc						_nodeAlloc;

			
    };	
	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs,
          map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }
	
	
} /* NAMESPACE FT */ 