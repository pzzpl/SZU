#include<stdio.h>
struct Node{
    char val;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree(char pre[], char mid[], int prel, int prer, int midl, int midr){
    if(prer < prel) return NULL;
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->val = pre[prel];
    //printf("created %c\n", p->val);
    int i;
    for(i = midl; i <= midr; i++){
        if(mid[i] == pre[prel])
            break;
    }
    p->left = createTree(pre, mid, prel+1, prel + i - midl, midl, i-1);
    p->right = createTree(pre, mid, prel+1+i-midl, prer, i+1, midr);
    return p;
}

void postPrint(struct Node* root){
    if(root == NULL) return;
    postPrint(root->left);
    postPrint(root->right);
    printf("%c",root->val);
}

int main(){
    printf("Let's create a binary tree with prelist and midlist!\n");
    printf("please input a prelist:");
    char pre[255];
    gets(pre);
    /*for(int i = 0; i < strlen(pre);i++){
        printf("%c",pre[i]);
    }*/
    printf("please input a midlist:");
    char mid[255];
    gets(mid);
    if(strlen(pre) != strlen(mid)){
        printf("different length of these lists!\n");
        return 0;
    }

    struct Node* root = createTree(pre, mid, 0, strlen(pre)-1, 0, strlen(mid)-1);
    printf("successful created!\n");
    printf("the postlist is:");
    postPrint(root);
    printf("\n");
}
