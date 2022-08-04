#include "grade.hpp"
#include <iomanip>
#include <iostream>

// default constructor
Grade::Grade() {
  studentName = "";
  grade = 0;
}

// parameterized constructor which get infoLine as parameter containing grade
// info
Grade::Grade(const std::string &infoLine) {
  std::string line;
  std::istringstream line_stream(infoLine);
  int n = 0;
  std::string temp;

  // parsing
  while (std::getline(line_stream, temp, ',')) {
    if (n == 0) {
      studentName = temp;
    }
    if (n == 1) {
      grade = stof(temp);
    }
    n++;
  }
}

// getter of the student's name
std::string Grade::getName() const { return studentName; }

// getter of the grade
double Grade::getGrade() const { return grade; }
// print the grade info in the format like:
//   Name: Jerry Williams | Grade: 78.0
// should display one decimal place
std::string Grade::infoLine() const {
  std::stringstream format;
  // generating a format and storing in format
  format << "Name: " << studentName << " | Grade: " << std::fixed
         << std::setprecision(1) << grade;

  // return a format in string
  return format.str();
}
