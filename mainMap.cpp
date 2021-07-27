/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/27 15:59:29 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include "ft_stack.hpp"
#include "ft_pair.hpp"
#include <vector>
#include <algorithm>
#include "ft_reverse_iterator.hpp"
#include "ft_map.hpp"

int main()
{
	ft::map<int, std::string> ftmap;
	ftmap.insert(ft::pair<int, std::string>(4, "sal"));
	ftmap.insert(ft::pair<int, std::string>(10, "salut"));
	//ftmap.printTree(NULL, 0);
	ftmap.insert(ft::pair<int, std::string>(2, "sal"));
	ftmap.insert(ft::pair<int, std::string>(12, "sal"));

	ftmap.insert(ft::pair<int, std::string>(8, "sal"));
	std::cout << "ici\n";

	ftmap.printTree(NULL, 0);
	
	//ftmap.insert(ft::pair<int, std::string>(9, "sal"));
	//ftmap.insert(ft::pair<int, std::string>(43, "sal"));
	
	ftmap.printTree(NULL, 0);

	
}