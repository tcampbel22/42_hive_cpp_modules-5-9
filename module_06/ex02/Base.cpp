/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:58:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/23 18:15:57 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base*	generate(void) 
{
	Base *base = nullptr;
	std::srand(std::time(0));
	int num = rand() % 3;
	switch (num)
	{
		case 0:
			base = new A();
			break;
		case 1:
			base = new B();
			break;
		case 2:
			base = new C();
			break;
		default:
			throw std::out_of_range("Invalid number");
	}
	return base; 
}

Base::~Base() {}

void	identify(Base* p) {}


void 	identify(Base& p) {}