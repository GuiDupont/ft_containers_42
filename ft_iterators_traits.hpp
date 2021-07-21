/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterators_traits.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:27:11 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/21 10:57:10 by gdupont          ###   ########.fr       */
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
        typedef typename iterator::difference_type    	difference_type;
        typedef typename iterator::pointer           	pointer;
        typedef typename iterator::reference          	reference;
    };

	/// Partial specialization for pointer types.
	 template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
      typedef std::random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef _Tp*                        pointer;
      typedef _Tp&                        reference;
    };

  /// Partial specialization for const pointer types.
  template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
      typedef std::random_access_iterator_tag iterator_category;
      typedef _Tp                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef const _Tp*                  pointer;
      typedef const _Tp&                  reference;
    };


} /* NAMESPACE FT */ 

#endif