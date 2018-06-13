#pragma once
#include <map>
#include "StaffInfo.h"
using namespace std;
class StaffList
{
public:
    StaffList();
    ~StaffList();
    enum StaffType
    {
        TStaff,
        TSalesman,
        TManager,
        TSalesManager
    };
    void Insert(const Staff& staff);
    void Insert(const Salesman& salesman);
    void Insert(const Manager& manager);
    void Insert(const SalesManager& salesManager);
    pair<Staff*, StaffType> Find(const string& id);
private:
    map<string, StaffInfo> staffMap;
};

