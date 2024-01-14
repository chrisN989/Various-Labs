#ifndef task_h
#define task_h


unsigned int nChooseI(unsigned int n, unsigned int i){
 if(i ==0 || i == n){
  return 1;
 }
 else{
  return nChooseI(n-1,i-1) + nChooseI(n-1,i);
 }
}

double taylorForwardN(double (*f)(double),double x0, double h, int n, int i){
 return pow(-1,(n-i))*nChooseI(n,i)*f(x0+i*h);
}


double forwardDifferenceFirst(double (*f)(double),double x0, double h, const int n){
 
 double derivative = 0;
 std::vector<double> v;
 
 int N = 1;
 
 //Build delta operators from N to n
 do{
  for(int i = 0; i<=N; i++){
   derivative += taylorForwardN(*f,x0,h,N,i);
  }
 
  v.push_back(derivative);
  derivative=0; 
  N++;
 }while(N<=n);
 
 //multiply coefficient 
 for(int i = 0, j=1; i<=n; i++,j++){
  
  if(i%2==0){
   derivative += v[i]/j;
  }
  else{
   derivative -= v[i]/j;
  }

 }

 return derivative/h ;
}

//computed , starts for delta 2 ends at delta 14
std::vector<double> coefficient = {1,-1,11.0/12.0,-5.0/6.0,137.0/180.0,-7.0/10.0,363.0/560.0,-223.0/630.0,153.0/700.0,-29.0/210.0,107.0/1260.0,-1.0/42.0,1.0/49.0};

double forwardDifferenceSecond(double (*f)(double),double x0, double h, const int n){
 
 double derivative = 0;
 std::vector<double> v;
 
 int N = 2;
 
 //Build delta operators from N to n
 do{
 
  for(int i = 0; i<=N; i++){
   derivative += taylorForwardN(*f,x0,h,N,i);
  }
 
  v.push_back(derivative);
  derivative=0; 
  N++;
  
 }while(N<=n);
 
 for(int i = 0; i<n-1;i++){  
   derivative += v[i]*coefficient[i];
 }

 return derivative/(h*h) ;
}







#endif
