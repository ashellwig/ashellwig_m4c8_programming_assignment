
/**
 * @file chapter7.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the prototypes required to
 * compute the data requested in the assignment.
 * @date 2020-04-12
 *
 * Assignment: Module 4 Chapter 7 Programming Assignment
 * Description: This file contains the chapter7 namespace for the assigned
 * exercise.
 * Instructor: Jeffrey Hemmes Course: [CSC 160] Introduction to
 * Programming (C++) Date: 02 April 2020
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#ifndef CHAPTER7_HH_INCLUDED
#  define CHAPTER7_HH_INCLUDED

namespace chapter7 {
#  ifndef DEBUG
#    define DEBUG 0
#    ifdef NDEBUG
#      define DEBUG 0
#    endif // !NDEBUG
#  else
#    define DEBUG 1
#  endif // !DEBUG

#  if (DEBUG == 1)
#    include "ashwig_debug.hh"
#  endif // DEBUG

class StudentData {
public:
  StudentData(std::string &userInput) : m_inputString(userInput) {
    getData(m_inputString);
  };

  void getData(std::string &);
  std::string obscureData(std::string);
  void printObscuredStudentData();
  std::string getInputString() const;

private:
  std::string &m_inputString;
};

#endif // !CHAPTER7_HH_INCLUDED
} // namespace chapter7
