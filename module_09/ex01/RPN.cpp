/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:35:57 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/11 15:19:34 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(RPN& copy) : stack(copy.stack) {}

const RPN& RPN::operator=(RPN& other) 
{
	if (this != &other)
		stack = other.stack;
	return *this;
}

RPN::~RPN(){}


bool RPN::isOp(std::string val)
{
	if (val == "+" || val == "-" || val == "/" || val == "*")
		return true;
	return false;
}

void	RPN::operation(std::string operation)
{
	if (operation.empty())
		throw std::invalid_argument("error: empty argument");
	std::istringstream	stream(operation);
	std::string			value;
	while (stream >> value)
	{
		if (!isOp(value))
		{
			try 
			{
				stack.push(stol(value));	
			}
			catch (std::exception& e)
			{
				throw std::invalid_argument("error: invalid character/exceeds int boundaries");
			}
		}
		else
		{
			if (stack.size() < 2)
				throw std::runtime_error("error: insufficient values to perform operation");
			long a = stack.top();
			stack.pop();
			long b = stack.top();
			stack.pop();
			switch (value[0])
			{
				case '+':
					stack.push(b + a);
					break;
				case '-':
					stack.push(b - a);
					break;
				case '/':
					if (a == 0 || b == 0)
						throw  std::invalid_argument("error: cannot divide by 0");
					stack.push(b / a);
					break;
				case '*':
					stack.push(b * a);
					break;
				default:
					throw std::invalid_argument("error: invalid character");
			}
		}
	}
	if (stack.size() != 1 || isOp(std::to_string(stack.top())))
		throw std::invalid_argument("error: extra value in stack or only whitespace in stack");
	if (stack.top() > INT_MAX || stack.top() < INT_MIN)
		throw std::runtime_error("error: result is not within int boundaries");
	std::cout << std::to_string(stack.top()) << std::endl;
}
