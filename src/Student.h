#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <string>
#include <vector>
#include <SQLiteCpp/SQLiteCpp.h>

class Student
{
private:
    std::string itsStudentName;
    std::string itsStudentID;
    int itsCurrentYear;
    int itsCurrentSemester;
    std::vector<std::vector<Course>> semesters;

public:
    Student();
    Student(const std::string &studentName, const std::string &studentID, int currentYear, int currentSemester);

    std::string GetStudentName() const;
    std::string GetStudentID() const;
    int GetCurrentYear() const;
    int GetCurrentSemester() const;
    std::vector<std::vector<Course>> GetTotalSemesters() const;
    void addCourse(int semesterIndex, const Course &course);
    double calculateGPA(int semesterIndex) const;
    double calculateCGPA() const;

    void saveToDatabase(SQLite::Database &db) const;
    void loadFromDatabase(SQLite::Database &db, const std::string &studentID);
};

#endif // STUDENT_H