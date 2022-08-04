#ifndef GRADE_HPP
#define GRADE_HPP

#include <string>

class Grade{
 std::string studentName;
 double grade;
 public:
// default constructor
   Grade();

//parameterized constructor which get infoLine as parameter containing grade info
   Grade(const std::string& infoLine);

// return current studentName
   std::string getName() const;

//return current grade
   double getGrade() const;

// infoLine method to genrate a string representing the content of current object
   std::string infoLine() const;
   
}; 

#endif //GRADE_HPP 