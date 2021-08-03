/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlNODE.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:49:25 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/30 12:59:50 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVLNODE_HPP
#define FT_AVLNODE_HPP

#include "ft_pair.hpp"

namespace ft {

	
	template <class T>
	struct	s_node {

		struct s_node				*parent;
		struct s_node				*left;
		struct s_node				*right;
		T*							data;
		int							height;
		int							balanceFactor;

		s_node(void) : parent(NULL), left(NULL), right(NULL), data(NULL), height(0), balanceFactor(0) {} 
	};
}

# endif