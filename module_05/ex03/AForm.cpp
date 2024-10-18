/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:34 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/18 11:38:01 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("AForm"), isSigned(false), isExec(false), gradeSign(0), gradeExec(0) {}

AForm::AForm(std::string newName, bool sign, bool exec, int newSign, int newExec) 
			: name(newName), isSigned(sign), isExec(exec), gradeSign(newSign), gradeExec(newExec) {}

AForm::AForm(const AForm& copy) : name(copy.name), isSigned(copy.isSigned), isExec(copy.isExec), gradeSign(copy.gradeExec), gradeExec(copy.gradeExec) {}

AForm::~AForm() {}

const AForm&		AForm::operator=(const AForm& other) 
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		this->isExec = other.isExec;
	}
	return *this;
}

const std::string	AForm::getAName() const { return name; }

bool				AForm::getAIsSigned() const { return isSigned; }

int					AForm::getAGradeSign() const { return gradeSign; }

int					AForm::getAGradeExec() const { return gradeExec; }

bool				AForm::getAIsExec() const { return isExec; }

void				AForm::setExecuted(bool exec) const { isExec = exec; }

void				AForm::setSigned(bool sign) { isSigned = sign; }


void				AForm::beSigned(const Bureaucrat& b) 
{
	if (b.getGrade() > getAGradeSign())
		throw GradeTooLowException("Grade to low to sign!");
	isSigned = true;
}

void				AForm::execute(Bureaucrat const & executor) const
{
	if (isSigned == false)
		throw std::invalid_argument("Form not signed and cannot be executed!");
	if (isExec == true)
		throw std::invalid_argument("Form has already been executed!");
	if (executor.getGrade() > getAGradeExec())
		throw GradeTooLowException("Grade to low to execute!");
	setExecuted(true);
}

std::ostream& operator<<(std::ostream& stream, AForm const& Aform) 
{
	return stream << "AForm " << Aform.getAName() << " info:\n->Signed status: " << std::boolalpha << Aform.getAIsSigned()
				<< "\n->Executed status: " << Aform.getAIsExec() 
				<< "\n->Grade required to sign: " << Aform.getAGradeSign() << "\n->Grade required to execute: "
				<< Aform.getAGradeExec() << std::endl;   
}