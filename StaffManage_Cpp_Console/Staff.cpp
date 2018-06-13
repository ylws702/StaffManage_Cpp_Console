#include "stdafx.h"
#include "Staff.h"


Staff::Staff()
{
}

Staff::~Staff()
{
}
void Staff::SetInfo()
{
    cout << "Please enter the ID:" << endl;
    cin >> id;
    cout << "Please enter the name:" << endl;
    cin >> name;
    cout << "Please enter the age:" << endl;
    cin >> age;
}
string Staff::GetName() const
{
    return name;
}
string Staff::GetId() const
{
    return id;
}
unsigned short Staff::GetAge() const
{
    return age;
}
inline bool Staff::operator==(const Staff & s) const
{
    return name == s.name&&id == s.id&&age == s.age;
}
inline bool Staff::operator!=(const Staff & s) const
{
    return !(*this == s);
}

Salesman::Salesman()
{
}

Salesman::~Salesman()
{
}

void Salesman::SetInfo()
{
    Staff::SetInfo();
    cout << "Please enter the major:" << endl;
    cin >> major;
    cout << "Please enter the title:" << endl;
    cin >> sales;
}

string Salesman::GetMajor() const
{
    return major;
}

double Salesman::GetSales() const
{
    return sales;
}

inline bool Salesman::operator==(const Salesman & s) const
{
    return Staff::operator==(s) && major == s.major&&sales == s.sales;
}

inline bool Salesman::operator!=(const Salesman & s) const
{
    return !(*this == s);
}

Manager::Manager()
{
}

Manager::~Manager()
{
}
void Manager::SetInfo()
{
    Staff::SetInfo();
    cout << "Please enter the department:" << endl;
    cin >> department;
    cout << "Please enter the job:" << endl;
    cin >> level;
}

string Manager::GetDepartment() const
{
    return department;
}
string Manager::GetLevel() const
{
    return level;
}
inline bool Manager::operator==(const Manager & m) const
{
    return Staff::operator==(m) && department == m.department&&level == m.level;
}
inline bool Manager::operator!=(const Manager & m) const
{
    return !(*this == m);
}
SalesManager::SalesManager()
{
}

SalesManager::~SalesManager()
{
}
void SalesManager::SetInfo()
{
    Salesman::SetInfo();
    cout << "Please enter the department:" << endl;
    cin >> department;
    cout << "Please enter the job:" << endl;
    cin >> level;
}

double SalesManager::GetTotalSales() const
{
    return totalSales;
}

inline bool SalesManager::operator==(const SalesManager & sm) const
{
    return Salesman::operator==(sm) && department == sm.department&&level == sm.level;
}

inline bool SalesManager::operator!=(const SalesManager & sm) const
{
    return !(*this == sm);
}
