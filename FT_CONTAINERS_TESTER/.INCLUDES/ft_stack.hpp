/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 08:41:22 by gdupont           #+#    #+#             */
/*   Updated: 2021/09/14 10:42:03 by gdupont          ###   ########.fr       */
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
		
		typedef container					container_type;
		typedef T 							value_type;
		typedef T* 							pointer;
		typedef const T* 					const_pointer;
		typedef T& 							reference;
		typedef const T& 					const_reference;
		
		explicit stack(const container_type& ctnr = container_type()) : _data(ctnr)  {  }

		bool 				empty() const { return (_data.empty()); }
		size_t				size() const { return (_data.size()); }
		reference			top() { return (_data.back()); }
		const_reference		top() const { return (_data.back()); } 
		void				push (const value_type& val) { return (_data.push_back(val)); };
		void 				pop() { _data.pop_back(); } ;
		
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
