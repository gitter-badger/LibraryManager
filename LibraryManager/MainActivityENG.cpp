/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "MainActivity.h"
void MainActivityENG()
{
    int menuchoice, smchoice, bmchoice, statschoice;
	// Initialising components as waiting for avoiding interupt
	InitializingComponentsENG();
	system("cls");
	while (true)
	{
		menuchoice = MainMenuENG();
		switch (menuchoice) // main menu choice
		{
		case 1: // student manager
		{
			while (true) // Student Menu
			{
				smchoice = StudentManagementMenuENG();
				if (smchoice == 0) break;
				switch (smchoice)
				{
				case 1: 
					
				{
					system("cls");
					StudentListingENG(); break;
				}
				case 2: 
				{
					system("cls");
					StudentCreatingENG(); break;
				}
				case 3: 
				{
					system("cls");
					fflush(stdin);
					int location;
					printf("  -> Input student's position to edit : ");
					scanf_s("%d", &location);
					ESSubMenuENG(location);
					system("cls");
					break;
				}
				case 4: 
				{
					system("cls");
					fflush(stdin);
					int location;
					printf(" -> Input student's position to delete : ");
					scanf_s("%d", &location);
					StudentDeletingENG(location);
					break;
				}
				case 5: 
				{
					system("cls");
					fflush(stdin);
					char cmnd[25];
					printf("  -> Input ID to search : ");
					getchar();
					gets_s(cmnd);
					SearchByIDENG(cmnd);
					break;
				}
				case 6 : 
				{
					system("cls");
					fflush(stdin);
					char name[25];
					printf("  -> Input name to search : ");
					getchar();
					gets_s(name);
					SearchByNameENG(name);
					break;
				}
				default: 
				{
					printf("Invalid choice ! Please try again ....\n");
					Sleep(1000);
					break;
				}
				}
			}
		} break;
		case 2: // book manager
		{
			while (true) // Book Menu
			{
				bmchoice = BookManagementMenuENG();
				if (bmchoice == 0) break;
				switch (bmchoice)
				{
				case 1:
				{
					system("cls");
					BookListingENG(); break;
				}
				case 2:
				{
					getchar();
					system("cls");
					BookCreatingENG();
					break;
				}
				case 3: 
				{
					system("cls");
					fflush(stdin);
					getchar();
					int location;
					printf("  -> Input book's position to edit: ");
					scanf_s("%d", &location);
					EBSubMenuENG(location);
					break;
				}
				case 4: 
				{
					system("cls");
					fflush(stdin);
					int location;
					printf("  -> Input books's position to delete : ");
					scanf_s("%d", &location);
					BookDeletingENG(location);
					break;
				}
				case 5: 
				{
					system("cls");
					fflush(stdin);
					char isbn[25];
					getchar();
					printf(" -> Input ISBN to search : ");
					gets_s(isbn);
					SearchByISBNENG(isbn);
					break;
				}
				case 6: 
				{
					system("cls");
					fflush(stdin);
					char bookname[30];
					getchar();
					printf(" -> Input book name to search : ");
					gets_s(bookname);
					SearchByBookNameENG(bookname);
					break;
				}
				default:
					break;
				}
			}
		} break;
		case 3:  // card menu
		{
			system("cls");
			fflush(stdin);
			CardCreatingMenuENG();
			break;
		} break;
		case 4: // statistics menu 
		{
			while (true)
			{
				statschoice = StatisticsMenuENG();
				if (statschoice == 0) break;
				switch (statschoice)
				{
				case 1: 
				{
					system("cls");
					printf("\n\n");
					printf("\t\t\t=================== TOTAL BOOKS STATS ===================\n");
					BookRemainingENG();
					break;
				}
				case 2: 
				{
					system("cls");
					BookStatsByGenreENG();
					break;
				}
				case 3:
				{
					system("cls");
					printf("=================== STUDENTS STATS ===================\n");
					printf("\n");
					printf("  -> Total students in library's database are : %d", StudentStatisticsENG());
					_getch();
					break;
				}
				case 4 :
				{
					system("cls");
					StatsBasedSexENG();
					break;
				}
				case 5: 
				{
					system("cls");
					TotalBookInUseENG();
					break;
				}
				case 6:
				{
					system("cls");
					LateStatsENG();
					break;
				}
				default:
					break;
				}
			}
		} break;
		case 0 :
		{
			return;
		} break;
		case 5: // about author
		{
			system("cls");
			IntroductionENG();
			break;
		} break;
		default:
		{
			printf(" -> Invalid option !");
			Sleep(1000);
		}
			break;
		}
	}
	_getch();
}