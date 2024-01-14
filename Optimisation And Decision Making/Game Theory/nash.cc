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
 int maximin();
 int minimax();



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
//This function is used in the "nashEquilibrium" function to combine both matrix coordinates "i" and "j" corresponding to the nash equilibriums.
// This was done to optimize and faciliate the comparison of duplicate positions 
int concat(int a, int b){

 std::string s1 = std::to_string(a);
 std::string s2 = std::to_string(b);
 
 std::string s = s1 + " " + s2;
 
 int c = std::stoi(s);

 return c;
}

//Here we input the cost matrix A extract its optimal decisions by column. We store the coordinates "i" and "j" corresponding to its best decisions
// int vector "indexA" and we store the optimal value at that position in "valueA" 
std::vector<int> aStrategy(int a[m][n]){

 int *p;
 std::vector<int> indexA;
 std::vector<int> valueA;

 int i=0;
 int j=0; 
 
 
 do{
  p = &a[0][j];
  for(i; i<m; i++){   
   if(*p < a[i][j]){
    p = &a[i][j];
   }
  }
  
  for(int r=0; r<m; r++){
   for(int s=0; s<n; s++){
    if(*p == a[r][s]){
     indexA.push_back(r);
     indexA.push_back(s);
     valueA.push_back(*p);
     
    }
   }
  }
  
  j++;
  i=0; 
 }while(j!=n);
 
 
 indexA.insert(std::end(indexA), std::begin(valueA), std::end(valueA));
   
 return indexA;
} 

//This is similar to the above function except the search is done by row
std::vector<int> bStrategy(int b[m][n]){

 std::vector<int> indexB;
 std::vector<int> valueB; 
 int *p;
 int t=0;
 int J[t]={0};
 
 for(int i=0; i<m; i++){
   p = &b[i][0];
  for(int j=0; j<n+1; j++){
  
   if(*p <= b[i][j]){
    std::cout<<*p<<" "<<std::endl;
    p = &b[i][j]; 
    J[i]=j;      
   }
   
  }
   
  indexB.push_back(i);
  indexB.push_back(J[i]);
  valueB.push_back(*p);
  
 }
 



 
 //for(auto c : valueB){std::cout<<c<<std::endl;};
 //for(auto c : indexB){std::cout<<c<<std::endl;};
 indexB.insert(std::end(indexB), std::begin(valueB), std::end(valueB));
 
 return indexB;
}

// This function accepts the output vectors of the "aStrategy" and "bStrategy" functions. 
// Its job is to extract the single vector containing the matrix coordinates and optimal values into the arrays aPosition and aValue respectively
// The coordinates of the coordinates of the optimal solutions are concatonated into a single integer in arrays Aposition and BPosition
// Finally these two arrays are compared for duplicates. If they are found a nash equilibirum exists at this positoin and is stored in the vector
// "nashEquilibrium"
void nashEquilibrium(std::vector<int> a, std::vector<int> b){
 
 int aPosition[n*2];
 int APosition[n];
 int aValue[n];
 int bPosition[n*2];
 int BPosition[n];
 int bValue[n]; 
 std::vector<int> nashEquilibrium;
 
 for(int i=0; i<n*2; i++){
  aPosition[i] = a[i];
  bPosition[i] = b[i];
 }
  
 for(int i=0; i<n*2; i++){
  a.erase(std::begin(a));
  b.erase(std::begin(b));
 } 
 

 for(int i=0; i<n; i++){
  APosition[i] = concat(aPosition[i] , aPosition[i+1]);
  BPosition[i] = concat(bPosition[i] , bPosition[i+1]);
   
  aValue[i] = a[i];
  bValue[i] = b[i];
  //std::cout<<aValue[i]<<" "<<bValue[i];
 }

 for(int i=0; i<n; i++){
  
  for(int j=0; j<n; j++){
   if(APosition[i] == BPosition[j]){
    
    nashEquilibrium.push_back(APosition[i]); 
    nashEquilibrium.push_back(aValue[i]);
    nashEquilibrium.push_back(bValue[j-1]);
   
   }
  }
 }
 for(auto c : nashEquilibrium){std::cout<<c<<std::endl;};  
 //std::cout<<"The Nash equilibrium is at position i j of "<<nashEquilibrium[0]<<std::endl;
 //std::cout<<"and its value is "<< nashEquilibrium[1] << " " << nashEquilibrium[2]<<std::endl<<std::endl;

}

/*This function will take our "nashEquilibrium" vector and determine which is the better strategy using the following formula

 	A solution i1j1  is better than i2j2 iff  A_i1j1 <= A_21j2 and B_i1j1 <= B_i2j2 
*/
void bestStrategy(std::vector<int> N){
// 10 4 3 00 3 4
 if (N[1] <= N[4] && N[2] <= N[5]){
   std::cout<<"The best strategy is"<<N[1] << " " << N[2];
 } 
 else{
   std::cout<<"The best strategy is"<<N[4] << " " << N[5];
 }

}

int main(){

//int Ba[m][n] = {{12,12,10},{14,-15,-18},{11,13,-12}};
//int Bb[m][n] = {{-1,4,1},{3,-8,1},{2,0,-7}};

//int Ba[m][n]={{2,2,0},{4,-5,-8},{1,3,-2}};
//int Bb[m][n]={{-1,4,1},{3,-8,1},{2,0,7}};

int Ba[m][n]={{5,3,-1},{-3,-5,8},{1,2,2}};
int Bb[m][n]={{-1,4,4},{5,-8,5},{-6,1,1}};

GameBoard g1(Ba),g2(Bb);
//g1.printBoard();
//g2.printBoard();
//aStrategy(Ba);
bStrategy(Bb);
//nashEquilibrium(aStrategy(Ba),bStrategy(Bb));

}
