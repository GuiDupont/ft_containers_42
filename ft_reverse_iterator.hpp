/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:19:58 by gdupont           #+#    #+#             */
/*   Updated: 2021/08/18 11:56:01 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR
#define FT_REVERSE_ITERATOR

#include "ft_iterators_traits.hpp"

namespace ft {
	
	template<class iterator>
	class reverse_iterator : public std::iterator<typename iterator_traits<iterator>::iterator_category,
		      typename iterator_traits<iterator>::value_type,
		      typename iterator_traits<iterator>::difference_type,
		      typename iterator_traits<iterator>::pointer,
                      typename iterator_traits<iterator>::reference> {
						  
	protected:
		iterator 								_current;
    	typedef iterator_traits<iterator>		traits_type;

    public:
    	typedef iterator								iterator_type;
    	typedef typename traits_type::difference_type	difference_type;
    	typedef typename traits_type::pointer			pointer;
    	typedef typename traits_type::reference			reference;

		reverse_iterator() : _current() { }	

		explicit reverse_iterator(iterator x) : _current(x) { }
		
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ) : _current(other.base()) { }
		
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ) {	_current = other.base();
																			return (*this); }

		iterator_type base() const	{ return (_current); }
		
		reference operator*() const {	iterator temp = _current; 
										return (*(--temp)); }
		
		pointer operator->() const	{	_current.operator->(); }

		reference operator[](difference_type n) const {
			iterator it = _current;
			for (difference_type i = 0; i != -(-n - 1); i++, it--)
				;
			return (*it);
		}

		reverse_iterator& operator++() { --_current; return(*this); }

		reverse_iterator& operator--() {  ++_current; return(*this); }

		reverse_iterator operator++(int) { reverse_iterator temp = *this;
											_current--;
											return (temp); }

		reverse_iterator operator--(int) { reverse_iterator temp = *this;
											_current++;
											return (temp); }

		reverse_iterator operator+( difference_type n ) const { return reverse_iterator(_current - n); }						
		
		reverse_iterator operator-( difference_type n ) const { return reverse_iterator(_current + n); }
		
		reverse_iterator& operator+=( difference_type n ) { _current -= n; return (*this); }
		
		reverse_iterator& operator-=( difference_type n ) { _current += n; return (*this); }
	};
	
	template< class Iter >
	reverse_iterator<Iter>
    operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it ) {
		return reverse_iterator<Iter>(it.base() - n);
	}

	template< class Iter >
	typename reverse_iterator<Iter>::difference_type
    operator-( const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs ) {
		return (rhs.base() - lhs.base());
	}

	template< class IterL, class IterR >
	typename reverse_iterator<IterL>::difference_type
    operator-( const reverse_iterator<IterL>& lhs, const reverse_iterator<IterR>& rhs ) {
		return (rhs.base() - lhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() == rhs.base();
	}
	
	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() != rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() > rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() >= rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() < rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() <= rhs.base();
	}
}

#endif
