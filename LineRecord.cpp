#include "StdAfx.h"


CLineRecord::CLineRecord(const std::string& line)
{
    auto comma_pos = line.find(',');
    m_dateTime = line.substr(0, comma_pos);

    auto comma_pos1 = line.find(',', comma_pos+1);
    m_carName = line.substr(comma_pos + 2, comma_pos1 - comma_pos - 2 );

    m_weight = atoi(line.substr(comma_pos1 + 1).c_str()); 

    m_t = CDateTime(m_dateTime);  
}


CLineRecord::~CLineRecord(void)
{
}

std::string CLineRecord::getDateTime()
{
    return m_dateTime;
}

std::string CLineRecord::getCarName()
{
    return m_carName;
}

int CLineRecord::getWeight()
{
    return m_weight;
}

CDateTime CLineRecord::getT()
{
    return m_t;
}
