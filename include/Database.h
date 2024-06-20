#ifndef DATABASE_H
#define DATABASE_H

#include <SQLiteCpp/SQLiteCpp.h>

void createTables(SQLite::Database &db);
void initializeDatabase(SQLite::Database &db);

#endif // DATABASE_H
