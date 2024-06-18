#include "../src/FileManager.h"
#include "../src/Student.h"
#include "../src/Course.h"
#include <cassert>
#include <fstream>
#include <iostream>

void testSaveToFile()
{
    // Create sample students and courses
    Student student1("Pham Tien Dat", "103174539", 1, 2);
    Student student2("Tony Nguyen", "103171612", 1, 2);

    Course course1("Technical Software Development", 85);
    Course course2("Introduction to Artificial Intelligence", 70);

    student1.addCourse(0, course1);
    student1.addCourse(0, course2);

    student2.addCourse(0, course1);
    student2.addCourse(1, course2);

    std::vector<Student> students = {student1, student2};

    // Save to file
    FileManager::saveToFile(students);

    // Read the file and verify its contents
    std::ifstream file("students.txt");
    assert(file.is_open());

    std::string line;
    // Check student1 data
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "103174539");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "Pham Tien Dat");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "1");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "2");

    // Check student1's total semesters
    std::getline(file, line);
    std::cout << "Read line (total semesters): " << line << std::endl;
    assert(std::stoi(line) == 1); // Total semesters

    // Check student1's semester 0 courses
    std::getline(file, line);
    std::cout << "Read line (semester 0 courses): " << line << std::endl;
    assert(std::stoi(line) == 2); // Two courses in semester 0
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "Technical Software Development");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "85");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "Introduction to Artificial Intelligence");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "70");

    // Check student2 data
    std::getline(file, line);
    std::cout << "Read line (Student2 ID): " << line << std::endl;
    assert(line == "103171612");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "Tony Nguyen");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "1");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "2");

    // Check student2's total semesters
    std::getline(file, line);
    std::cout << "Read line (total semesters): " << line << std::endl;
    assert(std::stoi(line) == 2); // Total semesters

    // Check student2's semester 0 courses
    std::getline(file, line);
    std::cout << "Read line (semester 0 courses): " << line << std::endl;
    assert(std::stoi(line) == 1); // One course in semester 0
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "Technical Software Development");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "85");

    // Check student2's semester 1 courses
    std::getline(file, line);
    std::cout << "Read line (semester 1 courses): " << line << std::endl;
    assert(std::stoi(line) == 1); // One course in semester 1
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "Introduction to Artificial Intelligence");
    std::getline(file, line);
    std::cout << "Read line: " << line << std::endl;
    assert(line == "70");

    file.close();
    std::cout << "testSaveToFile passed!" << std::endl;
}

void testLoadFromFile() {
    std::vector<Student> students;

    // Load from file
    FileManager::loadFromFile(students);

    // Verify loaded data
    assert(students.size() == 2);

    const Student &student1 = students[0];
    assert(student1.GetStudentID() == "103174539");
    assert(student1.GetStudentName() == "Pham Tien Dat");
    assert(student1.GetCurrentYear() == 1);
    assert(student1.GetCurrentSemester() == 2);

    auto semesters1 = student1.GetTotalSemesters();
    assert(semesters1.size() == 1);
    assert(semesters1[0].size() == 2);
    assert(semesters1[0][0].GetCourseName() == "Technical Software Development");
    assert(semesters1[0][0].GetItsGrades() == 85);
    assert(semesters1[0][1].GetCourseName() == "Introduction to Artificial Intelligence");
    assert(semesters1[0][1].GetItsGrades() == 70);

    const Student &student2 = students[1];
    assert(student2.GetStudentID() == "103171612");
    assert(student2.GetStudentName() == "Tony Nguyen");
    assert(student2.GetCurrentYear() == 1);
    assert(student2.GetCurrentSemester() == 2);

    auto semesters2 = student2.GetTotalSemesters();
    assert(semesters2.size() == 2);
    assert(semesters2[0].size() == 1);
    assert(semesters2[0][0].GetCourseName() == "Technical Software Development");
    assert(semesters2[0][0].GetItsGrades() == 85);
    assert(semesters2[1].size() == 1);
    assert(semesters2[1][0].GetCourseName() == "Introduction to Artificial Intelligence");
    assert(semesters2[1][0].GetItsGrades() == 70);

    std::cout << "testLoadFromFile passed!" << std::endl;
}

int main()
{
    testSaveToFile();
    testLoadFromFile();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
