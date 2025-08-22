#include "BitcoinExchange.hpp"

void BitcoinExchange::loadData(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");
	
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = line.substr(0, comma);
		std::string priceStr = line.substr(comma + 1);
	
		std::stringstream ss(priceStr);
		float price;
		if (!(ss >> price))
			continue;
		_data[date] = price;
	}
	file.close();
}

bool BitcoinExchange::validateDate(const std::string& date) const
{
	if (date.length() != 10)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	
	std::tm tm = {};
	//* strptime parses date string according to format "%Y-%m-%d"
	char* end = strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (!end || *end != '\0')
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	//* tm_year stores years since 1900 e.g. 2024 = 1224, so add 1900 to get actual year
	int year = tm.tm_year + 1900;
	//* tm_mon stores months as 0-11 (Jan=0, Dec=11), so add 1 for actual month
	int month = tm.tm_mon + 1;
	int day = tm.tm_mday;
	
	//* extra check for Feb 29 non-leap years, June 31 etc.
	if (!isValidDate(year, month, day))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (year < 2009)
	{
		std::cerr << "Error: bad input: bitcoin didnt exist before 2009" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(int year, int month, int day) const
{
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	std::tm tm = {};
	tm.tm_year = year - 1900;  //* tm_year expects years since 1900
	tm.tm_mon = month - 1;     //* tm_mon expects 0-11 (Jan=0, Dec=11)
	tm.tm_mday = day;
	
	//* store original values before mktime normalization
	int orig_year = tm.tm_year;
	int orig_month = tm.tm_mon;
	int orig_day = tm.tm_mday;
	
	//* mktime normalizes invalid dates (e.g., feb 30 becomes mar 2)
	time_t result = mktime(&tm);
	if (result == -1)
		return false;
	
	//* If mktime changed any values, the original date was invalid
	return (tm.tm_year == orig_year && 
			tm.tm_mon == orig_month && 
			tm.tm_mday == orig_day);
}

bool BitcoinExchange::validateValue(float value) const
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::parseInputLine(const std::string& line, std::string& date, float& value) const
{
	size_t pipe = line.find(" | ");
	if (pipe == std::string::npos)
		throw std::invalid_argument("Error: bad input => " + line);
	
	date = line.substr(0, pipe);
	std::string valueStr = line.substr(pipe + 3);
	
	std::stringstream ss(valueStr);
	if (!(ss >> value) || !ss.eof())
		throw std::invalid_argument("Error: bad input => " + line);
}

float BitcoinExchange::findClosestRate(const std::string& date) const
{
	//* lower_bound returns iterator to first element >= date
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	
	//* if exact match found, use it
	if (it != _data.end() && it->first == date)
		return it->second;
	if (it == _data.begin())
		throw std::runtime_error("Error: no data available for date => " + date);
	
	//* move back one position to get largest date < target
	--it;
	return it->second;
}

void BitcoinExchange::calculateResult(const std::string& date, float value) const
{
	//* find the exchange rate for the given date
	float rate = findClosestRate(date);
	std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	
	std::string line;
	bool firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine && line == "date | value")
		{
			firstLine = false;
			continue;  //* skip header
		}
		firstLine = false;
		if (line.empty())
			continue;
		try
		{
			std::string date;
			float value;
			parseInputLine(line, date, value);
			if (!validateDate(date) || !validateValue(value))
				continue;
			calculateResult(date, value);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}

