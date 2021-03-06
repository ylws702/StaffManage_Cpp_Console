// StaffManage_Cpp_Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StaffList.h"
#include <iostream>
using namespace std;

StaffList staffList;

bool AddStaff()
{
    char choice;
    cout << "Please choose a item as follows" << endl;
    cout << "1:Add salesman; ";
    cout << "2:Add manager; ";
    cout << "3:Add sales manager; ";
    cout << "4:Back; " << endl;
    cin >> choice;
    if ('1'==choice)
    {
        Salesman saleman;
        saleman.SetInfo();
        staffList.Insert(saleman);
    }
    else if ('2'==choice)
    {
        Manager manager;
        manager.SetInfo();
        staffList.Insert(manager);
    }
    else if('3'==choice)
    {
        SalesManager salesManger;
        salesManger.SetInfo();
        staffList.Insert(salesManger);
    }
    else if ('4'==choice)
    {
        return false;
    }
    else
    {
        cout << "Wrong choice!" << endl;
        return false;
    }
    return true;
}
bool SearchStaff()
{
    cout << "Search staffs by:" << endl;
    cout << "1:ID" << endl;
    cout << "2:Name" << endl;
    cout << "3:Major" << endl;
    cout << "4:Level" << endl;
    cout << "5:Department" << endl;
    cout << "6:Type" << endl ;
    cout << endl;
    cout << "Or, " << endl;
    cout << "7:List all staffs" << endl;
    cout << "8:Back; " << endl;
    cout << endl;
    char choice;
    cin >> choice;
    if ('1' == choice)
    {
        string id;
        cout << "Please enter the id." << endl;
        cout << "id: " << endl;
        cin >> id;
        StaffInfo info = staffList.Find(id);
        if (StaffInfo::TUnknown==info.type)
        {
            cout << "No result." << endl;
        }
        else
        {
            info.Print();
        }
    }
    else if ('2' == choice)
    {
        string name;
        cout << "Please enter the name." << endl;
        cout << "name: " << endl;
        cin >> name;
        auto info = staffList.FindName(name);
        if (info.size() > 0)
        {
            for (auto i : info)
            {
                i.Print();
            }
        }
        else
        {
            cout << "No result." << endl;
        }
    }
    else if ('3' == choice)
    {
        string major;
        cout << "Please enter the major." << endl;
        cout << "major: " << endl;
        cin >> major;
        auto info = staffList.FindMajor(major);
        if (info.size() > 0)
        {
            for (auto i : info)
            {
                i.Print();
            }
        }
        else
        {
            cout << "No result." << endl;
        }
    }
    else if ('4' == choice)
    {
        string level;
        cout << "Please enter the level." << endl;
        cout << "level: " << endl;
        cin >> level;
        auto info = staffList.FindLevel(level);
        if (info.size() > 0)
        {
            for (auto i : info)
            {
                i.Print();
            }
        }
        else
        {
            cout << "No result." << endl;
        }
    }
    else if ('5' == choice)
    {
        string department;
        cout << "Please enter the department." << endl;
        cout << "department: " << endl;
        cin >> department;
        auto info = staffList.FindDepartment(department);
        if (info.size() > 0)
        {
            for (auto i : info)
            {
                i.Print();
            }
        }
        else
        {
            cout << "No result." << endl;
        }
    }
    else if ('6' == choice)
    {
        StaffInfo::StaffType type;
        cout << "Please enter the type." << endl;
        cout << StaffInfo::TStaff << ": Staff" << endl;
        cout << StaffInfo::TSalesman << ": Salesman" << endl;
        cout << StaffInfo::TManager << ": Manager" << endl;
        cout << StaffInfo::TSalesManager << ": SalesManager" << endl;
        cout << "type: " << endl;
        int t;
        cin >> t;
        type = (StaffInfo::StaffType)t;
        auto info = staffList.FindType(type);
        if (info.size() > 0)
        {
            for (auto i : info)
            {
                i.Print();
            }
        }
        else
        {
            cout << "No result." << endl;
        }
    }
    else if ('7' == choice)
    {
        auto info = staffList.FindType(StaffInfo::TStaff);
        if (info.size()> 0)
        {
            for (auto i : info)
            {
                i.Print();
            }
        }
        else
        {
            cout << "No result." << endl;
        }
    }
    else if ('8' == choice)
    {
        cout << "Operation cancled!" << endl;
        return false;
    }
    else
    {
        cout << "Wrong choice!" << endl;
        return false;
    }
    return true;
}

bool RemoveStaff()
{
    cout << "Please enter the id." << endl;
    cout << "id: " << endl;
    string id;
    cin >> id;
    StaffInfo info = staffList.Find(id);
    if (StaffInfo::TUnknown == info.type)
    {
        cout << "No result." << endl;
        return false;
    }
    else
    {
        info.Print();
    }
    char choice;
    cout << "Are you sure to remove?" << endl;
    cout << "(y/n)" << endl;
    cin >> choice;
    if ('y' == choice || 'Y' == choice)
    {
        if (staffList.Remove(id))
        {
            cout << "Remove successfully!" << endl;
            return true;
        }
        else
        {
            cout << "Remove failed!" << endl;
            return false;
        }
    }
    else if ('n' == choice || 'N' == choice)
    {
        cout << "Cancled!" << endl;
        return false;
    }
    else
    {
        return false;
    }
}
bool ReadData()
{
    if (staffList.Read("staff.dat"))
    {
        cout << "Read data successfully!" << endl;
        return true;
    }
    else
    {
        cout << "Read data failed!" << endl;
        return false;
    }
}
bool SaveData()
{
    if (staffList.Save("staff.dat"))
    {
        cout << "Save data successfully!" << endl;
        return true;
    }
    else
    {
        cout << "Save data failed!" << endl;
        return false;
    }
}
void Quit()
{
    cout << "Are you sure to quit?" << endl;
    cout << "(y/n)" << endl;
    char choice;
    cin >> choice;
    if ('y' == choice || 'Y' == choice)
    {
        cout << "Do you want to save data?" << endl;
        cout << "(y/n)" << endl;
        cin >> choice;
        if ('y' == choice || 'Y' == choice)
        {
            if (staffList.Save("staff.dat"))
            {
                cout << "Save data successfully!" << endl;
            }
            else
            {
                cout << "Save data failed!" << endl;
            }
        }
        exit(0);
    }
}
int main()
{
    cout << "************Staff Manage System************" << endl;
    cout << "Please choose a item as follows：" << endl;
    cout << "1:Add staff" << endl;
    cout << "2:Search staff" << endl;
    cout << "3:Remove staff" << endl;
    cout << "4:Read data from file" << endl;
    cout << "5:Save data to file" << endl;
    cout << "6:Quit" << endl;
    cout << endl;
    char choice;
    while (cin >> choice)
    {
        if (choice == '1')
        {
            AddStaff();
        }
        else if (choice == '2')
        {
            SearchStaff();
        }
        else if (choice == '3')
        {
            RemoveStaff();
        }
        else if (choice == '4')
        {
            ReadData();
        }
        else if (choice == '5')
        {
            SaveData();
        }
        else if (choice == '6')
        {
            Quit();
        }
        else 
        {
            cout << "Wrong choise!" << endl;
        }
        cout << endl;
        cout << "Please choose a item as follows:" << endl;
        cout << "1:Add staff" << endl;
        cout << "2:Search staff" << endl;
        cout << "3:Remove staff" << endl;
        cout << "4:Read data from file" << endl;
        cout << "5:Save data to file" << endl;
        cout << "6:Quit"  << endl;
        cout << endl;
    }
    return 0;
}

