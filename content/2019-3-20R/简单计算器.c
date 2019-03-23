#include<stdio.h>

double to_num(char sen[], int i){
    double sum = sen[i] - '0';
    return sum;
}

double calcu(char c, double a, double b){
    double res = 0;
    switch(c){
    case '+':
        res = a + b;break;
    case '-':
        res = a - b;break;
    case '*':
        res = a * b;break;
    case '/':
        res = a / b;break;
    }
    return res;
}

int main(){
    char sen[200];  //存放本行的运算式
    double tmp[200];    //  存放暂时的运算结果和未参与演算的数据
    char cal[100];  //  存放运算符
    int topt = -1, topc = -1, i = 0, sum;
    gets(sen);
    while(sen[0] != '0'){
        do{
            if(sen[i] >= '0' && sen[i] <= '9'){
                sum = 0;
                while(sen[i] >= '0' && sen[i] <= '9'){//是数字则入栈
                    sum *= 10;
                    sum += to_num(sen, i++);
                }
                tmp[++topt] = sum;
            }

            else{           //不是数字，先若前一个运算符高级，就先弹出两个数字和一个运算符继续计算，，否则继续压入符号
                while(topc > -1 && (sen[i] == '+' || sen[i] == '-' || ((sen[i] == '*' || sen[i] == '/') && (cal[topc] == '*' || cal[topc] == '/')))){
                    tmp[topt-1] = calcu(cal[topc--], tmp[topt-1], tmp[topt]);
                    topt--;
                }
                cal[++topc] = sen[i++];
            }
            if(sen[i] == ' ') ++i;

        }while(topt >= 0 && sen[i] != '\0');

        while(topc > -1){       //栈中还有符号，说明运算还没有结束
            tmp[topt-1] = calcu(cal[topc], tmp[topt-1], tmp[topt]);
            topt--;
            topc--;
        }

        printf("%.2f\n", tmp[0]);
        topt = topc = -1;
        i=0;
        gets(sen);      //接收新的一行
    }
    return 0;
}
