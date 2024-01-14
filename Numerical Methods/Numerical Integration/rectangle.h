#ifndef rec_h
#define rec_h

double rectangleMethod(double(*f)(double),double a, double b, int n){

 double answer,xi,h;
 
 h = (b-a)/n;
 
 for(int i = 1; i<=n; i++){
  xi = a + (i-0.5)*h;
  answer += f(xi);
 
 }
 
 answer *= h;
 return answer;

}

#endif



























