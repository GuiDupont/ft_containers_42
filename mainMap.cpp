/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/29 15:04:58 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include "ft_stack.hpp"
#include "ft_pair.hpp"
#include <vector>
#include <algorithm>
#include "ft_reverse_iterator.hpp"
#include "ft_map.hpp"
#include <map>

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

	ftmap.insert(ft::pair<int, std::string>(16, "sal"));
	ftmap.insert(ft::pair<int, std::string>(20, "sal"));
	ftmap.printTree(NULL, 0);

	std::map<int, std::string> stdmap;
	stdmap.insert(std::pair<int, std::string>(14, "sal"));
	stdmap.insert(std::pair<int, std::string>(17, "salut"));
	
	stdmap.insert(std::pair<int, std::string>(11, "sal"));
	stdmap.insert(std::pair<int, std::string>(7, "sal"));

	stdmap.insert(std::pair<int, std::string>(53, "sal"));
	
	stdmap.insert(std::pair<int, std::string>(4, "sal"));

	stdmap.insert(std::pair<int, std::string>(13, "sal"));
	stdmap.insert(std::pair<int, std::string>(12, "sal"));
	stdmap.insert(std::pair<int, std::string>(8, "sal"));

	stdmap.insert(std::pair<int, std::string>(60, "sal"));

	stdmap.insert(std::pair<int, std::string>(19, "sal"));

	stdmap.insert(std::pair<int, std::string>(16, "sal"));

	stdmap.insert(std::pair<int, std::string>(20, "sal"));
	std::map<int, std::string>::iterator it = stdmap.end();
	while (it != stdmap.begin())
		std::cout << (--it)->first << std::endl;
	
	ft::map<int, std::string>::iterator it2 = ftmap.end();
	
	while (it2 != ftmap.begin())
	 	std::cout << (--it2)->first << std::endl;
	while (it2 != ftmap.end())
	 	std::cout << (it2++)->first << std::endl;
	while (it != stdmap.end())
	 	std::cout << (it++)->first << std::endl;
	ft::map<int, std::string>::const_reverse_iterator it3 = ftmap.rbegin();
	// std::cout << it3->second;
	
	std::cout << "my size = " << ftmap.size() << std::endl;
	std::cout << "my size = " << stdmap.size() << std::endl;

	std::map<int, std::string>::iterator it4 = stdmap.end();

	(void)it4;
	(void)it3;
}