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
    totalSales(salesManager.totalSales),
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
    totalSales(t),
    type(ty)
{
}

StaffInfo::~StaffInfo()
{
}

void StaffInfo::Print()
{
    switch (type)
    {
    case TUnknown:
        cout << "Unknown" << endl;
        break;
    case TStaff:
        cout << "Staff" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        break;
    case TSalesman:
        cout << "Salesman" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Major: " << major << endl;
        cout << "Sales: " << sales << endl;
        break;
    case TManager:
        cout << "Manager" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Level: " << level << endl;
        break;
    case TSalesManager:
        cout << "SalesManager" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Major: " << major << endl;
        cout << "Sales: " << sales << endl;
        cout << "Department: " << department << endl;
        cout << "Level: " << level << endl;
        cout << "Total sales: " << totalSales << endl;
        break;
    default:
        cout << "Unknown Error" << endl;
        break;
    }
    cout << endl;
}
