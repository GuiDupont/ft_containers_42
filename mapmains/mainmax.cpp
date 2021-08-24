#include "map.hpp"
#include "map"

int main(void)
{
	std::cout << "sizeof(map): " << sizeof(ft::map<int, std::string>); 
	std::cout << "\nsizeof(map): " << sizeof(std::map<int, std::string>); 
	std::map<int, std::string> them;
	ft::map<int, std::string> mine;

	std::cout << "\n" << them.max_size();
	std::cout << "\n" << mine.max_size();

}