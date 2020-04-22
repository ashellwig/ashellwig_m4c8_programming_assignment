#include "../../include/chapter8.hh"
#include <string>

class TestCandidates : public chapter8::Candidate {
public:
  // Constructors
  explicit TestCandidates(std::string);
  int *getVotes();

  // Getters
  std::string *getNames();
}; // class TestCandidates

/**
 * @brief Construct a new Test Candidates:: Test Candidates object
 *
 * @param userInput String containing the last names and number of votes for
 * each candidate.
 */
TestCandidates::TestCandidates(std::string userInput)
    : chapter8::Candidate(userInput) {}

/**
 * @brief Returns a pointer to an array of the candidate's last names.
 *
 * @return std::string* The candidate's last names.
 */
std::string *TestCandidates::getNames() {
  static std::string names[5];

  for (int i = 0; i < m_numberOfCandidates; i++) {
    names[i] = m_names[i];
  }

  return names;
}

/**
 * @brief Returns a pointer to an array of the candidate's number of votes.
 *
 * @return int* The candidate's number of votes.
 */
int *TestCandidates::getVotes() {
  static int votes[5];

  for (int i = 0; i < m_numberOfCandidates; i++) {
    votes[i] = m_votes[i];
  }

  return votes;
}
