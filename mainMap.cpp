/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/28 15:13:42 by gdupont          ###   ########.fr       */
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
	ftmap.insert(ft::pair<int, std::string>(14, "sal"));
	ftmap.insert(ft::pair<int, std::string>(17, "salut"));
	//ftmap.printTree(NULL, 0);
	ftmap.insert(ft::pair<int, std::string>(11, "sal"));
	ftmap.insert(ft::pair<int, std::string>(7, "sal"));

	ftmap.printTree(NULL, 0);
	ftmap.insert(ft::pair<int, std::string>(53, "sal"));
	
	ftmap.printTree(NULL, 0);
	ftmap.insert(ft::pair<int, std::string>(4, "sal"));

	ftmap.printTree(NULL, 0);
	ftmap.insert(ft::pair<int, std::string>(13, "sal"));
	ftmap.printTree(NULL, 0);
	ftmap.insert(ft::pair<int, std::string>(12, "sal"));
	ftmap.printTree(NULL, 0);
	ftmap.insert(ft::pair<int, std::string>(8, "sal"));
	ftmap.printTree(NULL, 0);

	ftmap.insert(ft::pair<int, std::string>(60, "sal"));
	ftmap.printTree(NULL, 0);

	ftmap.insert(ft::pair<int, std::string>(19, "sal"));
	ftmap.printTree(NULL, 0);

	ftmap.insert(ft::pair<int, std::string>(16, "sal"));
	ftmap.printTree(NULL, 0);

	ftmap.insert(ft::pair<int, std::string>(20, "sal"));
	ftmap.printTree(NULL, 0);


	

	
}