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
    int maxExponent;
    int* polynomial;

public:
    Poly();
    Poly(int coefficient, int exponent);
    Poly(int coefficient);
    Poly(const Poly &toCopy);

    ~Poly();

    Poly operator+(const Poly &toAdd);
    Poly operator-(const Poly &toSubtract);
    Poly operator*(const Poly &toMultiply);

    int getCoeff(int exponent) const;
    int getMaxExp() const;
    
    void setCoeff(int coefficient, int exponent);
};
