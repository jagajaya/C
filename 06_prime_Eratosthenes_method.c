/********************************************
NAME		: Jagajeevan.S
DATE		: 08.06.2021
DESCRIPTION	: To print all prime numbers <= given number,By Sieve of Eratosthenes method
INPUT & OUTPUT	: 

Enter the value of 'n' : 200000000000
Number out of range
Do you want to continue(y/Y) : y
Enter the value of 'n' : -20
Invalid input
Do you want to continue(y/Y) : Y
Enter the value of 'n' : 79
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 
Do you want to continue(y/Y) : n

*********************************************/
//To print all prime numbers <= given number,By Sieve of Eratosthenes method

#include<stdio.h>
int main()
{
	// Variable declration
	int num, check;
	char ch;
	
	// limit calculation
	for (int i=1;i<=20;i++)
    	     check=check*2;
	do
	{
		printf("Enter the value of 'n' : ");
		scanf("%d",&num);				// Input from user
		
		if( num > 1 && num < check)			// checks input is within the limit
		{
			int array[num];			// declaring array according the input 
			for (int i=2;i<=num;i++)		// creating array elements from 2 to given number
			{
				array[i]=i;
			}
			for (int i=2;i<=num;i++)		//making others elements 0 except primenumbers
			{
				for (int j=i+1;j<=num;j++)	
				{
					
					if( array[j] != 0 && array[i] != 0 && (array[j] % array[i]) == 0)	// if the value is modulus of any number is 0 according to the loop order
						array[j]=0;							// then that elements becomes 0 , Eratostenes method
				}
			}
			for (int i=2;i<=num;i++)	// printing prime numbers
			{
				if(array[i] != 0)	// condition to print otherthan 0 only
					printf("%d ",array[i]);		
			}	
		}
		else if ( num > check)			// if number > check
		{
			printf("Number out of range");
		}
		else				// otherwise it executes
		{	
			printf("Invalid input");
		}
		
		printf("\n");	
	
		printf("Do you want to continue(y/Y) : ");	// asks the user to continue or not
		scanf(" %c",&ch);

	} while(ch =='y' || ch == 'Y');	// condition checking for repetetion	

	return 0;
}		


