#pragma once
#include <map>
#include "Staff.h"
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
private:
    map<string, pair<Staff*, StaffType>> staffMap;
};

