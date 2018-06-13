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
    if (staffMap.end() == p)
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
        if (i->second.name == name)
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
        if (i->second.major == major
            && (StaffInfo::TSalesman == i->second.type
                || StaffInfo::TSalesManager == i->second.type))
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
        if (i->second.level == level
            && (StaffInfo::TManager == i->second.type
                || StaffInfo::TSalesManager == i->second.type))
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
        if (i->second.department == department
            && (StaffInfo::TManager == i->second.type
                || StaffInfo::TSalesManager == i->second.type))
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

bool StaffList::Save(const string & path)
{
    ofstream f(path, ios::binary);
    int length;
    string str;
    if (f.fail())
    {
        cout << "Cannot open " << path << " !" << endl;
        return false;
    }
    for (auto p : staffMap)
    {
        length = p.second.id.size();
        f.write((char *)&length, sizeof(int));
        f.write((char *)&p.second.id[0], length);

        length = p.second.name.size();
        f.write((char *)&length, sizeof(int));
        f.write((char *)&p.second.name[0], length);

        f.write(
            (char *)&p.second.age,
            sizeof(unsigned short)
        );

        length = p.second.major.size();
        f.write((char *)&length, sizeof(int));
        f.write((char *)&p.second.major[0], length);

        f.write((char *)&p.second.sales, sizeof(double));

        length = p.second.department.size();
        f.write((char *)&length, sizeof(int));
        f.write((char *)&p.second.department[0], length);

        length = p.second.level.size();
        f.write((char *)&length, sizeof(int));
        f.write((char *)&p.second.level[0], length);

        f.write((char *)&p.second.totalSales, sizeof(double));

        f.write(
            (char *)&p.second.type,
            sizeof(StaffInfo::StaffType)
        );
    }
    f.close();
    cout << "Data successfully saved!" << endl;
    return true;
}

bool StaffList::Read(const string & path)
{
    ifstream f;
    int length;
    int num = 0;
    string id;
    string name;
    unsigned short age{ 0 };
    string major;
    double sales{ 0.0 };
    string department;
    string level;
    double totleSales{ 0.0 };
    StaffInfo::StaffType type{ StaffInfo::TUnknown };
    f.open(path, ios::binary);
    if (f.fail())
    {
        cout << "Cannot open " << path << " !" << endl;
        return false;
    }
    while (!f.read((char *)&length, sizeof(int)).eof())
    {
        id.resize(length);
        f.read((char *)&id[0], length);

        f.read((char *)&length, sizeof(int));
        name.resize(length);
        f.read((char *)&name[0], length);

        f.read((char *)&age, sizeof(unsigned short));

        f.read((char *)&length, sizeof(int));
        major.resize(length);
        f.read((char *)&major[0], length);

        f.read((char *)&sales, sizeof(double));

        f.read((char *)&length, sizeof(int));
        department.resize(length);
        f.read((char *)&department[0], length);

        f.read((char *)&length, sizeof(int));
        level.resize(length);
        f.read((char *)&level[0], length);

        f.read((char *)&age, sizeof(unsigned short));

        f.read((char *)&type, sizeof(StaffInfo::StaffType));
        staffMap.emplace(
            id,
            StaffInfo(
                id,
                name,
                age,
                major,
                sales,
                department,
                level,
                age,
                type
            )
        );
        num++;
    }
    cout << num << " staff(s) successfully read." << endl;
    return true;
}
