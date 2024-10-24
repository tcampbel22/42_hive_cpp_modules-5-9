/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:58:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 11:26:45 by tcampbel         ###   ########.fr       */
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

void	identify(Base* p) 
{
	(void)p;
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "ptr: A\n";
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "ptr: B\n";
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "ptr: C\n";
	else
		std::cout << "Not type A, B or C\n";
}


void 	identify(Base& p)
{
	try { (void)dynamic_cast<A&>(p); std::cout << "ref: A\n"; }
	catch (std::bad_cast&) {}
	try { (void)dynamic_cast<B&>(p); std::cout << "ref: B\n"; }
	catch (std::bad_cast&) {}
	try { (void)dynamic_cast<C&>(p); std::cout << "ref: C\n"; }
	catch (std::bad_cast&) {}
}