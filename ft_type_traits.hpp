/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 08:29:18 by gdupont           #+#    #+#             */
/*   Updated: 2021/09/14 11:11:31 by gdupont          ###   ########.fr       */
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

}

#endif