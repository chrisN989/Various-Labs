#ifndef conditions_h
#define conditions_h
#include <cmath>


bool condition( long double f_xk, long double e){
 
 if(std::fabs(f_xk)<e){
  //std::cout<<"true\n";
  return true;
 }
 //std::cout<<"false\n";
 return false;

}


#endif






