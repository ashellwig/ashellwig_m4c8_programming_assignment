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
#include <iostream> // std::cin, std::cout
#include <string>   // std::string

void chapter8::Candidate::setCandidateData(std::string names[], int votes[]) {
  int numberOfCandidates = 0;

  std::cout << "Enter candidate's name and the votes received by the candidate."
            << std::endl;

  while (std::cin && numberOfCandidates < 150) {
    numberOfCandidates++;
    std::cin >> names[numberOfCandidates] >> votes[numberOfCandidates];
  }
}

void chapter8::Candidate::printCandidates() {
  std::cout << "Names:" << std::endl;
  for (char &n : *m_candidateNames) {
    std::cout << n;
  }
  std::cout << "Votes:" << std::endl;
  for (int &n : m_candidateVotes) {
    std::cout << n;
  }
}
