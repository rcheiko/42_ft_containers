/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:29:26 by rcheiko           #+#    #+#             */
/*   Updated: 2021/11/09 16:36:55 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <stack>

template <typename T>
class Stack
{
	public:
		Stack( void ){}

		Stack( Stack const & copy )
		{
			*this = copy;
		}
		
		~Stack( void ){}

		Stack &	operator=( Stack const & copy)
		{
			(void) copy;
			return (*this);
		}
};

#endif
