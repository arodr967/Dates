/*
 File Name: FormatDates.c
 
 Description:  
    Accept the validated dates in month/day/year format and convert
    each of them to the day, abbreviated month & year format 
    (i.e. 1 JAN 1990). The abbreviated month consist of the first
    three letters of the month, capitalized.
 
    The converted results will be redirected to the output file 
    (output.dat), followed by a copy of the original (dates.dat) data.
 
 Disclaimer:
    I hereby certify that this collective work is my own
    and none of it is the work of any other person or entity.
 
 Created by Alicia Rodriguez.
 Panther ID: 5162522
 
 */

#include <stdio.h>
#include <stdlib.h>

/* String array of the months for printing. */
char *theMonths[] = {"NIL", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

/* main function: print to the output.dat file and valid formatted dates
   and open the dates.dat file */
int main(int argc, char *argv[])
{
    int day, month, year, buffer;
    FILE *fptr; /* Create the file pointer */
    
    printf("\nThe valid formatted dates...\n\n");
    
    /* Print to the output file. */
    while(scanf("%d/%d/%d", &day, &month, &year) == 3) {
        printf("%d %s %d\n", day, theMonths[month], year);
    }
    
    printf("\nOpening the original file...\n\n");
    if((fptr = fopen("dates.dat", "r")) != NULL)
    {
        while((buffer = getc(fptr)) != EOF) {
            printf("%c", buffer);
        }
    }
    
    printf("\n\nClosing the file...\n\n");
    fclose(fptr);
    
    return 0;
}
