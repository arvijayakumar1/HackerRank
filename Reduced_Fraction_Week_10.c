//gcc 5.4.0
/*
Test case-1:
5
722/148+360/176
978/1212+183/183
358/472+301/417
780/309+684/988
258/840+854/686

Test case-2:
10
241/26+612/398
278/348+246/157
156/53+952/760
263/418+560/304
540/28+44/295
636/78+354/868
68/415+1041/807
147/269+224/844
759/120+370/72
654/162+476/307

Test case-3:
10
263/418+560/304
540/28+44/295
636/78+354/868
68/415+1041/807
147/269+224/844
759/120+370/72
722/148+360/176
978/1212+183/183
358/472+301/417
780/309+684/988

*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int gcd(int first, int second){
    int r;
    while(second > 0){
        r=first%second;
        first=second;
        second=r;
    }
    return first;
}
void addFraction(int num1, int den1, int num2, 
                 int den2, int &num3, int &den3)
{
    den3 = gcd(den1,den2);
    den3 = (den1*den2) / den3;
    num3 = (num1)*(den3/den1) + (num2)*(den3/den2);
    lowest(den3,num3);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,dd,i=0, k=0, u=0, j=0, a,b,c,d, rr;
    char exp[500][1000], temp[10]={'\0'}, temp1[10]={'\0'}, cc='/';
    int len;
    scanf("%d", &len);
    for(i=0;i<len;i++)
        scanf("%s", exp[i]);
    
    for(i=0;i<len;i++){
        j=0;k=0;
        while(exp[i][k]!='/'){
              temp[j]=exp[i][k];
              k++;j++;
              }
              a=atoi(temp);
              //temp[10]={};
        k++;j=0;
        u=0;
        while(temp[u++])
            temp[u]='\0';
              while(exp[i][k]!='+'){
              temp[j]=exp[i][k];
              k++;j++;
              }
              b=atoi(temp);
        k++;j=0;u=0;
        while(temp1[u++])
            temp[u]='\0';
              while(exp[i][k]!='/'){
              temp1[j]=exp[i][k];
              k++;j++;
              }
              c=atoi(temp1);
        k++;j=0;
        u=0;
        while(temp[u++])
            temp[u]='\0';
              while(exp[i][k]!='\0'){
              temp[j]=exp[i][k];
              k++;j++;
              }
              d=atoi(temp);
        n=(a*d)+(b*c);
        dd=b*d;
        rr=gcd(n,dd);
        n/=rr;
        dd/=rr;
        printf("%d",n);
        printf("%c",cc);
        printf("%d",dd);
        printf("\n");
    }
    return 0;
}



#include<stdio.h>

int gcd(int f, int s){
    int r;
    while(s > 0){
        r=f%s;
        f=s;
        s=r;
    }
    return f;
}
int main(){

    int a,b,c,d,e,f,g,len;
    scanf("%d", &len);
    for(int i=0;i<len;i++){
    scanf("%d/%d+%d/%d", &a,&b,&c,&d);
    e=(a*d+b*c);
    f=(b*d);
    g=gcd(e,f);
    e/=g;
    f/=g;
        printf("%d/%d\n",e , f);}
    return 0;
}