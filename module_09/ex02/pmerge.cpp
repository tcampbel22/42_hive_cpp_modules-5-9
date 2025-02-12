/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:00:29 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/12 16:30:09 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmerge.hpp"

Pmergeme::Pmergeme() {}
Pmergeme::Pmergeme(Pmergeme& copy) : vec(copy.vec), lst(copy.lst) {}
Pmergeme& Pmergeme::operator=(Pmergeme& other) 
{
	if (this != &other)
	{
		vec = other.vec;
		lst = other.lst;
	}
	return *this;
}

Pmergeme::~Pmergeme() {}

std::vector<int>&	Pmergeme::getVec() { return vec; }
std::list<int>&		Pmergeme::getLst() { return lst; }
std::vector<int>&	Pmergeme::getSortVec() { return sort_vec; }
std::list<int>&		Pmergeme::getSortLst() { return sort_lst; }


void	Pmergeme::storeValues(char** values, int count)
{
	for (int i = 1; i < count; i++)
	{
		std::string temp = values[i];
		if (temp.size() > 1 && !isdigit(temp[1]))
			throw std::invalid_argument("error: strings not accepted");
		try 
		{
			vec.push_back(std::stoi(values[i]));
			lst.push_back(std::stoi(values[i]));
		}
		catch(std::exception& e)
		{
			throw std::invalid_argument("error: invalid input");
		}
		if (std::stoi(values[i]) < 0)
			throw std::invalid_argument("error: positive integers only");
	}
}

void	printVec(std::vector<int> vector, std::string name)
{
	std::cout << name << ": ";
	for (auto it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
}

void	printLst(std::list<int> list, std::string name)
{
	std::cout << name << ": ";
	for (auto it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
}

void	Pmergeme::vecSort(std::vector<int>& vec, std::vector<int>& sorted) 
{
	//Ensure recursion stops
	if (vec.size() == 0)
		return ;
	if (vec.size() == 1)
	{
		sorted = vec;
		return;
	}
	//Create 2 vectors to pair off each value
	std::vector<int> main, pending;
	//Divide the numbers into pairs and then size into separate vectors eg  9 67 7 6 8 0 => [9, 67] [7, 6] [8, 0]
	// main => [9, 6, 0] pending => [67, 7, 8]
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
		{
			main.push_back(vec[i]);
			pending.push_back(vec[i + 1]);
		}
		else
		{
			main.push_back(vec[i + 1]);
			pending.push_back(vec[i]);
		}
	}
	
	//If the sequence is an odd number then add the last number to the pending vector 
	if (vec.size() % 2 != 0)
		pending.push_back(vec[vec.size() - 1]);
	
	// Recursive call the sort the pairs again main is currently [9, 6, 0]
	// Rmain => [6] Rpending => [9, 0]
	// sorted => [6]
	// sorted => [0, 6, 9]
	// sorted => [0, 6, 7, 8, 9, 67]
	vecSort(main, sorted);
	
	
	//Insert pending into the final sorted list using a binary insertion sort
	for (auto num : pending)
	{
		auto it = std::lower_bound(sorted.begin(), sorted.end(), num);
		sorted.insert(it, num);
	}
}

void	Pmergeme::lstSort(std::list<int>& lst, std::list<int>& sorted)
{
	//Ensure recursion stops
	if (lst.size() < 1)
		return ;
	
	std::list<int> main, pending;
	
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		if (std::next(it) != lst.end())
		{
			if (*it < *std::next(it))
			{
				main.push_back(*it);
				pending.push_back(*std::next(it));
			}
			else
			{
				main.push_back(*std::next(it));
				pending.push_back(*it);
			}
			it++;
		}
		else
			pending.push_back(*it);
	}
	
	lstSort(main, sorted);
	
	for (auto num : pending)
	{
		auto it = std::lower_bound(sorted.begin(), sorted.end(), num);
		sorted.insert(it, num);
	}
}

void	Pmergeme::printResult(int count) 
{
	std::cout << "Before: "; 
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
	std::cout << "After:  ";
	for (auto it = sort_vec.begin(); it != sort_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n';
	// std::cout << "Before: ";
	// for (auto it = lst.begin(); it != lst.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << '\n';
	// std::cout << "After:  ";
	// for (auto it = sort_lst.begin(); it != sort_lst.end(); it++)
	// std::cout << *it << " ";
	// std::cout << '\n';
	std::cout << "Time to process a range of " << count << " elements with std::vector => " <<  vec_time.count() << "us\n";
	std::cout << "Time to process a range of " << count << " elements with std::list   => " << lst_time.count() << "us\n";
}

void	Pmergeme::setVecTime(std::chrono::microseconds time) { vec_time = time; }
void	Pmergeme::setLstTime(std::chrono::microseconds time) { lst_time = time; }