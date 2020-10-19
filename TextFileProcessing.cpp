// TextFileProcessing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

/*--------- ��� ������ ������������ ������ ���� ���������� � FileWrapper.cpp, 
� ���������� � �������� ��������� ��� sort: 
void FileWrapper::SortData()
{
     listRecords.sort(dateTimeCompare1);
     listRecords.sort(truckCompare);
}
�� ��������� �������, �������� �� ����������
stdafx.obj : error LNK2005: "class std::list<class CLineRecord,class std::allocator<class CLineRecord> > FileWrapper::listRecords" (?listRecords@FileWrapper@@3V?$list@VCLineRecord@@V?$allocator@VCLineRecord@@@std@@@std@@A) already defined in FileWrapper.obj
��� ������ �� main() �� ���������� ������� ��������

��� ������������� ����������� ����
listRecords.sort([]( CLineRecord d1,  CLineRecord d2)
    {
        return (d1.getCarName() < d2.getCarName());
    });
������� ����������� ������ ���� � main(), ���� �������� �� ��� �������.
����� ���� ���� �� ���� ������, ���� ����� �� �����...

*/
bool truckCompare( CLineRecord d1,  CLineRecord d2)
{
    return (d1.getCarName() < d2.getCarName());
}

bool dateTimeCompare( CLineRecord lr1,  CLineRecord lr2)
{
    CDateTime d1 = lr1.getT();
    CDateTime d2 = lr2.getT();
    if(d1.m_year != d2.m_year) return (d1.m_year < d2.m_year);
    if(d1.m_month != d2.m_month) return (d1.m_month < d2.m_month);
    if(d1.m_day != d2.m_day) return (d1.m_day < d2.m_day);
    if(d1.m_hour != d2.m_hour) return (d1.m_hour < d2.m_hour);
    return (d1.m_min < d2.m_min);

}
//---------

int _tmain(int argc, _TCHAR* argv[])
{
    std::string inFileName = "table.txt";

    TCHAR buf[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, buf);
    std::string currentDir(buf);

    if(!currentDir.empty())
    {
        inFileName = currentDir+"\\table.txt";
        
        std::list<CLineRecord> listRecords; // ������ ���� � FileWrapper, ��. ������� ����
        FileWrapper::ReadDataFromFile(inFileName, &listRecords);
        if(listRecords.empty())
        {
            cout << "cannot open input file or file is empty";
            return 0;
        }
        //FileWrapper::SortData();
        listRecords.sort(dateTimeCompare);
        listRecords.sort(truckCompare);
        FileWrapper::GenerateOutFiles(currentDir, listRecords);
    }

    return 0;
}

