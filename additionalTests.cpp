#include "poly.h"
#include <iostream>

using namespace std;

int main() 
{
    //test
    Poly blank;
    Poly a(-8,3);
    Poly b(2,1);
    Poly c(-5,1);
    Poly d(2); //-8^3 -3^1 +2

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

    Poly temp(a);
    
    for (int i = temp.getMaxCap(); i >= 0; i--) 
    {
        cout << temp.getCoeff(i) << ", ";  
    }
    cout <<endl;
    temp -= b;
    for (int i = temp.getMaxCap(); i >= 0; i--) 
    {
        cout << temp.getCoeff(i) << ", ";  
    }
    cout << endl;
    if (temp == a)
    {
        cout << "temp == a" << endl;
    }
    cout << temp.getMaxCap() << endl;;
    return 0;
}