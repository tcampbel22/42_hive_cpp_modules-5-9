/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:46:16 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/17 16:40:56 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	std::string	target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string t);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();
	const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	void						beSigned(const Bureaucrat& b) override;
	void						Robotomize(const Bureaucrat& b);
	std::string					getTarget();
};