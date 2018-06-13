#pragma once
#include <iostream>
#include <string>
using namespace std;

class Staff
{
    friend class StaffInfo;
    friend class StaffList;
public:
    Staff();
    ~Staff();
    void SetInfo();
    void PrintInfo() const;
    string GetName()const;
    string GetId()const;
    unsigned short GetAge()const;
    bool operator==(const Staff &s)const;
    bool operator!=(const Staff &s)const;
protected:
    string name;
    string id;
    unsigned short age;

};
class Salesman
    :virtual public Staff
{
    friend class StaffInfo;
    friend class StaffList;
public:
    Salesman();
    ~Salesman();
    void SetInfo();
    void PrintInfo()const;
    string GetMajor()const;
    double GetSales()const;
    bool operator==(const Salesman &s)const;
    bool operator!=(const Salesman &s)const;
protected:
    string major;
    double sales;
};

class Manager
    :virtual public Staff
{
    friend class StaffInfo;
    friend class StaffList;
public:
    Manager();
    ~Manager();
    void SetInfo();
    void PrintInfo()const;
    string GetDepartment()const;
    string GetLevel()const;
    bool operator==(const Manager &m)const;
    bool operator!=(const Manager &m)const;
protected:
    string department;
    string level;
};
class SalesManager :
    public Salesman, public Manager
{
    friend class StaffInfo;
    friend class StaffList;
public:
    SalesManager();
    ~SalesManager();
    void SetInfo();
    void PrintInfo()const;
    double GetTotalSales()const;
    bool operator==(const SalesManager &sm)const;
    bool operator!=(const SalesManager &sm)const;
private:
    double totalSales;
};
