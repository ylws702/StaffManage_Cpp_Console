#pragma once
#include "Staff.h"
class StaffInfo
{
public:
    StaffInfo();
    StaffInfo(const Staff& staff);
    StaffInfo(const Salesman& salesman);
    StaffInfo(const Manager& manger);
    StaffInfo(const SalesManager& salesManager);
    ~StaffInfo();
    enum StaffType
    {
        TUnknown,
        TStaff,
        TSalesman,
        TManager,
        TSalesManager
    };
    string id;
    string name;
    unsigned short age{ 0 };
    string major;
    double sales{ 0.0 };
    string department;
    string level;
    double totleSales{ 0.0 };
    StaffType type{ TUnknown };
};

