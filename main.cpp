/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:01:31 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/06 15:38:58 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main(void)
{
	int a = 2;
	ft::vector<int> test2(3, a);
	ft::vector<int> test(test2);
	ft::vector<int> test3;

	test.printSelf();
	test2.printSelf();
	test3 = test;
	test3.printSelf();

}
