/********************************************
NAME		: Jagajeevan.S
DATE		: 17.06.2021
DESCRIPTION	: To swap two variables by using pass by reference 
INPUT & OUTPUT	:

Enter the number num1 : 10
Enter the number num1 : 20
After swapping
num1 = 20
num2 = 10

Do you want to continue (y/Y) : N

*********************************************/
//To swap two variables by using pass by reference 

#include<stdio.h>
//Function Declarations
void swap(int *a, int *b);

int main()
{
	char ch;	//Variable declaration
	int num1, num2;
	do
	{
		printf("Enter the number num1 : ");
		scanf("%d",&num1);			//Read number 1 from user
		printf("Enter the number num1 : ");
		scanf("%d",&num2);			//Read number 2 from user
		swap(&num1 ,&num2);			//Function call
		printf("After swapping\nnum1 = %d\nnum2 = %d\n",num1,num2); // print after swapping
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		printf("\n");
		
	 } while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
		
	return 0;
}
//Function Definition
void swap(int *a, int *b)
{
	*a = *a ^ *b;	// *a=10^20 (00001010 ^ 00010100), *a=30 (00011110)
	*b = *a ^ *b;	// *b=30-20 (00011110 ^ 00010100), *b=10 (00001010)
	*a = *a ^ *b;	// *a=30-10 (00011110 ^ 00001010), *a=20 (00010100)
}
			
