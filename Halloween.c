#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int temp, k=0;
    temp=p;
     //printf("%d %d", s, p);
    while( s>temp){
    	//printf("%d %d ", s, temp);
        k++;
        p-=d;
        temp+=p;
        
    }
    //printf("%d %d", s, temp);
    return (--k);
}

int main() {
    int p; 
    int d; 
    int m; 
    int s; 
    scanf("%i %i %i %i", &p, &d, &m, &s);
    int answer = howManyGames(p, d, m, s);
   // printf("%d\n", answer);
    return 0;
}
