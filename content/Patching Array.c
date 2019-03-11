int minPatches(int* nums, int numsSize, int n) {
    int res = 0;    //返回增加数
    int i = 0;
    long target = 1;    //下一个sum目标
    while(target <= n){
        //目标在n以内时循环
        if(i < numsSize && nums[i] <= target){      //当前数字<=目标，即现有数字可以组成target
            target += nums[i++];    //下一个sum目标
        }
        else{
            target += target;   //下一个sum目标
            res++;  //需要增加一个数字
        }
    }
    return res;
}