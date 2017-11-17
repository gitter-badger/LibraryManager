#include "MainActivity.h"
int LanguageSelection()
{
    int lang;
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t\tMoi chon ngon ngu/Select your language :\n\n");
		printf("\t\t\t\t\t\t  1. Tieng Viet \n");
		printf("\t\t\t\t\t\t  2. English  \n\n");
		printf("\n\t\t\t   -> Nhap vao lua chon cua ban /Input your choice : ");
		scanf_s("%d", &lang);
		if (lang != 1 || lang != 2)
		{
			printf("\n\t\t\t -> Lua chon khong ton tai! / Invalid choice !");
			Sleep(1000);
		}
		else break;
	} while (true);
	getchar();
    return lang;
}