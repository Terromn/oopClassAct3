#include "Journal.h"
#include <iostream>

// Constructor definition
Journal::Journal(const std::string& title, const std::string& author, int itemID, int issueNo)
    : LibraryItem(title, author, itemID), issueNo(issueNo) {}

// Method to display journal details
void Journal::displayDetails() const {
    std::cout << "Journal Details:\n"
              << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Item ID: " << itemID << "\n"
              << "Issue Number: " << issueNo << "\n"
              << "Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
}
