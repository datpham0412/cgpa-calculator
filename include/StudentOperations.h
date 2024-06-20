#ifndef STUDENT_OPERATIONS_H
#define STUDENT_OPERATIONS_H

#include <SQLiteCpp/SQLiteCpp.h>

void addStudent(SQLite::Database &db);
void addCoursesToExistingStudent(SQLite::Database &db);
void displayStudent(SQLite::Database &db);
void listAllStudents(SQLite::Database &db);

#endif // STUDENT_OPERATIONS_H
