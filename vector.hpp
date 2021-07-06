/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 08:41:22 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/06 15:35:56 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>

namespace ft {

	template <typename T, class A = std::allocator<T> >
	class vector : public A {
	public:
		typedef A allocator_type;
		typedef typename A::value_type value_type; 
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type size_type;
		

		// class iterator { 
		// public:
		// 	typedef typename A::difference_type difference_type;
		// 	typedef typename A::value_type value_type;
		// 	typedef typename A::reference reference;
		// 	typedef typename A::pointer pointer;
		// 	typedef std::random_access_iterator_tag iterator_category;

		// 	iterator();
		// 	iterator(const iterator&);
		// 	~iterator();

		// 	iterator& operator=(const iterator&);
		// 	bool operator==(const iterator&) const;
		// 	bool operator!=(const iterator&) const;
		// 	bool operator<(const iterator&) const;
		// 	bool operator>(const iterator&) const;
		// 	bool operator<=(const iterator&) const;
		// 	bool operator>=(const iterator&) const;

		// 	iterator& operator++();
		// 	iterator operator++(int);
		// 	iterator& operator--();
		// 	iterator operator--(int);
		// 	iterator& operator+=(size_type);
		// 	// iterator operator+(size_type) const;
		// 	// friend iterator operator+(size_type, const iterator&); //optional
		// 	iterator& operator-=(size_type);           
		// 	iterator operator-(size_type) const;
		// 	// difference_type operator-(iterator) const; //optional

		// 	reference operator*() const;
		// 	// pointer operator->() const;
		// 	reference operator[](size_type) const;
		// };
		// class const_iterator {
		// public:
		// 	typedef typename A::difference_type difference_type;
		// 	typedef typename A::value_type value_type;
		// 	typedef typename const A::reference reference;
		// 	typedef typename const A::pointer pointer;
		// 	typedef std::random_access_iterator_tag iterator_category;

		// 	const_iterator ();
		// 	const_iterator (const const_iterator&);
		// 	const_iterator (const iterator&);
		// 	~const_iterator();

		// 	const_iterator& operator=(const const_iterator&);
		// 	bool operator==(const const_iterator&) const;
		// 	bool operator!=(const const_iterator&) const;
		// 	bool operator<(const const_iterator&) const;
		// 	bool operator>(const const_iterator&) const;
		// 	bool operator<=(const const_iterator&) const;
		// 	bool operator>=(const const_iterator&) const;

		// 	const_iterator& operator++();
		// 	const_iterator operator++(int);
		// 	const_iterator& operator--();
		// 	const_iterator operator--(int);
		// 	const_iterator& operator+=(size_type);
		// 	// const_iterator operator+(size_type) const; //optional
		// 	// friend const_iterator operator+(size_type, const const_iterator&); //optional
		// 	const_iterator& operator-=(size_type);           
		// 	// const_iterator operator-(size_type) const; //optional
		// 	// difference_type operator-(const_iterator) const; //optional

		// 	reference operator*() const;
		// 	// pointer operator->() const;
		// 	reference operator[](size_type) const;
		// };

		// typedef std::reverse_iterator<iterator> reverse_iterator; //optional
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator; //optional

		explicit vector (const A& alloc = allocator_type()) : _alloc(alloc), _nbElem(0), 
		_space(0) {
			std::cout << "J'alloue un vector vide\n";
			this->_buffer = this->_alloc.allocate(_space);
		} 
		//default
		
		explicit vector (size_type n, const value_type& val = value_type(), 
							const allocator_type& alloc = allocator_type()) : _alloc(alloc), _nbElem(n), _space(3 * n) {
			std::cout << "J'alloue un vector de " << n <<" elem\n";
			try
			{
				this->_buffer = this->_alloc.allocate(_space);
				for (size_type i = 0; i < n; i++) {
					this->_alloc.construct(this->_buffer + i, val);
				}
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
			}
		}

