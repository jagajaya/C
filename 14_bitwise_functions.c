/********************************************
NAME		: Jagajeevan.S
DATE		: 07.06.2021
DESCRIPTION	: To implement some bitwise functions
INPUT & OUTPUT	:

Select bit operation from below list
1. int get_nbits
2. get_nbits_from_pos
3. replace_nbits
4. replace_nbits_from_pos
5. toggle_bits_from_pos
6.print_bits
Enter your choice : 4
Enter the num : 20
Enter the n : 3
Enter the pos : 4
Enter the val: 12
Binary format for given number 20 is
00000000000000000000000000010100
Binary format for given value 12 is
00000000000000000000000000001100
Interchange 3 bits from position 4 in num 20 by fetching 3 bits from LSB of val 12 is
00000000000000000000000000010000
Solution is : 16 

Do you want to continue (y/Y) : n

*********************************************/
//To implement some bitwise functions
#include<stdio.h>
//Function declration
int get_nbits(int num, int n);
int get_nbits_from_pos(int num, int n,int pos);
int replace_nbits(int num, int n,int val);
int replace_nbits_from_pos(int num, int n,int pos,int val);
int toggle_bits_from_pos(int num, int n,int pos);
int print_bits(unsigned int num,int n);

int main()
{
	int num, n,res, pos, val, choice, i;	//Variable declaration
	unsigned int unsigned_num;
	char ch;
	do
	{
		printf("Select bit operation from below list\n1. int get_nbits\n2. get_nbits_from_pos\n3. replace_nbits\n4. replace_nbits_from_pos\n5. toggle_bits_from_pos\n6.print_bits\n");	
		printf("Enter your choice : ");	//Ask users choice
		scanf("%d",&choice);
		
		switch (choice)
		{
			case 1:			
				printf("Enter the num : ");
				scanf("%d",&num);
				printf("Enter the n : ");
				scanf("%d",&n);
				res=get_nbits(num,n);
				printf("Binary format for %d -->  ",num);
				for(i=31;i>=0;i--)
					printf("%d",(num >> i) & 1); 
				printf("\n");
				printf("%d bits from LSB-->  ",n);
				for(i=31;i>=0;i--)
					printf("%d",(res >> i) & 1);		
				printf("\n");
				printf("Solution is : %d \n",res);
				break;
			case 2:
				printf("Enter the num : ");
				scanf("%d",&num);
				printf("Enter the n : ");
				scanf("%d",&n);
				printf("Enter the val: ");
				scanf("%d",&val);
				res=replace_nbits(num,n,val);
				printf("Binary format for %d is\n",num);
				for(i=31;i>=0;i--)
					printf("%d",(num >> i) & 1);	
				printf("\n");
				printf("Binary format for given value %d is\n",val);
				for(i=31;i>=0;i--)
					printf("%d",(val >> i) & 1);
				printf("\n");
				printf("After fetching %d bits from LSB of %d replacing in %d bits of LSB of num %d is\n",n, val, n, num);
				for(i=31;i>=0;i--)
					printf("%d",(res >> i) & 1);	
				printf("\n");
				printf("Solution is  : %d\n",res);
				break;
			case 3:
				printf("Enter the num : ");
				scanf("%d",&num);
				printf("Enter the n : ");
				scanf("%d",&n);
				printf("Enter the pos: ");
				scanf("%d",&pos);
				res=get_nbits_from_pos(num,n,pos);
				printf("Binary format for %d is \n",num);
				for(i=31;i>=0;i--)
					printf("%d",(num >> i) & 1);
				printf("\n");
				printf("%d bits from position %d is\n",n, pos);
				for(i=31;i>=0;i--)
					printf("%d",(res >> i) & 1);			
				printf("\n");
				printf("Value at %d[%d(pos):%d(bits)] --> %d\n",num, pos, n, res);
				printf("Solution is : %d \n",res);
				break;
			case 4:
				printf("Enter the num : ");
				scanf("%d",&num);
				printf("Enter the n : ");
				scanf("%d",&n);
				printf("Enter the pos : ");
				scanf("%d",&pos);
				printf("Enter the val: ");
				scanf("%d",&val);
				res=replace_nbits_from_pos(num,n,pos,val);
				printf("Binary format for given number %d is\n",num);
				for(i=31;i>=0;i--)
					printf("%d",(num >> i) & 1);		
				printf("\n");
				printf("Binary format for given value %d is\n",val);
				for(i=31;i>=0;i--)
					printf("%d",(val >> i) & 1);			
				printf("\n");
				printf("Interchange %d bits from position %d in num %d by fetching %d bits from LSB of val %d is\n",n, pos, num, n, val );
				for(i=31;i>=0;i--)
					printf("%d",(res >> i) & 1);			
				printf("\n");
				printf("Solution is : %d \n",res);
				break;
			case 5:
				printf("Enter the num : ");
				scanf("%d",&num);
				printf("Enter the n : ");
				scanf("%d",&n);
				printf("Enter the pos : ");
				scanf("%d",&pos);
				res=toggle_bits_from_pos(num,n,pos);
				printf("Binary format for %d is\n",num);
				for(i=31;i>=0;i--)
					printf("%d",(num >> i) & 1);		
				printf("\n");
				printf("Toggling %d bits from position %d is\n",n, pos);
				for(i=31;i>=0;i--)
					printf("%d",(res >> i) & 1);				
				printf("\n");
				printf("Solution is : %d \n",res);
				break;
			case 6:
				printf("Enter the num : ");
				scanf("%d",&unsigned_num);
				printf("Enter the n : ");
				scanf("%d",&n);
				if(n>32)
					n=32;
				print_bits(unsigned_num,n);
				break;
			default:
				printf("Enter valid numbers 1 to 6 only\n");
		}	
		printf("\n");	
		printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		printf("\n");
	}  while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	return 0;
}
//1.			
int get_nbits(int num, int n)	// num=10, n=2
{	
	int sol;
	sol=(num & (1 << n)-1); // move 1 << given number of bits then, -1 from that value i.e, mask and then mask '&' with given num
	return sol;
}
//2.
int replace_nbits(int num, int n,int val)	// num=10, n=3, val=12
{	
	int a, b, mask,sol;	
	mask=(1<<n)-1;	//move 1 << given number of bits then, -1 from that value ( so we get mask) 00000111
	b=val & mask;	//given value '&' with mask [ 00001100 & 00000111 = 00000100 stored in b]
	a=num & ~(mask);//num '&' with mask	[ 00001010 & 11111000 = 00001000 stored in a]
	sol= a | b;	// a '|' with b [00001000 | 00000100 = 00001100 stored in sol i.e, 12]
	return sol;
}
//3.
int get_nbits_from_pos(int num, int n,int pos)	// num=12, n=3, pos=4
{	
	int mask,sol, shift;	
	mask=(1<<(pos+1))-1;	//move 1 << of given position + 1 (00100000) and the obtain value - 1 (so we get mask) 00011111
	shift=pos-n+1;		//given pos - number of bits and then add with 1 (so we get shift according to given input) shift=2
	sol= (num & mask) >> shift;//num '&' with mask [00001100 & 00011111 = 00001111] then the value >> 2(shift) so [sol = 00000011 i.e, 3]
	return sol;
}
//4.
int replace_nbits_from_pos(int num, int n,int pos,int val) // num=20, n=3, pos=4, val=12
{	
	int a, b, mask1, mask2, real_mask, sol, shift;
	shift=pos-n+1; //given pos - number of bits and then add with 1 (so we get shift according to given input) shift=2
	mask1=((1<<(pos+1))-1) >> shift;//move 1 << of given position + 1 (00100000) and the obtain value - 1  (00011111) then >> 2(shift) so we get (00000111) 
	real_mask=~(mask1 << shift);	// [mask1 << 2 = 00011100] and ~ of that value is [real_mask=11100011]
	a=num & real_mask;	//num '&' real_mask [00010100 & 11100011 = 00000000]
	mask2=(1 << n)-1;	//move 1 << given number of bits then, -1 from that value ( so we get mask2) 00000111
	b= (val & mask2) << shift;	//val '&' mask2 [00001100 & 00000111 = 00000100] and << 2(shift) so [b= 00010000]
	sol= a | b;	// a '|' with b [00000000 | 00010000 = 00010000 stored in sol i.e, 16]
	return sol;
}
//5.
int toggle_bits_from_pos(int num,int n,int pos)	// num=10, n=3, pos=5
{	
	int a, b, mask, real_mask, sol, shift;
	shift=pos-n+1; //to find shift 5-3+1=3(shift)
	mask=((1<<(pos+1))-1) >> shift;//move 1 << of given position + 1 (01000000) and the obtain value - 1  (00111111) then >> 3(shift) so we get (00000111) 
	real_mask=(mask << shift);  //00000111 << 3 then, real_mask=00111000
	sol=num ^ real_mask;// 00001010 ^ 00111000 , then sol=00110010 i.e, 50
	return sol;
}
//6.
int print_bits(unsigned int unsigned_num,int n)	// num=10, n=12
{	
	int i, sol;
	printf("%d bits of given number %d is\n",n,unsigned_num);
	for(i=n-1;i>=0;i--)
	{
		sol=(unsigned_num >> i) & 1;	
		printf("%d",sol);	// printing n number of bits of given number [000000001010]
	}
	printf("\n");
	return 0;
}	
