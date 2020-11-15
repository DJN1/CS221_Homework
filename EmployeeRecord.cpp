#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
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
	m_pCustomerList = new CustomerList();
	m_pLeft = NULL;
	m_pRight = NULL;
}

EmployeeRecord::EmployeeRecord(int ID, char* fName, char* lName, int dept, double sal)
{
	cout << "called custom constructor" << endl;
	m_iEmployeeID = ID;
	strcpy(m_sFirstName, fName);
	strcpy(m_sLastName, lName);
	m_iDeptID = dept;
	m_dSalary = sal;
	m_pCustomerList = new CustomerList();
	m_pLeft = NULL;
	m_pRight = NULL;
}

EmployeeRecord::~EmployeeRecord()
{
	if (m_pCustomerList != NULL)
	{
		removeCustomerList();
		destroyCustomerList();
	}
	else
	{
		destroyCustomerList();
	}
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

int EmployeeRecord::getDept()
{
	cout << "Called EmployeeRecord::getDept()" << endl;
	return m_iDeptID;
}

void EmployeeRecord::setDept(int d)
{
	cout << "Called EmployeeRecord::setDeot()" << endl;
	m_iDeptID = d;
}

double EmployeeRecord::getSalary()
{
	cout << "Called EmployeeRecord::getSalary()" << endl;
	return m_dSalary;
}

void EmployeeRecord::setSalary(double sal)
{
	cout << "Called EmployeeRecord::setSalary()" << endl;
	m_dSalary = sal;
}

void EmployeeRecord::printRecord()
{
	cout << setw(10) << m_iEmployeeID;
	cout << setw(33) << m_sFirstName;
	cout << setw(33) << m_sLastName;
	cout << setw(8) << m_iDeptID;
	cout << setw(11) << "$" << m_dSalary << endl;
}

CustomerList* EmployeeRecord::getCustomerList()
{
	return m_pCustomerList;
}

void EmployeeRecord::removeCustomerList()
{
	m_pCustomerList = NULL;
}

void EmployeeRecord::destroyCustomerList()
{
	delete m_pCustomerList;
	m_pCustomerList = NULL;
}