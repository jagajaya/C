/********************************************
NAME		: Jagajeevan.S
DATE		: 01.06.2021
DESCRIPTION	: To generate  AP, GP and HP values
INPUT & OUTPUT	: Enter First Number 'A': 2
		  Enter Comman Difference / Ratio 'R': 3
		  Enter Number of terms 'N': 5
		  AP = 2 5 8 11 14 
		  GP = 2 6 18 54 162 
		  HP = 0.500000 0.200000 0.125000 0.090909 0.071429 
		  Do you want to continue (y/Y) : N

*********************************************/
//To generate  AP, GP and HP values

#include<stdio.h>

int main()
{
	int A, R, N, check=1;
	int ap, gp;
	float hp;
	char ch;
	for (int i=1;i<=10;i++) // FINDING THE LIMITS
    	     check=check*2;
    	     
	do
	{
		
		// READ THE INPUTS FROM THE USER
		
		printf("Enter First Number 'A': ");
		scanf("%d",&A);
		printf("Enter Comman Difference / Ratio 'R': ");
		scanf("%d",&R);
		printf("Enter Number of terms 'N': ");
		scanf("%d",&N);
		
		if ( (A < check && A >= 0) &&  (R < check && R >= 0) && (N < check && N >= 0) ) // CHECK ALL INPUT IS > 0 AND < CHECK 
		{
			//ARITHMETIC PROGRESSION
			ap=A;
			printf("AP = ");
			for(int i=1;i<=N;i++)
			{
				printf("%d ",ap);
				ap=ap+R;	
			}
			
			printf("\n");
			
			//GEOMETRIC PROGRESSION
			gp=A;
			printf("GP = ");
			for(int i=1;i<=N;i++)
			{
				printf("%d ",gp);
				gp=gp*R;	
			}
			
			printf("\n");
			
			//HARMONIC PROGRESSION
			ap=A;
			hp=1/(float)ap;
			printf("HP = ");
			for(int i=1;i<=N;i++)
			{
				printf("%f ",hp);
				ap=ap+R;
				hp=1/(float)ap;	
			}
			
			printf("\n");
		}
		else if ( A > check || R > check || N > check)	// CHECKS INPUT(S) IS OUT OF RANGE OR NOT
    	            printf("Inout(s) out of range\n");
			
		else if ( A < 0 || R < 0 || N < 0)	// CHECKS ANY OF THE INPUT(S) IS < 0
    	            printf("Invalid input(s) : Please enter only positive values\n");
    	            
    	        printf("Do you want to continue (y/Y) : ");
    	        scanf(" %c",&ch);
    	      
	}  while (ch == 'Y' || ch == 'y');  	// CHECKING TO CONTINUE OR NOT
	
	return 0;
}	
