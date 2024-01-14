#include <iostream>
#include <math.h>
#include <vector>
#include "printFunctions.h"
#include "task.h"

#define E 2.718281828459045235360287471352
/*********** Function being evaluated**************/

#define x_0 1
#define H 0.001

double f(double x){return pow(E,(2*cos(x)));}
double f_Prime(double x){return -2*pow(E,(2*cos(x)))*sin(x);}
double f_PrimePrime(double x);

//double f(double x){return log(x);}
//double f_Prime(double x){return 1/x;}
//double f_PrimePrime(double x){return -1/(pow(x,2));}

//double f(double x){return pow(x,4);}
//double f_Prime(double x){return 6*pow(x,5);}
//double f_PrimePrime(double x){return 30*pow(x,4);}

//double f(double x){return pow(x,9);}
//double f_Prime(double x){return 9*pow(x,8);}
//double f_PrimePrime(double x){return 72*pow(x,7);}
/***************************************************/

int main(){
 
 double value1 = f_Prime(x_0);
 double value2 = f_PrimePrime(x_0);
 
 double F_f_p = forwardDifferenceFirst(*f,x_0,H,10);
 double F_f_pp = forwardDifferenceSecond(*f,x_0,H,10);
 taskPrintStatement("Taylor formulae: Forward difference",F_f_p,f_Prime(x_0),F_f_pp,f_PrimePrime(x_0));
 
}



double f_PrimePrime(double x){return -2*(-2*pow(E,(2*cos(x)))*pow(sin(x),2)+pow(E,(2*cos(x)))*cos(x));}

