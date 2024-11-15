#include "Member.h"
#include <iostream>

// Constructor
Member::Member(int memberID, std::string  name)
    : memberID(memberID), name(std::move(name)) {}

// Method to borrow an item
void Member::borrowItem(LibraryItem* item) {
    if (!item->getIsBorrowed()) {
        item->borrowItem();
        borrowedItems.push_back(item);
        std::cout << "Item borrowed successfully.\n";
    } else {
        std::cout << "Item is already borrowed.\n";
    }
}

// Method to return an item
void Member::returnItem(LibraryItem* item) {
    auto it = std::ranges::find(borrowedItems, item);
    if (it != borrowedItems.end()) {
        item->returnItem();
        borrowedItems.erase(it);
        std::cout << "Item returned successfully.\n";
    } else {
        std::cout << "Item not found in borrowed items.\n";
    }
}

// Method to list all borrowed items
void Member::listBorrowedItems() const {
    if (borrowedItems.empty()) {
        std::cout << "No items borrowed.\n";
    } else {
        std::cout << "Borrowed Items:\n";
        for (const auto& item : borrowedItems) {
            item->displayDetails();
        }
    }
}

// Accessor for memberID
int Member::getMemberID() const {
    return memberID;
}

// Accessor for name
std::string Member::getName() const {
    return name;
}
