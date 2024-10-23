/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:29:10 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/23 17:32:29 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& copy) { *this = copy; }
const Serializer& Serializer::operator=(const Serializer& other) 
{ 
	if (this != &other)
		return *this;
	return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) 
{
	return   reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) 
{
	return reinterpret_cast<Data*>(raw);	
}