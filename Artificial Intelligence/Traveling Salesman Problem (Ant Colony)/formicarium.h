#ifndef FORMICARIUM_H
#define  FORMICARIUM_H

#include <iomanip>
#include <vector>
#include <cmath>
#include <random>
#include <set>
#include <algorithm>
#include <limits>
#include <fstream>

typedef struct{
 double x,y;
}Point;

/*
 static_cast<T>: C++ cast operator. Performs a compile-time type conversion. It converts the given argument to the specified type T.
    
 (args)...: Fold expression that expands the expression for each element in the parameter pack args.
*/
//***** City Vector 
template<typename T, typename... Args>
std::vector<T> cityVector( Args... args) {
  return {static_cast<T>(args)...};
}

// Function to convert Point vector to a single row of ints
template<typename T>
void mapCity(const std::vector<T>& points, const std::string& filename) {
 std::vector<int> row;
 for (const auto& point : points) {
  row.push_back(static_cast<int>(point.x));
  row.push_back(static_cast<int>(point.y));
 }
 std::ofstream file(filename,  std::ios::trunc);
 if (file.is_open()) {
  for (const auto& value : row) {
   file << value << " ";
  }
  file << "\n";
  file.close();
  } else {
   std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

double distance(Point p1, Point p2){
 return sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2));
}

