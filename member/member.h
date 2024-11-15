#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "../libraryItem/LibraryItem.h"

class Member {
private:
    int memberID;
    std::string name;
    std::vector<LibraryItem*> borrowedItems;

public:
    // Constructor
    Member(int memberID, std::string  name);

    // Method to borrow an item
    void borrowItem(LibraryItem* item);

    // Method to return an item
    void returnItem(LibraryItem* item);

    // Method to list all borrowed items
    void listBorrowedItems() const;

    // Accessor for memberID
    int getMemberID() const;

    // Accessor for name
    std::string getName() const;
};

#endif // MEMBER_H
