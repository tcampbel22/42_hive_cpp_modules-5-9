/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:19:08 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 17:22:42 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T> class Array
{
	Array();
	Array(const Array& copy);
	~Array();
	const Array& operator=(const Array& other);
};