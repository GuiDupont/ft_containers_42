/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:28:07 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/26 15:26:00 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>

#include "ft_pair.hpp"

namespace ft {
	
	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > 
    class map{
        
        public:

        typedef	Key	                                    key_type;
        typedef	T                                       mapped_type;
        typedef	ft::pair<const Key, T>                 value_type;
        typedef	std::size_t                             size_type;
        typedef	std::ptrdiff_t                          difference_type;
        typedef	Compare	                                key_compare;
        typedef	Alloc									allocator_type;
        typedef	value_type&								reference;
        typedef	const value_type&                       const_reference;
        typedef	typename Alloc::pointer  	     		pointer;
        typedef	typename Alloc::const_pointer           const_pointer;
       // typedef	LegacyBidirectionalIterator to value_type	iterator;
        //typedef	LegacyBidirectionalIterator to const value_type	const_iterator	;
        

        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
            
        };
        
        typedef	std::reverse_iterator<iterator>         reverse_iterator;
        typedef const iterator                          const_iterator;
        typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;

        
		
		
        
        map() left(NULL), right(NULL) {}
        explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) left(NULL), right(NULL) {}
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


		private:
        typedef struct s_node {
            struct s_node *_left;
            struct s_node *_right;
            ft::pair<const Key, T> _data;
        }               t_node;

		t_node 		_tree;
		size_type	_size;
    };
           
	
} /* NAMESPACE FT */ 