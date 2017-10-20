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

void print(struct Node *head)
{
    struct Node *temp;
    temp=head;
    printf("\nList：\n");
    while(temp!=NULL)
    {
        printf("%6d\n",temp->n);
        temp=temp->next;
    }
    printf("end\n");
    //free(p);
}

struct Node * front(struct List * list)
{

    return list->head;
}

struct Node* createNode ()
{
    struct Node *node;
    node=malloc(sizeof(struct Node));
    return node;
}

struct Node* createList(int num1)
{
    struct Node* temp;
    struct Node* head;
    //struct Node* p;
    //srand((unsigned) time(NULL));
    int i=1;
    head=malloc(sizeof(struct Node));
    // printf("put in\n");
    // scanf("%d",&head->n);
    
    head->n=rand() % 101;
    printf("number in the list :%d\n", head->n);
    head->next=NULL;
    head->ahead =NULL;
     print(head);
     temp=head;
     //p=head;
    while(i<num1)
    {
        temp->next=malloc(sizeof(struct Node));
        // printf("put in\n");
        // scanf("%d",&temp->next->n);
        temp->next->n=rand() % 101;
        printf("number in the list :%d\n", temp->next->n);
       temp->next->next=NULL;
       temp->next->ahead=temp;
       temp=temp->next;
        i++;
        print(head);
    }
    //temp->next= NULL;
    printf("END\n");
    return head;
}

struct Node* insert (struct List *list,int index, int a)
{
    int n=0;
    index--;
    struct Node*p1,*p2;
    struct Node *temp=malloc(sizeof(struct Node));
    temp->n=a;
    temp->next=NULL;
    p1=list->head;
    while(n<index)
    {
        p1=p1->next;
        n++;
    }
    if(n==index)
    {
        p2=p1->next;
        p1->next=temp;
        temp->next=p2;
    }
    return list->head;

}
int myremove (struct List *list,int index)
{
    int n=1;
    struct Node*p1,*p2;
    p1=list->head;
    while(n<index)
    {

        p1=p1->next;
        n++;
    }
    if(n==index)
    {
        p2=p1->next->next;
        p1->next=p2;
    }
    return 1;
}
void part2()
{
     int num;
    int index;
    int index1;
    struct List *list;
    list=malloc(sizeof(struct List));
    //list->head=malloc(sizeof(struct Node));
    //list->head=NULL;
    printf("input the number of the list\n");
    scanf("%d",&num);
    list->head=createList(num);
    //print(list->head);
    printf("in put the index you want to insert\n");
    scanf("%d",&index);
    if(index<=num)
    {
        insert(list,index,111);
        print(list->head);
    }
    else
        printf("out of bound\n");
    //============================
    printf("input the node index you want to delete\n");
    scanf("%d",&index1);
        if(index<=num)
    {
        myremove(list,index1);
        print(list->head);
    }
    else
        printf("out of bound\n");
    free(list);
    //free(list->head);
}
int main()
{
    part2();
}
