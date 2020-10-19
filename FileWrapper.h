#pragma once
#include <list>
#include "LineRecord.h"

namespace FileWrapper
{

    static const char delim = ',';
    //std::list<CLineRecord> listRecords; // look comments in TextFileProcessing.cpp
    void ReadDataFromFile(const std::string& inputFileName, std::list<CLineRecord> *listRecords);
    void SortData();
    void GenerateOutFiles(const std::string& outFileDir, std::list<CLineRecord> listRecords);
    
}