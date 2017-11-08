#include "Introduction.h"
#include "BookManagement.h"
#include "StudentManagement.h"

void main() {
	int menuchoice, smchoice, bmchoice;
	// Initialising components as waiting for avoiding interupt
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
	Sleep(5000);
	printf("\t Ban da hieu roi chu. Bat dau nao \n");
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
	printf(". ");
	menuchoice = MainMenu();
	switch (menuchoice)
	{
	case 0: Introduction();
	case 1: {
		system("cls");
		smchoice = StudentManagementMenu();
		switch (smchoice)
		{
		case 1: StudentListing(); break;
		case 2: StudentCreating(); break;
		case 3: {
			fflush(stdin);
			char xemdg;
			printf("Vui long xem danh sach doc gia de biet vi tri cua doc gia do.");
			printf("Ban co muon xem danh sach doc gia khong ? Neu co, nhan Y, neu khong, nhan N : " );
			xemdg = getchar();
			if (xemdg == 'Y' || xemdg == 'y') StudentListing();
			else printf("-> Bat dau chinh sua\n");
			int editw;
			printf("Nhap vi tri cua doc gia muon sua : ");
			scanf_s("%d", &editw);
			ESSubMenu(editw);
		} break;
		case 4: {
			fflush(stdin);
			int deletew;
			printf("Nhap vi tri cua doc gia muon sua : ");
			scanf_s("%d", &deletew);
			StudentEditing(deletew);
		} break;
		case 5: {
			fflush(stdin);
			char cmnd[25];
			printf("Nhap vao CMND doc gia can tim : ");
			gets_s(cmnd);
			SearchByID(cmnd);
		} break;
		case 6: {
			char hoten[25];
			fflush(stdin);
			printf("Nhap vao ho ten doc gia can tim (Chu y: viet hoa chu cai dau, co dau cach giua cac chu) : ");
			gets_s(hoten);
			SearchByName(hoten);
		} break;
		case 0: break;
		default: printf("Lenh khong hop le, vui long thu lai..");
			break;
		}
	}
	case 2: {
		system("cls");
		bmchoice = BookManagementMenu();
		switch (bmchoice)
		{
		case 1: BookListing(); break;
		case 2: BookCreating(); break;
		case 3: {
			fflush(stdin);
			int vitrisua;
			printf("Nhap vao so thu tu cuon sach can sua : ");
			scanf_s("%d", &vitrisua);
			EBSubMenu(vitrisua);
		} break;
		case 4: {
			fflush(stdin);
			int vitrixoa;
			printf("Nhap vao so thu tu cuon sach can xoa : ");
			scanf_s("%d", &vitrixoa);
			BookDeleting(vitrixoa); 
		} break;
		case 5: {
			char isbn[30];
			printf("Nhap ma sach can tim kiem : ");
			gets_s(isbn);
			SearchByISBN(isbn);
		} break;
		case 6: {
			char tensach[30];
			printf("Nhap vao ten sach can tim : ");
			gets_s(tensach);
			SearchByBookName(tensach);
		} break;
		case 0: break;
		default: printf("Lenh khong hop le, vui long thu lai..");
			break;
		}
	}
	default:
		break;
	}
	_getch();
}