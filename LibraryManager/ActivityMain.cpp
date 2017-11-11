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
				case 2: StudentCreating(); break;
				case 3: 
				{
					int location;
					printf("  -> Nhap vao so thu tu hoc sinh can sua : ");
					scanf_s("%d", &location);
					StudentEditing(location-1);
					ESSubMenu(location);
					break;
				}
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