#include <stdio.h>
#include <stdlib.h>
//打印沙漏


void printShaLou(int n,char ch){
    if(n == 0){
        printf("no num");
        return;
    }


    int leftOver = n;//剩余没用的字符
    int i,k = 0,topNum;
    int temp;//用于临时存储 topNum

    i=1;//因为有一个在两个倒三角之间

    //计算topNum
    leftOver--;
    while(leftOver >= (2*i+1)*2){
        leftOver -= (2*i+1)*2;
        i++;
        k++;
    }
    topNum = 2*k+1;
    temp = topNum;


    //一下都是打印沙漏的代码
    i=0;
    while(topNum >= 1){
        for(k=0;k<i;k++)
            printf(" ");
        for(k=0;k<topNum;k++)
            putchar(ch);
        topNum -= 2;
        i++;
        printf("\n");
    }
    //printf("topNum:%d\n",topNum);
    //printf("i:%d\n",i);
    topNum = 3;
    i -= 2;

    while(topNum  <= temp){
        for(k=0;k<i;k++)
            printf(" ");
        for(k=0;k<topNum;k++)
            putchar(ch);
        topNum += 2;
        i--;
        printf("\n");
    }

    printf("%d",leftOver);

}


//测试用例
int main()
{
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    printShaLou(n,ch);

    return 0;
}
