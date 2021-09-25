#include "map.hpp"
#include <string>
#include "ft_pair.hpp"
#include <stdio.h>
#include <map>
#include <vector>
#include <unistd.h>

#define NS_TESTED std

int main() {
	NS_TESTED::map<int, std::string> map1;
	std::vector<int> lis;
	srand(time(0));
	for (int i = 0; i != 10000; i++) {
		lis.push_back(i);
		//std::cout << lis[i] << std::endl;
	}

	for (std::vector<int>::iterator it = lis.begin(); it != lis.end(); it++) {
		map1.insert(NS_TESTED::pair<int, std::string>(*it, "salut"));
	}
int previous = -1;
	for (NS_TESTED::map<int, std::string>::iterator it = map1.begin(); it != map1.end(); it++) {
		if (previous == -1)
			previous = it->first;
		else if (previous >= it->first) {
			std::cout << "errorrrrrrrrr\n";
			return (0) ;
		}
		//std::cout << it->first << " ";
	}
	// map1.printTree();


}