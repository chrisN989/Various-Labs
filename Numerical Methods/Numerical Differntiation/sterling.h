#ifndef sterling_h
#define sterling_h

/******** power series : first derivative********/
double sterlingOne(double a, double b, double c, double d,double h){
 return (1/h)*((a+b)/2 - (c+d)/12 );
}

/******** power series : second derivative********/
double sterlingTwo(double a, double b,double h){
 return ((1/(h*h))*(a-(b/12)));
}
/******* Taylor formulae: Forward difference *******/
std::vector<double> sterling(double (*f)(double),double x0,double h){
 
 std::vector<double> answer;
 std::vector<double> c1(5,0),c2,c3,c4,c5;
 
 const double x = x0;
  
 for(int i = 0; i<3; i++){
  if(i==0){
   c1[2] = f(x); 
  }
  if(i==1){
   c1[1] = f(x-i*h);
   c1[3] = f(x+i*h);
  }
  if(i==2){
   c1[0] = f(x-i*h);
   c1[4] = f(x+i*h);
  }
 }
 
 for(int i = 1; i<k; i++){
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

 answer.push_back(sterlingOne(c2[1],c2[2],c4[0],c4[1],h));
 answer.push_back(sterlingTwo(c3[1],c5[0],h));
 return answer;
}


#endif
