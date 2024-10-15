/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:52:28 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/15 14:56:27 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bob"), grade(150) {}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName), grade(newGrade) {}

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
	if (grade < 0)
		throw GradeTooLowException("Grade below 0");
}

void		Bureaucrat::decrementGrade()
{ 
	this->grade++;
	if (grade > 150)
		throw GradeTooHighException("Grade exceeds 150");
}

void		Bureaucrat::setGrade(int newGrade) 
{
	grade = newGrade; 
	if (grade > 150)
		throw GradeTooHighException("Grade exceeds 150");
	else if (grade < 0)
		throw GradeTooLowException("Grade below 0");
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	return stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}