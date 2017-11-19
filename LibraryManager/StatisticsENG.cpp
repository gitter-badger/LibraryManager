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
int StudentStatisticsENG() {
	return studentcounter;
}
/* Starting StatsBasedSex function
Type : void
Input : none
Output : Return total students based sex
*/
void StatsBasedSexENG() {
	system("cls");
	int totalmale =0;
	int totalfemale = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (strcmp("Male", Sex[i]) == 0)  totalmale++;
		else if (strcmp("Female", Sex[i]) == 0) totalfemale++;
	}
	printf("============== STATISTICS STUDENTS BY SEX ===============\n");
	printf("\n");
	printf(" -> There are %d male students in database \n", totalmale);
	printf(" -> There are %d female students in database \n", totalfemale);
	_getch();
}
/* Starting BookStatistics fucntion
Type : void
Input : none
Output : return remaining book in db
*/
void BookRemainingENG() {
	printf(" -> Total books deliveried to library : %d\n\n", TotalBook);
	printf(" -> Total books which are available for borrowing : %d\n", readybook);
	_getch();
}
/* Starting BookStatsByGenre function
Type : void
Input : none
Output : listing books by genre
*/
void BookStatsByGenreENG() {
	printf("=================== STATISTICS BOOKS BY GENRES =======================\n");
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
		if (dem != 0) printf(" -> Genre %s has %d books .\n", Genre[i], dem);
	}
	printf("=====================================================================\n");
	_getch();
}
/* Starting BookInUse function
Type : void
Input : none
Output : print informations about books which are in-use
*/
void TotalBookInUseENG() {
	printf(" ================= STATISTICS BOOKS IN-USE =================\n");
	printf("   -> There are %d books which are in-use status.\n", borrowedbook);
	printf("   -> Include : ");
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
void LateStatsENG() {
	system("cls");
	printf("================== STATISTICS STUDENTS IN-LATE =================\n");
	printf("\n");
	int late = 0;
	for (int i = 0; i < studentcounter; i++)
	{
		if (returningDay[i] > estimatedDay[i] || returningMonth[i] > estimatedMonth[i] || returningYear[i] > estimatedYear[i])
		{
			late++;
			printf("  -> Library ID (borrowing) : "); puts(BorrowingID[i]);
			printf("  -> Name : "); puts(Name[i]);
			printf("  -> Currently borrowing these books : ");
			for (int j = 0; j < bookInATime[i]; i++)
			{
				printf("  -> ISBN : ");
				puts(BorrowingISBN[j]);
				printf("  -> Book name : ");
				puts(BookName[j]);
				printf("\n");
			}
		}
	}
	printf("   -> Total students in-late are %d !\n", late);
	printf("=================================================================");
	_getch();
}