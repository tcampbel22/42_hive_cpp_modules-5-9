/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:01:08 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 11:55:31 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Roboto", false, false, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("RobotomyRequestForm", false, false, 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget() { return target; }

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void	RobotomyRequestForm::Robotomize(const Bureaucrat& b) const
{
	std::srand(std::time(0));
	std::cout << "!*!*!*!LOUD DRILLING NOISES!*!*!*!*!*!\n";
	int	num = std::rand() % 1000;
	if (num % 2 == 0)
		std::cout << b.getName() << " has been robotomized!\n";
	else
		std::cout << "Robotomy has failed\n*!*!*!SAD BEEPING NOISES!*!*!*!*\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	Robotomize(executor);
}

void	RobotomyRequestForm::beSigned(const Bureaucrat& b) 
{
	if (b.getGrade() > getAGradeSign())
		throw Bureaucrat::GradeTooLowException("Grade to low to sign!");
	setSigned(true);
	std::cout << getAName() << " signed by " << b.getName() << std::endl;
}