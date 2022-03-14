#include "Shape.h"
Shape::Shape(Color color, unsigned int Num) {
	m_col = color;
	m_NumOfCorn = Num;
};
Shape::Shape() {
	m_col = WHITE;
	m_NumOfCorn = 0;
};
/*Shape::Shape(const Rect& r) {
	m_col = r.m_col;
	m_NumOfCorn = 4;
};*/
Shape::~Shape() { std::cout << "Now I am in Shape's destructor!" << std::endl; }
Shape* Shape::Clone() const
{

	return nullptr;
}
bool Shape::operator==(const Shape& s1) const
{
	
	return m_col == s1.m_col;
}
const char* Shape::GetColor() const
{
	switch (this->m_col)
	{
	case 0:
		return "RED";
	case 1:
		return "GREEN";
	case 2:
		return "BLUE";
	case 3:
		return "CYAN";
	case 4:
		return "MAGENTA";
	case 5:
		return "YELLOW";
	case 6:
		return "WHITE";
	default:
		return "No color";
	}
	
}
double Shape::GetColorDouble() const
{
	return this->m_col;
}
Shape& Shape::operator=(const Shape& c)
{
	m_col = c.m_col;
	return *this;// TODO: insert return statement here
}
;
Rect::Rect(Color color, double left, double right, double top, double bottom)
	:Shape(color, 4)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	MakeOK();
};
Rect::Rect()
	:Shape(WHITE, 4)
{
	m_left = 0;
	m_right = 1;
	m_top = 1;
	m_bottom = 0;
};
Rect::~Rect() { std::cout << "Now I am in Rect's destructor!" << std::endl; };
void Rect::MakeOK() {
	int buff = 0;
	if (m_left > m_right) { buff = m_left; m_left = m_right; m_right = buff; };
	if (m_bottom > m_top) { buff = m_bottom; m_bottom = m_top; m_top = buff; };
};

Circle::Circle(Color color, double rad)
	:Shape(color, 0)
{
	m_rad = rad;
};
Circle::Circle(const Rect& r)
	:Shape(r.m_col, 0)
{
	m_rad = r.m_left;
};
Circle::~Circle() { std::cout << "Now I am in Circle's destructor!" << std::endl; };
Circle::Circle()
	:Shape(WHITE, 0)
{
	m_rad = 1;
};
void Rect::Inflate(int x) {
	m_left -= x;
	m_right += x;
	m_top += x;
	m_bottom -= x;
	MakeOK();
}
double Rect::GetSquare() const
{
	double s = (m_top - m_bottom) * (m_right - m_left);
	return s;
}
Shape* Rect::Clone() const
{
	Rect* Data = new Rect(*this);
	return Data;
}
bool Rect::operator==(const Shape& s1) const
{
	
	if (typeid(s1) == typeid(const Rect&)) {
		
		const Rect& r= static_cast<const Rect&>(s1);
		bool ans = (m_bottom == r.m_bottom) && (m_top == r.m_top) && (m_left == r.m_left) && (m_right == r.m_right) && Shape::operator==(s1);
		return ans;
	}
	else { return false; }
			//return (m_col==s1->m_col) && (m_bottom == s1->m_bottom) && (m_top == s1->m_top) && (m_left == s1->m_left) && (m_right == s1->m_right);
}
std::ostream& Rect::Output(std::ostream& os) const
{	
	os << "Color:" << this->GetColor() << ", " << " Height: " << this->m_top - this->m_bottom << " Width: " << this->m_right - this->m_left << " Square: " << this->GetSquare();
	return os;
}

Shape& Rect::operator=(const Shape& c)
{
	if (typeid(c) == typeid(const Rect&)) {
		const Rect& r = static_cast<const Rect&>(c);
		/*m_left = r.m_left;
		m_right = r.m_right;
		m_top = r.m_top;
		m_bottom = r.m_bottom;
		Shape::operator=(r);*/
		*this = r;
	}
	return *this;// TODO: insert return statement here
}

