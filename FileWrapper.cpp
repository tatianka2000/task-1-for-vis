#include "stdafx.h"
//#include "FileWrapper.h"
#include <fstream>
#include <iostream>


using namespace std;

/*
namespace FileWrapper{

static bool truckCompare( CLineRecord d1,  CLineRecord d2)
{
    return (d1.getCarName() < d2.getCarName());
}
static bool dateTimeCompare( CLineRecord d1,  CLineRecord d2)
{
    if(d1.getT().m_year != d2.getT().m_year) return (d1.getT().m_year < d2.getT().m_year);
    if(d1.getT().m_month != d2.getT().m_month) return (d1.getT().m_month < d2.getT().m_month);
    if(d1.getT().m_day != d2.getT().m_day) return (d1.getT().m_day < d2.getT().m_day);
    if(d1.getT().m_hour != d2.getT().m_hour) return (d1.getT().m_hour < d2.getT().m_hour);
    return (d1.getT().m_min < d2.getT().m_min);
}

static bool dateTimeCompare1( CLineRecord lr1,  CLineRecord lr2)
{
    CDateTime d1 = lr1.getT();
    CDateTime d2 = lr2.getT();
    if(d1.m_year != d2.m_year) return (d1.m_year < d2.m_year);
    if(d1.m_month != d2.m_month) return (d1.m_month < d2.m_month);
    if(d1.m_day != d2.m_day) return (d1.m_day < d2.m_day);
    if(d1.m_hour != d2.m_hour) return (d1.m_hour < d2.m_hour);
    return (d1.m_min < d2.m_min);

}


}
*/
void FileWrapper::ReadDataFromFile(const std::string& inputFileName, std::list<CLineRecord> *listRecords)
{
    std::ifstream inputFile(inputFileName.c_str());
    if(!inputFile)
    {
        std::cerr <<"error - filestream not open";
    }
    else
    {
        while(inputFile)
        {
            std::string buf;
            getline(inputFile, buf);
            if(buf.size()) // skip empty lines
            {
                listRecords->push_back(CLineRecord(buf));
            }
        }
    inputFile.close();
    }
}

void FileWrapper::SortData()
{
    // sort by date, then by truck name
//     listRecords.sort(dateTimeCompare);
//     listRecords.sort(truckCompare);
}

// GenerateOutFiles works with list sorted by SortData
void FileWrapper::GenerateOutFiles(const std::string& outFileDir, std::list<CLineRecord> listRecords)
{
    ofstream outFile;
 
    //std::string dirPath = "C:\\documents and settings\\tatianka\\мои документы\\visual studio 2010\\Projects\\TextFileProcessing\\Debug";
  // get list sorted by time and truck name

    string curCarName = listRecords.begin()->getCarName();
    std::string outFileName = outFileDir+"\\"+curCarName+".txt";   
    outFile.open(outFileName.c_str());

    int sum = 0;
    for(std::list<CLineRecord>::iterator it = listRecords.begin(); it != listRecords.end(); it++)
    {
        if(curCarName == it->getCarName())
        {
            sum += it->getWeight();
            outFile << it->getDateTime().c_str() << ", " << it->getCarName().c_str() << ", " << it->getWeight() << endl;     
        }
        else
        {
            outFile << endl << sum;
            curCarName = it->getCarName();
            outFile.close();
            outFile.open((outFileDir+"\\"+curCarName+".txt").c_str());
            sum = it->getWeight();
            outFile << it->getDateTime().c_str() << ", " << it->getCarName().c_str() << ", " << it->getWeight() << endl;     
        }
    }

    outFile << endl << sum;
    outFile.close();
}
