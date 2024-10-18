/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:30 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/18 11:43:17 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try 
	{
		Bureaucrat	Bob("Bob", 135); 
		Bureaucrat	Mary("Mary", 44);
		Bureaucrat	Tom("Tom", 4);
		
		ShrubberyCreationForm	Shrub("Bob"); //Grade 145 Exec 137
		RobotomyRequestForm		Robot("Mary"); //Grade 72 Exec 45
		PresidentialPardonForm	Zaphod("Tom"); //Grade 25 Exec 5
		
		std::cout << "\n*****BUREAUCRAT INFO*****\n\n";
		std::cout << Mary;
		std::cout << Bob;
		std::cout << Tom;
		std::cout << "\n*****FORM INFO*****\n\n";
		std::cout << Shrub;
		std::cout << Robot;
		std::cout << Zaphod;

		Shrub.beSigned(Bob);
		Robot.beSigned(Mary);
		Zaphod.beSigned(Tom);

		Shrub.execute(Bob);
		Robot.execute(Mary);
		Zaphod.execute(Tom);
		// Shrub.execute(Bob);
		
		std::cout << "\n*****BUREAUCRAT SIGNING FORMS*****\n\n";
		Bob.signForm(Shrub);
		Mary.signForm(Robot);
		Tom.signForm(Zaphod);

		std::cout << "\n*****BUREAUCRAT EXECUTING FORMS*****\n\n";
		Bob.executeForm(Shrub);
		Mary.executeForm(Robot);
		Tom.executeForm(Zaphod);
		
		std::cout << "\n*****FORM STATUS POST-SIGNING*****\n\n";
		std::cout << Shrub;
		std::cout << Robot;
		std::cout << Zaphod;
		
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