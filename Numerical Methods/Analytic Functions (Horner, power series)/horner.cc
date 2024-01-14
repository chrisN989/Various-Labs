#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>      // std::setprecision

#include "printFunctions.h"

#define STEP 0.0001
#define START 0.01
#define RANGE_GUESS 2.1208

/******** function prototypes ******/
double horner (std::vector<double>,double);

bool hornerVerity (std::vector<double>,double);
bool hornerVerityMod (std::vector<double>,double);
std::vector<double> root(std::vector<double>);

std::vector<double> modRoot(std::vector<double>);

/** auxillary function prototypes **/
void print(std::vector<double>);
void printPoly(std::vector<double>);
void message(std::string s){std::cout<<s<<std::endl;}
void printStars();

void line(){std::cout<<std::endl;}

/***************** main function ******************/
int main(){

//std::vector<double> polynomial={1,3,-4,5,-1};
//message("All Positive Roots Polynomial");

/* EMAIL EXAMPLE 1 */
//std::vector<double> polynomial={1,2,-355,700,12000};

/* EMAIL EXAMPLE 2 */
//std::vector<double> polynomial={1,-23,-405,9575,-5500,-300000};

/* All Positive Roots */
std::vector<double> polynomial={1,0,-3,-4,5,-1};


printPoly(polynomial);
root(polynomial);

line();
}

/*************** horner function ******************/
double horner (std::vector<double> v, double x){
 
 std::cout<<"\nHorner Scheme (x = "<<x<<")\n";
 double p;
 p = v[0];
 for(int  i = 1; i < v.size(); i++){ 
  p = p * x + v[i];
 }
 
 line();
 return p;

}
/************ hornerVerity function **************/
bool hornerVerity (std::vector<double> v,double x){
 
 bool verity = true;
 double p;
 p = v[0];

 for(int  i = 1; i < v.size(); i++){
  p = p * x + v[i];
  if(p < 0){
   verity = false;
   return verity;
  }
 }
 
 return verity;
 
}

/************** root function *********************/
std::vector<double> root (std::vector<double> v){

 std::vector<double> range = {-0.6,12};
 
 double p;
 
 p = range[1];
/*********** beta ******************/
 while(hornerVerity(v,p)==false){
  p += STEP;
 }
 range[1] = p;//-STEP;

/*********** alpha ******************/ 

/** modify f(x): Even degree **  
 for(int i = 0; i<v.size();i++){  
  if(i != v.size() - 1 && i%2==1){
   v[i] *= -1; 
  }
 }
 */ 
 for(int i = 0; i<v.size();i++){  
  if(i != v.size() - 1 && i%2==0){
   v[i] *= -1; 
  }
  v[i] *= -1;
 }
 
 printPoly(v);
/**** find alpha ****/   
 p = range[0];
 while(hornerVerity(v,p)==false){
  p += STEP;
 }
 
 range[0] = p * -1;
 
 message("\nThe range of the roots are ");
 std::cout<<"["<<range[0]<<"] "<<"["<<range[1]<<"] "<<std::endl<<std::endl;
 printStars();
 return range;

}





