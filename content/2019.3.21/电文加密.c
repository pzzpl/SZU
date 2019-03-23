#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
/*
电文加密 C程序设计124T6
*/
int myStrlen(char *str){
    char *p = str;
    while(*p!='\0')
        p++;
    return p-str;
}

int isLow(char ch){
    return ch<='z'&&ch>='a';
}
int isCap(char ch){
    return ch>='A'&&ch<='Z';
}

int main()
{
    char seq[MAXSIZE];
    scanf("%s",seq);
    int len = myStrlen(seq);
    int i;
    int redun;

    for(i=0;i<len;i++){
        if((isCap(seq[i])&&seq[i]+8 <= 'Z') ||( isLow(seq[i])&&seq[i]+8 <= 'z')){
            seq[i] += 8;
        }else{
            if(isLow(seq[i])){
                    redun = 'z' - seq[i];
                    seq[i] = 'a' + (8 - redun ) -1;
            }else{
                    redun = 'Z' - seq[i];
                    seq[i] = 'A' + (8 - redun ) -1;
            }
        }
    }

    printf("%s",seq);
    return 0;
}
