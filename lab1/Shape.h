#pragma once
#include <iostream>
#include <fstream>
enum Color { RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE };
class Shape
{

protected:
	Color m_col;
	unsigned int m_NumOfCorn;
public:
	Shape(Color color, unsigned int Num);
	Shape();
	//Shape(const Rect& r);
	virtual ~Shape();
	void WhereAmI() { std::cout << "Now I am in class Shape" << std::endl; };
	virtual void WhereAmIVirtual() { std::cout << "Now I am in class Shape" << std::endl; };
	virtual void Inflate(int x) = 0;
	virtual Shape* Clone() const;
	virtual double GetSquare() const= 0;
	virtual bool operator == (const Shape& s1) const = 0;
	const char* GetColor() const;
	double GetColorDouble() const;
	friend std::ostream& operator<<(std::ostream& os, const Shape& c);
	friend std::ofstream& operator<<(std::ofstream& fout, const Shape& c);
	virtual std::ostream& Output(std::ostream& os) const = 0;
	virtual Shape& operator=(const Shape& c);
};
class Rect :public Shape
{
	double m_left, m_right, m_top, m_bottom;

public:
	Rect(Color color, double left, double right, double top, double bottom);
	Rect();
	virtual ~Rect();
	void MakeOK();
	void WhereAmI() { std::cout << "Now I am in class Rect" << std::endl; };
	virtual void WhereAmIVirtual() { std::cout << "Now I am in class Rect" << std::endl; };
	friend class Circle;
	virtual void Inflate(int x);
	virtual double GetSquare() const;
	virtual Shape* Clone() const;
	const char* GetColor() const;
	double GetColorDouble() const;
	virtual bool operator == (const Shape& s1) const;
	friend std::ostream& operator<<(std::ostream& os, const Rect& c);
	friend std::ofstream& operator<<(std::ofstream& fout, const Rect& c);
	virtual std::ostream& Output(std::ostream& os) const;
	virtual Shape& operator=(const Shape& c);

};
class Circle :public Shape
{
	double m_rad;
public:
	Circle(Color color, double rad);
	Circle(const Rect& r);
	Circle();
	virtual ~Circle();
	void WhereAmI() { std::cout << "Now I am in class Circle" << std::endl; };
	virtual void WhereAmIVirtual() { std::cout << "Now I am in class Circle" << std::endl; };
	virtual void Inflate(int x);
	virtual double GetSquare() const;
	virtual Shape* Clone() const;
	virtual bool operator == (const Shape& s1) const;
	const char* GetColor() const;
	double GetColorDouble() const;
	friend std::ostream& operator<<(std::ostream& os, const Circle& c);
	friend std::ofstream& operator<<(std::ofstream& fout, const Circle& c);
	virtual std::ostream& Output(std::ostream& os) const;
	virtual Shape& operator=(const Shape& c);
};