			//  fill (2)	
		// template <class T::iterator >
        // vector (InputIterator first, InputIterator last,
        //         const A& alloc = allocator_type()) : _alloc(alloc), _nbElem(5)
		// {
		// 	std::cout << "J'alloue un vector de " << last - first <<" elem a base d'un range\n";
		// 	try
		// 	{
		// 		this->_buffer = this->_alloc.allocate(last - first);
		// 		for (size_type i = 0; i < this->_nbElem; i++) {
		// 			std::advance(first, 1);
		// 			this->_alloc.construct(this->_buffer + i, first);
		// 		}
		// 	}
		// 	catch (std::exception & e)
		// 	{
		// 		std::cout << e.what() << std::endl;
		// 	}
		// } //range (3)	
		vector (const vector& x) : _alloc(x._alloc), _nbElem(x._nbElem) {
			std::cout << "J'alloue un vector de " << _nbElem <<" elem par copy\n";
			this->_buffer = this->_alloc.allocate(_nbElem);
			for (size_type i = 0; i < _nbElem; i++) {
					this->_alloc.construct(this->_buffer + i, x._buffer[i]);
				}
		} 
		//copy (4)	
		~vector() {
			std::cout << "je vais delete un vector de " << _nbElem << " elem \n";
			for (size_type i = 0; i < _nbElem; i++) {
					this->_alloc.destroy(this->_buffer + i);
				}
			this->_alloc.deallocate(this->_buffer, _nbElem);
		}

		vector& operator=(const vector& rhs) {
			for (size_type i = 0; i < _nbElem; i++) {
					this->_alloc.destroy(this->_buffer + i);
				}
			this->_alloc.deallocate(this->_buffer, _nbElem);
			_nbElem = rhs._nbElem;
			this->_buffer = this->_alloc.allocate(_nbElem);
			for (size_type i = 0; i < _nbElem; i++) {
					this->_alloc.construct(this->_buffer + i, rhs._buffer[i]);
				}
			return (*this);
		}
/////to delete---------------------------------------------------------------------------------------------
		size_type getNbElem(void) const { return (this->_nbElem); } 
		T const * getBuff(void) const{ return (this->_nbElem); } 
		void printSelf(void) {
			for (typename A::size_type i = 0; i < this->_nbElem; i++)
				std::cout << this->_buffer[i] << " "; }
/////to delete-------------------------------------------------------------------------------------
					
						

		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const; 
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;
		void push_back(const T&);
		// // void push_back (const value_type& val);
		// void pop_back();
		// reference operator[](size_type);
		// const_reference operator[](size_type) const;
		// reference at(size_type); 
		// const_reference at(size_type) const;

		// iterator insert(const_iterator, const T&); //single element
		// iterator insert(const_iterator, size_type, T&); //fill
		// template<class iter>
		// iterator insert(const_iterator, iter, iter); //range
		// iterator erase(const_iterator); //single elem
		// iterator erase(const_iterator, const_iterator); //range
		// void clear();
		// template<class iter>
		// void assign(iter, iter); //range 
		// void assign(size_type, const T&); //fill

		// void swap(vector&);
		// size_type size() const;
		// void resize (size_type, value_type val = value_type());
		// size_type max_size() const;
		// bool empty() const;
		// size_type capacity() const;
		// void reserve (size_type n);
		
		// A get_allocator() const;
		private:
			T *			_buffer;
			A			_alloc;
			size_type	_nbElem;
			size_type	_space;
	};
	
	// template <class T, class A = std::allocator<T> >
	// void swap(X<T,A>&, X<T,A>&);
	
	// template <class T, class Alloc>
	// bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <typename T, class A>
	// std::ostream & operator<<(std::ostream & o, const vector<T,A>& rhs) {
	// 	for (typename A::size_type i = 0; i < rhs.getNbElem(); i++)
	// 		o << (rhs.getBuff() + i) << " ";
	// 	return (o);
	// }
	
}



// https://stackoverflow.com/questions/7758580/writing-your-own-stl-container