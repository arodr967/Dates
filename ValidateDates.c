/*
 File Name: ValidateDates.c
 
 Description:   
    Accept input via command-line arguments. The input will be the number
    of valid entries to be redirected from the dates input file
    (dates.dat). A zero indicates to input all entries from the dates input
    file. This input will then be piped out to the second program,
    FormatDates.c.
    
    This program will also handle corrupt dates in the dates.dat file.
 
 Disclaimer: 
    I hereby certify that this collective work is my own
    and none of it is the work of any other person or entity.
 
 Created by Alicia Rodriguez.
 Panther ID: 5162522

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /* Use INT_MAX for the maximum value of an unsigned int. */

#define TRUE 1
#define FALSE 0
#define ARG_NUM 2 /* Max number of arguments. The first one, argv[0], is the
                     program and the second one, argv[1] is the number which 
                     we want to read up to. */
#define MAXLINE 100 /* The maximum number of entries each line can contain */
#define INPUT 1 /* The input is in argument 1 (e.g. argv[1]) */

/* Start at 1 until 12 for each Month. */
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

/* Prototypes */
int getLine(char line[], int limit);
int validate(int month, int day, int year);
void getDate(int month, int day, int year);


/* main function: accept input via command-line arguments and 
   generate the dates. */
int main(int argc, char *argv[])
{
    int day, month, year, input; /* Input, for the number of lines we want
                                    to read from the file */
    char line[MAXLINE + 1];
    
    if(argc == ARG_NUM)
    {
        input = atoi(argv[INPUT]);
        
        if(input > INT_MAX) {
            input = INT_MAX; /* To make sure that the input number does not
                                exceed the int maximum. */
        }
        
        getDate(month, day, year); /* Read the first line of the file */
        
        if(input <= 0) /* Input ALL valid dates */
        {
            while(getLine(line, sizeof(line)) > 0)
            {
                getDate(month, day, year);
            }
        } else { /* Input up to the input provided of valid dates */
            
            while(input > 0 && getLine(line, sizeof(line)) > 0)
            {
                getDate(month, day, year);
                input--; /* Decrement the input */
            }
        }
    }
    return 0;
}

/* validate function: validate the date. */
int validate(int month, int day, int year)
{
    /* test for leap years: */
    int leapYear = ((year%4 == 0 && year % 100 != 0) || year % 400 == 0);
    
    
    if((month >= 1 && month <= 12) && (day >= 1 && day <= 31))
    {
        if((month == JAN || month == MAR || month == MAY || month == JUL || month == AUG || month == OCT || month == DEC))
        {
            return TRUE;
        } else if((day >= 1 && day <= 30) && (month == APR || month == JUN || month == SEP || month == NOV))
        {
            return TRUE;
        } else if(((day >1 && day <= 28) && month == FEB && !leapYear) || ((day >1 && day <= 29) && month == FEB && leapYear))
        {
            return TRUE;
        }
    } 
    
    return FALSE;
}

/* getDate function: gets the dates and validates them. */
void getDate(int month, int day, int year)
{
    if(scanf("%d/%d/%d", &month, &day, &year) == 3)
    {
        if(validate(month, day, year))
        {
            /* Print here to the second program in the day, month, year format */
            printf("%d/%d/%d\n", day, month, year);
        }
    }
}

/* getLine function: get a line and return the length of the string. */
int getLine(char line[], int limit)
{
    int c, i;
    
    for (i = 0 ; i < limit-1 && ((c=getchar()) != EOF) && c !='\n' ; ++i)
    {
        line[i] = c;
    }
    
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    
    /* Add the end of file character (null) after it is done reading */
    line[i] = '\0';
    return i;
}