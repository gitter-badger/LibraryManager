#include "StudentManagement.h"
#include "StudentComponents.h"

/* Starting EditStudent SubMenu
Input : ESSubMenu choice
Output: choice
*/
 void ESSubMenuENG(int number) {
	//system("cls");
	int choice;
	while (true)
	{
		if (number > 0 && number <= studentcounter)
		{
			system("cls");
			printf("\n");
			printf("=================== STUDENT INFORMATIONS UPDATING MENU ===================\n");
			printf("           1. Continue to update informations of student %d       \n", number);
			printf("           2. See the local changes after updating of student %d  \n", number);
			printf("           3. Go back to menu                                             \n");
			printf("==========================================================================\n");
			printf("   -> Input your choice : ");
			scanf_s("%d", &choice);
			if (choice == 3) break;
			switch (choice)
			{
			case 1: StudentEditingENG(number); break;
			case 2: SeeLocalChangesENG(number); break;
			default: printf("Invalid choice ! Please try again ... \n");
				break;
			}
		}
		else
		{
			printf("Info of this student is not exist in library database... Exiting...\n");
			Sleep(1000);
			break;
		}
	}
	//_getch();
}
/* Starting StudentDeclaraion
Input : LibraryID, Name, ID, Birth, Sex, Email, Address
Output : Initial first student informations
*/
 void StudentDeclarationENG() {
	while (true) {
		if (studentcounter >= Max) printf("No memory for declaring !");
		else
			while (studentcounter < Max)
			{
				printf(" ================== INFORMATIONS OF STUDENTS %d ===================\n", studentcounter + 1);
				fflush(stdin); // Clear the caches
				// Input the informations
				printf("  -> Library ID of student %d : ", studentcounter + 1);
				gets_s(LibraryID[studentcounter]);
				printf("  -> Name of student %d : ", studentcounter + 1);
				gets_s(Name[studentcounter]);
				printf("  -> ID of student %d : ", studentcounter + 1);
				gets_s(ID[studentcounter]);
				printf("  -> Birthday of student %d : ", studentcounter + 1);
				gets_s(Birth[studentcounter]);
				printf("  -> Sex of student %d : ", studentcounter + 1);
				gets_s(Sex[studentcounter]);
				printf("  -> Email of student %d : ", studentcounter + 1);
				gets_s(Email[studentcounter]);
				printf("  -> Address of student %d (please type without using dot or comma) : ", studentcounter + 1);
				gets_s(Address[studentcounter]);
				//Library card creating
				printf("  -> Time creating library card : \n");
				DayCreatingENG();
				// Automatic evaluate expired time
				DayExpiredENG();
				studentcounter++; break;
			}
		if (studentcounter >= 1) break;
	}
}
/* Starting DayCreate function
Input : None
Output: Day, month, year of library card for first use
*/
 void DayCreatingENG() {
	printf("\t  -> Input creating day : ");
	scanf_s("%d", &DayCre[studentcounter]);
	printf("\t  -> Input creating month : ");
	scanf_s("%d", &MonthCre[studentcounter]);
	printf("\t  -> Input creating year : ");
	scanf_s("%d", &YearCre[studentcounter]);
}
/* Starting DayExpired function with automatically evaluate the expiration
Input : DayCre, MonthCre, YearCre
Output: DayEx, MonthEx, YearEx
*/
 void DayExpiredENG() {
	DayEx[studentcounter] = DayCre[studentcounter];
	MonthEx[studentcounter] = MonthCre[studentcounter];
	YearEx[studentcounter] = YearCre[studentcounter] + 4;
}
/* Starting StudentListing function
Input : None
Output : students list
*/
 void StudentListingENG() {
	printf("\t\t================== STUDENTS INFORMATIONS LISTING ==================\n\n");
	if (studentcounter <= 0) printf("There is empty in library database. Please update or declare at least 1 student !\n");
	else {
		for (int i = 0; i < studentcounter; i++) {
			printf("=============== INFORMATIONS OF STUDENT %d ============= \n", i + 1);
			printf("\n");
			printf(" -> Library ID : ");
			puts(LibraryID[i]);
			printf(" -> Name : ");
			puts(Name[i]);
			printf(" -> ID : ");
			puts(ID[i]);
			printf(" -> Birthday : ");
			puts(Birth[i]);
			printf(" -> Sex : ");
			puts(Sex[i]);
			printf(" -> Email : ");
			puts(Email[i]);
			printf(" -> Currently address : ");
			puts(Address[i]);
			printf(" -> Time creating library card : %d/%d/%d\n", DayCre[i], MonthCre[i], YearCre[i]);
			printf(" -> Time expired  : %d/%d/%d\n", DayEx[i], MonthEx[i], YearEx[i]);
			printf("\n");
		}
	}
	_getch();
}
/* Starting StudentCreating function
Input : arrays with student informations
Output : student added
*/
void StudentCreatingENG() {
	while (true)
	{
		int choice;
		printf("====================== STUDENT CREATING MENU ========================\n");
		printf("                 -> 1. Create a new student                          \n");
		printf("                 -> 2. Go back to menu                               \n");
		printf("=====================================================================\n");
		printf("      -> Input your ch : ");
		scanf_s("%d", &choice);
	if (choice==1)
	{
			if (studentcounter > Max) printf("No memory to create a new student !\n");
			else
			{
				printf(" ================= INFORMATIONS OF STUDENT %d ================\n", studentcounter + 1);
				fflush(stdin);
				getchar();// Clear the caches
							   // Input the informations
				printf("  -> Input library ID of student %d : ", studentcounter + 1);
				gets_s(LibraryID[studentcounter]);
				printf("  -> Input name of student %d : ", studentcounter + 1);
				gets_s(Name[studentcounter]);
				printf("  -> Input ID of student %d : ", studentcounter + 1);
				gets_s(ID[studentcounter]);
				printf("  -> Input birthday of student %d : ", studentcounter + 1);
				gets_s(Birth[studentcounter]);
				printf("  -> Input sex of student %d : ", studentcounter + 1);
				gets_s(Sex[studentcounter]);
				printf("  -> Input email of student %d : ", studentcounter + 1);
				gets_s(Email[studentcounter]);
				printf("  -> Input address of student %d (please type without dot or comma) : ", studentcounter + 1);
				gets_s(Address[studentcounter]);
				//Library card creating
				printf("  -> Input time creating : \n");
				DayCreatingENG();
				// Automatic evaluate expired time
				DayExpiredENG();
				studentcounter++;
				Sleep(1000);
				printf(" -> Student created successfully !");
				Sleep(500);
				break;
			}
		//	continue;
	}
	else if (choice == 2) break;
	}
}
/* Starting StudentEditing function
Input : student position
Output : local changed 
*/
 void StudentEditingENG(int number) {
	while (true)
	{
		if (number> 0 && number <= studentcounter)
		{
			int choice;
			printf("================ MENU CHINH SUA DOC GIA ===============\n");
			printf("  -> 1. Chinh sua Ma thu vien                          \n");
			printf("  -> 2. Chinh sua ten doc gia                          \n");
			printf("  -> 3. Chinh sua CMND cua doc gia                     \n");
			printf("  -> 4. Chinh sua ngay thang nam sinh cua doc gia      \n");
			printf("  -> 5. Chinh sua gioi tinh                            \n");
			printf("  -> 6. Chinh sua email                                \n");
			printf("  -> 7. Chinh sua dia chi                              \n");
			printf("  -> 8. Chinh sua thoi gian tao the thu vien           \n");
			printf("  -> 0. Huy bo chinh sua                               \n");
			printf("=======================================================\n");
			printf("   Nhap lua chon cua ban : ");
			scanf_s("%d", &choice);
			if (choice == 0) break;
			switch (choice)
			{
			case 8: {
				system("cls");
				fflush(stdin);
				int dayedit, monthedit, yearedit;
				printf("============ NOI DUNG CHINH SUA =============\n");
				printf(" -> Nhap ngay muon sua : ");
				scanf_s("%d", &dayedit);
				printf(" -> Nhap thang muon sua : ");
				scanf_s("%d", &monthedit);
				printf(" -> Nhap nam muon sua : ");
				scanf_s("%d", &yearedit);
				DayCre[number-1] = dayedit;
				MonthCre[number-1] = monthedit;
				YearCre[number-1] = yearedit;
				DayEx[number-1] = dayedit;
				MonthEx[number-1] = monthedit;
				YearEx[number-1] = yearedit + 4;
				
			} break;
			case 1: {
				getchar();
				fflush(stdin);
				char LibIDNew[25];
				printf("Nhap vao ma thu vien moi : ");
				gets_s(LibIDNew);
				strcpy_s(LibraryID[number - 1], LibIDNew);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 2: {
				getchar();
				fflush(stdin);
				char NewName[25];
				printf("Nhap vao ten moi : ");
				gets_s(NewName);
				strcpy_s(Name[number - 1], NewName);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 3: {
				getchar();
				fflush(stdin);
				char NewID[25];
				printf("Nhap vao CMND moi : ");
				gets_s(NewID);
				strcpy_s(ID[number - 1], NewID);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 4: {
				getchar();
				fflush(stdin);
				char NewBirth[25];
				printf("Nhap vao ngay thang nam sinh moi : ");
				gets_s(NewBirth);
				strcpy_s(Birth[number - 1], NewBirth);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 5: {
				getchar();
				fflush(stdin);
				char NewSex[25];
				printf("Nhap vao gioi tinh moi : ");
				gets_s(NewSex);
				strcpy_s(Sex[number - 1], NewSex);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 6: {
				getchar();
				fflush(stdin);
				char NewEmail[25];
				printf("Nhap email moi : ");
				gets_s(NewEmail);
				strcpy_s(Email[number - 1], NewEmail);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			case 7: {
				getchar();
				fflush(stdin);
				char NewAddress[50];
				printf("Nhap dia chi moi : ");
				gets_s(NewAddress);
				strcpy_s(Address[number - 1], NewAddress);
				Sleep(1000);
				printf("Chinh sua thanh cong !");
				Sleep(500);
			} break;
			default:
			{
				printf("Chuc nang ban nhap khong hop le! Vui long kiem tra lai.");
				Sleep(1000);
				break;
			}
			}
			system("cls");
		}
		else
		{
			printf("Du lieu hoc sinh khong ton tai hoac khong trung khop ! Vui long thoat ra va chon lai..\n");
			_getch();
			Sleep(1000);
		}
		break;
	}
}
/* Starting SeeLocalChanges function
Input : student position
Output: Student info */
 void SeeLocalChangesENG(int number) {
	printf("\n");
	printf("============== INFORMATIONS OF STUDENT %d AFTER UPDATING =============\n", number);
	printf("\n");
	printf(" -> Library ID : ");
	puts(LibraryID[number-1]);
	printf(" -> Name : ");
	puts(Name[number-1]);
	printf(" -> ID : ");
	puts(ID[number-1]);
	printf(" -> Birthday : ");
	puts(Birth[number-1]);
	printf(" -> Sex : ");
	puts(Sex[number-1]);
	printf(" -> Email : ");
	puts(Email[number-1]);
	printf(" -> Address : ");
	puts(Address[number-1]);
	printf(" -> Created time : %d/%d/%d\n", DayCre[number-1], MonthCre[number-1], YearCre[number-1]);
	printf(" -> Expired time  : %d/%d/%d\n", DayEx[number-1], MonthEx[number-1], YearEx[number-1]);
	Sleep(1000);
	_getch();
}
/*Starting StudentDelete function
Input: Student position
Output : Deleted student, listing student available*/
 void StudentDeletingENG(int number) {
	int flag = 0;
	if (number > 0 && number <= studentcounter)
	{
		for (int i = number - 1; i < studentcounter - 1; i++) 
		{
			strcpy_s(LibraryID[i], LibraryID[i + 1]);
			strcpy_s(Name[i], Name[i + 1]);
			strcpy_s(ID[i], ID[i + 1]);
			strcpy_s(Birth[i], Birth[i + 1]);
			strcpy_s(Sex[i], Sex[i + 1]);
			strcpy_s(Email[i], Email[i + 1]);
			strcpy_s(Address[i], Address[i + 1]);
			//Timing library card
			DayCre[i] = DayCre[i + 1];
			MonthCre[i] = MonthCre[i + 1];
			YearCre[i] = YearCre[i + 1];
			// Timing expired card
			DayEx[i] = DayEx[i + 1];
			MonthEx[i] = MonthEx[i + 1];
			YearEx[i] = YearEx[i + 1];
		}
		studentcounter--; flag = 1;
	}
	if (flag == 1) {
		printf("Xoa thanh cong !\n");
		printf("\n");
		Sleep(500);
		StudentListingENG();
	}	
	else
	{
		printf("Co loi khi xoa, vui long thu lai..");
		Sleep(500);
	}
	
}
/* Starting SearchByID function
Input : Identity (ID) of student
Output : Student info
*/
 void SearchByIDENG(char id[25]) {
	int flag = 0;
	for (int i = 0; i < studentcounter; i++) {
		printf("\n");
		if (strcmp(id, ID[i]) == 0) {
			printf("================ SEARCHING RESULT ==================\n");
			printf("   -> Library ID : ");
			puts(LibraryID[i]);
			printf("   -> Name : ");
			puts(Name[i]);
			printf("   -> ID : ");
			puts(ID[i]);
			printf("   -> Birthday : ");
			puts(Birth[i]);
			printf("   -> Sex : ");
			puts(Sex[i]);
			printf("   -> Email : ");
			puts(Email[i]);
			printf("   -> Address : ");
			puts(Address[i]);
			printf("   -> Created time : %d/%d/%d\n", DayCre[i], MonthCre[i], YearCre[i]);
			printf("   -> Expired time : %d/%d/%d\n", DayEx[i], MonthEx[i], YearEx[i]);
			printf("====================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf(" -> No result !");
	else
	{
		printf("\n");
		printf("   - > Searched end with %d result \n", flag);
	}
	_getch();
}
/*Starting SearchByName function 
Input: Name student
Output : Student info if it matched
*/
 void SearchByNameENG(char name[25]) {
	int flag = 0;
	for (int i = 0; i < studentcounter; i++) {
		printf("\n");
		if (strcmp(name, Name[i]) == 0) {
			printf("===================== SEARCHING RESULT ======================\n");
			printf("   -> Library ID : ");
			puts(LibraryID[i]);
			printf("   -> Name : ");
			puts(Name[i]);
			printf("   -> ID: ");
			puts(ID[i]);
			printf("   -> Birthday : ");
			puts(Birth[i]);
			printf("   -> Sex : ");
			puts(Sex[i]);
			printf("   -> Email : ");
			puts(Email[i]);
			printf("   -> Address : ");
			puts(Address[i]);
			printf("   -> Created time : %d/%d/%d\n", DayCre[i], MonthCre[i], YearCre[i]);
			printf("   -> Expired time : %d/%d/%d\n", DayEx[i], MonthEx[i], YearEx[i]);
			printf("====================================================\n");
			flag++;
		}
	}
	if (flag == 0) printf(" -> No result !");
	else
	{
		printf("\n");
		printf("   - > Searched end with %d result.\n", flag);
	}
	_getch();
}
