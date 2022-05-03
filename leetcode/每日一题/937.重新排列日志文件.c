

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct arrlogs
 {
     char *log;  //每条日志及其下标
     int idx;
 };
 int cmp(const void* a,const void* b)
 {
        //强制转换构造类型
        struct arrlogs* log1=(struct arrlogs*)a;
        struct arrlogs* log2=(struct arrlogs*)b;
        //找到第一个空格
        char* s1=strstr(log1->log," ");
        char* s2=strstr(log2->log," ");
        //判读是否是数字日志
        int flag1=isdigit(s1[1]);
        int flag2=isdigit(s2[1]);
        if(flag1&&flag2)  //如果两个都是数字日志  下标小的优先
        {
            return log1->idx-log2->idx;
        }
        if(!flag1&&!flag2)  //如果都是字母日志
        {
            int flag=strcmp(s1,s2);
            if(flag==0)
            return strcmp(log1->log,log2->log) ;//比较标识符

            return flag;
        }
        //如果其中一个是数字日志
        return flag1?1:-1;
 }
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    struct arrlogs* arr=(struct arrlogs*)malloc(sizeof(struct arrlogs)*logsSize);
    //由于qsort排序的实现，我们必须保证知道每条日志的下标来判断数字日志的顺序
    //下面为数组赋上每条日志
    for(int i=0;i<logsSize;i++)
    {
        arr[i].log=logs[i];
        arr[i].idx=i;
    }
    //qsort排序  注意我的每个参数传递
    qsort(arr,logsSize,sizeof(struct arrlogs),cmp);
    char ** ret = (char **)malloc(sizeof(char *) * logsSize);  //malloc数组然后赋上排好序的日志
    for (int i = 0; i < logsSize; i++) {
        ret[i] = arr[i].log;
    }
    *returnSize=logsSize;
    free(arr);
    return ret;
}


