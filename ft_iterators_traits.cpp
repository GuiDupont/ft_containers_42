/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterators_traits.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:27:11 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/19 16:53:56 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATORS_TRAITS

# define FT_ITERATORS_TRAITS

namespace ft {

	template<typename iterator>
    struct iterator_traits
    {
        
        typedef typename iterator::iterator_category    iterator_category;
        typedef typename iterator::value_type           value_type;
        typedef typename iterator::difference_type    difference_type;
        typedef typename iterator::pointer            pointer;
        typedef typename iterator::reference          reference;
    };



} /* NAMESPACE FT */ 

#endif