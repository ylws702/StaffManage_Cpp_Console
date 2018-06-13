#include "stdafx.h"
#include "StaffInfo.h"


StaffInfo::StaffInfo()
{
}

StaffInfo::StaffInfo(const Staff & staff):
    id(staff.id),
    name(staff.name),
    age(staff.age)
{
}

StaffInfo::StaffInfo(const Salesman & salesman):
    id(salesman.id),
    name(salesman.name),
    age(salesman.age),
    major(salesman.major),
    sales(salesman.sales)
{
}

StaffInfo::StaffInfo(const Manager & manger):
    id(manger.id),
    name(manger.name),
    age(manger.age),
    department(manger.department),
    level(manger.level)
{
}

StaffInfo::StaffInfo(const SalesManager & salesManager):
    id(salesManager.id),
    name(salesManager.name),
    age(salesManager.age),
    major(salesManager.major),
    sales(salesManager.sales),
    department(salesManager.department),
    level(salesManager.level),
    totleSales(salesManager.totalSales)
{
}


StaffInfo::~StaffInfo()
{
}
