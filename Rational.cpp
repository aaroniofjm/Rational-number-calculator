
#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational() {                  //defalut ctor

}

void Rational::setNumerator(int nume) {     //setter
    numerator=nume;
}

void Rational::setDenominator(int den){//setter
    if (den==0)
        denomerator=1;
    else
        denomerator=den;
}

int Rational::getNumerator() const{//constant getter
    return numerator;
}

int Rational::getDenomerator() const {//constant getter
    return denomerator;
}

Rational Rational::reduction( const Rational& res) const  //short for result
{
    int newNume=res.numerator;      //short for numerator and denomerator
    int newDen=res.denomerator;

    if (newNume < 0 && newDen < 0)
    {
        newDen*=-1;
        newNume*=-1;
    }
    else if (newDen < 0)
    {
        newDen*=-1;
        newNume*=-1;
    }

    for (int i = newDen; i > 1; --i) {
        if(newNume % i == 0 && newDen % i == 0)
        {
            newNume/=i;
            newDen/=i;
        }

    }

    Rational result(newNume,newDen);
    return result;
}

Rational::Rational(int nume, int den) {         //ctor that allows for Rational eaxmple(9,3);

    if (den==0)
    {
        cout<<"ERROR"<<endl;
        den=1;
    }

                        //short for numerator and denomerator
    int newDen=den;
    int newNume=nume;

    if (newNume < 0 && newDen < 0)
    {
        newDen*=-1;
        newNume*=-1;
    }
    else if (newDen < 0)
    {
        newDen*=-1;
        newNume*=-1;
    }

    for (int i = newDen; i > 1; --i) {
        if(newNume % i == 0 && newDen % i == 0)
        {
            newNume/=i;
            newDen/=i;
        }

    }
    numerator=newNume;
    denomerator=newDen;
}

Rational Rational::operator+(const Rational &_rat) const {      //the PLUS operator

    Rational result;

    if (denomerator==_rat.getDenomerator())
    {
        result.setNumerator(numerator+_rat.numerator);              //if the denomonators are equal
        result.setDenominator(denomerator);
    }
    else
    {
        result.numerator=numerator*_rat.denomerator+_rat.numerator*denomerator;
        result.denomerator=denomerator*_rat.denomerator;
        //according to this calculation: a/b+c/d=(ad+cb)/bd
    }

    return reduction(result);

}

Rational Rational::operator-(const Rational &_rat) const {      //the MINUS operator

    Rational result;

    if (denomerator==_rat.getDenomerator())
    {
        result.setNumerator(numerator-_rat.getNumerator());
        result.setDenominator(denomerator);
    }
    else
    {
        result.denomerator=denomerator*_rat.denomerator;
        result.numerator=(numerator*_rat.denomerator)-(_rat.numerator*denomerator);
        //according to this calculation: a/b-c/d=(ad-cb)/bd

    }
    return reduction(result);
}

Rational Rational::operator*(const Rational &_rat) const {

    Rational result;

    result.setNumerator(numerator*_rat.getNumerator());
    result.setDenominator(denomerator*_rat.getDenomerator());
    return reduction(result);
}

Rational Rational::operator/(const Rational &_rat) const {

    Rational result;

   result.setNumerator(numerator*_rat.getDenomerator());
   result.setDenominator(denomerator*_rat.getNumerator());

    return reduction(result);
}


Rational & Rational::operator++() {       //the prefix operator
        numerator=numerator+denomerator;
        return *this;
}


Rational Rational::operator++(int u)        ////postfix
{
    Rational temp = *this;
    numerator += denomerator;
    return temp;
}


bool Rational::operator==(const Rational &_rat) const {
    Rational r1=*this;
    Rational r2(_rat);

    reduction(r1);
    reduction(r2);

    if (reduction(r1).getNumerator()==reduction(r2).getNumerator()&&reduction(r1).getDenomerator()==reduction(r2).getDenomerator())
        return true;
    return false;


}

bool Rational::operator!=(const Rational &_rat) const {
    Rational r1(*this);
    Rational r2(_rat);

    reduction(r1);
    reduction(r2);

    return !(reduction(r1).getNumerator() == reduction(r2).getNumerator() && reduction(r1).getDenomerator() == reduction(r2).getDenomerator());
}

void Rational::print() const {
    reduction(*this);
    if (numerator%denomerator==0)
    {
        cout<<numerator/denomerator;
        return;
    }
    if (denomerator==1 || numerator==0)
        cout<<numerator;
    else if (numerator==denomerator)
        cout <<1;
    else
        cout << numerator << '/' << denomerator ;
}

Rational &Rational::operator--() {
    numerator=numerator-denomerator;
    return *this;}

Rational Rational::operator--(int h) {
    Rational temp = *this;
    numerator -= denomerator;
    return temp;
}

bool Rational::operator>(const Rational &_rat) const {
    Rational temp(*this);
    if(temp.numerator<0 && temp.denomerator<0)//must make sure I have no problems if the numbers are negative
    {
        temp.numerator*=-1;
        temp.denomerator*=-1;
    }
    else {
        {
            if (temp.numerator < 0)
                temp.numerator *= -1;
        }
        if (temp.denomerator < 0) {
            temp.denomerator *= -1;
        }
    }


    float num1= (float)temp.numerator/temp.denomerator;
    float num2 = (float)_rat.numerator/_rat.denomerator;

    if (num1>num2)      //the logical part
        return true;
    return false;       //will return this even without else, bc it's a return function

}

bool Rational::operator<(const Rational &_rat) const {
    Rational temp(*this);
    if(temp.numerator<0 && temp.denomerator<0)//must make sure I have no problems if the numbers are negative
    {
        temp.numerator*=-1;
        temp.denomerator*=-1;
    }
    else {
        {
            if (temp.numerator < 0)
                temp.numerator *= -1;
        }
        if (temp.denomerator < 0) {
            temp.denomerator *= -1;
        }
    }


    float num1= (float)temp.numerator/temp.denomerator;
    float num2 = (float)_rat.numerator/_rat.denomerator;

    if (num1>num2)      //the logical part
        return false;
    return true;       //will return this even without else, bc it's a return function

}

bool Rational::operator>=(const Rational &_rat) const {
    Rational temp(*this);
    if(temp.numerator<0 && temp.denomerator<0)//must make sure I have no problems if the numbers are negative
    {
        temp.numerator*=-1;
        temp.denomerator*=-1;
    }
    else {
        {
            if (temp.numerator < 0)
                temp.numerator *= -1;
        }
        if (temp.denomerator < 0) {
            temp.denomerator *= -1;
        }
    }

    float num1= (float)temp.numerator/temp.denomerator;
    float num2 = (float)_rat.numerator/_rat.denomerator;

    if (num1>=num2)
        return true;//the logical part
    return false;
}

bool Rational::operator<=(const Rational &_rat) const {
    Rational temp(*this);
    if(temp.numerator<0 && temp.denomerator<0)//must make sure I have no problems if the numbers are negative
    {
        temp.numerator*=-1;
        temp.denomerator*=-1;
    }
    else {
        {
            if (temp.numerator < 0)
                temp.numerator *= -1;
        }
        if (temp.denomerator < 0) {
            temp.denomerator *= -1;
        }
    }


    float num1= (float)temp.numerator/temp.denomerator;
    float num2 = (float)_rat.numerator/_rat.denomerator;

    if (num1>=num2)     //the logical part
        return false;
    return true;
}

