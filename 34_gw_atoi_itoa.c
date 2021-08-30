/********************************************
NAME		: Jagajeevan.S
DATE		: 08.07.2021
DESCRIPTION	: To implement getword, atoi, itoa functions
INPUT & OUTPUT	:

1. getword
2. atoi
3. itoa
Enter your choice:1
Enter a word	: Hello World
You entered Hello and length is 5

Do you want to continue (y/Y) : y
1. getword
2. atoi
3. itoa
Enter your choice:2
Enter a numeric string	: -12345
String to integer -12345

Do you want to continue (y/Y) : y
1. getword
2. atoi
3. itoa
Enter your choice:3
Enter a number	: 1289
Integer to string 1289

Do you want to continue (y/Y) : n

*********************************************/
//To implement getword, atoi, itoa functions

#include<stdio.h>
#include<stdio_ext.h>
int get_word (char *str);
int my_atoi (char *str);
int my_itoa (int num, char *str);

int main()
{
	char str[100],ch;
	int choice, len, num;	// variable declaration
	
	do
	{
		printf("1. getword\n2. atoi\n3. itoa\nEnter your choice:");
		scanf("%d",&choice);	// read option from user
		__fpurge (stdin);
		
		switch (choice)
		{
			case 1:
				printf("Enter a word	: ");
				scanf("%50[^\n]",str);		//read word from user
				__fpurge (stdin);
				
				len = get_word (str);	//func call
				
				printf("You entered %s and length is %d\n",str,len);
				break;
			case 2:
				printf("Enter a numeric string	: ");
				scanf("%50[^\n]",str);		//read numeric string from user
				__fpurge (stdin);
			
				len = my_atoi(str);	//func call
			
				printf("String to integer %d\n",len);
				break;
			case 3:
				printf("Enter a number	: ");
				scanf("%d",&num);		//read number from user
				__fpurge (stdin);
				//str[100];
			
				my_itoa (num, str);	//func call
			
				printf("Integer to string %s\n",str);
				break;
		}
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);	
		__fpurge(stdin);
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
//function definition

int get_word (char *str)
{
	int len = 0;
	while(*str  && ( *str != ' ' && *str != '\t' && *str != '\n'))	// TAKE WORD UPTO SPACE OR \n and calculate length
	{
		++len;
		str++;
	}
	*(str) = '\0';
	return len;	// return length of string
}

int my_atoi(char *str)
{
	int a, temp = 0, check = 0, flag_p = 0, flag_n = 0;
	
	while(*str)
	{
		if ( ( check == 0 && *str == '+' ) || ( check == 0 && *str == '-' ) )	// Checks 1st char is '+' or '-'
		{
			if( *str == '+' )
			{
				flag_p = flag_p + 1;	// flag_p count incremented
				//continue;
			}
			else if( *str == '-' )
			{
				flag_n = flag_n + 1;	// // flag_n count incremented
				//continue;
			}
		}
		else if ( *str >= '0' && *str <= '9' )	// Checks entered ch is number or not
		{
			if ( flag_p <= 1 && flag_n <= 1 )	//  char to int conversion
			{
				temp = ( temp * 10 ) + (*str - 48);
			}
		} 
		else if ( ( check == 1 && *str == '+' ) || ( check == 1 && *str == '-' ) ) // Checks 2nd char is '+' or '-', is yes it comes out of loop
			break;
		else 					// if the entered char is not number and not '+' or '-' it comes out of loop
			break;
		check++;
		str++;
		
	}
	
	 if ( flag_n == 1)	
		return -temp;	//	 returns -ve value
		
	 else if ( flag_p <= 1 && flag_n == 0 )
		return temp;	
		
	 else
	 	return temp;	
}
int my_itoa(int num,char *str)
{
	int i =0 ;
	int val;
	
	//Positive numbers
	if ( num >= 0)
	{ 
		val = num;
		while(val > 0)	// Calculating no of digits
		{
			val= val / 10;
			i++;
		}
		
		*(str+i) = '\0';	// store null in array
		
		while(num)
		{	
			*(str + (--i)) = (num % 10) + '0';	// integer to character
			num = num / 10 ;
		}	
	}
	
	//Negative numbers
	else if ( num < 0)
	{ 
		num = -num;
		val = num;
		while(val > 0)	// Calculating no of digits
		{
			val = val/10;
			i++;
		}
		
		*(str + (i+1) ) = '\0';	// store null in array	
		
		while(num)
		{	
			*(str + (i--)) = (num % 10) + '0';	// integer to character
			num = num / 10 ;
		}
		
		*(str+i) = '-';	
	}
}
