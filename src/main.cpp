#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Student.h"
#include "Course.h"
#include <vector>
#include <iomanip> // for std::setw

void createTables(SQLite::Database &db)
{
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

void addStudent(SQLite::Database &db)
{
    std::string studentID, studentName;
    int currentYear, currentSemester;

    std::cout << "Enter Student ID: ";
    std::getline(std::cin, studentID);

    // Check if studentID already exists
    SQLite::Statement query(db, "SELECT COUNT(*) FROM students WHERE studentID = ?");
    query.bind(1, studentID);
    if (query.executeStep() && query.getColumn(0).getInt() > 0)
    {
        std::cout << "Student ID already exists. Cannot add duplicate student." << std::endl;
        return;
    }

    std::cout << "Enter Student Name: ";
    std::getline(std::cin, studentName);

    std::cout << "Enter Current Year: ";
    std::cin >> currentYear;

    std::cout << "Enter Current Semester: ";
    std::cin >> currentSemester;

    Student student(studentName, studentID, currentYear, currentSemester);
    std::cin.ignore(); // Clear newline character left in input buffer

    char addMoreCourses;
    do
    {
        int year, semester;
        std::cout << "Enter Year to add courses: ";
        std::cin >> year;
        std::cin.ignore();

        std::cout << "Enter Semester (1 or 2): ";
        std::cin >> semester;
        std::cin.ignore();

        if (semester != 1 && semester != 2)
        {
            std::cout << "Invalid semester. Please enter 1 or 2." << std::endl;
            continue;
        }

        int semesterIndex = (year - 1) * 2 + semester;
        int numUnits;

        std::cout << "Enter number of units (courses) in semester " << semester << " of year " << year << ": ";
        std::cin >> numUnits;
        std::cin.ignore();

        for (int i = 0; i < numUnits; ++i)
        {
            std::string courseName;
            int grades;

            std::cout << "Enter Course Name: ";
            std::getline(std::cin, courseName);

            std::cout << "Enter Course Grade: ";
            std::cin >> grades;
            std::cin.ignore();

            student.addCourse(semesterIndex, Course(courseName, grades));
        }

        std::cout << "Add courses for another semester? (y/n): ";
        std::cin >> addMoreCourses;
        std::cin.ignore();

    } while (addMoreCourses == 'y' || addMoreCourses == 'Y');

    student.saveToDatabase(db);
    std::cout << "Student and courses saved to database successfully!" << std::endl;
}

void displayStudent(SQLite::Database &db)
{
    std::string studentID;

    std::cout << "Enter Student ID to display: ";
    std::getline(std::cin, studentID);

    // Check if studentID exists
    SQLite::Statement query(db, "SELECT COUNT(*) FROM students WHERE studentID = ?");
    query.bind(1, studentID);
    if (query.executeStep() && query.getColumn(0).getInt() == 0)
    {
        std::cout << "Student ID does not exist." << std::endl;
        return;
    }

    Student student;
    student.loadFromDatabase(db, studentID);

    // Display in table format
    std::cout << std::left << std::setw(15) << "Student ID"
              << std::setw(25) << "Student Name"
              << std::setw(15) << "Current Year"
              << std::setw(20) << "Current Semester"
              << std::setw(10) << "CGPA" << std::endl;

    std::cout << std::left << std::setw(15) << student.GetStudentID()
              << std::setw(25) << student.GetStudentName()
              << std::setw(15) << student.GetCurrentYear()
              << std::setw(20) << student.GetCurrentSemester()
              << std::setw(10) << student.calculateCGPA() << std::endl;
}

void listAllStudents(SQLite::Database &db)
{
    SQLite::Statement query(db, "SELECT studentID, studentName, currentYear, currentSemester, CGPA FROM students");

    std::cout << "All Students:" << std::endl;

    // Display headers
    std::cout << std::left << std::setw(15) << "Student ID"
              << std::setw(25) << "Student Name"
              << std::setw(15) << "Current Year"
              << std::setw(20) << "Current Semester"
              << std::setw(10) << "CGPA" << std::endl;

    // Display each student in table format
    while (query.executeStep())
    {
        std::cout << std::left << std::setw(15) << query.getColumn(0).getText()
                  << std::setw(25) << query.getColumn(1).getText()
                  << std::setw(15) << query.getColumn(2).getInt()
                  << std::setw(20) << query.getColumn(3).getInt()
                  << std::setw(10) << query.getColumn(4).getDouble() << std::endl;
    }
}

void displayMenu()
{
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Display Student" << std::endl;
    std::cout << "3. List All Students" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    try
    {
        // Open a database file
        SQLite::Database db("student.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        std::cout << "SQLite database opened successfully!" << std::endl;

        // Create tables
        createTables(db);
        std::cout << "Tables created successfully!" << std::endl;

        while (true)
        {
            displayMenu();
            int choice;
            std::cin >> choice;
            std::cin.ignore(); // Clear newline character left in input buffer

            switch (choice)
            {
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
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
