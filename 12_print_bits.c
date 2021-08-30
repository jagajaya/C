/********************************************
NAME		: Jagajeevan.S
DATE		: 07.06.2021
DESCRIPTION	: To print the given number bits and its 2's compliment using bitwise operators
INPUT & OUTPUT	:

Enter Intergers only
Enter the number: 12
12 --> 00000000000000000000000000001100
-12 --> 11111111111111111111111111110100
Do you want to continue (y/Y) : y

Enter Intergers only
Enter the number: 255
255 --> 00000000000000000000000011111111
-255 --> 11111111111111111111111100000001
Do you want to continue (y/Y) : n

*********************************************/

//To print the given number bits and its 2's comliment using bitwise operators

#include<stdio.h>
int main()
{
	int num,opp,value,a, i;	// Declaring the variables
	char ch;
	
	do
	{
	// Get input from user
	
	printf("Enter Intergers only\n");
	printf("Enter the number: ");
	scanf("%d",&num);
	
	if (num > 0 || num < 0)
	{
		printf("%d --> ",num);
		
		for (i=31;i>=0;i--)		// printing each bit of given input
		{
			value = (num >> i) & 1;
			printf("%d",value);
		}
		
		printf("\n");	
		
		opp=(~num)+1;			// 2's compliment of that given input 
		printf("%d --> ",opp);
		
		for (i=31;i>=0;i--)		// printing 2's compliment of that given input 
		{
			value = (opp >> i) & 1;
			printf("%d", value);
		}
		
		printf("\n");		
	}
	else
		printf("Enter +ve or -ve numbers only\n");
		
	printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
	scanf(" %c",&ch);
	printf("\n");

	}  while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion	
	
	return 0;	
		
}	
