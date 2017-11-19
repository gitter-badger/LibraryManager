/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#ifndef BOOKMANAGEMENT_
#define  BOOKMANAGEMENT_
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#define Max 1000
//void GetBookInfo(int position); //Print info of a book (No need)
 void BookListing();
 void BookListingENG(); // See books
 void BookCreating();
 void BookCreatingENG(); //Create a new book
 void BookDeclaration();
 void BookDeclarationENG();    // Declares the book's default value
 void BookEditing(int number);
 void BookEditingENG(int number);         // Edit a books
 void BookDeleting(int number);
 void BookDeletingENG(int number);     // Delete a book with its position
 void SearchByBookName(char name[30]);
 void SearchByBookNameENG(char name[30]); // Search the book with its name
 void SearchByISBN(char isbn[30]);
 void SearchByISBNENG(char isbn[30]); // Search the book with ISBN
 void SeeBookChanges(int number);
 void SeeBookChangesENG(int number); // See the changes
 void EBSubMenu(int number);
 void EBSubMenuENG(int number); //Edit book submenu
#endif