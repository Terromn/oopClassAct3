#include "Book.h"
#include <iostream>

// Constructor definition
Book::Book(const std::string& title, const std::string& author, int itemID, int pageCount)
    : LibraryItem(title, author, itemID), pageCount(pageCount) {}

// Method to display book details
void Book::displayDetails() const {
    std::cout << "Book Details:\n"
              << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Item ID: " << itemID << "\n"
              << "Pages: " << pageCount << "\n"
              << "Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
}
