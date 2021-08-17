/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexicographical_compare.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:02:41 by gdupont           #+#    #+#             */
/*   Updated: 2021/08/17 17:10:45 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXICOGRAPHICAL_COMPARE

#define FT_LEXICOGRAPHICAL_COMPARE

namespace ft {
	
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare(	InputIt1 first1, InputIt1 last1,
                            		InputIt2 first2, InputIt2 last2 ) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
        	if (*first2 < *first1) return false;
    	}
    	return ((first1 == last1) && (first2 != last2));
	}

	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare(	InputIt1 first1, InputIt1 last1,
                              		InputIt2 first2, InputIt2 last2, Compare comp ) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
			if (comp(*first1, *first2)) return true;
        	if (comp(*first2, *first1)) return false;
    	}
		return (first1 == last1) && (first2 != last2);
	}
	
} /* NAMESPACE FT */ 


# endif
