/*计算公式*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int to_nums(char* c);   //函数定义
int evalRPN(char** tokens, int tokensSize);

int main(){
    char* s[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    char** str = s;     //初始化
    //不知道为什么下面这句不采用定义中间变量的方法来初始化不可以
    //char** str = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    /*然后我查了一下
    **
        警告是因为，害怕你通过指针来修改字串常量，因为字串常量分配在全局区，而不是在函数的堆栈区，
        程序员可能会存在非法操作，造成内存入侵。只是警告而已。
        消除警告的话：
        #pragma warning(disable : 警告号)
        在头文件中加上这么一句就可以了……
        还有……最好少用 ** 类的指针，或者说最好杜绝这类指针的出现。


        */
    //printf("%c \n", *(*(str)));
    int len = 13;
    int result = evalRPN(str, len);
    if(result == -1)
        printf("wrong arithmetic expression!\n");
    else
        printf("the result is: %d\n", result);
    return 0;
}
int to_nums(char* c){       //将字符转化为数字
    int res=0;
    int flag = 0;
    if(*c == '-'){
        flag = 1;
        *c++;
    }
    while(*c != '\0'){
        res *= 10;
        res += *c - '0';
        *c++;
    }
    if(flag)
        res = -res;
    return res;
}


int evalRPN(char** tokens, int tokensSize) {
    if(tokensSize == 0)
        return 0;
    int stack[tokensSize];
    int i = -1,j = 0;
    int result = 0;
    while(j < tokensSize){
        switch(tokens[j][0]){
            case '+':
                if(i<1)
                    return -1;
                result = stack[i-1]+stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            case '-':
                if(tokens[j][1] != '\0'){       //如果第一个字符是负号，还要判断其是不是负数
                    stack[++i] = to_nums(tokens[j]);
                    break;
                }
                if(i<1)
                    return -1;
                result = stack[i-1]-stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            case '*':
                if(i<1)
                    return -1;
                result = stack[i-1]*stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            case '/':
                if(i<1)
                    return -1;
                result = stack[i-1]/stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            default:                            //是数字则转化为数字
                stack[++i] = to_nums(tokens[j]);
        }
        j++;
    }
    if(j == tokensSize && i == 0)
        return stack[0];
    else
        return -1;
}
