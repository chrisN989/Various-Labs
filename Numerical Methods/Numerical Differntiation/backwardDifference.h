#ifndef backwardDifference_h
#define backwardDifference_h

/******** power series : first derivative********/
double powerSeriesOneBackward(double a, double b, double c, double d,double h){
 return (1/h)*(a+(b/2)+(c/3)+(d/4));
}

/******** power series : second derivative********/
double powerSeriesTwoBackward(double a, double b, double c, double d,double h){
 return 1/(h*h)*(a+b+(11*c)/12+(10*d/12));
}
/******* Taylor formulae: Backward difference *******/
std::vector<double> taylorBackward(double (*f)(double),double x0,double h){
 
 std::vector<double> answer;
 std::vector<double> c1,c2,c3,c4,c5;
 
 const double x = x0;
 
 for(int i = k-1, j=0; i>=0; i--, j++){
  x0 = x - i*h;
  c1.push_back(f(x0)-f(x0-h));
  if(j!=0){
   c2.push_back(c1[j]-c1[j-1]);
  }
  if(j>1){
   c3.push_back(c2[j-1]-c2[j-2]);
  }
  if(j>2){
   c4.push_back(c3[j-2]-c3[j-3]);  
  }  
 }
 c5.push_back(c4[1]-c4[0]);
   
 answer.push_back(powerSeriesOneBackward(c1[k-1],c2[k-2],c3[k-3],c4[k-4],h));
 answer.push_back(powerSeriesTwoBackward(c2[k-2],c3[k-3],c4[k-4],c5[0],h));

 return answer;
}

#endif
