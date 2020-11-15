#include <iostream>
#include "EmployeeRecord.h"
#include "CustomerList.h"
#include "Store.h"
#include "EmployeeDatabase.h"


using namespace std;


void testEmployee()
{
	int employeeDept = 0;
	char employeeFName[32];
	char employeeLName[32];
	char* employeeFNamePtr = employeeFName;
	char* employeeLNamePtr = employeeLName;
	char newEmployeeFirstName[] = "Jerry";
	char newEmployeeLastName[] = "Smith";
	char* newEmployeeFirstNamePtr = newEmployeeFirstName;
	char* newEmployeeLastNamePtr = newEmployeeLastName;
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
	int newID = 1;
	char newName[] = "Store1";
	char newAddr[] = "1234 Main Street";
	char newCity[] = "Miami";
	char newSt[] = "Florida";
	char newZip[] = "123456";
	char* newNamePtr = newName;
	char* newAddrPtr = newAddr;
	char* newCityPtr = newCity;
	char* newStPtr = newSt;
	char* newZipPtr = newZip;
	Store* newStore = new Store(newID, newNamePtr, newAddrPtr, newCityPtr, newStPtr, newZipPtr);
	int newID2 = 2;
	char newName2[] = "Main Store";
	char newAddr2[] = "111 Central Avenue";
	char newCity2[] = "New York";
	char newSt2[] = "New York";
	char newZip2[] = "150248";
	char* newName2Ptr = newName2;
	char* newAddr2Ptr = newAddr2;
	char* newCity2Ptr = newCity2;
	char* newSt2Ptr = newSt2;
	char* newZip2Ptr = newZip2;
	Store* newStore2 = new Store(newID2, newName2Ptr, newAddr2Ptr, newCity2Ptr, newSt2Ptr, newZip2Ptr);
	Store* tempStore = NULL;
	CustomerList* CL = new CustomerList();
	int updateID = 1;
	char updateName[] = "Store 5";
	char updateAddr[] = "604 Palms Avenue";
	char updateCity[] = "Atlanta";
	char updateSt[] = "Georgia";
	char updateZip[] = "654321";
	char* updateNamePtr = updateName;
	char* updateAddrPtr = updateAddr;
	char* updateCityPtr = newCity;
	char* updateStPtr = newSt;
	char* updateZipPtr = updateZip;
	CL->printStoresInfo();
	cout << "Add Store: " << CL->addStore(newStore) << endl;
	tempStore = CL->getStore(1);
	cout << "Get Store(1): " << tempStore->getStoreName() << endl;
	CL->printStoresInfo();
	cout << "Add Store: " << CL->addStore(newStore2) << endl;
	CL->printStoresInfo();
	tempStore = CL->removeStore(2);
	cout << "Get Store(0): " << tempStore->getStoreName() << endl;
	cout << "Remove Store: " << CL->removeStore(0) << endl;
	cout << "Update Store: " << CL->updateStore(updateID, updateNamePtr, updateAddrPtr, updateCityPtr, updateStPtr, updateZipPtr) << endl;
	CL->printStoresInfo();
}



void testEmployeeDatabase()
{
	EmployeeDatabase* db = new EmployeeDatabase();
	EmployeeRecord* temp = new EmployeeRecord();
	EmployeeRecord* temp2 = new EmployeeRecord();
	int newID = 1;
	char newFName[] = "John";
	char newLName[] = "Fettersmith";
	char* newFNamePtr = newFName;
	char* newLNamePtr = newLName;
	int newDept = 184;
	double newSal = 54000.50;
	EmployeeRecord* addEmp = new EmployeeRecord(newID, newFNamePtr, newLNamePtr, newDept, newSal);
	char file[] = "prog3Data.txt";
	char* filePtr = file;
	db->buildDatabase(filePtr);
	db->printEmployeeRecords();
	temp = db->getEmployee(1234);
	temp->printRecord();
	db->addEmployee(addEmp);
	db->printEmployeeRecords();
	temp2 = db->removeEmployee(1);
	db->removeEmployee(1234);
	db->removeEmployee(9876);
	db->removeEmployee(5678);
	temp2->printRecord();
	db->printEmployeeRecords();
}	


int main()
{
	testEmployeeDatabase();
	cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
	return 0;
}