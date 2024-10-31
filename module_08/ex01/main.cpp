/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:36:48 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/31 15:41:45 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try 
	{

		Span 	span1(10000);
		
		span1.addAllTheNumbers(10000);
		uint longest1 = span1.longestSpan();
		uint shortest1 = span1.shortestSpan();
		
		std::cout << "***Span1***\n\nLongest: " << longest1 << "\nShortest: " << shortest1 << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span 	span2(10);
	
		span2.addNumber(10);
		span2.addNumber(20457);
		span2.addNumber(11);
		span2.addNumber(534);
		span2.addNumber(8768);
		span2.addNumber(204);
		span2.addNumber(1);
		span2.addNumber(980);
		span2.addNumber(78);
		span2.addNumber(29);

		uint longest2 = span2.longestSpan();
		uint shortest2 = span2.shortestSpan();

		
		std::cout << "***Span2***\n\nLongest: " << longest2 << "\nShortest: " << shortest2 << "\n\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span	span3(3);
		span3.addAllTheNumbers(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}