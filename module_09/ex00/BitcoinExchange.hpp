/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:56 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/17 13:43:26 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <sstream>
#include <regex>
#include <string>
#include <limits.h>
#include <filesystem>
#include <algorithm>
#include <utility>


#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12


enum e_map
{
	DATABASE,
	EXCHANGE
};

class Bitcoin
{
private:
	std::map<std::string, float>	dataBase;
public:
	Bitcoin();
	~Bitcoin();
	void							parseFile(std::string file, char delim, e_map map);
	bool							validDate(std::string& date);
	bool							checkRateAndDate(float rate, std::string date, e_map map);
	void							validSum(float db_price, std::string& date, float rate);
	void							printExchange(std::string date, float rate);
};