/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:21:26 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:02 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <iostream>

struct Data
{
	uint num;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& copy);
	const Serializer& operator=(const Serializer& other);
	~Serializer();
public:
	static	uintptr_t serialize(Data* ptr);
	static	Data* deserialize(uintptr_t raw);
};