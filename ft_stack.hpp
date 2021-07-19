/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 08:41:22 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/12 15:14:37 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <unistd.h>
#include <iostream>
#include "vector.hpp"

namespace ft {
	
	template <typename T, class container = ft::vector <T> >
	class stack {
		public:
		explicit stack(const container_type& ctnr = container_type()) : _data(ctnr)  {  }
		private:

		container<T> 	_data;
		
		bool empty() const { return (_data.empty()); }
		size_type size() const { return (_data.size()); }
		value_type& top() { return (_data.back()); }
		const value_type& top() { return (_data.back()); } const;
		void push (const value_type& val) { return (_data.push_back(val)); };
		void pop() { _data.pop(); } ;
		
		friend bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs._data == rhs._data);
		}
		
		friend bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs._data != rhs._data);
		}

		friend bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs._data < rhs._data);
		}
		
		friend bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs._data <= rhs._data);
		}
		
		friend bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs._data > rhs._data);
		}
		
		friend bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs._data >= rhs._data);
		}	
	}
}	
