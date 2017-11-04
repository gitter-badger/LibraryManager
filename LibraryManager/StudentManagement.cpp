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
			//	DayCreating
			}
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
