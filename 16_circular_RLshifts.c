/********************************************
NAME		: Jagajeevan.S
DATE		: 14.06.2021
DESCRIPTION	: To do circular right & left shift of given number according to bits
INPUT & OUTPUT	:

Enter the number num	: -12
Enter n	: 3
Possible operations
1. Circular righr shift
2. Circular left shift
Enter your choice	: 2
Binary form of number	: 11111111111111111111111111110100
After circular left shifting by 3
Binary form of number	: 11111111111111111111111110100111
Do you want to continue (y/Y) : y

Enter the number num	: 12
Enter n	: 3
Possible operations
1. Circular righr shift
2. Circular left shift
Enter your choice	: 1
Binary form of number	: 00000000000000000000000000001100
After circular right shifting by 3
Binary form of number	: 10000000000000000000000000000001
Do you want to continue (y/Y) : n

*********************************************/
//To do circular right & left shift of given number according to bits

#include<stdio.h>
int right_shift(int num, int n);
int left_shift(int num, int n);	
int bits(int x);

int main()
{
	int num, n,r,l,option;	//Variable declaration
	char ch;
	do
	{
		printf("Enter the number num\t: ");	//Read inputs from user
		scanf("%d",&num);
		printf("Enter n\t: ");
		scanf("%d",&n);
		printf("Possible operations\n1. Circular righr shift\n2. Circular left shift\n");
		printf("Enter your choice\t: ");	//Asking user choice
		scanf("%d",&option);
		
		switch (option)
		{
			case 1:	//Circular right sfift
				printf("Binary form of number\t: ");
				bits(num);	// func call to print bits
				printf("After circular right shifting by %d\n",n);
				r=right_shift(num,n); //function call for circular right operation
				printf("Binary form of number\t: ");
				bits(r); // func call to print bits
				break;
			case 2:	//Circular left shift
				printf("Binary form of number\t: ");
				bits(num);
				printf("After circular left shifting by %d\n",n);
				l=left_shift(num,n);	//function call for circular right operation
				printf("Binary form of number\t: ");
				bits(l);
				break;
			default:
				printf("Enter valid choice\n");
		}
		
		printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		printf("\n");
		
	 } while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
		
	return 0;
}
//Function definition
int right_shift(int num, int n)//(12,3)
{	
	int mask,mask1,a,b,move;
	move=32-n;//(32-3=29)
	mask=(1<<n)-1;// 1 << of given n and - 1 from that value gives mask(000.....0111)
	a=(num & mask) << move; //((0000....1100 & 0000....0111) = 000....0100)) << 29 i.e, a=100....000	
	mask1=~(mask << move);	// (000....0111 << 29 = 11100...000), ~(1110..000) is mask1 = 00011...111
	b= (num>>n) & mask1;	//((0000...1100 >> 3 ) = 0000....0010) & 00011....11 is b = 00000....0010
	num= a|b;	// 100....000 | 000...0010 is num = 1000....001
	return num;		
}
int left_shift(int num, int n)//(-12,3)
{	
	int mask,a,move,j;
	move=32-n;//(32-3=29)	
	mask=((1<<n)-1);// 1 << of given n and - 1 from that value gives mask(000.....0111)
	a=(num >> move) & mask;// ((1111...10100 >> 29 ) = 1111....1111) & 000....0111 then a = 000....00111
	num=(num << n) | a;	// ((1111....10100 << 3 = 11..10100000) | 000....00111 then num = 111....10100111 		
	return num;
}
int bits(int x)// value of l/r
{
	int j;
	for(j=31;j>=0;j--)
		printf("%d",(x >> j) & 1);	//printing all bits
	printf("\n");	
}	
