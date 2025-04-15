// main.cpp
// This file contains the main function, which serves as the entry point for the Improved Dictionary program.
// It initializes the random number generator and invokes the menu of the ImprovedDictionary class to start the program.
// written by: Janani Rasanjali
// Date of Creation: 14th April 2025

#include "ImprovedDictionary.h"
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create an instance of the ImprovedDictionary class
    ImprovedDictionary dictionary;

    // Display the menu and start the program
    dictionary.menu();

    return 0;
}
