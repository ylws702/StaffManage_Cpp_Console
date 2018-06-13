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
