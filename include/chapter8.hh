/**
 * @file chapter8.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the prototypes used for
 * calculating the vote statistics of data input by the user.
 * @date 2020-04-16
 *
 * Assignment: Module 4 Chapter 8 Programming Assignment.
 * Description: This file contains the prototypes used for
 * calculating the vote statistics of data input by the user.
 * Instructor: Jeffrey Hemmes.
 * Course: [CSC 160] Introduction to Programming (C++).
 * Date: 16 April 2020.
 */

#include <string>

#ifndef CHAPTER8_HH_INCLUDED
#  define CHAPTER8_HH_INCLUDED

#  include "ashwig_exceptions.hh"

namespace chapter8 {
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

class Candidate {
public:
  Candidate();
  void setNumberOfCandidates(int);
  int getNumberOfCandidates() const;
  void getUserInput(std::string[], int[]);
  void printResult() const;
  static const int m_numberOfCandidates = 6;

private:
  std::string m_names[m_numberOfCandidates] = {
      "Candidate0", "Candidate1", "Candidate2", "Candidate3", "Candidate4"};
  int m_votes[m_numberOfCandidates] = {0, 1, 2, 3, 4, 5};
}; // class Candidate

#endif // !CHAPTER8_HH_INCLUDED
} // namespace chapter8
