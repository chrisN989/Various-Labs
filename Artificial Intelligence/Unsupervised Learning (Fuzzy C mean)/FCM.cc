#include <iostream>
#include <vector>

#include "fuzzy.h"
#include "readFromFile.h"

double fuzzyClustering(int,double,int,std::vector<std::vector<double>>&);

int main(){
 
 std::vector<std::vector<double>> X = readDataFromFile("exampleSix.txt");

 double e = 10E-10;
   
 fuzzyClustering(3,e,3,X);
  
}

double fuzzyClustering(int m, double e, int C, std::vector<std::vector<double>> &X){
//*****SETUP
 int len = X[0].size();
 int c  = C;
 std::vector<std::vector<double>> U = partitionInit(c,len); 
 //U ={ {0.5,0.7, 0.0, 0.0, 1.0, 0.4, 0.6, 0.2},{0.5, 0.3, 1.0, 1.0, 0.0, 0.6, 0.4, 0.8}};

 //*****1st iteration
 std::vector<std::vector<double>> V = clusterCenters(c,m,X,U);
 
 std::vector<std::vector<double>> D = euclideanNorm(c,X,V);
 
 double FCM_Criterion= fcmCriterion(m,U,D);
 
 double tempCriterion;
  
 //*****nth iteration
 do{
  U = updateU(m,D);
  V = clusterCenters(c,m,X,U);
  D = euclideanNorm(c,X,V);
  tempCriterion = FCM_Criterion;
  FCM_Criterion = fcmCriterion(m,U,D);
 }while(abs(tempCriterion) > FCM_Criterion - e);

 std::cout<<"criterion "<<FCM_Criterion<<"\n";

 return FCM_Criterion;
}
