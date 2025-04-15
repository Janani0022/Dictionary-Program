// Dictionary.h
// This header file defines the Dictionary class, which manages a collection of Word objects.
// The class provides methods to load a dictionary from a file, search for a word, retrieve a random word,
// and display a menu for user interaction.
// written by: Janani Rasanjali
// Date of Creation: 11th April 2025

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include "Word.h"

using namespace std;

class Dictionary {
private:
    vector<Word> words; // A vector to store Word objects

public:
    // Loads the dictionary from a file
    // Returns true if the file is loaded successfully, false otherwise
    bool loadDictionary(const string& filename);

    // Searches for a word in the dictionary based on user input
    void searchWord() const;

    // Retrieves and displays a random word from the dictionary
    void randomWord() const;

    // Displays a menu for user interaction
    // Declared as virtual to allow for potential overriding in derived classes
    virtual void menu();
};

#endif // DICTIONARY_H
