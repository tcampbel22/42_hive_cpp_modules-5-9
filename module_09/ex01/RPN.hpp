/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:36:05 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/11 14:50:56 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <regex>
#include <climits>
#include <sstream>
#include <algorithm>

class RPN
{
private:
	std::stack<long>	stack;
public:
	RPN();
	RPN(RPN& copy);
	const RPN& operator=(RPN& other);
	~RPN();
	void	operation(std::string operation);
	bool	isOp(std::string val);
};