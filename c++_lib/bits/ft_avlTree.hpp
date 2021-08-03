/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlTree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:49:25 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/30 12:59:50 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVLTREE_HPP
#define FT_AVLTREE_HPP

#include "ft_pair.hpp"


namespace ft {

	
	template <class key, class value>
	struct	s_node {

		typedef ft::pair<key, value> value_type;
		struct s_node				*parent;
		struct s_node				*left;
		struct s_node				*right;
		value_type					*data;
		int							height;
		int							balanceFactor;
	};



}

# endif