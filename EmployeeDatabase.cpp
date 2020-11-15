#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "EmployeeDatabase.h";


EmployeeDatabase::EmployeeDatabase()
{
	cout << "called constructor" << endl;
	m_pRoot = NULL;
}


EmployeeDatabase::~EmployeeDatabase()
{
	cout << "called destructor" << endl;
	destroyTree(m_pRoot);
	return;
}

bool EmployeeDatabase::addEmployee(EmployeeRecord* e)
{
	cout << "called addEmployee" << endl;
	EmployeeRecord* temp;
	EmployeeRecord* back;

	temp = m_pRoot;
	back = NULL;

	while (temp != NULL)
	{
		back = temp;
		if (e->getID() < temp->getID())
		{
			temp = temp->m_pLeft;
		}
		else
		{
			temp = temp->m_pRight;
		}
	}

	if (back == NULL)
	{
		m_pRoot = e;
	}
	else
	{
		if (e->getID() < back->getID())
		{
			back->m_pLeft = e;
		}
		else
		{
			back->m_pRight = e;
		}
	}
	return true;

}

EmployeeRecord* EmployeeDatabase::getEmployee(int ID)
{
	cout << "called getEmployee" << endl;
	EmployeeRecord* temp;

	temp = m_pRoot;

	while ((temp != NULL) && (temp->getID() != ID))
	{
		if (temp->getID() > ID)
		{
			temp = temp->m_pLeft;
		}
		else
		{
			temp = temp->m_pRight;
		}
	}

	return temp;

}

EmployeeRecord* EmployeeDatabase::removeEmployee(int ID)
{
	cout << "called removeEmployee" << endl;
	EmployeeRecord* temp;
	EmployeeRecord* back;
	EmployeeRecord* delParent;
	EmployeeRecord* delNode;

	temp = m_pRoot;
	back = NULL;

	while ((temp != NULL) && (temp->getID() != ID))
	{
		back = temp;
		if (temp->getID() > ID)
		{
			temp = temp->m_pLeft;
		}
		else
		{
			temp = temp->m_pRight;
		}
	}

	if (temp == NULL)
	{
		return NULL;
	}
	else
	{
		delNode = temp;
		delParent = back;
	}

	if (delNode->m_pRight == NULL)
	{
		if (delParent == NULL)
		{
			m_pRoot = delNode->m_pLeft;
			return delNode;
		}
		else
		{
			if(delParent->m_pLeft == delNode)
			{
				delParent->m_pLeft = delNode->m_pLeft;
			}
			else
			{
				delParent->m_pRight = delNode->m_pLeft;
			}
			return delNode;
		}
	}
	else if (delNode->m_pLeft == NULL)
	{
		if (delParent == NULL)
		{
			m_pRoot = delNode->m_pRight;
			return delNode;
		}
		else
		{
			if (delParent->m_pLeft == delNode)
			{
				delParent->m_pLeft = delNode->m_pRight;
			}
			else
			{
				delParent->m_pLeft = delNode->m_pRight;
			}
			return delNode;
		}
	}
	else
	{

		EmployeeRecord* returnEmployeeRecord = new EmployeeRecord();
		returnEmployeeRecord->destroyCustomerList();
	

		temp = delNode->m_pLeft;
		back = delNode;

		while (temp->m_pRight != NULL)
		{
			back = temp;
			temp = temp->m_pRight;
		}

		delNode->setID(temp->getID());

		*returnEmployeeRecord = *delNode;

		returnEmployeeRecord->m_pLeft = NULL;
		returnEmployeeRecord->m_pRight = NULL;


		if (back == delNode)
		{
			back->m_pLeft = temp->m_pLeft;
		}
		else
		{
			back->m_pRight = temp->m_pLeft;
		}

		delete temp;
		return returnEmployeeRecord;

	}

}

