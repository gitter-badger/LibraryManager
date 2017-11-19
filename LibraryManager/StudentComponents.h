/*
  	Copyright™ Hieu Hoang Minh. The Library Manager Project.
  	See source code on https://github.com/hyperion0201/LibraryManager
    Free for personal and commercial use under the MIT license .
	2017. Ho Chi Minh University of Science.
*/
#ifndef STUDENTCOMPONENTS_
#define STUDENTCOMPONENTS_
#define Max 1000
// Initialising arrays include student information
extern char LibraryID[Max][25], Name[Max][25], ID[Max][25], Birth[Max][25], Sex[Max][25], Email[Max][25], Address[Max][50];
extern int DayCre[Max];
extern int MonthCre[Max];
extern int YearCre[Max];
extern int DayEx[Max];
extern int MonthEx[Max];
extern int YearEx[Max];
extern int studentcounter ; // Initialising student number counter
#endif // !STUDENTCOMPONENTS_
