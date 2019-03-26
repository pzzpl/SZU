#include <stdio.h>
#include <stdlib.h>
/*
leetcode 14:Longest Common Prefix
*/
char* longestCommonPrefix(char** strs, int strsSize) {
    int len =0,i,j;



    for(int k=0;strs[0][k]!= '\0';k++){
        for(j=1;j<strsSize;j++){
            if(strs[j-1][k] == strs[j][k]){
                continue;
            }else{
                break;
            }
        }
        if(j==strsSize){
            len++;
        }else{
            break;
        }
    }
    char *result = malloc(len);
    for(i=0;i<len;i++){
        result[i] = strs[0][i];
    }
    result[len] = '\0';
    return result;
}

int main()
{
    char *p[] = {"flowr","flowr","flow"};
    int arrSize = 3;
    char *result = longestCommonPrefix(p,arrSize);
    printf("%s",result);
    return 0;
}
