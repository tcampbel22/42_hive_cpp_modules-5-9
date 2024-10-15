/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:30 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/15 16:14:55 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

int	main()
{
	try 
	{
		Bureaucrat Bob("Bob", 150);
		Bureaucrat Bot("Bot", 0);

		// Bob.setGrade(-1);
		// Bob.setGrade(160);
		// std::cout << Bob;
		// Bob.decrementGrade();
		std::cout << Bot;
		Bot.incrementGrade();
		std::cout << Bot;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}