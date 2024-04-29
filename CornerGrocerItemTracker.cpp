// Brianna Reed
// CS-210-R4726 Programming Languages 24EW4
// Corner Grocer Item Tracking Application
// This program provides a menu-driven user interface for tracking item frequencies
// from the grocery store's daily records.

#include <iostream>
#include <limits> // Required for std::numeric_limits
#include "ItemTracker.h" // Include the interface for the ItemTracker class

int main() {
    // Instantiate an ItemTracker object, initializing it with the name of the input file.
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");

    // Initialize the backup data file without user intervention.
    tracker.initializeDataFile("frequency.dat");

    int choice = 0; // Variable to store user's menu choice.

    // Main program loop
    while (true) {
        // Display the menu options
        std::cout << "1. Search item frequency\n";
        std::cout << "2. Display all frequencies\n";
        std::cout << "3. Display histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";

        // Get user input for menu choice
        std::cin >> choice;

        // If input fails due to incorrect type
        if (std::cin.fail()) {
            // Clear the error state of cin so it works for future input
            std::cin.clear();
            // Ignore the rest of the incorrect input until the end of the line (or a large number)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Notify user of the invalid option
            std::cout << "Invalid option. Please try again.\n";
            // Skip the rest of this iteration
            continue;
        }

        // Process the menu choice
        switch (choice) {
        case 1:
            // Search for an item and display its frequency
            tracker.searchItemFrequency();
            break;
        case 2:
            // Display all items with their frequencies
            tracker.printAllFrequencies();
            break;
        case 3:
            // Display a histogram of item frequencies
            tracker.printHistogram();
            break;
        case 4:
            // Exit the program
            std::cout << "Exiting...\n";
            return 0; // Return from main, which terminates the program
        default:
            // Handle any choice that is not covered by the switch cases
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}

