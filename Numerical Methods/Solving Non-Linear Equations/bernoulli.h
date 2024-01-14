#ifndef bernoulli_h
#define bernoulli_h

#include <cmath>
#include <vector>

#include "printFunctions.h"

void push_front(std::vector<long double>& vec, long double element) {
    vec.insert(vec.begin(), element);
}

long double bernoulli(long double(*f)(long double x),std::vector<double> c, double e){
  
 long double answer;
 long double y_star = 0;
 long double xm = 0;
 long double f_xm = 0;
 //here we save a0 in a variable and shorten the coefficient
 //vector in order to make it the same size as y_star_vector
 double a0 = c[0];
 c.erase(c.begin());
 int n = c.size();
 
  //Building set of initial conditions
 std::vector<long double> y_star_vector((n-1),0);//could be other value than zero
 push_front(y_star_vector,1);
  
 int iteration = 0; 
 do{
 
  for(int i =n-1; i>=0; i--){
   y_star += c[i]*y_star_vector[i];
  }
  
  y_star /= -a0;
  //approximate root
  xm = y_star/y_star_vector[0];
    
  //adding new y_star to front
  push_front(y_star_vector,y_star); 
  //removing last value since it won't be needed
  y_star_vector.pop_back(); 

  y_star=0;
  //std::cout<<std::setprecision(20)<<std::setw(25)<<xm<<" "<<f(xm)<<"\n";
  iteration++; 
 }while(std::fabs(f(xm))>e);
 
 answer = xm;
 //std::cout<<"Iteration:Bernoulli = "<<iteration<<"\n";
 return answer;
 
}

#endif
