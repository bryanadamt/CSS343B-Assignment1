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
Poly::Poly() : maxExponent(0)
{
    polynomial = new int[1];
    setCoeff(0, 0);
}

// Create a polynomial with the given coefficient and exponent
Poly::Poly(int coefficient, int exponent) : maxExponent(exponent)
{
    polynomial = new int[exponent + 1];
    setCoeff(coefficient, exponent);
}

// Create a polynomial with the given coefficient and an exponent of 0
Poly::Poly(int coefficient) : maxExponent(0)
{ 
    polynomial = new int[1];
    setCoeff(coefficient, 0);
}

// Copy Constructor, Create a deep copy of the polynomial toCopy
Poly::Poly(const Poly &toCopy)
{
    maxExponent = toCopy.getMaxExp();
    polynomial = new int[maxExponent + 1];

    for(int i = 0; i <= maxExponent; i++) 
    {
        setCoeff(toCopy.getCoeff(i), i);
    }
}

// Destructor
Poly::~Poly() 
{
    delete[] polynomial;
}

// Overload addition operator, adds 2 polynomials together
Poly Poly::operator+(const Poly &toAdd)
{
    int toAddMaxExp = toAdd.getMaxExp();
    if (maxExponent < toAddMaxExp) 
    {
        Poly newPoly(toAdd);
        for(int i = 0; i <= maxExponent; i++) 
        {
            int newCoeff = newPoly.getCoeff(i) + getCoeff(i);
            newPoly.setCoeff(newCoeff, i);
        }
        return newPoly;
    } 

    Poly newPoly(getCoeff(maxExponent), maxExponent);
    // Range is based on the number of exponent of toAdd because
    // at this point, it's either the polynomial being added is of 
    // equal exponents or toAdd has lesser.
    for(int i = 0; i <= toAddMaxExp; i++)
    {
        int newCoeff = toAdd.getCoeff(i) + getCoeff(i);
        newPoly.setCoeff(newCoeff, i);
    }
    // If the polynomial is not equal (which means toAdd has less exponent),
    // add the rest of the first polynomial
    if(toAddMaxExp < maxExponent) {
        for(int i = toAddMaxExp + 1; i <= maxExponent; i++)
        {
            newPoly.setCoeff(getCoeff(i), i);
        }
    }
    return newPoly;
}

Poly Poly::operator-(const Poly &toSubtract) 
{

}

Poly Poly::operator*(const Poly &toMultiply) 
{
    
}

// Get one term's coefficient
int Poly::getCoeff(int exponent) const 
{
    return polynomial[exponent];
}

// Get the polynomial's max exponent
int Poly::getMaxExp() const
{
    return maxExponent;
}

void Poly::setCoeff(int coefficient, int exponent) 
{
    polynomial[exponent] = coefficient;
}

int main() 
{
    //test
    Poly blank;
    Poly a(3,2);
    Poly b(5);
    Poly c(a);
    // cout << blank.getCoeff(0) << endl;
    // cout << a.getMaxExp() << endl;
    // cout << b.getMaxExp() << endl;
    // cout << c.getCoeff(2) << endl;
    Poly temp(b + a);
    cout << temp.getMaxExp() << endl;
    cout << temp.getCoeff(0) << endl;
    cout << temp.getCoeff(1) << endl;
    cout << temp.getCoeff(2) << endl;
    return 0;
}