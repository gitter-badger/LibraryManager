/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "BookManagement.h"
#include "BookComponents.h"
/* Starting GetBookInfo function
Input: book position
Output: Info
*/
/* Starting BookDeclaration for default database.
Input: informations on arrays
Output : informations stored for max 1 books
*/
void BookDeclaration() {
	while (true)
	{
		if (bookcounter > Max) printf("Khong du bo nho de them sach !");
		else while (bookcounter<Max)
		{
			printf("================ THONG TIN CUON SACH THU %d ==============\n", bookcounter + 1);
			fflush(stdin);//clear caches
			getchar();
			printf("    -> ISBN cuon sach thu %d : ", bookcounter + 1);
			
			gets_s(ISBN[bookcounter]);
			printf("    -> Ten cuon sach thu %d : ", bookcounter + 1);
			gets_s(BookName[bookcounter]);
			printf("    -> Ten tac gia cuon sach thu %d : ", bookcounter + 1);
			gets_s(Author[bookcounter]);
			printf("    -> Nha san xuat cuon sach thu %d : ", bookcounter + 1);
			gets_s(Producer[bookcounter]);
			printf("    -> Nam san xuat cuon sach thu %d : ", bookcounter + 1);
			gets_s(YearProducing[bookcounter]);
			printf("    -> The loai cuon sach thu %d : ", bookcounter + 1);
			gets_s(Genre[bookcounter]);
			printf("    -> Gia thanh cuon sach thu %d : ", bookcounter + 1);
			scanf_s("%d", &Cost[bookcounter]);
			printf("    -> So luong cuon nhap ve : ");
			scanf_s("%d", &Amount[bookcounter]);
			TotalBook += Amount[bookcounter];
			readybook += Amount[bookcounter];
			bookcounter++; break;
		}
		if (bookcounter >= 1) break; //Declaring max 3 books
	}
}
/* Starting BookCreating function
Input : none
Output : book informations
*/
void BookCreating() {
	 while (true)
	 {
		 int choice;
		 printf("===================== MENU TAO SACH ========================\n");
		 printf("                 -> 1. Tao sach moi                         \n");
		 printf("                 -> 2. Thoat                                   \n");
		 printf("===============================================================\n");
		 printf("      -> Nhap vao lua chon cua ban : ");
		 scanf_s("%d", &choice);
		 if (choice == 1)
		 {
			 if (bookcounter > Max) printf("Khong du bo nho de tao hay cap nhat sach !");
			 else while (bookcounter < Max)
			 {
				 printf("============ THONG TIN CUON SACH THU %d ============\n", bookcounter + 1);
				 fflush(stdin);
				 getchar();
				 printf("    -> Nhap ma sach : ");
				 gets_s(ISBN[bookcounter]);
				 printf("    -> Nhap ten sach : ");
				 gets_s(BookName[bookcounter]);
				 printf("    -> Nhap tac gia : ");
				 gets_s(Author[bookcounter]);
				 printf("    -> Nhap ten nha san xuat : ");
				 gets_s(Producer[bookcounter]);
				 printf("    -> Nhap nam san xuat : ");
				 gets_s(YearProducing[bookcounter]);
				 printf("    -> Nhap the loai : ");
				 gets_s(Genre[bookcounter]);
				 printf("    -> Nhap gia : ");
				 scanf_s("%d", &Cost[bookcounter]);
				 printf("    -> Nhap vao so luong sach nhap ve : ");
				 scanf_s("%d", &Amount[bookcounter]);
				 TotalBook += Amount[bookcounter];
				 readybook += Amount[bookcounter];
				 bookcounter++; 
				 Sleep(1000);
				 printf("Tao sach moi thanh cong !\n");
				 Sleep(500);
				 break;
			 }
			// continue;
		 }
		 else if (choice == 2) break;
		 break;
	 }
 }