void EmployeeDatabase::printEmployeeRecords()
{
	cout << "called printEmployeeRecords" << endl;
	cout << endl << endl;
	cout << setw(10) << "Emp ID" << setw(33) << "First Name" << setw(33) << "Last Name" << setw(8) << "Dep" << setw(10) << " " << "Salary" << endl;
	cout << string(110, '#') << endl;
	printEmployeeRecords(m_pRoot);
	cout << string(110, '#') << endl;
}

bool EmployeeDatabase::buildDatabase(char* dataFile)
{
	cout << "called buildDatabase" << endl;
	bool OK = true;
	int numEmp, id, dept, numStores, sID;
	double sal;
	EmployeeRecord* empRec;
	CustomerList* theList;
	Store* theStore;
	char inStr[128];
	char fName[32];
	char lName[32];
	char sName[64];
	char sAddr[64];
	char sSt[32];
	char sCity[32];
	char sZip[12];


	inFile.open(dataFile, ifstream::in);
	if (!inFile.is_open())
	{
		// inFile.is_open() returns false if the file could not be found or
		//    if for some other reason the open failed.
		cout << "Unable to open file" << dataFile << "\nProgram terminating...\n";
		cout << "Press Enter to continue...";
		getc(stdin);
		return false;
	}

	// Get number of employees
	getNextLine(inStr, 128);
	numEmp = atoi(inStr);
	for (int i = 0; i < numEmp; i++)
	{
		// Instantiate an EmployeeRecord
		empRec = new EmployeeRecord();
		// Read and set the ID
		getNextLine(inStr, 128);
		id = atoi(inStr);
		empRec->setID(id);
		// Read and set the name
		getNextLine(fName, 32);
		getNextLine(lName, 32);
		empRec->setName(fName, lName);
		// Read and set the Department ID
		getNextLine(inStr, 128);
		dept = atoi(inStr);
		empRec->setDept(dept);
		// Read and set the Salary
		getNextLine(inStr, 128);
		sal = atof(inStr);
		empRec->setSalary(sal);
		// Get the customer list
		theList = empRec->getCustomerList();
		// Get the number of stores
		getNextLine(inStr, 128);
		numStores = atoi(inStr);
		for (int j = 0; j < numStores; j++)
		{
			// Read the store ID
			getNextLine(inStr, 128);
			sID = atoi(inStr);
			// Read the store name
			getNextLine(sName, 64);
			// Read the store address
			getNextLine(sAddr, 64);
			// Read the store city
			getNextLine(sCity, 32);
			// Read the store state
			getNextLine(sSt, 32);
			// Read the store zip
			getNextLine(sZip, 11);
			// Create a new Store object
			theStore = new Store(sID, sName, sAddr, sCity, sSt, sZip);
			theList->addStore(theStore);
		}
		cout.flush();
		addEmployee(empRec);
	}
	inFile.close();
	return true;	// Successfully built the database
}

void EmployeeDatabase::printEmployeeRecords(EmployeeRecord* rt)
{
	cout << "printEmployeeRecord(etc)" << endl;
	if (rt != NULL)
	{
		printEmployeeRecords(rt->m_pLeft);
		rt->printRecord();
		printEmployeeRecords(rt->m_pRight);
	}
}

void EmployeeDatabase::destroyTree(EmployeeRecord* rt)
{
	cout << "called destroyTree" << endl;
	if (rt == NULL) {
		return;
	}
	if (rt->m_pLeft != NULL)
	{
		destroyTree(rt->m_pLeft);
	}
	if (rt->m_pRight != NULL)
	{
		destroyTree(rt->m_pRight);
	}
	delete rt;
	return;
}


bool EmployeeDatabase::getNextLine(char* line, int lineLen)
{
	cout << "called getNextLine" << endl;
	int    done = false;
	while (!done)
	{
		inFile.getline(line, 128);

		if (inFile.good())    // If a line was successfully read
		{
			if (strlen(line) == 0)  // Skip any blank lines
				continue;
			else if (line[0] == '#')  // Skip any comment lines
				continue;
			else return true;    // Got a valid data line so return with this line
		}
		else
		{
			strcpy(line, "");
			return false;
		}
	} // end while
	return false;
}