/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:35 by tcampbel          #+#    #+#             */
/*   Updated: 2025/01/16 16:03:18 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(){}

Bitcoin::~Bitcoin(){}

std::multimap<std::string, double>&	Bitcoin::getMap(e_map map) 
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


bool	validFirstLine(std::string line, e_map map)
{
	if (map == DATABASE && !line.compare("date,exchange_rate"))
		return true;
	else if (map == EXCHANGE && !line.compare("date | value"))
		return true;
	else
		return false;
}

void	Bitcoin::parseFile(std::string file, char delim, e_map map_type)
{
	std::multimap<std::string, double>& map = getMap(map_type);
	std::string line, date, rate;
	std::fstream data;
	data.open(file);
	if (!data || (std::filesystem::exists(file) && std::filesystem::is_empty(file)))
		throw std::runtime_error("File empty or failed to open");
	if(!std::getline(data, line)) //skip first line
		if (validFirstLine(line, map_type)) //checks if first is correct format
			throw std::runtime_error("error: first line invalid");
	while (std::getline(data, line))
	{
		std::istringstream	tempLine(line); //stores line from getline in an istringstream to send to getline
		if (!std::getline(tempLine, date, delim) || (!std::getline(tempLine, rate))) //extracts date and rate from templine stream into separate strings
		{
			if (map_type == EXCHANGE)
			{
				map.insert({date, -1});
				continue;
			}
			throw std::runtime_error("error: missing date, value or delimiter");
		}
		try 
		{
			removeSpaces(date);
			removeSpaces(rate);
			double conv_rate = std::stod(rate);
			if (map_type == DATABASE && !checkRateAndDate(conv_rate, date, DATABASE))
				exit(1);
			map.insert({date, conv_rate});
		}
		catch (std::exception& e)
		{
			std::cerr << "error: " << e.what() << ": invalid format in file"<< std::endl;
			exit(1);
		}
	}
	data.close();
}

bool	isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;	
}

bool	Bitcoin::validDate(std::string& date)
{	
	std::regex date_format("^(2009-(01-(0[2-9]|[12]\\d|3[01])|(0[2-9]|1[0-2])-(0[1-9]|[12]\\d|3[01]))|20[1-9]\\d-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01]))$");
	if (!std::regex_match(date, date_format))
		return false;
	int day, month, year;
	try {
		year = stoi(date.substr(0, 4));
		month = stoi(date.substr(5, 7));
		day = stoi(date.substr(8, 10));
		if (month == APR || month == JUN | month == SEP || month == NOV)
		{
			if (day > 30)
				return false;
		}
		else if (month == FEB && (day > 28 || (isLeapYear(year) && day > 29)))
			return false;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return true;
}
bool	Bitcoin::checkRateAndDate(double rate, std::string date, e_map map)
{
	if (!validDate(date))
	{
		std::cerr << "error: date not valid: " + date << std::endl;
		return false;
	}
	if (map == EXCHANGE && (rate < 0 || rate > 1000))
	{
		std::cerr << "error: rate should be between 0 & 1000" << std::endl;
		return false;
	}
	return true;
}

void	Bitcoin::validSum(std::pair<std::string, double> db, std::pair<std::string, double> ex)
{
	if (db.second * ex.second > INT32_MAX)
		std::cerr << "error: value too large" << std::endl;
	else
		 std::cout << ex.first + " => " << ex.second << " = " << db.second * ex.second << std::endl;
}
void	Bitcoin::printExchange(std::string inputfile) 
{
	// 2011-01-03 => 3 = 0.9 example of printed conversion
	parseFile(inputfile, '|', EXCHANGE);
	for (const auto& ex : this->exchange)
	{
		if (!checkRateAndDate(ex.second, ex.first, EXCHANGE))
			continue;
		for (const auto& db : this->dataBase)
		{
			auto it = exchange.lower_bound(db.first);
			if (it != exchange.end())
				validSum(db, ex);
		}
	}
}