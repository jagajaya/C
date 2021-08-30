/********************************************
NAME		: Jagajeevan.S
DATE		: 01.06.2021
DESCRIPTION	: To print sizes of all basic data types of c
OUTPUT		:

size of int		: 4 bytes
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
//To print sizes of all basic data types of c
#include<stdio.h>

int main()
{
    printf("Size of int		: %zu bytes\n", sizeof(int));
    printf("Size of char		: %zu bytes\n", sizeof(char));
    printf("Size of float		: %zu bytes\n", sizeof(float));
    printf("Size of double		: %zu bytes\n", sizeof(double));
    printf("Size of short int	: %zu bytes\n", sizeof(short int));
    printf("Size of long int	: %zu bytes\n", sizeof(long int));
    printf("Size of signed int 	: %zu bytes\n", sizeof(signed int));
    printf("Size of unsigned int	: %zu bytes\n", sizeof(unsigned int));
    printf("Size of signed char	: %zu bytes\n", sizeof(signed char));
    printf("Size of unsigned char	: %zu bytes\n", sizeof(unsigned char));
    printf("Size of long double	: %zu bytes\n", sizeof(long double));
    printf("Size of long long int	: %zu bytes\n", sizeof(long long int));
    printf("Size of unsigned short	: %zu bytes\n", sizeof(unsigned short));
    printf("Size of unsigned long	: %zu bytes\n", sizeof(unsigned long));
    
    return 0;
}
