/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#ifndef STATISTICS_
#define STATISTICS_
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "BookComponents.h"
#include "LibraryComponents.h"
#include "StudentComponents.h"
int StudentStatistics();
int StudentStatisticsENG(); // Calculating and statisting students in library's database
void StatsBasedSex();
void StatsBasedSexENG(); // Calculating and statisting students based sex type
void BookRemaining();
void BookRemainingENG();  // return total books in db
void BookStatsByGenre();
void BookStatsByGenreENG(); // stats by book's genre
void TotalBookInUse();
void TotalBookInUseENG(); // stats books in-use, not available for lending
void LateStats();
void LateStatsENG(); // stats students who are in out of time
#endif // !STATISTICS_
