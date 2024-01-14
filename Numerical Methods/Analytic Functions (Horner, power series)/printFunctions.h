#ifndef printFunctions_h
#define printFunctions_h

#include <iomanip>
#include <vector>

/************** printStars function ***************/

void printStars(){
 for(int i = 0; i<50; i++){
  std::cout<<"*";
 }
std::cout<<std::endl;
} 

void print(std::string S){
  printStars();
  std::cout<<S<<std::endl;
}
/*************** printV function *****************/
void printV(std::vector<double>v){
 for(auto c : v){
  std::cout<<c<<" ";
 }
 std::cout<<std::endl;
}

/*************** printPoly function ***************/
void printPoly(std::vector<double> v){
 printStars();
 //std::cout<<"f(x) = ";
 
 for(int i = 0; i<v.size()-2; i++){
  
  if(v[i] > 0){
   if(i==0){
    if(v[0] == 1){
     std::cout<<"x^"<<v.size()-i-1<<" "; 
    }
    else{
     std::cout<<v[i]<<"x^"<<v.size()-i-1<<" "; 
    }
   }
   else if(v[i]==1 && i!=0){
    std::cout<<"+ "<<"x^"<<v.size()-i-1<<" ";
   }
   else{
    std::cout<<"+ "<<v[i]<<"x^"<<v.size()-i-1<<" "; 
   }
  } 
  else if(v[i] < 0){
   v[i] *= -1;
   if(i==0){
    if(v[0] == 1){
     std::cout<<"-x^"<<v.size()-i-1<<" "; 
    }
    else{
     std::cout<<"-"<<v[i]<<"x^"<<v.size()-i-1<<" "; 
    }
   }
   else if(v[i] == 1 && i!=0){
    std::cout<<"- "<<"x^"<<v.size()-i-1<<" "; 
   }
   else{
    std::cout<<"- "<<v[i]<<"x^"<<v.size()-i-1<<" "; 
   }
  }
 }  
 
 if(v[v.size()-2] == 1){
  std::cout<<"+ x"<<std::endl; 
 } 
 else if (v[v.size()-2] == -1){ 
  std::cout<<"- x"<<std::endl; 
 }
 else if (v[v.size()-2] == 0){ 
  std::cout<<""<<std::endl; 
 }
 else if(v[v.size()-2] < 0){
  v[v.size()-2] *= -1;
  std::cout<<"- "<<v[v.size()-2]<<"x"<<" ";
 }
 else{
  std::cout<<"+ "<<v[v.size()-2]<<"x"<<" "; 
 }
 
  if(v[v.size()-1] > 0){
   std::cout<<"+ "<<v[v.size()-1]<<" "; 
  }
  else if(v[v.size()-1] == 0){
   std::cout<<" ";  
  }
  else{
   v[v.size()-1] *= -1;
   std::cout<<"- "<<v[v.size()-1]<<" ";  
  }
 
 std::cout<<std::endl; 
}

/************* printPolyMod function *************/
void printPoly(std::vector<double> v,std::string s){

 std::cout<<s;
 
 for(int i = 0; i<v.size()-2; i++){
  
  if(v[i] > 0){
   if(i==0){
    if(v[0] == 1){
     std::cout<<"x^"<<v.size()-i-1<<" "; 
    }
    else{
     std::cout<<v[i]<<"x^"<<v.size()-i-1<<" "; 
    }
   }
   else if(v[i]==1 && i!=0){
    std::cout<<"+ "<<"x^"<<v.size()-i-1<<" ";
   }
   else{
    std::cout<<"+ "<<v[i]<<"x^"<<v.size()-i-1<<" "; 
   }
  } 
  else if(v[i] < 0){
   v[i] *= -1;
   if(i==0){
    if(v[0] == 1){
     std::cout<<"-x^"<<v.size()-i-1<<" "; 
    }
    else{
     std::cout<<"-"<<v[i]<<"x^"<<v.size()-i-1<<" "; 
    }
   }
   else if(v[i] == 1 && i!=0){
    std::cout<<"- "<<"x^"<<v.size()-i-1<<" "; 
   }
   else{
    std::cout<<"- "<<v[i]<<"x^"<<v.size()-i-1<<" "; 
   }
  }
 }  
 
 if(v[v.size()-2] == 1){
  std::cout<<"+ x"<<std::endl; 
 } 
 else if (v[v.size()-2] == -1){ 
  std::cout<<"- x"<<std::endl; 
 }
 else if (v[v.size()-2] == 0){ 
  std::cout<<""<<std::endl; 
 }
 else if(v[v.size()-2] < 0){
  v[v.size()-2] *= -1;
  std::cout<<"- "<<v[v.size()-2]<<"x"<<" ";
 }
 else{
  std::cout<<"+ "<<v[v.size()-2]<<"x"<<" "; 
 }
 
  if(v[v.size()-1] > 0){
   std::cout<<"+ "<<v[v.size()-1]<<" "; 
  }
  else if(v[v.size()-1] == 0){
   std::cout<<" ";  
  }
  else{
   v[v.size()-1] *= -1;
   std::cout<<"- "<<v[v.size()-1]<<" ";  
  }
 std::cout<<std::endl;
}

/**** taskPrintStatement function *********/
void taskPrintStatement(std::string s, int n,double a,double b,double x0,std::vector<double> x,std::vector<double> y, double function,double w_x0, std::vector<double> w){
 
 double fValue, wValue;
 
 printStars();
 std::cout<<"Interpolated function"<<s<<"\n";
 std::cout<<n<<" nodes between ["<<a<<","<<b<<"]\n";
 std::cout<<"x:";
 for(auto c : x)(std::cout<<std::setw(10)<<c<<" ");
 std::cout<<std::endl;
 std::cout<<"y:";
 for(auto c : y)(std::cout<<std::setw(10)<<c<<" ");
 std::cout<<std::endl<<std::endl;
 std::cout<<"W_"<<n-1<<"(x)= ";
 printPoly(w,"");
 std::cout<<"W_"<<n-1<<"("<<x0<<")= "<<w_x0 <<"\n";
 std::cout<<"|W_"<<n-1<<"("<<x0<<") - "<<"f("<<x0<<")| = "<<abs(function - w_x0)<<"\n";
}





#endif












