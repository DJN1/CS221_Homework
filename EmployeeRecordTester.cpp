#include <iostream>
#include "EmployeeRecord.h"
#include "CustomerList.h"

using namespace std;

	

int main()
{
	cout << "called main" << endl;
	testEmployee();
	testCustomerList();
	return 0;
}

void testEmployee()
{
	int employeeDept = 0;
	int employeeID;
	char employeeFName[32];
	char employeeLName[32];
	char* employeeFNamePtr = employeeFName;
	char* employeeLNamePtr = employeeLName;
	char newEmployeeFirstName[] = "Jerry";
	char newEmployeeLastName[] = "Smith";
	char* newEmployeeFirstNamePtr = newEmployeeFirstName;
	char* newEmployeeLastNamePtr = newEmployeeLastName;
	double employeeSalary = 0;
	// function tests
	EmployeeRecord rec = EmployeeRecord(0, newEmployeeFirstNamePtr, newEmployeeLastNamePtr, 1, 200000);
	cout << "Employee ID: " << rec.getID() << endl;
	rec.setID(9);
	rec.getName(employeeFNamePtr, employeeLNamePtr);
	cout << "Employee first name: ";
	cout << endl << "Employee last name: ";
	rec.setName(newEmployeeFirstNamePtr, newEmployeeLastNamePtr);
	cout << "Employee Department: " << rec.getDept() << endl;
	rec.setDept(3);
	cout << "Employee salary: " << rec.getSalary() << endl;
	rec.setSalary(100000);
	rec.printRecord();
}

void testCustomerList()
{
	CustomerList CL = new CustomerList();
	CL.printStoresInfo();
}