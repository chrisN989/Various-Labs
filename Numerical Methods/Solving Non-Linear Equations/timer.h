#ifndef timer_h
#define timer_h

#include <vector>
#include <chrono>

typedef long double (*rootApproximation)(long double(*)(long double),double,double,long double);
typedef long double (*Bernoulli)(long double(*)(long double x),std::vector<double>, double);

double timer(rootApproximation method,long double(*f)(long double x),double a, double b, long double e){
  
  auto start = std::chrono::high_resolution_clock::now();
  method(*f,a,b,e);
  auto end = std::chrono::high_resolution_clock::now();
  
  return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

double timer(Bernoulli method,long double(*f)(long double x),std::vector<double> c, double e){
  auto start = std::chrono::high_resolution_clock::now();
  method(*f,c,e);
  auto end = std::chrono::high_resolution_clock::now();
  
  return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}
#endif
