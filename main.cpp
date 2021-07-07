/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/07 16:46:13 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

template< typename T>
void	printVec(std::vector<T> const & v, std::string s)
{
	std::cout << s;
	for (typename std::allocator<T>::size_type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "\n";
}



int main(void)
{
	ft::vector<int> mine2(2);
	ft::vector<int> mine(mine2);
	ft::vector<int> mine3;
	ft::vector<int> mine4;


	std::vector<int> them2(5, 4);
	std::vector<int> them(them2);
	std::vector<int> them3(5);
	std::cout << "\n";


	// mine.push_back(1);
	// mine.push_back(2);
	// mine.push_back(3);

	// //std::cout << mine.capacity();

	// mine.push_back(4);
	// mine.push_back(5);
	// mine.push_back(6);
	// mine.push_back(7);
	// mine.push_back(8);
	// mine.pop_back();
	mine2.printSelf();
	mine3.printSelf();
	mine3.push_back(1);
	mine3.push_back(2);
	mine3.push_back(3);
	mine3.push_back(4);
	mine3.push_back(5);
	mine3.push_back(6);

	mine2.push_back(1);
	mine2.push_back(2);
	mine2.push_back(3);
	mine2.push_back(4);
	mine2.push_back(5);
	mine2.push_back(5);

	

	mine3.printSelf();
	//mine3.assign(17, 3);
	mine3.push_back(24);
	std::cout << "mine 3 : ";
	mine3.printSelf();
	std::cout << "mine 2 : ";
	mine2.printSelf();
	
	mine3.swap(mine2);
	std::cout << "mine 3 : ";
	mine3.printSelf();
	std::cout << "mine 2 : ";
	mine2.printSelf();
	mine2.resize(37);
	std::cout << "mine 2 : ";
	mine2.printSelf();
	// std::cout << mine[0] << mine[1] << mine[2]
	//  << mine[3]<< mine[4] << mine[5] << " ";
	std::cout << them3.capacity() << " ";
	printVec(them3, "them3 = ");
	them3.resize(200, 3);
	printVec(them3, "them3 = ");
	std::cout << them3.capacity();
	

	std::cout << " \n " << mine2.max_size() << " \n ";
	std::cout << them.max_size();
	std::cout << mine4.empty();
	std::cout << them.empty();

	mine = mine2;
	if (mine == mine2)
		std::cout << "ils sont egaux\n";
	if (mine == mine3)
		std::cout << "ils sont egaux\n";
	else
		std::cout << "ils sont pas egaux\n";
		
	printVec(them3, "before clean; ");
	printVec(them3, "before clean; ");
	them3.clear();
	them2.clear();

	printVec(them3, "after clean; ");
	printVec(them3,  "after clean: ");
	
	them3.push_back(1);
	them3.push_back(2);
	them3.push_back(3);
	them3.push_back(4);
	them3.push_back(5);
	them3.push_back(5);

	them2.push_back(1);
	them2.push_back(2);
	them2.push_back(3);
	them2.push_back(4);
	them2.push_back(5);
	them2.push_back(5);
	them2.push_back(7);


	std::cout << "\n" << (them3 < them2) << "\n";
	// std::cout << mine[0] << mine[1] << mine[2]
	//  << mine[3]<< mine[4] << mine[5] << mine[6] << mine[7] << mine[8];
	// mine.printSelf();
	// mine.clear();
	// mine.printSelf();
	// std::cout << them.capacity();
	// them.assign(10, 2);
	// std::cout << them[0] << them[1] << them[2]
	//   << them[3]<< them[4] << them[5] << them[6] << them[7];
	// std::cout << them.capacity();


	std::cout << "\n";


	
	// }

// 
}
