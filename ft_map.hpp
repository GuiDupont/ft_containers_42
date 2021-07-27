/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:28:07 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/26 17:07:33 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>

#include "ft_pair.hpp"

namespace ft {
	
	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class compare = std::less<Key>,                     // map::key_compare
           class alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           >
    class map {
        
        public:

        typedef	Key	                                    key_type;
        typedef	T                                       mapped_type;
        typedef	ft::pair<const Key, T>                	value_type;
        typedef	std::size_t                             size_type;
        typedef	std::ptrdiff_t                          difference_type;
        typedef	compare	                                key_compare;
        typedef	alloc									allocator_type;
        typedef	value_type&								reference;
        typedef	const value_type&                       const_reference;
        typedef	typename alloc::pointer  	     		pointer;
        typedef	typename alloc::const_pointer           const_pointer;
       // typedef	LegacyBidirectionalIterator to value_type	iterator;
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

        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
            
        };
        
        typedef	std::reverse_iterator<iterator>         reverse_iterator;
        typedef const iterator                          const_iterator;
        typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;

        map() {
			_tree(NULL);
			_size(0);

		}
		
        explicit map( const compare& comp, const allocator_type& a = alloc() ) : _tree(NULL), _alloc(a), _comp(comp) {
				
				_vComp(comp);
		}
        ~map() { };

		// map& operator=( const map& other ) { }; 
		allocator_type get_allocator() const { return (_alloc); }

		//T& at( const Key& key );
		//const T& at( const Key& key ) const;
		// T& operator[]( const Key& key );
		size_type size() const { return _size; }
		bool empty() const { return (!_size); }
		size_type max_size() const { return (_alloc.max_size());}
		
		// void clear();
		// ft::pair<iterator, bool> insert( const value_type& value ); 
		
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

		private:
		
			typedef struct	s_node {
				struct s_node				*_left;
				struct s_node				*_right;
				ft::pair<const Key, T>		_data;
			}				t_node;

			typedef std::allocator<t_node> nodeAlloc;

			t_node 			*_tree;
			size_type		_size;
			compare			_comp;
			value_compare	_vComp(compare c);
			alloc			_alloc;
			nodeAlloc		_nodeAlloc;

			
    };	
	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs,
          map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }
	
	
} /* NAMESPACE FT */ 