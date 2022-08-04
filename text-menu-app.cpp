#include "text-menu-app.hpp"
#include <iostream>

void TextMenuApp::run() {
  // this is where we print
  std::cout << "\n1. Print all grades \n";
  std::cout << "2. Update a grade \n";
  std::cout << "3. Save to file \n";
  std::cout << "4. Exit. \n";

  int userSelection = -1;

  std::cout << "Choose an option between(1-4): ";
  std::cin >> userSelection;

  // menu's 1st option
  if (userSelection == 1) {
    gradeBook.print();
  }

  // 2nd option of menu
  if (userSelection == 2) {
    std::cout << "input name of student..";
    std::string user;
    std::cin.ignore();
    getline(std::cin, user); // get full name
    int i = gradeBook.searchStudent(user);

    // if student name matched
    if (i > -1) {

      std::cout << "Enter info in format(student's Name,comma,grade): ";
      std::string form;
      std::cin.ignore(0);
      getline(std::cin, form);

      // update grade through function
      gradeBook.updateGrade(i, form);
    }

    // if student not found then..
    else {
      std::cout << " \nName not found!, Input an existing name, ";
    }
  }

  // 3rd option of menu
  if (userSelection == 3) {

    // going to save on file
    std::string file;
    std::cout << " Please provide a file name..";
    std::cin >> file;
    // function call
    gradeBook.save(file);
  }

  // reapeat if not select to exit
  if (userSelection != 4) {
    run();
  }
}

/// end