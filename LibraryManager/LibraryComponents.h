/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#ifndef LIBRARYCOMPONENTS_
#define LIBRARYCOMPONENTS_
#define Max 1000
extern char BorrowingID[Max][25], BorrowingISBN[Max][25], ReturningID[Max][25], ReturningISBN[Max][25];
extern int BorrowingDay[Max], BorrowingMonth[Max], BorrowingYear[Max],
estimatedDay[Max], estimatedMonth[Max], estimatedYear[Max],
returningDay[Max], returningMonth[Max], returningYear[Max];
extern int bookInATime[Max]; // Books amount stored books which borrowed by a student during a time
extern int remainingBook[Max]; // books amount stored books which remaining to return
extern int returnInATime[Max]; //Books amount stored book which returned by a student
extern int borrowedbook; // Counting books which borrowed by students
extern int borrowedcard;// count borrowed card
extern int returnedcard; // count returned card
extern int cardcounter; // Variable stored card amount
#endif // !LIBRARYCOMPONENTS_
