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
}



#endif