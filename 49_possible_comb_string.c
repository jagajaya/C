/********************************************
NAME		: Jagajeevan.S
DATE		: 09.07.2021
DESCRIPTION	: To print all possible combinations of string

INPUT & OUTPUT	:

Enter the string	: abca
Error : Enter distinct characters

Do you want to continue (y/Y) : y

Enter the string	: abc
abc
acb
bac
bca
cba
cab

Do you want to continue (y/Y) : n

*********************************************/
// To print all possible combinations of string

#include<stdio.h>
#include<stdio_ext.h>
int poss_comb (int start, int end, char *str);

int main()
{
	char ch;
	
	do
	{
		int len = 0;
		char str[50];			// variable declaration
				
		printf("\nEnter the string	: ");
		scanf("%[^\n]",str);			// Read string from user
		__fpurge(stdin);				
	
		for(int i=0; str[i] != '\0' ; i++)
			len++;				// String length calculation
		
		for( int i=0; i < len ; i++)
		{
			for(int j=i+1 ; j < len ; j++)
			{
				if ( str[i] == str[j] )
				{
					printf("Error : Enter distinct characters\n");	// Checks distinct chracters are not
					goto ask;
				}	
			}	
		}
	
		poss_comb(0, len-1, str);	//Func call
		
		ask:
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		__fpurge(stdin);	
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

	return 0;
	
}

//Function Declaration

int poss_comb(int start, int end, char *str)
{
	char temp;
	
	if (start == end)
		printf("%s\n",str);	// Prints the string combinations
	
	for (int i=start; i <= end; i++)	
		{
			temp = *(str+i);
			*(str+i) = *(str+start);
			*(str+start) = temp;		// swapping the string characters
			
			poss_comb(start+1, end, str);	// Recursive func call
			
			temp = *(str+i);
			*(str+i) = *(str+start);
			*(str+start) = temp;		// swapping the string characters 
		}
	
}
