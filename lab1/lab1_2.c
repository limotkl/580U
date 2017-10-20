#include <stdio.h>
#include <math.h>
int main ()
{
        //PART A
        double x=2.55;
        double result_1=3*pow(x,3)-5*pow(x,2)+6;
        printf("\nPART A===================\n\n");
        printf("3x^3-5x^2+6=%e\n",result_1);
        double result_2=(3.31*pow(10,-8)*2.01*pow(10,-7))/(7.16*pow(10,-6)+2.01*pow(10,-8));
        printf("(3.31 × 10^-8 × 2.01 × 10^-7) / (7.16 × 10^-6 + 2.01 × 10^-8)=%e\n",result_2);
        //PART B
        int i[3]={365,12258,996};
        int j[3]={7,28,4};
        printf("\nPART B===================\n\n");
        int n;
        for(n=0;n<3;n++)
        {
                int next_multiple=i[n]+j[n]-i[n]%j[n];
                printf("i=%d,j=%d,next_multiple=%d\n",i[n],j[n],next_multiple);
        }
        //PART C
        //typecast int
        printf("\nPART C (int) ===================\n\n");
        for( n=0;n<3;n++)
        {
                int next_multiple=i[n]+j[n]-i[n]%j[n];
                printf("i=%d,j=%d,next_multiple=%d\n",(int)i[n],(int)j[n],(int)next_multiple);
        }
        //typecast double
        printf("\nPART C (double) ===================\n\n");
        for( n=0;n<3;n++)
        {
                int next_multiple=i[n]+j[n]-i[n]%j[n];
                printf("i=%f,j=%f,next_multiple=%f\n",(double)i[n],(double)j[n],(double)next_multiple);
        }
        //typecast char
        printf("\nPART C (char)===================\n\n");
        for( n=0;n<3;n++)
        {
                int next_multiple=i[n]+j[n]-i[n]%j[n];
                printf("i=%c, j=%c, next_multiple=%c\n",(char)i[n],(char)j[n],(char)next_multiple);
        }
        return 0;
}
