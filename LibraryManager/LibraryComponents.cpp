#include "LibraryComponents.h"
char BorrowingID[Max][25], BorrowingISBN[Max][25], ReturningID[Max][25], ReturningISBN[Max][25];
int	 BorrowingDay[Max], BorrowingMonth[Max], BorrowingYear[Max],
estimatedDay[Max], estimatedMonth[Max], estimatedYear[Max],
returningDay[Max], returningMonth[Max], returningYear[Max];
int bookInATime[Max]; // Books amount stored books which borrowed by a student during a time
int returnInATime[Max]; //Books amount stored book which returned by a student
int borrowedbook = 0; // Counting books which borrowed by students
int borrowedcard = 0;// count borrowed card
int returnedcard = 0; // count returned card
int cardcounter = 0; // Variable stored card amount