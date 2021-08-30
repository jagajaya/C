/********************************************
NAME		: Jagajeevan.S
DATE		: 08.08.2021
DESCRIPTION	: To find the average of n numbers by taking input in 3 different ways
INPUT & OUTPUT	:

./a.out
Select the method to calculate average:
1. Scan from keyboard.
2. Proceed with environmental variable arguents.
Enter your choice		   : 1
Enter the total number of integers : 4
Enter the elements			: 3 5 10 7
The average of the enterd elements is   : 6.25

./a.out 3 5 10 7
Select the method to calculate average:
1. Scan from keyboard.
2. Preceed with provided command line arguments
3. Proceed with environmental variable arguents.
Enter your choice		   : 2
The average of the enterd elements is   : 6.25

./a.out
Select the method to calculate average:
1. Scan from keyboard.
2. Proceed with environmental variable arguents.
Enter your choice		   : 2
The average of the enterd elements is   : 2.5

*********************************************/
// To find the average of n numbers by taking input in 3 different ways
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

int my_atoi(char *str);
char *my_strtok (char *str, char *tok);
char *start;

int main( int argc, char *argv[] )
{
	int choice;
	float avg = 0, sum = 0;
	
	if (argc == 1)
	{
		printf("Select the method to calculate average:\n1. Scan from keyboard.\n2. Proceed with environmental variable arguents.\nEnter your choice\t\t   : ");
	}
	if ( argc > 1 )
	{
		printf("Select the method to calculate average:\n1. Scan from keyboard.\n2. Preceed with provided command line arguments\n3. Proceed with environmental variable arguents.\nEnter your choice\t\t   : ");
	}	
	
	scanf("%d",&choice);
		
	if (choice == 1)		// read input from user and find avg
	{
		int total;
	 	printf("Enter the total number of integers : ");
 		scanf("%d",&total);
		printf("Enter the elements\t\t\t: ");
		int arr[total];
		
		for (int i=0; i < total; i++)
		{
			scanf("%d",&arr[i]);
			sum = sum + arr[i];
		}
		avg = sum / total;
		printf("The average of the enterd elements is   : %g\n",avg);	// prints avg
	}
	
	if ( ( argc > 1 && choice == 3) || ( argc == 1 && choice == 2 )  )	// to calulate average from environmental variable
	{
		char *ptr;
		char token[1] = " ";
		char *ret;
		ptr = getenv("arr");
		
		if(ptr == NULL )	// prints incase env is not available
		{
			printf("ENVIRONMENT VARIABLE NOT AVAILABLE\n");
			return 1;
		}
		else
		{
			ret = my_strtok(ptr, token);		// func call
		
			while ( ret != NULL)
			{	
				sum = sum + my_atoi(ret);		
				fflush(stdout);
				ret = my_strtok( NULL , token);	//func call string 1 as NULL
			} 
		}		
		avg = sum / 4;
		printf("The average of the enterd elements is   : %g\n",avg);	// prints avg
			
	}
	
	if ( argc > 1 && choice == 2)	// calulate avg from command line arguments
	{
		for (int i=1; i < argc ; i++)
			sum = sum + my_atoi(argv[i]);		
	
		avg = sum / (argc - 1);
		printf("The average of the enterd elements is   : %g\n",avg);	// prints avg
	}
	return 0;
}
/*atoi function*/

int my_atoi(char *str)
{
	int a, temp = 0, check = 0, flag_p = 0, flag_n = 0;
	
	while(*str)
	{
		if ( ( check == 0 && *str == '+' ) || ( check == 0 && *str == '-' ) )	// Checks 1st char is '+' or '-'
		{
			if( *str == '+' )
			{
				flag_p = flag_p + 1;	// flag_p count incremented
				//continue;
			}
			else if( *str == '-' )
			{
				flag_n = flag_n + 1;	// // flag_n count incremented
				//continue;
			}
		}
		else if ( *str >= '0' && *str <= '9' )	// Checks entered ch is number or not
		{
			if ( flag_p <= 1 && flag_n <= 1 )	//  char to int conversion
			{
				temp = ( temp * 10 ) + (*str - 48);
			}
		} 
		else if ( ( check == 1 && *str == '+' ) || ( check == 1 && *str == '-' ) ) // Checks 2nd char is '+' or '-', is yes it comes out of loop
			break;
		else 					// if the entered char is not number and not '+' or '-' it comes out of loop
			break;
		check++;
		str++;
		
	}
	
	 if ( flag_n == 1)	
		return -temp;	//	 returns -ve value
		
	 else if ( flag_p <= 1 && flag_n == 0 )
		return temp;	
		
	 else
	 	return temp;	
}
/*string token function*/
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
