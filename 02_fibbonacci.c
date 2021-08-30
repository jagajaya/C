/********************************************
NAME		: Jagajeevan.S
DATE		: 01.06.2021
DESCRIPTION	: To generate fibonacci numbers <= 'n'
INPUT		: Enter the number : -21

OUTPUT		: 
0 1 -1 2 -3 5 -8 13 -21 
Do you want to continue (y/Y) : y
Enter the number : 13

0 1 1 2 3 5 8 13 
Do you want to continue (y/Y) : n
 
*********************************************/
//To generate fibonacci numbers <= 'n'
#include<stdio.h>

int main()
{
	int num, check=1;
	int fib;
	char ch;
	for (int i=1;i<=20;i++) // finding limit values
    	     check=check*2;
    	printf("%d",check);
    	do
    	{
		printf("Enter the number : ");
		scanf("%d",&num);
		printf("\n");
		
		if (-check < num && num < check)	// checks number is with in limit
		{
			if(num > 0)			// checks num > 0
			{	
				int num1=0, num2=1;
				while(num1 <= num)	// fibonacci value execution
				{
					printf("%d ",num1);
					fib=num1+num2;
					num1=num2;
					num2=fib;
				}
			}
			else
			{
				int num1=0, num2=1;
				while(num1 >= num && -num1 >= num)	// fibonacci value execution
				{
					printf("%d ",num1);
						
					fib=num1-num2;
					num1=num2;
					num2=fib;
				}
			}
			printf("\n");
		}
		else
			printf("Error : Number out of range, please enter the value -2^20 < N < 2^20\n");	// print error statement
		
		printf("Do you want to continue (y/Y) : ");
		scanf(" %c",&ch);
	}  while (ch == 'Y' || ch == 'y');  	// condition checking
	
	return 0;
}
			
