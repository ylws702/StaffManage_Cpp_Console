#include "stdafx.h"
#include "StaffList.h"


StaffList::StaffList()
{
}


StaffList::~StaffList()
{
}

void StaffList::Insert(const Staff & staff)
{
    string id(staff.id);
    StaffInfo info(staff);
    staffMap.insert(pair<string, StaffInfo>(id, info));
}

void StaffList::Insert(const Salesman & salesman)
{
    string id(salesman.id);
    StaffInfo info(salesman);
    staffMap.insert(pair<string, StaffInfo>(id, info));
}

void StaffList::Insert(const Manager & manager)
{
    string id(manager.id);
    StaffInfo info(manager);
    staffMap.insert(pair<string, StaffInfo>(id, info));
}

void StaffList::Insert(const SalesManager & salesManager)
{
    string id(salesManager.id);
    StaffInfo info(salesManager);
    staffMap.insert(pair<string, StaffInfo>(id, info));
}

StaffInfo StaffList::Find(const string & id)
{
    auto p = staffMap.find(id);
    if (staffMap.end()==p)
    {
        return StaffInfo();
    }
    return p->second;
}

list<StaffInfo> StaffList::FindName(const string & name)
{
    list<StaffInfo> result;
    for (auto i = staffMap.begin(); i != staffMap.end(); i++)
    {
        if (i->second.name==name)
        {
            result.push_back(i->second);
        }
    }
    return result;
}

list<StaffInfo> StaffList::FindMajor(const string & major)
{
    list<StaffInfo> result;
    for (auto i = staffMap.begin(); i != staffMap.end(); i++)
    {
        if (i->second.major == major)
        {
            result.push_back(i->second);
        }
    }
    return result;
}

list<StaffInfo> StaffList::FindLevel(const string & level)
{
    list<StaffInfo> result;
    for (auto i = staffMap.begin(); i != staffMap.end(); i++)
    {
        if (i->second.level == level)
        {
            result.push_back(i->second);
        }
    }
    return result;
}

list<StaffInfo> StaffList::FindDepartment(const string & department)
{
    list<StaffInfo> result;
    for (auto i = staffMap.begin(); i != staffMap.end(); i++)
    {
        if (i->second.department == department)
        {
            result.push_back(i->second);
        }
    }
    return result;
}

list<StaffInfo> StaffList::FindType(StaffInfo::StaffType type)
{
    list<StaffInfo> result;
    for (auto i = staffMap.begin(); i != staffMap.end(); i++)
    {
        if (i->second.type == type)
        {
            result.push_back(i->second);
        }
    }
    return result;
}

bool StaffList::Remove(const string & id)
{
    auto p = staffMap.find(id);
    if (staffMap.end() == p)
    {
        return false;
    }
    staffMap.erase(p);
    return true;
}

//pair<Staff*, StaffList::StaffType> StaffList::Find(const string & id)
//{
//    auto staff = staffMap.find(id);
//    if (staffMap.end()==staff)
//    {
//        return pair<Staff*, StaffList::StaffType>(nullptr,TStaff);
//    }
//    *(staff->second.first);
//    auto p=new Staff
//    return pair<Staff*, StaffType>();
//}
