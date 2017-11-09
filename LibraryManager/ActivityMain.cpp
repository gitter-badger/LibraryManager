#include "Introduction.h"
#include "BookManagement.h"
#include "StudentManagement.h"

void main() {
	int menuchoice, smchoice, bmchoice;
	// Initialising components as waiting for avoiding interupt
	InitializingComponents();
	system("cls");
	menuchoice = MainMenu();
	switch (menuchoice)
	{
	case 0: Introduction(); break;
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
		} break;
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