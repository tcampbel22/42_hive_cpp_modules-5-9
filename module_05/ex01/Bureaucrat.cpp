/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:52:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/25 15:07:18 by tcampbel         ###   ########.fr       */
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

void	Bureaucrat::signForm(const Form& form) 
{
	if (form.getIsSigned() == true && grade < form.getGradeSign())
		std::cout << name << " has signed form " << form.getName() << std::endl;
	else
		std::cout << name << " hasn't signed form " << form.getName() << " because of reasons\n";
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	return stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char * msg) : message(msg) {}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return message.c_str(); }

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* msg) : message(msg) {}

const char*	Bureaucrat::GradeTooLowException::what() const throw() { return message.c_str(); }