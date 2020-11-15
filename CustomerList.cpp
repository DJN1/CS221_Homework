#include "CustomerList.h"
#include "Store.h"
#include <iomanip>

using namespace std;


CustomerList::CustomerList()
{
	cout << "Called CustomerList constructor" << endl;
	m_pHead = NULL;
	cout << "m_pHead: " << m_pHead << endl;
}

CustomerList::~CustomerList()
{
	cout << "Called Destructor function" << endl;
}

bool CustomerList::isEmpty()
{
	cout << "Called isEmpty functions" << endl;
	return(m_pHead == NULL);
}

bool CustomerList::addStore(Store* s)
{
	cout << "Called addStore function" << endl;
	Store* temp = new Store();
	Store* back = new Store();
	if (s == NULL)
		return false;
	if (m_pHead == NULL)
	{
		s->m_pNext = NULL;
		m_pHead = s;
	}
	else
	{
		temp = m_pHead;
		back = NULL;
		while((temp != NULL) && (temp->getStoreID() < s->getStoreID())) 
		{
			back = temp;
			temp = temp->m_pNext;
		}
		if (back == NULL)
		{
			s->m_pNext = m_pHead;
			m_pHead = s;
		}
		else
		{
			back->m_pNext = s;
			s->m_pNext = temp;
		}
	}
	return true;
}

Store* CustomerList::removeStore(int ID)
{
	cout << "Called removeStore function" << endl;
	Store* temp;
	Store* back;
	if (m_pHead == NULL)
		return NULL;

	temp = m_pHead;
	back = NULL;

	while ((temp != NULL) && (ID != temp->getStoreID()))
	{
		back = temp;
		temp = temp->m_pNext;
	}

	if (temp == NULL)
		return NULL;
	else if (back == NULL)
	{
		m_pHead = m_pHead->m_pNext;
		return temp;
	}
	else
	{
		back->m_pNext = temp->m_pNext;
		return temp;
	}
	return NULL;
}

Store* CustomerList::getStore(int ID)
{
	cout << "Called getStore function" << endl;
	Store* temp = NULL;
	Store* back;
	if (m_pHead == NULL)
	{
		cout << "list is empty" << endl;
		return NULL;
	}
	else
	{
		temp = m_pHead;
		back = NULL;
		while ((temp != NULL) && (ID != temp->getStoreID()))
		{
			back = temp;
			temp = temp->m_pNext;
		}
		return temp;
	}
	
}

bool CustomerList::updateStore(int ID, char* name, char* addr, char* city, char* st, char* zip)
{
	cout << "Called updateStore function" << endl;
	Store* temp = NULL;
	if (m_pHead == NULL)
		return false;
	temp = m_pHead;
	while (temp != NULL)
	{
		if (temp->getStoreID() == ID)
		{
			temp->setStoreName(name);
			temp->setStoreAddress(addr);
			temp->setStoreCity(city);
			temp->setStoreState(st);
			temp->setStoreZip(zip);
			return true;
		}
		else {
			temp = temp->m_pNext;
		}
	}
	return false;
}

void CustomerList::printStoresInfo()
{
	cout << "Called printStoresInfo function" << endl;
	Store* temp = NULL;
	cout << "################################################################ Stores ################################################################" << endl;
	temp = m_pHead;
	while (temp != NULL)
	{
		cout << setw(5) << temp->getStoreID() << setw(32) << temp->getStoreName() << setw(32) << temp->getStoreAddress() << setw(32) << temp->getStoreCity() << setw(16) << temp->getStoreState() << setw(8) << temp->getStoreZip() << endl;
		temp = temp->m_pNext;
	}
	cout << "########################################################################################################################################" << endl;
}