/* Starting BookListing function
Input : none
Output : listed books
*/
 void BookListing() {
	 printf("\t\t============= DANH SACH CAC SACH CO TRONG THU VIEN =============\n\n");
		if (bookcounter <= 0) printf("Hien tai chua co cuon sach nao trong co so du lieu thu vien !\n Vui long them sach.. \n");
	for (int i = 0; i < bookcounter; i++)
	{
		printf("\n");
		printf(" ============ THONG TIN CUON SACH THU %d =======================\n", i + 1);
		printf("   -> Ma sach : ");
		puts(ISBN[i]);
		printf("   -> Ten sach : ");
		puts(BookName[i]);
		printf("   -> Tac gia : ");
		puts(Author[i]);
		printf("   -> Nha xuat ban : ");
		puts(Producer[i]);
		printf("   -> Nam xuat ban : ");
		puts(YearProducing[i]);
		printf("   -> The loai : ");
		puts(Genre[i]);
		printf("   -> Gia thanh : %d VND \n", Cost[i]);
		printf("   -> So luong co san : %d\n", Amount[i]);
	}
	_getch();
}
/* Starting BookEditing function
Input : book position
Output: listed books available
*/
void BookEditing(int number){
	if (number > 0 && number <= bookcounter)
	{
		int choice;
		printf("============== MENU CHINH SUA SACH ================\n");
		printf("    1. Chinh sua ISBN\n");
		printf("    2. Chinh sua ten sach \n");
		printf("    3. Chinh sua tac gia \n");
		printf("    4. Chinh sua nha xuat ban \n");
		printf("    5. Chinh sua nam xuat ban \n");
		printf("    6. Chinh sua the loai\n");
		printf("    7. Chinh sua gia\n");
		printf("    8. Chinh sua so luong\n");
		printf("==================================================\n");
		printf(" Nhap vao lua chon cua ban : ");
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1: {
			fflush(stdin);
			char NewISBN[25];
			printf("Nhap vao ISBN moi : ");
			gets_s(NewISBN);
			strcpy_s(ISBN[number-1], NewISBN);
			Sleep(1000);
			printf("Chinh sua thanh cong !");
			Sleep(500);
		} break;
		case 2: {
			fflush(stdin);
			char NewBookName[25];
			printf(" Nhap vao ten moi : ");
			gets_s(NewBookName);
			strcpy_s(BookName[number - 1], NewBookName);
			Sleep(1000);
			printf("Chinh sua thanh cong !");
			Sleep(500);
		} break;
		case 3: {
			fflush(stdin);
			char NewAuthor[25];
			printf("Nhap vao tac gia moi : ");
			gets_s(NewAuthor);
			strcpy_s(Author[number - 1], NewAuthor);
			Sleep(1000);
			printf("Chinh sua thanh cong !");
			Sleep(500);
		} break;
		case 4: {
			fflush(stdin);
			char NewProducer[25];
			printf("Nhap vao nha xuat ban moi : ");
			gets_s(NewProducer);
			strcpy_s(Producer[number - 1], NewProducer);
			Sleep(1000);
			printf("Chinh sua thanh cong !");
			Sleep(500);
		} break;
		case 5: {
			fflush(stdin);
			char NewYearProducing[25];
			printf("Nhap vao nam san xuat moi : ");
			gets_s(NewYearProducing);
			strcpy_s(YearProducing[number - 1], NewYearProducing);
			Sleep(1000);
			printf("Chinh sua thanh cong !");
			Sleep(500);
		} break;
		case 6: {
			fflush(stdin);
			char NewGenre[25];
			printf(" Nhap vao the loai moi : ");
			gets_s(NewGenre);
			strcpy_s(Genre[number - 1], NewGenre);
			Sleep(1000);
			printf("Chinh sua thanh cong !");
			Sleep(500);
		} break;
		case 7: {
			fflush(stdin);
			int newcost;
			printf("Nhap vao gia moi : ");
			scanf_s("%d", &newcost);
			Cost[number - 1] = newcost;
			Sleep(1000);
			printf("Chinh sua thanh cong !");
			Sleep(500);
		} break;
		case 8:
		{
			int sl;
			TotalBook -= Amount[number - 1];
			printf(" -> Nhap vao so luong moi : ");
			scanf_s("%d", &sl);
			Amount[number - 1] = sl;
			TotalBook += Amount[number - 1];
			break;
		}
		default: 
		{
			printf(" Lua chon khong hop le ! Vui long thu lai ..");
			Sleep(500);
			break;
		}

		}
	}
	else
	{
		printf("Co loi xay ra khi chinh sua! Vui long thoat ra menu chinh va thu lai..");
		Sleep(500);
	}

}
/* Starting EBSubMenu function
Input : choice
Output : 
*/
 void EBSubMenu(int number) {
	while (true)
	{
		if (number > 0 && number <= bookcounter)
		{
			system("cls");
			int choice;
			printf("==================== MENU CHINH SUA SACH ====================\n");
			printf("\n");
			printf("     -> 1. Tiep tuc chinh sua va cap nhat cuon sach thu %d\n", number);
			printf("     -> 2. Xem thong tin cuon sach thu %d sau khi chinh sua\n", number);
			printf("     -> 3. Thoat chinh sua\n");
			printf("=============================================================\n");
			printf("  Nhap vao lua chon cua ban : ");
			scanf_s("%d", &choice);
			if (choice == 3) break;
			switch (choice)
			{
			case 1: BookEditing(number); break;
			case 2: SeeBookChanges(number); break;
			default: printf("Lenh khong ton tai, xin thu lai..");
				break;
			}
		}
		else
		{
			printf("Du lieu sach khong ton tai trong thu vien ! Vui long thu lai ...\n");
			Sleep(1000);
			break;
		}
	}
	//_getch();
}
/* Starting SeeBookChanges function
Input: book position
Output: Book informations
*/
void SeeBookChanges(int number) {
	printf("============ THONG TIN CUON SACH THU %d SAU KHI CHINH SUA ==============\n", number);
	printf("   -> Ma sach : ");
	puts(ISBN[number - 1]);
	printf("   -> Ten sach : ");
	puts(BookName[number - 1]);
	printf("   -> Tac gia : ");
	puts(Author[number - 1]);
	printf("   -> Nha xuat ban : ");
	puts(Producer[number - 1]);
	printf("   -> Nam xuat ban : ");
	puts(YearProducing[number - 1]);
	printf("   -> The loai : ");
	puts(Genre[number - 1]);
	printf("   -> Gia thanh : %d VND \n", Cost[number-1]);
	printf("   -> So luong co san : %d\n", Amount[number - 1]);
	_getch();
}
/* Starting BookDeleting function
Input: book position
Output: Listed book available
*/
 void BookDeleting(int number) {
	int flag = 0;
	if (number > 0 && number <= bookcounter) {
		for (int i = number - 1; i < bookcounter - 1; i++) {
			strcpy_s(ISBN[i], ISBN[i + 1]);
			strcpy_s(BookName[i], BookName[i + 1]);
			strcpy_s(Author[i], Author[i + 1]);
			strcpy_s(Producer[i], Producer[i + 1]);
			strcpy_s(YearProducing[i], YearProducing[i + 1]);
			strcpy_s(Genre[i], Genre[i + 1]);
			Cost[i] = Cost[i + 1];
			TotalBook -= Amount[i];
			Amount[i] = Amount[i + 1];
		}
		bookcounter--;
		flag = 1;
	}
	if (flag == 1) {
		printf(" -> Xoa thanh cong !\n");
		printf("\n");
		Sleep(500);
		BookListing();
	}
	else
	{
		printf("Co loi khi xoa, vui long thu lai..");
		Sleep(500);
	}
}
/* Starting SearchByBookName function
Input: Book's name
Output : Return info if it matched
*/
 void SearchByBookName(char name[30]) {
	int flag = 0;
	printf("============ KET QUA TIM KIEM ===========\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(name, BookName[i]) == 0) {
			printf("\n");
			printf("    -> Ma sach : ");
			puts(ISBN[i]);
			printf("    -> Ten sach : ");
			puts(BookName[i]);
			printf("    -> Tac gia : ");
			puts(Author[i]);
			printf("    -> Nha xuat ban : ");
			puts(Producer[i]);
			printf("    -> Nam xuat ban : ");
			puts(YearProducing[i]);
			printf("    -> The loai : ");
			puts(Genre[i]);
			printf("    -> Gia(VND) : %d\n", Cost[i]);
			printf("==========================================\n");
			flag++;
		}	
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d sach duoc tim thay.\n", flag);
	}
	_getch();
}
/* Starting SearchByISBN function
Input: ISBN[25]
Output : Return info if it matched
*/
 void SearchByISBN(char isbn[30]) {
	int flag = 0;
	printf("============ KET QUA TIM KIEM ===========\n");
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(isbn, ISBN[i]) == 0) {
			printf("\n");
			printf("    -> Ma sach : ");
			puts(ISBN[i]);
			printf("    -> Ten sach : ");
			puts(BookName[i]);
			printf("    -> Tac gia : ");
			puts(Author[i]);
			printf("    -> Nha xuat ban : ");
			puts(Producer[i]);
			printf("    -> Nam xuat ban : ");
			puts(YearProducing[i]);
			printf("    -> The loai : ");
			puts(Genre[i]);
			printf("    -> Gia(VND) : %d\n", Cost[i]);
			printf("==========================================\n");
			flag++;
		}
	}
	if (flag == 0) printf("Khong tim thay ket qua !");
	else
	{
		printf("\n");
		printf("   - > Tong cong co %d sach duoc tim thay.\n", flag);
	}
	_getch();
}
