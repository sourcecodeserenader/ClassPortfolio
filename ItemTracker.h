// Brianna Reed
// CS-210-R4726 Programming Languages 24EW4
// Header for ItemTracker class used in Corner Grocer Item Tracking Application
// This file declares the ItemTracker class that encapsulates the logic for tracking
// and displaying item frequencies.

#include <string>
#include <unordered_map>

class ItemTracker {
private:
    std::string inputFileName;
    std::unordered_map<std::string, int> itemFrequencies;

    // Helper function to convert strings to lowercase
    std::string toLower(const std::string& str);

public:
    // Constructor that initializes the input file name and reads the item frequencies
    ItemTracker(const std::string& fileName);

    // Initializes the backup data file with the item frequencies
    void initializeDataFile(const std::string& outputFileName);

    // Allows the user to search for a specific item and displays its frequency
    void searchItemFrequency();

    // Prints the frequency of all items
    void printAllFrequencies();

    // Prints a histogram of item frequencies
    void printHistogram();
};
