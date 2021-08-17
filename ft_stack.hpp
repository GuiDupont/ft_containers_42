/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 08:41:22 by gdupont           #+#    #+#             */
/*   Updated: 2021/08/12 15:09:37 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <unistd.h>
#include <iostream>
#include "ft_vector.hpp"

namespace ft {
	
	template <typename T, class container = ft::vector <T> >
	class stack {
		public:

		typedef typename container::allocator_type 	A;
		typedef container					container_type;
		typedef T 							value_type;
		typedef T* 							pointer;
		typedef const T* 					const_pointer;
		typedef T& 							reference;
		typedef const T& 					const_reference;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type 		size_type;
		
		explicit stack(const container_type& ctnr = container_type()) : _data(ctnr)  {  }

		bool empty() const { return (_data.empty()); }
		size_type size() const { return (_data.size()); }
		value_type& top() { return (_data.back()); }
		const value_type& top() const { return (_data.back()); } 
		void push (const value_type& val) { return (_data.push_back(val)); };
		void pop() { _data.pop(); } ;
		
		friend bool operator== (const ft::stack<T,container>& lhs, const ft::stack<T,container>& rhs) {
			return (lhs._data == rhs._data);
		}
		
		friend bool operator!= (const ft::stack<T,container>& lhs, const ft::stack<T,container>& rhs) {
			return (lhs._data != rhs._data);
		}

		friend bool operator<  (const ft::stack<T,container>& lhs, const ft::stack<T,container>& rhs) {
			return (lhs._data < rhs._data);
		}
		
		friend bool operator<= (const ft::stack<T,container>& lhs, const ft::stack<T,container>& rhs) {
			return (lhs._data <= rhs._data);
		}
		
		friend bool operator>  (const ft::stack<T,container>& lhs, const ft::stack<T,container>& rhs) {
			return (lhs._data > rhs._data);
		}
		
		friend bool operator>= (const ft::stack<T,container>& lhs, const ft::stack<T,container>& rhs) {
			return (lhs._data >= rhs._data);
		}

		protected:

		container 	_data;
	};
}
