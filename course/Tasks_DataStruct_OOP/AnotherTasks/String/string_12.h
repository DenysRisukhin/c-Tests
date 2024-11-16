//
//  string_12.h
//  Test2019
//
//  Created by Risukhin Denys on 1/17/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef string_12_h
#define string_12_h

// 1. You're creating an input stream range that will return a range of words
// 2. You're transforming each word to lowercase - view::transform(tolower)
// 3. Ignore characters that aren't letters or digits - view::filter(isalnum).
// 4. You might get empty strings when a token did not contain any letters or digits. You want to skip those.
// 5. Now you have a clear list of words that you can pass to the rest of the algorithm.

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>

// Function to check if a character is a punctuation mark
// Function to check if a character is a punctuation mark or digit
bool isPunctuationOrDigit(char ch)
{
    return std::ispunct(ch) || std::isdigit(ch);
}


// Function to remove punctuation from a string
std::string removePunctuation(const std::string& input)
{
    std::string result;
    
    // Iterate through each character in the input string
    for (char ch : input) {
        // Check if the character is not a punctuation mark
        if (!isPunctuationOrDigit(ch)) {
            // Append the character to the result string
            result += ch;
        }
    }
    
    return result;
}

// Function to count words in a book
std::unordered_map<std::string, int> countWordsInBook(const std::string& book, const std::string& keyWord)
{
    std::unordered_map<std::string, int> wordCounts;
    
    // Convert the book to lowercase to make the counting case-insensitive
    std::string lowercaseBook = book;
    std::transform(lowercaseBook.begin(), lowercaseBook.end(), lowercaseBook.begin(), ::tolower);
    
    // Convert the key word to lowercase
    std::string lowercaseKeyWord = keyWord;
    std::transform(lowercaseKeyWord.begin(), lowercaseKeyWord.end(), lowercaseKeyWord.begin(), ::tolower);
    // Remove punctuation from the key word
    std::string cleanedKeyWord = removePunctuation(lowercaseKeyWord);
    
    // Use a stringstream to extract words
    std::istringstream iss(lowercaseBook);
    std::string word;
    
    while (iss >> word)
    {
        // Remove punctuation from the word
        std::string cleanedWord = removePunctuation(word);
        
        // Increment the count for each cleaned word
        wordCounts[cleanedWord]++;
    }
    
    
    // Count occurrences of the cleaned key word
    int keyWordCount = wordCounts[cleanedKeyWord];
    
    std::cout << "Occurrences of the key word '" << keyWord << "': " << keyWordCount << std::endl;
    
    return wordCounts;
}

//int main()
//{
//    // Example usage
//    std::string book = "This is a sample book3. It's a small book, but it's interesting.";
//
//    // Key searching word
//    std::string keyWord = "book";
//
//    // Count words and occurrences of the key word
//    std::unordered_map<std::string, int> wordCounts = countWordsInBook(book, keyWord);
//
//    // Display word counts
//    for (const auto& pair : wordCounts) {
//        std::cout << "Word: " << pair.first << " -> Count: " << pair.second << std::endl;
//    }
//
//    return 0;
//}

#endif /* string_12_h */