;
void Circle::Inflate(int x) {
	m_rad += x;
}
double Circle::GetSquare() const
{
	double s = 3.14 * m_rad * m_rad;
	return s;
}
Shape* Circle::Clone() const
{
	Circle* Data = new Circle(*this);
	return Data;
}
bool Circle::operator==(const Shape& s1) const
{
	const Shape* temp = this;
	bool temp1 = 1; //(*(dynamic_cast<const Shape*>(temp)) == s1);
	if (typeid(s1) == typeid(const Circle&)) {
		const Circle& r = static_cast<const Circle&>(s1);
		bool ans = (m_rad == r.m_rad) && temp1;
		return ans;
	}
	else { return false; }
		
}
const char* Circle::GetColor() const
{
	switch (this->m_col)
	{
	case 0:
		return "RED";
	case 1:
		return "GREEN";
	case 2:
		return "BLUE";
	case 3:
		return "CYAN";
	case 4:
		return "MAGENTA";
	case 5:
		return "YELLOW";
	case 6:
		return "WHITE";
	default:
		return "No color";
	}
}
double Circle::GetColorDouble() const
{
	return this->m_col;
}
std::ostream& Circle::Output(std::ostream& os) const
{
	os << "Color:" << this->GetColor() << ", " << " Radius: " << this->m_rad << " Square: " << this->GetSquare();
	return os;
}
Shape& Circle::operator=(const Shape& c)
{
	if (typeid(c) == typeid(const Circle&)) {
		const Circle& r = static_cast<const Circle&>(c);
	/*	m_rad = r.m_rad;
		Shape::operator=(r);*/
		*this = r;
	}
	return *this;// TODO: insert return statement here
}
const char* Rect::GetColor() const
{
	switch (this->m_col)
	{
	case 0:
		return "RED";
	case 1:
		return "GREEN";
	case 2:
		return "BLUE";
	case 3:
		return "CYAN";
	case 4:
		return "MAGENTA";
	case 5:
		return "YELLOW";
	case 6:
		return "WHITE";
	default:
		return "No color";
	}
}
double Rect::GetColorDouble() const
{
	return this->m_col;
}
std::ostream& operator<<(std::ostream& os, const Circle& c) {
	os << "Color:" <<  c.GetColor()<< ", " << " Radius: " << c.m_rad << " Square: " << c.GetSquare();
	return os;
}
std::ostream& operator<<(std::ostream& os, const Rect& c) {
	os << "Color:" << c.GetColor() << ", " << " Height: " << c.m_top-c.m_bottom << " Width: " << c.m_right - c.m_left << " Square: " << c.GetSquare();
	return os;
}
std::ostream& operator<<(std::ostream& os, const Shape& c) {
	/*if (typeid(c) == typeid(const Circle&)) {
		const Circle& r = static_cast<const Circle&>(c);
		os << r;
	} else {
		const Rect& r = static_cast<const Rect&>(c);
		os << r;
	}*/
	c.Output(os);
	return os;
}
std::ofstream& operator<<(std::ofstream& fout, const Circle& c) {
	fout << "Color:" << c.GetColor() << ", " << " Radius: " << c.m_rad << " Square: " << c.GetSquare();
	return fout;
}
std::ofstream& operator<<(std::ofstream& fout, const Rect& c) {
	fout << "Color:" << c.GetColor() << ", " << " Height: " << c.m_top - c.m_bottom << " Width: " << c.m_right - c.m_left << " Square: " << c.GetSquare();
	return fout;
}
std::ofstream& operator<<(std::ofstream& fout, const Shape& c) {
	if (typeid(c) == typeid(const Circle&)) {
		const Circle& r = static_cast<const Circle&>(c);
		fout << r;
	}
	else {
		const Rect& r = static_cast<const Rect&>(c);
		fout << r;
	}
	return fout;
}