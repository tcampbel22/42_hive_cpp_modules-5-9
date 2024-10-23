/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:28:41 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/23 17:34:30 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *data = new Data;
	
	uintptr_t ptr = Serializer::serialize(data);
	
	Data *data2 = Serializer::deserialize(ptr);

	if (data == data2)
		std::cout << "Success!\nData address: " << data << "\nData2 address: " << data2 << '\n'; 
	else
		std::cout << "BOOOOO! Addresses do not match\n";
	delete data;
}