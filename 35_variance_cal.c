/********************************************
NAME		: Jagajeevan.S
DATE		: 12.07.2021
DESCRIPTION	: To calculate variance with static and dynamic arrays
INPUT & OUTPUT	:

Enter the number of elements : 10
1. Ststic allocation
2. Dynamic allocation
Enter your choice : 2
[0] --> 9
[1] --> 12
[2] --> 15
[3] --> 18
[4] --> 20
[5] --> 22
[6] --> 23
[7] --> 24
[8] --> 26
[9] --> 31

x(input)	D=x-Mean	D^2
9		-11		121
12		-8		64
15		-5		25
18		-2		4
20		0		0
22		2		4
23		3		9
24		4		16
26		6		36
31		11		121
Sum = 200			Sum = 400
Variance is 40

Do you want to continue (y/Y) : n


*********************************************/
// To calculate variance with static and dynamic arrays

#include<stdio.h>
#include<stdlib.h>
void my_static (int *ptr ,int );
void my_dynamic (int );

int main()
{
	int elements, choice;
	char ch;			// variable declaration
	
	do
	{
		printf("Enter the number of elements : ");
		scanf("%d",&elements);				// read elements from user		
	
		printf("1. Ststic allocation\n2. Dynamic allocation\nEnter your choice : ");
		scanf("%d",&choice);
 
		switch (choice)
		{
			case 1:
				{
					int arr[elements];
					my_static(arr,elements);	// static memory function call
					break;	
				}
			case 2:
				my_dynamic(elements);		// dynamic memory function call
				break;
			default:
				printf("Error :Enter valid option\n");
		}
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
			
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

	return 0;	
}

void my_static (int *ptr ,int size)
{
	float sum = 0, mean = 0, sum_var = 0, d, var;
	for ( int i=0; i < size; i++)
	{
		printf("[%d] --> ",i);
		scanf("%d",&ptr[i]);		// reading array elements
		sum = sum + ptr[i];	
	}
	
	mean = sum / size;			// mean calculation
	printf("\nx(input)\tD=x-Mean\tD^2\n");
	
	for(int i=0; i < size; i++)
	{
		d = ptr[i] - mean;
		var = d * d;
		sum_var = sum_var + var;
		printf("%d\t\t%g\t\t%g\n",ptr[i], d, var );
	}
	printf("Sum = %g\t\t\tSum = %g\n",sum,sum_var);
	printf("Variance is %g\n", sum_var / size);	// variance calculation
}

void my_dynamic (int size)
{
	
	float sum = 0, mean = 0, sum_var = 0, d, var;
	int *ptr;
	ptr = calloc ( size, sizeof(size));		// dynamic array created
	
	if (ptr == NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		for ( int i=0; i < size; i++)
		{
			printf("[%d] --> ",i);
			scanf("%d",&ptr[i]);		// reading array elements
			sum = sum + ptr[i];
		}
		mean = sum / size;			// mean calculation
		printf("\nx(input)\tD=x-Mean\tD^2\n");
	
		for(int i=0; i < size; i++)
		{
			d = ptr[i] - mean;
			var = d * d;
			sum_var = sum_var + var;
			printf("%d\t\t%g\t\t%g\n",ptr[i], d, var );
		}
		printf("Sum = %g\t\t\tSum = %g\n",sum,sum_var);
		printf("Variance is %g\n", sum_var / size);
	
		free (ptr);		// frees the pointer
		ptr = NULL;		// pointer that hold the address is set to NULL  
	}
}
