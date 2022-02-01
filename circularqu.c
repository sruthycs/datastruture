
#include<stdio.h>
struct node
{
int data;
struct node *next;
};struct node *front=NULL,*rear=NULL;
void main()
{
int choice;
while(1)
{
printf("********MENU********\n");
printf("1.insertion at end or enqueue\n");
printf("2.deletion at begining or dequeue\n");
printf("3.display");
printf("4.search");
printf("5.exit");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();
       break;
case 2:dequeue();
       break;
case 3:display();
       break;
case 4:search();
       break;
case 5:exit(0);
       break;
default:printf("invalid choice");
}
}
}
void enqueue()
{
struct node *newnode,*rear=front;
int item;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the item\n");
scanf("%d",&item);
newnode->data=item;
if(front==NULL)
{

 front=newnode;
    newnode->next=front;

}
else
{
    while(rear->next!=front)
    {

    rear=rear->next;
    }
rear->next=newnode;
newnode->next=front;
printf("new node inserted at end\n");
}
}
void dequeue()
{
struct node *rear=front,*temp1=front;
if(front==NULL)
printf("list is empty");
else
{
while(rear->next!=front)
    {

    rear=rear->next;
    }
front=front->next;
rear->next=front;
free(temp1);
printf("first node is deleted");
}
}
void search()
{ int value,count=0;
struct node *temp=front;
    printf("enter the value to be searched");
    scanf("%d",&value);
    while(temp->next!=front)
    {
    if(temp->data==value)
    {

        count++;
    }

    temp=temp->next;
    }
    if(count!=0)
    {

        printf("element found in the linked list");
    }
    else{
        printf("element not found in the linked list");
    }

}
void display()
{

    struct node *rear=front;
    while(rear->next!=front)
        {

            printf("%&d",rear->data);
            rear=rear->next;
        }
        printf("%&d",rear->data);
    }
