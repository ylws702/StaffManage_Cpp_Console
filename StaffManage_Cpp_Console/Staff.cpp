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
void Staff::PrintInfo()const
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
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
    cin >> title;
}

void Salesman::PrintInfo()const
{
    Staff::PrintInfo();
    cout << "Major: " << major << endl;
    cout << "Title: " << major << endl;
}

string Salesman::GetMajor() const
{
    return major;
}

string Salesman::GetTitle() const
{
    return title;
}

inline bool Salesman::operator==(const Salesman & s) const
{
    return Staff::operator==(s) && major == s.major&&title == s.title;
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
    cin >> job;
}
void Manager::PrintInfo()const
{
    Staff::PrintInfo();
    cout << "Department: " << department << endl;
    cout << "Job: " << job << endl;

}
string Manager::GetDepartment() const
{
    return department;
}
string Manager::GetJob() const
{
    return job;
}
inline bool Manager::operator==(const Manager & m) const
{
    return Staff::operator==(m) && department == m.department&&job == m.job;
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
    cin >> job;
}
void SalesManager::PrintInfo()const
{
    Salesman::PrintInfo();
    cout << "Department: " << department << endl;
    cout << "Job: " << job << endl;
}

inline bool SalesManager::operator==(const SalesManager & sm) const
{
    return Salesman::operator==(sm) && department == sm.department&&job == sm.job;
}

inline bool SalesManager::operator!=(const SalesManager & sm) const
{
    return !(*this == sm);
}
