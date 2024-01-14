#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "printFunctions.h"
#include "rectangle.h"
#include "trapMethod.h"
#include "simpMethod.h"
#include "cheb.h"
#include "gauss.h"

#define PI 3.141592653589793238462643383279502884197


double f_p(double x){return ((pow(x,3)*cos(x/2)+0.5)*sqrt(4-pow(x,2)));}

double f(double x){return (-0.5 * pow(x, 3) * sin(0.5 * x) + 3 * pow(x, 2) * cos(0.5 * x)) * sqrt(4 - pow(x, 2)) - (x * (pow(x, 3) * cos(0.5 * x) + 0.5)) / sqrt(4 - pow(x, 2));}


//double f(double x){return pow(x,4)/4 + (2*pow(x,3)/3)-x;}

//double f_p(double x){return pow(x,3) + 2*pow(x,2)-1;}
//double f(double x){return pow(x,2)/2;}
//double f_p(double x){return x;}                    

int main(){

double a = -2; 
double b = 2; 


//double real = PI;




for(int i = 1; i<10; i++){
  e = pow(10.0,-1*i);
  
 long double chebAbsError = std::fabs(chebyshev(*f_p,a,b,e)-PI);
 long double gaussAbsError = std::fabs(gauss(*f_p,a,b,e)-PI);
   
 std::cout<<std::setprecision(28)<<std::setw(8)<<std::fixed<<e<<" "<<chebAbsError<<" "<<gaussAbsError<<" "<<std::endl;
 //std::cout<<std::setprecision(28)<<chebyshev(*f_p,a,b,e)<<" "<<gauss(*f_p,a,b,e)<<" "<<std::endl;
}
















}

