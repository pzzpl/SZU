#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//在s中寻找ch字符的index
int indexOfCh(char *s,char ch){
    char *p0 = s;
    while(*p0 != ch && *p0 != '\0') {
        p0++;
    }
    if(*p0 == '\0')
        return -100;
    return p0 - s;
}


double myAtof(char *s){
    double result;
    result = 0.0;
    int num,i;

    int iofe;
    int iofp;

    //寻找e
    iofe = indexOfCh(s,'e');
    iofe = indexOfCh(s,'E');
    //寻找.
    iofp = indexOfCh(s,'.');

    if(iofp != -100){
        //先读点的左边
        i=1;//i-0 个位 i-1 十位
        while(s+iofp-i != s-1){
            num = *(s+iofp-i) - '0';
            result += num * pow(10,i-1);
            i++;
        }
        //读小数点的右边
        i=1;
        while(*(s+iofp+i) != '\0' && *(s+iofp+i) != 'e'){
            num = *(s+iofp+i) - '0';
            result += num * pow(10,-i);
            i++;
        }
    }
    //若e存在 都e的右边
    if(iofe != -100){
        int sign = 1;
        i =1;
        while(*(s+iofe+i) != '\0'){
            if(*(s+iofe+i) == '-'){
                sign = -1;
            }else{
                num = *(s+iofe+i) - '0';
            }
            i++;
        }
        result *= pow(10,sign*num);
    }
    return result;
}

//测试
int main()
{
    char s[100];
    gets(s);
    double result = myAtof(s);
    printf("%.9f",result);
    return 0;
}
