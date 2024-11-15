#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>

class LibraryItem {
protected:
    std::string title;
    std::string author;
    int itemID;
    bool isBorrowed;

public:
    // Constructor
    LibraryItem(std::string  title, std::string  author, int itemID);

    // Method to display item details
    void displayDetails() const;

    // Method to mark the item as borrowed
    void borrowItem();

    // Method to mark the item as returned
    void returnItem();

    // Accessor to check if the item is borrowed
    bool getIsBorrowed() const;

    // Accessor for item ID
    int getItemID() const;

    // Destructor
    ~LibraryItem() {}
};

#endif // LIBRARYITEM_H
