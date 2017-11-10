#include "LibraryComponents.h"
#include "LibraryCard.h"
#include <stdio.h>
#include <conio.h>

/*Starting BorrowingCardInput function
Type : void
Input : none
Output : created borrow card
*/
void BorrowingCardInput() {
	system("cls");
	while (true)
	{
		if (borrowedcard >= Max) printf("Khong du bo nho de tao the muon moi !");
		else while (borrowedcard < Max)
		{
			fflush(stdin); //Clear caches
			printf("\t============ NHAP THONG TIN DOC GIA MUON ============\n");
			printf("\t-> Nhap ma doc gia can muon : ");
			gets_s(BorrowingID[borrowedcard]);
			
			printf("\t=============== NHAP NGAY MUON =====================\n");
			printf("\t  -> Nhap ngay muon : ");
			scanf_s("%d", &BorrowingDay[borrowedcard]);
			printf("\t  -> Nhap thang muon : ");
			scanf_s("%d", &BorrowingMonth[borrowedcard]);
			printf("\t  -> Nhap nam muon : ");
			scanf_s("%d", &BorrowingYear[borrowedcard]);
			printf("\t=============== NHAP THONG TIN SACH MUON ==============\n");
			printf("\t   -> Nhap so luong sach doc gia can muon : ");
			scanf_s("%d", &bookInATime[borrowedcard]);
			for (int i = 0; i < bookInATime[borrowedcard]; i++) {
				fflush(stdin);
				getchar();
				printf("\t  -> Nhap ma sach thu %d :  ", i + 1);
				gets_s(BorrowingISBN[i]);
				borrowedbook++;
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
void EstimatedReturnTime() {
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
void BorrowingCardListing() {
	system("cls");
	printf("=================== PHIEU MUON SACH CUA DOC GIA  ==================\n");
	printf("\n");
	printf("   -> Ma so doc gia muon sach : ");
	puts(BorrowingID[borrowedcard - 1]);
	printf("   -> Thoi gian muon sach gan nhat la : %d/%d/%d\n", BorrowingDay[borrowedcard - 1], BorrowingMonth[borrowedcard - 1], BorrowingYear[borrowedcard - 1]);
	printf("   -> Thoi gian tra sach du kien : %d/%d/%d\n", estimatedDay[borrowedcard - 1], estimatedMonth[borrowedcard - 1], estimatedYear[borrowedcard - 1]);
	printf("   -> So sach da muon : %d", bookInATime[borrowedcard - 1]);
	printf("   -> Danh sach ma sach va ten sach da muon :\n");
	for (int i = 0; i < bookInATime[borrowedcard - 1]; i++)
	{
		printf("              -> ISBN cuon sach thu %d : ", i+1);
		puts(BorrowingISBN[i]);
	/*	printf("              -> Ten cuon sach thu %d : ", i + 1);
		for (int j = 0; j < bookcounter; j++)
			if (strcmp(BorrowingISBN[i], ISBN[j]) == 0) puts(BookName[j]);
			*/
	}
	printf("===================== DOC GIA CAN LUU Y : ================== \n");
	printf(" -> Chi duoc phep muon sach toi da 7 ngay.\n");
	printf(" -> Neu tre han thi phat 5000VND/1 ngay/1 sach.\n");
	printf(" -> Neu mat sach thi phai boi thuong 200 phan tram gia tri cuon sach do.\n");
	printf(" Mong doc gia thuc hien nghiem tuc.\n");
	printf("===================================================================\n");
}
/* Starting ReturningCardInput function
Type: void
Input : none
Output: returning card created
*/
void ReturningCardInput() {
	system("cls");
	while (true)
	{
		if (returnedcard > Max) printf("Khong du bo nho de tao phieu tra sach ! Vui long xoa bot va thu lai !");
		else 
			while (returnedcard<Max)
			{
				fflush(stdin); // clear caches
				printf("=============== NHAP THONG TIN DOC GIA TRA SACH ============\n ");
				printf("     -> Nhap ma doc gia can tra sach : ");
				gets_s(ReturningID[returnedcard]);
				printf("     -> Nhap ngay tra sach thuc te : ");
				scanf_s("%d", &returningDay[returnedcard]);
				printf("     -> Nhap thang tra sach thuc te : ");
				scanf_s("%d", &returningMonth[returnedcard]);
				printf("     -> Nhap nam tra sach thuc te : ");
				scanf_s("%d", &returningYear[returnedcard]);
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
void ReturningCardListing() {
	system("cls");
	int flag = 0;
	for (int i = 0; i < borrowedcard; i++)
	{
		if (strcmp(BorrowingID[i], ReturningID[i]) == 0)
		{
			printf("================== THONG TIN PHIEU TRA SACH =================\n");
			printf("\n");
			printf("   -> Ma so doc gia : ");
			puts(BorrowingID[i]);
			printf("   -> Thoi diem muon sach : %d/%d/%d\n", BorrowingDay[i], BorrowingMonth[i], BorrowingYear[i]);
			printf("   -> Thoi diem tra sach du kien : %d/%d/%d\n", estimatedDay[i], estimatedMonth[i], estimatedYear[i]);
			printf("   -> Thoi diem tra sach thuc te : %d/%d/%d\n", returningDay[i], returningMonth[i], returningYear[i]);
			printf("   -> Danh sach cac sach da muon : \n");
			for (int j = 0; j < bookInATime[i]; j++)
			{
				printf("     -> ISBN Cuon sach thu %d : ", j + 1);
				puts(BorrowingISBN[j]);
			/*	printf("     -> Ten cuon sach thu %d : ", j + 1);
				for (int k = 0; k < bookcounter; k++)
					if (strcmp(BorrowingISBN[j], ISBN[k]) == 0)
						puts(BookName[k]);
						*/
			}
				printf("   -> So tien phat phai tra : %d VND \n",PenaltyFee(returningDay[i], returningMonth[i], returningYear[i], estimatedDay[i], estimatedMonth[i], estimatedYear[i]));
		}
	}
}
/* Starting PenaltyFee function
Type: int
Input : returningDay, returningMonth, returningYear, estimatedDay, estimated Month, estimatedYear
Output: fee for against library's rule
*/
int PenaltyFee(int returningDay, int returningMonth, int returningYear, int estimatedDay, int estimatedMonth, int estimatedYear)
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
				else
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
		// In-condition : estimatedYear < returningYear
		else
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
					fee = 5000 * daysover;
					return fee;
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
					fee = 5000 * daysover;
					return fee;
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
					}
				}
			}
		}
	}
}