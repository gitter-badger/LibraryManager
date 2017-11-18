/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "LibraryComponents.h"
#include "LibraryCard.h"
#include <stdio.h>
#include <conio.h>
#include "Statistics.h"
#include "BookComponents.h"
#include "StudentComponents.h"
/*Starting BorrowingCardInput function
Type : void
Input : none
Output : created borrow card
*/
void BorrowingCardInputENG() {
	system("cls");
	while (true)
	{
		if (borrowedcard >= Max) printf("No memory to create a borrowing card !");
		else while (borrowedcard < Max)
		{
			fflush(stdin); //Clear caches
			do {
				int flag = 0;
				printf("\t============ BORROWING CARD INFORMATIONS ============\n");
				printf("\t-> Input borrowing ID  : ");
				gets_s(BorrowingID[borrowedcard]);
				for (int i = 0; i<studentcounter; i++)
					if (strcmp(BorrowingID[borrowedcard], LibraryID[i]) == 0)
					{
						flag = 1; // already in db
						break;
					}
				if (flag == 1) break;
				else if (flag == 0) {
					printf(" -> No student info found in database. Please create or update students database ! \n");
					Sleep(1000);
					system("cls");
					continue;
				}
			} while (true);

			// input borrowing day	
			printf("\n");
			printf("\t=============== NHAP NGAY MUON ========================\n");
			printf("\t  -> Nhap ngay muon : ");
			scanf_s("%d", &BorrowingDay[borrowedcard]);
			printf("\t  -> Nhap thang muon : ");
			scanf_s("%d", &BorrowingMonth[borrowedcard]);
			printf("\t  -> Nhap nam muon : ");
			scanf_s("%d", &BorrowingYear[borrowedcard]);
			printf("\n");
			printf("\t=============== NHAP THONG TIN SACH MUON ==============\n");
			do
			{
				printf("\n");
				printf("\t  -> Nhap so luong sach doc gia can muon : ");
				scanf_s("%d", &bookInATime[borrowedcard]);
				readybook -= bookInATime[borrowedcard];
				borrowedbook += bookInATime[borrowedcard];
				remainingBook[borrowedcard] = bookInATime[borrowedcard];
				if (bookInATime[borrowedcard] > bookcounter)
				{
					printf("  -> So sach muon vuot qua du lieu thu vien ! Vui long thu lai !\n");
					Sleep(1000);
					continue;
				}
				else break;
			} while (true);

			getchar();
			for (int i = 0; i < bookInATime[borrowedcard]; i++) {
				fflush(stdin);
				do
				{
					int flag = 0;
					printf("\t  -> Nhap ma sach thu %d :  ", i + 1);
					gets_s(BorrowingISBN[i]);
					for (int j = 0; j < bookcounter; j++)
					{
						if (strcmp(BorrowingISBN[i], ISBN[j]) == 0)
						{
							flag = 1; // already in db
							Amount[j]--;
							break;
						}
					}
					if (flag == 1)
					{
						printf(" -> Them sach vao the muon thanh cong ! \n");
						Sleep(1000);
						break;
					}

					else if (flag == 0)
					{
						printf(" -> Thong tin sach khong ton tai trong thu vien ! Vui long tao moi hoac cap nhat !\n");
						Sleep(1000);
						system("cls");
						continue;
					}

				} while (true);
			}
			borrowedcard++; break;
		}
		break;
	}
}
/* Starting EstimatedReturnTime function
Type : void
Input : none
Output : Estimated returning time
*/
void EstimatedReturnTimeENG() {
	int realreturnday;
	switch (BorrowingMonth[borrowedcard - 1])
	{
	case 1: case 3: case 5:case 7: case 8: case 10: case 12: realreturnday = 31; break;
	case 4: case 6: case 9:case 11: realreturnday = 30; break;
	case 2: if (BorrowingYear[borrowedcard - 1] % 400 == 0 || (BorrowingYear[borrowedcard - 1] % 4 == 0 && BorrowingYear[borrowedcard - 1] % 100 != 0))
		realreturnday = 29;
			else realreturnday = 28; break;
	default: realreturnday = NULL;
		break;
	}
	// Determining Estimated time
	if (BorrowingDay[borrowedcard - 1] == realreturnday) // Mean if borrows in last day of a month
	{
		estimatedDay[borrowedcard - 1] = 6; // Maximum days for borrowing are 7 days
		estimatedMonth[borrowedcard - 1] = BorrowingMonth[borrowedcard - 1] + 1;
		estimatedYear[borrowedcard - 1] = BorrowingYear[borrowedcard - 1];
	}
	else {
		estimatedDay[borrowedcard - 1] = BorrowingDay[borrowedcard - 1] + 6;
		if (estimatedDay[borrowedcard - 1] > realreturnday)
		{
			estimatedDay[borrowedcard - 1] = estimatedDay[borrowedcard - 1] - realreturnday;
			estimatedMonth[borrowedcard - 1] = BorrowingMonth[borrowedcard - 1] + 1;
		}
		else estimatedMonth[borrowedcard - 1] = BorrowingMonth[borrowedcard - 1];
		estimatedYear[borrowedcard - 1] = BorrowingYear[borrowedcard - 1];
	}
	// Processing for days approx. the end of a year
	if (estimatedMonth[borrowedcard - 1] > 12)
	{
		estimatedMonth[borrowedcard - 1] = 1;
		estimatedYear[borrowedcard - 1] = BorrowingYear[borrowedcard - 1] + 1;
	}
}
/* Starting BorrowingCardListing function
Type : void
Input : none
Output : print BorrowingCard info
*/
void BorrowingCardListingENG() {
	system("cls");
	if (borrowedcard == 0) printf(" -> There is empty number of students who are in-borrowing status now. !\n");
	else
	{
		printf("  -> Total: %d borrowing cards \n\n ", borrowedcard);
		printf("=================== BORROWING CARDS INFORMATIONS LISTING  ==================\n");
		printf("\n");
		for (int i = 0; i < borrowedcard; i++)
		{
			printf("================ BORROWING CARD INFORMATIONS OF STUDENT %d ================\n", i + 1);
			printf("   -> Library borrowing ID : ");
			puts(BorrowingID[i]);
			printf("   -> Student name : ");
			for (int j = 0; j < studentcounter; j++)
				if (strcmp(BorrowingID[i], LibraryID[j]) == 0)
				{
					puts(Name[j]);
					break;
				}
			printf("   -> Time borrowed recently : %d/%d/%d\n", BorrowingDay[i], BorrowingMonth[i], BorrowingYear[i]);
			printf("   -> Estimated time returning : %d/%d/%d\n", estimatedDay[i], estimatedMonth[i], estimatedYear[i]);
			printf("   -> Number of borrowed books : %d\n", bookInATime[i]);
			printf("   -> LISTING OF NAME OF BORROWED BOOKS :\n");
			for (int k = 0; k < bookInATime[i]; k++)
			{
				printf("              -> ISBN of book %d : ", k + 1);
				puts(BorrowingISBN[k]);
				printf("              -> Name of book %d  : ", k + 1);
				for (int l = 0; l < bookcounter; l++)
					if (strcmp(BorrowingISBN[k], ISBN[l]) == 0) puts(BookName[l]);
			}
			printf("\n");
			printf("====================================================================\n");
		}
		printf("===================== ATTENTION: ========================= \n");
		printf(" -> Students are only allowed to borrow with up to 7 days.\n");
		printf(" -> If in-late, a penalty fee will begin with 5000 VND/1 day.\n");
		printf(" -> If lost, fee to pay is 200 percents of book's price.\n");

		printf("===================================================================\n");
	}
	_getch();
}
/* Starting ReturningCardInput function
Type: void
Input : none
Output: returning card created
*/
void ReturningCardInputENG() {
	while (true)
	{
		int brlocation;
		system("cls");
		if (returnedcard > Max) printf("-> No memory to create returning card ! Please free memory or restart this app!");
		else
			while (returnedcard<Max)
			{
				fflush(stdin); // clear caches
				printf("=============== RETURNING CARD INFORMATIONS ============\n ");
				do
				{
					int flag = 0;
					printf("     -> Input returning ID of student : ");
					gets_s(ReturningID[returnedcard]);
					for (int i = 0; i < borrowedcard; i++)
					{
						if (strcmp(ReturningID[returnedcard], BorrowingID[i]) == 0)
						{
							flag = 1; // already in db
							brlocation = i;  // point the borrower location
							break;
						}
					}
					if (flag == 1)
					{
						break;
					}
					else
					{
						printf("  -> No borrowing information found! Seem this student didn't borrow any book yet. Exiting... \n");
						Sleep(1000);
						system("cls");
						continue;
					}
				} while (true);

				printf("     -> Input real-returning day : ");
				scanf_s("%d", &returningDay[returnedcard]);
				printf("     -> Input real-returning month : ");
				scanf_s("%d", &returningMonth[returnedcard]);
				printf("     -> Input real-returning year : ");
				scanf_s("%d", &returningYear[returnedcard]);
				do
				{
					printf("\n");
					//int flag = 0;
					printf("     -> Input number of books for returning : ");
					scanf_s("%d", &returnInATime[returnedcard]);
					readybook += returnInATime[returnedcard];
					remainingBook[returnedcard] = bookInATime[returnedcard] - returnInATime[returnedcard];
					if (remainingBook[returnedcard]<0)
						continue;
					else if (remainingBook[returnedcard] == 0) // return all books in a time
					{
						for (int j = 0; j < returnInATime[returnedcard]; j++)
						{
							printf("   -> Input ISBN of book %d : ", j + 1);
							getchar();
							gets_s(ReturningISBN[j]);
						}
						printf("  -> Returned successfully ! \n");
						Sleep(1000);
						borrowedcard--;
						break;
					}
					else
					{
						for (int j = 0; j < returnInATime[returnedcard]; j++)
						{
							printf("   -> Input ISBN of book %d : ", j + 1);
							getchar();
							gets_s(ReturningISBN[j]);
						}
					}
				} while (true);
				returnedcard++; break;
			}
		break;
	}
}
/* Starting ReturningCardListing function
Type : void
Input : none
Output : print ReturningCard info
*/
void ReturningCardListingENG() {
	system("cls");
	if (returnedcard == 0) printf("  -> There is empty number of students who are in-returning status now ! \n");
	else
	{
		int flag = 0;
		for (int i = 0; i < returnedcard; i++)
		{
			if (strcmp(BorrowingID[i], ReturningID[i]) == 0)
			{
				printf("================== RETURNING CARD INFORMATIONS OF STUDENT =================\n");
				printf("\n");
				printf("   -> Library ID of student : ");
				puts(BorrowingID[i]);
				printf("   -> Time borrowed : %d/%d/%d\n", BorrowingDay[i], BorrowingMonth[i], BorrowingYear[i]);
				printf("   -> Estimated returning time : %d/%d/%d\n", estimatedDay[i], estimatedMonth[i], estimatedYear[i]);
				printf("   -> Real returning time : %d/%d/%d\n", returningDay[i], returningMonth[i], returningYear[i]);
				printf("   -> Total books borrowed : %d", bookInATime[i]);
				printf("   -> List of book's name borrowed : \n");
				for (int j = 0; j < bookInATime[i]; j++)
				{
					printf("     -> ISBN of book %d : ", j + 1);
					puts(BorrowingISBN[j]);
					printf("     -> Name of book %d : ", j + 1);
					for (int k = 0; k < bookcounter; k++)
						if (strcmp(BorrowingISBN[j], ISBN[k]) == 0)
							puts(BookName[k]);

				}
				printf("   -> Penalty fee : %d VND \n", PenaltyFee(returningDay[i], returningMonth[i], returningYear[i], estimatedDay[i], estimatedMonth[i], estimatedYear[i]));
				printf("========================================================================\n");
				flag = 1; break;
			}
		}
		//if (flag = 0) printf("Khong co doc gia tra sach ! ");
	}
	_getch();
}
/* Starting PenaltyFee function
Type: int
Input : returningDay, returningMonth, returningYear, estimatedDay, estimated Month, estimatedYear
Output: fee for against library's rule
*/
int PenaltyFeeENG(int returningDay, int returningMonth, int returningYear, int estimatedDay, int estimatedMonth, int estimatedYear)
{
	// Initiating variables : daysover(days over rules), fee(money for paying), distance1(between 2 returning time),
	int daysover, fee, distance1, distance2;
	// In-condition : estimatedYear = returningYear, estimatedMonth = returningMonth
	if (estimatedYear == returningYear) // Same year
	{
		if (estimatedMonth == returningMonth)  // Same month
		{
			if (estimatedDay >= returningDay) return 0;
			else
			{
				daysover = returningDay - estimatedDay;
				fee = daysover * 5000;
				return fee;
			}
		}
		// In-condition: estimatedMonth != returningMonth
		else if (estimatedMonth < returningMonth)
		{
			// If estimatedMonth = 2
			if (estimatedMonth == 2)
			{
				// Check if leap year
				if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)
				{
					// Caculating distance from	returningDay of returningMonth to estimatedDay of estimatedMonth
					distance1 = returningDay;
					int i = returningMonth - 1;
					for (i; i > estimatedMonth; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 = distance1 + 31;
						else distance1 = distance1 + 30;
					}
					// Nam nhuan nen so ngay qua han bang distance + (29 - estimatedDay)
					daysover = distance1 + (29 - estimatedDay);
					fee = 5000 * daysover;
					return fee;
				}
				else // Not a leap year
				{
					distance1 = returningDay;
					int i = returningMonth - 1;
					for (i; i > estimatedMonth; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
						else distance1 += 30;
					}
					// Nam khong nhuan nen so ngay qua han bang distance + (28-estimatedDay)
					daysover = distance1 + (28 - estimatedDay);
					fee = 5000 * daysover;
					return fee;
				}
			}
			else //estimatedMonth != 2
			{
				// if returning month in 1,3,5,7,8,10,12 which has 31 days
				if (estimatedMonth == 1 || estimatedMonth == 3 || estimatedMonth == 5 || estimatedMonth == 7 || estimatedMonth == 8 || estimatedMonth == 10 || estimatedMonth == 12)
				{
					// Check if leap year
					if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)
					{
						distance1 = returningDay;
						int i = returningMonth - 1;
						for (i; i > estimatedMonth; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 29;
							else distance1 += 30;
						}
						daysover = distance1 + (31 - estimatedDay);
						fee = 5000 * daysover;
						return fee;
					}
					else // not a leap year
					{
						distance1 = returningDay;
						int i = returningMonth - 1; // check next month
						for (i; i > estimatedMonth; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 28;
							else distance1 += 30;
						}
						daysover = distance1 + (31 - estimatedDay);
						fee = daysover * 5000;
						return fee;
					}
				}
				else // if in month 4,6,9,11  which has 30 days
				{
					if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)
					{
						distance1 = returningDay;
						int i = returningMonth - 1;
						for (i; i > estimatedMonth; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 29;
							else distance1 += 30;
						}
						daysover = distance1 + (30 - estimatedDay);
						fee = 5000 * daysover;
						return fee;
					}
					else // not leap year
					{
						distance1 = returningDay;
						int i = returningMonth - 1;
						for (i; i > estimatedMonth; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 28;
							else distance1 += 30;
						}
						daysover = distance1 + (30 - estimatedDay);
						fee = 5000 * daysover;
						return fee;
					}
				}
			}
		}
	}
	else// In-condition : estimatedYear < returningYear
	{
		distance2 = 0;
		// calculating distance from estimatedDay, estimatedMonth to 31/12/estimatedYear.
		if (estimatedMonth == 2) // if estimatedMonth = 2
		{
			//check leap year
			if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)
			{
				// calculating distance from returningDay of returningMonth to estimatedDay of estimatedMonth
				int i = estimatedMonth + 1;
				for (i; i <= 12; i++)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;
					else if (i == 2) distance2 += 29;
					else distance2 += 30;
				}
				daysover = distance2 + (29 - estimatedDay);
			}
			else // not a leap year
			{
				int i = estimatedMonth + 1;
				for (i; i <= 12; i++)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;
					else if (i == 2) distance2 += 28;
					else distance2 += 30;
				}
				daysover = distance2 + (28 - estimatedDay);
			}
		}
		else // if estimatedMonth != 2
		{
			// if estimatedmonth in 1,3,5,7,8,10,12
			if (estimatedMonth == 1 || estimatedMonth == 3 || estimatedMonth == 5 || estimatedMonth == 7 || estimatedMonth == 8 || estimatedMonth == 10 || estimatedMonth == 12)
			{
				// check leap year
				if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)
				{
					int i = estimatedMonth + 1;
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;
						else if (i == 2) distance2 += 29;
						else distance2 += 30;
					}
					daysover = distance2 + (31 - estimatedDay);
				}
				else // not a leap year
				{
					int i = estimatedMonth + 1;
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;
						else if (i == 2) distance2 += 28;
						else distance2 += 30;
					}
					daysover = distance2 + (31 - estimatedDay);
				}
			}
			else // estimatedmonth in 4,6,9,11
			{
				// check leap year
				if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)
				{
					int i = estimatedMonth + 1;
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;
						else if (i == 2) distance2 += 29;
						else distance2 += 30;
					}
					daysover = distance2 + (30 - estimatedDay);
				}
				else //not a leap year
				{
					int i = estimatedMonth + 1;
					for (i; i <= 12; i++)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;
						else if (i == 2) distance2 += 28;
						else distance2 += 30;
					}
					daysover = distance2 + (30 - estimatedDay);
				}
			}
		}
		// calculating distance from 1/1/returningYear to returningDay/returningMonth/returningYear
		int daysover2 = 0;
		// check leap year
		if ((returningYear % 4 == 0 && returningYear % 100 != 0) || returningYear % 400 == 0)
		{
			if (returningMonth == 1) daysover2 = returningDay; // Jan
			else if (returningMonth == 2) daysover2 = 31 + returningDay; // Feb 
			else // all except Jan, Feb
			{
				daysover2 = returningDay;
				int i = returningMonth - 1;
				for (i; i > 0; i--)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysover2 += 31;
					else if (i == 2) daysover2 += 29;
					else daysover2 += 30;
				}
			}
		}
		else // not a leap year
		{
			if (returningMonth == 1) daysover2 = returningDay;
			else if (returningMonth == 2) daysover2 = 31 + returningDay;
			else // except Jan, Feb
			{
				daysover2 = returningDay;
				int i = returningMonth - 1;
				for (i; i > 0; i--)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysover2 += 31;
					else if (i == 2) daysover2 += 28;
					else daysover2 += 30;
				}
			}
		}
		// calculating  days between estimatedYear -> returningYear
		int daysover3 = 0;
		for (int i = returningYear; i > estimatedYear; i--)
		{
			// if leap year
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) daysover3 += 366;
			else daysover3 += 365;
		}
		// Total days over :
		int totaldaysover = daysover + daysover2 + daysover3;
		fee = 5000 * totaldaysover;
		return fee;
	}
}
/* Starting CardCreatingMenu function
Type : void
Input : none
Output : library card submenu
*/
void CardCreatingMenuENG() {
	while (true)
	{
		system("cls");
		printf("================ LIBRARY CARD MENU ================\n");
		printf("   -> 1. Create borrowing card                     \n");
		printf("   -> 2. Create returning card                     \n");
		printf("   -> 3. See borrowed list                         \n");
		printf("   -> 4. See returned list                         \n");
		printf("   -> 0. Go back to menu                           \n");
		printf("===================================================\n");
		int choice;
		printf("   -> Input your choice : ");
		scanf_s("%d", &choice);
		getchar();
		if (choice == 0) break;
		else if (choice == 1)
		{
			BorrowingCardInput();
			EstimatedReturnTime();
			break;
		}
		else if (choice == 2)
		{
			ReturningCardInput();
			// EstimatedReturnTime(); no need
			break;
		}
		else if (choice == 3)
		{
			BorrowingCardListing(); break;
		}
		else if (choice == 4)
		{
			ReturningCardListing(); break;
		}
		else
		{
			printf("Lua chon khong hop le ! Vui long thu lai !\n");
			Sleep(500);
		}
	}
}
