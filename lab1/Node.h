#pragma once
#include "Shape.h"
#include <iostream>
#include <fstream>
#include <typeinfo>

class List
{
	class Node
	{
		friend class List;
		//ƒанные:
		Node* pPrev;		//указатель на предыдущий элемент
		Node* pNext;		//указатель на следующий элемент
		Shape* m_Data;
		//ћетоды:
		friend std::ostream& operator<<(std::ostream& os, const List& l);
		Node();//скорее всего понадобитс€ дл€ создани€ вспомогательных оберток Ц Ђстражейї (Head, Tail)
		Node(Node* p,  const Shape* d);	//конструктор, посредством которого создаваемый Node Ђподключаетс€ї в список.
		~Node();//деструктор должен Ђисключатьї уничтожаемый Node из списка
		void Swap(Node* n);
	};//встроенное объ€вление класса Node

	//данные
	Node Head;	// фиктивный элемент, который €вл€етс€ признаком начала списка
	Node Tail;	// фиктивный элемент, который €вл€етс€ признаком конца списка
	size_t m_size;	//количество элементов
public:
	List();
	~List();
	List(const List& source);
	List& operator=(List&& source);
	List& operator=(const List& source);
	void AddToHead(const Shape* c);
	void AddToTail(const Shape* c);
	bool Remove(const Shape* ref);
	int RemoveAll(const Shape* ref);
	void MakeEmpty();
	void SortBySquare();
	void SortBy();
	void PrintToFile();
	friend std::ostream& operator<<(std::ostream& os, const List& l);
	//std::ostream& PrintNodes(std::ostream& os, const List& l)
	};
