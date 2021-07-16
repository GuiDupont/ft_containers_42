/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespaceFt.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:52:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/15 14:56:03 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_FT

#define NAMESPACE_FT

namespace ft {
	template <bool, typename T = void>
	struct enable_if {};


	template <typename T>
	struct enable_if<true, T> {
	typedef T type;
	};


	template<typename _Iterator>
    struct iterator_traits
    {
      typedef typename _Iterator::iterator_category iterator_category;
    //   typedef typename _Iterator::value_type        value_type;
    //   typedef typename _Iterator::difference_type   difference_type;
    //   typedef typename _Iterator::pointer           pointer;
    //   typedef typename _Iterator::reference         reference;
    };



// 	  template<typename>
//     struct __is_integral_helper
//     : public false_type { };
//   _DEFINE_SPEC(0, __is_integral_helper, bool, true)
//   _DEFINE_SPEC(0, __is_integral_helper, char, true)
//   _DEFINE_SPEC(0, __is_integral_helper, signed char, true)
//   _DEFINE_SPEC(0, __is_integral_helper, unsigned char, true)
// #ifdef _GLIBCXX_USE_WCHAR_T
//   _DEFINE_SPEC(0, __is_integral_helper, wchar_t, true)
// #endif
//   _DEFINE_SPEC(0, __is_integral_helper, short, true)
//   _DEFINE_SPEC(0, __is_integral_helper, unsigned short, true)
//   _DEFINE_SPEC(0, __is_integral_helper, int, true)
//   _DEFINE_SPEC(0, __is_integral_helper, unsigned int, true)
//   _DEFINE_SPEC(0, __is_integral_helper, long, true)
//   _DEFINE_SPEC(0, __is_integral_helper, unsigned long, true)
//   _DEFINE_SPEC(0, __is_integral_helper, long long, true)
//   _DEFINE_SPEC(0, __is_integral_helper, unsigned long long, true)

//   /// is_integral
//   template<typename _Tp>
//     struct is_integral
//     : public integral_constant<bool, (__is_integral_helper<typename
// 				      remove_cv<_Tp>::type>::value)>
//     { };

}



#endif