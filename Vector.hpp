/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:29:26 by rcheiko           #+#    #+#             */
/*   Updated: 2021/11/18 14:42:51 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <stack>

template <typename T, typename _allocator = std::allocator<T> >
class vector
{
	public:
		typedef T						value_type;
		typedef T						&reference;
		typedef const T					&const_reference;
		typedef T				*pointer;
		typedef const T		*const_pointer;
		typedef size_t			size_type;
		typedef std::ptrdiff_t	difference_type;
		typedef _allocator				allocator_type;

		explicit vector (const allocator_type& alloc = _allocator()){}
//		Vector( ){}
		~vector( void ){}

		vector &	operator=( vector const & copy)
		{
			copy = *this;
			return (*this);
		}
};

#endif
