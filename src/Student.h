#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <string>
#include <vector>

class Student
{
private:
    std::string itsStudentName;
    std::string itsStudentID;
    int itsCurrentYear;
    int itsCurrentSemester;
    std::vector<std::vector<Course>> semesters;

public:
    Student(const std::string &studentName, const std::string &studentID, int currentYear, int currentSemester);

    std::string GetStudentName() const;
    std::string GetStudentID() const;
    int GetCurrentYear() const;
    int GetCurrentSemester() const;
    void addCourse(int semesterIndex, const Course &course);
    double calculateGPA(int semesterIndex) const;
    double calculateCGPA() const;
};

#endif // STUDENT_H