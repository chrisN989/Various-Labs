#ifndef simpMethod_h
#define simpMethod_h

#include <cmath>
#include "sterling.h" //fourth derivative

std::vector<double> simpsonMethod(double(*f)(double),double a, double b, int n){

  std::vector<double> answer(2,0),f_xi;

  double h,xi,k,temp;
 
  h = (b - a)/n;
  xi = a;
  k = n/2;
  
  //generating values for f(xi)
  for(int i = 0; i<=n; i++){
   if(i%2==1){
    f_xi.push_back(4*f(xi));
   }
   else{
    f_xi.push_back(f(xi));
   }
   xi += h;
  }
  
  int I = 0;
    
  do{
  
   for(int i = 1; i<4; i++){
    temp += f_xi[I];
    I++;
   }
   
   temp *= (h/3);
   answer[0] += temp;
   temp = 0;
   I--;
     
  }while(I<n);
 
 answer.push_back((pow(h,5)*sterlingFourth(*f,answer[0],0.1))/-90);
 
 return answer;
}

#endif
