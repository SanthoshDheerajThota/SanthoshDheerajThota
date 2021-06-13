#include <iostream>
using namespace std;
class Rational{
    private :
        int numerator;
        int demonimator;
    public :
        void setValues();
        void printValues();
        friend void addThem(Rational r1,Rational r2);
        friend void multiplyThem(Rational r1,Rational r2);
};
class Complex {
    private:
        int real;
        int imag;
    public :
        void setValues();
        void printValues();
        friend void addThem(Complex c1,Complex c2);
        friend void multiplyThem(Complex c1,Complex c2);
};
void Rational:: setValues(){
    cout<<"enter the numerator and demonimator values of the Rational number :"<<endl;
    cin>>this->numerator;
    cin>>this->demonimator;
}
void Rational:: printValues(){
    cout<<"the rational number is "<<this->numerator<<" / "<<this->demonimator<<endl;
}
void addThem(Rational r1,Rational r2){
    Rational answer;
    answer.numerator=r1.numerator*r2.demonimator+r1.demonimator*r2.numerator;
    answer.demonimator=r1.demonimator*r2.demonimator;
    cout<<"the  answer of addition is is "<<endl;
    answer.printValues();
    return;
}
void multiplyThem(Complex r1,Complex r2){
    Complex answer;
    answer.real=r1.real+r2.real-r1.imag+r2.imag;
    answer.imag=r1.imag*r2.real+r1.real*r1.imag;
    cout<<"the answer od multiplication  is "<<endl;
    answer.printValues();
    return;
}
void addThem(Complex r1,Complex r2){
    Complex answer;
    answer.real=r1.real+r2.real;
    answer.imag=r1.imag+r2.imag;
    cout<<"the  answer of addition is is "<<endl;
    answer.printValues();
    return;
}
void multiplyThem(Rational r1,Rational r2){
    Rational answer;
    answer.numerator=r1.numerator*r2.numerator;
    answer.demonimator=r1.demonimator*r2.demonimator;
    cout<<"the answer od multiplication  is "<<endl;
    answer.printValues();
    return;
}
void Complex:: setValues(){
    cout<<"enter the real and imag part of a complex number :"<<endl;
    cin>>this->real;
    cin>>this->imag;
}
void Complex:: printValues(){
    cout<<"the complex number is "<<this->real<<" + "<<this->imag<<" i "<<endl;
}
int main(){
    Rational *r1,*r2,*r3;
    r1=new Rational;
    r1->setValues();
    r1->printValues();
    r2=new Rational;
    r2->setValues();
    r2->printValues();
    addThem(*r1,*r2);
    multiplyThem(*r1,*r2);
    delete r1;
    delete r2;
    Complex *c1,*c2;
    c1=new Complex;
    c1->setValues();
    c1->printValues();
    c2=new Complex;
    c2->setValues();
    c2->printValues();
    addThem(*c1,*c2);
    multiplyThem(*c1,*c2);
    return 0;
}
