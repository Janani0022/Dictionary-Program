#include <iostream> // For input and output
#include <fstream> // For file handling
#include <vector> // For using vectors
#include <string> // For using strings
#include <cstdlib> // For random number generation
#include <ctime> // For seeding random number generator

using namespace std;

// Struct to hold word information
struct Word {
    string name;
    string type;
    string definition;
};

/**
 * Loads a dictionary from a file into a vector of Word structs.
 *
 * Input:
 * - vector<Word>& dictionary: A reference to the vector where the dictionary will be stored.
 * - const string& filename: The name of the file to load the dictionary from.
 *
 * Output:
 * - bool: Returns true if the file was successfully loaded, false otherwise.
 *
 * Written by: Janani Rasanjali
 * Date: 09th April 2025
 */
bool loadDictionary(vector<Word>& dictionary, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    Word currentWord;

    // Reset dictionary
    dictionary.clear();

    // Read file line by line
    while (getline(file, line)) {
        // Line 1: Word name
        if (!line.empty() && line.back() == ';') {
            currentWord.name = line.substr(0, line.length() - 1);

            // Line 2: Word type
            if (getline(file, line) && !line.empty() && line.back() == ';') {
                currentWord.type = line.substr(0, line.length() - 1);

                // Line 3: Word definition
                if (getline(file, line)) {
                    currentWord.definition = line;

                    // Line 4: Blank line
                    getline(file, line);

                    // Add word to dictionary
                    dictionary.push_back(currentWord);
                }
            }
        }
    }

    file.close();
    cout << "Dictionary loaded successfully with " << dictionary.size() << " words." << endl;
    return true;
}

/**
 * Returns an abbreviated type for a given word type.
 *
 * Input:
 * - const string& type: The type of the word.
 *
 * Output:
 * - string: The abbreviated type in parentheses.
 *
 * Written by: Janani Rasanjali
 * Date: 09th April 2025
 */
string getAbbreviatedType(const string& type) {
    if (type == "n") return "(n.)";
    if (type == "v") return "(v.)";
    if (type == "adv") return "(adv.)";
    if (type == "adj") return "(adj.)";
    if (type == "prep") return "(prep.)";
    if (type == "misc") return "(misc.)";
    if (type == "pn") return "(pn.)";
    if (type == "n_and_v") return "(n. v.)";
    return "(" + type + ")";
}

/**
 * Searches for a word in the dictionary and displays its definition.
 *
 * Input:
 * - const vector<Word>& dictionary: The dictionary to search within.
 *
 * Output:
 * - None: Displays the word and its definition if found.
 *
 * Written by: Janani Rasanjali
 * Date: 09th April 2025
 */
void searchWord(const vector<Word>& dictionary) {
    if (dictionary.empty()) {
        cout << "Error -- dictionary empty" << endl;
        return;
    } 

    string searchTerm;
    cout << "Enter a word to search: ";
    cin >> searchTerm;

    bool found = false;
    for (const Word& word : dictionary) {
        if (word.name == searchTerm) {
            cout << word.name << " " << getAbbreviatedType(word.type) << endl;

            // Split definitions by semicolon followed by two spaces
            string def = word.definition;
            size_t pos = 0;
            while ((pos = def.find("; ", pos)) != string::npos) {
                def.replace(pos, 3, "\n");
                pos += 1; // Move past the newline character
            }

            cout << def << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Word not found." << endl;
    }
}

/**
 * Selects and displays a random word from the dictionary.
 *
 * Input:
 * - const vector<Word>& dictionary: The dictionary to select a word from.
 *
 * Output:
 * - None: Displays a random word and its definition.
 *
 * Written by: Janani Rasanjali
 * Date: 09th April 2025
 */
void randomWord(const vector<Word>& dictionary) {
    if (dictionary.empty()) {
        cout << "Error -- dictionary empty" << endl;
        return;
    }

    // Select a random word
    int randomIndex = rand() % dictionary.size();
    const Word& word = dictionary[randomIndex];

    // Display the word
    cout << "Random word: " << word.name << " " << getAbbreviatedType(word.type) << endl;

    // Split definitions by semicolon followed by two spaces
    string def = word.definition;
    size_t pos = 0;
    while ((pos = def.find("; ", pos)) != string::npos) {
        def.replace(pos, 3, "\n");
        pos += 1; // Move past the newline character
    }

    cout << def << endl;
}

/**
 * Main function to run the dictionary program.
 *
 * Input:
 * - None: Interacts with the user through the console.
 *
 * Output:
 * - int: Returns 0 upon successful execution.
 *
 * Written by: Janani Rasanjali
 * Date: 09th April 2025
 */
int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Word> dictionary;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n==== Dictionary Program ====" << endl;
        cout << "1. Load Dictionary" << endl;
        cout << "2. Search for a Word" << endl;
        cout << "3. Random Word" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                loadDictionary(dictionary, "dictionary.txt");
                break;
            case 2:
                searchWord(dictionary);
                break;
            case 3:
                randomWord(dictionary);
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

    return 0;
}
