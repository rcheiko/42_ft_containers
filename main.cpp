/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:34:50 by rcheiko           #+#    #+#             */
/*   Updated: 2022/01/07 14:38:43 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Map.hpp"
//#include "Stack.hpp"
#include "Vector.hpp"

int main( void )
{
	ft::vector<int> first(5,3);
	ft::vector<int> second(10,1);
	for (int i = 0; i < 10; i++)
	{
		first.push_back(i);
	}

	//std::cout << first.max_size() << std::endl;
	//std::cout << first[4] << std::endl;
	//first.pop_back();
	//first.resize(16, 1);
	//first.reserve(50);
	//std::cout << "CAPACITY " << first.capacity() << std::endl;
	//first.clear();
	//first.swap(second);
	//std::cout << first.at(2) << std::endl;
	first.print();
	std::cout << "\n\n";
	second.print();
	return (0);
}
