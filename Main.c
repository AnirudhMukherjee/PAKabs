#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct node
{
	char name[20], location[20], destination[20];
	struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;

void enqueue()
{
	struct node * new_node;
	char n[20],l[20],d[20],ln[20];
	char s[2];
	s[0]=' ';
	printf("Enter the first and last name of the passenger:\n");
    scanf("%s%s",&n,&ln);
    strcat(n,s);
    strcat(n,ln);
	printf("Enter the pick-up location:\n");
    scanf("%s",&l);
	printf("Enter the destination:\n");
    scanf("%s",&d);
	printf("Passenger records have been stored. Have a safe trip!\n");
	new_node = (struct node *)malloc(sizeof(struct node));
	strcpy(new_node->name,n);
	strcpy(new_node->location,l);
	strcpy(new_node->destination,d);
	if(front == NULL)
	{
	front = new_node;
	rear = new_node;
	}
	else
	{
	rear->next = new_node;
	rear = new_node;
	}
}
void dequeue()
{
	int num;
	struct node * temp;
	if(front == NULL)
	{
	printf("You have no passengers to drop-off.\n");
	}
	else
	{
	temp = front;
	front = front->next;
	free(temp);
	printf("Passenger has been dropped off!\n");
	}
}
void peek()
{
	if(front == NULL)
	{
	printf("There are no passengers remaining.\n");}
	else
	{
	printf("Current passenger details are:\nName: %s\nPick-up location: %s\nDestination: %s\n",front->name,front->location,front->destination);}
}
void display()
{
	struct node * p;
	p = front;
	if(front == NULL)
	{printf("There are no passengers remaining.\n");}
	else
	{	printf("List of remaining passengers:\n|%*s|%*s|%*s|\n", 20, "Name", 20, "Location", 20, "Destination");
		while(p!=NULL)
		{printf("|%*s|%*s|%*s|\n",20,p->name,20,p->location,20,p->destination);
		p = p->next;
		}
	}
}

void main()
{
	int option;
	do{
		printf("\nWelcome to PAKab's taxi services. Please make a choice:\n1.Add passenger for pick-up\n2.Drop off current passenger\n3.View details of current passenger\n4.Display all the pending trips\n5.Exit\nEnter option\n");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
		enqueue();
		break;
		case 2:
		dequeue();
		break;
		case 3:
		peek();
		break;
		case 4:
		display();
		break;
		}
	}while(option!=5);
}
