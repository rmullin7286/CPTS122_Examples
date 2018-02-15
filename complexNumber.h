#ifndef COMPLEXNUMBER_H

#include <iostream>

using std::cout;
using std::cin;
using std::istream;
using std::ostream;
//This is a simple class in C++ that simulates a complex number.
//A complex number consists of an expression a + bi, where
//a is the real number and b is the imaginary number.


//Classes in C++ are similar to the way we used structs in C. They are used to encapsulate data
//into objects. There are a few features that classes include however that structs didn't have. These are:
//Constructors and destructors
//Member functions
//Access specifiers
//Inheritance/Polymorphism (We'll learn about this later)
class ComplexNumber 
{
	//public and private are access specifiers. These signify which members a user can access.
	//PUBLIC members are always accessible outside of a class
	//PROTECTED members are only accessible from classes derived from the class (useful later)
	//PRIVATE members are only accessible from within the class itself
	//in a C struct, all members are public
	public:
		//This is a constructor. A constructor is a function that can be called when the class is
		//initialized. It always shares the name of the class itself. There can be multiple 
		//constructors for a single class.
		//Note the default values passed into the constructor.
		ComplexNumber(double real=0.0, double imaginary=0.0);

		//These are getters and setters for the member variables. These are useful for hiding
		//the direct implementation of the variables themselves. Always try and have the user
		//access member variables with getters and setters.
		double getReal();
		double getImaginary();

		void setReal(double real);
		void setImaginary(double imaginary);
	
		//for this example, we'll define 2 additional member functions,
		//add() and read()
		//
		//NOTE: the & symbol in a function definition denotes a reference.
		//References are similar to C pointers, except that they cannot be reassigned.
		//References also do not have a unique notation, so you can refer to an argument
		//as you regularly would without the need for dereferencing.
		ComplexNumber add(ComplexNumber &rhs);
		void read();

	private:
		//member variables should usually be kept private
		double r;
		double i;
}; //make sure to have the semicolon here!

//For this example we'll also be defining add as a non-member function, to show the difference between
//implementations
ComplexNumber add(ComplexNumber &lhs, ComplexNumber &rhs);

//We'll also be defining some operator overloads for the class. These functions change the way standard C++
//operators function with certain classes. We'll be overloading + for addition, - for subtraction, and
//>> and << for reading and writing.
//
//NOTE: istream and ostream are stream objects that can be read from and written to. the standard C++
//cin and cout to read to and write from the console are istream and ostream types respectively,
//which is why we can pass them as arguments to the operator overload.
//When the overload function is done we will return the streams again so that they can be used in chain
//calls, e.g. (cin >> complex1 >> complex2). It will evaluate (cin >> complex1), return cin, and then
//evaluate (cin >> complex2).
ComplexNumber operator+(ComplexNumber &lhs, ComplexNumber &rhs);
ComplexNumber operator-(ComplexNumber &lhs, ComplexNumber &rhs);
ostream & operator>>(ostream &lhs, ComplexNumber &rhs);
istream & operator<<(istream &lhs, ComplexNumber &rhs);

//All functions should be defined in complexNumber.cpp. 
#endif
