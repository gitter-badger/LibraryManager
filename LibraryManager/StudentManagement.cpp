#include "StudentManagement.h"

// Initialising arrays include student information
char LibraryID[Max][25], Name[Max][25], ID[Max][25], Birth[Max][25], Sex[Max][25], Email[Max][25], Address[Max][25];
int DayCre[Max];
int MonthCre[Max];
int YearCre[Max];
int DayEx[Max];
int MonthEx[Max];
int YearEx[Max];
int studentcounter = 0; // Initialising student number counter
/* Starting EditStudent SubMenu
Input : ESSubMenu	 choice
Output: choide
*/
void ESSubMenu() {

}
/* Starting StudentDeclaraion
Input : LibraryID, Name, ID, Birth, Sex, Email, Address
Output : Initial first student informations
*/
void StudentDeclaration() {
	while (true) {
		if (studentcounter > Max) printf("Khong du bo nho de tao hoac cap nhat doc gia !");
		else
			while (studentcounter < Max)
			{
				printf(" ========== Thong Tin Doc Gia Thu %d =============\n", studentcounter + 1);
				fflush(stdin); // Clear the caches
				// Input the informations
				printf("  -> Ma so doc gia thu %d : ", studentcounter + 1);
				gets_s(LibraryID[studentcounter]);
				printf("  -> Ten doc gia thu %d : ", studentcounter + 1);
				gets_s(Name[studentcounter]);
				printf("  -> CMND doc gia thu %d : ", studentcounter + 1);
				gets_s(ID[studentcounter]);
				printf("  -> Ngay thang nam sinh doc gia thu %d : ", studentcounter + 1);
				gets_s(Birth[studentcounter]);
				printf("  -> Gioi tinh doc gia thu %d : ", studentcounter + 1);
				gets_s(Sex[studentcounter]);
				printf("  -> Email doc gia thu %d : ", studentcounter + 1);
				gets_s(Email[studentcounter]);
				printf("  -> Dia chi doc gia thu %d (luu y khong dung dau cham hay dau phay) : ", studentcounter + 1);
				gets_s(Address[studentcounter]);
				//Library card creating
				printf("  -> Nhap vao thoi gian lam the thu vien : ");
				DayCreating();
				// Automatic evaluate expired time
				DayExpired();
				studentcounter++; break;
			}
		if (studentcounter >= 3) break;
	}
}
/* Starting DayCreate function
Input : None
Output: Day, month, year of library card for first use
*/
void DayCreating() {
	printf("  -> Nhap ngay lap the : ");
	scanf_s("%d", &DayCre[studentcounter]);
	printf("  -> Nhap thang lap the : ");
	scanf_s("%d", &MonthCre[studentcounter]);
	printf("  -> Nhap nam lap the : ");
	scanf_s("%d", &YearCre[studentcounter]);
}
/* Starting DayExpired function with automatically evaluate the expiration
Input : DayCre, MonthCre, YearCre
Output: DayEx, MonthEx, YearEx
*/
void DayExpired() {
	DayEx[studentcounter] = DayCre[studentcounter];
	MonthEx[studentcounter] = MonthCre[studentcounter];
	YearEx[studentcounter] = YearCre[studentcounter] + 3;
}
/* Starting StudentListing function
Input : None
Output : students list
*/
void StudentListing() {
	if (studentcounter <= 0) printf("Hien tai chua co hoc sinh nao trong du lieu thu vien. Vui long cap nhat hoac them doc gia !\n");
	else {
		for (int i = 0; i < studentcounter; i++) {
			printf("=============== Thong Tin Doc Gia Thu %d ============= \n", i + 1);
			printf("\n");
			printf("Ma thu vien la : ");
			puts(LibraryID[i]);
			printf("Ten cua doc gia : ");
			puts(Name[i]);
			printf("So CMND : ");
			puts(ID[i]);
			printf("Ngay thang nam sinh : ");
			puts(Birth[i]);
			printf("Gioi tinh : ");
			puts(Sex[i]);
			printf("Email : ");
			puts(Email[i]);
			printf("Dia chi : ");
			puts(Address[i]);
			printf("Thoi gian lam the thu vien : %d/%d/%d", DayCre[i], MonthCre[i], YearCre[i]);
			printf("Ngay het han  : %d/%d/%d", DayEx[i], MonthEx[i], YearEx[i]);

		}
	}
}
/* Starting StudentCreating function
Input : arrays with student informations
Output : student added
*/
void StudentCreating() {
	while (true)
	{
		int choice;
		printf("============= Menu Chinh Sua Va Cap Nhat Doc Gia =============\n");
		printf("                 -> 1. Cap nhat thong tin doc gia\n             ");
		printf("                 -> 2. Thoat\n                                  ");
		printf("===============================================================\n");
		printf("      -> Nhap vao lua chon cua ban : ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 2: break;
		case 1: {
			if (studentcounter > Max) printf("Khong du bo nho de tao hoac cap nhat doc gia !");
			else
				while (studentcounter < Max)
				{
					printf(" ========== Thong Tin Doc Gia Thu %d =============\n", studentcounter + 1);
					fflush(stdin); // Clear the caches
								   // Input the informations
					printf("  -> Ma so doc gia thu %d : ", studentcounter + 1);
					gets_s(LibraryID[studentcounter]);
					printf("  -> Ten doc gia thu %d : ", studentcounter + 1);
					gets_s(Name[studentcounter]);
					printf("  -> CMND doc gia thu %d : ", studentcounter + 1);
					gets_s(ID[studentcounter]);
					printf("  -> Ngay thang nam sinh doc gia thu %d : ", studentcounter + 1);
					gets_s(Birth[studentcounter]);
					printf("  -> Gioi tinh doc gia thu %d : ", studentcounter + 1);
					gets_s(Sex[studentcounter]);
					printf("  -> Email doc gia thu %d : ", studentcounter + 1);
					gets_s(Email[studentcounter]);
					printf("  -> Dia chi doc gia thu %d (luu y khong dung dau cham hay dau phay) : ", studentcounter + 1);
					gets_s(Address[studentcounter]);
					//Library card creating
					printf("  -> Nhap vao thoi gian lam the thu vien : ");
					DayCreating();
					// Automatic evaluate expired time
					DayExpired();
					studentcounter++; break;
				}
			
		} break;
		default: printf("Lenh ban vua nhap vao khong hop le !");
		}
	}
}
/* Starting StudentEditing function
Input : student position
Output : local changed 
*/
void StudentEditing(int number) {
	if (number >= 0 && number < studentcounter)
	{
		int choice;
		printf("=========== MENU CHINH SUA DOC GIA ==========\n");
		printf("  -> 1. Chinh sua Ma thu vien \n               ");
		printf("  -> 2. Chinh sua ten doc gia \n               ");
		printf("  -> 3. Chinh sua CMND cua doc gia \n          ");
		printf("  -> 4. Chinh sua ngay thang nam sinh cua doc gia \n");
		printf("  -> 5. Chinh sua gioi tinh  \n               ");
		printf("  -> 6. Chinh sua email      \n               ");
		printf("  -> 7. Chinh sua dia chi    \n               ");
		printf("  -> 8. Chinh sua thoi gian tao the thu vien\n");
		printf("==============================================\n");
		printf("Nhap lua chon cua ban : ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 8: {
			fflush(stdin);
			int dayedit, monthedit, yearedit;
			printf("============ Noi dung chinh sua =============\n");
			printf("Nhap ngay muon sua : ");
			scanf_s("%d", dayedit);
			printf("Nhap thang muon sua : ");
			scanf_s("%d", &monthedit);
			printf("Nhap nam muon sua : ");
			scanf_s("%d", &yearedit);
			DayCre[number] = dayedit;
			MonthCre[number] = monthedit;
			YearCre[number] = yearedit;
			DayEx[number] = dayedit;
			MonthEx[number] = monthedit;
			YearEx[number] = yearedit;
		} break;
		case 1: {
			fflush(stdin);
			char LibIDNew[25];
			printf("Nhap vao ma thu vien moi : ");
			gets_s(LibIDNew);
			strcpy(LibraryID[number - 1], LibIDNew);
		} break;
		case 2: {
			fflush(stdin);
			char NewName[25];
			printf("Nhap vao ten moi : ");
			gets_s(NewName);
			strcpy(Name[number - 1], NewName);
		} break;
		case 3: {
			fflush(stdin);
			char NewID[25];
			printf("Nhap vao CMND moi : ");
			gets_s(NewID);
			strcpy(ID[number - 1], NewID);
		} break;
		case 4: {
			fflush(stdin);
			char 
		}
		default:
			break;
		}
	}
}