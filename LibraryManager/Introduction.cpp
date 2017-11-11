#include "Introduction.h"
#include "BookManagement.h"
#include "StudentManagement.h"
/*Starting Introduction function
Type : void
Input : none
Output: About author
*/
void Introduction() {
	system("cls");
	printf("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("  *                                                                                             *\n");
	printf("  *                                   DAI HOC QUOC GIA TPHCM                                    *\n");
	printf("  *                              TRUONG DAI HOC KHOA HOC TU NHIEN                               *\n");
	printf("  *                                                                                             *\n");
	printf("  *                                  DO AN NHAP MON LAP TRINH 01                                *\n");
	printf("  *                                 CHUONG TRINH QUAN LY THU VIEN                               *\n");
	printf("  *                            Sinh Vien  : Hoang Minh Hieu                                     *\n");
	printf("  *                            Lop        : 17CK1_CL - Khoa CNTT                                *\n");
	printf("  *                            MSSV       : 1760311                                             *\n");
	printf("  *                            Dien Thoai : 0125 428 0401                                       *\n");
	printf("  *                            Email      : 1760311@student.hcmus.edu.vn                        *\n");
	printf("  *         See source code on my GitHub    : https://github.com/hyperion0201/LibraryManager    *\n");
	printf("  *                                                                                             *\n");
	printf("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	_getch();
}
/*Starting InitializingComponents function
Type: void
Input : none
Output : waiting system for avoiding interrupts
*/
void InitializingComponents() {
	printf("\t=============== CHAO MUNG BAN DEN VOI QUAN LI THU VIEN =================\n");
	Sleep(5000);
	printf("\t Chuong trinh dang chuan bi du lieu. Vui long doi trong giay lat !");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". \n");
	printf("\t Luu y : De chuong trinh chay on dinh, \n \tban can phai nhap thong tin khoi dau cho 1 doc gia va 1 cuon sach dau tien.\n");
	Sleep(3000);
	printf("\t Ban da hieu roi chu. Bat dau nao. \n");
	Sleep(3000);
	printf("\n");
	printf("\t -> Nhap thong tin cho doc gia dau tien :\n");
	printf("\n");
	StudentDeclaration();
	printf("\n");
	printf("\t -> Nhap thong tin cho cuon sach dau tien : \n");
	printf("\n");
	BookDeclaration();
	Sleep(3000);
	printf("\t Thu vien da nhan duoc du lieu khoi dong. Chuong trinh se duoc tiep tuc");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". ");
	Sleep(1000);
	printf(". \n");
}
/*Starting MainMenu function
Type: integer
Input : none
Output : user's choice
*/
int MainMenu() {
	system("cls");
	int choice;
	printf( "          CHUONG TRINH QUAN LY THU VIEN  -- HOANG MINH HIEU -- 17CK1_CL          \n");
	printf( "      ****************************************************************************\n");
	printf( "                            1 .Quan Ly Doc Gia                                   \n");
	printf( "                            2 .Quan Ly Sach                                      \n");
	printf( "                            3 .Quan Li Phieu Muon,Tra Sach	                      \n");
	printf( "                            5 .Cac  Thong Ke Co Ban                              \n");
	printf( "                            0. Xem Thong Tin Tac Gia                             \n");
	printf( "\t     ***************************************************************************\n");
	printf( "                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung  :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting StudentManagementMenu function
Type: int
Input: none
Output: user's choice
*/
int StudentManagementMenu() {
	system("cls");
	int choice;
	printf("        ======================= QUAN LI DOC GIA =======================\n");

	printf("                        Vui long chon cac chuc nang !				\n");
	printf("                        1. Xem Doc Gia Trong Thu Vien				\n");
	printf("                        2. Them Doc Gia								\n");
	printf("                        3. Chinh Sua Thong Tin Mot Doc Gia           \n");
	printf("                        4. Xoa Thong Tin Mot Doc Gia                 \n");
	printf("                        5. Tim Kiem Doc Gia Theo CMND                \n");
	printf("                        6. Tim Kiem Sach Theo Ho Ten                 \n");
	printf("                        0. Quay lai menu chinh                       \n");
	printf("        ===============================================================\n");
	printf("                      Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting BookManagementMenu function
Type : int
Input: none
Output : user's choice
*/
int BookManagementMenu() {
	system("cls");
	int choice;
	printf("      ===================== QUAN LI SACH =======================\n");
	printf("      ==========================================================\n");
	printf("                   Vui long chon cac chuc nang !                \n");
	printf("                   1. Xem Danh Sach Cac Sach Co Trong Thu Vien  \n");
	printf("                   2. Them Sach                                 \n");
	printf("                   3. Chinh Sua Thong Tin Mot Quyen Sach        \n");
	printf("                   4. Xoa Thong Tin Sach                        \n");
	printf("                   5. Tim Kiem Sach Theo ISBN                   \n");
	printf("                   6. Tim Kiem Sach Theo Ten Sach               \n");
	printf("                   0. Quay lai menu chinh                       \n");
	printf("      ==========================================================\n");
	printf("           Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
/*Starting Statistics function
Type : int
Input: none
Output :user's input
*/
int StatisticsMenu() {
	system("cls");
	int choice;
	printf("      ===================== THONG KE CO BAN ====================\n");
	printf("                  Vui long chon cac chuc nang !                \n");
	printf("                  1. Thong Ke So Luong Sach Trong Thu Vien     \n");
	printf("                  2. Thong Ke So Luong Sach Theo The Loai      \n");
	printf("                  3. Thong Ke So Luong Doc Gia                 \n");
	printf("                  4. Thong Ke So Luong Doc Gia Theo Gioi Tinh  \n");
	printf("                  5. Thong Ke So Sach Dang Duoc Muon           \n");
	printf("                  6. Thong Ke Danh Sach Doc Gia Bi Tre Han     \n");
	printf("      ==========================================================\n");
	printf("                   Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
