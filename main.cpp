#include <iostream>
#include <memory>
#include "librarySystem/LibrarySystem.h"
#include "items/book/Book.h"
#include "items/journal/Journal.h"
#include "items/dvd/DVD.h"

void displayMenu() {
    std::cout << "\nLibrary System Menu:\n";
    std::cout << "1. Add New Member\n";
    std::cout << "2. Add New Item (Book, Journal, or DVD)\n";
    std::cout << "3. Borrow Item\n";
    std::cout << "4. Return Item\n";
    std::cout << "5. Display Member's Borrowed Items\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    LibrarySystem librarySystem;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 1) {
            // Add New Member
            int memberID;
            std::string name;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Member Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            Member newMember(memberID, name);
            librarySystem.createNewMember(newMember);

        } else if (choice == 2) {
            // Add New Item
            int itemType, itemID, extraAttribute;
            std::string title, author;
            std::cout << "Select Item Type (1: Book, 2: Journal, 3: DVD): ";
            std::cin >> itemType;
            std::cout << "Enter Item ID: ";
            std::cin >> itemID;
            std::cout << "Enter Title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter Author: ";
            std::getline(std::cin, author);

            LibraryItem* newItem = nullptr;
            if (itemType == 1) {
                // Add a Book
                std::cout << "Enter Page Count: ";
                std::cin >> extraAttribute;
                newItem = new Book(title, author, itemID, extraAttribute);
            } else if (itemType == 2) {
                // Add a Journal
                std::cout << "Enter Issue Number: ";
                std::cin >> extraAttribute;
                newItem = new Journal(title, author, itemID, extraAttribute);
            } else if (itemType == 3) {
                // Add a DVD
                std::cout << "Enter Duration (in minutes): ";
                std::cin >> extraAttribute;
                newItem = new DVD(title, author, itemID, extraAttribute);
            }

            if (newItem) {
                librarySystem.createNewItem(newItem);
            } else {
                std::cout << "Invalid item type selected.\n";
            }

        } else if (choice == 3) {
            // Borrow Item
            int memberID, itemID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Item ID to Borrow: ";
            std::cin >> itemID;

            // Search for the item in the catalog
            LibraryItem* itemToBorrow = nullptr;
            for (LibraryItem* item : librarySystem.catalog) {
                if (item->getItemID() == itemID) {
                    itemToBorrow = item;
                    break;
                }
            }

            if (itemToBorrow) {
                librarySystem.borrowItem(memberID, itemToBorrow);
            } else {
                std::cout << "Item not found in the catalog.\n";
            }

        } else if (choice == 4) {
            // Return Item
            int memberID, itemID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Item ID to Return: ";
            std::cin >> itemID;

            // Search for the item in the catalog
            LibraryItem* itemToReturn = nullptr;
            for (LibraryItem* item : librarySystem.catalog) {
                if (item->getItemID() == itemID) {
                    itemToReturn = item;
                    break;
                }
            }

            if (itemToReturn) {
                librarySystem.returnItem(memberID, itemToReturn);
            } else {
                std::cout << "Item not found in the catalog.\n";
            }

        } else if (choice == 5) {
            // Display Member's Borrowed Items
            int memberID;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            librarySystem.displayBorrowedItems(memberID);

        } else if (choice == 6) {
            // Exit
            std::cout << "Exiting the library system. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
