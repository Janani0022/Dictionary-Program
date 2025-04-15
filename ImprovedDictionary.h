// ImprovedDictionary.h
// This header file defines the ImprovedDictionary class, which extends the Dictionary class.
// It adds functionality to calculate character probabilities and generate text based on these probabilities.
// written by: Janani Rasanjali
// Date of Creation: 14th April 2025

#ifndef IMPROVEDDICTIONARY_H
#define IMPROVEDDICTIONARY_H

#include "Dictionary.h"
#include <map>
#include <string>

using namespace std;

class ImprovedDictionary : public Dictionary {
public:
    // Overrides the menu method from the Dictionary class
    void menu() override;

    // Method to demonstrate that this class is not using GPT-like functionality
    void notGPT();

private:
    map<string, map<char, int>> charProbabilities; // Map to store character probabilities

    // Calculates character probabilities based on the input text
    void calculateCharProbabilities(const string& text);

    // Generates text based on calculated character probabilities
    string generateText(int sentenceCount, int wordsPerSentence, int wordLength, const string& startingPair);
};

#endif // IMPROVEDDICTIONARY_H
