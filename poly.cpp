// ------------------------------------------------ poly.cpp --------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 2/4/2021
// Date of Last Modification: 
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - This project is to create the abstract data type (ADT) for a polynomial called Poly.
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "poly.h"
#include <iostream>

using namespace std;

// default constructor
Poly::Poly() : maxCapacity(0)
{
    polynomial = new int[1];
    setCoeff(0, 0);
}

// Create a polynomial with the given coefficient and exponent
Poly::Poly(int coefficient, int exponent) : maxCapacity(exponent)
{
    polynomial = new int[exponent + 1];
    setCoeff(coefficient, exponent);
}

// Create a polynomial with the given coefficient and an exponent of 0
Poly::Poly(int coefficient) : maxCapacity(0)
{ 
    polynomial = new int[1];
    setCoeff(coefficient, 0);
}

// Copy Constructor, Create a deep copy of the polynomial toCopy
Poly::Poly(const Poly &toCopy)
{
    maxCapacity = toCopy.getMaxCap();
    polynomial = new int[maxCapacity + 1];

    for(int i = 0; i <= maxCapacity; i++) 
    {
        setCoeff(toCopy.getCoeff(i), i);
    }
}

// Destructor
Poly::~Poly() 
{
    delete[] polynomial;
}

// Overload addition operator, create a new Poly object
// that stores the sum of the 2 given polynomials
Poly Poly::operator+(const Poly &toAdd)
{
    int toAddMaxCap = toAdd.getMaxCap();
    int newMaxCap = getMaxCap();
    if (maxCapacity < toAddMaxCap)
    {
        newMaxCap = toAddMaxCap;
    }
    // Initialize a newPoly object, "0" is just a neutral number/placeholder
    Poly newPoly(0, newMaxCap);

    for (int i = 0; i <= maxCapacity; i++) 
    {
        newPoly.setCoeff(getCoeff(i), i);
    }
    for (int i = 0; i <= toAddMaxCap; i++) 
    {
        int newCoeff = newPoly.getCoeff(i) + toAdd.getCoeff(i);
        newPoly.setCoeff(newCoeff, i);
    }
    return newPoly;
}

// Overload subtraction operator, create a new Poly object
// that stores the difference of the 2 given polynomials
Poly Poly::operator-(const Poly &toSubtract) 
{
    int toSubMaxCap = toSubtract.getMaxCap();
    int newMaxCap = getMaxCap();
    if (maxCapacity < toSubMaxCap)
    {
        newMaxCap = toSubMaxCap;
    }
    // Initialize a newPoly object, "0" is just a neutral number/placeholder
    Poly newPoly(0, newMaxCap);

    for (int i = 0; i <= maxCapacity; i++) 
    {
        newPoly.setCoeff(getCoeff(i), i);
    }
    for (int i = 0; i <= toSubMaxCap; i++) 
    {
        int newCoeff = newPoly.getCoeff(i) - toSubtract.getCoeff(i);
        newPoly.setCoeff(newCoeff, i);
    }
    return newPoly;
}

// Overload multiplication operator, create a new Poly object
// that stores the product of the 2 given polynomials
Poly Poly::operator*(const Poly &toMultiply) 
{
    int newMaxCap = getMaxCap() + toMultiply.getMaxCap();
    Poly newPoly(0, newMaxCap);

    for (int i = getMaxCap(); i >= 0; i--) 
    {
        for (int j = toMultiply.getMaxCap(); j >= 0; j--) 
        {
            int newExp = i + j;
            int newCoeff = newPoly.getCoeff(newExp) + (getCoeff(i) * toMultiply.getCoeff(j));
            newPoly.setCoeff(newCoeff, newExp);
        }
    }
    return newPoly;
}

// Overload assignment operator, assign one polynomial to another
void Poly::operator=(const Poly &toAssign)
{
    int toAssignExp = toAssign.getMaxCap();
    if (maxCapacity < toAssignExp) 
    {
        // If current capacity is not enough, delete the polynomial array
        // and create a new one then point the pointer to a new one
        maxCapacity = toAssignExp;
        delete polynomial;
        polynomial = new int[maxCapacity + 1];
    } 
    else if (maxCapacity > toAssignExp)
    {
        // If the original polynomial has more exponent,
        // turn them all to 0
        for(int i = toAssignExp + 1; i <= maxCapacity; i++)
        {
            setCoeff(0, i);
        }
    }

    for(int i = 0; i <= toAssignExp; i++) 
    {
        setCoeff(toAssign.getCoeff(i), i);
    }
}

void Poly::operator+=(const Poly &toAssign)
{
    
}

// Get one term's coefficient
int Poly::getCoeff(int exponent) const 
{
    return polynomial[exponent];
}

// Get the object's max exponent capacity
int Poly::getMaxCap() const
{
    return maxCapacity;
}

void Poly::setCoeff(int coefficient, int exponent) 
{
    polynomial[exponent] = coefficient;
}

int main() 
{
    //test
    Poly blank;
    Poly a(-8,3);
    Poly b(2,1);
    Poly c(-5,1);
    Poly d(2); //-8^3 +2^1 -5^1 +2

    Poly e(-3,2);
    Poly f(7); 
    Poly g(7);
    Poly ha(-9,3);//-9^3-3x^2 +7 +7
    
    Poly q(a + b);
    Poly o(q + c);
    Poly x(o + d);

    Poly w(e + f);
    Poly hi(w + ha);
    Poly y(hi + g);

    Poly temp(x * y);
    temp = x;
    for (int i = temp.getMaxCap(); i >= 0; i--) 
    {
        cout << temp.getCoeff(i) << ", ";  
    }
    cout << endl;
    cout << temp.getMaxCap() << endl;;
    return 0;
}