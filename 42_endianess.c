/********************************************
NAME		: Jagajeevan.S
DATE		: 22.06.2021
DESCRIPTION	: To check the endianess of system
INPUT & OUTPUT	:

Enter any number : 255555555555555555555
Little Endian

Do you want to continue (y/Y) : y
Enter any number : 0
Little Endian

Do you want to continue (y/Y) : n

*********************************************/
//To check the endianess of system
#include<stdio.h>

int main()
{
	char ch;
	do
	{
		unsigned int num;		// Variable declaration as unsigned lo access large numbers too.
		unsigned int sol,mask=0xFF;
		unsigned char *cptr = (char *)&num;
		
		printf("Enter any number : ");	// Read a number from user
		scanf(" %x",&num);

		sol=num & mask;	// least significant byte value is stored in sol
		
		*cptr == sol ? printf("Little Endian\n") : printf("Big Endian\n");	// comparing *cptr with sol ....
			
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
