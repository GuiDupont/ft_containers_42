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
        typedef	ft::pair<const Key, T>                	value_type;
        typedef	std::size_t					            size_type;
        typedef	std::ptrdiff_t							difference_type;
        typedef	compare									key_compare;
        typedef	alloc									allocator_type;
        typedef	value_type&								reference;
        typedef	const value_type&					    const_reference;
        typedef	typename alloc::pointer  	     		pointer;
        typedef	typename alloc::const_pointer           const_pointer;
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
		
		private:
		
			typedef struct	s_node {
				struct s_node				*parent;
				struct s_node				*left;
				struct s_node				*right;
				value_type					*data;
				int							height;
				int							balanceFactor;
			}				t_node;

		public:
		
        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
			
			public:

				iterator() : _node(NULL), _end(0) {}
				iterator(const iterator & rhs) : _node(rhs._node), _end(0) {}
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
					t_node * current = this->_node;
					compare comp;
							
					if (current->right)
					{
						current = current->right;
						while (1)
						{
							if (current->left)
								current = current->left;
							else
							{
								_node = current;
								break;
							}
						}
					}
					else
					{
						while (current->parent)
						{
							if (comp(current->data->first, current->parent->data->first))
							{
								_node = current->parent;
								return (*this);
							}
							current = current->parent;
						}
						_node = NULL;
					}
					return (*this);
				}

				iterator& operator--() 
				{
					t_node * current = this->_node;
					compare comp;
					if (!current->data)
						return (goToLastNode(_tree));
					if (current->left)
					{
						current = current->left;
						while (1)
						{
							if (current->right)
								current = current->right;
							else
							{
								_node = current;
								break;
							}
						}
					}
					else
					{
						while (current->parent)
						{
							if (!comp(current->data->first, current->parent->data->first))
							{
								_node = current->parent;
								return (*this);
							}
							current = current->parent;
						}
						_node = NULL;
					}
					return (*this);
				}
				
				iterator operator--(int) 
				{
					iterator iterator = *this;
					--(*this);
					return (iterator);
				}
				
				// iterator& operator=(const_reference & lhs) { this->_ptr = lhs; return (*this); }


			private:
				t_node*		_node;
				t_node*		_previous;
				int			_end;
				map*		_map;
			
			t_node * goToLastNode(t_node *node) {
				while (node->right)
					node = node->right;
				return (node);
			}


				
        };
        
        typedef	ft::reverse_iterator<iterator>         reverse_iterator;
        typedef const iterator					         const_iterator;
        typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

        map() : _tree(NULL), _size(0) { }
		
        explicit map( const compare& comp, const allocator_type& a = alloc() ) : _tree(NULL), _alloc(a), _comp(comp), _size(0) {
				
				_vComp(comp);
		}
        ~map() { };
		
		void	printTree(t_node *current, int depth) {
			if (depth == 0)
				current = this->_tree;
			if (!current)
				return ;
			std::cout << depth << " | Key: " << current->data->first << " Height : " << current->height << " Balance factor " << current->balanceFactor << std::endl;
			printTree(current->left, depth + 1);
			printTree(current->right, depth + 1);
			if (depth == 0)
				std::cout << std::endl;
		}



		// map& operator=( const map& other ) { }; 
		allocator_type get_allocator() const { return (_alloc); }

		//T& at( const Key& key );
		//const T& at( const Key& key ) const;
		// T& operator[]( const Key& key );
		
		public:

		iterator begin() {
			t_node* node = _tree;
		
			while (1) {
				if (node->left)
					node = node->left;
				else
					break;
			}
			return (iterator(node));
		}

		const_iterator begin() const {
			iterator ret = begin();
			return (ret);
		}
		
		iterator end() {
			t_node* node = _tree;
		
			while (node->right)
				node = node->right;

			return (iterator());
		}

		const_iterator end() const {
			iterator ret = end();
			return (ret);
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rbegin() const {
			const_iterator ret = begin();
			return (reverse_iterator(ret));
		}

		reverse_iterator rend() {
			return (reverse_iterator(end()));
		}
		
		const_reverse_iterator rend() const {
			const_iterator ret = end();
			return (reverse_iterator(ret));
		}

		size_type size() const { return _size; }
		bool empty() const { return (!_size); }
		size_type max_size() const { return (_alloc.max_size());}
		
		// void clear();

		// ft::pair<iterator, bool> 
		void insert( const value_type& value ) {
			if (!_tree)
			{
				_tree = setUpNode(value, NULL);
			}
			else
			{
				findSpot(value, _tree);
				computeBalanceFactorNRebalance(_tree);
				
			}
		}

		private:
			int computeBalanceFactorNRebalance(t_node *current) {
				if (!current)
					return (0);
				if (!current->left && !current->right)
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
				this->_nodeAlloc.construct(node);
				node->parent = parent;
				node->data = this->_alloc.allocate(1);
				this->_alloc.construct(node->data, value);
				node->left = NULL;
				node->right = NULL;
				node->height = 0;
				node->balanceFactor = 0;
				return (node);
			}
		
			void	findSpot(const value_type& value, t_node *current) {
				if (value.first == current->data->first)
					return ;
				else if (this->_comp(value.first, current->data->first))
				{
					if (!current->left)
						current->left = setUpNode(value, current);
					else
						findSpot(value, current->left);
				}
				else
				{
					if (!current->right)
						current->right = setUpNode(value, current);
					else
						findSpot(value, current->right);
				}
				current->height += 1; //add a condition;
				
			}

		// template< class InputIt >
		// void insert( InputIt first, InputIt last); 
		
		// void erase( iterator pos );
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


			t_node 			*_tree;
			size_type		_size;
			compare			_comp;
			value_compare	_vComp(compare c);
			alloc			_alloc;
			nodeAlloc		_nodeAlloc;

			t_node *goToLastNode(t_node *node)
			{
				while (node->right)
					node = node->right;
				return (node);
			}

			
    };	
	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs,
          map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }
	
	
} /* NAMESPACE FT */ 