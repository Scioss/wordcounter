#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <limits>

std::string sentence;
std::vector<std::string> sentenceWords;

std::string word;
int nbWord;

std::string const continueKey = "y";
std::string key = "y";

// Delimiter to separate words
constexpr char delimiter = ' ';

// Loop to write the sentence word by word
void write_cut_sentence() {
    for (int i = 0; i < sentenceWords.size(); i++) {
        word = sentenceWords[i];
        std::cout << word << ", ";
    }
}

// Writes the number of words in the sentence
void write_nb_word() {
    std::cout << std::endl << "There are " << nbWord << " words in this sentence" << std::endl;
}

void write_sentence() {
    std::cout << sentence << std::endl;
}

// Splits the sentence into individual words
void cutSentence() {
    auto start = sentence.begin();
    auto end = sentence.end();
    auto it = std::find(start, end, delimiter);
    while (it != end) { // Adds the individual words separated by spaces to the word list
        std::string word(start, it);
        start = it + 1;
        it = std::find(start, end, delimiter);
        sentenceWords.push_back(word);
        // Increment the word count
        nbWord++;
    }
    // Add the last word because the loop stops one word before
    std::string word(start, it);
    sentenceWords.push_back(word);
    // Increment the word count
    nbWord++;
}

// Removes extra spaces from the beginning and end of the sentence
std::string remove_spaces(std::string str) {
    // Find the first character that is not a space
    auto charLocation {std::find_if_not(str.begin(), str.end(), isspace)};
    // Remove leading spaces
    str.erase(str.begin(), charLocation);
    // Reverse the string and repeat the operation to remove trailing spaces
    std::reverse(str.begin(), str.end());
    charLocation = std::find_if_not(str.begin(), str.end(), isspace);
    str.erase(str.begin(), charLocation);
    std::reverse(str.begin(), str.end());
    return str;
}

int main() {
    while (key == continueKey) {
        std::cout << "Enter a sentence, I will clean and cut it : ";
        std::getline(std::cin, sentence);
        std::cout << "The sentence without spaces is: ";
        sentence = remove_spaces(sentence);
        write_sentence();
        cutSentence();
        write_cut_sentence();
        write_nb_word();
        std::cout << "Press Y to continue or another key to quit : ";
        std::cin.clear();
        std::cin >> key;
        key = remove_spaces(key);
        for (int i = 0; i < key.size(); i++) {
            key[i] = tolower(key[i]);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}
