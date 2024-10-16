/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:55:39 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/16 18:02:24 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string newName, bool sign, int newGradeSign, int newGradeExec);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	~ShrubberyCreationForm();
	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;
	// void				setSigned();
	const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	void		beSigned(const Bureaucrat& b) override;
	void		makeShrubbery(const Bureaucrat& b);
};