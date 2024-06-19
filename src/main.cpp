#include <iostream>
#include <vector>
#include "Student.h"
#include "FileManager.h"

void addStudent(std::vector<Student> &students);
void addCourseToStudent(std::vector<Student> &students);
void displayStudentDetails(const std::vector<Student> &students);
void menu();
int main()
{
    menu();
    return 0;
}

void addStudent(std::vector<Student> &students)
{
    std::string studentID, studentName;
    int currentYear, currentSemester;
    std::cout << "\nEnter student ID: \n> ";
    std::cin >> studentID;
    std::cout << "\nEnter student name: \n> ";
    std::cin.ignore(); // Ignore the newline character in the input buffer.
    std::getline(std::cin, studentName);
    std::cout << "\nWhich year are you in at university?: \n> ";
    std::cin >> currentYear;
    std::cout << "\nEnter current semester (1 or 2): \n> ";
    std::cin >> currentSemester;
    students.push_back(Student(studentName, studentID, currentYear, currentSemester));
    FileManager::saveToFile(students);
    std::cout << "Student added successfully!!!";
}