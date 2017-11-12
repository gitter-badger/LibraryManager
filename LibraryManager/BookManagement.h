#ifndef BOOKMANAGEMENT_
#define  BOOKMANAGEMENT_
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#define Max 1000

//void GetBookInfo(int position); //Print info of a book (No need)
 void BookListing(); // See books
 void BookCreating(); //Create a new book
 void BookDeclaration(); // Declares the book's default value
 void BookEditing(int number); // Edit a books
 void BookDeleting(int number); // Delete a book with its position
 void SearchByBookName(char name[30]); // Search the book with its name
 void SearchByISBN(char isbn[30]); // Search the book with ISBN
 void SeeBookChanges(int number); // See the changes
 void EBSubMenu(int number); //Edit book submenu
#endif