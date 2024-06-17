#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Student.h"
#include <vector>

class FileManager
{
public:
// static method for saving and loading student data
    static void saveToFile(const std::vector<Student> &students);
    static void loadFromFile(std::vector<Student> &students);
};

#endif // FILEMANAGER_H