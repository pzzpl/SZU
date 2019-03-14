#include<stdio.h>
#define bool int  //因为c语言没有bool型，要自己定义
#define false 0
#define true 1
bool judgeCircle(char* moves) {
    int cu,cd,cl,cr;
    cu = cd = cl  = cr = 0;
    while(*moves){ //moves指向的内容不是‘\0’
        switch(*moves){   //统计四种指令的总数
            case 'U': cu++;break;
            case 'D': cd++;break;
            case 'L': cl++;break;
            case 'R': cr++;break;
        }
        moves++;
    }
    if(cu == cd && cl == cr)  //只要上下指令数相等，且左右指令数相等， 就肯定能返回原点
        return true;
    else
        return false;
}

int main(){
    char tmp[100];
    printf("please input a string of instructions: ");//输入指令，只能是LRUD四种而且只能是大写
    scanf("%s", tmp);
    printf("\nthe robot returns to the origin : ");//判断能否返回原点
    if( judgeCircle(tmp))
        printf("true");
    else
        printf("false");
}
