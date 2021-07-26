/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 08:29:18 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/26 08:52:09 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_TRAITS_H
#define FT_TYPE_TRAITS_H

namespace ft {

/* is_pointer */

	template <bool V>
	struct _value { static const bool value = V; };

	template <typename T>
	struct is_pointer : public _value<false> {};

	template <typename T>
	struct is_pointer<T *> : public _value<true> {};

/* has_iterator category */

template <class T>
	struct _has_iterator_category
	{
	private:
		struct _yes {char __c1; char __c2;};

		template <class U>
		static char _test(...);
		template <class U>
		static _yes _test(typename U::iterator_category * = NULL);

	public:
		static const bool value = sizeof(_test<T>(0)) == sizeof(_yes);
	};

/* is_input_iterator */

	template <bool, class T>
	struct _is_input_iterator
	{
		static const bool value = false;
	};

	template <class T>
	struct _is_input_iterator<true, T>
	{
	private:
		struct _yes {char _c1;char _c2;};

		static _yes _test(typename std::input_iterator_tag *);
		static char _test(...);

	public:
		static const bool value = sizeof(_test(static_cast<typename T::iterator_category *>(NULL))) == sizeof(_yes);
	};

	template <class T>
	struct is_input_iterator : public _value<_is_input_iterator<_has_iterator_category<T>::value, T>::value || is_pointer<T>::value> {};


// template <typename T>
// struct has_iterator_category {
//   // Types "yes" and "no" are guaranteed to have different sizes,
//   // specifically sizeof(yes) == 1 and sizeof(no) == 2.
//   typedef char yes[1];
//   typedef char no[2];

//   template <typename C>
//   static yes& test(typename C::iterator_category category *);

//   template <typename>
//   static no& test(...);

//   // If the "sizeof" of the result of calling test<T>(nullptr) is equal to
//   // sizeof(yes), the first overload worked and T has a nested type named
//   // foobar.
//   static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
// };


}

#endif