/********************************************
NAME		: Jagajeevan.S
DATE		: 27.07.2021
DESCRIPTION	: To implement fragments using array pointers ( First static Second dynamic)
INPUT & OUTPUT	: 

Enter the number of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Before sorting
1 2 3 4 2.5 
2 5 9 5.33333 
1 3 2 4 1 2.2 

After sorting
1 3 2 4 1 2.2 
1 2 3 4 2.5 
2 5 9 5.33333 
Do you want to continue(y/Y):n


*********************************************/
// To implement fragments using array pointers ( First static Second dynamic)

#include<stdio.h>
#include <stdlib.h>
void print_array(int rows , int *col, float **ptr);

int main()
{
	char ch; 
	
	do
	{
		int rows, i, j, a; 
		float avg = 0, sum = 0; 	// variable declaration
	
		printf("Enter the number of rows : ");
		scanf("%d",&rows);	// read no of rows from user
	
		int col[rows] , temp= 0;
	
		float *ptr[rows];	// array of pointer
		float * addr;
	
		for ( i=0; i < rows; i++)
		{
			printf("Enter no of columns in row[%d] : ",i);	// read no of column element for i th row 
			scanf("%d",&col[i]);
		
			ptr[i] = malloc ( (col[i]+1) * sizeof (float) );	// dynamic memory allocation
		}	
		for ( i=0; i < rows; i++)
		{
			printf("Enter %d values for row[%d] : ",col[i], i);
			
			for (j=0; j < col[i]  ;j++)
		 		scanf("%f",&ptr[i][j]);	// read row elements from user 	
		}
	
		for ( i=0 ; i < rows; i++ )	// avg calculation
		{
			for ( j=0; j < col[i] ;j++)
		 	{
		 		sum = sum + ptr[i][j];
		 	}
		 	avg = sum / col[i];	
		 	ptr[i][j] = avg;
		 	avg = 0;
		 	sum = 0; 
		}
	 
		printf("\nBefore sorting\n");
		
		print_array(rows,col,ptr);		// func call for printing 
		
		for ( int i=0; i < rows; i++)	// array sorting
		{
			for ( int j=i+1; j < rows; j++)
		 	{
		 		if ( ptr[i][col[i]] > ptr[j][col[j]] )
		 		{
		 			temp = col[i];
		 			col[i] = col[j];
		 			col[j] = temp;
	 			
		 			addr = ptr[i];
		 			ptr[i] = ptr[j];
		 			ptr[j] = addr;	
		 		}
		 	 }
		 }
	
		 printf("\nAfter sorting\n");
	
		 print_array(rows,col,ptr);	// func call for printing 
		 
		 printf("Do you want to continue(y/Y):"); // asking for continue
     		 scanf(" %c",&ch);
     			
    }while (ch == 'Y' || ch == 'y');  	// condition checking
    
    return 0;
}
 
void print_array(int rows , int *col, float **ptr)	// to print array elements
{
	 for ( int i=0; i < rows ; i++)
	 {
	 	for ( int j=0; j <= col[i] ; j++)
	 	{
	 		printf("%g ",ptr[i][j]);
	 	}
	 	printf("\n");
	 } 
}
