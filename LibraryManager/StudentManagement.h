#ifndef STUDENTMANAGEMENT_
#define STUDENTMANAGEMENT_
#include <stdio.h>
#include <conio.h>
#include <string.h>
const int Max = 1000;
void StudentListing();  // See students
void CreateStudent();  // Create a new student
void DayCreating(); // Day creating aka valid from
void DayExpired();  // Expired day
void StudentDeclaration(); // Declares the default information for student
void EditStudent(int number);  // Edit student with their position
void ESSubMenu(int choice); // EditStudent SubMenu
void SeeLocalChanges(int choice); // See student infomation which has been changed
void SeachByID(char id[25]);   // Search a student by their ID
void SearchByName(char name[25]);   // Search a student by their name
void DeleteStudent(int number); // Delete a student with their position
#endif // !STUDENTMANAGEMENT_
	
