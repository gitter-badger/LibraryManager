/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "Statistics.h"
#include "BookComponents.h"
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
	printf("\n");
	printf("Co %d doc gia la nam trong thu vien \n", totalmale);
	printf("Co %d doc gia la nu trong thu vien \n", totalfemale);
	_getch();
}
/* Starting BookStatistics fucntion
Type : void
Input : none
Output : return remaining book in db
*/
void BookRemaining() {
	printf(" -> Tong so sach nhap ve thu vien la : %d\n\n", TotalBook);
	printf(" -> Tong so sach san sang cho muon : %d\n", readybook);
	_getch();
}
/* Starting BookStatsByGenre function
Type : void
Input : none
Output : listing books by genre
*/
void BookStatsByGenre() {
	printf("================== THONG KE SACH THEO THE LOAI ==================\n");
	printf("\n");
	int dem;
	for (int i = 0; i < bookcounter; i++)
	{
		dem = 0;
		for (int j = 0; j < bookcounter; j++)
		{
			if (strcmp(Genre[i], Genre[j]) == 0)
			{
				if (i <= j) dem += Amount[j];
				else break;
			}
		}
		if (dem != 0) printf(" -> The loai %s co so luong sach la : %d\n", Genre[i], dem);
	}
		printf("=================================================================\n");
	_getch();
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