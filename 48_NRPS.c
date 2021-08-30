/********************************************
NAME		: Jagajeevan.S
DATE		: 07.07.2021
DESCRIPTION	: To generate consecutive NRPS
INPUT & OUTPUT	:

Enter the number of characters K: 3
Enter the length of the string N: 6
Enter 3 distinct characters	: a b c
Possible NRPS is		: abcbca

Do you want to continue (y/Y) : y
Enter the number of characters K: 3
Enter the length of the string N: 7
Enter 3 distinct characters	: a b a
Error : Enter distinct characters

Do you want to continue (y/Y) : n

*********************************************/
// To generate consecutive NRPS

#include<stdio.h>
void nrps( char arr[], int n_char, int length);

int main()
{
	int n_char,length;	// variable declaration
	char ch;
	do
	{
		printf("Enter the number of characters K: ");
		scanf("%d",&n_char);					// read n_char from user 
	
		if( n_char >= 1 && n_char <= 10 )			
		{
			printf("Enter the length of the string N: ");
			scanf("%d",&length);				// read string length from user
	
			if(length >1 )
			{
		
				char arr[n_char];
				printf("Enter %d distinct characters	: ", n_char);
		
				for (int i = 0;i < n_char;i++)
				{
					scanf(" %c",&arr[i]);		// read n_char no of characters from user
				}
				// checks repetition
				for( int i=0; i < n_char ; i++)
				{
					for(int j=i+1 ; j < n_char ; j++)
					{
						if ( arr[i] == arr[j] )
						{
							printf("Error : Enter distinct characters\n");
							goto ask;
						}	
					}	
				}
	
				printf("Possible NRPS is		: ");
				nrps(arr,n_char,length);			// function call
			}
			else
			{
				printf("Error : Invalid number \n");
			}
		}
		else
		{
			printf("Error : Invalid number \n");
		}
	
		
		ask:
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

	return 0;	
}
// Function definiton

void nrps( char arr[], int n_char, int length)
{
	for( int j=0 ; j < length ; j++)
	{
		for (int  i = 0;i < n_char;i++)
		{
			if( j < length)
			{
				printf("%c",arr[i]);		// print characters
				j++;
			}
			if( (j % n_char == 0) && ( j != 0) )	
				j--;
		}
		if( j <= length)		// changing the array elements
		{
			int k,temp;
			temp = arr[0];
			for ( k = 0;k < n_char-1;k++)
			{
				arr[k] = arr[k+1];	
			}
			arr[k] = temp;
		}	
	}
	printf("\n");		
}	 

/*	Another method

	int count=0;
	for( int i = 0 ; i <length ; i++)
	{
		if( (i % n_char == 0) && ( i != 0) )
			 count++;
			 
		printf("%c",arr[(i+count) % n_char]);
	}
	
	}*/
