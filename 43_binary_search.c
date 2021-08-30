/********************************************
NAME		: Jagajeevan.S
DATE		: 20.07.2021
DESCRIPTION	: To implement binary search all basic data types
INPUT & OUTPUT	: 

Enter the length of an array : 5
1. int
2. char
3. float
4. double
Enter the choice : 1
Enter 5 elements of type int
arr[0] : 1
arr[1] : 2
arr[2] : 8
arr[3] : 7
arr[4] : 4

After sorting : 
arr[0] : 1
arr[1] : 2
arr[2] : 4
arr[3] : 7
arr[4] : 8

Enter the key element to search : 1
Search element 1 is at position 0 of array

Do you want to continue (y/Y) : n


*********************************************/
// To implement binary search all basic data types

#include<stdio.h>

void int_sort_array(void *ptr, int size);
void char_sort_array(void *ptr, int size);
void float_sort_array(void *ptr, int size);
void double_sort_array(void *ptr, int size);

int int_binary_search(void *vptr, int size, int mid,int key);
int char_binary_search(void *vptr, int size, int mid,char key);
int float_binary_search(void *vptr, int size, int mid,float key);
int double_binary_search(void *vptr, int size, int mid, double key);

int main()
{
	char ch;
	do
	{
		int size, choice, pos;
		printf("Enter the length of an array : ");	// read inputs from user
		scanf("%d",&size);
		printf("1. int\n2. char\n3. float\n4. double\nEnter the choice : ");
		scanf("%d",&choice);
		
		
		if ( choice == 1 )		// int
		{
			int arr[size], key;
			printf("Enter %d elements of type int\n",size);
			for ( int i=0; i<size; i++)
			{
				printf("arr[%d] : ",i);
				scanf("%d",&arr[i]);	// read elements from user (int)
			}
	
			int_sort_array(arr,size);	// func call for sorting
			printf("\nAfter sorting : \n");	
	
			for ( int i=0; i<size; i++)
				printf("arr[%d] : %d\n",i,arr[i]);	// print elements after sorting
	
			printf("\nEnter the key element to search : ");
			scanf("%d",&key);					// read search element from user
			pos = int_binary_search(arr, size, (size-1)/2,key);	// func call for binary search
		
			if ( pos == -1)
				printf("Element not present\n");
			else
				printf("Search element %d is at position %d of array\n",key,pos);		
		}
		else if ( choice == 2 )	// char
		{
			char arr[size], key;
			printf("Enter %d elements of type char\n",size);
			for ( int i=0; i<size; i++)
			{
				printf("arr[%d] : ",i);
				scanf(" %c",&arr[i]);	// read elements from user (char)
			}

			char_sort_array(arr,size);	// func call for sorting
			printf("\nAfter sorting : \n");	
			for ( int i=0; i<size; i++)
				printf("arr[%d] : %c\n",i,arr[i]);	// print elements after sorting
		
			printf("\nEnter the key element to search : ");
			scanf(" %c",&key);					// read search element from user
			pos = char_binary_search(arr, size, (size-1)/2,key);	// func call for binary search
		
			if ( pos == -1)
				printf("Element not present\n");
			else
				printf("Search element %c is at position %d of array\n",key,pos);	
		}
		else if ( choice == 3 )	// float
		{
			float arr[size], key;
			printf("Enter %d elements of type float\n",size);
			for ( int i=0; i<size; i++)
			{
				printf("arr[%d] : ",i);
				scanf("%f",&arr[i]);	// read elements from user (float)
			}
		
			float_sort_array(arr,size);	// func call for sorting
			printf("\nAfter sorting : \n");	
			for ( int i=0; i<size; i++)
				printf("arr[%d] : %g\n",i,arr[i]);	// print elements after sorting
		
			printf("\nEnter the key element to search : ");
			scanf("%f",&key);					// read search element from user
			pos = float_binary_search(arr, size, (size-1)/2,key); // func call for binary search
		
			if ( pos == -1)
				printf("Element not present\n");
			else
				printf("Search element %g is at position %d of array\n",key,pos);	
		}
		else if ( choice == 4 )	// double
		{
			double arr[size], key;
			printf("Enter %d elements of type double\n",size);
			for ( int i=0; i<size; i++)
			{
				printf("arr[%d] : ",i);
				scanf("%lf",&arr[i]);	// read elements from user (double)
			}
		
			double_sort_array(arr,size);	// func call for sorting
			printf("\nAfter sorting : \n");	
			for ( int i=0; i<size; i++)
				printf("arr[%d] : %g\n",i,arr[i]);	// print elements after sorting
		
			printf("\nEnter the key element to search : ");
			scanf("%lf",&key);						// read search element from user
			pos = double_binary_search(arr, size, (size-1)/2,key);	// func call for binary search
			
			if ( pos == -1)
				printf("Element not present\n");
			else
				printf("Search element %g is at position %d of array\n",key,pos);	
		}
		else
			printf("Invalid choice\n");
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}	
void int_sort_array(void *ptr, int size)	// sorting int elements
{
	int temp;
	for (int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-1-i; j++)
		{
			if( *((int*)ptr+j) > *((int*)ptr+j+1) )
			{
				temp = *((int*)ptr+j);
				*((int*)ptr+j) = *((int*)ptr+j+1);
				*((int*)ptr+j+1) = temp;
			}
		}
	}
}
void char_sort_array(void *ptr, int size)	// sorting char elements
{
	char temp;
	for (int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-1-i; j++)
		{
			if( *((char*)ptr+j) > *((char*)ptr+j+1) )
			{
				temp = *((char*)ptr+j);
				*((char*)ptr+j) = *((char*)ptr+j+1);
				*((char*)ptr+j+1) = temp;
			}
		}
	}
}
void float_sort_array(void *ptr, int size)	// sorting float elements
{
	float temp;
	for (int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-1-i; j++)
		{
			if( *((float*)ptr+j) > *((float*)ptr+j+1) )
			{
				temp = *((float*)ptr+j);
				*((float*)ptr+j) = *((float*)ptr+j+1);
				*((float*)ptr+j+1) = temp;
			}
		}
	}
}
void double_sort_array(void *ptr, int size)	// sorting double elements
{
	double temp;
	for (int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-1-i; j++)
		{
			if( *((double*)ptr+j) > *((double*)ptr+j+1) )
			{
				temp = *((double*)ptr+j);
				*((double*)ptr+j) = *((double*)ptr+j+1);
				*((double*)ptr+j+1) = temp;
			}
		}
	}
}
int int_binary_search(void *vptr, int size, int mid,int key)	// BINARY SEARCH INT
{
	int count = 0;
	for (int i=0; i<size; i++)
	{
		if ( *((int*)vptr+i) == key )		// checks element present or not 
			count++; 
	}
	if ( count == 0 )
		return -1;	// if not return -1
		
	while ( (*((int*)vptr+mid))!= key )	
	{
		if ( *((int*)vptr+mid) > key)
			mid--;
		
		else if ( *((int*)vptr+mid) < key)
			mid++;
	} 
	if ( *((int*)vptr+mid) == key )
			return mid;		// returns position
	
}
int char_binary_search(void *vptr, int size, int mid,char key)	// BINARY SEARCH CHAR
{
	int count = 0;
	for (int i=0; i<size; i++)
	{
		if ( *((char*)vptr+i) == key )
			count++; 
	}
	if ( count == 0 )
		return -1;
		
	while ( (*((char*)vptr+mid))!= key )
	{
		if ( *((char*)vptr+mid) > key)
			mid--;
		
		else if ( *((char*)vptr+mid) < key)
			mid++;
	} 
	if ( *((char*)vptr+mid) == key )
		return mid;
}
int float_binary_search(void *vptr, int size, int mid, float key)	// BINARY SEARCH FLOAT
{
	int count = 0;
	for (int i=0; i<size; i++)
	{
		if ( *((float*)vptr+i) == key )
			count++; 
	}
	if ( count == 0 )
		return -1;
		
	while ( (*((float*)vptr+mid))!= key )
	{
		if ( *((float*)vptr+mid) > key)
			mid--;
		
		else if ( *((float*)vptr+mid) < key)
			mid++;
	} 
	if ( *((float*)vptr+mid) == key )
		return mid;	
}
int double_binary_search(void *vptr, int size, int mid, double key)	// BINARY SEARCH DOUBLE
{
	int count = 0;
	for (int i=0; i<size; i++)
	{
		if ( *((double*)vptr+i) == key )
			count++; 
	}
	if ( count == 0 )
		return -1;
		
	while ( (*((double*)vptr+mid))!= key )
	{
		if ( *((double*)vptr+mid) > key)
			mid--;
		
		else if ( *((double*)vptr+mid) < key)
			mid++;
	} 
	if ( *((double*)vptr+mid) == key )
		return mid;	
}
