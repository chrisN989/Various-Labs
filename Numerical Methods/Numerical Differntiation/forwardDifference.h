#ifndef forwardDifference_h
#define forwardDifference_h

#define E 2.718281828459045235360287471352
#define PI 3.141592653589793238462643383279502884197
#define k 5


/******** power series : first derivative********/
double powerSeriesOne(double a, double b, double c, double d,double h){
 return (1/h)*(a-(b/2)+(c/3)-(d/4));
}

/******** power series : second derivative********/
double powerSeriesTwo(double a, double b, double c, double d,double h){
 return ((1/(h*h))*(a-b+(11*c/12)-(10*d/12)));
}
/******* Taylor formulae: Forward difference *******/
std::vector<double> taylorForward(double (*f)(double),double x0,double h){
 
 std::vector<double> answer;
 std::vector<double> c1,c2,c3,c4,c5;
 
 for(int i = 0; i<k; i++){
  c1.push_back(f(x0+h)-f(x0));
  x0 += h;
  if(i!=0){
   c2.push_back(c1[i]-c1[i-1]);
  }
  if(i>1){
   c3.push_back(c2[i-1]-c2[i-2]);
  }
  if(i>2){
   c4.push_back(c3[i-2]-c3[i-3]);
  }
 }
 c5.push_back(c4[1]-c4[0]);
 
 answer.push_back(powerSeriesOne(c1[0],c2[0],c3[0],c4[0],h));
 answer.push_back(powerSeriesTwo(c2[0],c3[0],c4[0],c5[0],h));
 return answer;
}






#endif
