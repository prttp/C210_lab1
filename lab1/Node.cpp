#include "Node.h"

List::Node::Node() {
	pPrev = nullptr;
	pNext = nullptr;
	m_Data = nullptr;
}
List::Node::Node(Node* p, const Shape* d)/*:m_Data(d)*/{
	pPrev = p;
	pNext = pPrev->pNext;
	if (p != 0) { p->pNext = this; };
	if (pNext != 0) { pNext->pPrev = this; };
	//if (typeid(*d) == typeid(Rect)) { 
	//	m_Data =new Rect(*static_cast<const Rect*>(d)); 
	m_Data = d->Clone();
}
List::Node::~Node() {
	if (pNext != 0) { pNext->pPrev = pPrev; };
	if (pPrev != 0) { pPrev->pNext = pNext; };
	if (m_Data != 0) { delete m_Data; m_Data = nullptr; };
}
void List::Node::Swap(Node* n)
{
	Shape* tmp = m_Data;
	m_Data = n->m_Data;
	n->m_Data = tmp;
	////Node* tmpN = pNext;
	//Node* tmpP = pPrev;
	//pNext = n->pNext;
	//pPrev = n;
	//n->pPrev = tmpP;
	//n->pNext = this;

}
List::List() {
	//Head = Node();
	//Tail = Node();
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
}
List::~List() {
	Node* p = Head.pNext;
	while (p->pNext != 0) {
		Head.pNext = p->pNext;
		delete p;
		p = Head.pNext;
	}
}
List::List(const List& source)
{
	Node* ps = source.Head.pNext;
	for (size_t i = 0; i < source.m_size; i++) {
		this->AddToTail(ps->m_Data);
		ps = ps->pNext;
	};
	m_size = source.m_size;
	
}
List& List::operator=(List&& source)
{
	this->MakeEmpty();
	Head = source.Head;
	Tail = source.Tail;
	m_size = source.m_size;
	source.Head.pNext = &source.Tail;
	source.Tail.pPrev = &source.Head;
	source.m_size = 0;
	return *this;
}
List& List::operator=(const List& source)
{
	Node* p = Head.pNext;
	Node* ps = source.Head.pNext;
	if (m_size <= source.m_size) {
		for (size_t i = 0; i < m_size; i++) {
			if (typeid(p->m_Data) == typeid(ps->m_Data)) { *(p->m_Data) = *(ps->m_Data); }
			else {
				delete p->m_Data;
				p->m_Data = ps->m_Data->Clone();
			}

			////
			//try {
			//	*(p->m_Data) = *(ps->m_Data);
			//}
			//catch (...)
			//{
			//	delete p->m_Data;
			//	p->m_Data = ps->m_Data->Clone();
			//}


			/////
			p = p->pNext;
			ps = ps->pNext;
		};
		for (size_t i = m_size; i < source.m_size; i++) {
			this->AddToTail(ps->m_Data);
			ps = ps->pNext;
		};
		m_size = source.m_size;
	}
	else {
		for (size_t i = 0; i < source.m_size; i++) {
			if (typeid(*(p->m_Data)) == typeid(*(ps->m_Data))) { *(p->m_Data) = *(ps->m_Data); }
			else {
				delete p->m_Data;
				p->m_Data = ps->m_Data->Clone();
			}
			p = p->pNext;
			ps = ps->pNext;
		}
		for (size_t i = source.m_size; i < m_size; i++) {
			ps = p;
			delete p;
			p = ps->pNext;
		}
		m_size = source.m_size;
	}// TODO: insert return statement here
	return *this;
}
//List::~List() {
//	
//	while (Head.pNext != &Tail) {
//		delete Head.pNext;
//	}
//}
void List::AddToHead(const Shape* c) {
	new Node(&Head, c);
	m_size++;
}
void List::AddToTail(const Shape* c) {
	new Node(Tail.pPrev, c);
	m_size++;
}
bool List::Remove(const Shape* ref) {
	Node* p = Head.pNext;
	for (int i = 0; i < m_size; i++) {
		if (*ref ==*(p->m_Data)) {

			delete p;
			m_size--;
			return 1;
		};
	p = p->pNext;
		
	};
	return 0;
}
int List::RemoveAll(const Shape* ref) {
	Node* p = Head.pNext;
	int n = 0;
	while (p !=0) {
		Node* next = p->pNext;
		if (next == nullptr) { break; }
		if (*ref == *(p->m_Data)) {
			delete p;
			m_size--;
			n++;
			
		};
		p = next;
	};
	return n;
}
void List::MakeEmpty() {
	//Node* p = Head.pNext;
	for (int i = 0; i < m_size; i++) {
		delete Head.pNext;
		//Node* next = p->pNext;
		//delete p;
		//p = next;
	};
	m_size = 0;
}
void List::SortBySquare() {
	if (m_size != 0) {
		Node* p1 = Head.pNext;
		while (p1->pNext->pNext != 0) {

			Node* p = Head.pNext;
			while (p->pNext->pNext != 0) {
				double s1 = p->m_Data->GetSquare();
				double s2 = (p->pNext)->m_Data->GetSquare();
				if (s1 > s2) {
					/*Circle tmp = p->m_Data;
					p->m_Data = (p->pNext)->m_Data;
					(p->pNext)->m_Data = tmp;*/
					p->Swap(p->pNext);
					/*((p->pPrev)->pPrev)->pNext = p->pPrev;
					(p->pNext)->pPrev = p;*/
					/*Node* tmpN = p->pNext;
					(p->pPrev)->pNext = p->pNext;
					((p ->pNext)->pNext)->pPrev = p;
					(p->pNext)->pPrev = p->pPrev;
					(p->pNext)->pNext = p;
					p->pNext = (p->pNext)->pNext;
					p->pPrev = tmpN;*/
					continue;
				}
				p = p->pNext;
			}
			p1 = p1->pNext;
		}
	};
}
void List::SortBy()
{
	std::cout << "Sort the List by: \n 1. Square \n 2. Color \n";
	int ans;
	std::cin >> ans;
	double (Shape:: * pGet)() const = NULL;
	switch (ans)
	{
	case 1:
		pGet = &Shape::GetSquare;
		break;
	case 2:
		pGet = &Shape::GetColorDouble;
		break;
	default:
		std::cout << "ERROR: Unknown operation!\n";
		return;
	}
	if (m_size != 0) {
		Node* p1 = Head.pNext;
		while (p1->pNext->pNext != 0) {

			Node* p = Head.pNext;
			while (p->pNext->pNext != 0) {
				
				if (((p->m_Data->*pGet)()) > (((p->pNext)->m_Data->*pGet)())) {
					p->Swap(p->pNext);
					continue;
				}
				p = p->pNext;
			}
			p1 = p1->pNext;
		}
	};
	
}
void List::PrintToFile() {
	std::cout << "Enter Output File Name  - ";
	char ar[80];
	std::cin >> ar;
	std::ofstream fout(ar);
	fout << *this;
	//List::Node* p = Head;
	//for (int i = 0; i < m_size; i++) {
	//	p = p->pNext;
	//	fout << p->m_Data << std::endl;
	//};
	//fout << "Size of the list: " << m_size << std::endl;
	fout.close();

}
std::ostream& operator<<(std::ostream& os, const List& d) {
	if (d.m_size == 0) { return os << "EMPTY!" << std::endl; };
	const List::Node* p = &d.Head;
	for (int i = 0; i < d.m_size; i++) { 
		p = p->pNext;
		os << *(p->m_Data) << std::endl; };
	os << "Size of the list: " << d.m_size <<  std::endl;
	return os;
}