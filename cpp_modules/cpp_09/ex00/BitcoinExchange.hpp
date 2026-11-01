#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _rates;

    std::string trim(const std::string& str) const;
    bool        isValidDate(const std::string& date) const;
    bool        isLeapYear(int year) const;
    int         daysInMonth(int year, int month) const;
    bool        parseNumber(const std::string& str, double& value) const;
    void        processLine(const std::string& line) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void        loadDatabase(const std::string& filename);
    void        processInput(const std::string& filename) const;
    double      getRateForDate(const std::string& date) const;
};

#endif 
