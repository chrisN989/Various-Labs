#include <iomanip>
#include<iostream>
#include<math.h>

#define SQRTFIVE 2.236067977499789805
#define DELTA 10e-9
#define GR (SQRTFIVE - 1) / 2


double minimumOfFunction(double (*f)(double),double a, double b){

double x1,x2,fx1,fx2;

x1 = b - GR*(b-a);
x2 = a + GR*(b-a);

fx1 = f(x1);
fx2 = f(x2);

do{
 
 if ( f(x1) > f(x2) ){
  a = x1;
  x1 = x2;
  x2 = a + GR*(b-a);
  f(x1);
  f(x2);
  //std::cout<<"*********";
  
 }
 if( f(x2) > f(x1) ) {
  b = x2;
  x2 = x1;
  x1 = b - GR*(b-a);
  //std::cout<<"~~~~~~";
  f(x1);
  f(x2);  
 }


}
while((b - a) >= DELTA);

//std::cout<<x1<<" "<<x2<<" "<<fx1<<" "<<fx2<<" "<<a<<" "<< b<<"\n";
return (x1+x2)/2;

};


double f(double x){
return -(pow(x,2) - 0.4*x + 0.04 );
};

double trueF(double x){
return x / (1.4 - sin(2*x)) ;
};

int main(){

double X = minimumOfFunction(*f,-1,2);
std::cout<<std::setprecision(12)<<"The maximum is x= "<< X <<"\n";
std::cout<<std::setprecision(12)<<"f(x)= "<<trueF(X);


}
