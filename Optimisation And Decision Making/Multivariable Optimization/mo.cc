#include <iostream>
#include <math.h>
#include <vector>
#include "golden.h"

class Point{

 public:
  Point(double,double);
  double p[2]; 

};

Point::Point(double a, double b){
 p[0] = a;
 p[1] = b;
}

class Quadratic{ 
 public:
  static double constants[6];//nx,ny,x,y,phi,mu; 
  static void nx(double nx){constants[0] = nx; constants[4] = nx-0.2;}
  static void ny(double ny){constants[1] = ny; constants[5] = ny+0.3;}
  static void x(double x){constants[2] = x;}
  static void y(double y){constants[3] = y;}
  
  friend void Powell(double*);
};

double Quadratic::constants[6];

double f(double a){
 double nx = Quadratic::constants[0];
 double ny = Quadratic::constants[1];
 double x = Quadratic::constants[2];
 double y = Quadratic::constants[3];
 double phi = Quadratic::constants[4];
 double mu = Quadratic::constants[5];
  
 return pow(a*(pow(x,2)+pow(y,2)),2) + 2*a*(phi*x+mu*y) + pow(phi,2) + pow(mu,2);
}

double F(double x){
 return pow(x,2)-0.2*x+0.17;
}

void Powell(Point starting_point){

 Point p0(starting_point.p[0],starting_point.p[1]);
 
 Quadratic::nx(starting_point.p[0]);
 Quadratic::ny(starting_point.p[1]); 
 Quadratic::x(1);
 Quadratic::y(0);

 double p;

 p = golden(f,-1,1) + starting_point.p[0];
 
 Point p1(p,starting_point.p[1]);
 Quadratic::nx(p);
 Quadratic::x(0);
 Quadratic::y(1);
 
 golden(f,-1,1);
 
 Point p2(p, golden(f,-1,1)+starting_point.p[1]);
 
 
 std::cout<<"The minimum of the function using the Powell method is ="<<" ("<<p2.p[0]<<","<<p2.p[1]<<")"<<std::endl<<std::endl;  

 std::cout<<"Starting point p0 = ("<<p0.p[0]<<","<<p0.p[1]<<")"<<std::endl;
 std::cout<<"Moving in the i direction we minimize to p1 ("<<p1.p[0]<<","<<p1.p[1]<<")"<<std::endl;
 std::cout<<"Moving in the j direction we minimize to p2 ("<<p2.p[0]<<","<<p2.p[1]<<")"<<std::endl<<std::endl;  
 std::cout<<"____________________________________________________________________"<<std::endl;
}


int main(){

Point starting_point(0,0);
Powell(starting_point);

Point starting_point1(0.1,0.1);
Powell(starting_point1);

Point starting_point2(0.4,0.3);
Powell(starting_point2);

Point starting_point3(0.7,0.1);
Powell(starting_point3);

}
