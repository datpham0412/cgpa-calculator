#include "../include/Menu.h"
#include "../include/StudentOperations.h"
#include <iostream>

void displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Display Student" << std::endl;
    std::cout << "3. List All Students" << std::endl;
    std::cout << "4. Add Courses to Existing Student" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int getUserChoice() {
    displayMenu();
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear newline character left in input buffer
    return choice;
}

void processUserChoice(int choice, SQLite::Database &db) {
    switch (choice) {
    case 1:
        addStudent(db);
        break;
    case 2:
        displayStudent(db);
        break;
    case 3:
        listAllStudents(db);
        break;
    case 4:
        addCoursesToExistingStudent(db);
        break;
    case 5:
        std::cout << "Exiting program." << std::endl;
        exit(0);
    default:
        std::cout << "Invalid choice, please try again." << std::endl;
    }
}
