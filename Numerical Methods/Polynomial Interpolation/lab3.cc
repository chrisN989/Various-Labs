#include <iostream>
#include <vector>
#include <math.h>
#include "lagrange.h"
#include "maxError.h"

void task1(int,double,double,double);
void task2(int,double,double,double);

double f(double x){return 12*pow(x,3)+5*pow(x,2)-20*x ;}
//double f(double x){return (pow(x,3)+2)/((sqrt(pow(x,2)-9*x+4)))-300;}
//double f(double x){return abs(x);}
//double f(double x){return (x*sin(x))/(cos(x));}
//double f(double x){return tan(x);}
int main(){
 
 double x0= 2;
 print("f(x) = xsin(x)  ");
 

 task1(5,0,6,x0);
 task2(5,0,6,x0);

}

void task1(int n,double a,double b,double x0){

 double interval=abs((b - a) / (n-1));
 double s = a;
  
 std::vector<double> x,y,equality;
 x.push_back(a);
 y.push_back(f(a));
 
 for(int i = 0; i<n-1; i++){
  s += interval;
  x.push_back(s); 
  y.push_back(f(s));
 } 
 for(int i = 0; i<n; i++){
  equality.push_back(x[i]);
  equality.push_back(y[i]); 
 }
 
 double functionEval = f(x0);
 double polyEval = evalPoly(LagrangeInterpolation(equality),x0);
 taskPrintStatement("(Equidistant Nodes)",n,a,b,x0,x,y,functionEval,polyEval,LagrangeInterpolation(equality));
 maxError(a,b,LagrangeInterpolation(equality),*f);
}

void task2(int n,double a,double b,double x0){
 
 std::vector<double> xCheb,fCheb,equality;
  
  xCheb.push_back(a);
  fCheb.push_back(f(a));
 
 for(int i = 1; i<n; i++){
  xCheb.push_back(chebyshevNodes(n,a,b)[i]);
  fCheb.push_back(f(xCheb[i]));
 }
 for(int i = 0; i<n; i++){
  equality.push_back(xCheb[i]);
  equality.push_back(fCheb[i]); 
 }
 double functionEval = f(x0);
 double polyEval = evalPoly(LagrangeInterpolation(equality),x0);
 taskPrintStatement(" (Chebyshev nodes)",n,a,b,x0,xCheb,fCheb,functionEval,polyEval,LagrangeInterpolation(equality));
 maxError(a,b,LagrangeInterpolation(equality),*f);
}









