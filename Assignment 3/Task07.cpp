#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
class Complex {
    double re, im;
public:
    Complex():re(0),im(0){}
    Complex(double r):re(r),im(0){}
    Complex(double r,double i):re(r),im(i){}
    Complex operator+(const Complex& z)const{return {re+z.re,im+z.im};}
    Complex operator-(const Complex& z)const{return {re-z.re,im-z.im};}
    Complex operator*(const Complex& z)const{return {re*z.re-im*z.im,re*z.im+im*z.re};}
    Complex operator/(const Complex& z)const{double d=z.re*z.re+z.im*z.im;if(d==0)throw domain_error("Division by zero impedance");return {(re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d};}
    bool operator==(const Complex& z)const{return re==z.re&&im==z.im;}
    double magnitude()const{return hypot(re,im);}
    friend ostream& operator<<(ostream& os,const Complex& z){return os<<z.re<<(z.im<0?" - ":" + ")<<abs(z.im)<<'j';}
};
int main(){
    const double pi=acos(-1.0), f=50.0, w=2*pi*f, R=10.0, L=0.05, C=100e-6;
    Complex Zr(R,0), Zl(0,w*L), Zc(0,-1.0/(w*C));
    Complex series=Zr+Zl+Zc;
    Complex parallel=(Zr*Zl)/(Zr+Zl);
    cout<<"Resistor: "<<Zr<<" | magnitude="<<Zr.magnitude()<<'\n';
    cout<<"Series RLC: "<<series<<" | magnitude="<<series.magnitude()<<'\n';
    cout<<"Parallel R-L: "<<parallel<<" | magnitude="<<parallel.magnitude()<<'\n';
    try{ Complex invalid=Zr/Complex(); cout<<invalid<<'\n'; }catch(const domain_error& e){cout<<"Safe error: "<<e.what()<<'\n';}
}
