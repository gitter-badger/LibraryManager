#include "LibraryCard.h"
#include "BookManagement.h"
#include "Introduction.h"
#include "StudentManagement.h"
#include "BookManagement.cpp"
#include "StudentManagement.cpp"
#include "Introduction.cpp"
#define Max 1000
char BorrowingID[Max][25], BorrowingISBN[Max][25], ReturningID[Max][25];
int	 BorrowingDay[Max], BorrowingMonth[Max], BorrowingYear[Max],
	 estimatedDay[Max], estimatedMonth[Max], estimatedYear[Max],
	 returningDay[Max], returningMonth[Max], returningYear[Max];
int bookInATime[Max]; // Books amount stored books which borrowed by a student during a time
int borrowedbook = 0; // Counting books which borrowed by students
int borrowedcard = 0;// count borrowed card
int returnedcard = 0; // count returned card
int cardcounter = 0; // Variable stored card amount

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
		printf("              -> Ten cuon sach thu %d : ", i + 1);
		for (int j = 0; j < bookcounter; j++)
			if (strcmp(BorrowingISBN[i], ISBN[j]) == 0) puts(BookName[j]);
	}
	printf("===================== DOC GIA CAN LUU Y : ================== \n");
	printf(" -> Chi duoc phep muon sach toi da 7 ngay.\n");
	printf(" -> Neu tre han thi phat 5000VND/1 ngay/1 sach.\n");
	printf(" -> Neu mat sach thi phai boi thuong 200% gia tri cuon sach do.\n");
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

	printf("=================== THONG TIN PHIEU TRA SACH CUA DOC GIA ================\n");
	printf("\n");
	printf("     -> Ma so doc gia tra sach : ");
	if (strcmp(BorrowingID[]))
}