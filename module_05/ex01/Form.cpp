/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:11:27 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 11:49:27 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Form"), isSigned(false), gradeSign(1), gradeExec(1) {}

Form::Form(std::string newName, bool sign, int newSign, int newExec) 
			: name(newName), isSigned(sign), gradeSign(newSign), gradeExec(newExec) {}

Form::Form(const Form& copy) : name(copy.name), isSigned(copy.isSigned), gradeSign(copy.gradeExec), gradeExec(copy.gradeExec) {}

Form::~Form() {}

const Form&	Form::operator=(const Form& other) 
{
	if (this != &other)
		*this = Form(other);
	return *this;
}

const std::string	Form::getName() const { return name; }

bool				Form::getIsSigned() const { return isSigned; }

int			Form::getGradeSign() const { return gradeSign; }

int			Form::getGradeExec() const { return gradeExec; }

void				Form::beSigned(const Bureaucrat& b) 
{
	if (b.getGrade() > getGradeSign())
		throw Bureaucrat::GradeTooLowException("Grade to low to sign!");
	isSigned = true;
}

std::ostream& operator<<(std::ostream& stream, Form const& form) 
{
	return stream << "Form " << form.getName() << " info:\n->Signed status: " << std::boolalpha << form.getIsSigned() 
				<< "\n->Grade required to sign: " << form.getGradeSign() << "\n->Grade required to execute: "
				<< form.getGradeExec() << std::endl;   
}