#ifndef STUDENTMANAGEMENT_
#define STUDENTMANAGEMENT_
#include <stdio.h>
#include <conio.h>
#include <string.h>
void StudentListing();
void AddStudent();
void EditStudent(int number);
void ESSubMenu(int choice);
void SeeLocalChanges(int choice);
void SeachByID(char id[25]);
void SearchByName(char name[25]);
void DeleteStudent(int number);
#endif // !STUDENTMANAGEMENT_

