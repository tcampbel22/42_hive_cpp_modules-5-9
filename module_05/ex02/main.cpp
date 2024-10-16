/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:30 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/16 18:08:17 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try 
	{
		Bureaucrat Bob("Bob", 2);
		Bureaucrat Bot("Bot", 5);
		ShrubberyCreationForm Shrub("Bob", true, 20, 1);

		Shrub.makeShrubbery(Bob);
		std::cout << Bot;
		std::cout << Bob;
		std::cout << Shrub;
		// form1.beSigned(Bob);
		Bob.signForm(Shrub);
		std::cout << Shrub;
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