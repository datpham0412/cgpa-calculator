#include <iostream>
#include <cassert>
#include <vector>
#include "../src/FileManager.h"
#include "../src/Course.h"
#include "../src/Student.h"

// Function prototype
void testAddStudent();
void promptAddStudent(std::vector<Student> &students);

int main()
{
    testAddStudent();
    std::cout << "All test passed" << std::endl;
    return 0;
}

void testAddStudent()
{
    std::vector<Student> students;
    // Prompt user for student details
    promptAddStudent(students);
    // Save to file to simulate the addStudent function behavior
    FileManager::saveToFile(students);
    // Clear the vector and load from file to ensure persistance
    students.clear();
    FileManager::loadFromFile(students);

    // verify the student was added and loaded correctly
    assert(students.size() == 1);
    const Student &student = students[0];

    // Assuming that the Student ID and name were entered correctly in the prompt
    std::cout << "Verifying student details..." << std::endl;
    std::cout << "Student ID: " << student.GetStudentID() << std::endl;
    std::cout << "Student Name: " << student.GetStudentName() << std::endl;
    std::cout << "Current Year: " << student.GetCurrentYear() << std::endl;
    std::cout << "Current Semester: " << student.GetCurrentSemester() << std::endl;

    std::cout << "testAddStudent method passed !!!" << std::endl;
}

void promptAddStudent(std::vector<Student> &students)
{
    std::string studentID, studentName;
    int currentYear, currentSemester;
    std::cout << "\nEnter student ID: \n> ";
    std::cin >> studentID;
    std::cout << "\nEnter student name: \n> ";
    std::cin.ignore(); // Ignore the newline character in the input buffer.
    std::getline(std::cin, studentName);
    std::cout << "\nEnter current year: \n> ";
    std::cin >> currentYear;
    std::cout << "\nEnter current semester (1 or 2): \n> ";
    std::cin >> currentSemester;
    students.push_back(Student(studentName, studentID, currentYear, currentSemester));
    std::cout << "Student added successfully!!! \n";
}