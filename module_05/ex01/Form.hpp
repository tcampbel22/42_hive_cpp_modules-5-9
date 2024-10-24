/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:03 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 11:49:10 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeSign;
	const int			gradeExec;
public:
	Form();
	Form(std::string newName, bool sign, int newGradeSign, int newGradeExec);
	Form(const Form& copy);
	~Form();
	const Form&			operator=(const Form& other);
	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;
	void				beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& stream, Form const& form);