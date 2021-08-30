/********************************************
NAME		: Jagajeevan.S
DATE		: 16.06.2021
DESCRIPTION	: To implement own c-type library
INPUT & OUTPUT	:

Enter the character : a
Select any option :
1 - isalpha
2 - isalnum
3 - isascii
4 - isupper
5 - islower
Enter your choice : 2
The character 'a' is an alnum character

Do you want to continue (y/Y) : Y

Enter the character : }
Select any option :
1 - isalpha
2 - isalnum
3 - isascii
4 - isupper
5 - islower
Enter your choice : 2
The character '}' is not an alnum character

Do you want to continue (y/Y) : n

*********************************************/
//To implement own c-type library

#include<stdio.h>
//Function Declarations
int alpha(char a);
int alnum(char a);
int ascii(char a);
int upper(char a);
int lower(char a);
int main()
{
	char ch, choice;	//Variable declaration
	int num,res;
	do
	{
		printf("Enter the character : ");
		scanf(" %c",&ch);			//Read character from user
		printf("Select any option :\n1 - isalpha\n2 - isalnum\n3 - isascii\n4 - isupper\n5 - islower\n");
		printf("Enter your choice : ");
		scanf(" %d",&num);			//Read choice from user
		
		switch (num)
		{
			case 1:
				res=alpha(ch); // calling alpha function
				res?printf("The character '%c' is an alpha character\n",ch):printf("The character '%c' is not an alpha character\n",ch);	//print output
				break;
			case 2:
				res=alnum(ch);	// calling alnum function
				res?printf("The character '%c' is an alnum character\n",ch): printf("The character '%c' is not an alnum character\n",ch);	//print output
				break;		
			case 3:
				res=ascii(ch);	// calling ascii function
				res?printf("The character '%c' is an ascii character\n",ch):printf("The character '%c' is not an ascii character\n",ch);	//print output
				break;
			case 4:
				res=upper(ch);	// calling upper function
				res?printf("The character '%c' is an uppercase character\n",ch):printf("The character '%c' is not an uppercase character\n",ch);	//print output
				break;
			case 5:
				res=lower(ch);	// calling lower function
				res?printf("The character '%c' is an lowercase character\n",ch):printf("The character '%c' is not an lowercase character\n",ch);	//print output
				break;
			default:
				printf("Invalid option,Please enter 1 to 5 choice only\n");
		}
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&choice);
		printf("\n");
		
	 } while (choice == 'Y' || choice == 'y');  	// condition checking for repetetion		
		
	return 0;
}
//Function Definitions (Return type is int because it returns int value 0 or 1)

int alpha(char a)
{
	return ((a>=65 && a<=90) || (a>=97 && a<=122))?1:0; // checks condition and return 1 or 0
}
int alnum(char a)
{
	return (a>=65 && a<=90) || (a>=97 && a<=122) || (a>=48 && a<=57)?1:0;  // checks condition and return 1 or 0
}
int ascii(char a)
{
	return (a>=0 && a<=127)?1:0;	// checks condition and return 1 or 0
}
int upper(char a)
{
	return (a>=65 && a<=90)?1:0;   // checks condition and return 1 or 0
}
int lower(char a)
{
	return (a>=97 && a<=122)?1:0;  // checks condition and return 1 or 0
}				
