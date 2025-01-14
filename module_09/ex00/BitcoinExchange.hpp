/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:56 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/14 17:39:58 by tcampbel         ###   ########.fr       */
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

enum e_map
{
	DATABASE,
	EXCHANGE
};

class Bitcoin
{
private:
	std::map<std::string, double>	dataBase;
	std::map<std::string, double>	exchange;
public:
	Bitcoin();
	~Bitcoin();
	void							parseFile(std::string file, char delim, std::map<std::string, double>& map);
	bool							validDate(std::string& date);
	void							printExchange(std::string inputFile);
	std::map<std::string, double>&	getMap(e_map map);
};