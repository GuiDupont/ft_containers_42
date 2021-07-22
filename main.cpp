/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/22 12:18:07 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <vector>
#include <algorithm>
#include "ft_reverse_iterator.hpp"

#define NBVECTOR 5

template<typename T>
void	printVec(std::vector<T> const & v, std::string s)
{
	std::cout << s << " ";
	for (typename std::allocator<T>::size_type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "\n";
}


template< typename T>
void	printVec(ft::vector<T> const & v, std::string s)
{
	std::cout << s << " ";
	for (typename std::allocator<T>::size_type i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "\n";
}


void myfunction (int &i) {  // function:
  i++;
}


int main(void)
{

	int array[20]; 
	for (int i = 0; i < 20; i++)
		array[i] = i + 1;
	
	std::vector<int> stdVec;
	std::vector<int> stdVec2(20);
	std::vector<int> stdVec3(20, 42);
	std::vector<int> stdVec4(&array[0], &array[19]);
	std::vector<int> stdVec5(stdVec3);

	ft::vector<int> ftVec;
	ft::vector<int> ftVec2(20);
	ft::vector<int> ftVec3(20, 42);
	ft::vector<int> ftVec4(&array[0], &array[19]);
	ft::vector<int> ftVec5(ftVec3);
	
	std::cout << "######### Let's test constructors and operator = #########" << std::endl << std::endl;
	printVec(stdVec, "StdVec : ");
	printVec(ftVec, "ftVec  : ");
	printVec(stdVec2, "StdVec2 : ");
	printVec(ftVec2, "ftVec2  : ");
	printVec(stdVec3, "StdVec3 : ");
	printVec(ftVec3, "ftVec3  : ");
	printVec(stdVec4, "StdVec4 : ");
	printVec(ftVec4, "ftVec4  : ");
	printVec(stdVec5, "stdVec5 : ");
	printVec(ftVec5, "ftVec5  : ");
	ftVec5 = ftVec4;
	stdVec5 = stdVec4;
	printVec(stdVec5, "stdVec5 aprés l'opération stdVec5 = stdVec4 : ");
	printVec(ftVec5, "ftVec5  aprés l'opération ftVec5 = ftVec4   : ");

	std::cout << std::endl << "######### Let's test various functions #########" << std::endl << std::endl;
	std::cout << "*stdVec4.begin() : " << *stdVec4.begin() << std::endl;
	std::cout << "*ftVec4.begin()  : " << *ftVec4.begin() << std::endl;
	std::cout << "*(stdVec4.end() - 1) : " << *(stdVec4.end() - 1) << std::endl;
	std::cout << "*(ftVec4.end() - 1)  : " << *(ftVec4.end() - 1) << std::endl;

	std::cout << "*stdVec4.rbegin() : " << * (stdVec4.rbegin()) << std::endl;
	std::cout << "*ftVec4.rbegin()  : " << *(ftVec4.rbegin()) << std::endl;
	std::cout << "*(stdVec4.rend()- 1) : " << *(stdVec4.rend()- 1) << std::endl;
	std::cout << "*(ftVec4.rend() - 1) : " << *(ftVec4.rend() - 1) << std::endl;
	
	std::cout << "stdVec4.front() : " << stdVec4.front() << std::endl;
	std::cout << "ftVec4.front()  : " << ftVec4.front() << std::endl;
	std::cout << "stdVec4.back() : " << stdVec4.back() << std::endl;
	std::cout << "ftVec4.back()  : " << ftVec4.back() << std::endl;

	for (int i = 0; i < 10; i++)
	{
		stdVec4.push_back(i + 346);
		ftVec4.push_back(i + 346);
	}
	printVec(stdVec4, "StdVec4 aprés quelques push back : ");
	printVec(ftVec4, "ftVec4  aprés quelques push back : ");
	for (int i = 0; i < 5; i++)
	{
		stdVec4.pop_back();
		ftVec4.pop_back();
	}
	printVec(stdVec4, "StdVec4 aprés quelques pop back :  ");
	printVec(ftVec4, "ftVec4  aprés quelques pop back :  ");
	std::cout << "On affiche le vector grace à l'opérateur [] : " << std::endl;
	for (int i = 0; i < static_cast<int>(stdVec4.size()); i++)
		std::cout << stdVec4[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < static_cast<int>(ftVec4.size()); i++)
		std::cout << ftVec4[i] << " ";
	std::cout << std::endl;
	std::cout << "On affiche le vector grace à la fonction at : " << std::endl;
	for (int i = 0; i < static_cast<int>(stdVec4.size()); i++)
		std::cout << stdVec4.at(i) << " ";
	std::cout << std::endl;
	for (int i = 0; i < static_cast<int>(ftVec4.size()); i++)
		std::cout << ftVec4.at(i) << " ";
	std::cout << std::endl;
	std::cout << "Maintenant on utilise at avec un index hors des linites" << std::endl;
	try
	{
		stdVec4.at(200);
	}
	catch (const std::exception & e)
	{
		std::cout << "Std exception message: " << e.what() << std::endl;
	}
	try
	{
		ftVec4.at(200);
	}
	catch (const std::exception & e)
	{
		std::cout << "My exception message: " << e.what() << std::endl;
	}
	stdVec2.insert(stdVec2.begin() + 5, 244);
	ftVec2.insert(ftVec2.begin() + 5, 244);
	printVec(stdVec2, "StdVec2 aprés un insert de la valeur 244 à l'index 5: ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2  aprés un insert de la valeur 244 à l'index 5: ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;
	stdVec2.insert(stdVec2.begin() + 18, 20 ,666);
	ftVec2.insert(ftVec2.begin() + 18, 20, 666);
	printVec(stdVec2, "StdVec2 aprés un insert de la valeur 666, 20 fois à partir de l'index 18: ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2  aprés un insert de la valeur 666, 20 fois à partir de l'index 18: ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;
	stdVec2.insert(stdVec4.begin() + 12, ftVec4.begin() + 8, ftVec4.begin() + 18);
	ftVec2.insert(ftVec4.begin() + 12, stdVec4.begin() + 8, stdVec4.begin() + 18);
	// printVec(stdVec2, "StdVec2 aprés un insert de la valeur 666, 20 fois à partir de l'index 18: ");
	// std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	// printVec(ftVec2, "ftVec2  aprés un insert de la valeur 666, 20 fois à partir de l'index 18: ");
	// std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;
	

	

	
// 	std::vector<int> them(5);
// 	std::vector<int> them2(5, 5);
// 	std::vector<int> them3;
// 	std::vector<int> themSwap(6, 5);
	
// 	std::cout << "coucou\n";

// 	std::vector<int> *all = new std::vector<int>[NBVECTOR];
// 	all[0] = themEmpty;
// 	all[1] = themEmpty2;
// 	all[2] = them;
// 	all[3] = them2;
// 	all[4] = them3;

// 	std::cout << "coucou\n";

// 	ft::vector<int> mineEmpty;
// 	ft::vector<int> mineEmpty2;
// 	ft::vector<int> mine(5);
// 	ft::vector<int> mine2(5, 5);
// 	std::cout << "coucou\n";
// 	ft::vector<int> mine3;
// 	std::cout << "coucou1\n";
// 	ft::vector<int> mineSwap(6, 5);
// std::cout << "coucou2\n";

// 	ft::vector<int> *mineAll = new ft::vector<int>[NBVECTOR];
// 	mineAll[0] = mineEmpty;
// 	mineAll[1] = mineEmpty2;
// 	mineAll[2] = mine;
// 	mineAll[3] = mine2;
// 	mineAll[4] = mine3;

	
// 	for (int i = 0; i < NBVECTOR - 1; i++)
// 	{
// 		std::cout << "###########################\n";
// 		printVec(all[i], "\nVec at the begining: ");
// 		if(all[i].size())
// 		{
// 			all[i].pop_back();
// 			printVec(all[i], "Aprés un pop back =: ");
// 			std::cout	<< "aprés le pop back, size = " << all[i].size() 
// 				<< " capacity = " << all[i].capacity() << std::endl;
// 		}
// 		all[i].push_back(6);
// 		printVec(all[i], "Aprés un push back =: ");
// 		std::cout	<< "aprés le push back, size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		all[i].clear();
// 		printVec(all[i], "Aprés un clear =: ");
// 		std::cout	<< "aprés le clear, size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		all[i].assign(5, 0);
// 		printVec(all[i], "Aprés un assign de 5 0=: ");
// 		std::cout	<< "aprés le assign, size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		all[i].assign(5 * i + 5, i);
// 		printVec(all[i], "Aprés un assign: ");
// 		std::cout	<< "aprés le assign, size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		printVec(all[i], "Avant le swap A: ");
// 		printVec(themSwap, "Avant le swap B: ");
// 		all[i].swap(themSwap);
// 		printVec(all[i], "Apres le swap A: ");
// 		printVec(themSwap, "Apres le swap B: ");
// 		std::cout	<< "aprés le swap, A: size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		std::cout	<< "aprés le swap, B: size = " << themSwap.size() 
// 			<< " capacity = " << themSwap.capacity() << std::endl;
// 		all[i].resize(12, 4);
// 		printVec(all[i], "apres le resize 12 4: ");
// 		std::cout	<< "aprés le resize: size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		all[i].resize(20);
// 		printVec(all[i], "apres le resize 20: ");
// 		std::cout	<< "aprés le resize: size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		std::cout << "max size = " << all[i].max_size() << std::endl;
// 		std::cout << "empty= " << all[i].empty() << std::endl;
// 		if (i % 2)
// 		{
// 			all[i].clear();
// 			std::cout << "clear done " ;
			
// 		}
// 		std::cout << "empty= " << all[i].empty() << std::endl;
// 		all[i].reserve(i * 10);
// 		std::cout	<< "Aprés le reserve de " << i * 10 << " : size = " << all[i].size() 
// 			<< " capacity = " << all[i].capacity() << std::endl;
// 		if (i < NBVECTOR - 2)
// 			std::cout << "inequality : all[i] < all[i + 1] " << (all[i] < all[i + 1]) << "\n";

// 		std::cout << "--------------------------\n";

// 		printVec(mineAll[i], "\nVec at the begining: ");
// 		if(mineAll[i].size())
// 		{
// 			mineAll[i].pop_back();
// 			printVec(mineAll[i], "Aprés un pop back =: ");
// 			std::cout	<< "aprés le pop back, size = " << mineAll[i].size() 
// 				<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		}
// 		mineAll[i].push_back(6);
// 		printVec(mineAll[i], "Aprés un push back =: ");
// 		std::cout	<< "aprés le push back, size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		mineAll[i].clear();
// 		printVec(mineAll[i], "Aprés un clear =: ");
// 		std::cout	<< "aprés le clear, size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		mineAll[i].assign(5, 0);
// 		printVec(mineAll[i], "Aprés un assign de 5 0=: ");
// 		std::cout	<< "aprés le assign, size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		mineAll[i].assign(5 * i + 5, i);
// 		printVec(mineAll[i], "Aprés un assign: ");
// 		std::cout	<< "aprés le assign, size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		printVec(mineAll[i], "Avant le swap A: ");
// 		printVec(mineSwap, "Avant le swap B: ");
// 		mineAll[i].swap(mineSwap);
// 		printVec(mineAll[i], "Apres le swap A: ");
// 		printVec(mineSwap, "Apres le swap B: ");
// 		std::cout	<< "aprés le swap, A: size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		std::cout	<< "aprés le swap, B: size = " << mineSwap.size() 
// 			<< " capacity = " << mineSwap.capacity() << std::endl;
// 		mineAll[i].resize(12, 4);
// 		printVec(mineAll[i], "apres le resize 12 4: ");
// 		std::cout	<< "aprés le resize: size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		mineAll[i].resize(20);
// 		printVec(mineAll[i], "apres le resize 20: ");
// 		std::cout	<< "aprés le resize: size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		std::cout << "max size = " << mineAll[i].max_size() << std::endl;
// 		std::cout << "empty= " << mineAll[i].empty() << std::endl;
// 		if (i % 2)
// 		{
// 			mineAll[i].clear();
// 			std::cout << "clear done " ;
			
// 		}
// 		std::cout << "empty= " << mineAll[i].empty() << std::endl;
// 		mineAll[i].reserve(i * 10);
// 		std::cout	<< "Aprés le reserve de " << i * 10 << " : size = " << mineAll[i].size() 
// 			<< " capacity = " << mineAll[i].capacity() << std::endl;
// 		if (i < NBVECTOR - 2)
// 			std::cout << "inequality : mineAll[i] < mineAll[i + 1] " << (mineAll[i] < mineAll[i + 1]) << "\n";

// 		mineAll[i].assign(i*3,i);
// 		for (ft::vector<int>::iterator it = mineAll[i].begin(); it != mineAll[i].end(); it++)
// 			std::cout << *it << " ";
// 		std::cout << "\n###########################\n";
		
// 	}

// 	ft::vector<int> a(5);
// 	a.push_back(0);
// 	a.push_back(1);
// 	a.push_back(2);
// 	a.push_back(3);
// 	a.push_back(4);
// 	std::vector<int> c(5);
// 	c.push_back(0);
// 	c.push_back(1);
// 	c.push_back(2);
// 	c.push_back(3);
// 	c.push_back(4);
// 	ft::vector<int> b(5);
// 	b.insert(b.begin(), a.begin(), a.end());
// 	b.insert(b.begin() + 2, 3, 3);
// 	c.insert(c.begin() + 2, 3, 3);
// 	c.insert(c.begin(), c.begin(), c.end());
// 	printVec(b, "\nLe vecteur b: ");
// 	delete [] all;
// 	delete [] mineAll;
	
}


