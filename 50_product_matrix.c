/********************************************
NAME		: Jagajeevan.S
DATE		: 20.07.2021
DESCRIPTION	: To find the product of the given matrix
INPUT & OUTPUT	:

Enter the nuber of rows : 3
Enter the nuber of columns : 3
Enter values for 3 * 3 matrix : 
1 2 3
1 2 3
1 2 3
Given Matrix
1   2   3   
1   2   3   
1   2   3   
Transpose of given Matrix
1   1   1   
2   2   2   
3   3   3   
Product of two Matrix
14   14   14   
14   14   14   
14   14   14   

Do you want to continue (y/Y) : y
Enter the nuber of rows : -3
Enter the nuber of columns : 3
GIVE POSITIVE VALUES

Do you want to continue (y/Y) : n


*********************************************/
//To find the product of the given matrix
#include<stdio.h>
#include<stdlib.h>
void print_array(int row,int col,int *ptr[col]);

int main()
{
	char ch;
	do
	{
		int row, col, row_t, col_t, sum = 0;	//	 variable declaration
		printf("Enter the nuber of rows : ");
		scanf("%d",&row);			// read rows and columns from user	
		printf("Enter the nuber of columns : ");
		scanf("%d",&col);
		
		if( row <= 0 || col <= 0)
			printf("GIVE POSITIVE VALUES\n");
		else
		{	
			int **A;
			A = malloc ( row * sizeof(int) );	// rows dynamic memory allocation
	
			for (int i=0; i < row; i++)
			{
				A[i] = malloc ( col * sizeof(int) );	//// columns dynamic memory allocation
			}

			printf("Enter values for %d * %d matrix : \n",row, col);
	
			for (int i=0; i< row; i++)
			{
				for (int j=0; j < col; j++)
				{
					scanf("%d",&A[i][j]);	// Read input from user
				}
			}
			printf("Given Matrix\n");
			print_array(row,col,A);
		
			//Transpose Array
			int **AT;
			row_t = col;
			col_t = row;
		
			AT = malloc ( row_t * sizeof(int) );	// rows dynamic memory allocation for Transpose
		
			for (int i=0; i < row_t; i++)
			{
				AT[i] = malloc ( col_t * sizeof(int) );	//// columns dynamic memory allocation for Transpose
			}
	
			for (int j=0; j < col; j++)
			{
				for (int i=0; i< row; i++)
				{
					AT[j][i] = A[i][j];	//	elements changing
				}
			}
			printf("Transpose of given Matrix\n");
			print_array(col,row,AT);
		
			// Multiplied matrix Array
		
			int **B;
			B = malloc ( row * sizeof(int) );	// rows dynamic memory allocation for Solution
		
			for (int i=0; i < row; i++)
			{
				B[i] = malloc ( col_t * sizeof(int) );	//// columns dynamic memory allocation for Solution
			}
		
			for (int i=0; i< row; i++)
			{
				for (int j=0; j < row; j++)
				{
					for ( int k=0; k < col; k++) 
					{
						sum = sum + A[i][k] * AT[k][j];	// matrix multiplication process
					}
					B[i][j] = sum;
					sum = 0;
				}
			}
			printf("Product of two Matrix\n");
			print_array(row,col_t,B);
			
			// Freeing the pointers
			free(A);
			free(AT);
			free(B);
		}
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

	return 0;	
}	
void print_array(int row,int col,int *ptr[col])
{
	for (int i=0; i< row; i++)
	{
		for (int j=0; j < col; j++)
		{
			printf("%d   ",ptr[i][j]);	// printing the array elements
		}
		printf("\n");
	}
}
