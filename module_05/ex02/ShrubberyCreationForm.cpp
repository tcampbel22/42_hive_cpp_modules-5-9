/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:24:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/18 12:06:23 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrub", false, false, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", false, false, 145, 137), target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void	ShrubberyCreationForm::makeShrubbery(std::string target) const
{
	std::ofstream file(target + "_shrubbery");
	if (!file.is_open())
					throw std::invalid_argument("File failed to be opened/created");
	file << "        /\\\n       /**\\\n      /****\\\n     /******\\\n    /********\\\n   /**********\\\n  /____________\\\n       |  |\n       |  |\n       |  |\n";
	file.close();
	std::cout << target << "'s shrubbery file has been executed\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	makeShrubbery(executor.getName());
}


void		ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > getAGradeSign())
		throw GradeTooLowException("Grade to low to sign!");
	setSigned(true);
	std::cout << getAName() << " signed by " << b.getName() << std::endl;
}
