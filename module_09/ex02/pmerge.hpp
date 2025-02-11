/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:00:27 by tcampbel          #+#    #+#             */
/*   Updated: 2025/02/11 16:16:55 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>

class Pmergeme
{
private:
	std::vector<int> vec;
	std::deque<int> deq;
	std::vector<int> sort_vec;
	std::deque<int> sort_deq;
	double			vec_time = 0.0;
	double			deq_time = 0.0;
public:
	Pmergeme();
	Pmergeme(Pmergeme& copy);
	Pmergeme& operator=(Pmergeme& other);
	~Pmergeme();
	void	storeValues(char** values, int count);
	void	printResult(int count);
	void	vecSort();
	void	deqSort();
};

