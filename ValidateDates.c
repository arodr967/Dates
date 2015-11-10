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

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /* Use INT_MAX for the maximum value of an unsigned int. */

#define TRUE 1
#define FALSE 0
#define ARG_NUM 2 /* Max number of arguments. The first one, argv[0], is the
                     program and the second one, argv[1] is the number which 
                     we want to read up to. */
#define MAXDATE 1000
#define INPUT 1

//111, 157-160, 29

/* Start at 1 until 12 for each Month. */
enum months = {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC}:

/* Prototypes */
int getLine(char s[], int limit);
int validate(int month, int day, int year);
void getDate(int month, int day, int year)

int main(int argc, char *argv[])
{
    int day, month, year;
    char line[MAXLINE + 1];
    int input;
    
    if(argc == ARG_NUM)
    {
        input = atoi(argv(INPUT));
        
        if(input <= 0) /* Input ALL valid dates */
        {
            while(getLine(line, sizeof(line)) > 0)
            {
                getDate(month, day, year);
            }
        } else { /* Input up to the input provided of valid dates */
            
            while(input >= 0 && getLine(line, sizeof(line)) > 0)
            {
                getDate(month, day, year);
                input--; /* Decrement the input */
            }
            
        }
    }
    
    return 0;
}

void getDate(int month, int day, int year)
{
    if(scanf("%d %d %d", &month, &day, &year) == 3)
    {
        if(validate(&month, &day, &year) == TRUE)
        {
            printf("%d %d %d", &day, &month, &year);
        }
    }
}


/* getLine function: a line int a string and return the length of the string. */
int getLine(char s[], int limit)
{
    int c, i;
    
    for (i = 0 ; i < limit-1 && (c=getchar()) != EOF && c !='\n' ; ++i)
    {
        s[i] = c;
    }
        
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    
    /* Add the end of file character (null) after it is done reading */
    s[i] = '\0';
    return i;
}

int validate(int month, int day, int year)
{
    int leap;
    
    if((month >= 1 && month <= 12) )
}