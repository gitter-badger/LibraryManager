/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "MainActivity.h"
void main(){
    int langchoice;
    langchoice = LanguageSelection();
	if (langchoice == 1)
	{	
		Sleep(500);
		printf("\n\t\t\t   -> Dang thiet lap ngon ngu");
		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			printf(".");
		}
		system("cls");
		MainActivity();
	}
       
        else if(langchoice ==2)
        {
			Sleep(500);
			printf("\n\t\t\t   -> Setting language");
			for (int i = 0; i < 3; i++)
			{
				Sleep(500);
				printf(".");
			}
			system("cls");
            MainActivityENG();
        }
}