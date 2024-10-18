/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:52:10 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/18 13:44:49 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string 	name;
	int					grade;
public:
	Bureaucrat();
	Bureaucrat(std::string newName, int newGrade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();
	const Bureaucrat& operator=(const Bureaucrat& other);
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		setGrade(int newGrade);
	void		signForm(const Form& form);
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat const& bureaucrat);