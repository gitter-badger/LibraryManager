#include "Introduction.h"	
void Introduction() {
	printf("				                     DAI HOC QUOC GIA TPHCM        \n");
	printf("			                    TRUONG DAI HOC KHOA HOC TU NHIEN   \n");
	printf("\n");
	printf( "\n                                DO AN NHAP MON LAP TRINH 01     ");
	printf("\n                                CHUONG TRINH QUAN LY THU VIEN    ");
	printf("\n                            Sinh Vien  : Hoang Minh Hieu         ");
	printf("\n                            Lop        : 17CK1_CL - Khoa CNTT    ");
	printf("\n                            MSSV       : 1760311                 ");
	printf("\n                            Dien Thoai : 0125 428 0401           ");
	printf("\n                            Email      : 1760311@student.hcmus.edu.vn");
	printf("\n           See source code on my GitHub    : https://github.com/hyperion0201/LibraryManager");
}
int MainMenu() {
	int choice;
	printf( "\n          CHUONG TRINH QUAN LY THU VIEN  -- HOANG MINH HIEU -- 17CK1_CL        ");
	printf( "\n    ***************************************************************************");
	printf( "\n                          1 .Quan Ly Doc Gia       ");
	printf( "\n                          2 .Quan Ly Sach          ");
	printf( "\n							 3 .Lap Phieu Muon Sach   ");
	printf( "\n							 4 .Lap Phieu Tra Sach    ");
	printf( "\n							 5 .Cac  Thong Ke Co Ban  ");
	printf( "\n    ***************************************************************************");
	printf( "\n               Nhan Phim 0 De Xem Thong Tin Tac Gia  Chuong Trinh        ");
	printf( "\n    ***************************************************************************");
	printf( "\n                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung  :   ");
	scanf_s("%d", &choice);
	return choice;
}
int StudentManagementMenu() {
	int choice;
	printf("	   ****************** QUAN LI DOC GIA *********************\n");
	printf("	   ********************************************************\n");
	printf("					Vui long chon cac chuc nang !				\n");
	printf("			       1. Xem Doc Gia Trong Thu Vien				\n");
	printf("				   2. Them Doc Gia								\n");
	printf("                   3. Chinh Sua Thong Tin Mot Doc Gia           \n");
	printf("                   4. Xoa Thong Tin Mot Doc Gia                 \n");
	printf("                   5. Tim Kiem Doc Gia Theo CMND                \n");
	printf("                   6. Tim Kiem Sach Theo Ho Ten                 \n");
	printf("               Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
int BookManagementMenu() {
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
	printf("      ==========================================================\n");
	printf("           Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
int Statistics() {
	int choice;
	printf("      ===================== THONG KE CO BAN ====================\n");
	printf("      ==========================================================\n");
	printf("                   Vui long chon cac chuc nang !                \n");
	printf("                   1. Thong Ke So Luong Sach Trong Thu Vien     \n");
	printf("                   2. Thong Ke So Luong Sach Theo The Loai      \n");
	printf("                   3. Thong Ke So Luong Doc Gia                 \n");
	printf("                   4. Thong Ke So Luong Doc Gia Theo Gioi Tinh  \n");
	printf("                   5. Thong Ke So Sach Dang Duoc Muon           \n");
	printf("                   6. Thong Ke Danh Sach Doc Gia Bi Tre Han     \n");
	printf("      ==========================================================\n");
	printf("           Vui Long Chon Phim Chuc Nang :  ");
	scanf_s("%d", &choice);
	return choice;
}
