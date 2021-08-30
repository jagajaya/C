/********************************************
NAME		: Jagajeevan.S
DATE		: 07.06.2021
DESCRIPTION	: To check given number is odd or even and its sign using bitwise operators
INPUT & OUTPUT	:

Enter Intergers only
Enter the value of 'N' :0
Enter +ve or -ve numbers only
Do you want to continue (y/Y) : y

Enter Intergers only
Enter the value of 'N' :5
5 is a +ve odd number
Do you want to continue (y/Y) : y

Enter Intergers only
Enter the value of 'N' :-4
-4 is a -ve even number
Do you want to continue (y/Y) : n

*********************************************/

//To check given number is odd or even and its sign using bitwise operators

#include<stdio.h>
int main()
{
	// Variable Declaration
	int num;
	char ch;
	
	do
	{
		printf("Enter Intergers only\n");
		printf("Enter the value of 'N' :");
		scanf("%d",&num);			// Input from user
	
		if (num > 0 || num < 0)		// checks num is valid
		{
			// checks sign of given input +ve or -ve
			
			if ((num >> 31) & 1)	// if it is -ve it executes	
			{
				// checks given input is odd or even 
				
				if(num & 1)			
					printf("%d is a -ve odd number",num);
				else
					printf("%d is a -ve even number",num);
			
				printf("\n");	
			}
			else	// if it is +ve it executes
			{
				// checks given input is odd or even 
				
				if(num & 1)
					printf("%d is a +ve odd number",num);
				else
					printf("%d is a +ve even number",num);
			
				printf("\n");	
			}
		}
		else 			// if it is invalid it executes i.e, num = 0
			printf("Enter +ve or -ve numbers only\n");
		
		printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		printf("\n");

	}  while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion	
	
	return 0;		
}	
