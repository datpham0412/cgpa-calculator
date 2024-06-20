#include "../include/Student.h"
#include <stdexcept>
#include <iostream>
// Default constructor
Student::Student()
    : itsStudentName(""), itsStudentID(""), itsCurrentYear(0), itsCurrentSemester(0)
{
    // No need to resize semesters since there are no semesters initially
}

// Parameterized constructor
Student::Student(const std::string &studentName, const std::string &studentID, int currentYear, int currentSemester)
    : itsStudentName(studentName), itsStudentID(studentID), itsCurrentYear(currentYear), itsCurrentSemester(currentSemester)
{
    int totalSemesters = (currentYear - 1) * 2 + (currentSemester - 1);
    semesters.resize(totalSemesters);
}

std::string Student::GetStudentName() const { return itsStudentName; }
std::string Student::GetStudentID() const { return itsStudentID; }
int Student::GetCurrentYear() const { return itsCurrentYear; }
int Student::GetCurrentSemester() const { return itsCurrentSemester; }
std::vector<std::vector<Course>> Student::GetTotalSemesters() const { return semesters; }
void Student::addCourse(int semesterIndex, const Course &course)
{
    if (semesterIndex >= 1 && semesterIndex <= semesters.size())
    {
        semesters[semesterIndex - 1].push_back(course); // Adjust index to match 1-based indexing
    }
    else
    {
        std::cerr << "Invalid semester index: " << semesterIndex << std::endl;
    }
}

double Student::calculateGPA(int semesterIndex) const
{
    if (semesterIndex >= 1 && semesterIndex <= semesters.size())
    {
        double totalPoints = 0;
        int totalUnits = 0;
        for (const auto &course : semesters[semesterIndex - 1]) // Adjust index to match 1-based indexing
        {
            int gpaPoint = 0;
            if (course.GetItsGrades() > 80)
                gpaPoint = 4;
            else if (course.GetItsGrades() >= 70)
                gpaPoint = 3;
            else if (course.GetItsGrades() >= 60)
                gpaPoint = 2;
            else if (course.GetItsGrades() >= 50)
                gpaPoint = 1;
            // Fail grade does not count
            if (course.GetItsGrades())
            {
                totalUnits++;
                totalPoints += gpaPoint;
            }
        }
        return (totalUnits > 0) ? (totalPoints / totalUnits) : 0;
    }
    return 0;
}

double Student::calculateCGPA() const
{
    int totalSemester = 0;
    double totalGPA = 0;
    for (int i = 1; i <= semesters.size(); ++i)
    {
        double gpa = calculateGPA(i);
        if (gpa > 0)
        {
            totalGPA += gpa;
            totalSemester++;
        }
    }
    if (totalSemester > 0)
    {
        return totalGPA / totalSemester;
    }
    else
    {
        throw std::runtime_error("No semesters available");
    }
}

void Student::saveToDatabase(SQLite::Database &db) const
{
    SQLite::Statement query(db, "INSERT OR REPLACE INTO students (studentID, studentName, currentYear, currentSemester, CGPA) VALUES (?, ?, ?, ?, ?)");
    query.bind(1, itsStudentID);
    query.bind(2, itsStudentName);
    query.bind(3, itsCurrentYear);
    query.bind(4, itsCurrentSemester);
    query.bind(5, calculateCGPA());
    query.exec();
    std::cout << "Saved Student: " << itsStudentName << ", " << itsStudentID << ", " << itsCurrentYear << ", " << itsCurrentSemester << ", " << calculateCGPA() << std::endl;

    for (int semesterIndex = 1; semesterIndex <= semesters.size(); ++semesterIndex)
    {
        for (const auto &course : semesters[semesterIndex - 1])
        {
            SQLite::Statement courseQuery(db, "INSERT INTO courses (studentID, semesterIndex, courseName, grades) VALUES (?, ?, ?, ?)");
            courseQuery.bind(1, itsStudentID);
            courseQuery.bind(2, semesterIndex);
            courseQuery.bind(3, course.GetCourseName());
            courseQuery.bind(4, course.GetItsGrades());
            courseQuery.exec();
            std::cout << "Saved Course: " << course.GetCourseName() << ", Semester: " << semesterIndex << ", Grade: " << course.GetItsGrades() << std::endl;
        }
    }
}
void Student::loadFromDatabase(SQLite::Database &db, const std::string &studentID)
{
    itsStudentID = studentID; // Add this line to set the student ID

    SQLite::Statement query(db, "SELECT studentName, currentYear, currentSemester FROM students WHERE studentID = ?");
    query.bind(1, studentID);
    if (query.executeStep())
    {
        itsStudentName = query.getColumn(0).getText();
        itsCurrentYear = query.getColumn(1).getInt();
        itsCurrentSemester = query.getColumn(2).getInt();
        std::cout << "Loaded Student: " << itsStudentName << ", " << studentID << ", " << itsCurrentYear << ", " << itsCurrentSemester << std::endl;

        int totalSemesters = (itsCurrentYear - 1) * 2 + (itsCurrentSemester - 1);
        semesters.resize(totalSemesters);

        SQLite::Statement courseQuery(db, "SELECT semesterIndex, courseName, grades FROM courses WHERE studentID = ?");
        courseQuery.bind(1, studentID);
        while (courseQuery.executeStep())
        {
            int semesterIndex = courseQuery.getColumn(0).getInt();
            std::string courseName = courseQuery.getColumn(1).getText();
            int grades = courseQuery.getColumn(2).getInt();
            addCourse(semesterIndex, Course(courseName, grades));
            std::cout << "Loaded Course: " << courseName << ", Semester: " << semesterIndex << ", Grade: " << grades << std::endl;
        }
    }
}

std::vector<Course> Student::GetCoursesForSemester(int semesterIndex) const {
    if (semesterIndex >= 1 && semesterIndex <= semesters.size()) {
        return semesters[semesterIndex - 1];
    }
    return {};
}
