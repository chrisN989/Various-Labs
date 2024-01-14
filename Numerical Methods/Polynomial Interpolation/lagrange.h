#ifndef lagrange_h
#define lagrange_h

#include <iostream>
#include <vector>
#include <math.h>
#include "printFunctions.h"

#define PI 3.14159265358979323846264338327950288419716939937510

std::vector<double> polyMath(std::vector<double>);
double getDenominator(std::vector<double>,double);
std::vector<double> LagrangeInterpolation(std::vector<double>);
std::vector<double> chebyshevNodes(int);
std::vector<double> chebyshevNodes(int,double,double);
double evalPoly(std::vector<double> p,double f);
double c (int i, double n, double a, double b){
 return 0.5*(a+b)+0.5*(b-a)*cos((2*i-1)/(2*n)*PI);
}

/********* LagrangeInterpolation Function *****/
std::vector<double> LagrangeInterpolation(std::vector<double> W){
  
 std::vector<double> x,f;
 std::vector<double> w(W.size()/2,0);
 std::vector<double> position,temp,denominator;

//parsing W vector into x and f vectors 
 for(int i = 0; i<W.size(); i++){
  if(i%2==0){x.push_back(W[i]*-1);}
  else{f.push_back(W[i]);}
 }

 for(int i = 0; i<W.size()/2; i++){
  for(int j = 0; j<W.size()/2; j++){
   if(j!= i){
//creating w_i(x) polynomial   
    position.push_back(x[j]);
   }
  }  
  temp = polyMath(position);
  denominator.push_back(getDenominator(position,-x[i]));
  for(int k = 0; k<W.size()/2; k++){
//calculating each degree of the
//w_n(x) polynomial   
   w[k] += f[i]*temp[k]/denominator[i];
  }
  temp.clear();
  position.clear(); 
 }
 return w;
}

/************* getDenominator Function ************/
double getDenominator(std::vector<double> p,double f){
 
 std::vector<double> temp;
 double d; 
 
 temp = polyMath(p);
 if(p.size()==2){
  d += temp[0]*f*f + temp[1]*f + temp[2];
 }
 if(p.size()==3){
  d += temp[0]*f*f*f + temp[1]*f*f + temp[2]*f + temp[3];
 }
 if(p.size()==4){
  d += temp[0]*f*f*f*f + temp[1]*f*f*f + temp[2]*f*f + temp[3]*f + temp[4];
 }
 if(p.size()==5){
  d += temp[0]*f*f*f*f*f+ temp[1]*f*f*f*f + temp[2]*f*f*f + temp[3]*f*f + temp[4]*f + temp[5];
 }
 return d;
}

/************* polyMath Function *****************/
std::vector<double> polyMath(std::vector<double> p){
 std::vector<double> v;
 double a,b,c,d,e;
 
 a = p[0];
 b = p[1];
 c = p[2];
 d = p[3];
 e = p[4];
 
 //P_2(x)
 if(p.size()==2){
  v.push_back(1);
  v.push_back(a+b);
  v.push_back(a*b);
 }
 //P_3(x)
 if(p.size()==3){
  v.push_back(1);
  v.push_back(a+b+c);
  v.push_back(((a+b)*c)+(a*b));
  v.push_back((a*b)*c);
 }
 //P_4(x)
 if(p.size()==4){
  v.push_back(1);
  v.push_back(a+b+c+d);
  v.push_back((c*d)+(a+b)*(c+d)+(a*b));
  v.push_back((a+b)*(c*d)+(a*b)*(c+d));
  v.push_back(a*b*c*d);
 }
 
 //P_5(x)
 if(p.size()==5){
  v.push_back(1);
  v.push_back(a+b+c+d+e);
  v.push_back(a*(b+c+d+e)+b*(c+d+e)+c*(d+e)+d*e);
  v.push_back(a*b*(c+d+e)+c*(d+e)*(a+b)+d*e*(a+c));
  v.push_back(a*b*c*(d+e)+a*d*e*(b+c)+b*c*d*e);
  v.push_back(a*b*c*d*e);
 }
 return v;
}

/************* chebyshevNodes function ***********/
std::vector<double> chebyshevNodes(int n, double a, double b){
 
 std::vector<double> nodes;
 
 for(int i = n; i>=0; i--){
  nodes.push_back(c(i,n,a,b));
 }
 
 return nodes;
}

/************* getDenominator Function ************/
double evalPoly(std::vector<double> temp,double f){
 
 double d; 
 
 if(temp.size()==3){
  d += temp[0]*f*f + temp[1]*f + temp[2];
 }
 if(temp.size()==4){
  d += temp[0]*f*f*f + temp[1]*f*f + temp[2]*f + temp[3];
 }
 if(temp.size()==5){
  d += temp[0]*f*f*f*f + temp[1]*f*f*f + temp[2]*f*f + temp[3]*f + temp[4];
 }
 if(temp.size()==6){
  d += temp[0]*f*f*f*f*f+ temp[1]*f*f*f*f + temp[2]*f*f*f + temp[3]*f*f + temp[4]*f + temp[5];
 }
 
 return d;
}

#endif



