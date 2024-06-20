#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
private:
    std::string itsCourseName;
    int itsGrades;

public:
    std::string GetCourseName() const;
    int GetItsGrades() const;
    Course(const std::string &courseName, int grades);
};

#endif
