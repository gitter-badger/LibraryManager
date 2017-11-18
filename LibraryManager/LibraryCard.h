/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#ifndef LIBRARYCARD_
#define LIBRARYCARD_
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Max 1000
//#include <stdlib.h>
//#include <Windows.h>
void CardCreatingMenu();
void CardCreatingMenuENG(); // Create borrowing or returning card menu
void BorrowingCardInput();
void BorrowingCardInputENG(); // Input dd-mm--yyyy of borrowing card
void BorrowingCardListing();
void BorrowingCardListingENG(); // Print borrowing card informations
void EstimatedReturnTime();
void EstimatedReturnTimeENG(); //Input or automatically calculating returning time
void ReturningCardInput();
void ReturningCardInputENG(); // Input dd-mm-yyyy of returning card
void ReturningCardListing();
void ReturningCardListingENG(); // Print returning card informations  
int PenaltyFeeENG(int returingDay, int returningMonth, int returningYear, int estimatedDay, int estimatedMonth, int estimatedYear);                           // Caculating the fee for each student who against the rule
int PenaltyFee(int returingDay, int returningMonth, int returningYear, int estimatedDay, int estimatedMonth, int estimatedYear);       
#endif// LIBRARYCARD_