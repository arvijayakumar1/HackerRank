#include  <stdio.h>
#include  <stdlib.h>
int main(void)
{
    int i,j, no_of_words, count=0;
    char **input=(char**)malloc(sizeof(char*)*100);
    for (i=0; i<100; i++)
         input[i] = (char *)malloc(100000* sizeof(int));
    scanf("%d", &no_of_words);
    for(i=0;i<no_of_words;i++)
        scanf("%s",input[i]);
    for(i=0;i<no_of_words;i++){
    lab:
        j=1;
        while(input[i][j]){
            if(input[i][j-1]==input[i][j])
            {
                count++;
                input[i][j]='*';
                goto lab;
    }
            j++;
    }
        printf("%d\n", count);
        count=0;
    }
    return 0;
}