#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>
#include "../include/Menu.h"
#include "../include/Database.h"

int main() {
    try {
        // Open a database file
        SQLite::Database db("student.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        initializeDatabase(db);

        while (true) {
            int choice = getUserChoice();
            processUserChoice(choice, db);
        }
    } catch (const std::exception &e) {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
