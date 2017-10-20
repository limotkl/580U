#include <stdlib.h>
#include <string.h>   
#include <stdio.h>  

 struct Queue
{
    struct Node *tail;//tail;
    struct Node *head;//head;
    
};

struct Node
{
    int n;
    struct Node *next;
    struct Node *ahead;
};

void enqueue (struct Queue * queue, int a)
{
    struct Node *temp=malloc(sizeof(struct Node));
    temp->n=a;
    temp->next=NULL;
    if(queue->tail==NULL)
    {
        temp->ahead=NULL;
        queue->tail=temp;
        queue->head=temp;
    }
    else
    {
        temp->ahead=queue->tail;
        queue->tail->next=temp;
        queue->tail=temp;
    } 
}

int dequeue(struct Queue * queue)
{
    
    if(queue->head!=NULL)
    {
        int value;
        value=queue->head->n;
        queue->head=queue->head->next;
        return value;
    }

    else{
        printf("queue is empty\n");
        return 0;
    }

}


void print(struct Node *head)
{
    struct Node *temp;  
    temp=head; 
    printf("\n\n\nqueue：\n");  
    while(temp!=NULL)  
    {  
        printf("%6d\n",temp->n);
        temp=temp->next;
    }  
    printf("queue end.\n\n"); 
    //free(p); 
} 

int main()
{
    int i,v;
    struct Queue *ha;
    ha=malloc(sizeof(struct Queue));
    ha->head=ha->tail=NULL;
    printf("in out 5 numbers\n");
    for(i=0;i<5;i++)
    {   
        scanf("%d",&v);
        enqueue(ha,v);
    }
    print(ha->head);
    printf("begin dequeue:\n");
    while(ha->head!=NULL)
    {
        i=dequeue(ha);
        printf("dequeue:%6d\n",i);
    }

}













