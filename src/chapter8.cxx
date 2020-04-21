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
  // Prompt user for input to initialize our parallel arrays.
  getUserInput(m_names, m_votes);

  // Calculate number of total votes (sum of votes for all candidates).
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_totalVotes += m_votes[iter];
  }

  // Calculate the percentage of total votes received by each candidate and
  // store the value in a separate array.
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_percentOfVotes[iter] =
        100.00 * (m_votes[iter] / static_cast<double>(m_totalVotes));
  }
}

chapter8::Candidate::Candidate(std::string names[], int votes[]) {
  // Initialize Arrays
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_names[iter] = names[iter];
    m_votes[iter] = votes[iter];
  }

  // Calculate number of total votes (sum of votes for all candidates).
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_totalVotes += m_votes[iter];
  }

  // Calculate the percentage of total votes received by each candidate and
  // store the value in a separate array.
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    m_percentOfVotes[iter] = m_votes[iter] / static_cast<double>(m_totalVotes);
  }
}

void chapter8::Candidate::getUserInput(std::string names[], int votes[]) {
  // Prompt User
  std::cout
      << "Enter candidate's last name and the votes received by the candidate."
      << std::endl;

  // Initialize our arrays
  for (int iter = 0; iter < m_numberOfCandidates; iter++) {
    std::cin >> names[iter] >> votes[iter];
  }
}

/**
 * @brief Generates the desired output for the Chapter 8 Programming Assignment.
 */
void chapter8::Candidate::printResult() const {
  // Set local variables.
  int mostVotes = 0; //*< The number of votes received by the winning candidate.
  int index = 0;     //*< Index of array.
  int lcv = sizeof(m_votes) / sizeof(m_votes[0]); //*< Loop Control Variable.

  // Output formatted header
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << "Candidate" << std::setw(4) << " "
            << "Votes Received" << std::setw(4) << " "
            << "\% of Total Votes" << std::endl;

  // Loop which prints the election results based on our user's input.
  for (int i = 0; i < lcv; i++) {

    std::cout << std::setprecision(2);
    std::cout << m_names[i] << std::setw(11) << ' ' << m_votes[i] << ' '
              << std::setw(22) << m_percentOfVotes[i] << '\n';
  }

  // Find our election winner.
  for (int i = 0; i < lcv; i++) {
    if (m_votes[i] > mostVotes) {
      mostVotes = m_votes[i];
      index = i;
    }
  }

  // Output total number of votes received by ALL candidates.
  std::cout << "Total"
            << " " << std::setw(15) << m_totalVotes << std::endl;

  // Output winner of election.
  std::cout << "The winner of the election is " << m_names[index] << "."
            << std::endl;
}
