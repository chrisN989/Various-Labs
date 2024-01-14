#ifndef FUZZY_H
#define FUZZY_H

#include <iomanip>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
#include <limits>

//*****print matrix
template <typename T>
void printM(const std::vector<std::vector<T>> &matrix, const std::string& title = "") {
    if (!title.empty()) {
        std::cout << title << ":" << std::endl;
    }

    std::cout << std::setprecision(4) << std::fixed;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << std::setprecision(4) << element << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

//*****print vector
template <typename T>
void printV(const std::vector<T> &v){
 std::cout << std::endl;
 std::cout << std::setprecision(4) << std::fixed;
 for(const auto& element : v){
   std::cout << std::setprecision(8) << element << "  ";
  }
}

//random number with range
int r(int max){
    std::uniform_int_distribution<int> distribution(0, max);

 // Create a random number generator
 std::random_device rd;
 std::mt19937 gen(rd());    
 return distribution(gen);
}

//Initialize partition matrix U_f
//fuzziness !
std::vector<std::vector<double>> partitionInit(int c, int len){

 std::vector<std::vector<double>> U(c ,std::vector<double>(len, 0));
 
 int n;
 int max = 10;
 int error=0;
 for(size_t i = 0; i<U[0].size(); i++){
  for(size_t j = 0; j<U.size()-1; j++){
   n = r(max);
   max -= n;
   U[j][i] = static_cast<double>(n) / 10.0;
   error += n;
  }
 U[U.size()-1][i] = static_cast<double>(10.0-error)/10.0;
 n = 0;
 error=0;
 max = 10; 
}
 //printM(U);
 return U;
};

//*****clusterCenters v

std::vector<std::vector<double>> clusterCenters(int c, double m, const std::vector<std::vector<double>> X, const std::vector<std::vector<double>> U){

 std::vector<std::vector<double>> V(X.size() ,std::vector<double>(c, 0.0));

 double n;
 double d;
 size_t row = U.size();
 size_t col = U[0].size();
 std::vector<double> v;

 for(size_t i = 0; i<X.size(); i++){
  //std::vector<double> u = U[i];
  std::vector<double> x = X[i];
  for(size_t I = 0; I<row; I++){
   for(size_t J = 0; J<col; J++){
    n += pow(U[I][J],m)*x[J];
    d += pow(U[I][J],m);
   }   
   v.push_back(n/d);
   n = 0;
   d=0;
  } 
 }
 
 //printV(v);
 //std::cout<<std::endl;
 for (size_t i = 0; i < X.size(); ++i) {
  for (size_t j = 0; j < c; ++j) {
   
   V[i][j] = v[i * c + j];
   //std::cout<<V[i][j]<<std::endl;
  }
 }
  //printM(V);
 return V;
}

//*****Euclidean norm
//Distance of data points to prototypes
std::vector<std::vector<double>> euclideanNorm (int c, const std::vector<std::vector<double>> X, const std::vector<std::vector<double>> V){

 size_t row = X.size();
 size_t col = X[0].size();
 std::vector<std::vector<double>> D(c, std::vector<double>(col,0));
 double d; 
 
 for(size_t i = 0; i<c; i++){
  for(size_t J = 0; J<col; J++){
   for(size_t I = 0; I<row; I++){
     d+=pow((X[I][J] - V[I][i]),2);
   }   
   D[i][J] = sqrt(d);
   d = 0;
  } 
 }
  
 return D;
 }

double fcmCriterion(int m, const std::vector<std::vector<double>> U, const std::vector<std::vector<double>> D) {
 printM(U,"U");
 double criterion;  
 size_t row = U.size();
 size_t col = U[0].size();
   for(size_t i = 0; i<row; i++){
    for(size_t j = 0; j<col; j++){
     criterion += pow(U[i][j],m) * pow(D[i][j],2);
    }
 }
 return criterion;
}

std::vector<std::vector<double>> updateU (int m,std::vector<std::vector<double>> D){

 size_t row = D.size();
 size_t col = D[0].size();
 std::vector<std::vector<double>> U(row, std::vector<double>(col, 0.0));
 double d;
 
 for (size_t i = 0; i < row; i++) {
  for (size_t k = 0; k < col; k++) {
   U[i][k] = pow(D[i][k],2/(1-m));
   for (size_t j = 0; j < row; j++) {
    d+= pow(D[j][k],2/(1-m));    
   }

   U[i][k] /= d;
   d = 0;
  }
 }   
      
 return U;
}

//**************** to python

// Function to append matrix to a file
void appendToFile(const std::vector<std::vector<double>>& m, const std::string& filename) {  
 std::ofstream file(filename, std::ios::app);// Use app flag to append existing file
 if (file.is_open()) {
  for (const auto& row : m) {
   for (int point : row) {
    file << point << " ";
   }
   file << std::endl;
  }
  file.close();
 } 
 else {
  std::cerr << "Error opening file: " << filename << std::endl;
 }
}

void makeColZero(int col, std::vector<std::vector<double>> &tempProb) {
 for (size_t i = 0; i < tempProb.size(); ++i) {
  tempProb[i][col] = 0.0;
 }
}

std::vector<std::vector<double>> normalizeU(std::vector<std::vector<double>> U){

 size_t row = U.size();
 size_t col = U[0].size();
 std::vector<std::vector<double>> N(row, std::vector<double>(col, 0.0));
 double d=0;
 int I=0;
 for (size_t j = 0; j < col; j++) {
  for (size_t i = 0; i < row; i++) {
   if(U[i][j] > d){
    d = U[i][j];
    I = i;
   }
  }
  N[I][j] = 1;
  I = 0;
 }

 return N;
}


#endif
