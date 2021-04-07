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
    int maxCapacity;
    int* polynomial;

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

    bool operator==(const Poly &toCompare);
    bool operator!=(const Poly &toCompare);

    // Accessors
    int getCoeff(int exponent) const;
    int getMaxCap() const;
    
    // Mutators
    void setCoeff(int coefficient, int exponent);
};
