/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:29:26 by rcheiko           #+#    #+#             */
/*   Updated: 2021/12/07 15:45:24 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <string>
//# include <vector>
//# include <list>
//# include <algorithm>
# include <stack>
# include <memory>

template <typename T, typename _allocator = std::allocator<T> >
class vector : public std::allocator<T>
{
	private:
		size_t		_size;
		_allocator	_alloc;
		T			_value;
	public:
		typedef T								value_type;
		typedef T								&reference;
		typedef const T							&const_reference;
		typedef T								*pointer;
		typedef const T							*const_pointer;
		typedef size_t							size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef _allocator						allocator_type;
	/*	typedef std::iterator<iterator>			iterator;
		typedef std::reverse_iterator<std::iterator>			reverse_iterator;
		typedef std::reverse_iterator<std::const_iterator>	const_reverse_iterator;*/


		explicit vector (const allocator_type& alloc = _allocator()) : _alloc(alloc){}

		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : _size(n), _alloc(alloc), _value(val) {}
//		template <class InputIterator> vector (InputIterator first, InputIterator last,
//						const allocator_type& alloc = allocator_type()) {}
		~vector() {}

		vector (const vector& x){
			*this = x;
		}
		vector &	operator=( vector const & copy){
			_size = copy._size;
			_alloc = copy._alloc;
			_value = copy._value;
			return (*this);
		}

		size_type size() const{
			return (_size);
		}

		size_type max_size() const{
			return (1073741823);
		}

		bool empty() const{
			if (_size == 0)
				return (true);
			return (false);
		}


	/*	iterator begin(){
		
		}
		
		const_iterator begin() const{

		}*/

};

#endif
