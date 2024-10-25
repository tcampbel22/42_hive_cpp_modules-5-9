/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:46 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:14 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"

int main()
{
	int							array[5] = {1, 2, 3, 4, 5};
	int							len = sizeof(array)/sizeof(array[0]);
	std::vector<int> 			myVector(array, array+len);
	
	try 
	{
		int	param = 4;
		easyfind(myVector, param);
		std::cout << "Param: " << param << " was found\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		int	param = 10;
		easyfind(myVector, param);
		std::cout << "Param: " << param << " was found\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}