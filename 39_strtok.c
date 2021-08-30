/********************************************
NAME		: Jagajeevan.S
DATE		: 14.07.2021
DESCRIPTION	: To implement strtok function
INPUT & OUTPUT	:

Enter the string1 = Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter the string2 = ;./-:
Tokens : 
Bangalore
Chennai
Kolkata
Delhi
Mumbai
Do you want to continue (y/Y) : n

*********************************************/
// To implement strtok function

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
char *my_strtok (char *str, char *tok);
char *start;

int main()
{
	char ch;
	do
	{
		char str1[200], str2[100];
		char *ret;			//Variable declaration
		
		__fpurge(stdin);
		printf("Enter the string1 = ");
		scanf("%[^\n]",str1);			// read string 1 from user
		__fpurge(stdin);
		
		printf("Enter the string2 = ");
		scanf("%[^\n]",str2);			// read string 2 from user
		__fpurge(stdin);
		
		printf("Tokens : \n");
		ret = my_strtok(str1, str2);		// func call
		while ( ret != NULL)
		{	
			printf("%s\n",ret);		
			fflush(stdout);
			ret = my_strtok( NULL , str2);	//func call string 1 as NULL
		}
		printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		__fpurge(stdin);	
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

	return 0;	
}

char *my_strtok (char *str, char *tok)
{ 
	
	int len = 0,count = 0;
	static int final_check;
	char *print;
	
	if (str == NULL)		// checks string1 is NULL or not
	{
		print = start;		// address assigning
		str = print;
	}
	else
		print = str;
	
	for ( int i=0; *(str+i) != '\0';i++)
		len++;				// string length calculation
	
	for ( int i=0; i < len; i++)
	{
		for(int j=0 ; *(tok+j) != '\0';j++)
		{
			if ( *(str+i) == *(tok+j) )	// checks token characters in string 1 or not
			{
				*(str+i) = '\0';
				start = str+i+1;	// address after token element is assigned
				count = 1;
				break;	
			}		
		}
		if (count == 1)
			break;	
	}
	if (count == 1)
	{	
		if ( *(str) != '\0')
		{				
			for(int j=0 ; *(tok+j) != '\0';j++)	// returns the address if the string not having token
			{
				if (*(str) != *(tok+j))
				return str;			
			}
		}
		else if ( *str == '\0')
		{
	 		start = str+1;	// address incremented
			return my_strtok(NULL,tok);	// recursive call to clear tokens
		}
				
	}	
	if (count == 0 )
	{
		if ( final_check == 0 && *str != '\0')	// checks and returns the string if there is no tokens
		{
			final_check++;
			return str;	
		}
		else 
			return NULL;	// string is ended then it returns NULL so the loop terminates
	}
}
