#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include "grade.hpp"
#include <string>

class GradeBook{
 std::string courseName;
 std::string path;
int capacity;
int count;
Grade grades[40];
 public:
 //default constructor
 GradeBook();

  //parameterized constructor which is //input for data file 
GradeBook(const std::string& courseName , int capacity, const std::string& path );

//destructor to release memory of array
//~GradeBook();s
 
//getter of count
int getCount() const;

//function to search student by name
int searchStudent(const std::string &name) const;

//functtion to load file
void loadFile();

//function to update grade at the index given
 void updateGrade (int index, const std::string& infoLine); 
  
//function to save data on file
 void save(const std::string& file) const;

//function to print the recorde
void print() const;



};

#endif //GRADEBOOK_HPP