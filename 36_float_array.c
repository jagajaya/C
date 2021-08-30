/********************************************
NAME		: Jagajeevan.S
DATE		: 27.06.2021
DESCRIPTION	: To sort the float array without modifying or copying
INPUT & OUTPUT	:

Enter the count of float elements need to store : 5
[0] = 10.0
[1] = 1.2
[2] = 3.2
[3] = 8.2
[4] = -1.4
Before Sorting : 10  1.2  3.2  8.2  -1.4  
Sorted Array  : 
-1.4  1.2  3.2  8.2  10 
Array elements remain same : 10  1.2  3.2  8.2  -1.4  

Do you want to continue (y/Y) : n

*********************************************/
//To sort the float array without modifying or copying

#include<stdio.h>
//Function declaration
void array_sort(float arr[], int size);
void print_array(float arr[],int size);

int main()
{
	//Variable declaration
	char ch;
	int size;
	do
	{
		printf("Enter the count of float elements need to store : ");	//Read array size from user 
		scanf("%d",&size);
		float arr[size];
	
		for (int i = 0; i < size; i++)	//Reading array elements
		{
			printf("[%d] = ",i);
			scanf("%f", &arr[i]);
		}
		printf("Before Sorting : ");	//Print array elment before sorting 
		print_array(arr,size);
	
		printf("\nSorted Array  :\n");	//To print the elements in sorted order without modifying the array
		array_sort(arr,size);
	
		printf("\n\nArray elements remain same : ");	
		print_array(arr,size);		//After sorting array elements remain same
		
		printf("\n\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
//Function Definition

void print_array(float arr[],int size)
{
	for (int i = 0; i < size; i++)
		printf("%g  ", arr[i]);	//Print array elements
}
void array_sort(float arr[], int size)
{
	int count , value, pos;
	value = size-1;
	
	for(int i = 0; i < size;i++)		//Sorting of array 
	{
		
		pos = 0;
		ask:
		
		count = 0;
		for(int j = 0; j < size ; j++) 
		{
			if ( arr[pos] < arr[j] )
				count++;
		}
		
		if ( count == value)
				printf("%g  ",arr[pos]);	//Prints array elemnt in sorted order
		else
		{
			pos++;
			goto ask;
		}
		--value;
	}
}
				
