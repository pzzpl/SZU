#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    char val;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree2(char lay[], char mid[], int lenlay, int midl, int midr){
    if(lenlay == 0) return NULL;
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->val = lay[0];
    //printf("created %c\n", p->val);
    int i;
    for(i = midl; i <= midr; i++){
        if(mid[i] == lay[0])
            break;
    }
    /* Çó×óÓÒ×ÓÊ÷µÄ²ãĞò */
    char layl[i-midl];
    char layr[midr-i];
    int m = 0, n = 0;
    int k = 1, j;
    while(k < lenlay){
        for(j = midl; j <= midr; j++){
            if(mid[j] == lay[k] && j != i)
                break;
        }
        if(j < i)
            layl[m++] = lay[k];
        else
            layr[n++] = lay[k];
        k++;
    }
    /*for(int r = 0; r < m; r++){
        printf("%c ",layl[r]);
    }
    printf("\n");
    for(int r = 0; r < n; r++){
        printf("%c ",layr[r]);
    }*/
    p->left = createTree2(layl, mid, i-midl, midl, i-1);
    p->right = createTree2(layr, mid, midr-i, i+1, midr);
    return p;
}

void postPrint(struct Node* root){
    if(root == NULL) return;
    postPrint(root->left);
    postPrint(root->right);
    printf("%c",root->val);
}

int main(){
    printf("Let's create a binary tree with layerlist and midlist!\n");
    printf("please input a laylist:");
    char lay[255];
    gets(lay);
    printf("please input a midlist:");
    char mid[255];
    gets(mid);
    if(strlen(lay) != strlen(mid)){
        printf("different length of these lists!\n");
        return 0;
    }

    struct Node* root = createTree2(lay, mid, strlen(lay), 0, strlen(mid)-1);
    printf("successful created!\n");
    printf("the postlist is:");
    postPrint(root);
    printf("\n");
}
