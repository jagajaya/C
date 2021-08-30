/********************************************
NAME		: Jagajeevan.S
DATE		: 13.06.2021
DESCRIPTION	: To replace n bits according to given values
INPUT & OUTPUT	:
Enter the number num	: 11
Enter the number val	: 174
Enter the number a	: 3
Enter the number b	: 5
Binary form of 'num'	: 00000000000000000000000000001011
Binary form of 'val'	: 00000000000000000000000010101110
Updated form of val(158): 00000000000000000000000010011110

Do you want to continue (y/Y) : y

Enter the number num	: 255
Enter the number val	: 71
Enter the number a	: 33
Invalid value, Please enter valid a value 0<a<=31

Do you want to continue (y/Y) : n
*********************************************/
//To replace n bits according to given values

#include<stdio.h>
int replace_nbits_from_pos(int val,int n,int b, int num);
int bits(int x);

int main()
{
	int num, val, a, b, i, j;//Variable declaration
	char ch;
	do
	{
		printf("Enter the number num\t: ");//Read inputs from user
		scanf("%d",&num);
		printf("Enter the number val\t: ");
		scanf("%d",&val);
		printf("Enter the number a\t: ");//Read input a from user
		scanf("%d",&a);
	
		if(0 < a && a <= 31)
		{
			printf("Enter the number b\t: ");//Read input b from user
			scanf("%d",&b);
			if(a <= b && b <= 31)
			{
				printf("Binary form of 'num'\t: ");
				bits(num);	// func call to print bits
				printf("Binary form of 'val'\t: ");
				bits(val);// func call to print bits
				i=replace_nbits_from_pos(val,b-a+1,b,num);//function calling
				printf("Updated form of val(%d): ",i);
				bits(i);	// func call to print bits
			}
			else
				printf("Invalid value, Please enter valid b value a<=b<=31\n");
		}
		else
			printf("Invalid value, Please enter valid a value 0<a<=31\n");
		printf("\n");	
		printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		printf("\n");
	}  while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
		
	return 0;
	}
int replace_nbits_from_pos(int val,int n,int b, int num)//(174,3,5,11)
{	
	int mask,mask1;
	mask=(1<<n)-1;// 1 << of given n and - 1 from that value gives mask(000.....0111)
	num=(num & mask) << n;// ((000...01011 & 000... 0111) is = 000....011) << 3 is num = 000...011000
	mask1=(1<<(b+1))-1;//(1 << 6) -1 is  mask 1 = 000....00111111 
	mask1=~((mask1 >> n) << n);// ((00..00111111 >> 3 = 00..000111 ) << 3 is 00...00111000 ) ~(00...00111000) is mask1 = 111...000111
	val=val & mask1;// 000....10101110 & 111...000111 is val = 000...10000110	
	return (num | val);// ( 000...011000 | 000...10000110) is  00...10011110 i.e,158
}
int bits(int x)
{
	int j;
	for(j=31;j>=0;j--)
		printf("%d",(x >> j) & 1);	//printing all bits
	printf("\n");	
}	
