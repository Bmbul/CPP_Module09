#if !defined(BITCOIN_EXCHANGE_HPP)
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include "BtcException.hpp"
#include "Date.hpp"

class BitcoinExchange
{
    // typedef struct tm   Date;

    private:
        std::map<Date, float> data;
        BitcoinExchange(/* args */);
        
        void    AddRawData(const std::string &line);
        void    AnalyseInputRaw(const std::string &line);

        void    FillData();
        void    StartReadingInputFile(const std::string &inputFile);

    public:
        BitcoinExchange(const char *filename);
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();

        BitcoinExchange operator=(const BitcoinExchange &rhs);
};

#endif // BITCOIN_EXCHANGE_HPP
