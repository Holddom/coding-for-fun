int findKthNumber(int m, int n, int k){
    int left=0;
    int right=m*n;
    while(left<right)
    {
        int mid=(left+right)/2;
        int count=mid/n*n;
        for(int i=mid/n+1;i<=m;i++)
        {
            count+=mid/i;
        }
        if(count>=k)
        {
            right=mid;
        }
        else
        left=mid+1;
    }
    return left;
}

