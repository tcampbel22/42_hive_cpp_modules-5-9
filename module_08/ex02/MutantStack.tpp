/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:06:10 by tcampbel          #+#    #+#             */
/*   Updated: 2024/11/01 15:01:50 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() = default;

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) { c = copy.c; }

template<typename T>
const MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& other) 
{
	if (this != &other)
		c = other.c;
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() = default;

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return c.begin(); }

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return c.end(); }

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return c.cbegin(); }

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return c.cend(); }
