/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:58:18 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/31 17:54:40 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <vector>

template<typename T, template <typename, typename> class Container = std::vector>
class MutantStack
{
private:
	Container <T, std::allocator<T>> mutantStack;
public:
	MutantStack();
	MutantStack(const MutantStack& copy);
	const MutantStack&	operator=(const MutantStack& other);
	~MutantStack();
	void 		push(const T& val);
	void 		pop();
	T&			top();
	const T&	top() const;
	bool		empty() const;
	size_t		size() const;

	typename Container<T, std::allocator<T>>::iterator begin();
	typename Container<T, std::allocator<T>>::iterator end();
	typename Container<T, std::allocator<T>>::iterator begin() const;
	typename Container<T, std::allocator<T>>::iterator end() const;
};

#include "MutantStack.tpp"
