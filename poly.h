// ------------------------------------------------ Poly.h --------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 2/4/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This project is to create the abstract data type (ADT) for a polynomial called Poly.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

class Poly
{
private:
    int* polynomial;
    int arrSize;

public:
    // Constructors
    Poly();
    Poly(int coefficient, int exponent);
    Poly(int coefficient);
    // Copy Constructor
    Poly(const Poly &toCopy);

    // Destructor
    ~Poly();

    // Common overloaded operators
    Poly operator+(const Poly &toAdd);
    Poly operator-(const Poly &toSubtract);
    Poly operator*(const Poly &toMultiply);

    void operator=(const Poly &toAssign);
    void operator+=(const Poly &toAssign);
    void operator-=(const Poly &toAssign);
    void operator*=(const Poly &toAssign);

    const bool operator==(const Poly &toCompare);
    const bool operator!=(const Poly &toCompare);

    // Accessors
    int getCoeff(int exponent) const;
    int getMaxExp() const;
    int getArrSize() const;
    
    // Mutators
    void setCoeff(int newCoefficient, int Exponent);
    void setArrSize(int newArrSize);
};
