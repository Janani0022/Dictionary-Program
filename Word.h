// Word.h
// This header file defines the Word class, which represents a word with its name, type, and definition.
// The class provides methods to retrieve these attributes and print the word's definition in a formatted manner.
// written by: Janani Rasanjali
// Date of Creation: 11th April 2025

#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>

using namespace std;

class Word {
private:
    string name;       // The name of the word
    string type;       // The type of the word (e.g., noun, verb)
    string definition; // The definition of the word

public:
    // Default constructor
    Word() = default;

    // Parameterized constructor to initialize a Word object
    Word(const string& name, const string& type, const string& definition)
        : name(name), type(type), definition(definition) {}

    // Getter for the word's name
    string getName() const { return name; }

    // Getter for the word's type
    string getType() const { return type; }

    // Getter for the word's definition
    string getDefinition() const { return definition; }

    // Prints the word's definition in a formatted manner
    void printDefinition() const {
        cout << name << " " << getAbbreviatedType(type) << "\n" << definition << endl;
    }

    // Static method to get the abbreviated type of the word
    static string getAbbreviatedType(const string& type) {
        // Returns the abbreviated type based on the input type
        if (type == "n") return "(n.)";
        if (type == "v") return "(v.)";
        if (type == "adv") return "(adv.)";
        if (type == "adj") return "(adj.)";
        if (type == "prep") return "(prep.)";
        if (type == "misc") return "(misc.)";
        if (type == "pn") return "(pn.)";
        if (type == "n_and_v") return "(n. v.)";
        return "(" + type + ")"; // Default case if type is not recognized
    }
};

#endif // WORD_H
