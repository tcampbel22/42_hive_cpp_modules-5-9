/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:36:05 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/17 17:32:21 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <regex>

class RPN
{
private:
	int result = 0;
	std::stack<int>	stack;
public:
	RPN();
	~RPN();
	void	calculate(std::string operation);
	void	parseOperation(std::string& operation);
	void	add();
	void	subtract();
	void	divide();
	void	multiply();
};