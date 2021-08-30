/********************************************
NAME		: Jagajeevan.S
DATE		: 29.07.2021
DESCRIPTION	: To implement my_scanf() function
INPUT & OUTPUT	:

Enter a number : 20
You entered 20
Enter a character : a
You entered a
Enter a string : Hii 
You entered Hii
Enter float number : 12.45
You entered 12.45
Enter double number : 2.555555555555  
You entered 2.5556

Do you want to continue (y/Y) : n

*********************************************/
// To implement my_scanf() function

#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<stdio_ext.h>

void my_scanf(const char *format, ...);
void my_int(int *iptr);

int my_atoi(char *str);
//float my_float(char *);

int main()
{
	char ch;
	do
	{
		int num;
		char c;
		char str[100];
		float f;
		double d;		// variable declaratin
	
		printf("Enter a number : ");
		my_scanf("%d",&num);			// my_scanf() func call to read inputs (int)
		printf("You entered %d\n",num);
		
		printf("Enter a character : ");
		my_scanf("%c",&c);			// my_scanf() func call to read inputs (char)
		printf("You entered %c\n",c);
		
		printf("Enter a string : ");
		my_scanf("%s",str);			// my_scanf() func call to read inputs (string)
		printf("You entered %s\n",str);
		
		printf("Enter float number : ");
		my_scanf("%f",&f);			// my_scanf() func call to read inputs (float)
		printf("You entered %g\n",f);
		
		printf("Enter double number : ");
		my_scanf("%lf",&d);			// my_scanf() func call to read inputs (double)
		printf("You entered %g\n",d);
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		my_scanf(" %c",&ch);
	
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}
void my_scanf(const char *format, ...)
{
	va_list ap;		// ap is the argument pointer variable
	
	int *num;
	char *c_str;
	char *str;
	float *f_ptr;
	char fl_str[100];
	double *d_ptr;
	char d_str[100];
	
	va_start (ap, format);		// arg pinter variable ap points 1st argument
	
	while(*format)
	{
		if ( *format == '%')
		{
			format++;
			switch(*format)
			{
				case 'd':
					__fpurge(stdin);		// clearing input buffer
					
					num = va_arg(ap,int *);	// arg pinter variable ap points next argument
					my_int(num);
					//fscanf(stdin,"%d",i_ptr);	// read input
					
					format++;
					break;
				case 'f':
					__fpurge(stdin);
					
					f_ptr = va_arg(ap, float *);
					fgets(fl_str,100,stdin);
					*f_ptr = atof(fl_str);
					//fscanf(stdin,"%f",f_ptr);
					//*f_ptr = my_float(fl_str);
					format++;
					break;
				case 'l':
					format++;
					
					__fpurge(stdin);
					
					d_ptr = va_arg(ap,double *);
					
					fgets(d_str,100,stdin);
					//fscanf(stdin,"%lf",d_ptr);
					*d_ptr = atof(d_str);
					//*d_ptr = my_float(d_str);
					format++;
					break;
				case 's':
				{
					int i;
					__fpurge(stdin);
					
					str = va_arg(ap,char *);
					
					//fscanf(stdin,"%s",str);
					fgets(str,100,stdin);
					for (i =0; str[i] != EOF ; i++);
					i--;
					str[--i] = '\0';
					format++;
					break;
				}
				case 'c':
					__fpurge(stdin);
					
					c_str = va_arg(ap,char *);
					
					*c_str = getchar( );
					
					format++;
					break;
			}
		}
		else
			format++;	// othewise increment pointer address
	}
	va_end (ap); 	// ends the ap usage
}

void my_int(int *iptr)
{
    char str[100];
    char ch;
    
    int i;
    
    ch = getchar();
    
    for (i = 0; ((ch != ' ') && (ch != '\t') && (ch != '\n')) ; i++)	// checks any space,newline,or tab  
    {
    	str[i] = ch;
        ch = getchar();
    }
    *iptr = my_atoi(str);
}

// Function for converting string to float 
/*float my_float(char *str)
{
    char temp;
    float f = 0;
    int i,j;
    float val =10;
    
    for (i = 0; ((str[i] != ' ') && (str[i] != '\t') && (str[i] != '\n') && (str[i]!= '\0') && (str[i] != '.')) ; i++);	// checks any space,newline,or tab  
 
    if(str[i] == '.')
    {	
    	str[i] = '\0';
    	f = my_atoi(str);
    	
    	for(++i; str[i] != '\0' && str[i] != '\n'; i++)
   	{	
    		//printf("1-%f\n",f);
    		f = f + ((str[i] - 48 ) * (1/val) ); 
    		val = val * 10; 
    	//printf("2-%f\n",f); 
  	  } 
    }
    return f;
}*/

// atoi func -> string to integer

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
