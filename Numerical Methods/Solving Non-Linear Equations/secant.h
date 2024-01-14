#ifndef secant_h
#define secant_h

#include <cmath>

long double secant(long double(*f)(long double x),double a, double b, long double e){

 long double answer,constant_point,x0,xi;
  
 x0 = a - f(a)/(f(b)-f(a))*(b-a);
 
 do{
   
  xi = b - f(b)/(f(b)-f(x0))*(b-x0);
  answer = xi;
  //std::cout<<answer<<"\n";
  x0 = xi;
  xi = 0;

 }while(std::fabs(f(answer))>e);
  
 return answer;

}

#endif
