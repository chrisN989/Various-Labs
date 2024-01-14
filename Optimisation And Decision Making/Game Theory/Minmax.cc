#include <iostream>
#include <iomanip>
#include <vector>

#define m 3
#define n 3

class GameBoard{

private:
 int costMatrix[m][n];

public:
 GameBoard(int M[m][n]);
 void printBoard();
 int* minA();
 int* minB(int A[m][n]);
 
 friend int maxmin(int minA[m], int minIndex[m]);

};

GameBoard::GameBoard(int matrix[m][n]){
 for(int i=0; i<m; i++){
  for(int j=0; j<n; j++){
   costMatrix[i][j] = matrix[i][j];
  }
 }
}

void GameBoard::printBoard(){
 for(int i=0; i<m; i++){
  for(int j=0; j<n; j++){
   std::cout<<std::setw(4)<<costMatrix[i][j]<<" ";
  }
  std::cout<<std::endl;
 }
 std::cout<<std::endl;
}

//Here we identify the minimum in each row of matrix A
int* GameBoard::minA(){
 
 static int minArray[m];
 minArray[0]={costMatrix[0][0]};
 
 int min;
 
 for(int i=0,t=0; i<m; i++, t++){ 
  for(int j=0; j<n; j++){
   if(minArray[t] > costMatrix[i][j]){
    minArray[t] = costMatrix[i][j];    
   }
  }   
 }
 
 //for(auto c : minArray){std::cout<<c;};
 
 return minArray;
}

//Here we identify the minimum in each column of matrix B as well as the index of these minimums
// We then identify the values on matrix A corresponding to the minimums identified 
int* GameBoard::minB(int A[m][n]){

 int t=0;
 int i=0;
 int j=0; 
 
 int minArray[m]={0};
 int minIndexI[m];
 int minIndexJ[m];
 
 minIndexI[0] = 0;
 minIndexJ[0] = 0;
 static int minIndex[m]={A[0][0]};
 minArray[t]=costMatrix[0][j]; 
 
 
 do{

  for(i; i<m; i++){
   
   if(minArray[t] > costMatrix[i][j]){
    
    minIndexI[t] = i;
    minIndexJ[t] = j;
    
    minIndex[t] = A[i][j]; 
   }
  }
  j++;
  t++;
  i=0; 
 }while(j!=n);
 
 return minIndex;
}


int maxmin(int minA[m], int minIndex[m]){
 
 int maxmin;
 int min[m];
 
 maxmin = min[0];
 
 for(int i=0; i<m; i++){
  if(minA[i] > minIndex[i]){
   min[i] = minIndex[i];
  }
  else{
   min[i] = minA[i];
  }
 }
 
 for(int i=0; i<m; i++){
  if(min[i] > maxmin){
   maxmin = min[i];
  }
 }
 return maxmin;
}

int main(){

int a[m][n]={{2,2,0},{4,-5,-8},{1,3,-2}};
int b[m][n]={{-1,4,1},{3,-8,1},{2,1,-7}};

GameBoard A(a),B(b);

A.printBoard();
B.printBoard();

int *p,*q;

p = A.minA();
q = B.minB(a);

std::cout<<maxmin(p,q)<<std::endl;

return 0;
}







