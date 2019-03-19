/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isPalin(char* s, int end);
void helper(char* s, char*** ret, int** colS, int* retS, char** cur, int k );


char*** partition(char* s, int** columnSizes, int* returnSize) {
    *returnSize = 0;    //          初始可能结果数0
    if(s == NULL || !strcmp(s, "")) return NULL;  //给的是空串
    
    
    /*预分配空间*/
    *columnSizes = (int*)malloc(sizeof(int)*500);  //为每行分配500个保存字符串长度的int型空间
    char*** ret = (char***)malloc(sizeof(char**) * 500);    //假设有500个可能的不同的分配方案
    char** cur = (char**)malloc(sizeof(char*) * 500);   //假设每个方案有500个分字串    
    int len = strlen(s) + 1;
    for(int i = 0; i<500; i++)      //每个子字符串最长可能有原字符串那么长，所以为每个子字符串分配len个字符长度
        cur[i] = (char*)malloc(len);
    
    /*回溯法*/
    helper(s, ret, columnSizes, returnSize, cur, 0);

    return ret;
        
}

void helper(char* s, char*** ret, int** columnSizes, int* returnSize, char** cur, int k ){
    if(*s == '\0'){    //s指向字符串尾部，说明该方案成立
        ret[*returnSize] = (char**)malloc(sizeof(char*)*k);   //初始化新的方案
        for(int i = 0; i<k; i++){
            ret[*returnSize][i] = (char*)malloc(strlen(cur[i]) + 1);  //  初始化每个子字符串
            strcpy(ret[*returnSize][i], cur[i]);   //整个字符串赋值
        }
        (*columnSizes)[(*returnSize)++] = k;    //方案数加1，该方案子字符串数为k
        return;
    }
    /* 开始取字串 */
    int len = strlen(s);
    for(int i = 0; i < len; i++)  {
        if(isPalin(s, i)) {      /*  如果从0到i的字串是回文  */
            strncpy(cur[k], s, i+1);  //该字串放入到暂存方案里面的第k个暂存字段
            cur[k][i+1] = '\0';         //千万记得加终止符！
            
            /* 从下一个字符开始照下一个回文串 */
            helper(s+i+1, ret, columnSizes, returnSize, cur, k+1);
        }
        //如果从0到i的字串不是回文，则长度加一，继续找回文串
    }
}

bool isPalin(char* s, int end){
  /* printf("error: start %d, end %d\n", start, end); */
  if(end < 0)          return false;
  int start = 0;
  while(end > start)    //由两边像中间检查是否回文串
  {
    if(s[start] != s[end]) return false;
    start++;   end--;
  }
  return true;
}




