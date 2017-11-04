#ifndef BOOKMANAGEMENT_
#define  BOOKMANAGEMENT_
const int Max = 1000;
void BookListing(); // See books
void BookDeclaration(); // Declares the book's default value
void BookEditing(int number); // Edit a books
void DeleteBook(int number); // Delete a book with its position
void SearchByBookName(char name[30]); // Search the book with its name
void SearchByISBN(char isbn[30]); // Search the book with ISBN
#endif
