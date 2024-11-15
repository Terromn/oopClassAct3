#ifndef DVD_H
#define DVD_H

#include "../../libraryItem/LibraryItem.h"
#include <string>

class DVD : public LibraryItem {
private:
    int duration;

public:
    // Constructor declaration only
    DVD(const std::string& title, const std::string& author, int itemID, int duration);

    // Method to display DVD details
    void displayDetails() const;
};

#endif // DVD_H
