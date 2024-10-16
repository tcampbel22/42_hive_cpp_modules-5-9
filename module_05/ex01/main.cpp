/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:30 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/16 17:25:33 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

int	main()
{
	try 
	{
		Bureaucrat Bob("Bob", 2);
		Bureaucrat Bot("Bot", 5);
		Form form1("b52", false, 10, 0);

		std::cout << Bot;
		std::cout << Bob;
		std::cout << form1;
		// form1.beSigned(Bob);
		Bob.signForm(form1);
		std::cout << form1;
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