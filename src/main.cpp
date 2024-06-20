// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include "Student.h"
// #include "FileManager.h"

// void addStudent(std::vector<Student> &students);
// void addCourseToStudent(std::vector<Student> &students);
// void displayStudentDetails(const std::vector<Student> &students);
// void menu();
// int main()
// {
//     menu();
//     return 0;
// }

// void addStudent(std::vector<Student> &students)
// {
//     std::string studentID, studentName;
//     int currentYear, currentSemester;
//     std::cout << "\nEnter student ID: \n> ";
//     std::cin >> studentID;
//     std::cout << "\nEnter student name: \n> ";
//     std::cin.ignore(); // Ignore the newline character in the input buffer.
//     std::getline(std::cin, studentName);
//     std::cout << "\nWhich year are you in at university?: \n> ";
//     std::cin >> currentYear;
//     std::cout << "\nEnter current semester (1 or 2): \n> ";
//     std::cin >> currentSemester;
//     students.push_back(Student(studentName, studentID, currentYear, currentSemester));
//     FileManager::saveToFile(students);
//     std::cout << "Student added successfully!!!";
// }

// void addCourseToStudent(std::vector<Student> &students)
// {
//     std::string studentID;
//     std::cout << "\nEnter Student ID: \n>";
//     std::cin >> studentID;
//     auto it = std::find_if(students.begin(), students.end(), [&](const Student &s)
//                            { return s.GetStudentID() == studentID; });
//     if (it != students.end())
//     {
//         int semesterIndex = (it->GetCurrentYear() - 1) * 2 + (it->GetCurrentSemester() - 1);
//         int numUnits;
//         std::cout << "Enter the number of units for semester " << it->GetCurrentYear() << " - year " << it->GetCurrentYear() << ": ";
//         std::cin >> numUnits;
//         for (int i = 0; i < numUnits; i++)
//         {
//             std::string courseName;
//             int grade;
//             std::cout << "Enter course name: ";
//             std::cin.ignore();
//             std::getline(std::cin, courseName);
//             std::cout << "Enter grade: ";
//             std::cin >> grade;
//             it->addCourse(semesterIndex, Course(courseName, grade));
//         }
//     }
//     else
//     {
//         std::cout << "Student not found";
//     }
// }

#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

int main()
{
    try
    {
        // Open a database file
        SQLite::Database db("test.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        std::cout << "SQLite database opened successfully!" << std::endl;

        // Create a new table
        db.exec("CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, value TEXT)");
        std::cout << "Table created successfully!" << std::endl;

        // Insert a row of data
        SQLite::Statement query(db, "INSERT INTO test (value) VALUES (?)");
        query.bind(1, "Hello, SQLiteCpp!");
        query.exec();
        std::cout << "Data inserted successfully!" << std::endl;

        // Query the data
        SQLite::Statement selectQuery(db, "SELECT * FROM test");
        while (selectQuery.executeStep())
        {
            std::cout << "Row: id = " << selectQuery.getColumn(0) << ", value = " << selectQuery.getColumn(1) << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
