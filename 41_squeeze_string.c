/********************************************
NAME		: Jagajeevan.S
DATE		: 05.07.2021
DESCRIPTION	: To squeeze by deleting the character in string 1 if that matches with any character in string 2
INPUT & OUTPUT	:

Enter string 1		: Dennis Ritchie
Enter string 2		: Linux
After squeeze string 1	: Des Rtche

Do you want to continue (y/Y) : n

*********************************************/
//To squeeze by deleting the character in string 1 if that matches with any character in string 2

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
void my_squeeze( char *str, char *stp );

int main()
{
	char ch;
	do
	{
		char str1[100], str2[100];
	
		printf("Enter string 1		: ");
		scanf("%100[^\n]",str1);
		__fpurge(stdin);
		
		printf("Enter string 2		: ");
		scanf("%100[^\n]",str2);
		__fpurge(stdin);
		
		my_squeeze( str1, str2 );
		
		printf("After squeeze string 1	: ");
		printf("%s\n",str1);
	
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		__fpurge(stdin);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}

void my_squeeze( char *str, char *stp ) 
{
	while(*str)
	{
		int count = 0;
		int same_ch = 0;
		
		for(int j = 0; *(stp+j) != '\0' ; j++)
		{
			if (*str == *(str+1) )
			{
				int i = 0;
				while(*(str+i))
				{
					*(str+i) = *(str+i+1);
					i++;
				}
				same_ch = 1;
			}
				
			if (*(str) == *(stp+j))
			{
				count++;
				
				int i = 0;
				while(*(str+i))
				{
					*(str+i) = *(str+i+1);
					i++;
				}
			}
		}
		if (same_ch ==1)
			str--;
		str++;			
	}
}
