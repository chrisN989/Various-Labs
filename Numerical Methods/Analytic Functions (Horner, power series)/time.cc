#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <chrono>
#include "horner.h"

using namespace std::chrono;

#define ITERATION 100000

int main(){
/***************************************************/
/****comparing math.h to horner as polynomial*******/
/*********** degree increases **********************/ 
/***************************************************/ 
std::string fileName("data.txt");
std::fstream fileStream;
fileStream.open(fileName,std::fstream::out);

int degree = 10;
double m=1,m1=1,m2=1,m3=1,m4=1;

std::vector<double> polynomial={1,1,1,1,1,0,0,0,0,0,0};

for(int i = 0; i<ITERATION; i++){
 
 auto start1 = high_resolution_clock::now();
 double h = horner(polynomial,5);
 auto stop1 = high_resolution_clock::now();

 auto duration1 = duration_cast<microseconds>(stop1 - start1);
 
 auto start2 = high_resolution_clock::now();
 for(int i = 0; i<degree; i++){
  m *= 5;
 }
 for(int i = 0; i<degree-1; i++){
  m1 *= 5;
 }
 for(int i = 0; i<degree-2; i++){
  m2 *= 5;
 }
 for(int i = 0; i<degree-3; i++){
  m3 *= 5;
 }
 for(int i = 0; i<degree-4; i++){
  m4 *= 5;
 }
 m += m1 + m2 + m3 + m4;
 auto stop2 = high_resolution_clock::now();
 
 auto duration2 = duration_cast<microseconds>(stop2 - start2);
  
 int T1 = duration<double>(duration1).count()*100000;
 int T2 = duration<double>(duration2).count()*100000;
 
 printFunction(polynomial);
 std::cout<<"Horner = "<<h<<" in "<<T1<<"us\n";
 std::cout<<"Math = "<<m<<" in "<<T2<<"us\n"; 
 std::string d = std::to_string(degree);
 std::string t1 = std::to_string(T1);
 std::string t2 = std::to_string(T2);
 fileStream<<d<<" "<<t1<<" "<<t2<<"\n";
 
 m=m1=m2=m3=m4=1;
 polynomial.push_back(0);
 degree++;
}
fileStream.close();
}











