/********************************************
NAME		: Jagajeevan.S
DATE		: 01.06.2021
DESCRIPTION	: To check whetherthe given number is perfect or not
INPUT		: Enter the number : 6
OUTPUT		: Yes, entered number is perfect number
		  Do you want to continue (y/Y) : y
		  Enter the number : 10
		  No, entered number is not a perfect number
		  Do you want to continue (y/Y) : n

*********************************************/
// To check whetherthe given number is perfect or not

#include<stdio.h>

int main()
{
	int num, check=1, sum; // VARIABLE DECLARATION
	char ch;
	
	for (int i=1;i<=20;i++) // FINDING THE LIMITS
    	     check=check*2;
    	do
    	{
    	     printf("Enter the number : "); // READ THE NUMBER FROM USER
    	     scanf("%d",&num);
    	     sum=0;
    	     if (num < check && num > 0)	// CHECKIG LIMITS FOR THE NUMBER
    	     {
    	      	for (int i=1;i<num;i++)
    	     	{
    	     		if(num%i == 0)
    	     			sum=sum+i;	// ADDING DIVISORS OF THAT GIVEN NUMBER
    	     	}
    	     	
    	     	if(num==sum)			// CHECKING PERFECT NUM OR NOT
    	     		printf("Yes, entered number is perfect number\n");
    	     	else
    	     		printf("No, entered number is not a perfect number\n");
    	     		
    	      }
    	      else if (num > check)	// CHEKS NUM LIMIT IS OUT OF RANGE OR NOT
    	            printf("Number out of range\n");
    	      else
    	            printf("Error : Invalid Input, Enter only positive number\n"); // PRINTS IF THE INPUT IS INVALID 
    	      
    	      	  
    	      printf("Do you want to continue (y/Y) : ");
    	      scanf(" %c",&ch);
    	      
	}  while (ch == 'Y' || ch == 'y');  	// CHECKING TO CONTINUE OR NOT
	
	return 0;
}
	
