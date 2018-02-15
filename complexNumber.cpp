#include "complexNumber.h"

//keep in mind the notation for member function definitions. It should always be like this:
//<return type> <class name>::<function()>

//constructor. Note that constructors and destructors don't have return values.
//also note that default arguments should only be placed in the function declaration, not definition.
ComplexNumber::ComplexNumber(double real, double imaginary)
{
	r = real;
	i = imaginary;
}

//getters
double ComplexNumber::getReal()
{
	return r;
}

double ComplexNumber::getImaginary()
{
	return i;
}

//setters
void ComplexNumber::setReal(double real)
{
	r = real;
}

void ComplexNumber::setImaginary(double imaginary)
{
	i = imaginary;
}

//member functions
ComplexNumber ComplexNumber::add(ComplexNumber &rhs)
{
	ComplexNumber sum;
	sum.setReal(getReal() + rhs.getReal());
	sum.setImaginary(getImaginary() + rhs.getImaginary());
	return sum;
}

//read will read in an input in the format of a + bi from cin
void ComplexNumber::read()
{
	//this will capture the uneccesary symbols + and i 
	char junk;
	cin >> r >> junk >> i >> junk;
}

//non-member add function
ComplexNumber add(ComplexNumber &lhs, ComplexNumber &rhs)
{
	ComplexNumber sum;
	sum.setReal(lhs.getReal() + rhs.getReal());
	sum.setImaginary(lhs.getImaginary() + rhs.getImaginary());
}

//operator overloads
ComplexNumber operator+(ComplexNumber &lhs, ComplexNumber &rhs)
{
	ComplexNumber sum;
	sum.setReal(lhs.getReal() + rhs.getReal());
	sum.setImaginary(lhs.getImaginary()- rhs.getImaginary());
	return sum;
}

ComplexNumber operator-(ComplexNumber &lhs, ComplexNumber &rhs)
{
	ComplexNumber difference;
	sum.setReal(lhs.getReal() - rhs.getReal());
	sum.setImaginary(lhs.getImaginary() - rhs.getImaginary());
	return difference;
}

istream operator>>(istream &lhs, ComplexNumber &rhs)
{
	char junk;
	double r, i;
	lhs >> r >> junk >> i >> junk;
	rhs.setReal(r);
	rhs.setImaginary(i);
	return lhs; 
}

ostream operator<<(ostream &lhs, ComplexNumber &rhs)
{
	lhs << rhs.getReal() << " + " << rhs.getImaginary() << "i";
	return lhs;
}


