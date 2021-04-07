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
Poly::Poly() : maxExponent(0), arrSize(1)
{
    polynomial = new int[1];
    setCoeff(0, 0);
}

// Create a polynomial with the given coefficient and exponent
Poly::Poly(int coefficient, int exponent) : maxExponent(exponent), arrSize(exponent + 1)
{
    polynomial = new int[arrSize];
    setCoeff(coefficient, exponent);
}

// Create a polynomial with the given coefficient and an exponent of 0
Poly::Poly(int coefficient) : maxExponent(0), arrSize(1)
{ 
    polynomial = new int[1];
    setCoeff(coefficient, 0);
}

// Copy Constructor, Create a deep copy of the polynomial toCopy
Poly::Poly(const Poly &toCopy) : arrSize(toCopy.getArrSize())
{
    maxExponent = toCopy.getMaxExp();
    polynomial = new int[arrSize];
    // a = [0,1]
    // b should also be [0,1] not just [1]
    for (int i = 0; i <= maxExponent; i++) 
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
    int newMaxExp = getMaxExp();
    if (newMaxExp < toAddMaxExp)
    {
        newMaxExp = toAddMaxExp;
    }
    // Initialize a newPoly object, "0" is just a neutral number/placeholder
    Poly newPoly(0, newMaxExp);

    // Loop through the polynomial array in each object and adds
    // them to the newPoly object
    // Requires 2 arrays because the arrays might be different
    for (int i = 0; i <= getMaxExp(); i++) 
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
// Almost identical to the "+" overloaded operator
Poly Poly::operator-(const Poly &toSubtract) 
{
    int toSubMaxExp = toSubtract.getMaxExp();
    int newMaxExp = getMaxExp();
    if (newMaxExp < toSubMaxExp)
    {
        newMaxExp = toSubMaxExp;
    }
    Poly newPoly(0, newMaxExp);

    for (int i = 0; i <= getMaxExp(); i++) 
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
    int newMaxExp = getMaxExp() + toMultiply.getMaxExp();
    Poly newPoly(0, newMaxExp);

    for (int i = getMaxExp(); i >= 0; i--) 
    {
        for (int j = toMultiply.getMaxExp(); j >= 0; j--) 
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
    int toAssignExp = toAssign.getMaxExp();
    if (getArrSize() < toAssignExp) 
    {
        // If current capacity is not enough, delete the polynomial array
        // and create a new one then point the pointer to a new one
        maxExponent = toAssignExp;
        delete[] polynomial;
        polynomial = new int[toAssign.getArrSize()];
    } 
    else if (getMaxExp() > toAssignExp)
    {
        // If the original polynomial has more exponent,
        // turn them all to 0
        for (int i = toAssignExp + 1; i <= getArrSize(); i++)
        {
            setCoeff(0, i);
        }
    }

    for (int i = 0; i <= toAssignExp; i++) 
    {
        setCoeff(toAssign.getCoeff(i), i);
    }
}

// Overload addition assignment operator, adds the second polynomial to the first
// and stores the result to the first
void Poly::operator+=(const Poly &toAssign)
{
    int toAssignExp = toAssign.getMaxExp();
    
    // The following if statement is to see if the current
    // object has enough space in the array
    if (getArrSize() < toAssignExp) 
    {
        int* newArray;
        newArray = new int[toAssignExp];

        for (int i = 0; i <= toAssignExp; i++) 
        {
            int newCoeff = getCoeff(i) + toAssign.getCoeff(i);
            newArray[i] = newCoeff;
        }

        setArrSize(toAssignExp);
        delete[] polynomial;
        polynomial = newArray;
    } 
    else 
    {
        for (int i = 0; i <= toAssignExp; i++) 
        {
            int newCoeff = getCoeff(i) + toAssign.getCoeff(i);
            setCoeff(newCoeff, i);
        }
    }
}

// Overload subtraction assignment operator, adds the second polynomial to the first
// and stores the result to the first, identical to "+=" operator
void Poly::operator-=(const Poly &toAssign)
{
    int toAssignExp = toAssign.getMaxExp();
    
    // The following if statement is to see if the current
    // object has enough space in the array
    if (getArrSize() < toAssignExp) 
    {
        int* newArray;
        newArray = new int[toAssignExp];

        for (int i = 0; i <= toAssignExp; i++) 
        {
            int newCoeff = getCoeff(i) - toAssign.getCoeff(i);
            newArray[i] = newCoeff;
        }

        setArrSize(toAssignExp);
        delete[] polynomial;
        polynomial = newArray;
    } 
    else 
    {
        for (int i = 0; i <= toAssignExp; i++) 
        {
            int newCoeff = getCoeff(i) - toAssign.getCoeff(i);
            setCoeff(newCoeff, i);
        }
    }
}

// Overload multiplication assignment operator, multiply the second polynomial to the first
// and stores the result to the first
// void Poly::operator*=(const Poly &toAssign)
// {
//     int newMaxCap = getMaxCap() + toAssign.getMaxCap();
//     //search for largest exponent? as its not guaranteed no more
//     int* newPolyArray = maxCapacity;
//     if (newMaxCap > maxCapacity)
//     {
//         newPolyArray = new int[newMaxCap + 1];
//     }

//     for (int i = getMaxCap(); i >= 0; i--) 
//     {
//         for (int j = toAssign.getMaxCap(); j >= 0; j--) 
//         {
//             int newExp = i + j;
//             int newCoeff = newPolyArray[newExp] + (getCoeff(i) * toAssign.getCoeff(j));
//             newPolyArray[newExp] = newCoeff;
//         }
//     }

//     delete[] polynomial;
//     polynomial = newPolyArray;
// }

// Overload equality operator
const bool Poly::operator==(const Poly &toCompare)
{
    // For example [0, 0, 1] is equal to [1] or vice versa
    if (getMaxExp() != toCompare.getMaxExp())
    {
        return false;
    }

    for (int i = 0; i <= getMaxExp(); i++)
    {
        if (getCoeff(i) != toCompare.getCoeff(i))
        {
            return false;
        }
    }

    return true;
}

// Overload inequality operator
const bool Poly::operator!=(const Poly &toCompare)
{
    return !(*this == toCompare);
}

// Get one term's coefficient
int Poly::getCoeff(int exponent) const 
{
    return polynomial[exponent];
}

// Get the object's max exponent
int Poly::getMaxExp() const
{
    for (int i = getArrSize(); i >= 0; i--)
    {
        if (getCoeff(i) > 0)
        {
            return i;
        }
    }
    return 0;
}

// Get the object's max exponent capacity
int Poly::getArrSize() const
{
    return arrSize;
}

void Poly::setCoeff(int newCoefficient, int newExponent) 
{
    polynomial[newExponent] = newCoefficient;
}

void Poly::setArrSize(int newArrSize)
{
    arrSize = newArrSize;
}