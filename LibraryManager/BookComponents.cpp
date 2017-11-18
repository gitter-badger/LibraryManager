/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#include "BookComponents.h"
// Initialising arrays stored book informations
char ISBN[Max][30], BookName[Max][30], Author[Max][25], Producer[Max][30], YearProducing[Max][25],
Genre[Max][25];
int Amount[Max];
int TotalBook = 0;
int readybook = 0;
int Cost[Max];
// Init book in library counter
int bookcounter = 0;