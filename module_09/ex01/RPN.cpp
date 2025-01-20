/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:35:57 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/20 13:43:02 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

void	removeSpaces(std::string& str)
{
	std::regex spaces("[\\n\\t\\r ]");
	for (auto it = str.begin(); it != str.end();)
	{
		std::string temp(1, *it);
		if (std::regex_match(temp, spaces))
			it = str.erase(it);
		else
			it++;
	}
	if (str.empty())
		throw std::invalid_argument("error: empty argument");
}

void	RPN::parseOperation(std::string operation)
{
	removeSpaces(operation);
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
				std::cout << "Here\n";
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
	int top = stack.top();
	stack.pop();
	result = stack.top();
	while (stack.size() != 0)
	{
		result -= top;
		stack.pop();
	}
	stack.push(result);
}

void RPN::divide() //needs work to handle 0 and not keep dividing
{
	if (stack.size() <  2)
		throw std::runtime_error("error: insufficient values to perform operation");
	int n1 = stack.top();
	stack.pop();
	int n2 = stack.top();
	stack.pop();
	if (n1 == 0 || n2 == 0)
		throw  std::invalid_argument("error: cannot divide by 0");
	result = n2 / n1;
	while (stack.size() != 0)
	{
		int n3 = stack.top();
		result /= n3;
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