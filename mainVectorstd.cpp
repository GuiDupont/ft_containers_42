
#include "ft_vector.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include "ft_enable_if.hpp"
#include "ft_reverse_iterator.hpp"

#define TESTED_NAMESPACE std
#define TESTED_TYPE int

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

class foo {
		public:
			foo(void) { };
			~foo(void) { };
			void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
			void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
			foo &operator=(int src) { this->value = src; return *this; };
			int getValue(void) const { return this->value; };
		private:
			int	value;
	};

	std::ostream	&operator<<(std::ostream &o, foo const &bar) {
		o << bar.getValue();
		return o;
	}

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
						TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
	{
		static int i = 0;
		std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
		printSize(vct);
	}


void	checkErase(std::vector<std::string> const &vct,
						std::vector<std::string>::const_iterator const &it)
	{
		static int i = 0;
		std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
		printSize(vct);
	}




void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
	{
		std::cout << "is_empty: " << vct.empty() << std::endl;
	}

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << "<  " << (first < second) << std::endl;
	std::cout << "<= " << (first <= second) << std::endl;
	std::cout << ">  " << (first > second) << std::endl;
	std::cout << ">= " << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

void	prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct)
	{
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

		std::cout << "Pre inc" << std::endl;
		it_tmp = ++it;
		std::cout << *it_tmp << " | " << *it << std::endl;

		std::cout << "Pre dec" << std::endl;
		it_tmp = --it;
		std::cout << *it_tmp << " | " << *it << std::endl;

		std::cout << "Post inc" << std::endl;
		it_tmp = it++;
		std::cout << *it_tmp << " | " << *it << std::endl;

		std::cout << "Post dec" << std::endl;
		it_tmp = it--;
		std::cout << *it_tmp << " | " << *it << std::endl;
		std::cout << "###############################################" << std::endl;
	}

