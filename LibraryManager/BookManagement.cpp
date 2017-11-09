#include "BookManagement.h"
// Initialising arrays stored book informations
char ISBN[Max][30], BookName[Max][30], Author[Max][25], Producer[Max][30], YearProducing[Max][25],
Genre[Max][25], Cost[Max][25];
int Amount[Max];
// Init book in library counter
int bookcounter = 0;
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
			gets_s(Cost[bookcounter]);
			printf("    -> So luong cuon nhap ve : ");
			scanf_s("%d", &Amount[bookcounter]);
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
		if (bookcounter > Max) printf("Khong du bo nho de tao hay cap nhat sach !");
		else while (bookcounter<Max)
		{
			printf("============ THONG TIN CUON SACH THU %d ============\n", bookcounter + 1);
			fflush(stdin);
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
			gets_s(Cost[bookcounter]);
			printf("    -> Nhap vao so luong sach : ");
			scanf_s("%d", Amount[bookcounter]);
			bookcounter++; break;
		}
	}
}
/* Starting BookListing function
Input : none
Output : listed books
*/
void BookListing() {
	for (int i = 0; i < bookcounter; i++)
	{
		printf("============= DANH SACH CAC SACH CO TRONG THU VIEN =============\n");
		printf(" \n");
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
		printf("   -> Gia thanh : ");
		puts(Cost[i]);
		printf("   -> So luong co san : %d", Amount[i]);
	}
}
/* Starting BookEditing function
Input : book position
Output: listed books available
*/
void BookEditing(int number){
	if (number > 0 && number < Max)
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
		switch (choice)
		{
		case 1: {
			fflush(stdin);
			char NewISBN[25];
			printf("Nhap vao ISBN moi : ");
			gets_s(NewISBN);
			strcpy_s(ISBN[number-1], NewISBN);
		} break;
		case 2: {
			fflush(stdin);
			char NewBookName[30];
			printf(" Nhap vao ten moi : ");
			gets_s(NewBookName);
			strcpy_s(BookName[number - 1], NewBookName);
		} break;
		case 3: {
			fflush(stdin);
			char NewAuthor[25];
			printf("Nhap vao tac gia moi : ");
			gets_s(NewAuthor);
			strcpy_s(Author[number - 1], NewAuthor);
		} break;
		case 4: {
			fflush(stdin);
			char NewProducer[25];
			printf("Nhap vao nha xuat ban moi : ");
			gets_s(NewProducer);
			strcpy_s(Producer[number - 1], NewProducer);
		} break;
		case 5: {
			fflush(stdin);
			char NewYearProducing[25];
			printf("Nhap vao nam san xuat moi : ");
			gets_s(NewYearProducing);
			strcpy_s(YearProducing[number - 1], NewYearProducing);
		} break;
		case 6: {
			fflush(stdin);
			char NewGenre[25];
			printf(" Nhap vao the loai moi : ");
			gets_s(NewGenre);
			strcpy_s(Genre[number - 1], NewGenre);
		} break;
		case 7: {
			fflush(stdin);
			char NewCost[25];
			printf("Nhap vao gia moi : ");
			gets_s(NewCost);
			strcpy_s(Cost[number - 1], NewCost);
		} break;
		default: printf(" Lua chon khong hop le ! Vui long thu lai ..");
			break;
		}
	}
	else printf("Co loi xay ra khi chinh sua! Vui long thoat ra menu chinh va thu lai..");
}
/* Starting EBSubMenu function
Input : choice
Output : 
*/
void EBSubMenu(int number) {
	while (true)
	{
		int choice;
		printf("=========== Menu Chinh Sua Va Cap Nhat Sach =================\n");
		printf("\n");
		printf("     -> 1. Tiep tuc chinh sua va cap nhat cuon sach\n");
		printf("     -> 2. Xem thong tin cuon sach sau khi chinh sua\n");
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
}
/* Starting SeeBookChanges function
Input: book position
Output: Book informations
*/
void SeeBookChanges(int number) {
	printf("============ Thong Tin Cuon Sach Thu %d Sau Khi Chinh Sua ==============\n", number);
	printf("   -> Ma sach : ");
	puts(ISBN[number + 1]);
	printf("   -> Ten sach : ");
	puts(BookName[number + 1]);
	printf("   -> Tac gia : ");
	puts(Author[number + 1]);
	printf("   -> Nha xuat ban : ");
	puts(Producer[number + 1]);
	printf("   -> Nam xuat ban : ");
	puts(YearProducing[number + 1]);
	printf("   -> The loai : ");
	puts(Genre[number + 1]);
	printf("   -> Gia thanh : ");
	puts(Cost[number + 1]);
	printf("   -> So luong co san : %d", Amount[number + 1]);
}
/* Starting BookDeleting function
Input: book position
Output: Listed book available
*/
void BookDeleting(int number) {
	int flag = 0;
	if (number >= 0 && number < bookcounter) {
		for (int i = number - 1; i < bookcounter - 1; i++) {
			strcpy_s(ISBN[number], ISBN[number + 1]);
			strcpy_s(BookName[number], BookName[number + 1]);
			strcpy_s(Author[number], Author[number + 1]);
			strcpy_s(Producer[number], Producer[number + 1]);
			strcpy_s(YearProducing[number], YearProducing[number + 1]);
			strcpy_s(Genre[number], Genre[number + 1]);
			strcpy_s(Cost[number], Cost[number + 1]);
			Amount[number] = Amount[number + 1];
		}
		bookcounter--; flag = 1;
	}
	if (flag == 1) {
		printf("============ Danh Sach Quyen Sach Trong Thu Vien Sau Khi Xoa ================\n");
		BookListing();
	}
	else printf("Co loi khi xoa, vui long thu lai..");
}
/* Starting SearchByBookName function
Input: Book's name
Output : Return info if it matched
*/
void SearchByBookName(char name[30]) {
	int flag = 0;
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(name, BookName[i]) == 0) {
			printf("============ KET QUA TIM KIEM ===========\n");
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
			printf("    -> Gia(VND) : ");
			puts(Cost[i]);
			printf("==========================================\n");
			flag = 1; break;
		}	
	}
	if (flag != 1) printf("Khong tim thay sach hoac co loi khi tim kiem. Vui long thu lai..");
}
/* Starting SearchByISBN function
Input: ISBN[25]
Output : Return info if it matched
*/
void SearchByISBN(char isbn[30]) {
	int flag = 0;
	for (int i = 0; i < bookcounter; i++) {
		if (strcmp(isbn, ISBN[i]) == 0) {
			printf("============ KET QUA TIM KIEM ===========\n");
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
			printf("    -> Gia(VND) : ");
			puts(Cost[i]);
			printf("==========================================\n");
			flag = 1; break;
		}
	}
	if (flag != 1) printf("Khong tim thay ket qua hoac co loi khi tim kiem, vui long thu lai..");
}
