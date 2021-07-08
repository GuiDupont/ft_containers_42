/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/08 16:26:25 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
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
	std::vector<int, std::allocator<int> > themEmpty;
	std::vector<int> themEmpty2;
	std::vector<int> them(5);
	std::vector<int> them2(5, 5);
	std::vector<int> them3;
	std::vector<int> themSwap(6, 5);
	
	std::vector<int> *all = new std::vector<int>[NBVECTOR];
	all[0] = themEmpty;
	all[1] = themEmpty2;
	all[2] = them;
	all[3] = them2;
	all[4] = them3;

	ft::vector<int> mineEmpty;
	ft::vector<int> mineEmpty2;
	ft::vector<int> mine(5);
	ft::vector<int> mine2(5, 5);
	ft::vector<int> mine3;
	ft::vector<int> mineSwap(6, 5);


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


		std::cout << "###########################\n";
	}
	delete [] all;
	delete [] mineAll;

	
	// them3.push_back(6);
	// printVec(them3, "Vector de taille 5 aprés un push back =: ");
	// std::cout	<< "aprés le push back, size = " << them3.size() 
	// 			<< " capacity = " << them3.capacity() << std::endl;
	// themEmpty.push_back(6);
	// printVec(themEmpty, "Vector de taille 0 aprés un push back =: ");
	// std::cout	<< "aprés le push back, size = " << themEmpty.size() 
	// 			<< " capacity = " << themEmpty.capacity() << std::endl;
	
	// them3.clear();
	// printVec(them3, "Vector de taille 6 aprés un clear =: ");
	// std::cout	<< "aprés le clear, size = " << them3.size() 
	// 			<< " capacity = " << them3.capacity() << std::endl;



	
	// ///// 


	// printVec(mineEmpty, "An empty vector: ");
	// printVec(mine, "An empty vector de taille 5: ");
	// printVec(mine2, "Vector 5 sur 5: ");
	// mine3 = mine2;
	// printVec(mine3, "Vector 5 sur 5 par =: ");
	// mine3.push_back(6);
	// printVec(mine3, "Vector de taille 5 aprés un push back =: ");
	// std::cout	<< "aprés le push back, size = " << mine3.size() 
	// 			<< " capacity = " << mine3.capacity() << std::endl;
	// mineEmpty.push_back(6);
	// printVec(mineEmpty, "Vector de taille 0 aprés un push back =: ");
	// std::cout	<< "aprés le push back, size = " << mineEmpty.size() 
	// 			<< " capacity = " << mineEmpty.capacity() << std::endl;

	

	
}


// int main(void)
// {
// 	ft::vector<int> mine2(2);
// 	ft::vector<int> mine(mine2);
// 	ft::vector<int> mine3;
// 	ft::vector<int> mine4;


// 	std::vector<int> them2(5, 4);
// 	std::vector<int> them(them2);
// 	std::vector<int> them3(5);
// 	std::cout << "\n";


// 	// mine.push_back(1);
// 	// mine.push_back(2);
// 	// mine.push_back(3);

// 	// //std::cout << mine.capacity();

// 	// mine.push_back(4);
// 	// mine.push_back(5);
// 	// mine.push_back(6);
// 	// mine.push_back(7);
// 	// mine.push_back(8);
// 	// mine.pop_back();
// 	mine2.printSelf();
// 	mine3.printSelf();
// 	mine3.push_back(1);
// 	mine3.push_back(2);
// 	mine3.push_back(3);
// 	mine3.push_back(4);
// 	mine3.push_back(5);
// 	mine3.push_back(6);

// 	mine2.push_back(1);
// 	mine2.push_back(2);
// 	mine2.push_back(3);
// 	mine2.push_back(4);
// 	mine2.push_back(5);
// 	mine2.push_back(5);

	

// 	mine3.printSelf();
// 	//mine3.assign(17, 3);
// 	mine3.push_back(24);
// 	std::cout << "mine 3 : ";
// 	mine3.printSelf();
// 	std::cout << "mine 2 : ";
// 	mine2.printSelf();
	
// 	mine3.swap(mine2);
// 	std::cout << "mine 3 : ";
// 	mine3.printSelf();
// 	std::cout << "mine 2 : ";
// 	mine2.printSelf();
// 	mine2.resize(37);
// 	std::cout << "mine 2 : ";
// 	mine2.printSelf();
// 	// std::cout << mine[0] << mine[1] << mine[2]
// 	//  << mine[3]<< mine[4] << mine[5] << " ";
// 	std::cout << them3.capacity() << " ";
// 	printVec(them3, "them3 = ");
// 	them3.resize(200, 3);
// 	printVec(them3, "them3 = ");
// 	std::cout << them3.capacity();
	

// 	std::cout << " \n " << mine2.max_size() << " \n ";
// 	std::cout << them.max_size();
// 	std::cout << mine4.empty();
// 	std::cout << them.empty();

// 	mine = mine2;
// 	if (mine == mine2)
// 		std::cout << "ils sont egaux\n";
// 	if (mine == mine3)
// 		std::cout << "ils sont egaux\n";
// 	else
// 		std::cout << "ils sont pas egaux\n";
		
// 	printVec(them3, "before clean; ");
// 	printVec(them3, "before clean; ");
// 	them3.clear();
// 	them2.clear();

// 	printVec(them3, "after clean; ");
// 	printVec(them3,  "after clean: ");
	
// 	them3.push_back(1);
// 	them3.push_back(2);
// 	them3.push_back(3);
// 	them3.push_back(4);
// 	them3.push_back(5);
// 	them3.push_back(5);

// 	them2.push_back(1);
// 	them2.push_back(2);
// 	them2.push_back(3);
// 	them2.push_back(4);
// 	them2.push_back(5);
// 	them2.push_back(5);
// 	them2.push_back(7);


// 	std::cout << "\n" << (them3 < them2) << "\n";
// 	// std::cout << mine[0] << mine[1] << mine[2]
// 	//  << mine[3]<< mine[4] << mine[5] << mine[6] << mine[7] << mine[8];
// 	// mine.printSelf();
// 	// mine.clear();
// 	// mine.printSelf();
// 	// std::cout << them.capacity();
// 	// them.assign(10, 2);
// 	// std::cout << them[0] << them[1] << them[2]
// 	//   << them[3]<< them[4] << them[5] << them[6] << them[7];
// 	// std::cout << them.capacity();


// 	std::cout << "\n";


	
// 	// }

// // 
// }
