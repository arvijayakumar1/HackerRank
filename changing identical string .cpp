#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

void swap(char *a, char *b){
    char c;
    c=*a;
    *a=*b;
    *b=c;
}

int charPos(char *a, int i, char s){
    for(int p=i; p<strlen(a);p++){
        if(a[p]==s)
            return p;
    }
    return 10000;
} 

int charRevPos(char *a, int i, char s){
    for(int p=strlen(a); p>i;p--){
        if(a[p]==s)
            return p;
    }
    return 100000;
} 

void changeAChar(int pos, int i, char *str)
{
    for(int j=pos;j>i;j--) 
        swap(&str[j],&str[j-1]); 
    
}

void changeBChar(int pos, int i, char *str1)
{
    for(int j=pos;j>i;j--) 
        swap(&str1[j],&str1[j-1]); 
    
}



int addCount(int pos, int i, int len)
{
    //if(pos)
        return std::min(len-pos, pos-i);
    
    //if((pos-i>len-pos) &&( i<len/2))
      //  return (len-pos+i);
    //else 
      //  return (pos-i);
}

//int min(int afc, int abc, int bfc, int bbc){
  //  return std::min(std::min(afc,abc),std::min(bbc,bfc));
//}
int main(){
    char *a, *b, temp;
    int count=0, len, i, j, t, afrpos, abkpos, bfrpos, bbkpos, no1,no2,no3,no4, min1;
    a=(char*)malloc(sizeof(char*)*2500);
    b=(char*)malloc(sizeof(char*)*2500);
    cin>>a>>b;
    
    len=strlen(a);
    if(a[0]!=b[0])
    {
    if(a[0]==b[len-1])
        {
            temp=b[0];
            b[0]=b[len-1];
            b[len-1]=temp;
            count++;
        }
        else if(b[0]==a[len-1])
        {
            temp=a[0];
            a[0]=a[len-1];
            a[len-1]=temp;
            count++;
        }
    }
   for (i=0; i<strlen(a);i++)
   {
       if(a[i]!=b[i])
       {
           count++;
           min1=10000;
           afrpos = charPos(a, i,  b[i]);
           abkpos = charRevPos(a, i, b[i]);
           bfrpos = charPos(b, i, a[i]);
           bbkpos = charRevPos(b, i, a[i]);
           //printf("%d -- %d %d %d %d\n",i, afrpos,abkpos,bfrpos,bbkpos );
       
           no1=addCount(afrpos,i,strlen(a));
           no2=addCount(abkpos,i,strlen(a));
           no3=addCount(bfrpos,i,strlen(a));
           no4=addCount(bbkpos,i,strlen(a));
           //printf("%d -- %d %d %d %d\n",i, no1,no2,no3,no4 );
           min1 = std::min({no1,no2,no3,no4});
           count+=min1;
           //printf("min-%d\n",min1);
           if(min1==no1){
               //changeAChar(afrpos,i,a);
               for(int j=afrpos;j>i;j--) 
                    swap(&a[j],&a[j-1]);
               count++;
    
}
           else if(min1==no2){
               for(int j=afrpos;j>i;j--) 
                    swap(&a[j],&a[j-1]);
                count++;
           }
           else if(no3==min1){
               //changeBChar(bfrpos,i,b);
               for(int j=bfrpos;j>i;j--) 
                    swap(&b[j],&b[j-1]);
               count++;
           }
           else 
           {
               for(int j=bfrpos;j>i;j--) 
                    swap(&b[j],&b[j-1]);
                count++;
           }
          }
    //puts(a);
    //puts(b);
   }

    cout<<count<<endl;;
    puts(a);
    puts(b);     
    return 0;
}