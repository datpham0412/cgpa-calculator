#include "../include/Database.h"
#include <iostream>

void createTables(SQLite::Database &db) {
    db.exec("CREATE TABLE IF NOT EXISTS students ("
            "studentID TEXT PRIMARY KEY, "
            "studentName TEXT, "
            "currentYear INTEGER, "
            "currentSemester INTEGER, "
            "CGPA REAL)");

    db.exec("CREATE TABLE IF NOT EXISTS courses ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "studentID TEXT, "
            "semesterIndex INTEGER, "
            "courseName TEXT, "
            "grades INTEGER, "
            "FOREIGN KEY(studentID) REFERENCES students(studentID))");
}

void initializeDatabase(SQLite::Database &db) {
    std::cout << "SQLite database opened successfully!" << std::endl;

    // Create tables
    createTables(db);
    std::cout << "Tables created successfully!" << std::endl;
}
