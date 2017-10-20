#include <stdio.h>
#include <limits.h>
#define LOOP 20

int main ()
{
        int f1,f2,re,i;
        int num[5]={2,255,32,-1,-255};
        f1=0;f2=1;
 	printf("Fibonacci sequence\n");
        printf("%d\t",f1);
        printf("%d\t",f2);
        for (i=0;i<LOOP-2;i++){
                re=f1+f2;
                f1=f2;
                f2=re;
                printf("%d\t",re);
        }
        printf("\n==============\n");
//=================================
        int n;
        int size=sizeof(int)*8;
        printf("INT TO Binary\n");
        for(i=0;i<5;i++){
                printf("%d\n",num[i]);
                for(n=size-1;n>=0;n--){
                        printf("%d",num[i]>>n&1);
                } 
                printf("\n");
        }

//==================================
int a=(rand()%INT_MAX)+(rand()%INT_MIN);
printf("\n=====================\nRandom Binary Value\nTHE RAND VALUE:%d\n",a);
for(n=size-1;n>=0;n--){
        printf("%d",a>>n&1);
}
        printf("\n");
        return 0;
}
