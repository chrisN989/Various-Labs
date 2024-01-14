//Ant Colony Optimization algorithm to solve the Traveling Salesman Problem 

#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <limits>

#include "formicarium.h"

void ants(const std::vector<Point> &, int,int,int,int);

int main(){
//auto v =  cityVector<Point>(Point{0,0},Point{4,1},Point{3,3},Point{1,3},Point{5,5});
//auto v =  cityVector<Point>("choices.txt",Point{0,0},Point{2,1},Point{1,3},Point{4,4});
//auto v = cityVector<Point>(Point{0, 0}, Point{2, 1}, Point{1, 3}, Point{4, 4},Point{5, 2}, Point{7, 8}, Point{9, 6}, Point{3, 5},Point{10, 12}, Point{11, 9});
//auto v = cityVector<Point>(Point{0,0}, Point{2,1}, Point{1,3}, Point{4,4},Point{5,2},Point{7,8},Point{9,6},Point{3,5},Point{10,12}, Point{11,9});
auto v = cityVector<Point>(Point{3,1},Point{2,4},Point{12,2},Point{7,4.5},Point{9,9},Point{3,1.5},Point{16,11},Point{11,8},Point{9,10},Point{2,7});


auto s = "choices.txt";
mapCity(v,s);

//city , alpha, beta, rho, iteration
ants(v,1,5,0.5,200);
}

void ants(const std::vector<Point> &v,int alpha, int beta, int rho, int iteration){
 int len = v.size();
 std::vector<std::vector<double>> distance_M(len ,std::vector<double>(len, 0.0));
 std::vector<std::vector<double>> pheromones_M(len, std::vector<double>(len, 0));
 std::vector<std::vector<double>> probability_M(len, std::vector<double>(len, 1.0));
/********************* SETUP ***********************/
 //Computing distance between each point
 // Building distance matrix distance_M
 for(int i = 0; i<len; ++i){
  for(int j = 0; j<len; ++j){
   distance_M[i][j]=distance(v[i],v[j]);
  } 
 }
  
/************** 1st ITERATION **********************/
 auto choice_M = probability(probability_M);
 auto deltaT = dT(choice_M,distance_M);

 pheromones_M = pheromoneMatrix(pheromones_M,choice_M,deltaT); 
 probability_M = probabilityMatrix(distance_M,pheromones_M,alpha,beta);
 
 double bestAntEver = R(choice_M,distance_M);
/*************** nth ITERATION ******************/
 int it = iteration;
 do{
  choice_M = probability(probability_M);
  deltaT = dT(choice_M,distance_M);
  
  if(it != iteration){
     pheromones_M = pheromoneMatrix(pheromones_M,choice_M,deltaT);
     pheromones_M =  pheromoneEvaporation( pheromones_M,rho);
  }
  else{
   pheromones_M = pheromoneMatrix(pheromones_M,choice_M,deltaT);
  }
  probability_M = probabilityMatrix(distance_M,pheromones_M,alpha,beta);
  iteration--;
  
  if(bestAntEver > R(choice_M,distance_M) ){
   bestAntEver = R(choice_M,distance_M);
  }
 }while(iteration>0);
 
 //printM(choice_M);
 result(choice_M,distance_M,bestAntEver);

}
 


//46.3
 
 
 
 
  
