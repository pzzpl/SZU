#include <stdio.h>
#include <stdlib.h>

/*简单顺序查找*/
int findNumInArr(int *a,int len,int target){
    int i;
    for(i=0;i<len;i++){
        if(*(a+i) == target)
            return 1;
    }
    return 0;
}


int main()
{
    int n;
    scanf("%d",&n);//输入n个数
    int i,j;//工作指针
    int a[n];//定义n个整型
    for(i=0;i<n;i++){//输入n个数据
        scanf("%d",a+i);
    }

    int m;//待查找
    scanf("%d",&m);//输入n个数
    int b[m];
    for(i=0;i<m;i++){
        scanf("%d",b+i);
    }

    for(j=0;j<m;j++){
        int flag = findNumInArr(a,n,b[j]);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
