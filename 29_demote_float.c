/********************************************
NAME		: Jagajeevan.S
DATE		: 11.08.2021
DESCRIPTION	: To demote the type of given float number to integer
INPUT & OUTPUT	: 

Enter any float number : 23.76
Demoted value is 23.000000

Do you want to continue (y/Y) : y

Enter any float number : -3.76
Demoted value is -3.000000

Do you want to continue (y/Y) : y

Enter any float number : 0.76
Demoted value is 0.000000

Do you want to continue (y/Y) : y

Enter any float number : -0.999999
Demoted value is 0.000000

Do you want to continue (y/Y) : y

Enter any float number : 1.76
Demoted value is 1.000000

Do you want to continue (y/Y) : n

*********************************************/
// To demote the type of given float number to integer

#include<stdio.h>

union float_value
{
	float num;
	struct 
	{
		unsigned mantissa : 23;
		unsigned exponent : 8;
		unsigned sign : 1;
	}bits;
}f; // union variable 

int main()
{
	char ch;
	do
	{
		int n_bits;	// variable 
		
		printf("\nEnter any float number : ");	// read float number from user
		scanf("%f",&f.num);
		
		n_bits = f.bits.exponent - 127;	// finding diff b/w exponent amd IEEE 754 standard bias number (float) 127 and store it in n_bits
		  
		if ( n_bits <= 0 && f.num > -1 && f.num < 1)	// if n_bits is  <= 0 and f.num > -1 (i.e, f.num < 0 and f.num > -1)it executes
			f.num = 0;
		else
		{   
			/*finding integer value from float value according to the sign bit value 
			  using bitfields & bitwise operators then 
		  	  store that value in float number i.e f.num*/
		  	  
			if (f.bits.sign == 1 )
				f.num = - ((1 << n_bits) | (f.bits.mantissa >> (23 - n_bits)) );  
			else
				f.num = ((1 << n_bits) | (f.bits.mantissa >> (23 - n_bits)) ); 
		}
				
		printf("Demoted value is %f\n",f.num);		// prints output
		
		printf("\nDo you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
	
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		
	
	return 0;
}

/*
 sign value is ->	printf("Sign : %d \nexponent : ",f.bits.sign & 1);
		
exponent is ->		for (int i = 7; i >= 0 ; i--)
				printf("%d ",(f.bits.exponent >> i) & 1 );
		
exponent dec value -> 	printf("\nExp decimal value is %d\n",f.bits.exponent);
		
			printf("Mantissa : ");
mantissa is ->		for (int i = 22; i >= 0 ; i--)
				printf("%d ",(f.bits.mantissa >> i) & 1 );
*/
