/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:05:31 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 17:16:38 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template<typename T>

Iter<T>::Iter() {}

template<typename T>

Iter<T>::Iter(const Iter& copy) { (void)copy; }

template<typename T>

Iter<T>::~Iter() {}

template<typename T>

const Iter<T>& Iter<T>::operator=(const Iter<T>& other) 
{ 
	(void)other;
	return *this; 
}

template<typename T>
template<typename F>

void	Iter<T>::iter(T* address, T len, F (func))
{
	for (int i = 0; i < len; i++)
		(func)(address[i]);
}