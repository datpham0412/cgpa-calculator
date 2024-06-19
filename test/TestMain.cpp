#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include "../src/FileManager.h"
#include "../src/Course.h"
#include "../src/Student.h"

// Function prototype
void testAddStudent();
void testAddCourseToStudent();
void promptAddStudent(std::vector<Student> &students);
void promptAddCourseToStudent(std::vector<Student> &students);

int main()
{
    testAddStudent();
    testAddCourseToStudent();
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

void testAddCourseToStudent()
{
    std::vector<Student> students;

    // Load existing students from the file
    FileManager::loadFromFile(students);

    // Prompt user to add courses to a student
    promptAddCourseToStudent(students);

    // Save the updated student data to the file
    FileManager::saveToFile(students);

    // Clear the vector and load from file to ensure persistence
    students.clear();
    FileManager::loadFromFile(students);

    // Verify that courses were added correctly
    assert(!students.empty());
    const Student &student = students[0]; // Assuming we test with the first student
    auto semesters = student.GetTotalSemesters();
    assert(!semesters.empty());
    assert(semesters[0].size() > 0); // Ensure that courses were added

    std::cout << "testAddCourseToStudent passed." << std::endl;
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

void promptAddCourseToStudent(std::vector<Student> &students)
{
    std::string id;
    std::cout << "Enter Student ID: ";
    std::cin >> id;
    auto it = std::find_if(students.begin(), students.end(), [&](const Student &s)
                           { return s.GetStudentID() == id; });
    if (it != students.end())
    {
        int semesterIndex = (it->GetCurrentYear() - 1) * 2 + (it->GetCurrentSemester() - 1);
        int numUnits;
        std::cout << "Enter number of units for semester " << it->GetCurrentSemester() << " - year " << it->GetCurrentYear() << ": ";
        std::cin >> numUnits;
        std::cin.ignore(); // Ignore the newline character in the input buffer.
        for (int i = 0; i < numUnits; ++i)
        {
            std::string courseName;
            int creditHours, grade;
            std::cout << "Enter course name: ";
            std::getline(std::cin, courseName);
            std::cout << "Enter grade: ";
            std::cin >> grade;
            it->addCourse(semesterIndex, Course(courseName, grade));
            std::cin.ignore(); // Ignore the newline character in the input buffer for the next course
        }
        FileManager::saveToFile(students); // Save to file after adding courses
    }
    else
    {
        std::cout << "Student not found.\n";
    }
}