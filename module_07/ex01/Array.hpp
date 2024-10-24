/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:10:47 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 13:14:11 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> class Array
{
	Array();
	Array(uint n);
	Array(const Array& copy);
	~Array();
	const Array& operator=(const Array& other);
};