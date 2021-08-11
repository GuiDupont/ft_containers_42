/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/08/11 13:03:09 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include "ft_stack.hpp"
#include <vector>
#include <algorithm>
#include "ft_reverse_iterator.hpp"
// #include "ft_map.hpp"

#define NBVECTOR 5


#define TESTED_NAMESPACE ft
#define TESTED_TYPE int
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


template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = 1)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
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
	std::cout << "*(stdVec4.rend()- 1) : " << *(stdVec4.rend() - 1) << std::endl;
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
	std::cout << std::endl;
	std::cout << "Maintenant on utilise at avec un index hors des limites" << std::endl;
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
	
	stdVec2.insert(stdVec2.begin() + 4, ftVec4.begin() + 8, ftVec4.begin() + 18);
	ftVec2.insert(ftVec2.begin() + 4, stdVec4.begin() + 8, stdVec4.begin() + 18);
	printVec(stdVec2, "StdVec2 aprés un insert des valeurs allant de 8 à 18, à partir de l'index 4: ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2 aprés un insert des valeurs allant de 8 à 18, à partir de l'index 4:  ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;
	
	stdVec2.erase(stdVec2.begin() + 12);
	ftVec2.erase(ftVec2.begin() + 12);
	printVec(stdVec2, "StdVec2 aprés un erase à l'index 23 (valeur 17): ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2 aprés un erase à l'index 23 (valeur 17):  ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;
	
	stdVec2.erase(stdVec2.begin() + 12, stdVec2.begin() + 22);
	ftVec2.erase(ftVec2.begin() + 12, ftVec2.begin() + 22);
	printVec(stdVec2, "StdVec2 aprés un erase de l'index 12 à 22: ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2 aprés un erase de l'index 12 à 22:    ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;
	
	stdVec2.clear();
	ftVec2.clear();
	printVec(stdVec2, "StdVec2 aprés un clear: ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2 aprés un clear:    ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;

	
	stdVec2.assign(stdVec4.begin(), stdVec4.end());
	ftVec2.assign(ftVec4.begin(), ftVec4.end());
	printVec(stdVec2, "StdVec2 aprés un assign d'interval : ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2 aprés un assign d'interval :  ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;

	stdVec2.assign(20, 99);
	ftVec2.assign(20, 99);
	printVec(stdVec2, "StdVec2 aprés un assign de 20 fois 99 : ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2 aprés un assign de 20 fois 99 :  ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;

	stdVec2.swap(stdVec4);
	ftVec2.swap(ftVec4);
	printVec(stdVec2, "StdVec2 aprés le swap : ");
	std::cout << " Size = " << stdVec2.size() << " " << "| Capacity = " << stdVec2.capacity() << std::endl;
	printVec(ftVec2, "ftVec2 aprés le swap :  ");
	std::cout << " Size = " << ftVec2.size() << " " << "| Capacity = " << ftVec2.capacity() << std::endl;
	printVec(stdVec4, "StdVec4 aprés le swap : ");
	std::cout << " Size = " << stdVec4.size() << " " << "| Capacity = " << stdVec4.capacity() << std::endl;
	printVec(ftVec4, "ftVec4 aprés le swap :  ");
	std::cout << " Size = " << ftVec4.size() << " " << "| Capacity = " << ftVec4.capacity() << std::endl;

	std::cout << "Max size de stdVec2: " << stdVec2.max_size() << std::endl;
	std::cout << "Max size de ftVec2:  " << ftVec2.max_size() << std::endl;

	std::cout << "Empty() de stdVec2: " << stdVec2.empty() << std::endl;
	std::cout << "Empty() de ftVec2:  " << ftVec2.empty() << std::endl;

	stdVec5.clear();
	ftVec5.clear();
	
	std::cout << "Empty() de stdVec5: " << stdVec5.empty() << std::endl;
	std::cout << "Empty() de ftVec5:  " << ftVec5.empty() << std::endl;
	
	std::cout << "stdVec2 > stdVec4: " << (stdVec2 > stdVec4) << std::endl;
	std::cout << "ftVec2 > ftVec4:   " << (ftVec2 > ftVec4) << std::endl;
	
	std::cout << "stdVec2 == stdVec4: " << (stdVec2 == stdVec4) << std::endl;
	std::cout << "ftVec2 == ftVec4:   " << (ftVec2 == ftVec4) << std::endl;
	
	std::cout << "stdVec2 < stdVec4: " << (stdVec2 < stdVec4) << std::endl;
	std::cout << "ftVec2 < ftVec4:   " << (ftVec2 < ftVec4) << std::endl;

	std::cout << "stdVec2 != stdVec4: " << (stdVec2 != stdVec4) << std::endl;
	std::cout << "ftVec2 != ftVec4:   " << (ftVec2 != ftVec4) << std::endl;





	
}






