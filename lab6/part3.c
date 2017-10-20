#include <stdlib.h>
#include <string.h>   
#include <stdio.h>  

 struct Stack
{
    struct Node *top;//tail;
    struct Node *bottom;//head;
    
};

struct Node
{
    int n;
    struct Node *next;
    struct Node *ahead;
};

void push (struct Stack * stack, int a)
{
    struct Node *temp=malloc(sizeof(struct Node));
    temp->n=a;
    temp->next=NULL;
    if(stack->top==NULL)
    {
        temp->ahead=NULL;
        stack->top=temp;
        stack->bottom=temp;
    }

    else
    {
        temp->ahead=stack->top;
        stack->top->next=temp;
        stack->top=temp;
    } 
}

int pop(struct Stack * stack)
{
    if(stack->top==NULL)
    {
        printf("nothing to pop empty stack\n");
        return 0;
    }
    
    else if(stack->top==stack->bottom)
    {
        int value;
        value=stack->top->n;
        stack->top=NULL;
        stack->bottom=NULL;
        return value;
    }
    else{
        int value;
        struct Node * temp;
        value=stack->top->n;
        temp=stack->top;
        stack->top=temp->ahead;
        stack->top->next=NULL;
        return value;
    }
    
}

void print(struct Node *head)
{
    struct Node *temp;  
    temp=head; 
    printf("\n\n\nstack：\n");  
    while(temp!=NULL)  
    {  
        printf("%6d\n",temp->n);
        temp=temp->next;
    }  
    printf("end\n"); 
    //free(p); 
} 


void reverse (struct Stack *stack)
{
    int i;
    while(stack->bottom!=NULL)
    {
        i=pop(stack);
        printf("%6d\n",i);
    }

}

int main()
{
    int i,v;
    struct Stack *ha;
    struct Stack *haha;
    ha=malloc(sizeof(struct Stack));
    ha->bottom=ha->top=NULL;
    printf("in put 5 numbers\n");
    for(i=0;i<5;i++)
    {   
        scanf("%d",&v);
        push(ha,v);
    }
    print(ha->bottom);
    printf("reversed stack:\n");
    reverse(ha);
}













