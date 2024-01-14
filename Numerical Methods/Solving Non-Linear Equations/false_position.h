#ifndef false_position_h
#define false_position_h

#include <cmath>
#include <vector>

#include "sterling.h"

long double false_position(long double(*f)(long double x),double a, double b, long double e){

 long double answer,constant_point,x0,xi;
 
 auto f_pp = sterling(*f,0,0.001)[1];
 
 //finding constant point
 if((f(a)>0 && f_pp>0) || (f(a)<0 && f_pp<0)){
  constant_point = a;
 }
 else if((f(b)>0 && f_pp>0) || (f(b)<0 && f_pp<0)){
  constant_point = b;
 }
 //else use secant method!?
 x0 = a - f(a)/(f(b)-f(a))*(b-a);
 int iteration = 0;
 do{
    
  xi = x0 - f(x0)/(f(constant_point)-f(x0)) * (constant_point - x0);
  answer = xi;
  //std::cout<<xi<<"\n";
  x0 = xi;
  xi = 0;
  iteration++;
 }while(std::fabs(f(answer))>e);
 
 //std::cout<<"iteration:Regula falsi = "<<iteration<<"\n";
 return answer;

}

#endif
