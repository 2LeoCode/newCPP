/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniquePtr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:02:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 15:24:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIQUEPTR_HPP
# define UNIQUEPTR_HPP

template <typename T>
class UniquePtr {
	public:

	UniquePtr() : _ptr(nullptr) { }
	~UniquePtr() {
		delete _ptr;
	}

	UniquePtr(const UniquePtr &other) : _ptr(other._ptr) { }
	UniquePtr(const T *ptr) : _ptr(ptr) { }

	UniquePtr	&operator=(const UniquePtr &other) {
		_ptr = other._ptr;
		return (*this);
	}
	UniquePtr	&operator=(const T *ptr) {
		_ptr = ptr;
		return (*this);
	}

	T			&operator*(void) {
		return (*_ptr);
	}
	T			*operator->(void) {
		return (_ptr);
	}

	private:

	T	*_ptr;
};

#endif //UNIQUEPTR_HPP
