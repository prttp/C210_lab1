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
		//������:
		Node* pPrev;		//��������� �� ���������� �������
		Node* pNext;		//��������� �� ��������� �������
		Shape* m_Data;
		//������:
		friend std::ostream& operator<<(std::ostream& os, const List& l);
		Node();//������ ����� ����������� ��� �������� ��������������� ������� � �������� (Head, Tail)
		Node(Node* p,  const Shape* d);	//�����������, ����������� �������� ����������� Node �������������� � ������.
		~Node();//���������� ������ ����������� ������������ Node �� ������
		void Swap(Node* n);
	};//���������� ���������� ������ Node

	//������
	Node Head;	// ��������� �������, ������� �������� ��������� ������ ������
	Node Tail;	// ��������� �������, ������� �������� ��������� ����� ������
	size_t m_size;	//���������� ���������
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
