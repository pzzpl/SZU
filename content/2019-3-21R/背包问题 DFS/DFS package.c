#include<stdio.h>

int n = 5, capacity = 8;
int mass[5] = {3,5,1,2,2};
int v[5] = {4,5,2,1,3};
int max = 0, maxn = 0;
int maxpack[5];

void DFS(int k, int amount, int pack[], int totalv,int totalw){
    if( k == n ){        //没有物品可以装了，看是否最大价值，是则保存背包状态
        if(totalv > max){
            for(int i = 0; i < amount; i++){
                maxpack[i] = pack[i];
            }
            max = totalv;
            maxn = amount;
        }
        return;
    }

    if(totalw + mass[k] <= capacity){       //够装则装入这一件物品
        pack[amount] = k+1;
        DFS(k+1, amount + 1, pack,totalv + v[k], totalw + mass[k]);
    }

    DFS(k+1, amount, pack, totalv, totalw);     //不选这一件物品
}

int main(){

    int totalv = 0, totalw = 0;
    int pack[5];
    int amount = 0;

    DFS(0, amount, pack, totalv, totalw);
    printf("the max value is %d, packed :", max);
    for(int i = 0; i < maxn; i++){
        printf("%d ", maxpack[i]);
    }
}
