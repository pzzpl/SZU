/*2019-3-17
**来源：C语言程序设计第10章3
**题目：编写一个随机发牌的程序
**分析：
**随机产生0~54的数字表示每一张牌
**设置标记数组，防止发过的牌重复发
**2张JOKER不带花色*/

#include<stdio.h>
#include<stdlib.h>
void dis_card();
static int c[54];
enum poker{
    spade,heart,diamond,club
}p[13];

main(){
    printf("你想要多少张牌：");
    int n;
    scanf("%d", &n);
    if(n < 1 || n > 54){
        printf("invalid number!\n");
        return 0;
    }
    printf("your cards:\n");
    for(int i = 0; i < n; i++){
        if(i%5 == 0)
            printf("\n");
        dis_card();
    }

}

void dis_card(){
    static int i = 0;
    do{
        i = rand()%54;
    }while(c[i] == 1);      //已经发过的牌标注为1
    c[i]=1;

    if(i==52){
        printf("blackJoker\t");
        return;
    }

    if(i==53){
        printf("redJoker\t");
        return;
    }

     int num = (i/4)%13 +1; //  获得卡面数字
     enum poker suit;
    switch(i%4){    //获得卡面花色
        case 0: suit = spade;break;
        case 1: suit = heart;break;
        case 2: suit = diamond;break;
        case 3: suit = club;break;
    }
    switch(suit){
        case spade: printf("  spade");break;
        case heart: printf("  heart");break;
        case diamond: printf("diamond");break;
        case club: printf("   club");break;
    }
    printf("%-2d\t",num);
}
