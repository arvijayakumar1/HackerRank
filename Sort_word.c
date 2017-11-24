#include  <stdio.h>
#include  <stdlib.h>
#include<string.h>
int main(void){
char sentence[1000], words[100][100];
int a = 0, i = 0, len, length=1, index = 0, count=0, flag=0;
gets(sentence);
len=strlen(sentence);
sentence[len-1]='\0';	sentence[0]=sentence[0]+32;
while (sentence[a] != '\0') {
if (sentence[a] == ' ') { 
words[index][i] = '\0'; 
i=0; 	a++; 	index++; 
}
words[index][i++] = sentence[a++];
}
words[index][i] = '\0';
while(count!=index+1){
for(i=0;i<=index;i++){
	if(strlen(words[i])==length){
		if(flag==0){
			words[i][0]=words[i][0]-32;
			printf("%s", words[i]);		fflush( stdout );
			flag=1;			count++;
		}
		else		{
			printf(" %s", words[i]);
			fflush( stdout );
			count++;
		}		
}}
length++;
}
fflush( stdout );
printf(".");
return 0;
}