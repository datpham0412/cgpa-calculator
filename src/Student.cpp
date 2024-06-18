#include "Student.h"
#include <stdexcept>
#include <iostream>
// Constructor:

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
    if (semesterIndex >= 0 && semesterIndex < semesters.size())
    {
        semesters[semesterIndex].push_back(course);
    }
    else
    {
        std::cerr << "Invalid semester index: " << semesterIndex << std::endl;
        if (semesterIndex >= semesters.size())
        {
            semesters.resize(semesterIndex + 1);
            semesters[semesterIndex].push_back(course);
        }
    }
}

double Student::calculateGPA(int semesterIndex) const
{
    if (semesterIndex >= 0 && semesterIndex < semesters.size())
    {
        double totalPoints = 0;
        int totalUnits = 0;
        for (const auto &course : semesters[semesterIndex])
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
    int totalSemester = semesters.size();
    int totalGPA = 0;
    for (int i = 0; i < semesters.size(); i++)
    {
        try
        {
            totalGPA += calculateGPA(i);
        }
        catch (const std::exception &e)
        {
            // Handle error
            throw;
        }
    }
    return (totalSemester > 0) ? (totalGPA / totalSemester) : throw std::runtime_error("No semesters available");
}