/********************************************
NAME		: Jagajeevan.S
DATE		: 08.08.2021
DESCRIPTION	: To print the bits of float and double,IEEE standard
INPUT & OUTPUT	:

Enter the choice :
1.Float
2.Double
Choice : 1
Enter the float value : 2.3
Sign	Exponent		Mantissa
----------------------------------------------------------------
0	1 0 0 0 0 0 0 0 	0 0 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 

Do you want to continue(y/Y):y
Enter the choice :
1.Float
2.Double
Choice : 2
Enter the double value : -2.3
Sign - 1
Exponent - 10000000000
Mantissa - 0010011001100110011001100110011001100110011001100110

Do you want to continue(y/Y):n

*********************************************/
// To print the bits of float and double,IEEE standard

#include<stdio.h>
void my_float (void *ptr, int size);
void my_double (void *dptr, int size);

int main()
{
	char ch;
	do
	{
		int choice;
		printf("Enter the choice :\n1.Float\n2.Double\nChoice : ");	// read choice from user
		scanf("%d",&choice);
		if ( choice ==1 )
		{
			float num ;
			printf("Enter the float value : ");	// read float value from user
			scanf("%f",&num);
			
			my_float( &num, sizeof(num));	// func call
		
		}
		else if ( choice == 2 )
		{
			double num ;
			printf("Enter the double value : ");	// read double value from user
			scanf("%lf",&num);
			
			my_double ( &num, sizeof(num));	// func call
		}
		else
			printf("Invalid Choice\n");
		
		printf("\nDo you want to continue(y/Y):"); // asking for continue
     		scanf(" %c",&ch);
     			
     	}while (ch == 'Y' || ch == 'y');  	// condition checking
    
    return 0;
}
void my_float (void *ptr,int size)	// FUNCTION TO PRINT FLOAT ELEMENTS
{
	int count = 0;
	printf("Sign\tExponent\t\tMantissa\n----------------------------------------------------------------\n");
		for(int i= (size-1) ; i>=0; i--)
		{	
			for (int j=7; j >= 0; j--)
			{
				if (count == 0)
				{
					printf("%d\t",( *(char*)(ptr+i) >> j ) & 01 );	// sign bit
					count ++;
				}
				else if (count > 0 && count < 9)
				{
					printf("%d ",( *(char*)(ptr+i) >> j ) & 01 );		// exponent part
					count ++;
				}
				if (count == 9)
				{
					printf("\t");
					count++;
				}
				else if (count >= 9)
				{
					printf("%d ",( *(char*)(ptr+i) >> j ) & 01 );		// mantissa part
					count++;
				}
			}
		}
		printf("\n");
}
void my_double (void *dptr, int size)		// FUNCTION TO PRINT DOUBLE ELEMENTS
{
	int count = 0;
	for(int i=(size-1); i>=0; i--)
		{	
			for (int j=7; j >= 0; j--)
			{
				if (count == 0)
				{
					printf("Sign - %d\nExponent - ",( *(char*)(dptr+i) >> j ) & 01 );	// sign bit
					count ++;
				}
				else if (count > 0 && count < 12)
				{
					printf("%d",( *(char*)(dptr+i) >> j ) & 01 );				// exponent part
					count ++;
				}
				if (count == 12)
				{
					printf("\nMantissa - ");
					count++;
					//count++;
				}
				
				else if (count >= 12)
				{
					printf("%d",( *(char*)(dptr+i) >> j ) & 01 );				// mantissa part
					count++;
				}
			}
		}
		printf("\n");
}
