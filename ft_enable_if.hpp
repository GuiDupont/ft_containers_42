/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:25:24 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/21 15:25:37 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENABLE_IF

# define FT_ENABLE_IF

namespace ft {

	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
	typedef T type;
	};

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

}
#endif