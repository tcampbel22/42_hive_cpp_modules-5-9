/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:35:57 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/17 17:51:46 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

void	RPN::calculate(std::string operation)
{
	parseOperation(operation);
}

void	RPN::parseOperation(std::string& operation)
{
	for (char n : operation)
	{
		if (isdigit(n))
			stack.push(atoi(&n));
		else
		{
			switch (n)
			{
			case '+':
				add();
				break;
			case '-':
				subtract();
				break;
			case '/':
				divide();
				break;
			case '*':
				multiply();
				break;
			case ' ':
				break;
			default:
				throw std::invalid_argument("error: invalid character");
			}
		}
	}
	std::cout << result << std::endl;
}

void RPN::add()
{
	if (stack.size() <  2)
		throw std::runtime_error("error: insufficient values to perform operation");
	result = stack.top();
	stack.pop();
	while (stack.size() != 0)
	{
		result += stack.top();
		stack.pop();
	}
	stack.push(result);
}

void RPN::subtract()
{
	if (stack.size() <  2)
		throw std::runtime_error("error: insufficient values to perform operation");
	result = stack.top();
	stack.pop();
	while (stack.size() != 0)
	{
		result -= stack.top();
		stack.pop();
	}
	stack.push(result);
}

void RPN::divide() //needs work to handle 0 and not keep dividing
{
	if (stack.size() <  2)
		throw std::runtime_error("error: insufficient values to perform operation");
	result = stack.top();
	stack.pop();
	while (stack.size() != 0)
	{
		result /= stack.top();
		stack.pop();
	}
	stack.push(result);
}

void RPN::multiply()
{
	if (stack.size() <  2)
		throw std::runtime_error("error: insufficient values to perform operation");
	result = stack.top();
	stack.pop();
	while (stack.size() != 0)
	{
		result *= stack.top();
		stack.pop();
	}
	stack.push(result);
}