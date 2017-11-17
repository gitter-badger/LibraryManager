#include "MainActivity.h"
void MainActivity() {
	int menuchoice, smchoice, bmchoice, statschoice;
	// Initialising components as waiting for avoiding interupt
	InitializingComponents();
	system("cls");
	while (true)
	{
		menuchoice = MainMenu();
		switch (menuchoice) // main menu choice
		{
		case 1: // student manager
		{
			while (true) // Student Menu
			{
				smchoice = StudentManagementMenu();
				if (smchoice == 0) break;
				switch (smchoice)
				{
				case 1: 
					
				{
					system("cls");
					StudentListing(); break;
				}
				case 2: 
				{
					system("cls");
					StudentCreating(); break;
				}
				case 3: 
				{
					system("cls");
					fflush(stdin);
					int location;
					printf("  -> Nhap vao so thu tu hoc sinh can sua : ");
					scanf_s("%d", &location);
					ESSubMenu(location);
					system("cls");
					break;
				}
				case 4: 
				{
					system("cls");
					fflush(stdin);
					int location;
					printf(" -> Nhap so thu tu hoc sinh can xoa : ");
					scanf_s("%d", &location);
					StudentDeleting(location);
					break;
				}
				case 5: 
				{
					system("cls");
					fflush(stdin);
					char cmnd[25];
					printf("  -> Nhap CMND doc gia can tim kiem : ");
					getchar();
					gets_s(cmnd);
					SearchByID(cmnd);
					break;
				}
				case 6 : 
				{
					system("cls");
					fflush(stdin);
					char name[25];
					printf("  -> Nhap ten doc gia can tim kiem : ");
					getchar();
					gets_s(name);
					SearchByName(name);
					break;
				}
				default: 
				{
					printf("Lua chon khong hop le ! Vui long thu lai..\n");
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
				bmchoice = BookManagementMenu();
				if (bmchoice == 0) break;
				switch (bmchoice)
				{
				case 1:
				{
					system("cls");
					BookListing(); break;
				}
				case 2:
				{
					getchar();
					system("cls");
					BookCreating();
					break;
				}
				case 3: 
				{
					system("cls");
					fflush(stdin);
					getchar();
					int location;
					printf("  -> Nhap so thu tu sach can sua : ");
					scanf_s("%d", &location);
					EBSubMenu(location);
					break;
				}
				case 4: 
				{
					system("cls");
					fflush(stdin);
					int location;
					printf("  -> Nhap so thu tu sach can xoa : ");
					scanf_s("%d", &location);
					BookDeleting(location);
					break;
				}
				case 5: 
				{
					system("cls");
					fflush(stdin);
					char isbn[25];
					getchar();
					printf(" -> Nhap ma sach(ISBN) can tim : ");
					gets_s(isbn);
					SearchByISBN(isbn);
					break;
				}
				case 6: 
				{
					system("cls");
					fflush(stdin);
					char bookname[30];
					getchar();
					printf(" -> Nhap vao ten sach can tim : ");
					gets_s(bookname);
					SearchByBookName(bookname);
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
			CardCreatingMenu();
			break;
		} break;
		case 4: // statistics menu 
		{
			while (true)
			{
				statschoice = StatisticsMenu();
				if (statschoice == 0) break;
				switch (statschoice)
				{
				case 1: 
				{
					system("cls");
					printf("\n\n");
					printf("============ THONG KE SO SACH TRONG THU VIEN ==============\n");
					BookRemaining();
					break;
				}
				case 2: 
				{
					system("cls");
					BookStatsByGenre();
					break;
				}
				case 3:
				{
					system("cls");
					printf("=================== THONG KE SO LUONG DOC GIA ===================\n");
					printf("\n");
					printf("  -> Tong so doc gia trong thu vien la : %d", StudentStatistics());
					_getch();
					break;
				}
				case 4 :
				{
					system("cls");
					StatsBasedSex();
					break;
				}
				case 5: 
				{
					system("cls");
					TotalBookInUse();
					break;
				}
				case 6:
				{
					system("cls");
					LateStats();
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
			Introduction();
			break;
		} break;
		default:
		{
			printf(" -> Lua chon khong hop le !");
			Sleep(1000);
		}
			break;
		}
	}
	_getch();
}