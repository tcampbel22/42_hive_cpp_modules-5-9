/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:47:52 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/15 15:00:31 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(const char* msg) : message(msg) {}

const char*	GradeTooLowException::what() const throw() { return message.c_str(); }