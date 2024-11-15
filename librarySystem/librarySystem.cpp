#include "LibrarySystem.h"
#include <iostream>

// Method to add a new member
void LibrarySystem::createNewMember(const Member& member) {
    members.push_back(member);
    std::cout << "Member added successfully.\n";
}

// Method to add a new item to the catalog
void LibrarySystem::createNewItem(LibraryItem* item) {
    catalog.push_back(item);
    std::cout << "Item added to catalog successfully.\n";
}

// Method to borrow an item for a specific member
void LibrarySystem::borrowItem(int memberID, LibraryItem* item) {
    // Find the member by ID
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& m) {
        return m.getMemberID() == memberID;
    });

    if (it != members.end()) {
        // Check if the item is available
        if (!item->getIsBorrowed()) {
            it->borrowItem(item);
            std::cout << "Item borrowed successfully.\n";
        } else {
            std::cout << "Item is already borrowed.\n";
        }
    } else {
        std::cout << "Member not found.\n";
    }
}

// Method to return an item for a specific member
void LibrarySystem::returnItem(int memberID, LibraryItem* item) {
    // Find the member by ID
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& m) {
        return m.getMemberID() == memberID;
    });

    if (it != members.end()) {
        it->returnItem(item);
        std::cout << "Item returned successfully.\n";
    } else {
        std::cout << "Member not found.\n";
    }
}

// Method to display details of a specific member
void LibrarySystem::displayMemberDetails(int memberID) const {
    // Find the member by ID
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& m) {
        return m.getMemberID() == memberID;
    });

    if (it != members.end()) {
        std::cout << "Member ID: " << it->getMemberID() << "\n"
                  << "Name: " << it->getName() << std::endl;
        it->listBorrowedItems();
    } else {
        std::cout << "Member not found.\n";
    }
}

// Method to display all items borrowed by a specific member
void LibrarySystem::displayBorrowedItems(int memberID) const {
    // Find the member by ID
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& m) {
        return m.getMemberID() == memberID;
    });

    if (it != members.end()) {
        it->listBorrowedItems();
    } else {
        std::cout << "Member not found.\n";
    }
}
