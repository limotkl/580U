#include <stdlib.h>
#include <string.h>   
#include <stdio.h>  
#include <time.h>
struct Train
{
	struct Car *head;
	
};

struct Car
{
	int weight;
	struct Car *next;
};

void print(struct Car *head)
{
    struct Car *temp;  
    struct Car *p;
    p=malloc(sizeof(struct Car));
    temp=head; 
    printf("\n\ntrain：\n");  
    while(temp!=NULL)  
    {  
        p=temp->next;
        printf("%6d\n",temp->weight);
        temp=p;
    }  
    printf("train is enpty\n"); 
    //free(p); 
    // temp=head; 
    // while(temp!=NULL)  
    // {  
    //     p=temp->next;
    //     free(temp);
    //     temp=p;
    // }  
}  

struct Car* create(int num0,struct Car *head)  
{  
    if (num0==0)
    {
        printf("It's an empty Train\n");
        return NULL;
    }
    struct Car*temp; 
    struct Car*p;
    int i=1; 
    temp=p=malloc(sizeof(struct Car)); 
    printf("put in weight\n");  
    scanf("%d",&temp->weight); 
    temp->next=NULL;
    head=temp;
    p=head;
    if(num0==1)
    {
        head=temp;
        return head;
    }

    while(i<num0)
    {    
        temp=malloc(sizeof(struct Car));  
        printf("put in weight\n");  
        scanf("%d",&temp->weight);
        p->next=temp;
        p=temp;
        i++;
    }
    temp->next= NULL;   
    free(p);
    printf("END\n");    
    return head;
} 
void part1()
{
    int num;
    printf("in put the number of the Train\n");
    scanf("%d",&num);
    struct Train *HEXIE;
    HEXIE=malloc(sizeof(struct Train));
    HEXIE->head=malloc(sizeof(struct Car));
    HEXIE->head=NULL;     
    HEXIE->head=create(num,HEXIE->head);
    print(HEXIE->head);
    free(HEXIE->head);
    free(HEXIE);
}
int main()
{
    part1();  
 
}