#pragma once
#include <string>
#include <sstream>
#include <iomanip>
//#include <time.h>
#include "DateTime.h"

class CLineRecord
{
    std::string m_dateTime;
    std::string m_carName;
    int m_weight;
    //time_t m_Time;
    CDateTime m_t;
public:
    CLineRecord();
    CLineRecord(const std::string &dateTime, const std::string& carName, int weight)
        :m_dateTime(dateTime), m_carName(carName), m_weight(weight)
    {}
    CLineRecord(const std::string& line);
    ~CLineRecord();

    std::string getDateTime();
    std::string getCarName();
    int getWeight();
    CDateTime getT();
    // strToDateTime
};

