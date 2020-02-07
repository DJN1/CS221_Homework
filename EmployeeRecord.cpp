#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "EmployeeRecord.h"

using namespace std;

EmployeeRecord::EmployeeRecord()
{
	cout << "called standard constructor" << endl;
	m_iEmployeeID = 0;
	strcpy(m_sFirstName, "");
	strcpy(m_sLastName, "");
	m_iDeptID = 0;
	m_dSalary = 0.0;
}

EmployeeRecord::EmployeeRecord(int ID, char* fName, char* lName, int dept, double sal)
{
	cout << "called custom constructor" << endl;
	m_iEmployeeID = ID;
	strcpy(m_sFirstName, fName);
	strcpy(m_sLastName, lName);
	m_iDeptID = dept;
	m_dSalary = sal;
}

EmployeeRecord::~EmployeeRecord()
{
}


int EmployeeRecord::getID()
{	
	cout << "Called EmployeeRecord::getID()" << endl;
	return m_iEmployeeID;
}

void EmployeeRecord::setID(int ID)
{
	cout << "Called EmployeeRecord::setID()" << endl;
	m_iEmployeeID = ID;
}


void EmployeeRecord::getName(char* fName, char* lName)
{
	cout << "Called EmployeeRecord::getName()" << endl;
	strcpy(fName, m_sFirstName);
	strcpy(lName, m_sLastName);
}

void EmployeeRecord::setName(char* fName, char* lName)
{
	cout << "Called EmployeeRecord::setName()" << endl;
	strcpy(m_sFirstName, fName);
	strcpy(m_sLastName, lName);
}

void EmployeeRecord::getDept(int& d)
{
	cout << "Called EmployeeRecord::getDept()" << endl;
	d = m_iDeptID;
}

void EmployeeRecord::setDept(int d)
{
	cout << "Called EmployeeRecord::setDeot()" << endl;
	m_iDeptID = d;
}

void EmployeeRecord::getSalary(double* sal)
{
	cout << "Called EmployeeRecord::getSalary()" << endl;
	*sal =  m_dSalary;
}

void EmployeeRecord::setSalary(double sal)
{
	cout << "Called EmployeeRecord::setSalary()" << endl;
	m_dSalary = sal;
}

void EmployeeRecord::printRecord()
{
	cout << "################# EMPLOYEE RECORD #################" << endl;
	cout << "Employee ID: " << m_iEmployeeID << endl;
	cout << "Employee First Name: " << m_sFirstName << endl;
	cout << "Employee Last Name: " << m_sLastName << endl;
	cout << "Employee Department: " << m_iDeptID << endl;
	cout << "Employee Salary: " << m_dSalary << endl;
	cout << "###################################################" << endl;
}