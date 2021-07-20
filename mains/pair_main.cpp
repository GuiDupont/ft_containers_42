#include "ft_pair.hpp"


int main(void)
{
	ft::pair<int, char> test;
	ft::pair<int, char> test2(12,'s');
	ft::pair<int, char> test3(test2);
	(void)test3;

	int n  = 1;
	int array[5] = {1, 2, 3, 4, 5};

	ft::pair<int, int>pair1 = ft::make_pair<int, int>(n, array[n]);
	(void)pair1;

}