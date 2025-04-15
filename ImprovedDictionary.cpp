// ImprovedDictionary.cpp
// This file implements the ImprovedDictionary class methods defined in ImprovedDictionary.h.
// The class extends the Dictionary class, adding functionality to calculate character probabilities
// and generate text based on these probabilities.
// written by: Janani Rasanjali
// Date of Creation: 14th April 2025

#include "ImprovedDictionary.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

// Displays a menu for user interaction, extending the functionality of the base Dictionary class
void ImprovedDictionary::menu() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n==== Improved Dictionary Program ====" << endl;
        cout << "1. Load Dictionary" << endl;
        cout << "2. Search for a Word" << endl;
        cout << "3. Random Word" << endl;
        cout << "4. NotGPT" << endl;
        cout << "5. Exit" << endl;
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
                notGPT();
                break;
            case 5:
                running = false;
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

// Demonstrates text generation based on character probabilities
void ImprovedDictionary::notGPT() {
    string startingPair;
    cout << "Enter the starting two characters: ";
    cin >> startingPair;

    // Validate the input length
    if (startingPair.length() != 2) {
        cout << "Invalid input. Please enter exactly two characters." << endl;
        return;
    }

    string text = "your sample text here or load from a file"; // Replace with actual text or file content
    calculateCharProbabilities(text);

    int sentenceCount = 5; // Number of sentences to generate
    int wordsPerSentence = 7; // Number of words per sentence
    int wordLength = 6; // Average word length

    // Generate and display the text
    string generatedText = generateText(sentenceCount, wordsPerSentence, wordLength, startingPair);
    cout << "Generated Text:\n" << generatedText << endl;
}

// Calculates character probabilities based on the input text
void ImprovedDictionary::calculateCharProbabilities(const string& text) {
    charProbabilities.clear();

    // Iterate through the text to calculate probabilities of character pairs
    for (size_t i = 0; i < text.length() - 2; ++i) {
        string pair = text.substr(i, 2);
        char nextChar = text[i + 2];
        charProbabilities[pair][nextChar]++;
    }
}

// Generates text based on calculated character probabilities
string ImprovedDictionary::generateText(int sentenceCount, int wordsPerSentence, int wordLength, const string& startingPair) {
    string result;
    string currentPair = startingPair;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis('a', 'z'); // Distribution for random lowercase letters

    // Generate sentences and words based on the specified parameters
    for (int s = 0; s < sentenceCount; ++s) {
        for (int w = 0; w < wordsPerSentence; ++w) {
            string word = currentPair;

            // Generate each character in the word based on probabilities
            for (int c = 0; c < wordLength - 2; ++c) {
                map<char, int> probabilities = charProbabilities[currentPair];
                vector<char> possibleChars;
                vector<int> weights;

                // Collect possible characters and their weights
                for (const auto& entry : probabilities) {
                    possibleChars.push_back(entry.first);
                    weights.push_back(entry.second);
                }

                if (!possibleChars.empty()) {
                    discrete_distribution<int> dist(weights.begin(), weights.end());
                    char nextChar = possibleChars[dist(gen)];
                    word += nextChar;
                    currentPair = word.substr(word.length() - 2);
                } else {
                    // Use a random character if no probabilities are available
                    char nextChar = static_cast<char>(dis(gen));
                    word += nextChar;
                    currentPair = word.substr(word.length() - 2);
                }
            }
            result += word + " ";
        }
        result += ". ";
    }
    return result;
}
