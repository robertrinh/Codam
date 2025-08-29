#pragma once

//* using map for this exersize because it does map maintains in sorted order (good for date comparisons), 
//* prevents duplicate date entries 
//* builtin finding closest lower dates
#include <map>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>
#include <algorithm>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;
	
	bool	validateDate(const std::string& date) const;
	bool	validateValue(float value) const;
	bool	isValidDate(int year, int month, int day) const;
	void	parseInputLine(const std::string& line, std::string& date, float& value) const;
	float	findClosestRate(const std::string& date) const;

public:
	BitcoinExchange() = default;
	BitcoinExchange(const BitcoinExchange& src) = delete;
	BitcoinExchange& operator=(const BitcoinExchange& src) = delete;
	~BitcoinExchange() = default;

	void	loadData(const std::string& filename);
	void	processInputFile(const std::string& filename);
	void	calculateResult(const std::string& date, float value) const;
};