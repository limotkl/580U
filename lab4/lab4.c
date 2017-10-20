#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numTest 4

typedef struct Team
{
    char *name;
    int score;
    int win;
    int handicap;
}Team;
//==========================================part2A
struct Team *game(struct Team *x,struct Team *y){
    srand(rand()%100);
    x->score=rand()%100-(x->handicap);
    y->score=rand()%100-(x->handicap);
    if(x->score<0)
        x->score=0;
    if(y->score<0)
        y->score=0;
    if(x->score>y->score)
    {
        x->win=1;
        y->win=0;
        printf("winner: %s\n%s\t%d\n%s\t%d\n",x->name,x->name, x->score,y->name,y->score);
        return x;
    }
    else if (x->score<y->score)
    {
        y->win=1;
        x->win=0;
        printf("winner: %s\n%s\t%d\n%s\t%d\n",y->name,y->name, y->score,x->name,x->score);
        return y;
    }
    else
    {
        y->win=0;
        x->win=0;
        printf("no winner");
    }
            return 0;
}
//===========================================part2B
struct Team *tournament(struct Team *x[]){
    int i;
    struct Team *win[4];
    struct Team *win1[2];
    struct Team *win0;
    printf("========round 1========\n");
    for(i=0;i<=3;i++)
    {
        win[i]=game(x[i],x[7-i]);
    }
    printf("========round 2========\n\n");
    for(i=0;i<=1;i++)
    {
        win1[i]=game(win[i],win[3-i]);
    }
    printf("========round 3========\n\n");
    win0=game(win1[0],win1[1]);
    return win0;
    
}
//===========================================part1;
int myStrStr (char haystack[], char needle[], char buffer[]){
    
    int h=0;
    int k=0;
    int j=0;//
    int buf;
    while(h<strlen(haystack)&&j<strlen(needle))
    {
        if(haystack[h]==needle[j])
        {
            h++;
            j++;
        }
        else
        {
            j=0;k++;
            h=k;
        }
    }
    
    if(j==strlen(needle))
    {
        buffer[strlen(needle)]='\0';
        h=h-1;
        for(buf=(int)(strlen(needle)-1);buf>=0;buf--)
        {
            buffer[buf]=haystack[h];
            h--;
        }
        printf("find the string :%s\n",buffer);
        return 1;
    }
    else
    {
        printf("can't find the string\n");
        return 0;
    }
    
}

int main(int argc, const char * argv[]) {
    int i;
    char *haystack[50]={"apple","orange","blueberry","strawberry","grapefruit"};
    char *needle[50]={"app","ge","ueber","strawberry","terrible"};
    printf("=======================part1\n");
    for(i=0;i<=4;i++)
    {
        char buffer[(int)strlen(needle[i])];
        myStrStr (haystack[i], needle[i], buffer);
    }
    printf("=======================part2A\n");
    Team xman[7];
    xman[0].name="A";
    xman[0].score=0;
    xman[0].win=0;
    xman[0].handicap=10;
    
    xman[1].name="B";
    xman[1].score=0;
    xman[1].win=0;
    xman[1].handicap=30;
    
    xman[2].name="C";
    xman[2].score=0;
    xman[2].win=0;
    xman[2].handicap=15;
    
    xman[3].name="D";
    xman[3].score=0;
    xman[3].win=0;
    xman[3].handicap=8;
    
    xman[4].name="E";
    xman[4].score=0;
    xman[4].win=0;
    xman[4].handicap=6;
    
    xman[5].name="F";
    xman[5].score=0;
    xman[5].win=0;
    xman[5].handicap=8;
    
    xman[6].name="G";
    xman[6].score=0;
    xman[6].win=0;
    xman[6].handicap=9;
    
    xman[7].name="H";
    xman[7].score=0;
    xman[7].win=0;
    xman[7].handicap=20;
    struct Team *league[7];
    for(i=0;i<=7;i++)
    {
        league[i]=&xman[i];
    }
    for(i=0;i<=3;i++)
    {
      
        game(league[i],league[7-i]);
        //printf("%d,%d\n",league[i]->win,league[7-i]->win);
    }
    printf("=======================part2B\n");
    tournament(league);
    
    return 0;
}


