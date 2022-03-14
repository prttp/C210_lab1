#include "Shape.h"
#include "Node.h"

int main() {
	{
		List list;
		List list2;
		Circle c1(RED, 2.2);
		Circle c2(GREEN, 3.2);
		Rect r3(CYAN, 1.1, 2.2, 3.3, 4.4);
		Rect r4(YELLOW, 1.0, 2.9, 3.1, 4.2);
		Circle c5(YELLOW, 6.7);
		list.AddToHead(&c1);
		list.AddToTail(&c2);
		list.AddToHead(&c5);
		list2.AddToHead(&c1);
		
		
		
		list2.AddToTail(&r3);
		list = list2;
		std::cout << list;
		std::cout << list2;
		list = std::move(list2);
		std::cout << list;
		std::cout << list2;
	}
	List list;
	List list2;
	Circle c1(RED, 2.2);
	Circle c2(GREEN, 3.2);
	Rect r3(CYAN, 1.1, 2.2, 3.3, 4.4);
	Rect r4(YELLOW, 1.0, 2.9, 3.1, 4.2);
	Circle c5(YELLOW, 6.7);
	list.AddToHead(&c1);
	list.AddToTail(&c2);
	list.AddToHead(&c5);
	list.AddToHead(&r3);
	std::cout << list;
	list.Remove(&c1);
	std::cout << list;
	list.AddToTail(&c2);
	list.AddToTail(&c2);
	std::cout << list;
	list.RemoveAll(&c2);
	list.AddToHead(&r4);
	list.AddToHead(&c1);
	list.AddToHead(&c1);
	std::cout << list;
	//list.MakeEmpty();
	std::cout << list;
	list.SortBy();
	std::cout << list;
	list2 = list;
	std::cout << list2;
	list.PrintToFile();
	return 0;
}