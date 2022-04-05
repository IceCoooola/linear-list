#include"seqlist.h"

int main()
{
	//this program will create a sequence list
	SeqList list;
	std::cout << "new list created.\n";
	list.listPrint();
	std::cout << "\ntest list Push back: 5,0, 15, 3, 59\n";
	list.listPushback(5);
	list.listPushback(0);
	list.listPushback(15);
	list.listPushback(3);
	list.listPushback(59);
	list.listPrint();
	std::cout << "\ntest push front: 55, 9, -5\n";
	list.listPushfront(55);
	list.listPushfront(9);
	list.listPushfront(-5);
	list.listPrint();
	std::cout << "\ntest standard search: (1)\n";
	list.listFind(1);
	list.listSort();
	std::cout << "\ntest sort.\n";
	list.listPrint();
	int t = list.listBiSearch(5);
	std::cout << "\ntest binary search: (5)\n";
	if (t == -1)
	{
		std::cout << "element no found.\n";
	}
	else 
	{
		std::cout << "index: " << t << std::endl;
	}
	std::cout << "\ntest pop back\n";
	list.listPopback();
	list.listPopback();
	list.listPrint();
	std::cout << "\ntest pop front\n";
	list.listPopfront();
	list.listPopfront();
	list.listPopfront();
	list.listPrint();
	std::cout << "\ntest insert element (99)\n";
	list.listInsert(99);
	list.listPrint();
	std::cout << "\ntest reverse\n";
	list.listReverse();
	list.listPrint();
	std::cout << "\ntest erase\n";
	list.listErase();
	list.listPrint();
	std::cout << "\nend of program.\n";
	return 0;
}
