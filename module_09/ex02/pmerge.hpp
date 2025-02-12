/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:00:27 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/12 15:11:48 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

class Pmergeme
{
private:
	std::vector<int> vec;
	std::list<int> lst;
	std::vector<int> sort_vec;
	std::list<int> sort_lst;
	std::chrono::microseconds	vec_time;
	std::chrono::microseconds	lst_time;
public:
	Pmergeme();
	Pmergeme(Pmergeme& copy);
	Pmergeme& operator=(Pmergeme& other);
	~Pmergeme();
	void				storeValues(char** values, int count);
	void				printResult(int count);
	static void			vecSort(std::vector<int>& vec, std::vector<int>& sorted);
	static void			lstSort(std::list<int>& lst, std::list<int>& sorted);
	void				setVecTime(std::chrono::microseconds time);
	void				setLstTime(std::chrono::microseconds time);
	std::vector<int>&	getVec();
	std::list<int>&		getLst();
	std::vector<int>&	getSortVec();
	std::list<int>&		getSortLst();
};

