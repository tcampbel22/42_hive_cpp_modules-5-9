/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:22:35 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/11 15:49:27 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmerge.hpp"

int main(int ac, char** av)
{
	if (ac < 3)
	{
		std::cerr << "error: insufficent args" <<  std::endl;
		return (1);
	}
	try
	{
		Pmergeme merge;
		merge.storeValues(av, ac);
		// merge.vecSort();
		// merge.deqSort();
		merge.printResult(ac - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}