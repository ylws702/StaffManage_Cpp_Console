#include "stdafx.h"
#include "StaffInfo.h"


StaffInfo::StaffInfo()
{
}

StaffInfo::StaffInfo(const Staff & staff):
    id(staff.id),
    name(staff.name),
    age(staff.age),
    type(TStaff)
{
}

StaffInfo::StaffInfo(const Salesman & salesman):
    id(salesman.id),
    name(salesman.name),
    age(salesman.age),
    major(salesman.major),
    sales(salesman.sales),
    type(TSalesman)
{
}

StaffInfo::StaffInfo(const Manager & manger):
    id(manger.id),
    name(manger.name),
    age(manger.age),
    department(manger.department),
    level(manger.level),
    type(TManager)
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
    totleSales(salesManager.totalSales),
    type(TSalesManager)
{
}


StaffInfo::StaffInfo(
    string i,
    string n,
    unsigned short a,
    string m,
    double s,
    string d,
    string l,
    double t,
    StaffType ty) :
    id(i),
    name(n),
    age(a),
    major(m),
    sales(s),
    department(d),
    level(l),
    totleSales(t),
    type(ty)
{
}

StaffInfo::~StaffInfo()
{
}
