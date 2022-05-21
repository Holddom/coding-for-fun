

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node{
     int start;
     int idx;
 }node;

 int cmp(void* a, void* b)
 {
     return (*(struct node*)a).start-(*(struct node*)b).start;
 }
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize){
    node* st=(node*)malloc(sizeof(node)*intervalsSize);
    for(int i=0;i<intervalsSize;i++)
    {
        st[i].start=intervals[i][0];
        st[i].idx=i;
    }
    qsort(st,intervalsSize,sizeof(node),cmp);
    int* ret=(int*)malloc(sizeof(int)*intervalsSize);
    for(int i=0;i<intervalsSize;i++)
    {
        int left=0;
        int right=intervalsSize-1;
        int ans=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(st[mid].start>=intervals[i][1])
            {
                ans=st[mid].idx;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        ret[i]=ans;
    }
    *returnSize=intervalsSize;
    return ret;
}

