#ifndef LIBRARYCOMPONENTS_
#define LIBRARYCOMPONENTS_
#define Max 1000
extern char BorrowingID[Max][25], BorrowingISBN[Max][25], ReturningID[Max][25];
extern int BorrowingDay[Max], BorrowingMonth[Max], BorrowingYear[Max],
estimatedDay[Max], estimatedMonth[Max], estimatedYear[Max],
returningDay[Max], returningMonth[Max], returningYear[Max];
extern int bookInATime[Max]; // Books amount stored books which borrowed by a student during a time
extern int borrowedbook; // Counting books which borrowed by students
extern int borrowedcard;// count borrowed card
extern int returnedcard; // count returned card
extern int cardcounter; // Variable stored card amount
#endif // !LIBRARYCOMPONENTS_
