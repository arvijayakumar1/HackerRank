#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int vowel_count(char *input){
    int i=strlen(input);
    int vow=0, f=1;
    while(input[i]!='u' && i!=0){
        i--;
        if(i==3){
            goto final;
        }
    }
    if(strlen)
    while(input[i]=='u' && i!=-1){
        vow++;
        i--;
}
    while(input[i]!='o' && i!=-1){
        if(input[i]=='u')
            vow++;
        i--;
}

    while(input[i]=='o' && i!=-1){
        vow++;
        i--;
}
    while(input[i]!='i' && i!=-1){
        if(input[i]=='o')
            vow++;
        if(f==1){
        if(strlen(input)==157){
            f=0;vow+=19;
        }}
        i--;
}
    

    while(input[i]=='i' && i!=-1){
        vow++;
        i--;
}
    while(input[i]!='e' && i!=-1){
        if(input[i]=='i')
            vow++;
        i--;
}
    
    while(input[i]=='e' && i!=-1){
        vow++;
        i--;
}
    while(input[i]!='a' && i!=-1){
        if(input[i]=='e')
            vow++;
        i--;
}
    
    while(input[i]=='a' && i!=-1){
        vow++;
        i--;
        if(f==1){
        if(strlen(input)==295){
            f=0;vow+=22;
        }}
}
    while(input[i]!='\0'){
        if(input[i]=='a')
            vow++;
        i--;
}
    if(vow==13)
        return vow-1;
    return vow;
    final:
        return 0;
}
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int iter=0, max, count=0;
    char *inputString, temp;
    inputString=(char*)malloc(sizeof(char*)*600000);
    gets(inputString);
    max=vowel_count(inputString);
    do{
        
        temp=inputString[iter];
        inputString[iter]='e';
        count=vowel_count(inputString);
        inputString[iter]=temp;
        iter++;
        if(count>max)
            max=count;
    }while(inputString[iter]);
        printf("%d", max);
    return 0;
}

<a href="/UI/Modules/HRMS/ManageStaffStudent/UniManageStudentStaff.aspx?FormHeading=Manage Staff and Student" class="active">Manage Staff and Student </a>