#include <iostream>
#include "EmployeeRecord.h"

using namespace std;

	

int main()
{
	int employeeDept = 0;
	int employeeID;
	char employeeFName[32];
	char employeeLName[32];
	char* employeeFNamePtr = employeeFName;
	char* employeeLNamePtr = employeeLName;
	int& employeeDeptRef = employeeDept;
	char newEmployeeFirstName[] = "Jerry";
	char newEmployeeLastName[] = "Smith";
	char* newEmployeeFirstNamePtr = newEmployeeFirstName;
	char* newEmployeeLastNamePtr = newEmployeeLastName;
	double employeeSalary = 0;
	double* employeeSalaryPtr = &employeeSalary;
	// function tests
	EmployeeRecord rec = EmployeeRecord(0, newEmployeeFirstNamePtr, newEmployeeLastNamePtr, 1, 200000);
	employeeID = rec.getID();
	rec.setID(9);
	rec.getName(employeeFNamePtr, employeeLNamePtr);
	cout << "Employee first name: ";
	cout << endl << "Employee last name: ";
	rec.setName(newEmployeeFirstNamePtr, newEmployeeLastNamePtr);
	rec.getDept(employeeDeptRef);
	cout << endl << "Employee dept: " << employeeDeptRef << endl;
	rec.setDept(3);
	rec.getSalary(employeeSalaryPtr);
	cout << "Employee salary: " << *employeeSalaryPtr << endl;
	rec.setSalary(100000);
	rec.printRecord();
	system("pause");
	return 0;
}