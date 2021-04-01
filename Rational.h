#ifndef EX3QUES1_RATIONAL_H
#define EX3QUES1_RATIONAL_H
using namespace std;

class Rational {

private:
    //MEMBERS
    int numerator;
    int denomerator;

public:
    //constructors
    Rational();
    Rational(int nume, int den);

    //setters
    void setNumerator(int);
    void setDenominator(int);

    //getters
    int getNumerator () const;      //const bc we don't change any value
    int getDenomerator() const;    //const bc we don't change any value

    //print method
    void print() const; //const bc we don't change any value

    //ARITHMETICAL OPERATORS
    Rational reduction (const Rational& res) const;
    Rational operator + (const Rational &_rat) const;
    Rational operator - (const Rational &_rat) const;
    Rational operator * (const Rational &_rat) const;
    Rational operator / (const Rational &_rat) const;

    //LOGICAL OPERATORS
    bool operator == (const Rational &_rat) const;
    bool operator != (const Rational &_rat) const;
    bool operator > (const Rational &_rat) const;
    bool operator < (const Rational &_rat) const;
    bool operator >= (const Rational &_rat) const;
    bool operator <= (const Rational &_rat) const;

    //UNARY OPERATORS (ADD)
    Rational & operator++();    //the prefix operator
    Rational operator ++ (int); //postfix

    //UNARY OPERATORS (SUBTRACT)
    Rational & operator--();
    Rational operator -- (int); //postfix

};


#endif //EX3QUES1_RATIONAL_H
