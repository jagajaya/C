/********************************************
NAME		: Jagajeevan.S
DATE		: 22.06.2021
DESCRIPTION	: To find the fibonacci series <= given number using recursion
INPUT & OUTPUT	:

Enter the number : 8
Fibonacci series using recursive function is
0 1 1 2 3 5 8 

Do you want to continue (y/Y) : y
Enter the number : 10
Fibonacci series using recursive function is
0 1 1 2 3 5 8 

Do you want to continue (y/Y) : Y
Enter the number : -21
Fibonacci series using recursive function is
0 1 -1 2 -3 5 -8 13 -21 

Do you want to continue (y/Y) : y
Enter the number : -13
Fibonacci series using recursive function is
0 1 -1 2 -3 5 -8 13 

Do you want to continue (y/Y) : N

*********************************************/
//To find the fibonacci series <= given number using recursion

#include<stdio.h>

void fib_pos(int num, int num1, int num2, int fib);
void fib_neg(int num, int num1, int num2, int fib);

int main()
{
	int num, num1 = 0, num2 = 1; 	//Variable declaration
	int fib = 0;
	char ch;
	do
	{
		printf("Enter the number : ");
		scanf("%d",&num);			// Read input from user
			
		printf("Fibonacci series using recursive function is\n");
		
		if ( num > 0 )
			fib_pos( num, num1, num2, fib );	//function call for +ve num
			
		if( num < 0 )
			fib_neg( num, num1, num2, fib);	//function call for -ve num
			
		if ( num == 0 )
			printf("%d ",num);			// print 0 if num is 0
			
		printf("\n\nDo you want to continue (y/Y) : ");	// asks the user to continue or not
		scanf(" %c",&ch);
		
		if(ch == 'Y' || ch == 'y') // condition checking and changes the value of variable 	
		{
			num = 0;
			num1 = 0;
			num2 = 1;
		}
	}  while (ch == 'Y' || ch == 'y'); // condition checking for repetetion	
	
	return 0;	
}
//Function Definition

void fib_pos(int num, int num1, int num2, int fib)
{
	printf("%d ",num1);	//printing fibonacci numbers <= given number
	
	fib = num1 + num2 ;
	num1 = num2;
	num2 = fib;
	
	if (num1 > num)
		return;
	else
		fib_pos(num, num1, num2, fib);
		
}
void fib_neg(int num, int num1, int num2, int fib)
{
	printf("%d ",num1);	//printing fibonacci numbers upto given number +ve or -ve
	
	fib = num1 - num2 ;
	num1 = num2;
	num2 = fib;
	
	if (num1 >= num && -num1 >= num)
		fib_neg(num, num1, num2, fib);
	else
		return;				
}
