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

#ifndef _CHAPTER8_HH_INCLUDED
#  define _CHAPTER8_HH_INCLUDED

#  include "ashwig_exceptions.hh"

namespace chapter8 {

#  ifndef DEBUG
#    define DEBUG 0
#    ifdef NDEBUG
#      define DEBUG 0
#    endif // !NDEBUG
#  else
#    define DEBUG 1
#    ifndef COMMAND_LINE
#      define COMMAND_LINE 1
#    else
#      define COMMAND_LINE 0
#    endif // !COMMAND_LINE
#  endif   // !DEBUG

#  if (DEBUG == 1)
#    include "ashwig_debug.hh"
#  endif // DEBUG

class Candidate {
public:
  static const int m_numberOfCandidates = 5;

  Candidate();

  void setTotalVotes(int[]);
  int calculatePercentOfVotes();
  void getUserInput(std::string[], int[]);
  void printResult() const;

private:
  std::string m_names[m_numberOfCandidates];
  int m_votes[m_numberOfCandidates];
  double m_percentOfVotes[m_numberOfCandidates];
  int m_totalVotes;
}; // class Candidate
// Pop Warning Configuration
} // namespace chapter8
#endif // !CHAPTER8_HH_INCLUDED
