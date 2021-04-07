#include "poly.h"
#include <iostream>

using namespace std;

int main() 
{
    //test
    Poly a(-8,3);
    Poly b(2,2);
    Poly c(-5,1);
    Poly d(2); //-8x^3 + 2x^2 -5x + 2

    Poly e(-3,2);
    Poly f(7); 
    Poly g(5,1);
    Poly ha(-9,3);//-9x^3 -3x^2 + 5x + 7
    
    Poly q(a + b);
    Poly o(q + c);
    Poly x(o + d);

    Poly w(e + f);
    Poly hi(w + ha);
    Poly y(hi + g);

    Poly temp(x * y);
    
    for (int i = temp.getArrSize() - 1; i > -1; i--) 
    {
        cout << temp.getCoeff(i) << ", ";  
    }
    // cout <<endl;
    // temp -= b;
    // for (int i = temp.getArrSize(); i >= 0; i--) 
    // {
    //     cout << temp.getCoeff(i) << ", ";  
    // }
    cout << endl;
    // if (temp == a)
    // {
    //     cout << "temp == a" << endl;
    // }
    cout << temp.getArrSize() << endl;
    cout << temp.getMaxExp() << endl;
    return 0;
}