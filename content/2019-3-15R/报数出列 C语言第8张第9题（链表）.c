/*报数，每逢5出列，求剩下那个数（链表法）*/
#include<stdio.h>
struct Node{
    int val;
    struct Node* next;
};
int main(){
    printf("please input a number:");
    int n;
    scanf("%d", &n);
    if(n == 0){
        printf("wrong num!");
        return 0;
    }
    //开始创建链表
    struct Node* head = (struct Node* )malloc(sizeof(struct Node));
    if(head==NULL){
        printf("no allocate!\n");
        return 0;
    }
    else
        printf("success!\n");
    struct Node* k = head;
    head->val = 1;
    printf("the head is %d \n", head->val);
    int i = 2;
    while(i <= n){
        struct Node*p = (struct Node*)malloc(sizeof(struct Node));
        p->val = i;
        k->next = p;
        k = k->next;
        i++;
    }
    k->next = head;
    int c = 0;
    while(head->next != head){      //只剩一个的条件是自己指向自己
        c = 1;
        while(c<5-1){
            head = head->next;
            c++;
        }       //此时head指向要出列的节点的前一个节点
        k = head->next;     //k指向要删除的节点
        head->next = k->next;
        head = head->next;      //head记得要指向下一个
        //printf("delete %d\n", k->val);
        free(k);
    }
    printf("the last kid is %d\n", head->val);
    return 0;
}


