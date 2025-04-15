// Dictionary.cpp
// This file implements the Dictionary class methods defined in Dictionary.h.
// The class manages a collection of Word objects, providing functionality to load a dictionary from a file,
// search for a word, retrieve a random word, and display a menu for user interaction.
// written by: Janani Rasanjali
// Date of Creation: 11th April 2025

#include "Dictionary.h"
#include <fstream>
#include <cstdlib> 
#include <ctime>
#include <iostream>

using namespace std;

// Loads the dictionary from a file
bool Dictionary::loadDictionary(const string& filename) {
    ifstream file(filename); // Open the file for reading
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    words.clear(); // Clear any existing words in the vector

    // Read the file line by line
    while (getline(file, line)) {
        if (!line.empty() && line.back() == ';') {
            string name = line.substr(0, line.length() - 1); // Extract the word name
            if (getline(file, line) && !line.empty() && line.back() == ';') {
                string type = line.substr(0, line.length() - 1); // Extract the word type
                if (getline(file, line)) {
                    string definition = line; // Extract the word definition
                    getline(file, line); // Read the blank line
                    words.emplace_back(name, type, definition); // Add the word to the vector
                }
            }
        }
    }

    file.close();
    cout << "Dictionary loaded successfully with " << words.size() << " words." << endl;
    return true;
}

// Searches for a word in the dictionary based on user input
void Dictionary::searchWord() const {
    if (words.empty()) {
        cout << "Error -- dictionary empty" << endl;
        return;
    }

    string searchTerm;
    cout << "Enter a word to search: ";
    cin >> searchTerm;

    // Iterate through the words vector to find the search term
    for (const auto& word : words) {
        if (word.getName() == searchTerm) {
            word.printDefinition();
            return;
        }
    }

    cout << "Word not found." << endl;
}

// Retrieves and displays a random word from the dictionary
void Dictionary::randomWord() const {
    if (words.empty()) {
        cout << "Error -- dictionary empty" << endl;
        return;
    }

    int randomIndex = rand() % words.size(); // Generate a random index
    words[randomIndex].printDefinition(); // Print the definition of the random word
}

// Displays a menu for user interaction
void Dictionary::menu() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n==== Dictionary Program ====" << endl;
        cout << "1. Load Dictionary" << endl;
        cout << "2. Search for a Word" << endl;
        cout << "3. Random Word" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user choice with a switch statement
        switch (choice) {
            case 1:
                loadDictionary("dictionary.txt");
                break;
            case 2:
                searchWord();
                break;
            case 3:
                randomWord();
                break;
            case 4:
                running = false;
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
