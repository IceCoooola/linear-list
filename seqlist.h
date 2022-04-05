#include<iostream>
#include<assert.h>
#include<iomanip>
typedef int ElemType;
class SeqList 
{
public:
	SeqList();
	~SeqList();
	void listPushback(ElemType e);//add one element to the end of the list
	void listPopback();//delete the last element
	void listPushfront(ElemType e);//add one element to the front
	void listPopfront();//delete the first element
	void listInsert(ElemType e);//insert element to the nth position
	void listErase();
	void listFind(ElemType e);
	void listPrint();
	int listBiSearch(ElemType e);//return index if found. return -1 if no found.
	void listReverse();
	void listSort();
	void listCheckCapacity();//check capacity and expand
private:
	ElemType *m_pData;
	int m_iLength;
	int m_iCapacity;
};

SeqList::SeqList()
{
	m_pData = new ElemType[5];
	m_iLength = 0;
	m_iCapacity = 5;
}

SeqList::~SeqList()
{
	delete m_pData;
	m_pData = NULL;
}

void SeqList::listCheckCapacity()
{
	if (m_iCapacity == m_iLength)
	{
		ElemType* pTemp = (ElemType*)realloc(m_pData, 2*sizeof(ElemType)*m_iCapacity);
		assert(pTemp);
		m_pData = pTemp;
	}
}

void SeqList::listPushback(ElemType e)
{
	listCheckCapacity();
	m_pData[m_iLength] = e;
	m_iLength++;
}

void SeqList::listPopback()
{
	if (m_iCapacity > 0)
	{
		m_iLength--;
	}
	else
	{
		std::cout << "list is empty" << std::endl;
	}
}

void SeqList::listPushfront(ElemType e)
{
	listCheckCapacity();
	for (int i = m_iLength; i > 0; i--)
	{
		m_pData[i] = m_pData[i - 1];
	}
	m_iLength++;	
	m_pData[0] = e;
}

void SeqList::listPopfront()
{
	for (int i = 0; i < m_iLength; i++)
	{
		m_pData[i] = m_pData[i + 1];
	}
	m_iLength--;
}

void SeqList::listInsert(ElemType e)
{
	std::cout<<"enter the position you want to insert"<<std::endl;
	int pos;
	std::cin >> pos;
	pos -= 1;
	if (pos > m_iLength||pos<0)
	{
		std::cout << "invalid position! out of range." << std::endl;
	}
	else
	{
		listCheckCapacity();
		for (int i = m_iLength; i > pos; i--)
		{
			m_pData[i] = m_pData[i - 1];
		}
		m_iLength++;
		m_pData[pos] = e;
	}
}

void SeqList::listErase()
{
	std::cout << "enter the position you want to delete" << std::endl;
	int pos;
	std::cin >> pos;
	pos -= 1;
	if (pos >= m_iLength||pos<0)
	{
		std::cout<<"invalid position! out of range."<<std::endl;
	}
	else
	{
		for (int i = pos; i < m_iLength-1; i++)
		{
			m_pData[i] = m_pData[i + 1];
		}
		m_iLength--;
	}
}

void SeqList::listFind(ElemType e)
{
	for (int i = 0; i < m_iLength; i++)
	{
		if (e == m_pData[i])
		{
			std::cout << "found. index:>" << i << std::endl;
			return;
		}
	}
	std::cout << "not found.\n";
}

void SeqList::listPrint()
{
	if (m_iLength == 0)
	{
		std::cout << "empty list.\n";
		return;
	}
	for (int i = 0; i < m_iLength; i++)
	{
		std::cout<<"|"<< std::setw(5) << i+1;
	}
	std::cout << "|" << std::endl;
	for (int i = 0; i < m_iLength; i++)
	{
		std::cout << "|" << "-----";
	}
	std::cout << "|" << std::endl;
	for (int i = 0; i < m_iLength; i++)
	{
		std::cout << "|" << std::setw(5) << m_pData[i];
	}
	std::cout << "|" << std::endl<<std::endl;
}

int SeqList::listBiSearch(ElemType e)
{
	listSort();
	int left = 0;
	int right = m_iLength - 1;
	while (right >= left)
	{
		int mid = (left + right) / 2;
		if (m_pData[mid] < e)
		{
			left = mid + 1;
		}
		else if (m_pData[mid] > e)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void SeqList::listReverse()
{
	int left = 0;
	int right = m_iLength - 1;
	while (left < right)
	{
		ElemType temp = m_pData[left];
		m_pData[left] = m_pData[right];
		m_pData[right] = temp;
		left++;
		right--;
	}
}

void SeqList::listSort()
{
	for (int i = 1; i < m_iLength; i++)
	{
		ElemType key = m_pData[i];
		int j = i - 1;
		while (j >= 0 && m_pData[j] > key)
		{
			m_pData[j + 1] = m_pData[j];
			j -= 1;
		}
		m_pData[j + 1] = key;
	}
}
