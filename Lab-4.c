#include<stdio.h>
#include<stdlib.h>
#include "E:/mca christ/sem-2/DSA/user_calo.h"


struct userList *front  = NULL, *rear = NULL;


void enque()
{
	struct userList* ptr = (struct userList*)malloc(sizeof(struct userList));
	char c;
	
	
	ptr->data = (struct userNode*)malloc(sizeof(struct userNode));
	printf("\n\nEnter the user ID : ");
	scanf("%d",&ptr->data->id);
	fflush(stdin);
	printf("Enter the user Name : ");
	gets(ptr->data->name);
	printf("Enter the user Age : ");
	scanf("%d",&ptr->data->age);
	fflush(stdin);
	printf("Enter the user Program(weight Loss/weight gain/maintain) : ");
	gets(ptr->data->prog);
	printf("Enter how many times user workout weekly : ");
	scanf("%d",&ptr->data->exercise);
	printf("Enter the user calorie intake : ");
	scanf("%d",&ptr->data->calorie);
	ptr->link = NULL;
	if(front == NULL && rear == NULL)
	{
		front = ptr;
		rear = ptr;
	}	
	
	else
	{
		rear->link = ptr;
		rear = ptr;
	}
	printf("Add more data..(y/n) : ");
	c = getche();
	if(c == 'y')
		enque();
	else
		printf("\n\n\tQueue created!");
	
}
void deque()
{
	struct userList* temp;
	char c;
	if(front ==NULL && rear ==NULL)
	{
		printf("\n\t Queue is Empty..");
	}
	else
	{
		if(front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		temp = front;
		front = front->link;
		free(temp);
	}
	printf("\ndelete More..(y/n) : ");
	c= getche();
	if(c == 'y')
		deque();
	else
		printf("");
	}
	
	
}

void display()
{
	struct userList* ptr = front;
	if(front == NULL && rear == NULL)
	{
		printf("\n\tQueue is empty..\n\tNo Data!\n");
	}
	else
	{
		while(ptr != NULL)
		{
			printf("\n==========================\n");
			printf("\tuser ID : %d\n",ptr->data->id);
			printf("\tuser Name : %s\n",ptr->data->name);
			printf("\tuser Age : %d\n",ptr->data->age);
			printf("\tuser prog : %s\n",ptr->data->prog);
			printf("\texercise : %d\n",ptr->data->exercise);
			printf("\tuser calorie : %d\n",ptr->data->calorie);
			printf("\n==========================\n\t|\n\t|\n\t|\n\t\\/\n");
			ptr = ptr->link;
		}	
	}
	
}

void searchById()
{
	int n;
	struct userList *ptr = front;
	printf("\nEnter the ID of the user : ");
	scanf("%d",&n);
	
	while(ptr!= NULL)
	{
		if(ptr->data->id == n)
		{
			break;	
		}	
		ptr = ptr->link;
	}
	if(ptr!= NULL)
	{
			printf("\n==========================\n");
			printf("\tuser ID : %d\n",ptr->data->id);
			printf("\tuser Name : %s\n",ptr->data->name);
			printf("\tuser Age : %d\n",ptr->data->age);
			printf("\tuser prog : %s\n",ptr->data->prog);
			printf("\texercise : %d\n",ptr->data->exercise);
			printf("\tuser calorie : %d\n",ptr->data->calorie);
			printf("\n==========================\n");
	}
	else
	{
		printf("\n\t No Data Found!!\n");
	}
}


void main()
{
	
	int opt;
		
	do
	{
		printf("\n1.Add user data\n2.Display All\n3.Delete Data\n4.Search user By ID\n0.Exit\nChoose from the above : ");
		scanf("%d",&opt);
		
		switch(opt)
		{
			case 1:
				enque();
				break;
			case 2:
				display();
				break;
			case 3:
				deque();
				break;
			case 4:
				searchById();
				break;
			case 0:
				printf("\n\tTHANK YOU");
				break;
				
		}
	}while(opt!=0);
	
	
	
}