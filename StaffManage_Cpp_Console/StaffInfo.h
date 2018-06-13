#pragma once
#include <fstream>
#include "Staff.h"
class StaffInfo
{
    friend class StaffList;
public:
    StaffInfo();
    StaffInfo(const Staff& staff);
    StaffInfo(const Salesman& salesman);
    StaffInfo(const Manager& manger);
    StaffInfo(const SalesManager& salesManager);
    enum StaffType
    {
        TUnknown,
        TStaff,
        TSalesman,
        TManager,
        TSalesManager
    };
    StaffInfo(
        string id,
        string name,
        unsigned short age,
        string major,
        double sales,
        string department,
        string level,
        double totleSales,
        StaffType type
    );
    ~StaffInfo();
private:
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

