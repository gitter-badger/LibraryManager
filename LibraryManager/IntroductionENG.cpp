/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "Introduction.h"
#include "BookManagement.h"
#include "StudentManagement.h"
/*Starting Introduction function
Type : void
Input : none
Output: About author
*/
void IntroductionENG() {
	system("cls");
	printf("\n\n\n");
	printf("\t  =================================================================================================\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  ||                         VIETNAM NATIONAL UNIVERSITY HO CHI MINH CITY                        ||\n");
	printf("\t  ||                                 UNIVERSITY OF SCIENCES                                      ||\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  ||                               PROGRAMMING PROJECT 01                                        ||\n");
	printf("\t  ||                          THE LIBRARY MANAGER APPLICATION                                    ||\n");
	printf("\t  ||                    Student  : Hoang Minh Hieu                                               ||\n");
	printf("\t  ||                    Class        : 17CK1_CL - Faculty of Information Technology              ||\n");
	printf("\t  ||                    Student ID       : 1760311                                               ||\n");
	printf("\t  ||                    Phone : 0125 428 0401                                                    ||\n");
	printf("\t  ||                    Email      : 1760311@student.hcmus.edu.vn                                ||\n");
	printf("\t  ||    Source code available now on my GitHub: https://github.com/hyperion0201/LibraryManager   ||\n");
	printf("\t  ||                                                                                             ||\n");
	printf("\t  =================================================================================================\n");
	_getch();
}
/*Starting InitializingComponents function
Type: void
Input : none
Output : waiting system and prompting user for avoiding interrupts
*/
void InitializingComponentsENG() {
	printf("\n");
	printf("\t\t================= WELCOME TO HCMUS LIBRARY MANAGER SOFTWARE =================\n");
	printf("\n");
	Sleep(3000);
	printf("\t Initialising components, please wait !");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". \n");
	printf("\t Attention : To use this app, you must declare at least 1 user and 1 book.\n");
	Sleep(2000);
	printf("\t Got it ? Let's begin. \n");
	Sleep(2000);
	printf("\n");
	printf("\t -> Input informations for first student :\n");
	printf("\n");
	StudentDeclarationENG();
	printf("\n");
	printf("\t -> Input informations for first book : \n");
	printf("\n");
	BookDeclarationENG();
	Sleep(2000);
	printf("\n");
	printf("\t -> The library is being started..");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". \n");
}
/*Starting MainMenu function
Type: integer
Input : none
Output : user's choice
*/
int MainMenuENG() {
	system("cls");
	int choice;
	printf("\n");
	printf("\t                THE LIBRARY MANAGER SOFTWARE -- HOANG MINH HIEU -- 17CK1_CL         \n");
	printf("\t      ==============================================================================\n");
	printf("\t      ||                                                                          ||\n");
	printf("\t      ||                         1. Student Management                            ||\n");
	printf("\t      ||                         2. Book Management                               ||\n");
	printf("\t      ||                         3. Library card management(borrow, return)       ||\n");
	printf("\t      ||                         4. Statistics                                    ||\n");
	printf("\t      ||                         5. See author                                    ||\n");
	printf("\t      ||                         0. Exit                                          ||\n");
	printf("\t      ||                                                                          ||\n");
	printf("\t      ==============================================================================\n");
	printf("                   Please input your choice  :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting StudentManagementMenu function
Type: int
Input: none
Output: user's choice
*/
int StudentManagementMenuENG() {
	system("cls");
	int choice;
	printf("\t\t ======================= STUDENTS MANAGEMENT =====================\n");
	printf("\t\t ||                                                             ||\n");
	printf("\t\t ||             1. See the students list in library database    ||\n");
	printf("\t\t ||             2. Create a new student                         ||\n");
	printf("\t\t ||             3. Edit a student                               ||\n");
	printf("\t\t ||             4. Delete a student                             ||\n");
	printf("\t\t ||             5. Search a student by ID                       ||\n");
	printf("\t\t ||             6. Search a student by name                     ||\n");
	printf("\t\t ||             0. Go back to menu                              ||\n");
	printf("\t\t ||                                                             ||\n");
	printf("\t\t =================================================================\n");
	printf("                     Please input your choice :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting BookManagementMenu function
Type : int
Input: none
Output : user's choice
*/
int BookManagementMenuENG() {
	system("cls");
	int choice;
	printf("\t\t ========================== BOOKS MANAGEMENT ==========================\n");
	printf("\t\t ||                                                              ||\n");
	printf("\t\t ||             1. See the books list in library's database      ||\n");
	printf("\t\t ||             2. Create a new book                             ||\n");
	printf("\t\t ||             3. Edit a book                                   ||\n");
	printf("\t\t ||             4. Delete a book                                 ||\n");
	printf("\t\t ||             5. Search a book by ISBN                         ||\n");
	printf("\t\t ||             6. Search a book by name                         ||\n");
	printf("\t\t ||             0. Go back to menu                               ||\n");
	printf("\t\t ||                                                              ||\n");
	printf("\t\t ==================================================================\n");
	printf("                       Please input your choice :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting Statistics function
Type : int
Input: none
Output :user's input
*/
int StatisticsMenuENG() {
	system("cls");
	int choice;
	printf("\t\t ========================= STATISTICS ==== =========================\n");
	printf("\t\t ||                                                               ||\n");
	printf("\t\t ||            1. Stats total books in library                    ||\n");
	printf("\t\t ||            2. Stats book by genres                            ||\n");
	printf("\t\t ||            3. Stats total students in library                 ||\n");
	printf("\t\t ||            4. Stats student by sex                            ||\n");
	printf("\t\t ||            5. Stats books which are in-use                    ||\n");
	printf("\t\t ||            6. Stats students who are in-late                  ||\n");
	printf("\t\t ||            0. Go back to menu                                 ||\n");
	printf("\t\t ||                                                               ||\n");
	printf("\t\t ===================================================================\n");
	printf("                  Please input your choice  :  ");
	scanf_s("%d", &choice);
	return choice;
}
