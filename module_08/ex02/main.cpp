/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:57:04 by tcampbel          #+#    #+#             */
/*   Updated: 2024/11/18 14:49:29 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	try {
		
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n*****MutantStack*****\n";
	try {
		MutantStack<std::string> dstack;
		dstack.push("Hello");
		std::cout << "Top of stack: " << dstack.top() << " | Stack size: " << dstack.size() << '\n';
		dstack.push("World");
		std::cout << "Top of stack: " << dstack.top() << " | Stack size: " << dstack.size() <<'\n';
		dstack.push("Again");
		std::cout << "Top of stack: " << dstack.top() << " | Stack size: " << dstack.size() <<'\n';
		dstack.pop();
		std::cout << "Top of stack: " << dstack.top() << " | Stack size: " << dstack.size() <<'\n';

		MutantStack<std::string>::const_iterator it1 = dstack.begin();
		MutantStack<std::string>::const_iterator it2 = dstack.end();
		while (it1 != it2)
		{
			std::cout << *it1 << '\n';
			it1++;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n*****Deque*****\n";
	try {
		std::deque<std::string> deque1;
		deque1.push_back("Hello");
		std::cout << "Top of stack: " << deque1.back() << " | Stack size: " << deque1.size() << '\n';
		deque1.push_back("World");
		std::cout << "Top of stack: " << deque1.back() << " | Stack size: " << deque1.size() <<'\n';
		deque1.push_back("Again");
		std::cout << "Top of stack: " << deque1.back() <<  " | Stack size: " << deque1.size() <<'\n';
		deque1.pop_back();
		std::cout << "Top of stack: " << deque1.back() <<  " | Stack size: " << deque1.size() <<'\n';

		std::deque<std::string>::const_iterator it3 = deque1.begin();
		std::deque<std::string>::const_iterator it4 = deque1.end();
		while (it3 != it4)
		{
			std::cout << *it3 << '\n';
			it3++;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n*****List*****\n";
	try {
		std::list<std::string> list1;
		list1.push_back("Hello");
		std::cout << "Top of stack: " << list1.back() << " | Stack size: " << list1.size() << '\n';
		list1.push_back("World");
		std::cout << "Top of stack: " << list1.back() <<  " | Stack size: " << list1.size() <<'\n';
		list1.push_back("Again");
		std::cout << "Top of stack: " << list1.back() <<  " | Stack size: " << list1.size() <<'\n';
		list1.pop_back();
		std::cout << "Top of stack: " << list1.back() <<  " | Stack size: " << list1.size() <<'\n';

		std::list<std::string>::iterator it5 = list1.begin();
		std::list<std::string>::iterator it6 = list1.end();
		while (it5 != it6)
		{
			std::cout << *it5 << '\n';
			it5++;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		MutantStack<int> cstack;
		cstack.push(5);
		cstack.push(6);
		MutantStack<int> dstack(cstack);
		std::cout << "\n\n****Cstack****\n";
		for (auto c : cstack)
			std::cout << c << '\n';
		std::cout << "\n****Dstack****\n";
		for (auto d : dstack)
			std::cout << d << '\n';
		dstack.pop();
		MutantStack<int> fstack;
		fstack = dstack;
		std::cout << "\n****Fstack****\n";
		for (auto f : fstack)
			std::cout << f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}