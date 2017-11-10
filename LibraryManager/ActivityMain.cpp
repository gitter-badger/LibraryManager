#include "ActivityMain.h"

void main() {
	int menuchoice, smchoice, bmchoice;
	// Initialising components as waiting for avoiding interupt
	InitializingComponents();
	system("cls");
	while (true)
	{
		menuchoice = MainMenu();
		switch (menuchoice)
		{
		case 1: {
			while (true)
			{
				smchoice = StudentManagementMenu();
				switch (smchoice)
				{
				case 1: StudentListing(); break;
				case 2: BookCreating(); break;
				default:
					break;
				}
			}
		}
		default:
			break;
		}
	}
	_getch();
}