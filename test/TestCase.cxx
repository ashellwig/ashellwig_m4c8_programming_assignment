#include "../include/catch2/catch.hpp"
#include "../include/chapter8.hh"
#include <string>

using chapter8::Candidate;

SCENARIO("We use arrays to store and calculate the desired values.",
         "[class]") {
  GIVEN("The input ") {
    WHEN("We initialize our class") {
      std::string names[5]; //*< Last names of our candidates.
      int votes[5];         //*< Number of votes received by each candidate.

      Candidate candidates(names,
                           votes); //*< Object which calculates and stores our
                                   //*< candidate's information.

      THEN("No value should be empty") {
        for (int i = 0; i < 5; i++) {
          REQUIRE(names[i] != "");
          REQUIRE(votes[i] != 0);
          REQUIRE(candidates.m_numberOfCandidates == 5);
        }
      }
    }
  }
}
