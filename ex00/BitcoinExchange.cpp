#include "BitcoinExchange.hpp"
#include <stdlib.h>

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : data(src.data)
{

}

BitcoinExchange::BitcoinExchange(/* args */) { }

BitcoinExchange::BitcoinExchange(const char *filename)
{

    FillData();
    StartReadingInputFile(filename);
}

void    BitcoinExchange::FillData()
{
    std::ifstream dataFile;
    std::string line;

    dataFile.open("data.csv");

    while (std::getline(dataFile, line))
    {
        try
        {
            AddRawData(line);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    for (std::map<Date, float>::iterator iter = data.begin(); iter != data.end(); iter++)
    {
        std::cout << iter->first.year << "-" << iter->first.month << "-"
            << iter->first.day << std::endl;
    }
    
    std::cout << "Number of filled lines: " << data.size() << std::endl;
}

void    BitcoinExchange::AddRawData(const std::string &line)
{
    size_t pos = line.find(",");

    std::string value = line.substr(pos + 1);
    float val = std::atof(value.c_str());
    std::string dateString = line.substr(0, pos);
    Date date = Date(dateString);
    std::pair<Date, float> dataRaw(date, val);
    data.insert(dataRaw);
}

void    BitcoinExchange::StartReadingInputFile(const std::string &inputFile)
{

    std::ifstream input;
    std::string line;

    input.open(inputFile.c_str());

    // ignoring the first line
    std::getline(input, line);
        
    while (std::getline(input, line))
    {
        try
        {
            AnalyseInputRaw(line);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

void    BitcoinExchange::AnalyseInputRaw(const std::string &line)
{
    size_t pos = line.find(" | ");

    if (pos == std::string::npos)
        throw BtcException("Bad Input => " + line);
    std::string value = line.substr(pos + 3);

    float val = std::atof(value.c_str());
    if (val < 0)
        throw BtcException("Error: not a positive number.");
    else if (val > 1000)
        throw BtcException("Error: too large number.");

    std::string dateString = line.substr(0, pos);
    Date date = Date(dateString);
    std::map<Date, float>::iterator closest = data.lower_bound(date);
    if (date != closest->first)
        --closest;
    std::cout << dateString << " => " << val << " = "
        << val * closest->second << std::endl;
}

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        data = rhs.data;
    }
    return (*this);
}
