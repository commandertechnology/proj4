
#include "gradebook.hpp"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

// default constructor
GradeBook::GradeBook() {
  courseName = "";
  capacity = 0;
  path = "";
  count = 0;
}

// parameterized constructor

GradeBook::GradeBook(const std::string &courseName, int capacity,
                     const std::string &path) {
  count = 0;
  this->courseName = courseName;
  this->capacity = capacity;
  this->path = path;
  loadFile();
}

// function to load file for data
void GradeBook::loadFile() {
  std::ifstream readF;
  readF.open(path, std::ios::in);
  if (!readF)
    std::cout << "Cannot Open file.\n";
  else {

    // reading file
    while (!readF.eof()) {
      std::string line;
      getline(readF, line, '\n');
      if (line.length() > 0) {
//	std::cout << line << std::endl;
        grades[count] = Grade(line);
        count++;
      }
    }
  }
}

// getter of count
int GradeBook::getCount() const { return count; }

// search a student by name function
int GradeBook::searchStudent(const std::string &name) const {
  for (int i = 0; i < count; i++) {
    if (grades[i].getName() == name) {
      return i;
    }
  }
  return -1;
}

// function to update a grade
void GradeBook::updateGrade(int index, const std::string &infoLine) {
  grades[index] = Grade(infoLine);
  std::cout << "\nInformation updated.\n";
}

// function to print records in required format
void GradeBook::print() const {

  for (int i = 0; i < count; i++) {
    std::cout << grades[i].infoLine() << std::endl;
  }
}

// function ill store data on file
void GradeBook::save(const std::string &file) const {
  std::ofstream onfile;
  onfile.open(file, std::ofstream::out);
  if (!onfile) {
    std::cout << "Cannot open file! try again.\n";
  } else {
    std::string line;
    for (int i = 0; i < count; i++) {
      onfile << grades[i].getName() << ", " << grades[i].getGrade()
             << std::endl;
    }

    std::cout << "\n Data Saved on file! \n";
    onfile.close();
  }
}
