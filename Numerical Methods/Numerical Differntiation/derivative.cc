#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip> 
#include "printFunctions.h"
#include "forwardDifference.h"
#include "backwardDifference.h"
#include "sterling.h"
#include "findBest.h"

/*********** Function being evaluated**************/

#define x0 10
#define h 0.00001

//double f(double x){return pow(E,(2*cos(x)));}
//double f_Prime(double x){return -2*pow(E,(2*cos(x)))*sin(x);}
//double f_PrimePrime(double x);

double f(double x){return log(x);}
double f_Prime(double x){return 1/x;}
double f_PrimePrime(double x){return -1/(pow(x,2));}

//double f(double x){return pow(x,6);}
//double f_Prime(double x){return 6*pow(x,5);}
//double f_PrimePrime(double x){return 30*pow(x,4);}

//double f(double x){return pow(x,9);}
//double f_Prime(double x){return 9*pow(x,8);}
//double f_PrimePrime(double x){return 72*pow(x,7);}
/***************************************************/

int main(){
 
 printStars();
 //std::cout<<"\nf(x) = e ^ (2 cos(x))\n\n";
 
 double value1 = f_Prime(x0);
 double value2 = f_PrimePrime(x0);
 
 double F_f_p = taylorForward(*f,x0,h)[0];
 double F_f_pp = taylorForward(*f,x0,h)[1]; 
 taskPrintStatement("Taylor formulae: Forward difference",F_f_p,f_Prime(x0),F_f_pp,f_PrimePrime(x0));
 
 double B_f_p = taylorBackward(*f,x0,h)[0];
 double B_f_pp = taylorBackward(*f,x0,h)[1]; 
 taskPrintStatement("Taylor formulae: Backward difference",B_f_p,f_Prime(x0),B_f_pp,f_PrimePrime(x0));
 
 double S_f_p = sterling(*f,x0,h)[0];
 double S_f_pp = sterling(*f,x0,h)[1]; 
 taskPrintStatement("Steling formulae: Central difference",S_f_p,f_Prime(x0),S_f_pp,f_PrimePrime(x0)); 
 
 findBest("first derivative",F_f_p,B_f_p,S_f_p,value1);
 findBest("second derivative",F_f_pp,B_f_pp,S_f_pp,value2);

}

//double f_PrimePrime(double x){return -2*(-2*pow(E,(2*cos(x)))*pow(sin(x),2)+pow(E,(2*cos(x)))*cos(x));}

