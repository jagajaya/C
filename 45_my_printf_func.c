/********************************************
NAME		: Jagajeevan.S
DATE		: 29.07.2021
DESCRIPTION	: To implement my_printf() function
INPUT & OUTPUT	:

Enter a number, char, string : 20,c,Hello
Output : 20 c Hello

Do you want to continue (y/Y) : n


*********************************************/
// To implement my_printf() function

#include<stdio.h>
#include<stdarg.h>

int my_printf(const char *, ...);
int my_itoa(int num,char *str);
int my_count(char *str);

int main()
{
	char ch;
	do
	{
		int num;
		char c;
		char str[100];		// variable declaratin
		int count;
		
		my_printf("Enter a number, char, string : ");	// my_printf() func call 
		
		scanf("%d%*c",&num);
		scanf("%c%*c",&c);
		scanf("%s",str);	// read inputs from user
		
		my_printf("Output : %d %c %s\n",num,c,str);	// my_printf() func call 
		
		my_printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		
		scanf(" %c",&ch);
	
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
int my_printf(const char *format, ...)	// variadic function
{
	va_list ap;	// ap is the argument pointer variable
	int x;
	char int_value[100];
	char *c;
	char *str;	// variable declaration
	static int count;
	int total_var;
	int ret_value = 0;
	va_start (ap, format); // arg pinter variable ap points 1st argument
	
	while(*format)
	{
		if ( *format == '%')
		{
			format++;
			// checks fromat and execute according to its specification
			
			switch(*format)
			{
				case 'd':
					x = va_arg(ap,int); // arg pinter variable ap points next argument
					
					my_itoa(x,int_value);	//calling my_itoa function
					
					ret_value = my_count(int_value);
					count = count + ret_value;			//  counting total printable characters
	
					puts(int_value,stdout); // prints output
					
					format++;
					break;
				case 'c':
					x = va_arg(ap,int);
					
					count++;
					putchar(x);	
					
					format++;
					break;
				case 's':
					str = va_arg(ap,char *);
					
					ret_value = my_count(str);
					count = count + ret_value;
					
					fputs(str,stdout);
					
					format++;
					break;
			}
		}
		else
		{
			putchar(*format);	// otherwise prints the characters 
			count++;
			format++;
		}
	}
	va_end (ap); // ends the ap usage
	total_var = count;
	count = 0;
	return total_var;	// returns successive printed characters 
	
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
int my_count(char *str)
{
	int length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return length;
}
		
