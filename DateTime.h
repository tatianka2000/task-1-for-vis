#pragma once
struct CDateTime
{
    int m_year;
    int m_day; 
    int m_month;
    int m_hour;
    int m_min;
public:
    CDateTime(){};
    CDateTime(const std::string&);

};

