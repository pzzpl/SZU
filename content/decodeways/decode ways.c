int numDecodings(char* s) {
    int len = strlen(s);    
    if(len == 0 || (len > 0 && s[0] == '0'))//第一个字符不可以是'0'
        return 0;
    int ways[len+1] ; // ways[1] 到 ways[len +1] 保存 s[0]到s[len-1]的组合数
    ways[0] = 1;
    for(int  i = 1; i <= len; ++i){
        if(s[i-1] == '0'){  //当前字符为‘0’，则不能单独出现
            ways[i] = 0;
        }            
        else{		//单独组合时，加上前面i-1个数的组合数
            ways[i] = ways[i-1];
        }
        if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i-1] <= '6'))) {	//看当前字符能否能与前一个字符组合
            ways[i] += ways[i - 2];
        }
    }
    return ways[len];
}
