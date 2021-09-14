/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:25:24 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/26 08:53:23 by gdupont          ###   ########.fr       */
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

}
#endif