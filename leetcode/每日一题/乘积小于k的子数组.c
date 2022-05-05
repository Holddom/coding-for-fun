

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int ret=0;
    if(k==0)  //������������
    return ret;

    int i=0;  //����ָ��
    int j=0;  //����ָ��
    int product=1;  //�˻���
    for( i=0;i<numsSize;i++)
    {
        product*=nums[i];
        while(j<=i&&product>=k)  //��������
        {
            product/=nums[j];
            j++;
        }
        ret+=i-j+1;             //ÿһ�εĻ�������
    }

    return ret;
}

