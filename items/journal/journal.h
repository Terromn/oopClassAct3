#ifndef JOURNAL_H
#define JOURNAL_H

#include "../../libraryItem/LibraryItem.h"
#include <string>

class Journal : public LibraryItem {
private:
    int issueNo;

public:
    // Constructor declaration only
    Journal(const std::string& title, const std::string& author, int itemID, int issueNo);

    // Method to display journal details
    void displayDetails() const;
};

#endif // JOURNAL_H
