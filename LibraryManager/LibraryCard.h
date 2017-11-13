#ifndef LIBRARYCARD_
#define LIBRARYCARD_
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Max 1000
//#include <stdlib.h>
//#include <Windows.h>
void CardCreatingMenu();           // Create borrowing or returning card menu
void BorrowingCardInput();   // Input dd-mm--yyyy of borrowing card
void BorrowingCardListing(); // Print borrowing card informations
void EstimatedReturnTime();  //Input or automatically calculating returning time
void ReturningCardInput();   // Input dd-mm-yyyy of returning card 
void ReturningCardListing(); // Print returning card informations
 // Caculating the fee for each student who against the rule
int PenaltyFee(int returingDay, int returningMonth, int returningYear, int estimatedDay, int estimatedMonth, int estimatedYear);       
#endif// LIBRARYCARD_