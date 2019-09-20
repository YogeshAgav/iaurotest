#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
				int data;
				struct node *next;
};
void modifyEvenOdd(struct node*,struct node*,struct node*);
void display(struct node*);
void sort(struct node *);
int main()
{
				struct node *head=NULL,*iterator=NULL,*even=NULL,*odd=NULL;
				int no=0;
				int temp=0;
				int i=0;
				printf("\nEnter no of element you want to accept:");
				scanf("%d",&no);
				while(i<no)
				{
								if(head==NULL)
								{
												head=(struct node *)malloc(sizeof(struct node));
												printf("\nEnter a data:");
												scanf("%d",&temp);
												head->data =temp;
												head->next = NULL;

								}
								else
								{
												iterator=head;
												while(iterator->next != NULL)
												{		
																iterator = iterator->next;

												}
												iterator->next =(struct node *)malloc(sizeof(struct node));
												printf("\nEnter a data:");
												scanf("%d",&temp);
								
												iterator=iterator->next;
												iterator->data= temp;
												iterator->next = NULL;
								}
								i++;
				}
				printf("\nBefore sortng:");
				display(head);
				modifyEvenOdd(head,even,odd);
				/*while(1)
				{
								printf("\nEnter your choice:\n1:even\n2:odd\n3:exit");
								scanf("%d",&no);
								switch(no)
								{
												case 1:
																display(even);
																break;
												case 2:
																display(head);
																break;
												case 3:exit(0);
												default:printf("\nWrong choice");
								}
				}*/
				return 0;
}
void display(struct node *iterator)
{
				//printf("\nInside dsplay");
				while(iterator!=NULL)
				{
								printf("%d\t",iterator->data);
								iterator=iterator->next;
				}
				printf("\n");
}
void modifyEvenOdd(struct node* iterator,struct node *even,struct node *odd)
{
				struct node *temp,*temp1,*head,*temp2;
				temp=iterator;
				head=iterator;
				while(iterator->next->next!=NULL)
				{
								if(iterator->data %2 != 0)
								{
												while(iterator->next->data %2 !=0 && iterator->next!=NULL)
												{
																iterator=iterator->next;
												}
												temp=iterator;
								}
								else if(iterator->data %2==0)
								{
												while(iterator->next->data %2 ==0 && iterator->next!=NULL)
												{
																iterator=iterator->next;
												}
												temp1=iterator->next->next;
												iterator->next->next = temp->next;
												temp->next =iterator->next;
												//iterator=iterator->next;
												iterator->next= temp1;
								}
								iterator=iterator->next;
				}
				iterator=head;
				while(iterator->next->next->data %2 !=0 && iterator->next!=NULL)
				{
						iterator=iterator->next;
				}
				odd=head;
				even=iterator->next->next;
				iterator->next->next=NULL;
				printf("\nodd number");
				display(odd);
				printf("\neven number");
				display(even);
}
