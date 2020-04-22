#include "../include/catch2/catch.hpp"
#include "./include/test_chapter8.hh"
#include <string>

SCENARIO("We use arrays to store and calculate the desired values.",
         "[class]") {
  GIVEN("The input as shown for our desired output example.") {
    std::string inputExample = "Smith 12345\nJones 4567\nAdams "
                               "555\nWashington 888888\nJefferson 456789";

    WHEN("We initialize our class") {
      TestCandidates candidates(inputExample);

      THEN("Arrays should match input") {
        std::string *names;
        names = candidates.getNames();
        int *votes;
        votes = candidates.getVotes();

        std::string targetNames[] = {"Smith", "Jones", "Adams", "Washington",
                                     "Jefferson"};
        int targetVotes[] = {12345, 4567, 555, 888888, 456789};

        for (int i = 0; i < 5; i++) {
          REQUIRE(names[i] == targetNames[i]);
          REQUIRE(votes[i] == targetVotes[i]);
        }
      }

      THEN("The candidate with the most votes should be Washington") {
        REQUIRE(candidates.getWinnerIndex() == 3);
      }
    }
  }
}
