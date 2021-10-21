/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testPerformanceVect.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:53:39 by gdupont           #+#    #+#             */
/*   Updated: 2021/09/27 23:57:46 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../vector.hpp"
#include <string>
#include "../ft_pair.hpp"
#include <stdio.h>
#include <map>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <stdlib.h>


int g_erase = 0;
int main() {

	double diff_mine;
	double diff_std;
	double ratio;
	std::time_t begin;
	

	ft::vector<int>		myvec;
	std::vector<int>	stdvec;

	std::vector<int> vec;
	srand(time(0));
	for (int i = 50000000; i != 0; i--) {
		vec.push_back(i);
	}


//////////////////////////////////////////////////////////////


	std::cout << "\npush_back 50 000 000 ordered numbers:       ";


    begin = std::time(0);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		myvec.push_back(*it);
	}
	diff_mine = std::time(0) - begin;

	begin = std::time(0);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		stdvec.push_back(*it);
	}
	diff_std = std::time(0) - begin;
	ratio = diff_mine/diff_std;
	std::cout << "STD is " << ratio << " times faster" << std::endl;


// //////////////////////////////////////////////////////////////

	std::cout << "\nInsert 30 000 000 numbers in the middle:       ";



	for (int i = 30000000; i != 0; i--) {
		vec.push_back(rand() % 1000000);
	}

	begin = std::time(0);

	
	myvec.insert(myvec.begin() + 25000000, vec.begin(), vec.end());
	
	diff_mine = std::time(0) - begin;

	myvec.clear();
	begin = std::time(0);
	stdvec.insert(stdvec.begin() + 25000000, vec.begin(), vec.end());
	diff_std = std::time(0) - begin;

	ratio = diff_mine/diff_std;
	std::cout << "STD is " << ratio << " times faster" << std::endl;


//////////////////////////////////////////////////////////////
}

// clang++ -g -fsanitize=address -Wall -Wextra -Werror --std=c++98 testPerformanceVect.cpp && ./a.out
