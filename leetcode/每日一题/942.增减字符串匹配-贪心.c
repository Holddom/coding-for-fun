/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * s, int* returnSize){
    int len=strlen(s);
    int max=len;
    int min=0;
    int * ret=(int*)malloc(sizeof(int)*(len+1));
    int count=0;
    for(int i=0;i<len;i++)
    {
    if(s[i]=='I')
        ret[count++]=min++;
    else
        ret[count++]=max--;
    }
    ret[count]=max;
    *returnSize=len+1;
    return ret;
}



