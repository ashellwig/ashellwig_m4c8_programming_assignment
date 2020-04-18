/**
 * @file chapter8.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the function implementations used for
 * calculating the vote statistics of data input by the user.
 * @date 2020-04-16
 *
 * Assignment: Module 4 Chapter 8 Programming Assignment.
 * Description: This file contains the function implementations used for
 * calculating the vote statistics of data input by the user.
 * Instructor: Jeffrey Hemmes.
 * Course: [CSC 160] Introduction to Programming (C++).
 * Date: 16 April 2020.
 */

#include "../include/chapter8.hh"
#include <iomanip>  //std::setw, std::setprecision
#include <iostream> // std::cin, std::cout
#include <string>   // std::string

chapter8::Candidate::Candidate() { getUserInput(m_names, m_votes); }

int chapter8::Candidate::getNumberOfCandidates() const {
  return m_numberOfCandidates;
}

void chapter8::Candidate::getUserInput(std::string names[], int votes[]) {
  // Prompt User
  std::cout
      << "Enter candidate's last name and the votes received by the candidate."
      << std::endl;
  std::cin >> names[this->m_numberOfCandidates] >>
      votes[this->m_numberOfCandidates];

  // Initialize our array
  int count = 0;
  while (std::cin && count < m_numberOfCandidates) {
    count++;
    std::cin >> names[count] >> votes[count];
  }
}

void chapter8::Candidate::printResult() const {
  std::cout << std::setprecision(2) << std::setw(5) << std::fixed;
  std::cout << "Candidate"
            << "Votes Received"
            << "\% of Total Votes";

  for (int i = 0; i < m_numberOfCandidates; i++) {
    std::cout << m_names[i] << " " << m_votes[i] << " "
              << "0\%" << '\n';
  }

  std::cout << "Total"
            << " " << 0 << std::endl;
  std::cout << "The winner of the election is " << m_names[2] << std::endl;
}
