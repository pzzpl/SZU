#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
/*
PAT 1009
*/
void swap(char *s,int i,int j){
    char temp = *(s+i);
    *(s+i) = *(s+j);
    *(s+j) = temp;
}


void reverse(char *s,int a,int b){
    int i = a;
    int j = b;
    while(i<j){
        swap(s,i++,j--);
    }
}

void getResult(char *str,int len){
    int i;
    int begin_index = 0;
    reverse(str,0,len-1);
    //查询所有空格的index
    for(i=0;i<=len;i++){
        if(*(str+i) == ' ' || *(str+i) == '\0'){
            reverse(str,begin_index,i-1);
            begin_index = i+1;
        }
    }
    printf("%s",str);
}

int main()
{

    char s[MAXSIZE];
    gets(s);
    int len = strlen(s);
    getResult(s,len);
    return 0;
}

