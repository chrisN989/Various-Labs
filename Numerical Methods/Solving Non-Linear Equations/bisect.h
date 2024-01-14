#ifndef bisect_h
#define bisect_h

#include <cmath>

long double bisect(long double(*f)(long double x), double lower, double upper, long double e) {

 long double a, b, xk, f_xk;
    
 a = lower;
 b = upper;
    
 do{
    
  xk = (a+b)/2;
  f_xk = f(xk);
    
  long double *f_ax = new long double;
  *f_ax = f(a)*f(xk);
    
  if(*f_ax < 0){
   b = xk;
  }
  // not checking f(b)*f(xk) just assuming
  else{
   a = xk;
  }
  
 }while(!condition(f_xk,e));
    
 return xk;

}

#endif

