/**
 * @file main.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the main function to run the program.
 * @date 2020-04-16
 *
 * Assignment: Module 4 Chapter 8 Programming Assignment
 * Description: This file contains the main function to run the program.
 * Instructor: Jeffrey Hemmes
 * Course:
 *   [CSC 160] Introduction to Programming (C++)
 * Date: 16 April 2020
 */

#include "../include/chapter8.hh"          // TBD
#include "../include/cxxopts/cxxopts.hpp"  // cxxopts::Options
#include "../include/general_functions.hh" // pauseprompt
#include <iostream>                        // std::cout

/**
 * @brief Performs the steps to execute the main application.
 */
int main(int argc, char **argv) {
  // Command Line Options
  cxxopts::Options options("ashellwig_m4c8_programming_assignment",
                           "Programming assignment solution for CSC 160 C++ "
                           "Course at CCCOnline in SP 2020");
  options.add_options()("n,number-of-candidates", "Param numberOfCandidates",
                        cxxopts::value<int>()->default_value("6"))(
      "h,help", "Print usage");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  // Generate our candidate data
  chapter8::Candidate candidateList;
  candidateList.printResult();

  // "Press enter to continue..."
  general_functions::pauseprompt();

  // Return with exit code 0 if all goes well
  return 0;
}

// vim: set et ts=2 sw=2 ft=cpp:
