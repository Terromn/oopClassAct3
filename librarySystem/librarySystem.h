#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <vector>
#include "../member/member.h"
#include "../libraryItem/LibraryItem.h"

class LibrarySystem {
private:
    std::vector<Member> members;

public:
    std::vector<LibraryItem*> catalog;

    // Constructor
    LibrarySystem() = default;

    // Method to add a new member
    void createNewMember(const Member& member);

    // Method to add a new item to the catalog
    void createNewItem(LibraryItem* item);

    // Method to borrow an item
    void borrowItem(int memberID, LibraryItem* item);

    // Method to return an item
    void returnItem(int memberID, LibraryItem* item);

    // Method to display member details
    void displayMemberDetails(int memberID) const;

    // Method to display borrowed items for a specific member
    void displayBorrowedItems(int memberID) const;
};

#endif // LIBRARYSYSTEM_H
