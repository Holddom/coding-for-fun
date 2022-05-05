

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int ret=0;
    if(k==0)  //是正整数数组
    return ret;

    int i=0;  //遍历指针
    int j=0;  //滑动指针
    int product=1;  //乘积和
    for( i=0;i<numsSize;i++)
    {
        product*=nums[i];
        while(j<=i&&product>=k)  //滑动过程
        {
            product/=nums[j];
            j++;
        }
        ret+=i-j+1;             //每一次的滑动距离
    }

    return ret;
}

