
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next,*prev;
};
struct node* head;
void main()
{
int choice=0;
printf("********MENU DRIVEN********\n");
printf("1.insertion at begining\n");
printf("2.insertion at end\n");
printf("3.insertion at specific position\n");
printf("4.deletion at begining\n");
printf("5.deletion at end\n");
printf("6.deletion at specific position\n");
printf("7.display");
while(1)
{
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:beginsert();
       break;
case 2:endinsert();
       break;
case 3:specinsert();
       break;
case 4:begdelete();
       break;
case 5:enddelete();
       break;
case 6:specdelete();
       break;
case 7:display();
       break;
case 8:exit(0);
       break;
default:printf("invalid choice");
}
}
}
void beginsert()
{
    struct node* newnode;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nenter the item to be inserted");
    scanf("%d",&item);
    newnode->data=item;
    newnode->prev=NULL;
    newnode->next=head;
    head=newnode;
    printf("\nelement inserted at begining");
}
void endinsert()
{
struct node*newnode,*temp;
int item;
newnode=(struct node*)malloc(sizeof(struct node*));
if(newnode==NULL)
printf("overflow\n");
else
{
printf("\nenter the item to be inserted\n");
scanf("%d",&item);
newnode->data=item;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
printf("\nnode is inserted\n");
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next = newnode;
newnode ->prev=temp;
newnode->next = NULL;
printf("node inserted at the end\n");
}}

}
void specinsert()
{
int pos,item;
struct node*newnode,*temp=head;
newnode=(struct node*)malloc(sizeof(struct node*));
if(newnode==NULL)
printf("overflow\n");
else
{
printf("enter the item\n");
scanf("%d",&item);
newnode->data=item;
printf("enter the location");
scanf("%d",&pos);
for(int i=1;i<pos-1;i++)
temp=temp->next;

newnode->next=temp->next;
newnode->prev=temp;
temp->next=newnode;
printf("node inserted");
}
}
void begdelete()
{
struct node*temp;
if(head==NULL)
printf("list is empty");
if(head->next==NULL)
{
head=NULL;
free(head);
printf("node is deleted");
}
else
{
temp=head;
head=head->next;
head->prev=NULL;
free(temp);
printf("begining node is deleted");
}
}
void enddelete()
{
struct node*temp;
if(head==NULL)
printf("list is empty");
temp = head;
        while(temp->next->next!= NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next=NULL;
printf("end node is deleted");
}
void specdelete()
{
int pos;
struct node *newnode,*temp=head;
newnode=(struct node*)malloc(sizeof(struct node*));
if(newnode==NULL)
printf("overflow\n");
else
{
printf("enter the location");
scanf("%d",&pos);
for(int i=1;i<pos;i++)
{
newnode=temp;
temp=temp->next;
}
newnode->next=temp->next;
free(temp);
newnode=temp->next;
newnode=temp->prev;

temp->next=newnode;
printf("node deleted");
}
}
void display()
{

    struct node *temp;
    temp=head;
    if(temp==NULL)
    {


        printf("nothing to print");
    }
    else
    {

        printf("printing values\n");
        while(temp!=NULL)
        {

            printf("%3d",temp->data);
            temp=temp->next;
        }
    }
}
