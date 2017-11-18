/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#ifndef STUDENTMANAGEMENT_
#define STUDENTMANAGEMENT_
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#define Max 1000
void StudentListing();  // See students
void StudentListingENG();
void StudentCreating();
void StudentCreatingENG(); // Create a new student
void DayCreating();
void DayCreatingENG(); // Day creating aka valid from
void DayExpired();
void DayExpiredENG();      // Expired day
void StudentDeclaration();
void StudentDeclarationENG();     // Declares the default information for student
void StudentEditing(int number);
void StudentEditingENG(int number); // Edit student with their position
void ESSubMenu(int number);
void ESSubMenuENG(int number);    // EditStudent SubMenu
void SeeLocalChanges(int number);
void SeeLocalChangesENG(int number); // See student infomation which has been changed
void SearchByID(char id[25]);
void SearchByIDENG(char id[25]);    // Search a student by their ID
void SearchByName(char name[25]);
void SearchByNameENG(char name[25]); // Search a student by their name
void StudentDeleting(int number);
void StudentDeletingENG(int number); // Delete a student with their position
#endif // !STUDENTMANAGEMENT_
	
