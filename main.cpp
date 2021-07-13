/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/13 14:44:09 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.hpp"
#include <vector>

#define NBVECTOR 5

template< typename T>
void	printVec(std::vector<T> const & v, std::string s)
{
	std::cout << s;
	for (typename std::allocator<T>::size_type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "\n";
}


template< typename T>
void	printVec(ft::vector<T> const & v, std::string s)
{
	std::cout << s;
	v.printSelf();
}


int main(void)
{
	std::cout << "coucou\n";
	std::vector<int> themEmpty;
	std::vector<int> themEmpty2;
	std::vector<int> them(5);
	std::vector<int> them2(5, 5);
	std::vector<int> them3;
	std::vector<int> themSwap(6, 5);
	
	std::cout << "coucou\n";

	std::vector<int> *all = new std::vector<int>[NBVECTOR];
	all[0] = themEmpty;
	all[1] = themEmpty2;
	all[2] = them;
	all[3] = them2;
	all[4] = them3;

	std::cout << "coucou\n";

	ft::vector<int> mineEmpty;
	ft::vector<int> mineEmpty2;
	ft::vector<int> mine(5);
	ft::vector<int> mine2(5, 5);
	std::cout << "coucou\n";
	ft::vector<int> mine3;
	std::cout << "coucou1\n";
	ft::vector<int> mineSwap(6, 5);
std::cout << "coucou2\n";

	ft::vector<int> *mineAll = new ft::vector<int>[NBVECTOR];
	mineAll[0] = mineEmpty;
	mineAll[1] = mineEmpty2;
	mineAll[2] = mine;
	mineAll[3] = mine2;
	mineAll[4] = mine3;

	
	for (int i = 0; i < NBVECTOR - 1; i++)
	{
		std::cout << "###########################\n";
		printVec(all[i], "\nVec at the begining: ");
		if(all[i].size())
		{
			all[i].pop_back();
			printVec(all[i], "Aprés un pop back =: ");
			std::cout	<< "aprés le pop back, size = " << all[i].size() 
				<< " capacity = " << all[i].capacity() << std::endl;
		}
		all[i].push_back(6);
		printVec(all[i], "Aprés un push back =: ");
		std::cout	<< "aprés le push back, size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		all[i].clear();
		printVec(all[i], "Aprés un clear =: ");
		std::cout	<< "aprés le clear, size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		all[i].assign(5, 0);
		printVec(all[i], "Aprés un assign de 5 0=: ");
		std::cout	<< "aprés le assign, size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		all[i].assign(5 * i + 5, i);
		printVec(all[i], "Aprés un assign: ");
		std::cout	<< "aprés le assign, size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		printVec(all[i], "Avant le swap A: ");
		printVec(themSwap, "Avant le swap B: ");
		all[i].swap(themSwap);
		printVec(all[i], "Apres le swap A: ");
		printVec(themSwap, "Apres le swap B: ");
		std::cout	<< "aprés le swap, A: size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		std::cout	<< "aprés le swap, B: size = " << themSwap.size() 
			<< " capacity = " << themSwap.capacity() << std::endl;
		all[i].resize(12, 4);
		printVec(all[i], "apres le resize 12 4: ");
		std::cout	<< "aprés le resize: size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		all[i].resize(20);
		printVec(all[i], "apres le resize 20: ");
		std::cout	<< "aprés le resize: size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		std::cout << "max size = " << all[i].max_size() << std::endl;
		std::cout << "empty= " << all[i].empty() << std::endl;
		if (i % 2)
		{
			all[i].clear();
			std::cout << "clear done " ;
			
		}
		std::cout << "empty= " << all[i].empty() << std::endl;
		all[i].reserve(i * 10);
		std::cout	<< "Aprés le reserve de " << i * 10 << " : size = " << all[i].size() 
			<< " capacity = " << all[i].capacity() << std::endl;
		if (i < NBVECTOR - 2)
			std::cout << "inequality : all[i] < all[i + 1] " << (all[i] < all[i + 1]) << "\n";

		std::cout << "--------------------------\n";

		printVec(mineAll[i], "\nVec at the begining: ");
		if(mineAll[i].size())
		{
			mineAll[i].pop_back();
			printVec(mineAll[i], "Aprés un pop back =: ");
			std::cout	<< "aprés le pop back, size = " << mineAll[i].size() 
				<< " capacity = " << mineAll[i].capacity() << std::endl;
		}
		mineAll[i].push_back(6);
		printVec(mineAll[i], "Aprés un push back =: ");
		std::cout	<< "aprés le push back, size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		mineAll[i].clear();
		printVec(mineAll[i], "Aprés un clear =: ");
		std::cout	<< "aprés le clear, size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		mineAll[i].assign(5, 0);
		printVec(mineAll[i], "Aprés un assign de 5 0=: ");
		std::cout	<< "aprés le assign, size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		mineAll[i].assign(5 * i + 5, i);
		printVec(mineAll[i], "Aprés un assign: ");
		std::cout	<< "aprés le assign, size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		printVec(mineAll[i], "Avant le swap A: ");
		printVec(mineSwap, "Avant le swap B: ");
		mineAll[i].swap(mineSwap);
		printVec(mineAll[i], "Apres le swap A: ");
		printVec(mineSwap, "Apres le swap B: ");
		std::cout	<< "aprés le swap, A: size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		std::cout	<< "aprés le swap, B: size = " << mineSwap.size() 
			<< " capacity = " << mineSwap.capacity() << std::endl;
		mineAll[i].resize(12, 4);
		printVec(mineAll[i], "apres le resize 12 4: ");
		std::cout	<< "aprés le resize: size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		mineAll[i].resize(20);
		printVec(mineAll[i], "apres le resize 20: ");
		std::cout	<< "aprés le resize: size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		std::cout << "max size = " << mineAll[i].max_size() << std::endl;
		std::cout << "empty= " << mineAll[i].empty() << std::endl;
		if (i % 2)
		{
			mineAll[i].clear();
			std::cout << "clear done " ;
			
		}
		std::cout << "empty= " << mineAll[i].empty() << std::endl;
		mineAll[i].reserve(i * 10);
		std::cout	<< "Aprés le reserve de " << i * 10 << " : size = " << mineAll[i].size() 
			<< " capacity = " << mineAll[i].capacity() << std::endl;
		if (i < NBVECTOR - 2)
			std::cout << "inequality : mineAll[i] < mineAll[i + 1] " << (mineAll[i] < mineAll[i + 1]) << "\n";

		mineAll[i].assign(i*3,i);
		for (ft::vector<int>::iterator it = mineAll[i].begin(); it != mineAll[i].end(); it++)
			std::cout << *it << " ";
		std::cout << "\n###########################\n";
		
		
	}
	mineAll[3].clear();
	mineAll[3].push_back(1);
	mineAll[3].push_back(2);
	mineAll[3].push_back(3);
	mineAll[3].push_back(4);
	mineAll[3].push_back(5);

	all[3].clear();
	all[3].push_back(1);
	all[3].push_back(2);
	all[3].push_back(3);
	all[3].push_back(4);
	all[3].push_back(5);


	for (ft::vector<int>::iterator  it = mineAll[3].begin(); it != mineAll[3].end(); it++)
			std::cout << *it << " ";
	// ft::vector<int>::iterator it = mineAll[3].begin();
	// std::cout << (*it);

	// it = it + 2;
	// std::cout << (*it);

	// it = it + (-1);
	// std::cout << (*it);

	// it = it + 3;
	// std::cout << (*it);
	
	// it = it - 2;
	// std::cout << (*it);

	// it = it - (-1);
	// std::cout << (*it);
	distance(mineAll[3].begin(), mineAll[3].end());
	mineAll[3].printSelf();

//	ft::vector<int> test(mineAll[3].begin(), mineAll[3].end());
	std::cout << *(mineAll[3].end()) << mineAll[3].size();
	//test.printSelf();
	delete [] all;
	delete [] mineAll;	
}


