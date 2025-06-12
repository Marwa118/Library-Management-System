#include <iostream>
#include <limits>
#include "LibrarySystem.h"
#include "User.h"
#include "Book.h"
#include "Thesis.h"
#include "DigitalResources.h"  
#include "Article.h"
#include "MyDate.h"           

int main() {
    LibrarySystem system;
    system.loadData();

    int choice;
    do {
        std::cout << "\n====== Library Menu ======\n";
        std::cout << "1. Add User\n";
        std::cout << "2. Add Resource\n";
        std::cout << "3. Borrow Resource\n";
        std::cout << "4. Return Resource\n";
        std::cout << "5. List All Resources\n";
        std::cout << "6. Save and Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        if (choice == 1) {
            std::string id, name;
            std::cout << "Enter user ID: ";
            getline(std::cin, id);
            std::cout << "Enter name: ";
            getline(std::cin, name);
            system.addUser(User(id, name));
            std::cout << "User added.\n";

        } else if (choice == 2) {
            std::string type, id, title, author;
            int year;
            std::cout << "Enter resource type (Book, Thesis, Digital, Article): ";
            getline(std::cin, type);
            std::cout << "Enter ID: ";
            getline(std::cin, id);
            std::cout << "Enter title: ";
            getline(std::cin, title);
            std::cout << "Enter author: ";
            getline(std::cin, author);
            std::cout << "Enter publication year: ";
            std::cin >> year;
            std::cin.ignore();

            for (auto& c : type) c = std::tolower(c);

            if (type == "book") {
                system.addResource(new Book(id, title, author, year));
            } else if (type == "thesis") {
                system.addResource(new Thesis(id, title, author, year));
            } else if (type == "digital") {
                system.addResource(new DigitalResource(id, title, author, year));
            } else if (type == "article") {
                system.addResource(new Article(id, title, author, year));
            } else {
                std::cout << "Invalid type.\n";
            }

        } else if (choice == 3) {
            std::string userId, resourceId;
            std::cout << "Enter user ID: ";
            getline(std::cin, userId);
            std::cout << "Enter resource ID: ";
            getline(std::cin, resourceId);
            system.borrowResource(userId, resourceId);
            std::cout << "Borrow request processed.\n";

        } else if (choice == 4) {
            std::string userId, resourceId;
            std::cout << "Enter user ID: ";
            getline(std::cin, userId);
            std::cout << "Enter resource ID: ";
            getline(std::cin, resourceId);
            system.returnResource(userId, resourceId);
            std::cout << "Return request processed.\n";

        } else if (choice == 5) {
            std::cout << "\n--- Resource List ---\n";
            system.searchResources(""); 

        } else if (choice == 6) {
            MyDate today(13, 6, 2025);  
            system.checkOverdues(today);
            system.saveData();
            std::cout << "Data saved. Exiting...\n";
        } else {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
