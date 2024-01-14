#ifndef maxError_h
#define maxError_h

#include <iostream>
#include <vector>

#include "lagrange.h"

void maxError(double a, double b, std::vector<double> p,double (*f)(double)){
 std::vector<double> max (4,0);
 double STEP = (b-a) / 1000;
 double x=a;
 
 for(int i = 0; i<1000; i++){
  if(abs(evalPoly(p,x)-f(x))>max[1]){
   max[1] = abs(evalPoly(p,x)-f(x));
   max[0] = x;
  }
  x += STEP;
 }
 
 max[2] = f(max[0]);
 max[3] = evalPoly(p,max[0]);
 printError(max);
}

#endif
