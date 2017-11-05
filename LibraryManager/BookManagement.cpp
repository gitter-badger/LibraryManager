#include "BookManagement.h"
// Initialising arrays stored book informations
char ISBN[Max][25], BookName[Max][30], Author[Max][25], Producer[Max][30], YearProducing[Max][25],
Genre[Max][25], Cost[Max][25];
int Amount[Max];
// Init book in library counter
int bookcounter = 0;
/* Starting BookDeclaration for default database.
Input: informations on arrays
Output : informations stored for max 3 books
*/
void BookDeclaration() {
	while (true)
	{
		if (bookcounter > Max) printf("Khong du bo nho de them sach !");
		else while (bookcounter<Max)
		{
			printf("================ THONG TIN CUON SACH THU %d ==============\n", bookcounter + 1);
			fflush(stdin); //clear caches
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
		if (bookcounter >= 3) break; //Declaring max 3 books
	}
}
/* Starting BookCreating function
Input : none
Output : book informations
*/
void BookCreating() {

}