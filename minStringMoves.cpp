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
int minStringMoves(char* a, char* b) {
    int length, pos, i, j, moves=0;
    char *ptr;
    length = strlen(a);
    if(a[0]==b[length]){
        swap(&a[0],&b[length-1]);
        moves++;
    }
    for(i=0;i<length;i++) {
        ptr = strchr(a,b[i]);
        pos = ptr - a;
        if(i==0 && pos == length-1) {
            swap(&a[0], &a[length-1]);
            moves++;
        }
        else {
            for(j=pos;j>i;j--) {
                swap(&a[j],&a[j-1]);
                moves++;
            }
        }
        if(strcmp(a,b) == 0)
            break;       
   }
   return moves;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char *a, *b;
    a=(char*)malloc(sizeof(char*)*2000);
    b=(char*)malloc(sizeof(char*)*2000);
    cin>>a>>b;
    int no = minStringMoves(a,b);    
    cout<<no;
    return 0;
}