#ifndef MENU_H
#define MENU_H


#include <SQLiteCpp/SQLiteCpp.h>

void displayMenu();
int getUserChoice();
void processUserChoice(int choice, SQLite::Database &db);


#endif // MENU_H
