/********************************************
NAME		: Jagajeevan.S
DATE		: 13.06.2021
DESCRIPTION	: To find the median of two unsorted arrays
INPUT & OUTPUT	:

Enter the 'n' value of array 1 : 5
Enter the array elements one by one for array  1 : 3 2 8 5 4
After sorting : 2 3 4 5 8 
Median of array 1 : 4
Enter the 'n' value of array 2 : 4
Enter the array elements one by one for array  2 : 12 13 7 5
After sorting : 5 7 12 13 
Median of array 2 : 9.5
Median of both arrays : 6.75

Do you want to continue (y/Y) : y

Enter the 'n' value of array 1 : 20
Max array element exceeded

Do you want to continue (y/Y) : n

*********************************************/
//To find the median of two unsorted arrays

#include<stdio.h>
int main()
{
	//variable declaration
	int size,a=0,b,c,i,j,temp=0;
	float median1=0,median2=0,median,d;
	char ch;
	do
	{
		b=0;
		while (b++ < 2)	// loop for 2 arrays
		{
			c=b;
			printf("Enter the 'n' value of array %d : ",c);
			scanf("%d",&size);//Read size from user
			
			if((1 < size) && (size < 10))	// checks array size
			{
				int arr[size];
				printf("Enter the array elements one by one for array  %d : ",c);
				for(int i=0;i<size;i++)
				{
					scanf("%d",&arr[i]);	//Read inputs from user
				}
				//Sorting array in ascending order
				for(int i=0;i<size-1;i++)
				{
					for(int j=0;j<size-1-i;j++)
					{
						if(arr[j] > arr[j+1])
						{ 
							temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
				}
				printf("After sorting : ");
				for(int i=0;i<size;i++)
				{
					printf("%d ",arr[i]);	// prints array elements after sorting
				}
				printf("\n");
				if(size%2 == 0) // median for even size array
				{
					a=size/2;
					d=((float) arr[a]+arr[--a])/2;
					printf("Median of array %d : %g\n",c,d);
					median1=median1+d;
				}
				else // median for odd size array
				{
					a=size/2;
					d=arr[a];
					printf("Median of array %d : %g\n",c,d);
					median2=median2+d;
				}
			}
			else
			{
				printf("Max array element exceeded\n");	// if array size is invalid
				goto ask;	// going to ask the user
			}
		}
		median=(float)(median1+median2)/(--b); // avg median value
		printf("Median of both arrays : %g\n",median);
	ask:
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		printf("\n");
		
	 } while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
		
	return 0;
}
