/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:35 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/14 17:40:34 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(){}

Bitcoin::~Bitcoin(){}

std::map<std::string, double>&	Bitcoin::getMap(e_map map) 
{ 
	if (map == DATABASE)
		return dataBase; 
	return exchange;
}

void	removeSpaces(std::string& str)
{
	std::regex spaces("[\\t\\r\\a\\t ]");
	for (auto it = str.begin(); it != str.end();)
	{
		std::string temp(1, *it);
		if (std::regex_match(temp, spaces))
			it = str.erase(it);
		else
			it++;
	}
}

bool	Bitcoin::validDate(std::string& date)
{
	removeSpaces(date);
	std::regex date_format("^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01])$");
	if (std::regex_match(date, date_format))
		return true;
	return false;
}

void	Bitcoin::parseFile(std::string file, char delim, std::map<std::string, double>& map)
{
	std::string line, date, rate;
	std::fstream data;
	data.open(file);
	if (!data || (std::filesystem::exists(file) && std::filesystem::is_empty(file)))
		throw std::runtime_error("File empty or failed to open");
	if(!std::getline(data, line)) //skip first line
		throw std::runtime_error("Invalid format");
	while (std::getline(data, line))
	{
		std::istringstream	tempLine(line);
		if (!std::getline(tempLine, date, delim) || (!std::getline(tempLine, rate)))
			throw std::runtime_error("Invalid format");
		if (validDate(date))
		{
			try {
				removeSpaces(rate);
				double conv_rate = std::stod(rate);
				if (conv_rate < 0 || conv_rate > INT_MAX)
					throw std::invalid_argument("Invalid rate");
				map[date] = conv_rate;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else
			throw std::runtime_error("error: Invalid date: " + date);
	}
	data.close();
}

void	Bitcoin::printExchange(std::string inputfile) 
{
	parseFile(inputfile, '|', this->exchange);
	for (const auto& pair : this->exchange)
		std::cout << "Date: "<< pair.first << " Rate: " << pair.second << '\n';
}