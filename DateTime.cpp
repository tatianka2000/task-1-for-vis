#include "StdAfx.h"

CDateTime::CDateTime(const std::string& dateTime)
{
    sscanf(dateTime.c_str(), "%2d.%2d.%4d %2d:%2d", &m_day, &m_month, &m_year, &m_hour, &m_min);
}
