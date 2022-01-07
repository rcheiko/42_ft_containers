/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:29:26 by rcheiko           #+#    #+#             */
/*   Updated: 2022/01/07 14:37:26 by rcheiko          ###   ########.fr       */
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
# include <cmath>

namespace ft
{
template <typename T, typename _allocator = std::allocator<T> >
class vector// : public std::allocator<T>
{
	public:
		typedef T								value_type;
		typedef T								&reference;
		typedef const T							&const_reference;
		typedef T								*pointer;
		typedef const T							*const_pointer;
		typedef size_t							size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef _allocator						allocator_type;
//		typedef std::iterator<iterator>			iterator;
//		typedef std::reverse_iterator<std::iterator>			reverse_iterator;
//		typedef std::reverse_iterator<std::const_iterator>	const_reverse_iterator;


		explicit vector (const allocator_type& alloc = _allocator()) : _size_alloc(0), _size_value(0), _alloc(alloc){}

		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : _size_value(n), _alloc(alloc)
		{
			int	i = 0;
			_size_alloc = 0;
			_size_value = 0;
			while (_size_alloc < n)
			{
				realloc();
			}
			_size_value = n;
			while (i < (int)_size_value)
			{
				_value[i] = val;
				i++;
			}
		}
//		template <class InputIterator> vector (InputIterator first, InputIterator last,
//						const allocator_type& alloc = allocator_type()) {}
		~vector()
		{
			for (size_type i = 0; i < _size_value; i++)
			{
				_alloc.destroy(&_value[i]);
			}
			_alloc.deallocate(_value, _size_alloc);
		}

		vector (const vector& x){
			*this = x;
		}

		vector &	operator=( vector const & copy){
			_size_alloc = copy._size_alloc;
			_size_value = copy._size_value;
			_alloc = copy._alloc;
			_value = copy._value;
			return (*this);
		}

		size_type	size() const{
			return (_size_value);
		}

		size_type	max_size() const{
			size_t i = pow(2,64) / sizeof(value_type);
			return (i - 1);
		}

		size_type capacity() const{
			return (_size_alloc);
		}

		bool	empty() const{
			if (_size_value == 0)
				return (true);
			return (false);
		}

		void	push_back(const value_type& val)
		{
			if (_size_alloc == 0)
			{
				_value = _alloc.allocate(1);
				_size_alloc++;
			}
			if (_size_value == _size_alloc)
				realloc();
			_alloc.construct(_value + _size_value, val);
			_size_value++;
		}

		void	pop_back()
		{
			if (_size_value == 0)
				return;
			else{
				_alloc.destroy(_value + (_size_value - 1));
				_size_value--;
			}
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (_size_value > n)
			{
				while (_size_value != n)
				{
					_alloc.destroy(_value + (_size_value - 1));
					_size_value--;
				}
				return;
			}
			else if (_size_alloc < n && (_size_alloc * 2) >= n)
			{
				realloc();
			}
			else if (_size_alloc < n && (_size_alloc * 2) < n)
			{
				T	*new_value = NULL;
				new_value = _alloc.allocate(n);
				_size_alloc = n;
				for (size_t i = 0; i < _size_value; i++)
				{
					new_value[i] = _value[i];
					_alloc.destroy(_value + i);
				}
				_alloc.deallocate(_value, _size_alloc);
				_value = new_value;
			}
			if (val != 0)
			{
				for (size_t i = _size_value; i < n; i++)
				{
					_value[i] = val;
					_size_value++;
				}
			}
			if (val == 0)
			{
				for (size_t i = _size_value; i < n; i++)
				{
					_value[i] = 0;
					_size_value++;
				}
			}
		}

		void reserve (size_type n)
		{
			if (_size_alloc < n)
			{
				T	*new_value = NULL;
				new_value = _alloc.allocate(n);
				_size_alloc = n;
				for (size_t i = 0; i < _size_value; i++)
				{
					new_value[i] = _value[i];
					_alloc.destroy(_value + i);
				}
				_alloc.deallocate(_value, _size_alloc);
				_value = new_value;
			}
		}

		reference operator[] (size_type n)
		{
			return(_value[n]);
		}

		const_reference operator[] (size_type n) const
		{
			return(_value[n]);
		}
		
		reference at (size_type n)
		{
			if (_size_value < n)
			{
				throw std::out_of_range("vector");
			}
			else
				return (_value[n]);
		}

		const_reference at (size_type n) const
		{
			if (_size_value < n)
			{
				throw std::out_of_range("vector");
			}
			else
				return (_value[n]);
		}


		reference front()
		{
			return(_value[0]);
		}

		const_reference front() const
		{
			return(_value[0]);
		}

		reference back()
		{
			return(_value[_size_value]);
		}
		const_reference back() const
		{
			return(_value[_size_value]);
		}

		void clear()
		{
			for (int i = (int)(_size_value - 1); i >= 0; i--)
			{
				_alloc.destroy(&_value[i]);
				_size_value--;
			}
		}

		void	print()
		{
			size_t	i = 0;
			while (i < _size_value)
			{
				std::cout << _value[i] << std::endl;
				i++;
			}
		}

		void swap (vector& x)
		{
			pointer new_value;
			pointer new_value_two;
			new_value = _alloc.allocate(_size_alloc);
			new_value_two = _alloc.allocate(x._size_alloc);
			for (int i = 0; i < (int)_size_value ; i++)
			{
				new_value[i] = _value[i];
				_alloc.destroy(&_value[i]);
			}
			for (int i = 0; i < (int)x._size_value ; i++)
			{
				new_value_two[i] = x._value[i];
				_alloc.destroy(&x._value[i]);
			}
			_alloc.deallocate(_value, _size_alloc);
			_alloc.deallocate(x._value, x._size_alloc);
			_value = new_value_two;
			x._value = new_value;
			size_type tmp;
			size_type tmp2;
			tmp = x._size_alloc;
			tmp2 = x._size_value;
			x._size_alloc = _size_alloc;
			x._size_value = _size_value;
			_size_alloc = tmp;
			_size_value = tmp2;
		}


	/*	iterator begin(){
		
		}
		
		const_iterator begin() const{

		}*/

	private:
		size_type	_size_alloc;
		size_type	_size_value;
		_allocator	_alloc;
		pointer		_value;

		void	realloc()
		{
			if (_size_alloc == 0)
			{
				_value = _alloc.allocate(1);
				_size_alloc++;
			}
			T	*new_value = NULL;
			_size_alloc *= 2;
			new_value = _alloc.allocate(_size_alloc);
			for (int i = 0; i < (int)_size_value; i++)
			{
				new_value[i] = _value[i];
				_alloc.destroy(_value + i);
			}
			_alloc.deallocate(_value, _size_alloc);
			_value = new_value;
		}


};
}

#endif
