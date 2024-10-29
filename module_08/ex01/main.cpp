/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:36:48 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/29 12:19:35 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try 
	{

		Span 	span1(100);
		Span 	span2(10);
		Span	span3(3);
		
		span1.addAllTheNumbers(100);
		uint longest1 = span1.longestSpan();
		uint shortest1 = span1.shortestSpan();

		
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

		
		std::cout << "***Span1***\n\nLongest: " << longest1 << "\nShortest: " << shortest1 << "\n\n";
		std::cout << "***Span2***\n\nLongest: " << longest2 << "\nShortest: " << shortest2 << "\n\n";

		span3.addAllTheNumbers(10);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}