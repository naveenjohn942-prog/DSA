#include<stdio.h>
#include<stdlib.h>
struct linkedlist
{
	int data ;
	struct linkedlist * link;
};
void create (struct linkedlist*);
void display( struct linkedlist *);
main()
{
	int ch;
	char c;
	struct linkedlist * head=NULL;
	do 
	{
	
	printf("program to demonstarate Linkedlist creation and display\n 1. CREATION \n 2. Display \n enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: 
		if (head==NULL)
		{
			head=(struct linkedlist *)malloc (sizeof(struct linkedlist));
			create (head);
	    }
		else
		printf("List is already created\n");
		break;
		case 2:
		if (head==NULL)
		printf("list is empty\n");
		else
		display (head);	
	}
	printf(" do you want to continue(y/n)\n");
	c=getch();
}while(c=='y');
}
void create(struct linkedlist*ptr)
{
	char c;
	printf("enter data \n");
	scanf("%d", &ptr->data);
	printf("do you want to add more nodes(y/n)\n");
	c=getch();
	if (c=='y')
	{
		ptr->link=(struct linkedlist *) malloc (sizeof(struct linkedlist));
		create(ptr->link);
	}
	else
	ptr->link=NULL;
}
void display(struct linkedlist*ptr)
{
	while (ptr!=NULL)
	{
		printf("%d ---->", ptr->data);
		ptr=ptr->link;
	}
	printf("NULL\n");
}