# Dates #


_"A C program which generates an output file that contains a list of dates in day, abbreviated month &amp; year format (i.e. 1 JAN 1900), followed by the original list of dates in month/day/year format (i.e. 1/1/1900)."_

-------

- This program includes 2 different programs and a dates.dat file.
- __NOTE__: There is no header file. This is due to the minimal amount of information needed for a header file.

__Program 1__: Accept input for the first program via the command-line arguments. Input will be the number of valid entries to be redirected from the dates input file (dates.dat). A zero indicates to input all entries from the dates input file. This input will then be piped out to the second program. The program will handle corrupt dates in the dates.dat file.

Program 1 file name: _ValidateDates.c_

__Program 2__: Accept the validated dates in the month/day/year format and convert each of them to the day, abbreviated month, and year format. The abbreviated month consists of the first three letters of the month, capitalized. These converted results will be redirected to the output file (output.dat), followed by a copy of the original (dates.dat) data.

Program 2 file name: _FormatDates.c_

-------

### How to compile and link files for execution ###


Please use the following to compile (this will work on any OS):

First enter this:

__gcc ValidateDates.c -o main1__

Then this:

__gcc FormatDates.c -o main2__

- _This will rename the files to main1 and main2 for simplicity._


Please use the following to execute the program successfully:

__./main input < dates.dat | ./main2 > output.dat__

The input should be a number. If the input is less than or equal to 0, then it will read the entire dates.dat file. If the input is, for example, 3, then it will output the first 3 valid dates in the output.dat file.


After executing the program, it will create an output.dat file for the output.
