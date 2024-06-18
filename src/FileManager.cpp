#include "FileManager.h"
#include <fstream>

void FileManager::saveToFile(const std::vector<Student> &students)
{
    std::ofstream file("students.txt");
    for (const auto &student : students)
    {
        file << student.GetStudentID() << "\n"
             << student.GetStudentName() << "\n"
             << student.GetCurrentYear() << "\n"
             << student.GetCurrentSemester() << "\n";

        // Print the number of semesters
        auto semesters = student.GetTotalSemesters();
        file << semesters.size() << "\n";

        for (const auto &semester : semesters)
        {
            file << semester.size() << "\n";
            for (const auto &course : semester)
            {
                file << course.GetCourseName() << "\n"
                     << course.GetItsGrades() << "\n";
            }
        }
    }
    file.close();
}