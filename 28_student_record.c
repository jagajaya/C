/********************************************
NAME		: Jagajeevan.S
DATE		: 08.08.2021
DESCRIPTION	: To implement the student record using array of structures
INPUT & OUTPUT	: 

Enter the no.of students : 2
Enter the no.of subjects : 2
Enter the name of the subject 1 : Maths
Enter the name of the subject 2 : Science
 --------------- Enter student details -------------
Enter the sutdent Roll no : 1
Enter the student 1 name : Nandhu
Enter the Maths mark : 99
Enter the Science mark : 91
 --------------- Enter student details -------------
Enter the sutdent Roll no : 2
Enter the student 2 name : Bindhu
Enter the Maths mark : 88
Enter the Science mark : 78
----- Display menu -----
1. All student details
2. Particular student details
Enter your choice : 2
-----Menu for particular student-----
1. Name
2. Roll no
Enter your choice: 1
Enter the name of the student : Nandhu
Roll No	Name		Maths		Science	Average	Grade
1		Nandhu		99		91		95		A
Do you want to continue to display(y/Y) : n
Do you want to continue (y/Y) : n

*********************************************/
// To implement the student record using array of structures

#include<stdio.h>
#include <stdlib.h>

int my_strcmp( char *str1, char *str2);
char grade(float avg);

struct student		/*structure definition*/
{
	int roll_no;
	char name[30];
	int *mark;
	
};

int main()
{
	char ch,choose;
	do
	{
		int total_stu, total_sub;
		int option,choice;
		float sum = 0, avg;	// variable declaration
		int count = 0;
		printf("Enter the no.of students : ");
		scanf("%d",&total_stu);
		printf("Enter the no.of subjects : ");
		scanf("%d",&total_sub);			// reading inputs from user subjects & stdents
		
		char (*str)[20];
		str = malloc ( sizeof(*str) * total_sub);	// Dynamic memory allocation for subject name
	
		struct student  s[total_stu];		// structure variable declaration
			
		for(int i=0; i < total_sub; i++)
		{
			printf("Enter the name of the subject %d : ",i+1);
			scanf("%s",str[i]);		// read subjects from user
		}
		
		for (int i=0; i < total_stu; i++)	// read student details from user 
		{
			printf(" --------------- Enter student details -------------\n");
			printf("Enter the sutdent Roll no : ");
			scanf("%d",&s[i].roll_no);
			
			printf("Enter the student %d name : ",i+1);
			scanf("%s",s[i].name);
			
			s[i].mark = malloc ( sizeof(int) * total_sub);
			for(int j=0; j < total_sub; j++)
			{ 
				printf("Enter the %s mark : ",str[j]);
				scanf("%d",&s[i].mark[j]);
			}
		}
		
			
		do
		{
			printf("----- Display menu -----\n1. All student details\n2. Particular student details\nEnter your choice : ");
			scanf("%d",&option);
			avg = 0;
			count = 0;
	
			switch (option)
			{
				case 1:		/*Displaying all student details*/
				{
					printf("Roll No\t\tName\t\t");
					for(int j=0; j < total_sub; j++)
						printf("%s\t\t", str[j]);
		
					printf("Average\t\tGrade\n");
				
					for (int i=0; i < total_stu; i++)
					{
						sum = 0;
						for(int j=0; j < total_sub; j++)
							sum = sum + s[i].mark[j];
					
						printf("%d\t\t%s\t\t",s[i].roll_no, s[i].name);
						
						for(int j=0; j < total_sub; j++) 
							printf("%d\t\t",s[i].mark[j] );
					
						avg = sum / total_sub;
						
						printf("%g\t\t%c\n",avg,grade(avg));
					}
					break;
				}
				case 2:	/* Displaying particular student details */
				{
					printf("-----Menu for particular student-----\n1. Name\n2. Roll no\nEnter your choice: ");
					scanf("%d",&choice);
					
					if (choice == 1)		// if user wants to print details using name
					{
						char stu_name[40];
						printf("Enter the name of the student : ");
						scanf("%s",stu_name);
						sum = 0;
						for (int i=0; i < total_stu; i++)
						{
							if ( my_strcmp ( s[i].name, stu_name) == 0)
							{
								printf("Roll No\t\tName\t\t");
								for(int j=0; j < total_sub; j++)
								{ 
									printf("%s\t\t", str[j]);
									sum = sum + s[i].mark[j];
								}
								printf("Average\t\tGrade\n");
								printf("%d\t\t%s\t\t",s[i].roll_no, s[i].name);
								for(int j=0; j < total_sub; j++)
								{ 
									printf("%d\t\t",s[i].mark[j] );
								}
								avg = sum / total_sub;
								
								printf("%g\t\t%c\n",avg,grade(avg));
								count++;
							}
						}
						if ( count == 0 )		// if entered student name is not available means it executes
							printf("Please mention correct student name\n");		
					}
					else if ( choice == 2)		// if user wants to print details using roll no
					{
						int number;
						printf("Enter the number of the student : ");
						scanf("%d",&number);
						sum = 0;
						for (int i=0; i < total_stu; i++)
						{
							if ( number == s[i].roll_no )
							{
								printf("Roll No\t\tName\t\t");
								for(int j=0; j < total_sub; j++)
								{ 
									printf("%s\t\t", str[j]);
									sum = sum + s[i].mark[j];
								}
								printf("Average\t\tGrade\n");
								printf("%d\t\t%s\t\t",s[i].roll_no, s[i].name);
								for(int j=0; j < total_sub; j++)
								{ 
									printf("%d\t\t",s[i].mark[j] );
								}
								avg = sum / total_sub;
								
								printf("%g\t\t%c\n",avg,grade(avg));
								count++;
							}
						}
						if ( count == 0 )		// if entered student roll no is not available means it executes
							printf("Please mention correct student roll no\n");
					}
					else
						printf("Enter valid option\n");
					break;
				}
				default :
					printf("Enter valid option\n");
			}
			printf("Do you want to continue to display(y/Y) : "); // asks the user to continue or not
			scanf(" %c",&choose);	
		
		}while (choose == 'Y' || choose == 'y');  	// condition checking for repetetion		

		
		free(str);
		str = NULL;
		printf("Do you want to continue (y/Y) : "); // asks the user to continue or not
		scanf(" %c",&ch);
				
		
	}while (ch == 'Y' || ch == 'y');  	// condition checking for repetetion		

	return 0;	
		
}
/*string compare function for finding student name  
and entered name is matched or not irrespective of 
lower or upper case */

int my_strcmp( char *str1, char *str2)
{
	// Compares character treats uppercase and lower case as same
	while ( ( *str1 && *str2 ) && ( *str1 == *str2 ) || ( *str1 - 32 == *str2) || (*str2 - 32 == *str1) ) 
	{
		str1++;
		str2++;	
	}
		return *str1 - *str2;
}

char grade(float avg)		// function to find grade respective to avg 
{
	if ( avg >= 90 )
		return 'A';
	else if (avg >= 80 && avg < 90)
		return 'B';
	else if (avg >= 70 && avg < 80)
		return 'C';
	else if (avg >= 60 && avg < 70)
		return 'D';
	else if (avg >= 50 && avg < 60)
		return 'E';
	else
		return 'F';
}
	
