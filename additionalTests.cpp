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
    
    cout << q << " yay" << endl;

    Poly w(e + f);
    Poly hi(w + ha);
    Poly y(hi + g);

    // Poly nu(3,4);
    // Poly r(2,2);
    // Poly def(3,4);
    // x = nu + r;
    // x = x - def;// [3,0,2,0,0] - [3,0,0,0,0]

    // Poly ya(-9,3);
    // Poly yu(-3,2);
    // ya += yu;
    // temp -= ya;

    // Poly truth(-9,4);
    // truth += a;
    // Poly truthh(-9,4);
    // truth -= truthh;

    Poly temp(x);

    Poly huge(3,10);
    huge -= huge;
    // huge += y;
    // temp *= huge;
    // cout << x * y << " x*y";
    // cout << endl;
    // cout << "input: ";
    // cin >> huge;
    // cout << huge << " temp";
    // cout << endl;
    // if (temp == a)
    // {
    //     cout << "temp == a" << endl;
    // } else {
    //     cout << "nah" << endl;
    // }
    cout << huge.getArrSize() << endl;
    cout << huge.getMaxExp() << endl;
    return 0;
}