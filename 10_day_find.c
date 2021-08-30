/********************************************
NAME		: Jagajeevan.S
DATE		: 03.06.2021
DESCRIPTION	: To find the day of the year
INPUT & OUTPUT	:

Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 3
The 9 th day is Wednesday

Do you want to continue (y/Y) : y
Enter the value of 'n' : 366
Error: Invalid Input, n value should be > 0 and <= 365
Do you want to continue (y/Y) : y
Enter the value of 'n' : 52
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 8
Error: Invalid Input first day should be > 0 and <= 7
Do you want to continue (y/Y) : n

*********************************************/
// To find the day of the year

#include<stdio.h>

int main()
{
	int num, choice, day; //variable declaration 
	char ch;
	
    	do
    	{
    		printf("Enter the value of 'n' : "); // read nth day
    		scanf("%d",&num);
    		if (num > 0 && num <= 365 ) // checks condition of the given day
    		{
    			printf("Choose First Day :\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");
    			printf("Enter the option to set the first day : ");
    			scanf("%d",&choice);
    			
    			if (choice >=1 && choice <=7)	// checks option is valid or not
    			{
    				day=(num+choice-1)%7; // to find the day order
    			
    				//Printing the exact day as we required 
    				switch (day)
    				{
    					case 1:
    						printf("The %d th day is Sunday\n",num);
    						break;
    					case 2:
    						printf("The %d th day is Monday\n",num);
    						break;
    					case 3:
    						printf("The %d th day is Tuesday\n",num);
    						break;
    					case 4:
    						printf("The %d th day is Wednesday\n",num);
    						break;
    					case 5:
    						printf("The %d th day is Thursday\n",num);
    						break;
    					case 6:
    						printf("The %d th day is Friday\n",num);
    						break;
    					case 0:
    						printf("The %d th day is Saturday\n",num);
    						break;
    				
    				}
    				printf("\n");
    			}
    			else
    				printf("Error: Invalid Input first day should be > 0 and <= 7\n"); // option is invalid it printed
    		}
    		
    		
    		else if (num <= 0 || num > 365)    // if given day is invalid it executes
    			printf("Error: Invalid Input, n value should be > 0 and <= 365\n");	
    							
    		printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);

	}  while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion	
	
	return 0;
}			
