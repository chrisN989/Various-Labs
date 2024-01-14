#include <iomanip>
#include<iostream>
#include<math.h>

#define SQRTFIVE 2.236067977499789805
#define DELTA 10e-8
#define GR (SQRTFIVE - 1) / 2


double golden(double (*f)(double),double a, double b){

 double x1,x2,fx1,fx2;

 x1 = b - GR*(b-a);
 x2 = a + GR*(b-a);

 do{
 
  if ( f(x1) > f(x2) ){
   a = x1;
   x1 = x2;
   x2 = a + GR*(b-a);
   f(x1);
   f(x2);
  //std::cout<<"*********";
  
  }
  else if( f(x2) > f(x1) ) {
   b = x2;
   x2 = x1;
   x1 = b - GR*(b-a);
   //std::cout<<"~~~~~~";
   f(x1);
   f(x2);  
  }


 }
 while(abs((b - a)) >= DELTA);

 return (b+a)/2;
};



