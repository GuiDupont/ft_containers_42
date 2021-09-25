
#include "map.hpp"
#include <string>
#include "ft_pair.hpp"
#include <stdio.h>
#include <map>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <iomanip>
// #include <sys/time.h>
// #include <ctime>


int g_erase = 0;
int main() {

	double diff_mine;
	double diff_std;
	double ratio;
	std::time_t begin;
	// struct timeval time_now{};
	// time_t msecs_time;


	ft::map<int, std::string>	mymap;
	std::map<int, std::string>	stdmap;

	std::vector<int> vec;
	srand(time(0));
	for (int i = 1000000; i != 0; i--) {
		vec.push_back(i);
	}


//////////////////////////////////////////////////////////////


// 	std::cout << "\nInsert 1 000 000 ordered numbers:       ";


//     begin = std::time(0);

// 	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
// 		mymap.insert(ft::pair<int, std::string>(*it, "salut"));
// 	}
// 	diff_mine = std::time(0) - begin;

// 	begin = std::time(0);
// 	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
// 		stdmap.insert(std::pair<int, std::string>(*it, "salut"));
// 	}
// 	diff_std = std::time(0) - begin;
// 	ratio = diff_mine/diff_std;
// 	std::cout << "STD is " << ratio << " times faster" << std::endl;


// //////////////////////////////////////////////////////////////


	vec.clear();
	mymap.clear();
	stdmap.clear();
	for (int i = 1000000; i != 0; i--) {
		vec.push_back(rand() % 1000000);
	}
	std::cout << "\nInsert 1 000 000 random numbers:       ";

	begin = std::time(0);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		mymap.insert(ft::pair<int, std::string>(*it, "salut"));
	}
	diff_mine = std::time(0) - begin;

	// begin = std::time(0);
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
	// 	stdmap.insert(std::pair<int, std::string>(*it, "salut"));
	// }
	// diff_std = std::time(0) - begin;

	// ratio = diff_mine/diff_std;
	// std::cout << "STD is " << ratio << " times faster" << std::endl;


//////////////////////////////////////////////////////////////


	// vec.clear();
	// for (int i = 1000000; i != 0; i--) {
	// 	vec.push_back(rand() % 1000000);
	// }
	// std::cout << "\nFind 1 000 000 random numbers       ";

	// begin = std::time(0);

	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
	// 	mymap.find(*it);
	// }
	// diff_mine = std::time(0) - begin;

	// begin = std::time(0);
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
	// 	stdmap.find(*it);
	// }
	// diff_std = std::time(0) - begin;
	// ratio = diff_mine/diff_std;
	// std::cout << "STD is " << ratio << " times faster" << std::endl;


////////////////////////////////////////////////////////////////////

	
	// std::cout << "\nDuplicating a map of 1 000 000 elem:       ";

	// begin = std::time(0);

	// ft::map<int, std::string>	newmap = mymap;

	// diff_mine = std::time(0) - begin;

	// begin = std::time(0);
	// std::map<int, std::string>	newstdmap = stdmap;

	// diff_std = std::time(0) - begin;
	// ratio = diff_mine/diff_std;
	// std::cout << "STD is " << ratio << " times faster" << std::endl;


////////////////////////////////////////////////////////////////////

	vec.clear();
	for (int i = 500000; i != 0; i--) {
		vec.push_back(rand() % 1000000);
	}
	g_erase =1 ;
	std::cout << "\nDeleting 500 000 random numbers:      \n ";

	begin = std::time(0);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		mymap.erase(*it);
	}
	diff_mine = std::time(0) - begin;

	begin = std::time(0);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		stdmap.erase(*it);
	}
	diff_std = std::time(0) - begin;
	ratio = diff_mine/diff_std;
	std::cout << "STD is " << ratio << " times faster" << std::endl;



	std::cout <<  "\nWe are emptying all this data\n";
	return (0);
}