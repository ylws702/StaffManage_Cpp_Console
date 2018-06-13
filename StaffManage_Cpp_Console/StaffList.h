#pragma once
#include <map>
#include <list>
#include "StaffInfo.h"
using namespace std;
class StaffList
{
public:
    StaffList();
    ~StaffList();
    void Insert(const Staff& staff);
    void Insert(const Salesman& salesman);
    void Insert(const Manager& manager);
    void Insert(const SalesManager& salesManager);
    StaffInfo Find(const string& id);
    list<StaffInfo> FindName(const string& name);
    list<StaffInfo> FindMajor(const string& major);
    list<StaffInfo> FindLevel(const string& level);
    list<StaffInfo> FindDepartment(const string& department);
    list<StaffInfo> FindType(StaffInfo::StaffType type);
    bool Remove(const string& id);
private:
    map<string, StaffInfo> staffMap;
};

