#ifndef chebby_h
#define chebby_h

#include <cmath>
#include "Chebyshev_T_Table.h"

long double chebyshev(double(*f)(double), double a, double b, double e){
 
 long double temp,answer;
 answer=temp=0;
 long double xi;
 int n = 2;
 
 //points to t_i in "Chebyshev_T_Table.h" 
 auto *p = &t_vector[n-2];
 
 //guess of number of sub-intervals based on required 'e' (eq 5.41)
 int m = std::ceil((b-a)/sqrt(e));
 int M = 0; // used to track number of sub-intervals
 if(m%2==1){m++;}
 
 //width of interval
 const double k = (b-a)/m;
 
 long double lower = a;
 long double upper = lower + k;
 
 do{
  
  for(int i = 0; i<n; i++){
   xi = (lower+upper)/2+(*p)[i]*(lower-upper)/2;
   temp += f(xi);
   xi = 0;
  }
  
  temp *= (upper-lower)/n;
  answer += temp;

  temp = 0;
  lower = upper;
  upper += k;
  M++;
 }while(M<m); 
 
 return answer;
}


#endif



























