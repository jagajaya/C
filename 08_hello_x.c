/********************************************
NAME		: Jagajeevan.S
DATE		: 02.06.2021
DESCRIPTION	: To print hello in x format
INPUT & OUTPUT	:

Enter the number lines : 5

Hello    Hello 
 Hello  Hello  
  HelloHello  
 Hello  Hello  
Hello    Hello 
Do you want to continue (y/Y) : y
Enter the number lines : 6

Hello    Hello
 Hello  Hello 
  HelloHello  
  HelloHello  
 Hello  Hello 
Hello    Hello
Do you want to continue (y/Y) : Y
Enter the number lines : 32

Number out of range
Do you want to continue (y/Y) : y
Enter the number lines : -1

Enter only positive values
Do you want to continue (y/Y) : n

*********************************************/
// To print hello in x format

#include<stdio.h>
int main()
{
	int num, check=1;
	char ch;
	for (int i=1;i<=5;i++) // finding limit values
    	     check=check*2;
    	do
    	{
      		printf("Enter the number lines : ");	// readinginputs from user
		scanf("%d",&num);
		printf("\n");
      		
      		if(num < check && num > 0)	// condion checks input is with in limit
		{
			// x format printing
			if(num % 2 == 0)// checks odd or ven number
			{
				for (int i=1;i<=num;i++)
				{
					for(int j=1;j<=num;j++)
					{
						if (i==j || i+j == (num+1))
						{
							printf("Hello");
							if (i==j && i+j == (num+1))
								printf("Hello");			
						}
						else 
							printf(" ");
					}
				printf("\n");
				}
			}
			else
			{
				for (int i=1;i<=num;i++)
				{
					for(int j=1;j<=num;j++)
					{
						if (i==j || i+j == (num+1))
						{
							if (i==j && i+j == (num+1))
								printf("Hello");
							if (num != 0)
								printf("Hello ");	
							else
								printf("Hello ");
						}	
						else
						printf(" ");
					}
				printf("\n");
				}
			}
		}		
		else if(num >= check)				// checks input range is higher than limit
			printf("Number out of range\n");
				
		else if(num <= 0)				// checks input range is lower than limit
			printf("Enter only positive values\n");
		
		printf("Do you want to continue (y/Y) : ");
		scanf(" %c",&ch);
		
	}  while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion	
	
	return 0;
}
