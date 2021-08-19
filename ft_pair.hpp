/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:00:32 by gdupont           #+#    #+#             */
/*   Updated: 2021/08/18 14:51:08 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR

# define FT_PAIR

namespace ft {

	template<class T1, class T2> 
	struct pair {
		public:
			typedef T1 first_type;
			typedef T2 second_type;
		
			pair() {}
			pair( const T1& x, const T2& y ) : first(x), second(y) { }
			
			template< class U1, class U2 >
			pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) { }
			pair( const pair& p ): first(p.first), second(p.second) { }
			
			T1 first;
			T2 second;

			pair& operator=( const pair& other ) { this->first = other.first; this->second = other.second;
												return (*this); }								
		
		private:
			pair *left;
			pair *right;
	}; //STRUCT PAIR

	/*
	** FT_PAIR NON-MEMBER FUNCTIONS
	*/

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u ) { return (pair<T1, T2>(t, u)); }
	
	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) 
										{ return (lhs.first == rhs.first && lhs.second == rhs.second); }
	
	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return (!(lhs == rhs)); }

	template< class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		if (lhs.first<rhs.first) 
			return (true);
		else if (rhs.first<lhs.first)
			return (false);
		else if (lhs.second<rhs.second)
			return (true);
		else
			return (false);
	}

	template< class T1, class T2 >
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return (!(rhs < lhs)); }

	template< class T1, class T2 >
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return (rhs < lhs); }
	
	template< class T1, class T2 >
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return (!(lhs < rhs)); }

} /* NAMESPACE FT */ 

#endif
