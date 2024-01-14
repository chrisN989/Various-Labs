#ifndef findBest_h
#define findBest_h

#include <iomanip> 
#include <math.h>
#include "printFunctions.h"

void print(int s){

 if(s==0){
  std::cout<<" Forward";
 }
 else if(s==1){
  std::cout<<" Backward";
 }
 else{
  std::cout<<" Sterling";
 }

}

void findBest(std::string s, double F,double B,double S,double value){
 
 double best = abs(F-value);
 int seek = 0;
 
 if(abs(B-value)<best){
  best = abs(B-value);
  seek = 1;
 }
 if(abs(S-value)<best){
  best = abs(S-value);
  seek = 2;
 }
 
 std::cout<<"To calculate the "<<s<<std::endl;
 std::cout<<"The lowest overall error is = "<<std::setprecision(12)<<best<<std::endl;
 std::cout<<"Using the";
 print(seek);
 std::cout<<" method!"<<std::endl;
 printStars();
}


#endif
