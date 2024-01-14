#ifndef gauss_h
#define gauss_h

#include <cmath>

long double gauss(double(*f)(double), double a, double b, double e){
 
 long double temp,answer;
 answer=temp=0;
 
 long double x1,x2,x3;
 const long double c = sqrt(3.0/5.0); 

 double w1, w2, w3;
 w1 = w3 = 5.0/9.0;
 w2 = 8.0/9.0;
 
 //guess of number of sub-intervals based on required 'e' (eq 5.41)
 int m = std::ceil((b-a)/sqrt(e));
 int M = 0; // used to track number of sub-intervals
 if(m%2==1){m++;}
 
 //width of interval (step size)
 const double k = (b-a)/m;
 
 long double lower = a;
 long double upper = lower + k;
 
 do{
  
  x1 = (upper+lower)/2.0 - c*(upper-lower)/2.0;
  x2 = (upper+lower)/2.0;
  x3 = (upper+lower)/2.0 + c*(upper-lower)/2.0; 
  
  temp += w1 * f(x1) + w2 * f(x2) + w3 * f(x3);
  
  temp *= (upper-lower)/2.0;
  answer += temp;

  x1 = x2 = x3 = temp = 0;
  
  lower = upper;
  upper += k;
  
  M++;
  
 }while(M<m); 
 
 return answer;
}

#endif

