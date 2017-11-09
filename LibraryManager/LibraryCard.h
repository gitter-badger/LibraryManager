#ifndef LibraryCard_
#define LibraryCard_
#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include <stdlib.h>
//#include <Windows.h>
void CardCreatingMenu();           // Create borrowing or returning card menu
void BorrowingCardInput();   // Input dd-mm--yyyy of borrowing card
void BorrowingCardListing(); // Print borrowing card informations
void EstimatedReturnTime();  //Input or automatically calculating returning time
void ReturningCardInput();   // Input dd-mm-yyyy of returning card 
void ReturningCardListing(); // Print returning card informations
void PenaltyFee();           // Caculating the fee for each student who against the rule
#endif // !LibraryCard_
