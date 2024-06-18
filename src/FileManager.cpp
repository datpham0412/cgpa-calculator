#include "FileManager.h"
#include <fstream>
#include <sstream>

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
            file << semester.size() << "\n"; // Write the number of courses on that specific semester
            for (const auto &course : semester)
            {
                file << course.GetCourseName() << "\n"
                     << course.GetItsGrades() << "\n";
            }
        }
    }
    file.close();
}

void FileManager::loadFromFile(std::vector<Student> &students){
    std::ifstream file("students.txt");
    if (!file.is_open()){
        throw std::runtime_error("Could not open file!");
    }
    std::string line;
    while(std::getline(file, line)){
        std::string studentID = line;
        std::getline(file,line);
        std::string studentName = line;
        std::getline(file, line);
        int currentYear = std::stoi(line);
        std::getline(file, line);
        int currentSemester = std::stoi(line);

        Student student(studentName, studentID, currentYear, currentSemester);

        std::getline(file, line);
        int totalSemesters = std::stoi(line);
        for (int i = 0; i < totalSemesters; i++){
            std::getline(file, line);
            int numberOfCourse = std::stoi(line);
            for (int j = 0; j < numberOfCourse; j++){
                std::getline(file, line);
                std::string courseName = line;
                std::getline(file, line);
                int grades = std::stoi(line);
                Course course(courseName, grades);
                student.addCourse(i, course);
            }
        }
        students.push_back(student);
    }
    file.close();
}