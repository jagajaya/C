/********************************************
NAME		: Jagajeevan.S
DATE		: 20.07.2021
DESCRIPTION	: To generate a n*n magic square 
INPUT & OUTPUT	:

Enter a number : 3
 8   1   6  
 3   5   7  
 4   9   2  

Do you want to continue (y/Y) : y
Enter a number : 4
Enter odd numbers only

Do you want to continue (y/Y) : y
Enter a number : 5
17  24   1   8  15  
23   5   7  14  16  
 4   6  13  20  22  
10  12  19  21   3  
11  18  25   2   9  

Do you want to continue (y/Y) : n

*********************************************/
// To generate a n*n magic square

#include<stdio.h>
#include <stdlib.h>
void magic_square (int size, int *p[size] );

int main()
{
	char ch;
	do
	{
		int num, row, col;	// variable declaration
		printf("Enter a number : ");	// read input from user
		scanf("%d",&num);
	
		if (num % 2 == 0 )
			printf("Enter odd numbers only\n");	// checks valid input or not
		else if ( num <= 0 )
			printf("Enter positive numbers");
		else
		{
			int row = num;
			int **arr;			// array pointer 
			arr = calloc(num, sizeof(int *) ); 		// row and column memory allocation
			
			for (int i=0; i < num ;i++)
				arr[i] = calloc(num, sizeof(int) );
			
			magic_square(num, arr);	// func call
			
			for (int i=0; i < row ;i++)
			{
				for (int j=0; j < row ;j++)
				{
					printf("%2d  ", arr[i][j] );	// printing elements 
				}
				printf("\n");
			}
			free (arr);	// freeing the memory
		}
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

	return 0;
}	
void magic_square (int size, int *p[size] )
{
	int total = size * size;	
	int i = 0; 
	int j = size/2;
	
	for ( int k=1; k <= total; k++)
	{
		p[i][j] = k;		// allocate value according to position
		
		i--;			// decrement row
		j++;			// increment column
		
		if ( i < 0 ) 		// if row reduces to -1 increment row to its last position
			i = i + size;
		
		if ( j == size  )	// if column increases to its last position reduce column to its initial position
			j = 0;
		
		if (p[i][j] != 0)	// checks if there is any element present in that position 
		{
			i = i + 2;
			j = j - 1;
			
			if ( i > size && j < 0 )
			{
				i = i - size;
				j = size - 1 ;
			}
		}	
	}		
}
