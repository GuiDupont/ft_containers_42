/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 08:41:22 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/14 09:05:42 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstddef>
#include <iterator>

#include <unistd.h>

#define REALLOC_MULT 2


namespace ft {
	
	template <typename T>
		class vector {
			public:
				typedef std::allocator<T> A;
				typedef T valueType;
				typedef T* pointer;
				typedef const T* const_pointer;
				typedef T& reference;
				typedef const T& const_reference;
				typedef ptrdiff_t difference_type;
				typedef A allocator_type;
				typedef typename A::size_type size_type;				
				
				//typedef typename A::difference_type difference_type;
				class iterator { 
					public:
						
						typedef std::random_access_iterator_tag iterator_category;
						
						
						iterator(T* ptr) : _ptr(ptr) {}
						iterator(vector const & lhs) : _ptr(lhs._buffer) {}
						iterator(void) : _ptr(NULL) {}
						iterator& operator++() 
						{
							_ptr++;
							return (*this);
						}

						iterator& operator=(reference lhs) 
						{ this->_ptr = lhs->_ptrl; return (*this); }
						
						iterator& operator+=(int n)
						{
							this->_ptr += n;
							return (*this);
						}

						iterator& operator-=(int n)
						{
							this->_ptr -= n;
							return (*this);
						}

						iterator operator++(int) 
						{
							iterator it = *this;
							++(*this);
							return (it);
						}

						iterator operator+(int n) 
						{
							pointer it = _ptr;
							if (n < 0)
								for (int i = 0; i > n; i--)
									it--;
							else
								for (int i = 0; i < n; i++)
									it++;
							return (iterator(it));
						}

						iterator operator-(int n) 
						{
							pointer it = _ptr;
							if (n < 0)
								for (int i = 0; i > n; i--)
									it++;
							else
								for (int i = 0; i < n; i++)
									it--;
							return (iterator(it));
						}

						iterator& operator--() 
						{
							_ptr--;
							return (*this);
						}
						
						iterator operator--(int) 
						{
							iterator iterator = *this;
							--(*this);
							return (iterator);
						}

						reference operator[](int index) { return (*(_ptr + index)); }
						
						pointer operator->() { return (_ptr); }

						reference operator*() { return (*_ptr); }

						bool operator==(const iterator &rhs) const { return (_ptr == rhs._ptr) ;}
						
						bool operator!=(const iterator &rhs) const { return (_ptr != rhs._ptr) ;}
				
					private:
						pointer _ptr;
			
				};

				
				// vector (class it, typename vector<T>::iterator last,  const A& alloc = allocator_type()) : _alloc(alloc)
				// {
				// 	std::cout << "gdgdfsgdsgsd\n";
				// 	std::cout << *first << " " << *last << "\n";
				// 	//distance(first, last);
				// 	// this->_buffer = this->_alloc.allocate(distance(last, first));
				// 	// 	for (inputiterator it = first; it != last; it++) {
				// 	// 		this->_alloc.construct(this->_buffer + (it - first), *inputiterator );
				// 	// 		_size++;
				// 	// 	}
				// 	// }
				// 	// catch (std::exception & e)
				// 	// {
				// 	// 	std::cout << e.what() << std::endl;
				// 	// }
				// } //range (3)
				
				explicit vector (const A& alloc = allocator_type()) : _alloc(alloc), _size(0), 
				_capacity(0) { this->_buffer = this->_alloc.allocate(_capacity); } 
				
				explicit vector (size_type n, const valueType& val = valueType(), 
									const allocator_type& alloc = allocator_type()) 
									: _alloc(alloc), _size(n), _capacity(n) {
					this->_buffer = this->_alloc.allocate(_capacity);
					for (size_type i = 0; i < n; i++) {
						this->_alloc.construct(this->_buffer + i, val);
					}
				}
	
				
					
				vector (const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {
					this->_buffer = this->_alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++) {
							_alloc.construct(this->_buffer + i, x._buffer[i]);
						}
				}
					
				~vector() {
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
				void printSelf(void) const {
					for (typename A::size_type i = 0; i < this->_size; i++)
						std::cout << this->_buffer[i] << " ";
					// std::cout << "size = " << _size << " - ";
					// std::cout << " capapcity = " << _capacity << "\n"; 
					std::cout << "-\n"; 
					
					}
		/////to delete-------------------------------------------------------------------------------------
							
								

				vector<T>::iterator begin() { return (iterator(_buffer)); }
				vector<T>::iterator end() { return (iterator(&_buffer[_size])); }
				
				// const_iterator begin() const;
				// const_iterator end() const;
				// reverse_iterator rbegin();
				// const_reverse_iterator rbegin() const; 
				// reverse_iterator rend();
				// const_reverse_iterator rend() const;

				reference front() { return (*_buffer); }
				// const_reference front() const;
				reference back() { return ( *(_buffer + _size - 1)) ; } 
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
				
				void resize (size_type n, valueType val = valueType()) {
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
				
				size_type max_size() const { return (_alloc.max_size()); }

				bool empty() const { return (!_size); }
				
				size_type capacity() const { return (_capacity); }
				
				void reserve (size_type n) {
					if (n > _capacity)
						reallocateNCopy(n);
				}
				
				A get_allocator() const { return (_alloc); }
				
				friend bool operator==(vector<T> const & lhs, vector<T> const & rhs) {
					if (lhs._size != rhs._size)
						return (0);
					for (typename A::size_type i = 0; i < lhs._size; i++)
						if (lhs._buffer[i] != rhs._buffer[i])
							return (0);
					return (1);
				}

				friend bool operator!=(const vector<T>& lhs, const vector<T>& rhs)  {
					if (lhs._size != rhs._size)
						return (1);
					for (typename A::size_type i = 0; i < lhs._size; i++)
						if (lhs._buffer[i] != rhs._buffer[i])
							return (1);
					return (0);
				}
				
				friend bool operator<(const vector<T>& lhs, const vector<T>& rhs) {
					for (size_type i = 0; i < lhs._capacity && i < rhs._capacity; i++)
					{
						if (lhs._buffer[i] < rhs._buffer[i])
							return (1);
						if (lhs._buffer[i] > rhs._buffer[i])
							return (0);
						if (i == lhs._size && i == rhs._size)
							return (0);
					}
					return (0);
				} /// a refaire
				
				friend bool operator>(const vector<T>& lhs, const vector<T>& rhs) {
					return (!(lhs < rhs));
				}
				
				friend bool operator<=(const vector<T>& lhs, const vector<T>& rhs) {
					return (lhs == rhs || lhs < rhs);
				}
				
				friend bool operator>=(const vector<T>& lhs, const vector<T>& rhs) {
					return (lhs == rhs || lhs > rhs);
					
				}
			
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

	template <class T>
	typename ft::vector<T>::difference_type distance(typename ft::vector<T>::iterator first, typename ft::vector<T>::iterator last) 
	{ 
		typename ft::vector<T>::difference_type n = 0;
		while (first != last)
		{
			n++;
			first++;
		}
		return (n);
	}

	template <class T, class distance>
	void advance(typename ft::vector<T>::iterator it, distance n) { it += n; }
	
}

// https://www.youtube.com/watch?v=F9eDv-YIOQ0

// https://stackoverflow.com/questions/7758580/writing-your-own-stl-container


