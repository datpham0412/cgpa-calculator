#include "../include/Course.h"

Course::Course(const std::string &courseName, int grades) : itsCourseName(courseName), itsGrades(grades) {}

std::string Course::GetCourseName() const { return itsCourseName; };
int Course::GetItsGrades() const { return itsGrades; };