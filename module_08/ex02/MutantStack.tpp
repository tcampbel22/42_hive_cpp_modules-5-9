/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:06:10 by tcampbel          #+#    #+#             */
/*   Updated: 2024/11/01 15:30:32 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() = default;

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) { this->c = copy.c; }

template<typename T>
const MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& other) 
{
	if (this != &other)
		this->c = other.c;
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() = default;

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.cbegin(); }

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.cend(); }
