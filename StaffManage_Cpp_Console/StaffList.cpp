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
    Staff* p = new Staff(staff);
    staffMap.insert(
        pair<string, pair<Staff*, StaffType>>(
            p->id,
            pair<Staff*, StaffType>(p, TStaff)
            )
    );
}

void StaffList::Insert(const Salesman & salesman)
{
    Salesman* p = new Salesman(salesman);
    staffMap.insert(
        pair<string, pair<Staff*, StaffType>>(
            p->id,
            pair<Staff*, StaffType>(p, TSalesman)
            )
    );
}

void StaffList::Insert(const Manager & manager)
{
    Manager* p = new Manager(manager);
    staffMap.insert(
        pair<string, pair<Staff*, StaffType>>(
            p->id,
            pair<Staff*, StaffType>(p, TManager)
            )
    );
}

void StaffList::Insert(const SalesManager & salesManager)
{
    SalesManager* p = new SalesManager(salesManager);
    staffMap.insert(
        pair<string, pair<Staff*, StaffType>>(
            p->id,
            pair<Staff*, StaffType>(p, TSalesManager)
            )
    );
}
