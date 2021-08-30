/********************************************
NAME		: Jagajeevan.S
DATE		: 31.05.2021
DESCRIPTION	: To check the given nuber is odd or even and its signedness
INPUT		: Enter the value of 'n' : -4
OUTPUT		: -4 is -ve even number
		  Do you want to continue(y/Y):y
		  Enter the value of 'n' : 4
		  4 is +ve even number
		  Do you want to continue(y/Y):n

*********************************************/
//To check the given nuber is odd or even and its signedness
#include<stdio.h>

int main()
{
    int num, check;	// declaring variables						
    char ch;
    check=1;
    
    for (int i=1;i<=20;i++) // finding limit values
    	check=check*2;
   
    do
    {
    	printf("Enter the value of 'n' : "); 
    	scanf("%d",&num);			//getting input
    	
    	if (-check < num && num < check)	// checks number is with in limit
    	{
		if (num == 0)			// if num is 0 it executes
		{	
	     		printf(" %d is neither odd nor even\n",num);
		}
		else if (num > 0)		// if num is > 0 it executes odd or even
		{
	     		if (num%2 == 0)
	     		    printf("%d is +ve even number\n",num);
	     		else
	     		    printf("%d is +ve odd number\n",num);  	  
		}
		else if (num < 0)		// if num is < 0it executes odd or even
		{
	     		if (num%2 == 0)
	     		    printf("%d is -ve even number\n",num);
	     		else
	     		    printf("%d is -ve odd number\n",num);  	  
		}
     	}
     	else
     		printf("Number out of range"); // if num is out of limit it printed
     	
     	printf("Do you want to continue(y/Y):"); // asking for continue
     	scanf(" %c",&ch);
     			
    } while (ch == 'Y' || ch == 'y');  	// condition checking
    
    return 0;
}



