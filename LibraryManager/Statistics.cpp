#include "Statistics.h"
/* Starting StudentStatistics function
Type : int
Input : none
Output : Return the total students in database
*/
int StudentStatistics() {
	return studentcounter;
}
/* Starting StatsBasedSex function
Type : void
Input : none
Output : Return total students based sex
*/
void StatsBasedSex() {
	system("cls");
	int totalmale =0;
	int totalfemale = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (strcmp("Nam", Sex[i]) == 0)  totalmale++;
		else if (strcmp("Nu", Sex[i]) == 0) totalfemale++;
	}
	printf("============== THONG KE DOC GIA THEO GIOI TINH ===============\n");
	printf("Co %d so luong cac ban nam trong thu vien \n", totalmale);
	printf("Co %d so luong cac ban nu trong thu vien \n", totalfemale);
	_getch();
}
/* Starting BookStatistics fucntion
Type : void
Input : none
Output : return total book in db
*/
int BookStatistics() {
	return bookcounter;
}
/* Starting BookStatsByGenre function
Type : void
Input : none
Output : listing books by genre
*/
void BookStatByGenre() {
	printf("================== THONG KE SACH THEO THE LOAI ==================\n");
	printf("\n");
	for (int i = 0; i < bookcounter; i++)
	{
		printf("  -> The loai : ");
		puts(Genre[i]);
		for (int j = 0; j < studentcounter; j++)
		{
			if (strcmp(Genre[i], Genre[j]) == 0) puts(BookName[j]);
		}
		printf("==============================================================\n");
	}
}
/* Starting BookInUse function
Type : void
Input : none
Output : print informations about books which are in-use
*/
void TotalBookInUse() {
	printf(" ================= THONG KE SACH DANG MUON =================\n");
	printf("   -> Co %d sach dang duoc muon \n", borrowedbook);
	printf("   Bao gom cac sach sau : ");
	for (int i = 0; i < borrowedbook; i++)
	{
		if (strcmp(ISBN[i], BorrowingISBN[i]) == 0)
		{
			puts(BookName[i]);
			printf(",");
		}
	}
	_getch();
}
/* Starting LateStats function
Type : void
Input : none
Output : print info about students in late
*/
void LateStats() {
	system("cls");
	printf("================== THONG KE DOC GIA DANG TRE HAN =================\n");
	printf("\n");
	int late = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (returningDay[i] > estimatedDay[i] || returningMonth[i] > estimatedMonth[i] || returningYear[i] > estimatedYear[i])
		{
			late++;
			printf("  -> Ma doc gia : "); puts(BorrowingID[i]);
			printf("  -> Ten doc gia : "); puts(Name[i]);
			printf("  -> Hien tai dang muon cac sach : ");
			for (int j = 0; j < bookInATime[i]; i++)
			{
				printf("  -> Ma sach : ");
				puts(BorrowingISBN[j]);
				printf("  -> Ten sach : ");
				puts(BookName[j]);
				printf("\n");
			}
		}
	}
	printf("   -> Tong cong co %d doc gia dang tre han !\n", late);
	printf("=================================================================");
	_getch();
}