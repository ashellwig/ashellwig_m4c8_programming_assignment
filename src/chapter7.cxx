/**
 * @file chapter7.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the function implementations used for
 * obscuring student data inpout by the user.
 * @date 2020-04-12
 *
 * Assignment: Module 4 Chapter 7 Programming Assignment.
 * Description: This file contains the function implementations used for
 * obscuring student data inpout by the user.
 * Instructor: Jeffrey Hemmes.
 * Course: [CSC 160] Introduction to Programming (C++).
 * Date: 12 April 2020.
 */

#include "../include/chapter7.hh"
#include <iostream>
#include <string>

std::string chapter7::StudentData::getInputString() const {
  return this->m_inputString;
}

void chapter7::StudentData::getData(std::string &studentData) {
  std::cout << "Enter a student's name, social security number, user id, and "
               "password in one line:"
            << std::endl;

  std::getline(std::cin, studentData);
}

std::string chapter7::StudentData::obscureData(std::string inputData) {
  size_t position = 0;

  std::string studentData = inputData;

  while (true) {
    // Find the location of the first space in the data. This should be the
    // separation of the first and last name.
    size_t firstSpace = studentData.find_first_of(' ', position);
    if (firstSpace == std::string::npos)
      break;
    position = studentData.find_first_of(' ', firstSpace + 1) + 1;

    // First and last name will give us 2 spaces before the social security
    // number and the SSN should be 11 characters long.
    studentData.replace(position, 11, "xxx-xx-xxxx");
    position += 10;

    // We then have 2 more spaces until the password
    position = studentData.find_first_of(' ', position + 1);
    position = studentData.find_first_of(' ', position + 1);

    // Replace the characters we find until the end with 'x'
    position += 1;
    while (position < studentData.length()) {
      studentData.replace(position, 1, "x");
      position += 1;
      if (position == std::string::npos)
        break;
    }
  }

  if (position == std::string::npos)
    return studentData;

  return studentData;
}

void chapter7::StudentData::printObscuredStudentData() {
  std::string hiddenData = obscureData(this->m_inputString);

  std::cout << hiddenData << std::endl;
}
