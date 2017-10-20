#include <stdlib.h>
#include <string.h>   
#include <stdio.h>  
#include <time.h>
 struct List
{
    struct Node *head;
    
};

struct Node
{
    int n;
    struct Node *next;
    struct Node *ahead;
};
struct Node* createListB(int num)
{
    struct Node *temp,*p,*head;
    head=temp=malloc(sizeof(struct Node));

    temp->n=rand() % 101;
    printf("number in the list :%d\n", temp->n);
    // printf("input the value of node:");
    // scanf("%d",&temp->n);
    head=temp;
    head->ahead=NULL;
    p=head;
    int  i;
    for(i=1;i<num;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));

        temp->n=rand() % 101;
        printf("number in the list :%d\n", temp->n);
        // printf("input the value of node:");
        // scanf("%d",&temp->n);
        p->next  = temp;
        temp->ahead = p;
        p =temp;
    }
    temp->next = NULL;
    return head;
}
struct Node* searchTail(struct Node *head)
{
    struct Node* tail;
    tail=malloc(sizeof(struct Node));
    struct Node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    tail=temp->ahead;
    return tail;
}
int searchForward(struct Node *head,int n)
{
    struct Node *temp;  
    temp=head; 
    int step;
    step=0;
    printf("\n\n\nsearch for %d：\n",n);  
    while(temp!=NULL)  
    {  
        step++;
        if(temp->n==n)
        {
            printf("find the value\n"); 
            return step;
        }
        temp=temp->next;
    }  
    //printf("try %d\n",temp->ahead->n );
    printf("can't find the value");
    return 0;
    //free(p); 
}


int searchBackward(struct Node *tail,int n)
{
      struct Node *temp;  
    temp=tail; 
    int step;
    step=0;
    printf("\n\n\nsearch for %d：\n",n);  
    while(temp!=NULL)  
    {  
        step++;
        if(temp->n==n)
        {
            printf("fint the value\n"); 
            return step+1;
        }
        temp=temp->ahead;
    }  
    //printf("try %d\n",temp->ahead->n );
    printf("can't find the value");
    return 0;
    //free(p); 

}


void print(struct Node *head)
{
    struct Node *temp;  
    temp=head; 
    printf("\n\n\ntrain：\n");  
    while(temp!=NULL)  
    {  
        printf("%6d\n",temp->n);
        temp=temp->next;
    }  
    //printf("try %d\n",temp->ahead->n );
    printf("end\n"); 
    //free(p); 
} 

int main()
{
    
    //part2B();
    int num;
    int find;
    printf("in put the number of the List\n");
    scanf("%d",&num);
    struct List *list;
    list=malloc(sizeof(struct List));
    list->head=malloc(sizeof(struct Node));
    list->head=NULL;
    list->head=createListB(num);
    print(list->head);
    struct Node *tail;
    tail=searchTail(list->head);
    //printf("tail:%d\n", tail->next->n);
    printf("input the number you want to find\n");
    scanf("%d",&find);
    int stepforward;
    stepforward=searchForward(list->head,find);
    printf("step number forward:%d\n",stepforward);
    int stepbackward;
    stepbackward=searchBackward(tail,find);
    printf("step number backward:%d\n",stepbackward);
    
}