//*****print matrix
template <typename T>
void printM(const std::vector<std::vector<T>> &matrix){
 std::cout << std::endl;
 std::cout << std::setprecision(4) << std::fixed;
 for(const auto& row : matrix){
  for(const auto& element : row){
   std::cout << std::setprecision(8) << element << "  ";
  }
  std::cout << std::endl;
 }
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

void makeColZero(int col, std::vector<std::vector<double>> &tempProb) {
 for (size_t i = 0; i < tempProb.size(); ++i) {
  tempProb[i][col] = 0.0;
 }
}

void move(int pos, std::vector<std::vector<double>> probability_M, std::vector<std::vector<int>> &choices ){

 size_t len = probability_M.size(); 
 auto temp = probability_M;
 int start = choices[pos][0];

 std::random_device rd;
 std::mt19937 gen(rd());
 
 makeColZero(start,temp);
 for(size_t i = 1; i<len; i++){
  std::discrete_distribution<> distribution(temp[start].begin(), temp[start].end());
  start = distribution(gen);
  makeColZero(start,temp);
  choices[pos][i] = start;
 }
}

std::vector<std::vector<int>> probability(std::vector<std::vector<double>> probability_M){
 size_t len = probability_M.size();
 std::vector<std::vector<int>> choices(len, std::vector<int>(len,0));
 
 //**chose random start cities
 //Create a discrete distribution based on probabilities
 std::uniform_int_distribution<int> distribution(0,len-1);

 // Create a random number generator
 std::random_device rd;
 std::mt19937 gen(rd());    
 
 for(size_t i = 0; i<len; i++){
  choices[i][0] = distribution(gen);
 }
 
//**move city to city
 
 for(size_t i = 0; i<len; i++){
  move(i, probability_M, choices);
 }

return choices;
}

//*****deltaT vector
std::vector<double> dT (std::vector<std::vector<int>> &choices,std::vector<std::vector<double>> distance){ 
 std::vector<double> deltaT;
 size_t len = choices.size();
 for(size_t i = 0; i<len; i++){
  for(size_t j = 0; j<len; j++){
   if(j==0){
    deltaT.push_back(distance[i][choices[i][j]]);
   }
   else{
    deltaT[i] += distance[choices[i][j-1]][choices[i][j]];
   }
  }
 }
 
 // Compute the reciprocal of every element using std::transform and a lambda function
std::transform(deltaT.begin(), deltaT.end(), deltaT.begin(), [](double x) -> double {
  if (x == 0) { return 0;}
  else { return 1 / x;}
 });
 return deltaT;
}

//*****generate the pheromone matrix
std::vector<std::vector<double>> pheromoneMatrix(std::vector<std::vector<double>> phero, std::vector<std::vector<int>> choices,std::vector<double> deltaT){  
 size_t len = choices.size(); 
 std::vector<std::vector<double>> pM(len, std::vector<double>(len,0)); 
 pM = phero;
 // last element travels to first
 for(size_t i = 0; i<len; i++){
  for(size_t j = 0; j<len; j++){
   if(j==0){
    pM[choices[i][len-1]][choices[i][j]] += deltaT[i];
   }
   else{
    pM[choices[i][j-1]][choices[i][j]]+=deltaT[i];
   }
  }
 } 

 //add upper to lower triangle of matrix!
 for(size_t i = 0; i<len; i++){
  for(size_t j = i+1;j<len; j++){
   pM[i][j] += pM[j][i];
   pM[j][i] = pM[i][j];
  }
 }

 return pM;
}

//*****probability matrix
std::vector<std::vector<double>> probabilityMatrix(std::vector<std::vector<double>> distanceMatrix,std::vector<std::vector<double>> pheromoneMatrix, double a, double b){ 
 size_t len = distanceMatrix.size();
 std::vector<double> sigA(len,0),sigP(len,0);
 std::vector<std::vector<double>> probabilityMatrix(len, std::vector<double>(len,0)); 
 std::vector<std::vector<double>> decisionTable(len, std::vector<double>(len,0));  
 
 //computing denominator of a_ij
 for(size_t i = 0; i<len; i++){
  for(size_t j = 0; j<len; j++){
   if(distanceMatrix[i][j] != 0){
    sigA[i] += pow(pheromoneMatrix[i][j],a) * pow(1/distanceMatrix[i][j],b);
   }
  } 
 }
 
 //computing decision matrix a_ij^kstd::vector<double>> phero
 for(size_t i = 0; i<len; i++){
 for(size_t j = 0; j<len; j++){
  if(pheromoneMatrix[i][j] != 0){
   decisionTable[i][j] = pow(pheromoneMatrix[i][j],a) * pow(1/distanceMatrix[i][j],b) / sigA[i];
  }
 }
}
     
 //computing denominator of p_ij
for(size_t i = 0; i<len; i++){
 for(size_t j = 0; j<len; j++){
  sigP[i] += decisionTable[i][j];
 }
}
 
 //computing decision matrix p_ij^k
for(size_t i = 0; i<len; i++){
 for(size_t j = 0; j<len; j++){
  if(decisionTable[i][j] != 0){
   probabilityMatrix[i][j] = decisionTable[i][j]/sigP[i];
  }
 }
}
 
 return probabilityMatrix; 
}

/*********update the pheromone matrix ************/
std::vector<std::vector<double>> pheromoneEvaporation(std::vector<std::vector<double>> pheromoneMatrix,  double rho){
 size_t len = pheromoneMatrix.size();
 std::vector<std::vector<double>> pM(len, std::vector<double>(len,0)); 
 pM = pheromoneMatrix;
 
 for(size_t i = 0; i<len; i++){
  for(size_t j = 0; j<len; j++){
   pM[i][j] = (1-rho)*pheromoneMatrix[i][j] + pheromoneMatrix[i][j] ;
  }
 } 
 return pM;
} 

// Function to append choices to a file
void appendToFile(const std::vector<std::vector<int>>& choices, const std::string& filename) {  
 std::ofstream file(filename, std::ios::app);// Use app flag to append existing file
 if (file.is_open()) {
  for (const auto& row : choices) {
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

// Function to append choices to a file
void appendToFile2(int choice, const std::string& filename) {
 std::ofstream file(filename, std::ios::app);// Use app flag to append existing file
 if (file.is_open()) {
  file << choice << " ";
  file.close();
 }
 else {
  std::cerr << "Error opening file: " << filename << std::endl;
 }
}

/********* calculate the shorest path **********
***********and display the shortest path ******/
void result(std::vector<std::vector<int>> choices, std::vector<std::vector<double>> distance,double bestAntEver) {
 size_t len = choices.size(); 
 size_t index = 0;
 double tD = std::numeric_limits<double>::infinity(); // Initialize with positive infinity
 double temp_tD;
 std::vector<double> D;
 
 for (size_t i = 0; i < len; i++) {
  temp_tD = 0; 
  for (size_t j = 0; j < len - 1; j++) {
   temp_tD += distance[choices[i][j]][choices[i][j + 1]];
  }
  temp_tD += distance[choices[i][len - 1]][choices[i][0]]; // Loop back to the starting point
  if (tD > temp_tD) {
   tD = temp_tD;
   index = i;
  }
  D.push_back(temp_tD);
 }

 std::cout << "The shortest path is: ";
 for (size_t i = 0; i < len; i++) {
  std::cout << choices[index][i] << " ";
  appendToFile2(choices[index][i],"choices.txt");
 }
 std::cout << std::endl;
  
  std::cout << "Whose distance is " << bestAntEver << std::endl;
  std::cout << std::endl;
 //std::cout<<"All distances :";
 //printV(D);
}


double R(std::vector<std::vector<int>> choices, std::vector<std::vector<double>> distance) {
 size_t len = choices.size(); 
 size_t index = 0;
 double tD = std::numeric_limits<double>::infinity(); // Initialize with positive infinity
 double temp_tD;
 std::vector<double> D;
 
 for (size_t i = 0; i < len; i++) {
  temp_tD = 0; 
  for (size_t j = 0; j < len - 1; j++) {
   temp_tD += distance[choices[i][j]][choices[i][j + 1]];
  }
  temp_tD += distance[choices[i][len-1]][choices[i][0]]; // Loop back to the starting point
  if (tD > temp_tD) {
   tD = temp_tD;
   index = i;
  }
  D.push_back(temp_tD);
 }
 
 return tD;
} 
#endif

