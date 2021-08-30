/********************************************
NAME		: Jagajeevan.S
DATE		: 25.06.2021
DESCRIPTION	: To pre and post increment by passing int pointer as a paramater
INPUT & OUTPUT	:

Enter the value of N : 5
Enter the operation :
  1. Pre-Increment
  2. Post-Increment
Choice : 1
After Pre-Increment ret = 6, num = 6

Do you want to continue (y/Y) : y
Enter the value of N : 5
Enter the operation :
  1. Pre-Increment
  2. Post-Increment
Choice : 2
After Post-Increment ret = 5, num = 6

Do you want to continue (y/Y) : n

*********************************************/
//To pre and post increment by passing int pointer as a paramater

#include<stdio.h>
//Function Declaration
int pre_increment(int *);
int post_increment(int *);
int main()
{
	int num,choice,ret;//Variable declaration
	char ch;
	do
	{
		printf("Enter the value of N : ");	//reading number from user
		scanf("%d",&num);
		printf("Enter the operation :\n  1. Pre-Increment\n  2. Post-Increment\nChoice : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				ret = pre_increment(&num);
				printf("After Pre-Increment ret = %d, num = %d\n",ret,num);// calling Pre increment function
				break;
			case 2:
				ret = post_increment(&num);
				printf("After Post-Increment ret = %d, num = %d\n",ret,num);// calling Post increment function
				break;
			default:
				printf("Choose 1 or 2 only\n");
		}
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
int pre_increment(int *a)
{
	int count = 0, mask;
	for(int i = 0; i <= 31; i++)	// checks no of set bits from lsb upto 0 bit in that number  
	{
		if((*a>>i) & 1)	//( if number is 15(00001111) set bits is 4 then count becomes 4)
			++count;
		else
			break;
	}
	mask = (1 << (count + 1)) - 1;	// mask becomes (1 << 5)-1 i.e, 00011111
	*a = *a ^ mask;		// 00001111 ^ 00011111 then *a becomes 00010000 i.e 16 then returs *a for pre increment
	return *a ;
}
int post_increment(int *a)
{
	int b, count = 0, mask;
	b = *a;				// value of *a is assigned to a variable b
	for(int i = 0; i <= 31; i++)
	{
		if((*a >> i) & 1)
			++count;
		else
			break;
	}
	mask = (1 << (count + 1)) - 1;
	*a = *a ^ mask;		// *a value changed but returns the variable b only for post increment
	return b;
}		
