/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:38:03 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 11:52:05 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Zaphod", false, false, 25, 5) {} 

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("PresidentialPardonForm", false, false, 25, 5), target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) 
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

std::string	PresidentialPardonForm::getTarget() { return target; }


void		PresidentialPardonForm::PresidentialPardon(const Bureaucrat& b) const
{
	std::cout << b.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	PresidentialPardon(executor);
}

void		PresidentialPardonForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > getAGradeSign())
		throw Bureaucrat::GradeTooLowException("Grade to low to sign!");
	setSigned(true);
	std::cout << getAName() << " signed by " << b.getName() << std::endl;
}