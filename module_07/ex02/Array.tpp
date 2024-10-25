/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:52:56 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/25 14:24:14 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : array(nullptr), len(0) {}

template<typename T>
//Creates an array of tyre T with a length of <n>, array needs to be on the heap
Array<T>::Array(uint n) : array(new T[n]), len(n)
{
	for (uint i = 0; i < n; i++)
		array[i] = T();
		
}

//Creates deep copy
template<typename T>
Array<T>::Array(const Array& copy) 
{
	array = new T[copy.len];
	len = copy.len;
	for (uint i = 0; i < len; i++)
		array[i] = copy.array[i];
} 

template<typename T>
Array<T>::~Array() { delete[] array; }

template<typename T>
//Deletes previous array and creates deep copy
const Array<T>& Array<T>::operator=(const Array<T>& other) 
{
	if (this != &other)
	{
		delete[] this->array;
		array = new T[other.len];
		len = other.len;
		for (uint i = 0; i < len; i++)
			array[i] = other.array[i];
	}
	return *this;
} 

template<typename T>
//returns number of elements in the array
uint	Array<T>::size() { return len; }

template<typename T>

T&	Array<T>::operator[](uint n)
{
	if (n >= 0 && n < this->len)
		return this->array[n];
	else
		throw std::out_of_range("Index is out range");
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, Array<T> array)
{
	for (uint i = 0; i < array.size(); i++)
		stream << array[i] << " ";
	return stream;
}
