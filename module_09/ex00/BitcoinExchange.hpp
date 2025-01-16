/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:56 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/16 15:51:47 by tcampbel         ###   ########.fr       */
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
	std::multimap<std::string, double>	dataBase;
	std::multimap<std::string, double>	exchange;
public:
	Bitcoin();
	~Bitcoin();
	void							parseFile(std::string file, char delim, e_map map);
	bool							validDate(std::string& date);
	void							printExchange(std::string inputFile);
	bool							checkRateAndDate(double rate, std::string date, e_map map);
	void							validSum(std::pair<std::string, double> db, std::pair<std::string, double> ex);
	std::multimap<std::string, double>&	getMap(e_map map);
};