/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:19:08 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/25 13:53:52 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T> 
class Array
{
private:
	T	*array;
	uint		len;
public:
	Array();
	Array(uint n); //Creates an array of type T with a length of <n>, array needs to be on the heap
	Array(const Array& copy); //Have to be deep copies
	~Array(); 
	const Array& operator=(const Array& other); //Have to be deep copies
	uint	size(); //returns number of elements in the array
	T& operator[](uint n);
};

template<typename T> 
std::ostream& operator<<(std::ostream& stream, Array<T> array);