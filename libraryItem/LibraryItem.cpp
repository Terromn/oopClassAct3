#include "LibraryItem.h"
#include <iostream>
#include <utility>

// Constructor implementation
LibraryItem::LibraryItem(std::string  title, std::string  author, int itemID)
    : title(std::move(title)), author(std::move(author)), itemID(itemID), isBorrowed(false) {}

// Method to display item details
void LibraryItem::displayDetails() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Item ID: " << itemID << "\n"
              << "Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
}

// Method to mark the item as borrowed
void LibraryItem::borrowItem() {
    isBorrowed = true;
}

// Method to mark the item as returned
void LibraryItem::returnItem() {
    isBorrowed = false;
}

// Accessor to check if the item is borrowed
bool LibraryItem::getIsBorrowed() const {
    return isBorrowed;
}

// Accessor for item ID
int LibraryItem::getItemID() const {
    return itemID;
}
