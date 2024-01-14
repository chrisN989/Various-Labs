#ifndef printFunctions_h
#define printFunctions_h

#include <iomanip>
#include <vector>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197
/************** printStars function ***************/

void printStars(){
 for(int i = 0; i<50; i++){
  std::cout<<"*";
 }
std::cout<<std::endl;
} 

void print(std::string S){
  printStars();
  std::cout<<S<<std::endl;
}
/*************** printV function *****************/
void printV(std::vector<double>v){
 for(auto c : v){
  std::cout<<c<<" ";
 }
 std::cout<<std::endl;
}

void taskPrintStatement(std::string s,double numerical, double analytical,double a, double b,double error){
 
 auto c = std::setprecision(20);
 auto f = std::fixed;
 auto d = std::defaultfloat;
 
 long double absoluteError = std::fabs(numerical - analytical);
 long double relativeError = (absoluteError/analytical)*100;
  
 printStars();
 printStars();
  
 std::cout<<"\nThe definite integral of f'(x) using the "<< s <<d<<"\nbetween "<<a<<" and "<< b <<" is: \n\n";
 std::cout<<"Numerical value = "<<c<<numerical<<std::endl;
 

 if(std::isnan(analytical)){
  std::cout<<"Analytical value error -> miscalculation "<<std::endl; 
 }
 else{
  std::cout<<"Analytical value = "<<c<<analytical<<std::endl; 
 } 
 
  if(error != 999){
  std::cout<<"Integration error (R) = "<<c<<f<<error<<std::endl; 
 }
 
 if(std::isnan(absoluteError)){
  std::cout<<"Integration absolute error -> miscalculation "<<std::endl; 
 }
 else{
  std::cout<<"Integration absolute error = "<<c<<f<<absoluteError<<std::endl;
 } 
 if(std::isnan(relativeError)){
  std::cout<<"Integration relative error -> miscalculation "<<std::endl; 
 }
 else{
  std::cout<<"Integration relative error = "<<c<<f<<std::fabs(relativeError)<<" %"<<std::endl<<std::endl;
 }
     
}

void errorPrint(long double numerical, long double analytical, long double error){
 
 auto c = std::setprecision(18);
 
 long double oldAbsoluteError = std::fabs(numerical - analytical);
 long double oldRelativeError = (oldAbsoluteError/analytical)*100;
 
 long double correction = numerical + error; 
 long double absoluteError = std::fabs(correction - analytical);
 long double relativeError = (absoluteError/analytical)*100; 
 
 long double improvementRelative = 1 - (absoluteError/oldAbsoluteError); 
 long double improvementAbsolute = 1 - (relativeError/oldRelativeError);

  
 std::cout<<"Correction = numerical + R"<< correction << std::endl;

 if(std::isnan(analytical)){
  std::cout<<"New analytical value error -> miscalculation "<<std::endl; 
 }
 else{
  std::cout<<"New analytical value = "<<c<<analytical<<std::endl; 
 }
  
 if(std::isnan(absoluteError)){
  std::cout<<"New integration absolute error -> miscalculation "<<std::endl; 
 }
 else{
  std::cout<<"New integration absolute error = "<<c<<absoluteError<<std::endl;
  std::cout<<"Improvement = "<<improvementAbsolute<<" %"<<std::endl; 
 } 
 if(std::isnan(relativeError)){
  std::cout<<"New integration relative error -> miscalculation "<<std::endl; 

 }
 else{
  std::cout<<"New integration relative error = "<<c<<std::fabs(relativeError)<<"%"<<std::endl;
  std::cout<<"Improvement = "<<improvementRelative<<" %"<<std::endl<<std::endl;
 }
     

}


#endif












