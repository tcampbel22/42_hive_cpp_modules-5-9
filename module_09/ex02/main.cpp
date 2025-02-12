/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:22:35 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/12 15:27:58 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmerge.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "error: insufficent args" <<  std::endl;
		return (1);
	}
	try
	{
		Pmergeme merge;
		
		merge.storeValues(av, ac);
		
		auto start = std::chrono::high_resolution_clock::now();
		Pmergeme::vecSort(merge.getVec(), merge.getSortVec());
		auto end = std::chrono::high_resolution_clock::now();
		merge.setVecTime(std::chrono::duration_cast<std::chrono::microseconds>(end - start));
		
		start = std::chrono::high_resolution_clock::now();
		merge.lstSort(merge.getLst(), merge.getSortLst());
		end = std::chrono::high_resolution_clock::now();
		merge.setLstTime(std::chrono::duration_cast<std::chrono::microseconds>(end - start));
		merge.printResult(ac - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}