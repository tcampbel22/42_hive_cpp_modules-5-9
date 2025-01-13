/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:56 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/13 17:00:32 by tcampbel         ###   ########.fr       */
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

class Bitcoin
{
private:
	std::map<std::string, double>	dataBase;
	std::fstream					data;
	std::ofstream					input;
public:
	Bitcoin();
	~Bitcoin();
	void	parseDb(std::string file);
	bool	validDate(std::string& date);
	void	createFile(std::string& inputFile);
};