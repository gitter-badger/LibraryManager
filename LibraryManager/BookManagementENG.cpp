/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "BookManagement.h"
#include "BookComponents.h"
/* Starting GetBookInfo function
Input: book position
Output: Info
*/
/* Starting BookDeclaration for default database.
Input: informations on arrays
Output : informations stored for max 1 books
*/
void BookDeclarationENG() {
	while (true)
	{
		if (bookcounter > Max) printf(" -> No memory to create book !");
		else while (bookcounter<Max)
		{
			printf("================ BOOK INFORMATIONS %d ==============\n", bookcounter + 1);
			fflush(stdin);//clear caches
			getchar();
			printf("    -> ISBN of book %d : ", bookcounter + 1);

			gets_s(ISBN[bookcounter]);
			printf("    -> Name of book %d : ", bookcounter + 1);
			gets_s(BookName[bookcounter]);
			printf("    -> Author of book %d : ", bookcounter + 1);
			gets_s(Author[bookcounter]);
			printf("    -> Producer of book %d : ", bookcounter + 1);
			gets_s(Producer[bookcounter]);
			printf("    -> Year producing of book %d : ", bookcounter + 1);
			gets_s(YearProducing[bookcounter]);
			printf("    -> Genre of book %d : ", bookcounter + 1);
			gets_s(Genre[bookcounter]);
			printf("    -> Price of book(VND) %d : ", bookcounter + 1);
			scanf_s("%d", &Cost[bookcounter]);
			printf("    -> Delivery amount of book  : ");
			scanf_s("%d", &Amount[bookcounter]);
			TotalBook += Amount[bookcounter];
			readybook += Amount[bookcounter];
			bookcounter++; break;
		}
		if (bookcounter >= 1) break; //Declaring max 3 books
	}
}
/* Starting BookCreating function
Input : none
Output : book informations
*/
void BookCreatingENG() {
	while (true)
	{
		int choice;
		printf("======================= BOOK CREATING MENU ========================\n");
		printf("                 -> 1. Creating a new book                         \n");
		printf("                 -> 2. Go back                                     \n");
		printf("===================================================================\n");
		printf("      -> Input your choice : ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			if (bookcounter > Max) printf(" -> No memory to create or edit a book !");
			else while (bookcounter < Max)
			{
				printf("================== BOOK INFORMATIONS %d ==================\n", bookcounter + 1);
				fflush(stdin);
				getchar();
				printf("    -> Input ISBN : ");
				gets_s(ISBN[bookcounter]);
				printf("    -> Input book's name : ");
				gets_s(BookName[bookcounter]);
				printf("    -> Input book's author : ");
				gets_s(Author[bookcounter]);
				printf("    -> Input producer : ");
				gets_s(Producer[bookcounter]);
				printf("    -> Input year producing : ");
				gets_s(YearProducing[bookcounter]);
				printf("    -> Input genre : ");
				gets_s(Genre[bookcounter]);
				printf("    -> Input price (VND) : ");
				scanf_s("%d", &Cost[bookcounter]);
				printf("    -> Input delivery amount : ");
				scanf_s("%d", &Amount[bookcounter]);
				TotalBook += Amount[bookcounter];
				readybook += Amount[bookcounter];
				bookcounter++;
				Sleep(1000);
				printf(" -> Book created successfully !\n");
				Sleep(500);
				break;
			}
			// continue;
		}
		else if (choice == 2) break;
		break;
	}
}
/* Starting BookListing function
Input : none
Output : listed books
*/
void BookListingENG() {
	printf("\t\t============= LISTING BOOKS IN LIBRARY =============\n\n");
	if (bookcounter <= 0) printf("-> Oops, something was wrong. The library book database is seem to be empty.\n Please add something..\n");
	for (int i = 0; i < bookcounter; i++)
	{
		printf("\n");
		printf(" ================== INFORMATIONS OF BOOK %d =======================\n", i + 1);
		printf("   -> ISBN : ");
		puts(ISBN[i]);
		printf("   -> Name : ");
		puts(BookName[i]);
		printf("   -> Author : ");
		puts(Author[i]);
		printf("   -> Producer : ");
		puts(Producer[i]);
		printf("   -> Year producing : ");
		puts(YearProducing[i]);
		printf("   -> Genre : ");
		puts(Genre[i]);
		printf("   -> Price : %d VND \n", Cost[i]);
		printf("   -> Amount available in library : %d\n", Amount[i]);
	}
	_getch();
}
/* Starting BookEditing function
Input : book position
Output: listed books available
*/
void BookEditingENG(int number) {
	if (number > 0 && number <= bookcounter)
	{
		int choice;
		printf("==================== BOOK EDITING MENU ===================\n");
		printf("    1. Edit ISBN\n");
		printf("    2. Edit book's name \n");
		printf("    3. Edit book's author \n");
		printf("    4. Edit producer \n");
		printf("    5. Edit year producing \n");
		printf("    6. Edit genre  \n");
		printf("    7. Edit price \n");
		printf("    8. Edit amount\n");
		printf("==================================================\n");
		printf(" -> Input your choice : ");
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1: {
			fflush(stdin);
			char NewISBN[25];
			printf(" -> Input new ISBN : ");
			gets_s(NewISBN);
			strcpy_s(ISBN[number - 1], NewISBN);
			Sleep(1000);
			printf(" -> ISBN edited successfully !");
			Sleep(500);
		} break;
		case 2: {
			fflush(stdin);
			char NewBookName[25];
			printf(" -> Input new name : ");
			gets_s(NewBookName);
			strcpy_s(BookName[number - 1], NewBookName);
			Sleep(1000);
			printf(" -> Name edited successfully !");
			Sleep(500);
		} break;
		case 3: {
			fflush(stdin);
			char NewAuthor[25];
			printf(" -> Input new author : ");
			gets_s(NewAuthor);
			strcpy_s(Author[number - 1], NewAuthor);
			Sleep(1000);
			printf(" -> Author edited successfully !");
			Sleep(500);
		} break;
		case 4: {
			fflush(stdin);
			char NewProducer[25];
			printf(" -> Input new producer : ");
			gets_s(NewProducer);
			strcpy_s(Producer[number - 1], NewProducer);
			Sleep(1000);
			printf(" -> Producer edited successfully !");
			Sleep(500);
		} break;
		case 5: {
			fflush(stdin);
			char NewYearProducing[25];
			printf(" -> Input new year producing : ");
			gets_s(NewYearProducing);
			strcpy_s(YearProducing[number - 1], NewYearProducing);
			Sleep(1000);
			printf(" -> Year producing edited successfully !");
			Sleep(500);
		} break;
		case 6: {
			fflush(stdin);
			char NewGenre[25];
			printf(" -> Input new genre : ");
			gets_s(NewGenre);
			strcpy_s(Genre[number - 1], NewGenre);
			Sleep(1000);
			printf(" -> Genre edited successfully !");
			Sleep(500);
		} break;
		case 7: {
			fflush(stdin);
			int newcost;
			printf(" -> Input new price : ");
			scanf_s("%d", &newcost);
			Cost[number - 1] = newcost;
			Sleep(1000);
			printf(" -> Price edited successfully !");
			Sleep(500);
		} break;
		case 8:
		{
			int sl;
			TotalBook -= Amount[number - 1];
			printf(" -> Input new delivery amount : ");
			scanf_s("%d", &sl);
			Amount[number - 1] = sl;
			TotalBook += Amount[number - 1];
			Sleep(1000);
			printf(" -> Delivery amount edited successfully !");
			Sleep(500);
			break;
		}
		default:
		{
			printf(" Invaild choice ! Please try again ..");
			Sleep(500);
			break;
		}

		}
	}
	else
	{
		printf("Something went wrong.. Please try again with a valid book position.. \n");
		Sleep(500);
	}

}
/* Starting EBSubMenu function
Input : choice
Output :
*/
void EBSubMenuENG(int number) {
	while (true)
	{
		if (number > 0 && number <= bookcounter)
		{
			system("cls");
			int choice;
			printf("==================== BOOK EDITING MENU ======================\n");
			printf("\n");
			printf("     -> 1. Continue to edit and update infomations of book %d\n", number);
			printf("     -> 2. See the local changes of book %d                  \n", number);
			printf("     -> 3. Go back to menu                                   \n");
			printf("=============================================================\n");
			printf("  -> Input your choice : ");
			scanf_s("%d", &choice);
			if (choice == 3) break;
			switch (choice)
			{
			case 1: BookEditing(number); break;
			case 2: SeeBookChanges(number); break;
			default: 
			{
				printf(" -> Invalid choice ! Please try again.\n");
				Sleep(500);
				break;
			}
			}
		}
		else
		{
			printf(" -> Book information is not exist in library's database. Please try again ...\n");
			Sleep(1000);
			break;
		}
	}
	//_getch();
}
/* Starting SeeBookChanges function
Input: book position
Output: Book informations
*/
void SeeBookChangesENG(int number) {
	printf("============ INFORMATIONS OF BOOK %d AFTER EDITING ==============\n", number);
	printf("   -> ISBN : ");
	puts(ISBN[number - 1]);
	printf("   -> Book name : ");
	puts(BookName[number - 1]);
	printf("   -> Author : ");
	puts(Author[number - 1]);
	printf("   -> Producer : ");
	puts(Producer[number - 1]);
	printf("   -> Year producing : ");
	puts(YearProducing[number - 1]);
	printf("   -> Genre : ");
	puts(Genre[number - 1]);
	printf("   -> Pricing : %d VND \n", Cost[number - 1]);
	printf("   -> Amount available for borrowing : %d\n", Amount[number - 1]);
	_getch();
}
/* Starting BookDeleting function
Input: book position
Output: Listed book available
*/
void BookDeletingENG(int number) {
	int flag = 0;
	char answer;
	fflush(stdin);
	getchar();
	printf(" -> Confirm delete this student ? Type Y or y for Yes, N or n to Cancel : ");
	answer = getchar();
	if (answer == 'y' || answer == 'Y')
	{ 
		if (number > 0 && number <= bookcounter) {
			for (int i = number - 1; i < bookcounter - 1; i++) {
				strcpy_s(ISBN[i], ISBN[i + 1]);
				strcpy_s(BookName[i], BookName[i + 1]);
				strcpy_s(Author[i], Author[i + 1]);
				strcpy_s(Producer[i], Producer[i + 1]);
				strcpy_s(YearProducing[i], YearProducing[i + 1]);
				strcpy_s(Genre[i], Genre[i + 1]);
				Cost[i] = Cost[i + 1];
				TotalBook -= Amount[i];
				Amount[i] = Amount[i + 1];
			}
			bookcounter--;
			flag = 1;
		}
	}
	else if (answer == 'n' || answer == 'N')
	{
		printf("  -> Cancelled.");
		Sleep(1000);
		return;
	}
	if (flag == 1) {
		printf(" -> Book deleted successfully !\n");
		printf("\n");
		Sleep(500);
		BookListing();
	}
	else
	{
		printf(" -> Something went wrong. Please try again..");
		Sleep(500);
	}
}
/* Starting SearchByBookName function
Input: Book's name
Output : Return info if it matched
*/
 void SearchByBookNameENG(char name[30]) {
	int flag = 0;
	printf("================== SEARCHING RESULT ==================\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(name, BookName[i]) == 0) {
			printf("\n");
			printf("    -> ISBN : ");
			puts(ISBN[i]);
			printf("    -> Name : ");
			puts(BookName[i]);
			printf("    -> Author : ");
			puts(Author[i]);
			printf("    -> Producer : ");
			puts(Producer[i]);
			printf("    -> Year producing : ");
			puts(YearProducing[i]);
			printf("    -> Genre : ");
			puts(Genre[i]);
			printf("    -> Pricing (VND) : %d\n", Cost[i]);
			printf("=====================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf(" -> No result !");
	else
	{
		printf("\n");
		printf("   -> Searching completed with %d results .\n", flag);
	}
	_getch();
}
/* Starting SearchByISBN function
Input: ISBN[25]
Output : Return info if it matched
*/
void SearchByISBNENG(char isbn[30]) {
	int flag = 0;
	printf("===================== SEARCHING RESULTS =====================\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(isbn, ISBN[i]) == 0) {
			printf("\n");
			printf("    -> ISBN : ");
			puts(ISBN[i]);
			printf("    -> Name : ");
			puts(BookName[i]);
			printf("    -> Author : ");
			puts(Author[i]);
			printf("    -> Producer : ");
			puts(Producer[i]);
			printf("    -> Year producing : ");
			puts(YearProducing[i]);
			printf("    -> Genre : ");
			puts(Genre[i]);
			printf("    -> Pricing (VND) : %d\n", Cost[i]);
			printf("===========================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf(" -> No result !");
	else
	{
		printf("\n");
		printf("   -> Searching completed with %d results. `\n", flag);
	}
	_getch();
}
