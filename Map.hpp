/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:29:26 by rcheiko           #+#    #+#             */
/*   Updated: 2021/11/09 16:37:03 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <stack>

template <typename T>
class Map
{
	public:
		Map( void ){}

		Map( Map const & copy )
		{
			*this = copy;
		}
		
		~Map( void ){}

		Map &	operator=( Map const & copy)
		{
			(void) copy;
			return (*this);
		}
};

#endif
