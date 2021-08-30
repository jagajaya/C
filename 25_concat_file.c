/********************************************
NAME		: Jagajeevan.S
DATE		: 11.08.2021
DESCRIPTION	: To concatenate two files
INPUT & OUTPUT	: 

./a.out
asdafa
asdafa

./a.out assign1.txt 
Assignment number 1

./a.out assign1.txt assign2.txt 
Assignment number 1
Assignment number 2

./a.out assign1.txt assign2.txt destination.txt
Data copied successfully
Data copied successfully

*********************************************/
#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
void my_concat ( FILE *source, FILE *dest);

int main(int argc , char *argv[])
{
	FILE *fptr1, *fptr2, *fptr3;	// file pointers
	char ch;
	
	if ( argc == 1)	// if no cla it executes
	{
		char str[1024];
		fgets(str, 1024, stdin);
		fputs(str, stdout);
	}
	else if ( argc == 2 )	// if one file is passed prints file contents
	{
		fptr1 = fopen(argv[1], "r");
		if ( fptr1 == NULL)
		{
			fprintf(stderr,"File is not existing\n");
			return 1;
		}
		else
		{
			while ( (ch = fgetc(fptr1) ) != EOF )
				fputc (ch, stdout);
		}
		fclose (fptr1);
	}
	else if ( argc == 3 )	// if two files are passed prints file contents
	{
		FILE *fptr[2];
		for (int i = 0; i < (argc-1 ); i++)
		{
			fptr[i] = fopen(argv[i+1], "r");
			if ( fptr[i] == NULL)
			{
				printf("%s is not exist\n",argv[1]);
				return 1;
			}
			else
			{
				while ( (ch = fgetc(fptr[i]) ) != EOF )
					fputc (ch, stdout);
			}	
			fflush(stdout);
			fclose (fptr[i]);
		}
	}
	else if ( argc == 4 )	// if three files are passed first 2 contents of the file is copied to 3rd file
	{
		fptr1 = fopen (argv[1], "r");
		fptr2 = fopen (argv[2],"r");
		
		if ( fptr1 == NULL )		// checks 1st source file exists
		{
			printf("%s is not exist\n",argv[1]);	
			return 0;
		}
		else if ( fptr2 == NULL )			// checks 2nd source file exists
		{
			printf("%s is not exist\n",argv[2]);
			return 0;
		}
		else
		{
			fptr3 = fopen (argv[3], "a");
			//FUNC CALL;
			my_concat (fptr1 , fptr3);
			my_concat (fptr2 , fptr3);
		}
		fcloseall();
	}	
	else
		printf("Enter valid command line arguments\n");
	
	return 0;								
}

void my_concat ( FILE *source, FILE *dest)
{
	char ch;
	while( ch = fgetc(source) )	// copying file contents
	{
		if(feof(source))		// if file pointer reaches file end it breaks the loop 
			break;
		fputc(ch, dest);	// writing contents in destination file 
	}
	printf("Data copied successfully\n");
} 
