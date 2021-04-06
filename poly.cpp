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

// Overload addition operator, create a new Poly object
// that stores the sum of the 2 given polynomials
Poly Poly::operator+(const Poly &toAdd)
{
    int toAddMaxExp = toAdd.getMaxExp();
    int maxExp = getMaxExp();
    if (maxExponent < toAddMaxExp)
    {
        maxExp = toAddMaxExp;
    }
    // Initialize a newPoly object, "0" is just a neutral number/placeholder
    Poly newPoly(0, maxExp);

    for (int i = 0; i <= maxExponent; i++) 
    {
        newPoly.setCoeff(getCoeff(i), i);
    }
    for (int i = 0; i <= toAddMaxExp; i++) 
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
    int toSubMaxExp = toSubtract.getMaxExp();
    int maxExp = getMaxExp();
    if (maxExponent < toSubMaxExp)
    {
        maxExp = toSubMaxExp;
    }
    // Initialize a newPoly object, "0" is just a neutral number/placeholder
    Poly newPoly(0, maxExp);

    for (int i = 0; i <= maxExponent; i++) 
    {
        newPoly.setCoeff(getCoeff(i), i);
    }
    for (int i = 0; i <= toSubMaxExp; i++) 
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
    int maxExp = getMaxExp() + toMultiply.getMaxExp();
    Poly newPoly(0, maxExp);

    for (int i = getMaxExp(); i >= 0; i--) 
    {
        for (int j = toMultiply.getMaxExp(); j >= 0; j--) 
        {
            int newExp = i + j;
            int newCoeff = newPoly.getCoeff(newExp) + (getCoeff(i) * toMultiply.getCoeff(j));
            cout << newPoly.getCoeff(newExp) << " coeff at newPoly" <<endl;
            cout << i << " i " << j << " j" <<endl;
            cout << "     " << newExp << " exp " << newCoeff << " coeff" <<endl;
            cout << endl;
            newPoly.setCoeff(newCoeff, newExp);
        }
    }

    return newPoly;
}

// Overload assignment operator, assign one polynomial to another
Poly Poly::operator=(const Poly &toAssign)
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
    for (int i = temp.getMaxExp(); i >= 0; i--) 
    {
        cout << temp.getCoeff(i) << ", ";  
    }
    cout << endl;
    cout << temp.getMaxExp() << endl;;
    return 0;
}