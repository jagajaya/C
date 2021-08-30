/********************************************
NAME		: Jagajeevan.S
DATE		: 08.07.2021
DESCRIPTION	: To reverse a given string
INPUT & OUTPUT	:

1. Iterative method
2. Recursive method
Enter your choice : 2
Enter a string      : Hello World
Reverse string is   : dlroW olleH

Do you want to continue (y/Y) : y

1. Iterative method
2. Recursive method
Enter your choice : 1
Enter a string      : Hello World
str=Hello World
Reverse string is   : dlroW olleH

Do you want to continue (y/Y) : n

*********************************************/
//To reverse a given string

#include<stdio.h>
#include<stdio_ext.h>
int my_iter(char *str, int len);
int my_recursion(char *str, int len, int count);

int main()
{
	char ch;
	do
	{	__fpurge(stdin);
		char str[100];
		int choice, length = 0;	// VARIABLE DECLARATION
	
		printf("\n1. Iterative method\n2. Recursive method\n");
	
		printf("Enter your choice : ");
		scanf("%d",&choice);	// READ CHOICE FROM USER 1 OR 2
		__fpurge(stdin);
			
		if ( choice > 0 && choice < 3)
		{
			printf("Enter a string      : ");
			scanf("%[^\n]",str);		//READ STRNG FROM USER
			__fpurge(stdin);
	
			for ( int i = 0; str[i] != '\0'; i++ )
				length++;			// STRING LENGTH CALCULATION
			
			switch ( choice )
			{
				case 1:
					my_iter(str, length-1);	// FUNC CALL FOR ITERATIVE METHOD
					//fflush(stdout);
					printf("Reverse string is   : %s\n",str);
					break;
				case 2:
					my_recursion(str, length-1, 0);	// FUNC CALL FOR RECURSIVE METHOD
					//fflush(stdout);
					printf("Reverse string is   : %s\n",str);
					break;	
			}
		}
		else
			printf("Choose either 1 or 2\n");
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		__fpurge(stdin);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

}
//FUNC DEFINITION

int my_iter ( char *str, int len )	// ITERATIVE METHOD
{
	char temp;
	for( int i=len, j=0 ; i > len/2 ; i--, j++ )
	{
		temp = *(str + j);
		*(str + j) = *(str + i);
		*(str + i) = temp;
	}
}
int my_recursion (char *str, int len, int count)	//RECURSIVE METHOD
{
	char temp;
	if( count < len)
	{
		temp = *(str + count);
		*(str + count) = *(str + len);
		*(str + len) = temp;
		my_recursion(str, --len, ++count);
	}
}
