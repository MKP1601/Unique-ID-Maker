#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

struct node 
{
   int angka;
   int random;
   float nilai;
   char nama[20];
   char huruf [20];
   char angkah[5];	
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
char *huruf (float x);

void printtotext()
{
	FILE * fp;
    struct node *ptr = head;
    time_t s, val = 1; 
    struct tm* current_time; 
    
    s = time(NULL); 
    current_time = localtime(&s);
    
	fp = fopen ("c:\\temp\\1.txt","a+");
	
	while(ptr != NULL) 
	{
	fprintf(fp, "Name: %s\nUsername	: %s%s%d%02d\n\n", ptr->nama, ptr->angkah, ptr->nama, ptr->angka, current_time->tm_min);
	ptr = ptr->next;
	}
		fclose (fp);
}


void printList() 
{
	FILE *fp;
    char str[MAXCHAR];
    char* filename = "c:\\temp\\1.txt";
    
    fp = fopen(filename, "r");
    if (fp == NULL)
	{
        printf("Could not open file %s",filename);
        return main();
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
    printf("%s", str);
    fclose(fp);
    printf(" -End of Data-\n");
}

void printcurrent() 
{
	time_t s, val = 1; 
    struct tm* current_time; 
    
    s = time(NULL); 
    current_time = localtime(&s);
     
    struct node *ptr = head;
    printf("Username: %s%s%d%02d\n\n",ptr->angkah, ptr->nama, ptr->angka, current_time->tm_min);
}


void insert(int angka, char nama[20]) 
{
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->angka = angka;
   strcpy (link->nama, nama);
   strcpy (link->angkah, huruf(link->angka)); 
   link->next = head;
   head = link;
}

int main() 
{
	int b, x, choice, opt,option;
    char a[20], pass[10];
    int i;
    time_t t; 
    
    FILE *fp;
    char* filename = "c:\\temp\\1.txt";
    
    menu();
    scanf("%d", &choice);
   
    switch (choice){
   	
   	case 1:
	   srand((unsigned) time(&t));
       b = (rand() % 100); 
	   printf("\nEnter a name: ");
	   scanf (" %s", &a);
	   insert(b, a);
	   printcurrent();
	   system("pause");
	   system("cls");
	   return main();
	   
	case 2:
		goto admin;
	
	case 3:
		goto help;
				
	case 4:
		printtotext();
		printf("\n\nThank you for using Unique ID v.1");
		return 0;
		
	default:
		printf("Invalid input. Please choose one of the available options!\n");
		system("pause");
		system ("cls");
		return main();
	
	admin:
		system ("cls");
		printf("[Administrator]\n\n");
		printf("Enter the password: ");
		scanf(" %s", &pass);
			if (pass[5] = "abc123")
				{
				printf("\nList of usernames :\n\n");
				printList();
				
				printf("\n[1] Format List\n[2] Return to Main Menu\nChoice:");
				scanf("%d", &option);
					switch (option){
						case 1: 
							fp = fopen ("c:\\temp\\1.txt","w");
							printf(" ");
							fclose (fp);
							printf("\n\n---Username list has been cleared---\n\n");
							printf("Press any key to return to main menu");
							getch();
							system("cls");
							return main();
							
						case 2:
							system("cls");
							return main();		
					}				
				}
			else
			{
				printf("Password incorrect");
				return main();
			}
	help:
		system ("cls");
		printf("\n[Help]\nEnter any number you want.\nThe program will then ask you to enter your name.\nPlease enter your name without any spaces.\n\nExample: johndoe\n\n");
		printf("Enter [1] to go back to the main menu.\n");
		printf(": ");
		scanf("%d", &opt);
		if(opt==1)
		{
			system ("cls");
			return main();
		}
		else
		{
			printf("\nInvalid input. Please choose one of the available options!\n");
			system("pause");
			system ("cls");
			goto help;
		}
		
		
	system ("cls");
   }
}

char *huruf (float x){
	
	
	if(x >= 61)
	{
		return "our";
	}
	if(x <= 60 && x >= 51)
	{
		return "my";
	}
	if(x <= 50 && x >= 41)
	{
		return "mo";
	}
	if(x <= 40 && x >= 31)
	{
		return "the";
	}
	if(x <= 30 && x >= 21)
	{
		return "pop";
	}if(x <= 20 && x >= 11)
	{
		return "bob";
	}if(x <= 10 && x >=0)
	{
		return "xx";
	}
}

void menu()
	{
		printf("		============================================\n");
		printf("				Unique ID v.1\n");
		printf("		============================================\n\n\n");
		printf("			Your go to program to make that\n");
		printf("			ID that no one in the world has!\n\n");
		printf("Please choose an option below by entering its corresponding number.\n\n");
		printf("[1] Generate username\n[2] List of generated usernames (Administrator only)\n[3] Help\n[4] Exit\nYour choice: ");
	}

