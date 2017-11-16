#ifndef STATISTICS_
#define STATISTICS_
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "BookComponents.h"
#include "LibraryComponents.h"
#include "StudentComponents.h"
int StudentStatistics();    // Calculating and statisting students in library's database
void StatsBasedSex();       // Calculating and statisting students based sex type
void BookRemaining(); // return total books in db
void BookStatsByGenre();  // stats by book's genre
void TotalBookInUse();  // stats books in-use, not available for lending
void LateStats(); // stats students who are in out of time
#endif // !STATISTICS_
