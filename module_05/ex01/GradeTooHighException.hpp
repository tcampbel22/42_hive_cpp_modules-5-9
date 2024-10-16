/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:46:10 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/15 15:00:41 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>

class GradeTooHighException : public std::exception
{
private:
	std::string	message;
public:
	GradeTooHighException(const char* msg);
	const char*	what() const throw() override;
};