int main()
{
	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

		
		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		for (unsigned long int i = 0; i < vct_two.size(); ++i)
			vct_two[i] = (vct_two.size() - i) * 5;
		printSize(vct);
		printSize(vct_two);

		vct_three.assign(vct.begin(), vct.end());
		vct.assign(vct_two.begin(), vct_two.end());
		vct_two.assign(2, 42);
		vct_four.assign(4, 21);

		std::cout << "\t### After assign(): ###" << std::endl;

		printSize(vct);
		printSize(vct_two);
		printSize(vct_three);
		printSize(vct_four);

		vct_four.assign(6, 84);
		printSize(vct_four);

		std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

		vct.assign(5, 53);
		vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

		printSize(vct);
		printSize(vct_two);

	}

	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printSize(vct);

		TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

		for (unsigned long int i = 0; i < vct_c.size(); ++i)
			std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
		try {
			std::cout << vct_c.at(10) << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
		printSize(vct_c);
	}

	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct.at(): " << vct.at(i) << " | ";
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printSize(vct);

		TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

		try {
			vct.at(10) = 42;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
	}


	{
		std::list<TESTED_TYPE> lst;
		std::list<TESTED_TYPE>::iterator lst_it;
		for (int i = 1; i < 5; ++i)
			lst.push_back(i * 3);

		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
		printSize(vct);

		lst_it = lst.begin();
		for (int i = 1; lst_it != lst.end(); ++i)
			*lst_it++ = i * 5;
		vct.assign(lst.begin(), lst.end());
		printSize(vct);

		vct.insert(vct.end(), lst.rbegin(), lst.rend());
		printSize(vct);
	}
	



	

	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

		std::cout << "len: " << (ite - it) << std::endl;
		for (; it != ite; ++it)
			*it = (ite - it);

		it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
		for (int i = 0; it != ite; ++it)
			*it = ++i * 5;

		it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
		for (int i = 0; it != ite; ++it)
			*it = ++i * 7;
		vct_copy.push_back(42);
		vct_copy.push_back(21);

		std::cout << "\t-- PART ONE --" << std::endl;
		printSize(vct);
		printSize(vct_range);
		printSize(vct_copy);

		vct = vct_copy;
		vct_copy = vct_range;
		vct_range.clear();

		std::cout << "\t-- PART TWO --" << std::endl;
		printSize(vct);
		printSize(vct_range);
		printSize(vct_copy);
	}



	{
		//#define TESTED_TYPE std::string
		std::vector<std::string> vct(10);

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = std::string((vct.size() - i), i + 65);
		printSize(vct);

		checkErase(vct, vct.erase(vct.begin() + 2));

		checkErase(vct, vct.erase(vct.begin()));
		checkErase(vct, vct.erase(vct.end() - 1));

		checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
		checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

		vct.push_back("Hello");
		vct.push_back("Hi there");
		printSize(vct);
		checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

		vct.push_back("ONE");
		vct.push_back("TWO");
		vct.push_back("THREE");
		vct.push_back("FOUR");
		printSize(vct);
		checkErase(vct, vct.erase(vct.begin(), vct.end()));

	}


	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
		const int cut = 3;

		std::cout << "BEGIN\n";

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		printSize(vct);

		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		printSize(vct2);
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		printSize(vct2);
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
		printSize(vct2);

		std::cout << "insert return:" << std::endl;

		std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
		std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
		std::cout << "----------------------------------------" << std::endl;

		printSize(vct2);
	}

	// single element (1)
	// 	iterator insert (iterator position, const value_type& val);

	// fill (2)
	// 	void insert (iterator position, size_type n, const value_type& val);

	// range (3)
	// 	template <class InputIterator>
	// 		void insert (iterator position, InputIterator first, InputIterator last);
	


	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		std::cout << "BEGIN - 2\n";
		printSize(vct);

		vct2.insert(vct2.end(), 42);


		vct2.insert(vct2.begin(), 2, 21); // exact

		printSize(vct2);

		vct2.insert(vct2.end() - 2, 42); // * 2;
		printSize(vct2);

		vct2.insert(vct2.end(), 2, 84); // exact mais _size + n == capacity
		printSize(vct2);

		vct2.resize(4);
		printSize(vct2);

		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end()); // exact
		vct.clear();
		printSize(vct2);

		printSize(vct);
	}


	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it(vct.begin());
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite(vct.end());

		for (int i = 1; it != ite; ++i)
			*it++ = i;
		printSize(vct, 1);

		it = vct.begin();
		ite = vct.begin();

		std::cout << *(++ite) << std::endl;
		std::cout << *(ite++) << std::endl;
		std::cout << *ite++ << std::endl;
		std::cout << *++ite << std::endl;

		//it->m();
		// ite->m();

		std::cout << *(++it) << std::endl;
		std::cout << *(it++) << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << *++it << std::endl;

		std::cout << *(--ite) << std::endl;
		std::cout << *(ite--) << std::endl;
		std::cout << *--ite << std::endl;
		std::cout << *ite-- << std::endl;

		// (*it).m();
		// (*ite).m();

		std::cout << *(--it) << std::endl;
		std::cout << *(it--) << std::endl;
		std::cout << *it-- << std::endl;
		std::cout << *--it << std::endl;

	}


	

	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;
		prepost_incdec(vct);

		it = it + 5;
		// it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
		std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		printSize(vct, true);
	}



	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_0(vct.begin());
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_1(vct.end());
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_mid;

		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit_0 = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit_1;
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit_mid;

		for (int i = size; it_0 != it_1; --i)
			*it_0++ = i;
		printSize(vct, 1);
		it_0 = vct.begin();
		cit_1 = vct.end();
		it_mid = it_0 + 3;
		cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

		std::cout << std::boolalpha;
		std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

		std::cout << "\t\tft_eq_ope:" << std::endl;
		// regular it
		ft_eq_ope(it_0 + 3, it_mid);
		//it_0 + 3 < it_mid;

		ft_eq_ope(it_0, it_1);
		ft_eq_ope(it_1 - 3, it_mid);
		// const it
		ft_eq_ope(cit_0 + 3, cit_mid);
		ft_eq_ope(cit_0, cit_1);
		ft_eq_ope(cit_1 - 3, cit_mid);
		// both it
		ft_eq_ope(it_0 + 3, cit_mid);
		ft_eq_ope(it_mid, cit_0 + 3);
		ft_eq_ope(it_0, cit_1);
		ft_eq_ope(it_1, cit_0);
		ft_eq_ope(it_1 - 3, cit_mid);
		ft_eq_ope(it_mid, cit_1 - 3);

	}



	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
		//TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

		for (int i = 0; i < size; ++i)
			it[i] = i;

	//	ite[1] = 42; // < -- error

	}


	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	//	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

		for (int i = 0; i < size; ++i)
			it[i] = i;

