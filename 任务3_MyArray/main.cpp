#include <iostream>

#include "MyArray.h"

using namespace std;

int main()
{
    MyArray A(3);
    A.set(0, 6);
    A.set(1, 8);
    A.set(2, 9);

    MyArray B(3);
    B.set(0, 3);
    B.set(1, 2);
    B.set(2, 4);

    cout << "A = ";
    A.display();
    cout << endl;
    cout << "B = ";
    B.display();
    cout << endl;

    MyArray merged = A.merge(B);
    cout << "A merge B = ";
    merged.display();
    cout << endl;

    MyArray sum = A.add(B);
    cout << "A + B = ";
    sum.display();
    cout << endl;

    MyArray diff = A.subtract(B);
    cout << "A - B = ";
    diff.display();
    cout << endl;

    MyArray product = A.multiply(B);
    cout << "A * B = ";
    product.display();
    cout << endl;

    MyArray quotient = A.divide(B);
    cout << "A / B = ";
    quotient.display();
    cout << endl;

    cout << endl;
    MyArray C(3);
    C.set(0, 1);
    C.set(1, 2);
    C.set(2, 3);

    MyArray D(2);
    D.set(0, 4);
    D.set(1, 5);

    cout << "C = ";
    C.display();
    cout << endl;
    cout << "D = ";
    D.display();
    cout << endl;

    MyArray CaddD = C.add(D);
    cout << "C + D = ";
    CaddD.display();
    cout << endl;

    cout << endl;
    MyArray E(A);
    E.set(0, 100);
    cout << "A = ";
    A.display();
    cout << endl;
    cout << "E = ";
    E.display();
    cout << endl;

    MyArray P(2);
    P.set(0, 12);
    P.set(1, 8);

    MyArray Q(2);
    Q.set(0, 4);
    Q.set(1, 0);

    MyArray PdivQ = P.divide(Q);
    P.display();
    cout << " / ";
    Q.display();
    cout << " = ";
    PdivQ.display();
    cout << endl;

    cout << "A.get(5) = " << A.get(5) << endl;

    return 0;
}
