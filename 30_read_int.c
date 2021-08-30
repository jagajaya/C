/********************************************
NAME		: Jagajeevan.S
DATE		: 25.06.2021
DESCRIPTION	: To read a integer without using scanf
INPUT & OUTPUT	:

Enter a number : 212
The number is : 212

Do you want to continue (y/Y) : y
Enter a number : -212
The number is : -212

Do you want to continue (y/Y) : y
Enter a number : 212-
The number is : 212

Do you want to continue (y/Y) : y
Enter a number : +212
The number is : 212

Do you want to continue (y/Y) : Y
Enter a number : as212
The number is : 0

Do you want to continue (y/Y) : y
Enter a number : /*212
The number is : 0

Do you want to continue (y/Y) : y
Enter a number : 21267jk
The number is : 21267

Do you want to continue (y/Y) : n


*********************************************/
//To read a integer without using scanf
#include<stdio.h>
#include<stdio_ext.h>
int read_int(void);

int main()
{
	char ch;
	do
	{
		__fpurge(stdin);	// flushing stdin buffer
		
		read_int();		// Function call
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		__fpurge(stdin);
		
		scanf(" %c",&ch);
	
	 }while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
int read_int(void)
{
	int a, b = 0, check = 0, flag_p = 0, flag_n = 0;
	char num;
	printf("Enter a number : ");	
	
	for( ; (num = getchar() ) != '\n' ; )	// Read number from user upto user type (Enter)
	{
		if ( ( check == 0 && num == '+' ) || ( check == 0 && num == '-' ) )	// Checks 1st char is '+' or '-'
		{
			if( num == '+' )
			{
				flag_p = flag_p + 1;	// flag_p count incremented
				continue;
			}
			else if( num == '-' )
			{
				flag_n = flag_n + 1;	// // flag_n count incremented
				continue;
			}
		}
		else if ( num >= '0' && num <= '9' )	// Checks entered ch is number or not
		{
			if ( flag_p <= 1 && flag_n <= 1 )	//  char to int conversion
			{
				a = (int) (num);
				a = a -'0';
				b = (b * 10) + a; 
			}
		} 
		else if ( ( check == 1 && num == '+' ) || ( check == 1 && num == '-' ) ) // Checks 2nd char is '+' or '-', is yes it comes out of loop
			break;
		else 					// if the entered char is not number and not '+' or '-' it comes out of loop
			break;
		check++;
		printf("%d",check);
		
	}
	
	 if ( flag_n == 1)	
		printf("The number is : %d\n", -b);	// Print neg int
		
	 else if ( flag_p <= 1 && flag_n == 0 )
		printf("The number is : %d\n",  b);	// Print pos int	
		
	 else
	 	printf("The number is : %d\n",b);	
}
