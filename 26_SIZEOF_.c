/********************************************
NAME		: Jagajeevan.S
DATE		: 31.07.2021
DESCRIPTION	: To define a macro and find the size of variable without using sizeof operator
INPUT & OUTPUT	: 

Size of int		: 4 bytes
Size of char		: 1 bytes
Size of float		: 4 bytes
Size of double		: 8 bytes
Size of short int	: 2 bytes
Size of long int	: 8 bytes
Size of signed int 	: 4 bytes
Size of unsigned int	: 4 bytes
Size of signed char	: 1 bytes
Size of unsigned char	: 1 bytes
Size of long double	: 16 bytes
Size of long long int	: 8 bytes
Size of unsigned short	: 2 bytes
Size of unsigned long	: 8 bytes

*********************************************/
// To define a macro and find the size of variable without using sizeof operator

#include <stdio.h>

#define SIZEOF(x)	 (char *)(&x+1) - (char *)(&x)
	
int main()
{
	int i;
	char ch;
	float f;
	double d;
	short int s_i;
	long int l_i;
	signed int sign_i;
	unsigned int unsign_i;
	signed char sign_ch;
	unsigned char unsign_ch;
	long double long_d;
	long long int long_i;
	unsigned short unsign_sh;
	unsigned long unsign_l;		// variable declaration
	
	// prints output with the help of macro 
	
	printf("Size of int		: %zu bytes\n", SIZEOF(i));  
	printf("Size of char		: %zu bytes\n", SIZEOF(ch));
    	printf("Size of float		: %zu bytes\n", SIZEOF(f));
    	printf("Size of double		: %zu bytes\n", SIZEOF(d));
    	printf("Size of short int	: %zu bytes\n", SIZEOF(s_i));
    	printf("Size of long int	: %zu bytes\n", SIZEOF(l_i));
    	printf("Size of signed int 	: %zu bytes\n", SIZEOF(sign_i));
    	printf("Size of unsigned int	: %zu bytes\n", SIZEOF(unsign_i));
    	printf("Size of signed char	: %zu bytes\n", SIZEOF(sign_ch));
    	printf("Size of unsigned char	: %zu bytes\n", SIZEOF(unsign_ch));
    	printf("Size of long double	: %zu bytes\n", SIZEOF(long_d));
    	printf("Size of long long int	: %zu bytes\n", SIZEOF(long_i));
    	printf("Size of unsigned short	: %zu bytes\n", SIZEOF(unsign_sh));
    	printf("Size of unsigned long	: %zu bytes\n", SIZEOF(unsign_l));
    
}	
