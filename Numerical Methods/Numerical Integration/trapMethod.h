#ifndef trapMethod_h
#define trapMethod_h

#include <cmath>

#include "forwardDifference.h"

std::vector<double> trapezoidalMethod(double(*f)(double),double a, double b, int n){
 
 std::vector<double> answer;
 
 double approximation,xi,h,error;
 
 h = (b - a)/n;
 
 std::vector<double> v;
 v.push_back(f(a));
 
 for(int i = 1; i<n; i++){
  xi = a + i*h;
  v.push_back(2.0*f(xi));
 }
 
 v.push_back(f(b));
 
 for(auto c : v){
  approximation += c;
 }
  
  
 answer.push_back((h*approximation)/2.0);
 
 error = taylorForward(*f,approximation,0.01)[1]; 
 answer.push_back((pow(h,3)*error)/-12.0);
 
 return answer; 
}

#endif
