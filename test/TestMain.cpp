#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Student.h"
#include "Course.h"

int main()
{
    try
    {
        SQLite::Database db("test_student.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        std::cout << "SQLite database opened successfully!" << std::endl;

        // Create tables
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

        // Create a Student object
        Student student("John Doe", "12345", 3, 1);

        // Add courses to the student
        student.addCourse(1, Course("Math", 85));
        student.addCourse(1, Course("History", 78));
        student.addCourse(2, Course("Physics", 90));
        student.addCourse(2, Course("Chemistry", 75));

        // Save the student to the database
        student.saveToDatabase(db);
        std::cout << "Student saved to database successfully!" << std::endl;

        // Load the student from the database
        Student loadedStudent; // Use the default constructor
        loadedStudent.loadFromDatabase(db, "12345");
        std::cout << "Student loaded from database successfully!" << std::endl;

        // Print student details
        std::cout << "Student Name: " << loadedStudent.GetStudentName() << std::endl;
        std::cout << "Student ID: " << loadedStudent.GetStudentID() << std::endl;
        std::cout << "Current Year: " << loadedStudent.GetCurrentYear() << std::endl;
        std::cout << "Current Semester: " << loadedStudent.GetCurrentSemester() << std::endl;
        std::cout << "CGPA: " << loadedStudent.calculateCGPA() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
