/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:45 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 14:38:49 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) 
{ 
	if (this != &copy)
		return ;
}

Intern::~Intern() {}

const Intern& Intern::operator=(const Intern& other) 
{ 
	if (this != &other)
		return *this;
	return *this;
}

AForm*	Intern::makeForm(std::string form, std::string target) 
{
	AForm	*tmp = nullptr;
	int		id = 0;
	std::string Forms[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	
	for (int i = 0; i < 3; i++)
	{
		if (form.compare(Forms[i]) == 0)
			id = i + 1;
	}
	switch (id) 
	{
		case 1:
			tmp =  new ShrubberyCreationForm(target);
			break ;
		case 2:
			tmp = new RobotomyRequestForm(target);
			break ;
		case 3:
			tmp = new PresidentialPardonForm(target);
			break ;
		default:
			throw std::out_of_range("Failed to create form " + form);
	}
	std::cout << "Intern creates " << form << std::endl;
	return tmp;
}