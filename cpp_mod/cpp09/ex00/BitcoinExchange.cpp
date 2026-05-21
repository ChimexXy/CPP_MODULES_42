#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _rates = other._rates;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const
{
    std::size_t start;
    std::size_t end;

    start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return ("");
    end = str.find_last_not_of(" \t\r\n");
    return (str.substr(start, end - start + 1));
}

bool BitcoinExchange::isLeapYear(int year) const
{
    if (year % 400 == 0)
        return (true);
    if (year % 100 == 0)
        return (false);
    return (year % 4 == 0);
}

int BitcoinExchange::daysInMonth(int year, int month) const
{
    static const int days[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && isLeapYear(year))
        return (29);
    return (days[month - 1]);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    int year;
    int month;
    int day;

    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return (false);
    }
    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > daysInMonth(year, month))
        return (false);
    return (true);
}

bool BitcoinExchange::parseNumber(const std::string& str, double& value) const
{
    std::string s;
    std::size_t i;
    bool hasDigit;
    bool hasDot;
    std::stringstream ss;

    s = trim(str);
    if (s.empty())
        return (false);
    i = 0;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    hasDigit = false;
    hasDot = false;
    while (i < s.length())
    {
        if (s[i] >= '0' && s[i] <= '9')
            hasDigit = true;
        else if (s[i] == '.' && hasDot == false)
            hasDot = true;
        else
            return (false);
        ++i;
    }
    if (hasDigit == false)
        return (false);
    ss << s;
    ss >> value;
    return (!ss.fail());
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file;
    std::string line;

    file.open(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");
    if (!std::getline(file, line))
        throw std::runtime_error("Error: empty database.");
    while (std::getline(file, line))
    {
        std::size_t comma;
        std::string date;
        std::string rateString;
        double rate;

        if (line.empty())
            continue;
        comma = line.find(',');
        if (comma == std::string::npos)
            throw std::runtime_error("Error: bad database line.");
        date = trim(line.substr(0, comma));
        rateString = trim(line.substr(comma + 1));
        if (!isValidDate(date) || !parseNumber(rateString, rate) || rate < 0)
            throw std::runtime_error("Error: bad database line.");
        _rates[date] = rate;
    }
    if (_rates.empty())
        throw std::runtime_error("Error: empty database.");
}

void BitcoinExchange::processInput(const std::string& filename) const
{
    std::ifstream file;
    std::string line;

    file.open(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    if (!std::getline(file, line))
        return;
    if (trim(line) != "date | value")
        processLine(line);
    while (std::getline(file, line))
        processLine(line);
}

double BitcoinExchange::getRateForDate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it;

    it = _rates.lower_bound(date);
    if (it != _rates.end() && it->first == date)
        return (it->second);
    if (it == _rates.begin())
        throw std::runtime_error(
            "Error: no rate available before or on this date."
        );
    --it;
    return (it->second);
}

void BitcoinExchange::processLine(const std::string& line) const
{
    std::size_t sep;
    std::string date;
    std::string valueString;
    double value;
    double rate;

    if (line.empty())
        return;
    sep = line.find('|');
    if (sep == std::string::npos || line.find('|', sep + 1) != std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    date = trim(line.substr(0, sep));
    valueString = trim(line.substr(sep + 1));
    if (!isValidDate(date) || !parseNumber(valueString, value))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    try
    {
        rate = getRateForDate(date);
        std::cout << date << " => " << value << " = "
            << value * rate << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
