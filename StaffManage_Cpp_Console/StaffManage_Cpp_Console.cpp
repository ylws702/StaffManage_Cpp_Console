// StaffManage_Cpp_Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StaffList.h"

int main()
{
    Salesman a;
    a.SetInfo();
    StaffList L;
    L.Insert(a);
    
    return 0;
}

