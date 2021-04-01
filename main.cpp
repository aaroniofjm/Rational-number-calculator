#include <iostream>
#include "Rational.h"

using namespace std;

enum{add,sub,mult,divi,addPre,addPost,subPre,subPost,big,small,bigEq,smallEq,eequal,notEqual};
int main()
{
    int numerator, denominator;
    char tav;
    int op=1;



   while (op != 0)
    {
        cout << "enter two rational numbers:" << endl;
        cin >> numerator >> tav >> denominator;
        Rational r1(numerator, denominator);
        cin >> numerator >> tav >> denominator;
        Rational r2(numerator, denominator);
        switch (0)
        {
            case add:r1.print(); cout << " + "; r2.print(); cout << " = "; (r1 + r2).print(); cout << endl;

            case sub:r1.print(); cout << " - "; r2.print(); cout << " = "; (r1 - r2).print(); cout << endl;

            case mult:r1.print(); cout << " * "; r2.print(); cout << " = "; (r1 * r2).print(); cout << endl;

            case divi:r1.print(); cout << " / "; r2.print(); cout << " = "; (r1 / r2).print(); cout << endl;

            case addPre:cout << "++"; cout << "("; r1.print();  cout << ") = "; (++r1).print(); cout << endl;

            case addPost: cout << "("; r1.print(); cout << ")++"; cout << " = "; (r1++).print(); cout << endl;

            case subPre:cout << "--"; cout << "("; r1.print();  cout << ") = "; (--r1).print(); cout << endl;

            case subPost:cout << "("; r1.print(); cout << ")--"; cout << " = "; (r1--).print(); cout << endl;

            case big:r1.print(); cout << " > "; r2.print(); cout << " ? ";  (r1 > r2) ? cout << "yes" : cout << "no"; cout << endl;

            case small:r1.print(); cout << " < "; r2.print(); cout << " ? ";  (r1 < r2) ? cout << "yes" : cout << "no"; cout << endl;

            case bigEq:r1.print(); cout << " >= "; r2.print(); cout << " ? ";  (r1 >= r2) ? cout << "yes" : cout << "no"; cout << endl;

            case smallEq:r1.print(); cout << " <= "; r2.print(); cout << " ? ";  (r1 <= r2) ? cout << "yes" : cout << "no"; cout << endl;

            case eequal:r1.print(); cout << " == "; r2.print(); cout << " ? ";  (r1 == r2) ? cout << "yes" : cout << "no"; cout << endl;

            case notEqual:r1.print(); cout << " != "; r2.print(); cout << " ? ";  (r1 != r2) ? cout << "yes" : cout << "no"; cout << endl;

        }
        cout << "enter 1 to cont. 0 to exit." << endl;
        cin >> op;
    }

    return 0;
}
