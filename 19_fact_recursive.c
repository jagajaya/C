/********************************************
NAME		: Jagajeevan.S
DATE		: 22.06.2021
DESCRIPTION	: To find the factorial of the given number using recursion and main function only
INPUT & OUTPUT	:

Enter the number : -1
Error : Invalid input

Do you want to continue (y/Y) : y
Enter the number : 0
Factorial is 1

Do you want to continue (y/Y) : y
Enter the number : 1
Factorial is 1

Do you want to continue (y/Y) : y
Enter the number : 2
Factorial is 2

Do you want to continue (y/Y) : y
Enter the number : 3
Factorial is 6

Do you want to continue (y/Y) : y
Enter the number : 4
Factorial is 24

Do you want to continue (y/Y) : n

*********************************************/
//To find the factorial of the given number using recursion and main function only
#include<stdio.h>
static long int num = -1, fact , count = 1;	//variable declaration globally

int main()
{
	char ch;

	if(num < 0)
	{
		printf("Enter the number : ");	//Reading input from user
		scanf("%ld",&num);
		fact = 1;
		if (num < 0)
		{
			printf("Error : Invalid input\n");
			
			printf("\nDo you want to continue (y/Y) : "); // prompt for continue without using loop
			scanf(" %c",&ch);
			if (ch == 'Y' || ch == 'y')
				main(num);	
		}
	}
	 
	if(num >= 0)
	{
		if ( num > 1 )
		{
			fact=fact * num ;	// Factorial operation
			num=main(--num);	// Recursion calling main from main
		}
		else
		{
			if ( count == 1 )
			{
				printf("Factorial is %ld\n",fact);	//Printing final output
			
				printf("\nDo you want to continue (y/Y) : "); // prompt for continue without using loop
				scanf(" %c",&ch);
				if (ch == 'Y' || ch == 'y')
					main(num = -1);
				if ( ch != 'y' || ch != 'Y' )
				{
					count++;
					return 0;
				}
			}
			else
				return 0;
		}
	}
	return 0;
}
/*
int main()
{
	char ch;
	l1:
	if(num == 0)
	{
		printf("Enter the number : ");	//Reading input from user
		scanf("%ld",&num);
		if (num == 0)
		{
			printf("Factorial is %ld\n",fact);
			goto ask;
		}	
		
	}
	if(num < 0 )	//Error checking
	{
		printf("Error : Invalid input\n");
		goto ask;
		return 0;
	} 
	if(num == 1)
	{
		printf("Factorial is %ld\n",fact);	//Printing final output
		ask:
		printf("\nDo you want to continue (y/Y) : "); // prompt for continue without using loop
		scanf(" %c",&ch);
		if (ch == 'Y' || ch == 'y')
		{
			num=0;
			fact=1;	//Reassigning the values for continuation
			goto l1;
		}
		else
			return 0;
	}
	else
	{
		fact=fact * num ;	// Factorial operation
		num=main(--num);	// Recursion calling main from main
	}
}
*/
