/********************************************
NAME		: Jagajeevan.S
DATE		: 27.07.2021
DESCRIPTION	: To implement 
INPUT & OUTPUT	: 

Enter number of words : 5
Enter the 5 names of length max 32 caharacters in each
32
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

The Sorted names are:
[0] -> Agra 
[1] -> Bengaluru 
[2] -> Chennai 
[3] -> Delhi 
[4] -> Kolkata 
Do you want to continue(y/Y):n

*********************************************/

#include<stdio.h>
#include <stdlib.h>

void sort_array( char (*ptr)[32], int size);
int my_strcmp( char *str1, char *str2);
void my_swap(char *arr1, char *arr2,int len);

int main()
{
	char ch;
	do
	{
		int num, len = 0, count = 0;		// variable declaration
		char (*name)[32];
		
		printf("Enter number of words : ");
		scanf("%d",&num);			// read no.of.words from user 
		
		printf("Enter the %d names of length max 32 caharacters in each\n",num);
		
		name = malloc(sizeof(*name) * num);	// dynamic memory allocation for name
		printf("%ld\n",sizeof(*name));
		
		for(int i=0; i < num; i++)
		{
			printf("[%d] -> ",i);
			scanf("%s",name[i]);	// read name from user
			len =0;
			for ( int j=0; *(*(name+i)+j) != '\0' ; j++)
				len++;
		
			if (len >= 32 ) // length checking
			{
				printf("Error : please enter name with only 32 characters including null character \n"); 
				count =1;
				break;
			}
		}
		if ( count != 1)
		{
			printf("\nThe Sorted names are:\n");
			sort_array(name,num);			// func call for sort array
			
			for(int i=0; i < num; i++)
			{
				printf("[%d] -> ",i);
				printf("%s \n",name[i]);	// printing outputs in ascending order
			}
		}

		free (name);	// freeing the poiner
		name = NULL;
		
		printf("Do you want to continue(y/Y):"); // asking for continue
     		scanf(" %c",&ch);
     			
     	}while (ch == 'Y' || ch == 'y');  	// condition checking
    
    return 0;
}	
void sort_array( char (*ptr)[32], int size)	// sorting names
{
	for(int i=0; i<size; i++)
	{
		for (int j=0; j<size-i-1; j++)
		{
			if ( (my_strcmp(*(ptr+j), *(ptr+j+1)) ) > 0 )
				my_swap( *(ptr+j), *(ptr+j+1), 32 );
		}
	}
}
int my_strcmp( char *str1, char *str2)	
{
	int i=0;
	while (1)
	{
		// Compares character treats uppercase and lower case as same
		
		if ( ( str1[i] && str2[i] ) && ( str1[i] == str2[i] ) && ( (str1[i] + 32 == str2[i]) || (str1[i] - 32 == str2[i]) ) )
			i++;
		else
			break;
	}
	if ( str1[i] == str2[i] )
		return 0;
	else
		return str1[i] - str2[i];
}
void my_swap(char *arr1, char *arr2,int len)	// swaping words
{
	char temp;
	for (int i=0; i < len; i++)
	{
		temp = *arr1;
		*arr1 = *arr2;
		*arr2 = temp;
		arr1++;
		arr2++;
	}
}

