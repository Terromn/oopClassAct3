#ifndef BOOK_H
#define BOOK_H

#include "../../libraryItem/LibraryItem.h"
#include <string>

class Book : public LibraryItem {
private:
    int pageCount;

public:
    // Constructor declaration only
    Book(const std::string& title, const std::string& author, int itemID, int pageCount);

    // Method to display book details
    void displayDetails() const;
};

#endif // BOOK_H
