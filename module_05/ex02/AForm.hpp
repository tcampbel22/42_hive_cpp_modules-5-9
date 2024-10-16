/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:03 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/16 15:29:24 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeSign;
	const int			gradeExec;
public:
	AForm();
	AForm(std::string newName, bool sign, int newGradeSign, int newGradeExec);
	AForm(const AForm& copy);
	virtual ~AForm();
	const AForm&			operator=(const AForm& other);
	const std::string	getAName() const;
	bool				getAIsSigned() const;
	int					getAGradeSign() const;
	int					getAGradeExec() const;
	void				setSigned(bool sign);
	virtual void		beSigned(const Bureaucrat& bureaucrat) = 0;
};

std::ostream& operator<<(std::ostream& stream, AForm const& Aform);