//		*ite = 42; // < -- error

	}


	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> const vct(size);
		// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(); // <-- error expected

		// for (int i = 0; i < size; ++i)
		// 	it[i] = i;

	}

	{
		std::vector<std::string> vct(8);
		std::vector<std::string> vct2;
		std::vector<std::string>::iterator it = vct.begin();

		for (unsigned long int i = 0; i < vct.size(); ++i)
			it[i] = std::string((vct.size() - i), i + 65);
		printSize(vct, true);

		std::cout << "push_back():\n" << std::endl;

		vct.push_back("One long string");
		vct2.push_back("Another long string");

		printSize(vct);
		printSize(vct2);

		vct.pop_back();
		vct2.pop_back();

		printSize(vct);
		printSize(vct2);

	}




	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(4);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct2(4);

		cmp(vct, vct);  // 0
		cmp(vct, vct2); // 1

		vct2.resize(10);

		cmp(vct, vct2); // 2
		cmp(vct2, vct); // 3

		vct[2] = 42;

		cmp(vct, vct2); // 4
		cmp(vct2, vct); // 5

		swap(vct, vct2);

		cmp(vct, vct2); // 6
		cmp(vct2, vct); // 7

	}


	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct;
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);

	
		// TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit_(crit);
		// TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit2(cit);
		// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it2(rit);
		//TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit2(crit);


		std::cout << "OK" << std::endl;
	}


	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		printSize(vct, true);
	}



	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(vct.rbegin());
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(vct.rend());

		for (int i = 1; it != ite; ++i)
			*it++ = (i * 7);
		printSize(vct, 1);

		it = vct.rbegin();
		ite = vct.rbegin();

		std::cout << *(++ite) << std::endl;
		std::cout << *(ite++) << std::endl;
		std::cout << *ite++ << std::endl;
		std::cout << *++ite << std::endl;

		// it->m();
		// ite->m();

		std::cout << *(++it) << std::endl;
		std::cout << *(it++) << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << *++it << std::endl;

		std::cout << *(--ite) << std::endl;
		std::cout << *(ite--) << std::endl;
		std::cout << *--ite << std::endl;
		std::cout << *ite-- << std::endl;

		// (*it).m();
		// (*ite).m();

		std::cout << *(--it) << std::endl;
		std::cout << *(it--) << std::endl;
		std::cout << *it-- << std::endl;
		std::cout << *--it << std::endl;

	}


	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

		for (int i = 0; i < size; ++i)
			vct[i] = (i + 1) * 5;
		printSize(vct);

		std::cout << (it_ == it.base()) << std::endl;
		std::cout << (it_ == (it + 3).base()) << std::endl;

		std::cout << *(it.base() + 1) << std::endl;
		std::cout << *(it - 3) << std::endl;
		std::cout << *(it - 3).base() << std::endl;
		it -= 3;
		std::cout << *it.base() << std::endl;

		std::cout << "TEST OFFSET" << std::endl;
		std::cout << *(it) << std::endl;
		std::cout << *(it).base() << std::endl;
		std::cout << *(it - 0) << std::endl;
		std::cout << *(it - 0).base() << std::endl;
		std::cout << *(it - 1).base() << std::endl;

	}


	

	{
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;

		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

		for (int i = size; it_0 != it_1; --i)
			*it_0++ = i;
		printSize(vct, 1);
		it_0 = vct.rbegin();
		cit_1 = vct.rend();
		it_mid = it_0 + 3;
		cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

		std::cout << std::boolalpha;
		std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

		std::cout << "\t\tft_eq_ope:" << std::endl;
		// regular it
		ft_eq_ope(it_0 + 3, it_mid);
		ft_eq_ope(it_0, it_1);
		ft_eq_ope(it_1 - 3, it_mid);
		// const it
		ft_eq_ope(cit_0 + 3, cit_mid);
		ft_eq_ope(cit_0, cit_1);
		ft_eq_ope(cit_1 - 3, cit_mid);
		// both it
		ft_eq_ope(it_0 + 3, cit_mid);
		ft_eq_ope(it_mid, cit_0 + 3);
		ft_eq_ope(it_0, cit_1);
		ft_eq_ope(it_1, cit_0);
		ft_eq_ope(it_1 - 3, cit_mid);
		ft_eq_ope(it_mid, cit_1 - 3);

	}


	{
		const int start_size = 7;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

		for (int i = 2; i < start_size; ++i)
			it[i] = (start_size - i) * 3;
		printSize(vct, true);

		vct.resize(10, 42);
		printSize(vct, true);

		vct.resize(18, 43);
		printSize(vct, true);
		vct.resize(10);
		printSize(vct, true);
		vct.resize(23, 44);
		printSize(vct, true);
		vct.resize(5);
		printSize(vct, true);
		vct.reserve(5);
		vct.reserve(3);
		printSize(vct, true);
		vct.resize(87);
		vct.resize(5);
		printSize(vct, true);

		is_empty(vct2);
		vct2 = vct;
		is_empty(vct2);
		vct.reserve(vct.capacity() + 1);
		printSize(vct, true);
		printSize(vct2, true);

		vct2.resize(0);
		is_empty(vct2);
		printSize(vct2, true);
	}



	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
		TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);
		
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

		std::cout << "BEFORE SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		foo.swap(bar);

		std::cout << "AFTER SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		std::cout << "Iterator validity:" << std::endl;
		std::cout << (it_foo == bar.begin()) << std::endl;
		std::cout << (it_bar == foo.begin()) << std::endl;

	}

	return (0);

}