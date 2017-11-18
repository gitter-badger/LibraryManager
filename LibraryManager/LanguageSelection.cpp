/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "MainActivity.h"
int LanguageSelection()
{
    int lang;
	
	while (true)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t\tMoi chon ngon ngu/Select your language :\n\n");
		printf("\t\t\t\t\t\t  1. Tieng Viet \n");
		printf("\t\t\t\t\t\t  2. English  \n\n");
		printf("\n\t\t\t         -> Nhap vao lua chon cua ban /Input your choice : ");
		scanf_s("%d", &lang);
		if (lang == 1 || lang == 2) break;
		else
		{
			printf("\n\t\t\t  -> Lua chon khong ton tai ! / Invalid option !\n");
			Sleep(1000);
			continue;
		}
	}
		
	getchar();
    return lang;
}