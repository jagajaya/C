/********************************************
NAME		: Jagajeevan.S
DATE		: 02.07.2021
DESCRIPTION	: To implement the solution for tower of hanoi
INPUT & OUTPUT	:

Enter the number of disk N : 4

Move disk 1 from tower A to tower B
Move disk 2 from tower A to tower C
Move disk 1 from tower B to tower C
Move disk 3 from tower A to tower B
Move disk 1 from tower C to tower A
Move disk 2 from tower C to tower B
Move disk 1 from tower A to tower B
Move disk 4 from tower A to tower C
Move disk 1 from tower B to tower C
Move disk 2 from tower B to tower A
Move disk 1 from tower C to tower A
Move disk 3 from tower B to tower C
Move disk 1 from tower A to tower B
Move disk 2 from tower A to tower C
Move disk 1 from tower B to tower C

Do you want to continue (y/Y) : y
Enter the number of disk N : -3

Enter only positive values

Do you want to continue (y/Y) : n

*********************************************/
//To implement the solution for tower of hanoi

#include<stdio.h>
void tower(int, char, char, char );

int main()
{
	//variable declaration
	int num;
	char tower_1 = 'A', tower_2 = 'B', tower_3 = 'C' , ch;
	
	do
	{
		printf("Enter the number of disk N : ");	// read num from user
		scanf("%d",&num);
		
		if ( num <= 0 )	// checks num is not positive value or not
		{
			printf("Enter only positive values\n");
			goto ask;
		}
		
		tower(num,tower_1,tower_2,tower_3);
		
		ask:
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}

void tower(int num, char tower_1, char tower_2, char tower_3)
{
	if(num > 0)
	{
		tower(num-1, tower_1, tower_3, tower_2);	// recursion call (tower 1 to tower 2)
		
		printf("Move disk %d from tower %c to tower %c\n",num,tower_1,tower_3);	// print the changes
		
		tower(num-1, tower_2, tower_1, tower_3);	// recursion call (tower 2 to tower 3)
	}
}
