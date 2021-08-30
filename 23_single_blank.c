/********************************************
NAME		: Jagajeevan.S
DATE		: 01.07.2021
DESCRIPTION	: To replace each string of one or more blanks by a single blank space
INPUT & OUTPUT	:

Enter the string with more spaces in between two words
Pointers		are		   sharp 	 knives.

String with reduced space
Pointers are sharp knives.

Do you want to continue (y/Y) : y
Enter the string with more spaces in between two words
		    Welcome  		   to  		Emertxe

String with reduced space
Welcome to Emertxe

Do you want to continue (y/Y) : n

*********************************************/
//To replace each string of one or more blanks by a single blank space

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
int my_space(char *str);

int main()
{
	char ch;
	
	do
	{
		char str[500];
		printf("Enter the string with more spaces in between two words\n");
		scanf("%500[^\n]",str);
		__fpurge(stdin);
		
		my_space(str);		//Function call
		
		printf("String with reduced space\n");
		printf("%s\n",str);
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		__fpurge(stdin);
		
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
int my_space(char *str)
{
	int count = 0;
	while ( *str )
	{
		//To replace the starting space or tabs before entering characters
		
		if ( count == 0 )
		{
			while ( *str == ' ' || *str == '\t' )
			{
				int i = 0;
				while( *(str+i) != '\0' ) 
				{
					*(str+i) = *(str+i+1);		// *str characters shifts leftwards 
					i++;
				}
			}
		}
		
		if ( *str == '\t')
			*str = ' ';	// changes '\t' to ' '
				
		//To replace with single blank space
		
		if( ( *str == ' ' || *str == '\t' ) && ( *(str+1) == ' ' || *(str+1) == '\t' ) ) // checks '\t' or ' ' in between characters
		{
			if ( *(str+1) == '\t' )	//Replace '\t' to ' ' for single blank space 
				*(str+1) = ' ';
			
			int i = 0;
			while( *(str+i) != '\0' )
			{
				*(str+i) = *(str+i+1);			// *str characters shifts leftwards 
				i++;
			}
			str--;			
		}
		
		str++;
		count++;
	} 
	printf("\n");
}
