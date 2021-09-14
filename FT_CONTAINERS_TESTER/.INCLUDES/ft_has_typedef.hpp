/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_typedef.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:33:25 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/22 21:34:27 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	template <typename T>
	struct has_typedef_random_iterator_tag {

	typedef char yes[1];
	typedef char no[2];

	template <typename C>
	static yes& test(typename C::foobar*);

	template <typename>
	static no& test(...);

	// If the "sizeof" of the result of calling test<T>(nullptr) is equal to
	// sizeof(yes), the first overload worked and T has a nested type named
	// foobar.
	static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};
}