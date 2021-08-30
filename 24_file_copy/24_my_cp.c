/********************************************
NAME		: Jagajeevan.S
DATE		: 08.08.2021
DESCRIPTION	: To implement a my_cp() function files
INPUT & OUTPUT	: 

/a.out file1.txt file2.txt
Data copied successfully

./a.out
Error : Filenames not passed

/a.out file1.txt
Destination file missing

./a.out copy.txt
copy.txt : No such a file

*********************************************/
// To implement a my_cp() function files

#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>

void my_copy(FILE *f_cpy, FILE *fptr);

int main(int argc, char *argv[])
{
	FILE *fptr;
	FILE *f_cpy;		// file pointers
	char cp;
	
	fptr = fopen (argv[1],"r");	// open the file in read mode
	
	if ( argc == 1 )		// if no files are passed it executes
	{
		printf("Error : Filenames not passed\n");		
		return 1;
	}
	else if ( fptr == NULL )	// if source file is wrong it executes
	{
		printf("%s : No such a file\n",argv[1]);
		return 1;
	}
	else if ( argc == 2 )		// if no destination file means it executes
	{
		printf("Destination file missing\n");
		return 1;
	}	
	else
	{
		f_cpy = fopen (argv[2], "w");	// open file in write mode
		my_copy(f_cpy,fptr);		// func call
	}	
	fcloseall();		
}
void my_copy(FILE *f_cpy, FILE *fptr)
{
	char cp;
		
	while( cp = fgetc(fptr) )	// copying file contents
	{
		if(feof(fptr))		// if file pointer reaches file end it breaks the loop 
			break;
		fputc(cp, f_cpy);	// writing contents in destination file 
	}
	printf("Data copied successfully\n");
}
