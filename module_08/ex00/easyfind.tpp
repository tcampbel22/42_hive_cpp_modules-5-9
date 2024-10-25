/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:33:55 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/25 17:56:29 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>

typename T::iterator easyfind(T param1, int param2)
{
	auto it = find(param1.begin(), param1.end(), param2);
	if (it != param1.end())
		return it;
	else
		throw std::out_of_range("Param not found");
}