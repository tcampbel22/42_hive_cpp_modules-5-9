/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:10:47 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 16:08:22 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> 
class Iter
{
private:

public:
	Iter();
	Iter(const Iter& copy);
	~Iter();
	const Iter& operator=(const Iter& other);
template<typename F>
	void	iter(T* address, T len, F (func));
};