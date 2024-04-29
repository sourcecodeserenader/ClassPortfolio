// Brianna Reed
// CS-210-R4726 Programming Languages 24EW4
// Implementation of ItemTracker class for Corner Grocer Item Tracking Application
// This file contains the definition of the ItemTracker class and handles reading
// item frequencies from a file, searching for an item, displaying all frequencies,
// and displaying a histogram.

#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

// Constructor to initialize file name and read in the item frequencies
ItemTracker::ItemTracker(const std::string& fileName) : inputFileName(fileName) {
    std::ifstream file(inputFileName);
    std::string item;
    // Read each item, convert to lowercase, and update its frequency
    while (file >> item) {
        std::string lowerItem = toLower(item);
        itemFrequencies[lowerItem]++;
    }
    file.close();
}

// Converts a string to lowercase
std::string ItemTracker::toLower(const std::string& str) {
    std::string lowerCaseStr = str;
    std::transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerCaseStr;
}

// Initializes the backup data file with the item frequencies
void ItemTracker::initializeDataFile(const std::string& outputFileName) {
    std::ofstream outFile(outputFileName);
    for (const auto& pair : itemFrequencies) {
        outFile << pair.first << " " << pair.second << "\n";
    }
    outFile.close();
}

// Prompts user for an item and displays its frequency in a case-insensitive manner
void ItemTracker::searchItemFrequency() {
    std::string searchItem;
    std::cout << "Enter item to search: ";
    std::cin >> searchItem;
    searchItem = toLower(searchItem); // Convert search item to lowercase
    auto it = itemFrequencies.find(searchItem);
    if (it != itemFrequencies.end()) {
        std::cout << searchItem << " appears " << it->second << " times.\n";
    }
    else {
        std::cout << "Item not found.\n";
    }
}

// Prints all items with their frequencies
void ItemTracker::printAllFrequencies() {
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

// Prints a histogram of items based on their frequencies
void ItemTracker::printHistogram() {
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
