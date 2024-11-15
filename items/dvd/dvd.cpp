#include "DVD.h"
#include <iostream>

// Constructor definition
DVD::DVD(const std::string& title, const std::string& author, int itemID, int duration)
    : LibraryItem(title, author, itemID), duration(duration) {}

// Method to display DVD details
void DVD::displayDetails() const {
    std::cout << "DVD Details:\n"
              << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Item ID: " << itemID << "\n"
              << "Duration: " << duration << " minutes\n"
              << "Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
}
