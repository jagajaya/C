/********************************************
NAME		: Jagajeevan.S
DATE		: 20.07.2021
DESCRIPTION	: To implement mean calculation for all data types
INPUT & OUTPUT	: ./a.out 5

1. int
2. short
3. float
4. double
Enter the choice : 1
Enter 5 elements
arr[0] : 10
arr[1] : 20
arr[2] : 30
arr[3] : 40
arr[4] : 50
Mean 30

Do you want to continue (y/Y) : y
1. int
2. short
3. float
4. double
Enter the choice : 5
Invalid choice

Do you want to continue (y/Y) : n

*********************************************/
// To implement mean calculation for all data types

#include<stdio.h>
#include<stdlib.h>
int my_atoi(char *str);
float calc_mean(int size, int choice);

int main(int argc, char **argv)		// PAASING NO OF ELEMENTS THROUGH CMD LINE ARGUMRNTS
{
	char ch;
	do
	{
		int choice, size;	// VARIABLE DELARATION
		
		printf("1. int\n2. short\n3. float\n4. double\nEnter the choice : ");
		scanf("%d",&choice);	
	
		if ( choice >= 1 && choice <= 4)
		{
			double mean;
			
			if ( argc == 1 )		// IF USER NOT PASS COMMAND LINE ARGUMENT THEN READ INPUT FROM USER
			{
				printf("Enter number of elements : ");
				scanf("%d",&size);
			}
			else
				size = my_atoi(argv[1]);	// ELSE CONVERT THAT ARG (i.e,STORED IN STRING) TO INTEGER
		
			printf("Enter %d elements\n", size);	
			mean = calc_mean(size,choice);	//FUNCTION CALL
			printf("Mean %g\n",mean);
		}
		else
			printf("Invalid choice\n");
			
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;		
}
	
float calc_mean(int size,int choice)
{
	void *ptr;	//	VOID POINTER
	float avg;
	
	if (choice == 1)	// INT 
	{
		int arr[size] , sum = 0;
		ptr = &arr;
		for (int i=0; i < size;i++)
		{
			printf("arr[%d] : ",i);
			scanf("%d",&arr[i]);	// READ INPUTS FROM USER
			
			sum = sum + *((int*)ptr+i); // pointer converted to int it fetch [sizeof(int)] bytes 
		}
		avg = (float) sum / size;
	}
	else if (choice == 2) // SHORT
	{
		short arr[size] , sum = 0;
		ptr = &arr;
		for (int i=0; i < size;i++)
		{
			printf("arr[%d] : ",i);
			scanf("%hd",&arr[i]);	// READ INPUTS FROM USER
			
			sum = sum + *((short*)ptr+i);	// pointer converted to short it fetch [sizeof(short)] bytes 
		}
		avg = (float) sum / size;
	}
	else if (choice == 3)	// FLOAT
	{
		float arr[size] , sum = 0;
		ptr = &arr;
		for (int i=0; i < size;i++)
		{
			printf("arr[%d] : ",i);
			scanf("%f",&arr[i]);	// READ INPUTS FROM USER
			
			sum = sum + *((float*)ptr+i);	// pointer converted to float it fetch [sizeof(float)] bytes 
		}
		avg = sum / size;
	}
	else if (choice == 4)	// DOUBLE
	{
		double arr[size] , sum = 0;
		ptr = &arr;
		for (int i=0; i < size;i++)
		{
			printf("arr[%d] : ",i);
			scanf("%lf",&arr[i]);	// READ INPUTS FROM USER
			sum = sum + *((double*)ptr+i);  // pointer converted to double it fetch [sizeof(double)] bytes 
		}	
		avg = sum / size;
	}
	return avg;
}

int my_atoi(char *str)
{
	int a, temp = 0, check = 0, flag_p = 0, flag_n = 0;
	
	while(*str)
	{
		if ( ( check == 0 && *str == '+' ) || ( check == 0 && *str == '-' ) )	// Checks 1st char is '+' or '-'
		{
			if( *str == '+' )
			{
				flag_p = flag_p + 1;	// flag_p count incremented
				//continue;
			}
			else if( *str == '-' )
			{
				flag_n = flag_n + 1;	// // flag_n count incremented
				//continue;
			}
		}
		else if ( *str >= '0' && *str <= '9' )	// Checks entered ch is number or not
		{
			if ( flag_p <= 1 && flag_n <= 1 )	//  char to int conversion
			{
				temp = ( temp * 10 ) + (*str - 48);
			}
		} 
		else if ( ( check == 1 && *str == '+' ) || ( check == 1 && *str == '-' ) ) // Checks 2nd char is '+' or '-', is yes it comes out of loop
			break;
		else 					// if the entered char is not number and not '+' or '-' it comes out of loop
			break;
		check++;
		str++;
		
	}
	
	 if ( flag_n == 1)	
		return -temp;	//	 returns -ve value
		
	 else if ( flag_p <= 1 && flag_n == 0 )
		return temp;	
		
	 else
	 	return temp;	
}
