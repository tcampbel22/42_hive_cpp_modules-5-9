/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:36:48 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/28 17:38:22 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span span;
	span.addNumber(10);
	span.addNumber(20457);
	span.addNumber(1);
	span.addNumber(3);
	span.shortestSpan();
}