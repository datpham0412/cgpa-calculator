#include "../src/Student.h"
#include "../src/Course.h"
#include <cassert>
#include <iostream>
#include <vector>

// Test Student Constructor:
void TestStudentConstructor()
{
    Student student1("Pham Tien Dat", "103174539", 4, 1);
    assert(student1.GetStudentName() == "Pham Tien Dat");
    assert(student1.GetStudentID() == "103174539");
    assert(student1.GetCurrentYear() == 4);
    assert(student1.GetCurrentSemester() == 1);
    std::cout << "Test constructor passed" << std::endl;
}

// Test Student Getter Method:
void TestStudentGetterMethod()
{
    Student student2("Ho Vu Phuong Anh", "103171611", 4, 2);
    assert(student2.GetStudentName() == "Ho Vu Phuong Anh");
    assert(student2.GetStudentID() == "103171611");
    assert(student2.GetCurrentYear() == 4);
    assert(student2.GetCurrentSemester() == 2);
    std::cout << "Test Student Getter Method passed" << std::endl;
}

// Test Get Total Semesters:
void TestGetTotalSemester()
{
    Student student1("Christiano Ronaldo", "1987515384", 5, 1);
    Course course1("Energy and Motion", 79);
    Course course2("Managing Software Projects", 85);
    auto semesters = student1.GetTotalSemesters();
    assert(semesters.size() == 8); // Initially no semester are founded
    student1.addCourse(1, course1);
    student1.addCourse(1, course2);
    // Add courses and verify
    semesters = student1.GetTotalSemesters();
    assert(semesters.size() == 8);
    assert(semesters[0].size() == 2);
    assert(semesters[0][0].GetCourseName() == "Energy and Motion");
    assert(semesters[0][1].GetCourseName() == "Managing Software Projects");

    std::cout << "Test Get Total Semester Method passed" << std::endl;
}

// Test Add Course Method:
void TestAddCourseMethod()
{
    Student student3("Nguyen Dang Khanh Toan", "103123571", 3, 2);
    Course course1("Introduction to Programming", 95);
    student3.addCourse(1, course1);
    std::cout << "Test GPA score: " << student3.calculateGPA(1) << std::endl;
    assert(student3.calculateGPA(1) == 4);
    std::cout << "Test add course passed" << std::endl;
}

// Test Calculate GPA:
void TestCalculateGPA()
{
    Student student4("Dat Pham", "103174539", 4, 1);
    Course course1("Object Oriented Programming", 90);
    Course course2("User Centred Design", 65);
    student4.addCourse(1, course1);
    student4.addCourse(1, course2);
    assert(student4.calculateGPA(1) == 3);
    std::cout << "Test calculate GPA passed" << std::endl;
}

// Test Calculate CGPA:
void TestCalculateCGPA()
{
    Student student5("Dep trai va dang cap", "1250605606", 5, 1);
    Course course1("Calculus", 100);
    Course course2("Linear Algebra", 99);
    Course course3("Electronic and electromagnetism", 67);
    student5.addCourse(1, course1);
    student5.addCourse(2, course2);
    student5.addCourse(3, course3);
    double cGPA = student5.calculateCGPA();
    assert(cGPA > 0); // Simple check to ensure CGPA is calculated
    std::cout << "Test calculate CGPA passed" << std::endl;
}

int main()
{
    TestStudentConstructor();
    TestStudentGetterMethod();
    TestGetTotalSemester();
    TestAddCourseMethod();
    TestCalculateGPA();
    TestCalculateCGPA();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
