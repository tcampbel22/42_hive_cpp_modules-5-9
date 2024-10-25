/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:52:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/25 14:54:11 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bob"), grade(150) 
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade exceeds 150");
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade below 1");
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName), grade(newGrade) 
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade exceeds 150");
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade below 1");
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade) {}

Bureaucrat::~Bureaucrat() {}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}

std::string Bureaucrat::getName() const { return this->name; }

int			Bureaucrat::getGrade() const { return this->grade; }

void		Bureaucrat::incrementGrade()
{ 
	this->grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException("Grade below 1");
}

void		Bureaucrat::decrementGrade()
{ 
	this->grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade exceeds 150");
}

void		Bureaucrat::setGrade(int newGrade) 
{
	grade = newGrade; 
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade exceeds 150");
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade below 1");
}

void	Bureaucrat::signForm(const AForm& form) 
{
	if (form.getAIsSigned() == true && grade < form.getAGradeSign())
		std::cout << name << " has signed form " << form.getAName() << std::endl;
	else
		std::cout << name << " hasn't signed form " << form.getAName() << " because of reasons\n";
}

void		Bureaucrat::executeForm(AForm const & form) 
{
	if (grade > form.getAGradeExec())
		std::cout << name << " could not execute due to low grade\n";
	else
		std::cout << name << " executed " << form.getAName() << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	return stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char * msg) : message(msg) {}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return message.c_str(); }

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* msg) : message(msg) {}

const char*	Bureaucrat::GradeTooLowException::what() const throw() { return message.c_str(); }