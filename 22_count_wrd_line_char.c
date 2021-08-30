/********************************************
NAME		: Jagajeevan.S
DATE		: 27.06.2021
DESCRIPTION	: To count number of characters,words,lines entered through stdin buffer
INPUT & OUTPUT	:

hello world
dennid ritchie
linux

Character count	: 33
Line count	: 3
Word count	: 5

Do you want to continue (y/Y) : n
*********************************************/
//To count number of characters,words,lines entered through stdin buffer

#include<stdio.h>
#include<stdio_ext.h>

int main()
{
	//Variable declaration
	
	char ch;
	
	do
	{
		char ip;
		int words = 0, lines = 0, chars = 0, n = 0;
	
		while ( (ip = getchar()) != EOF)			// Read input from user
		{
			
			chars++;					// character counting
			
			//If 1st char is ' ' or '\t' or '\n' it not increase the word count
			
			if ( (chars == 1 && ip == '\t') || (chars == 1 && ip == 32) || (chars == 1 &&  ip == '\n'))	
				n = 1;
				
			else if( ip == '\t' || ip == 32 ||  ip == '\n')	// Word counting
			{
				n++;					// n value incremented
				if(n == 1)
					words++;
			}
			
			if ( ip != '\t' && ip != 32 && ip != '\n')	// checks and makes n to 0
				n = 0;
			
			if ( ip == '\n')				// line counting
				lines++;	
		
			
		}
		// Prints output
		
		__fpurge(stdin);
		
		printf("\nCharacter count	: %d\n",chars);
	
		printf("Line count	: %d\n",lines);
		
		if ( n == 0 && ip == EOF )
			printf("Word count	: %d\n",++words);
		else
		printf("Word count	: %d\n",words);
		
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		
		__fpurge(stdin);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
		
}
	
