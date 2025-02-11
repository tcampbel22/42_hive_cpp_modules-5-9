/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:30 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/25 15:10:58 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	
	AForm* Shrub = nullptr;
	AForm* Robot = nullptr;
	AForm* President = nullptr;
	// AForm* WrongForm = nullptr;
	
	try 
	{
		Bureaucrat	Tom("Tom", 100);
		Bureaucrat	Roboto("Roboto", 40);
		Bureaucrat	Bob("Bob", 4);
		// Bureaucrat	Wrong("Wrong", 1);
		
		Intern RandomIntern;
		Intern OtherIntern;
		Intern RoboticIntern;
		// Intern WrongIntern;
		
		std::cout << "\n*****INTERNs CREATES FORMS****\n\n";
		Shrub = OtherIntern.makeForm("ShrubberyCeationForm", "Tom");
		Robot = RoboticIntern.makeForm("RobotomyRequestForm", "Roboto");
		President = RandomIntern.makeForm("PresidentialPardonForm", "Bob");
		// WrongForm = WrongIntern.makeForm("fghdfjgh", "Wrong");
		
		std::cout << "\n*****CREATED FORMS INFO****\n\n";
		std::cout << *Shrub;
		std::cout << *Robot;
		std::cout << *President;

		std::cout << "\n*****FORMS SIGNING****\n\n";
		Shrub->beSigned(Tom);
		Robot->beSigned(Roboto);
		President->beSigned(Bob);

		std::cout << "\n*****FORMS EXECUTION****\n\n";
		Shrub->execute(Tom);
		Robot->execute(Roboto);
		President->execute(Bob);
		// Shrub->execute(Tom);
		std::cout << "\n*****BUREAUCRATS SIGNING FORMS****\n\n";
		Tom.signForm(*Shrub);
		Roboto.signForm(*Robot);
		Bob.signForm(*President);
			
		std::cout << "\n*****BUREAUCRATS EXECUTING FORMS****\n\n";
		Tom.executeForm(*Shrub);
		Roboto.executeForm(*Robot);
		Bob.executeForm(*President);

		std::cout << "\n*****CREATED FORMS INFO POST SIGNING/EXECUTION****\n\n";
		std::cout << *Shrub;
		std::cout << *Robot;
		std::cout << *President;

		if (Shrub) 
			delete Shrub;
		if (Robot)
			delete Robot;
		if (President)
			delete President;			
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		if (Shrub) 
			delete Shrub;
		if (Robot)
			delete Robot;
		if (President)
			delete President;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		if (Shrub) 
			delete Shrub;
		if (Robot)
			delete Robot;
		if (President)
			delete President;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		if (Shrub) 
			delete Shrub;
		if (Robot)
			delete Robot;
		if (President)
			delete President;
	}
}