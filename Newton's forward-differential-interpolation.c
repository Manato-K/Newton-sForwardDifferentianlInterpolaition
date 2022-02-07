/* Newton's forward differential interpolation */
#include <stdio.h>
#include <math.h>
#define N 5
int main(void){
    int i,j;
    float x[N],f[N][N],X,r,p,k;
    for(i=0;i<N;i++) {
        x[i]=2.0+0.1*i;
        f[0][i]=sqrt(x[i]);
        }
    for(i=1;i<N;i++)
        for(j=0;j<N-i;j++)
            f[i][j]=f[i-1][j+1]-f[i-1][j];
    printf("input X:");
    scanf("%f",&X);
    r=(X-x[0])/(x[1]-x[0]);
    p=f[0][0];
    k=1.0;
    for(i=1;i<N;i++) {
        k*=(r-i+1)/i;
        p+=k*f[i][0];
        printf("p%d=%f(%f)\n",i,p,sqrt(X)-p);
    }
}

/*
input X:9.2
p1=3.928755(-0.895605)
p2=1.827547(1.205603)
p3=5.126431(-2.093280)
p4=-0.637734(3.670885)
*/