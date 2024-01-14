
#define N 10e-8

#include <iostream>
#include <math.h>

#include <sys/time.h>
#include <iomanip>

long getTimeSec(){
 struct timeval start;
 gettimeofday(&start,NULL);
 return start.tv_sec;
      //start.tv_sec*1000000 + start.tv_usec;
      
}


// a,b range , n step size
double gradientMethod(double (*f)(double) , double (*fPrime) (double), double a, double b , double n){

double epsilon = -n*fPrime(a);
double x = a;
int i = 0;
std::cout<<"epsilon= "<<epsilon<<"\n";
do{
 
 if ( f(x+epsilon) <= f(a) + fPrime(a) * (x+epsilon) ){
  x += epsilon;
 
 }
 else{
  x -= epsilon;
 }

std::cout<<x<<"~~\n";
i++;
}
while(f(x+epsilon)<=f(x));
return x;
};


double f(double x){
return  x / (1.4 - sin(2*x)) ;
};

double fPrime(double x){
return (1.4-sin(2*x)+2*x*cos(2*x))/pow((1.4 - sin(2*x)),2);
};




int main(){

long startSec = getTimeSec();



std::cout<<std::setprecision(12)<<gradientMethod(*f,*fPrime,-1.0,2.0,N)<<"\n";



long endSec = getTimeSec();
std::cout<< abs(startSec - endSec) << " seconds\n" ;




}
