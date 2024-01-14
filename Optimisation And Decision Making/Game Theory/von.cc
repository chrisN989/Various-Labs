#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#define m 3
#define n 3
class GameBoard{

private:
 int costMatrix[m][n];

public:
 GameBoard(int M[m][n]);
 void printBoard();
 int vonStackelberg(int,int);


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


void vonStackelberg(int a[m][n], int b[m][n]){

 

 std::vector<int> indexAi;
 std::vector<int> indexAj;
 std::vector<int> valueA;
 int *p; 
 int Ja[m]={0};
 
 std::vector<int> indexBi;
 std::vector<int> indexBj;
 std::vector<int> valueB; 
 int *r;
 int Jb[m]={0};
 
 for(int i=0; i<m; i++){
  p = &a[i][0];
  for(int j=0; j<n; j++){
   if(*p <= a[i][j]){
    p = &a[i][j];
    Ja[i]=j;
   } 
  
  }
   indexAi.push_back(i);
   indexAj.push_back(Ja[i]);
   valueA.push_back(*p);
 }
  
  
  
 for(int i=0; i<m; i++){
  p = &b[i][0];
  for(int j=0; j<n; j++){
   if(*p <= b[i][j] ){
    p = &b[i][j];
    Jb[i]=j;
   }   
  }
   indexBi.push_back(i);
   indexBj.push_back(Jb[i]);
   valueB.push_back(*p);
 }
 
 
 for(int i=0; i<n; i++){  
  if(indexAi[i] == indexBi[i] && indexAj[i] == indexBj[i]){
    std::cout<<"There is a von Stackelberd equilibrium at "<<valueA[i]<<" "<<valueB[i];
  }
 } 
}

int main(){

//int Ba[m][n] = {{12,12,10},{14,-15,-18},{11,13,-12}};
//int Bb[m][n] = {{-1,4,1},{3,-8,1},{2,0,-7}};

int Ba[m][n]={{5,3,-1},{-3,-5,8},{1,2,-2}};
int Bb[m][n]={{-1,4,4},{5,-8,5},{-6,1,1}};

GameBoard g1(Ba),g2(Bb);
//g1.printBoard();
//g2.printBoard();

vonStackelberg(Ba,Bb);

}
