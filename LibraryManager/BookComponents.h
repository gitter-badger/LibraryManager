#ifndef BOOKCOMPONENTS_
#define BOOKCOMPONENTS_
#define Max 1000
// Initialising arrays stored book informations
extern char ISBN[Max][30], BookName[Max][30], Author[Max][25], Producer[Max][30], YearProducing[Max][25],
Genre[Max][25];
extern int Amount[Max];
extern int TotalBook;
extern int readybook;
extern int Cost[Max];
// Init book in library counter
extern int bookcounter;
#endif // !BOOKCOMPONENTS_
