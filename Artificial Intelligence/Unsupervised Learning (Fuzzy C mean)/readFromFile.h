#ifndef READFROMFILE_H
#define READFROMFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::vector<double>> readDataFromFile(const std::string& filename) {
 std::vector<std::vector<double>> X;

 // Open the text file
 std::ifstream inputFile(filename);

 // Check if the file is open
 if (!inputFile.is_open()){
  std::cerr << "Error opening the file." << std::endl;
  return X;
 }

 // Read each line from the file
 std::string line;
 while(std::getline(inputFile, line)){
  std::vector<double> row;
  std::istringstream iss(line);

  // Read each comma-separated value from the line
  double value;
  char comma;

  while (iss >> value) {
   row.push_back(value);
   // Check for a comma and ignore it
   if(iss >> comma && comma != ','){
    std::cerr << "Error: Expected comma." << std::endl;
    return X;
   }
  }

  // Add the row to the vector
  X.push_back(row);
 }

 // Close the file
 inputFile.close();

 return X;
}


#endif
