#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *input, c; 
    int i=0, ch;
    long int count=0;
    
    input=malloc(sizeof(char)*800000);
    gets(input);
    while(input[i]=='a' && input[i]!='\0')
	{
        i++;
		count++;
	}
 	while(input[i]!='e' && input[i]!='\0')
	 {
        if(input[i]=='a' && input[i]!='\0')
            count++;
            i++;                
            }
            while(input[i]=='e' && input[i]!='\0'){
                i++;count++;
                
            }
            while(input[i]!='i' && input[i]!='\0'){
                if(input[i]=='e' && input[i]!='\0')
                    count++;
                i++;                
            }
            while(input[i]=='i' && input[i]!='\0'){
                i++;count++;
            }
            while(input[i]!='o' && input[i]!='\0'){
                if(input[i]=='i' && input[i]!='\0')
                    count++;
                i++;                
            }
            while(input[i]=='o' && input[i]!='\0'){
                i++;count++;
            }
          while(input[i]!='u' && input[i]!='\0'){
                if(input[i]=='o' && input[i]!='\0')
                    count++;
                i++;                
            }
        if(input[i]=='u'){
            while(input[i]=='u' && input[i]!='\0'){
                i++;count++;
                
            }
            while(input[i]!='\0'){
                if(input[i]=='u' )
                    count++;
                i++;                
            }
        }
        else
            count=0;
        
    printf("%ld",count);
    return 0;
}
