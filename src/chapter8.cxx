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

chapter8::Candidate::Candidate() {
  getUserInput(m_names, m_votes);
  setTotalVotes(m_votes);
}

void chapter8::Candidate::setTotalVotes(int votes[]) {
  int sum = 0;

  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    sum += votes[iter];
  }

  m_totalVotes = sum;
}

void chapter8::Candidate::getUserInput(std::string names[], int votes[]) {
  // Prompt User
  std::cout
      << "Enter candidate's last name and the votes received by the candidate."
      << std::endl;

  // Initialize our array
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    std::cin >> names[iter] >> votes[iter];
  }
}

void chapter8::Candidate::printResult() const {
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << "Candidate"
            << " "
            << "Votes Received"
            << " "
            << "\% of Total Votes" << std::endl;

  for (int name = 0; name < m_numberOfCandidates; name++) {
    for (int votes = 0; votes < m_numberOfCandidates; votes++) {
      double percentOfVotes = m_votes[votes] / m_totalVotes;

      std::cout << std::fixed << std::setprecision(2) << std::setw(3);
      std::cout << m_names[name] << " " << m_votes[votes] << " "
                << percentOfVotes << "%" << '\n';
    }
  }

  std::cout << "Total"
            << " " << m_totalVotes << std::endl;
  std::cout << "The winner of the election is " << m_names[2] << std::endl;
}
