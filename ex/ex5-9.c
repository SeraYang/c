/*
 * A solution to exercise 5-9 in K&R2, page 114:
 *
 *	Rewrite the routines day_of_year and month_day with pointers
 *	instead of indexing.
 *
 * Lars Wirzenius <liw@iki.fi>
 */

#include <stdio.h>

static char daytab[2][13] =  {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* original versions, for comparison purposes */

int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}


/* pointer versions */

int day_of_year_pointer(int year, int month, int day)
{
	int i, leap;
	char *p;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	/* Set `p' to point at first month in the correct row. */
	p = &daytab[leap][1];

	/* Move `p' along the row, to each successive month. */
	for (i = 1; i < month; i++) {
		day += *p;
		++p;
	}
	return day;
}

void month_day_pointer(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	char *p;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	p = &daytab[leap][1];
	for (i = 1; yearday > *p; i++) {
		yearday -= *p;
		++p;
	}
	*pmonth = i;
	*pday = yearday;
}


int main(void)
{
	int year, month, day, yearday;
	
	year = 2000;
	month = 3;
	day = 1;
	printf("The date is: %d-%02d-%02d\n", year, month, day);
	printf("day_of_year: %d\n", day_of_year(year, month, day));
	printf("day_of_year_pointer: %d\n", 
		day_of_year_pointer(year, month, day));


	yearday = 61;	/* 2000-03-01 */
	month_day(year, yearday, &month, &day);
	printf("Yearday is %d\n", yearday);
	printf("month_day: %d %d\n", month, day);
	month_day_pointer(year, yearday, &month, &day);
	printf("month_day_pointer: %d %d\n", month, day);
	
	return 0;
}


//And here's Greg's: @br @br
/* Gregory Pietsch - gkp1@flash.net */

/* Given the problem, I thought that this would be a better
 * description of daytab.
 */
static int *daytab = {
    0, 
    31,
    31+28,
    31+28+31,
    31+28+31+30,
    31+28+31+30+31,
    31+28+31+30+31+30,
    31+28+31+30+31+30+31,
    31+28+31+30+31+30+31+31,
    31+28+31+30+31+30+31+31+30,
    31+28+31+30+31+30+31+31+30+31,
    31+28+31+30+31+30+31+31+30+31+30,
    0, 
    31,
    31+29,
    31+29+31,
    31+29+31+30,
    31+29+31+30+31,
    31+29+31+30+31+30,
    31+29+31+30+31+30+31,
    31+29+31+30+31+30+31+31,
    31+29+31+30+31+30+31+31+30,
    31+29+31+30+31+30+31+31+30+31,
    31+29+31+30+31+30+31+31+30+31+30,
};

/* is it a leap year?  (assume it's my calendar, the Gregorian) */
int leap(int year)
{
    return ((year % 4) == 0) 
            && (((year % 100) != 0)
                || (year % 400) == 0);
}

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    return *(daytab + ((month - 1) + (leap(year) * 12))) + day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int m, ly;

    ly = leap(year);
    if (yearday < 1 || yearday > (365 + ly))
        return; /* no real error checking */
    m = leap(year) ? 23 : 11;
    while (*(daytab + m) > yearday)
        m--;
    if (pmonth)
        *pmonth = (m % 12) + 1;
    if (pday)
        *pday = yearday - (*(daytab + m));
}
