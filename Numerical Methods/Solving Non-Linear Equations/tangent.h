#ifndef tangent_h
#define tangent_h

#include <cmath>
#include <vector>

#include "sterling.h"
#include "forwardDifference.h"
long double tangent(long double(*f)(long double x),double a, double b, long double e){

 long double answer,x0,xi;
 
 auto f_pp_a = sterling(*f,a,0.001)[1];
 auto f_pp_b = sterling(*f,b,0.001)[1]; 
 
 if(f(a)>0 && f(f_pp_a)>0 ){//|| f(a)<0 && f(f_pp_a)<0 ){
  x0 = a;
 }
 else if(f(b)>0 && f(f_pp_b)>0){// || f(b)<0 && f(f_pp_b)<0){
  x0 = b;
 }
 
 int iteration = 0;

 do{
  auto x0_p = taylorForward(*f,x0,0.001)[0];//sterling(*f,x0,0.001)[0]; 
  xi = x0 - f(x0)/x0_p;
  answer = xi;
  //std::cout<<xi<<"\n";
  x0 = xi;
  xi = 0;
  iteration++;
 }while(std::fabs(f(answer))>e);
 
 //std::cout<<"Iteration:Tangent = "<<iteration<<"\n";
 return answer;

}

#endif
