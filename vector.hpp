/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 08:41:22 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/07 16:13:42 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>

#include <unistd.h>

#define REALLOC_MULT 2

namespace ft {

	template <typename T, class A = std::allocator<T> >
	class vector {
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

		explicit vector (const A& alloc = allocator_type()) : _alloc(alloc), _size(0), 
		_capacity(0) {
			// std::cout << "J'alloue un vector vide\n";
			this->_buffer = this->_alloc.allocate(_capacity);
		} 
		//default
		
		explicit vector (size_type n, const value_type& val = value_type(), 
							const allocator_type& alloc = allocator_type()) 
							: _alloc(alloc), _size(n), _capacity(n) {
			// std::cout << "J'alloue un vector de " << n <<" elem\n";
			try
			{
				this->_buffer = this->_alloc.allocate(_capacity);
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
        //         const A& alloc = allocator_type()) : _alloc(alloc), _size(5)
		// {
		// 	std::cout << "J'alloue un vector de " << last - first <<" elem a base d'un range\n";
		// 	try
		// 	{
		// 		this->_buffer = this->_alloc.allocate(last - first);
		// 		for (size_type i = 0; i < this->_size; i++) {
		// 			std::advance(first, 1);
		// 			this->_alloc.construct(this->_buffer + i, first);
		// 		}
		// 	}
		// 	catch (std::exception & e)
		// 	{
		// 		std::cout << e.what() << std::endl;
		// 	}
		// } //range (3)
			
		vector (const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {
			// std::cout << "J'alloue un vector de " << _size <<" elem par copy\n";
			this->_buffer = this->_alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++) {
					_alloc.construct(this->_buffer + i, x._buffer[i]);
				}
		}//copy (4)
			
		~vector() {
			// std::cout << "je vais delete un vector de " << _size << " elem et de capacity " << _capacity << "\n";
			for (size_type i = 0; i < _size; i++) {
					this->_alloc.destroy(this->_buffer + i);
				}
			this->_alloc.deallocate(this->_buffer, _capacity);
		}

		vector& operator=(const vector& rhs) {
			reallocate(rhs._capacity);
			_size = rhs._size;
			for (size_type i = 0; i < _size; i++) {
					this->_alloc.construct(this->_buffer + i, rhs._buffer[i]);
				}
			return (*this);
		}
		
/////to delete---------------------------------------------------------------------------------------------
		size_type getNbElem(void) const { return (this->_size); } 
		T const * getBuff(void) const{ return (this->_size); } 
		void printSelf(void) {
			for (typename A::size_type i = 0; i < this->_size; i++)
				std::cout << this->_buffer[i] << " ";
			std::cout << "size = " << _size << " - ";
			std::cout << " capapcity = " << _capacity << "\n"; 
			std::cout << "\n"; 
			
				}
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
		void push_back(const T& value) {
			
			if (!_capacity)
			{
				_alloc.deallocate(this->_buffer, _capacity);
				_buffer = _alloc.allocate(1);
				_capacity++;
			}
			if (_capacity == _size)
				reallocateNCopy(_capacity * REALLOC_MULT);
			_alloc.construct(this->_buffer + _size, value);
			_size++;
				
		}
		
		void pop_back() {
			if (!_size)
				return ;
			_size--;
			_alloc.destroy(_buffer + _size);
		}
		
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
		void clear() {
			for (size_type i = 0; i < _size; i++) {
					this->_alloc.destroy(this->_buffer + i);
				}
			_size = 0;
		}
		// template<class iter>
		// void assign(iter, iter); //range 
		void assign(size_type n, const T& value) {
			T* substitute;
			
			if (n > _capacity)
			{
				substitute = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					substitute[i] = value;
					_alloc.destroy(_buffer + i);
				}
				_alloc.deallocate(_buffer, _capacity);
				_capacity = n;
				_buffer = substitute;
				_size = n;
			}
			else if (n > _size)
			{
				for (size_type i = 0; i < n; i++)
				{
					if (i < _size)
						_buffer[i] = value;
					else
						_alloc.construct(_buffer + i, value);
				}
				_size = n;
			}
			else
			{
				for (size_type i = 0; i < n; i++)
					_buffer[i] = value;
			}
				
		}

		void swap(vector &x) {
			T 			*temp;
			size_type 	temp_size;
			size_type 	temp_capacity;
			

			temp = x._buffer;
			temp_size = x._size;
			temp_capacity = x._capacity;
			x._buffer = _buffer;
			x._size = _size;
			x._capacity = _capacity;
			_buffer = temp;
			_size = temp_size;
			_capacity = temp_capacity;
		}
		size_type size() const { return (_size); }
		
		void resize (size_type n, value_type val = value_type()) {
			if (n < _size)
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_buffer + i);
			else 
			{
				if (n > _capacity)
					this->reallocateNCopy(n);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_buffer + i, val);
			}
			_size = n;	
		}
		
		size_type max_size() const {
   			
    		return (_alloc.max_size());
		}

		bool empty() const { return (!_size); }
		size_type capacity() const { return (_capacity); }
		
		void reserve (size_type n) {
			if (n > _capacity)
				reallocateNCopy(n);
		}
		
		A get_allocator() const { return (_alloc); }
		private:
			T *			_buffer;
			A			_alloc;
			size_type	_size;
			size_type	_capacity;

			void		reallocateNCopy(size_type n) {
				T* substitute;
			
				substitute = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					substitute[i] = _buffer[i];
					_alloc.destroy(_buffer + i);
				}
				_alloc.deallocate(_buffer, _capacity);
				_capacity = n;
				_buffer = substitute;
			}
			
			void		reallocate(size_type n) {
				T* substitute;
			
				substitute = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_buffer + i);
				_alloc.deallocate(_buffer, _capacity);
				_capacity = n;
				_buffer = substitute;
			}
	};
	
	template <class T>
	void swap(vector<T>& a, vector<T>& b) {
		a.swap(b);
	}
	
	// template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	
	
}



// https://stackoverflow.com/questions/7758580/writing-your-own-stl-container