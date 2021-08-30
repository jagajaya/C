/********************************************
NAME		: Jagajeevan.S
DATE		: 31.07.2021
DESCRIPTION	: To define a macro swap (t,x,y) that interchanges 2 arguments of type t
INPUT & OUTPUT	: 

1. int
2. char
3. short
4. float
5. double
6. string
Enter your choice : 1
Enter the num1 : 10
Enter the num2 : 20

After swapping :
num1 : 20
num2 : 10
Do you want to continue(y/Y):n

*********************************************/
// To define a macro swap (t,x,y) that interchanges 2 arguments of type t

#include<stdio.h>
#include <stdlib.h>

#define SWAP(t, x, y)		\
{				\
	t temp;		\
	temp = x;		\
	x = y;			\
	y = temp;		\
}				\

int main()
{
	char ch;
	do
	{
		int choice;
		printf("1. int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter your choice : "); 
		scanf("%d",&choice);		// read choice from user
	
		switch (choice)
		{
			case 1:
			{
				int num1, num2;
				
				printf("Enter the num1 : ");
				scanf("%d",&num1);
				printf("Enter the num2 : ");
				scanf("%d",&num2);			// read inputs from user
				
				SWAP(int, num1, num2)	// macro declaration
				
				printf("\nAfter swapping :\nnum1 : %d\nnum2 : %d\n",num1,num2);	// prints output
				break;
			}
			case 2:
			{
				char char1, char2;
				
				printf("Enter the char1 : ");
				scanf(" %c",&char1);
				printf("Enter the char2 : ");
				scanf(" %c",&char2);
				
				SWAP(char, char1, char2);	// macro declaration
				
				printf("\nAfter swapping :\nchar1 : %c\nchar2 : %c\n",char1,char2);
				break;
			}
			case 3:
			{
				short num1, num2;
				
				printf("Enter the num1 : ");
				scanf("%hd",&num1);
				printf("Enter the num2 : ");
				scanf("%hd",&num2);
				
				SWAP(short, num1, num2)		// macro declaration
				
				printf("\nAfter swapping :\nnum1 : %d\nnum2 : %d\n",num1,num2);
				break;
			}
			case 4:
			{
				float num1, num2;
				
				printf("Enter the num1 : ");
				scanf("%f",&num1);
				printf("Enter the num2 : ");
				scanf("%f",&num2);
				
				SWAP(float, num1, num2)		// macro declaration
				
				printf("\nAfter swapping :\nnum1 : %g\nnum2 : %g\n",num1,num2);
				break;
			}
			case 5:
			{
				double num1, num2;
				
				printf("Enter the num1 : ");
				scanf("%lf",&num1);
				printf("Enter the num2 : ");
				scanf("%lf",&num2);
				
				SWAP(double, num1, num2)		// macro declaration
				
				printf("\nAfter swapping :\nnum1 : %g\nnum2 : %g\n",num1,num2);
				break;
			}
			case 6:
			{
				char *str1, *str2;
				
				str1 = malloc ( 50 * sizeof(char));
				str2 = malloc ( 50 * sizeof(char));		// memory allocated dynamically
				
				printf("Enter string 1 : ");
				scanf("%s",str1);
				printf("Enter string 2 : ");
				scanf("%s",str2);
				
				SWAP(char *, str1, str2)		// macro declaration
				
				printf("\nAfter swapping :\nstring 1 : %s\nstring 2 : %s\n",str1,str2);
				break;
			}
			default :
				printf("Please enter correct choice\n");
		}
		printf("Do you want to continue(y/Y):"); // asking for continue
     		scanf(" %c",&ch);
     			
       }while (ch == 'Y' || ch == 'y');  	// condition checking
    
    return 0;	
}
