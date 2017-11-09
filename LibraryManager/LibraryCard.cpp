#include "LibraryCard.h"
#include "BookManagement.h"
//#include "Introduction.h"
#include "StudentManagement.h"
#define Max 1000
char BorrowingID[Max][25], BorrowingISBN[Max][25], ReturningID[Max][25];
int	 BorrowingDay[Max], BorrowingMonth[Max], BorrowingYear[Max],
	 ESReturningDay[Max], ESReturningMonth[Max], ESReturningYear[Max],
	 ReturningDay[Max], ReturningMonth[Max], ReturningYear[Max];
int BookAmount[Max]; // Books amount stored books which borrowed by a student during a time
int borrowedcounter = 0; // Counting books which borrowed by students
int BorrowCardAmount;//
int ReturnCardAmount;
int cardcounter = 0; // Variable stored card amount

/*Starting CardCreating function
Type : void
Input : none

Output : created card list
*/
void CardCreating() {
	while (true)
	{
		if (cardcounter >= Max) printf("Khong du bo nho de tao the muon moi !");
		else while (cardcounter<Max)
		{
			fflush(stdin); //Clear caches
			printf("\t============ NHAP THONG TIN DOC GIA MUON ============\n");
			printf("\t-> Nhap ma doc gia can muon : ");
			gets_s(BorrowingID[cardcounter]);
			
			printf("\t=============== NHAP NGAY MUON =====================\n");
			printf("\t  -> Nhap ngay muon : ");
			scanf_s("%d", &BorrowingDay[cardcounter]);
			printf("\t  -> Nhap thang muon : ");
			scanf_s("%d", &BorrowingMonth[cardcounter]);
			printf("\t  -> Nhap nam muon : ");
			scanf_s("%d", &BorrowingYear[cardcounter]);
			printf("\t=============== NHAP THONG TIN SACH MUON ==============\n");
			printf("\t   -> Nhap so luong sach doc gia can muon : ");
			scanf_s("%d", &BookAmount[cardcounter]);
			getchar();
			for (int i = 0; i < BookAmount[cardcounter]; i++) {
				fflush(stdin);
				printf("\t  -> Nhap ma sach thu %d :  ", i + 1);
				gets_s(BorrowingISBN[i]);
				borrowedcounter++;
			}
			cardcounter++; break;
		}
		break;
	}
}
