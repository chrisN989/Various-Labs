#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>

#include "conditions.h"
#include "bisect.h"
#include "false_position.h"
#include "secant.h"
#include "tangent.h"
#include "bernoulli.h"
#include "timer.h"

#include "sterling.h"
#include "forwardDifference.h"

#define E  2.7182818284590452353602874713526624977572470937

//long double f(long double x) { return sin(pow(E, x)); }
long double f(long double x){return pow(E,(x-1))+pow(x,2)-2;}
//long double f(long double x){return pow(x,30);}
//long double f(long double x){return pow(x,5)+5*pow(x,4)-5;}

//long double f2(long double x){return pow(x,5)+5*pow(x,4)-5;}
//long double f(long double x){return pow(x,4)-14*pow(x,3)+3*pow(x,2)+410*x-400;}

int main(){

double a,b;
long double e;

a = -10.0;
b = 0.0;
e = 1;

std::ofstream file("data.txt");

for (int i = 0; i < 16 ; i++) {
 
 double bis = timer(bisect,*f,a,b,e);
 double fal = timer(false_position,*f,a,b,e);
 double sec = timer(secant,*f,a,b,e);
 double tan = timer(tangent,*f,a,b,e);       
 
 file << std::setprecision(5)<<std::setw(10)<< e << std::setprecision(28) << " " <<  bis << " " << fal << " "<< sec<< " "<< tan << std::endl;       
 
 //std::cout<<e<<" ";
 e *= 0.1;

}
    
file.close();


/*

//std::cout<<std::setprecision(28)<<bisect(*f,a,b,e)<<"\n";
std::cout<<std::setprecision(28)<<timer(bisect,*f,a,b,e)<<" us\n";


//std::cout<<std::setprecision(28)<<false_position(*f,a,b,e)<<"\n\n";
std::cout<<std::setprecision(28)<<timer(false_position,*f,a,b,e)<<" us\n";

//std::cout<<std::setprecision(28)<<secant(*f,a,b,e)<<"\n";
std::cout<<std::setprecision(28)<<timer(secant,*f,a,b,e)<<" us\n";


//std::cout<<std::setprecision(28)<<tangent(*f,a,b,e)<<"\n\n";
std::cout<<std::setprecision(28)<<timer(tangent,*f,a,b,e)<<" us\n";
std::vector<double> W = {1,5,0,0,0,-5};
//std::vector<double> W = {1 , -14,3,410,-400};
std::cout<<std::setprecision(28)<<bernoulli(*f,W,e)<<"\n\n";
std::cout<<std::setprecision(28)<<timer(bernoulli,*f,W,e)<<" us\n";
//a = 1.0;
//b = 10.0;
//std::cout<<std::setprecision(28)<<false_position(*f,a,b,e)<<"\n\n";
//std::cout<<std::setprecision(28)<<timer(tangent,*f,a,b,e)<<"\n";

*/
}







