/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:24:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/16 18:07:09 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Form", false, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newName, bool sign, int newGradeSign, int newGradeExec) : AForm(newName, sign, newGradeSign, newGradeExec) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::makeShrubbery(const Bureaucrat& b) 
{
	std::ofstream file(b.getName() + "_shrubbery");
	if (!file.is_open())
					throw std::invalid_argument("File failed to be opened/created");
	file << "        /\\\n       /**\\\n      /****\\\n     /******\\\n    /********\\\n   /**********\\\n  /____________\\\n      ||  ||\n      ||  ||\n      ||  ||\n";
	file.close();
}

const std::string	ShrubberyCreationForm::getName() const { return getAName(); }

bool				ShrubberyCreationForm::getIsSigned() const { return getAIsSigned(); }

int					ShrubberyCreationForm::getGradeSign() const { return getAGradeSign(); }

int					ShrubberyCreationForm::getGradeExec() const { return getAGradeExec(); }

void		ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > getAGradeSign())
		throw GradeTooLowException("Grade to low to sign!");
	setSigned(true);
}
