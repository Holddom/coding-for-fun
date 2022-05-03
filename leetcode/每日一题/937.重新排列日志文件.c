

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct arrlogs
 {
     char *log;  //ÿ����־�����±�
     int idx;
 };
 int cmp(const void* a,const void* b)
 {
        //ǿ��ת����������
        struct arrlogs* log1=(struct arrlogs*)a;
        struct arrlogs* log2=(struct arrlogs*)b;
        //�ҵ���һ���ո�
        char* s1=strstr(log1->log," ");
        char* s2=strstr(log2->log," ");
        //�ж��Ƿ���������־
        int flag1=isdigit(s1[1]);
        int flag2=isdigit(s2[1]);
        if(flag1&&flag2)  //�����������������־  �±�С������
        {
            return log1->idx-log2->idx;
        }
        if(!flag1&&!flag2)  //���������ĸ��־
        {
            int flag=strcmp(s1,s2);
            if(flag==0)
            return strcmp(log1->log,log2->log) ;//�Ƚϱ�ʶ��

            return flag;
        }
        //�������һ����������־
        return flag1?1:-1;
 }
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    struct arrlogs* arr=(struct arrlogs*)malloc(sizeof(struct arrlogs)*logsSize);
    //����qsort�����ʵ�֣����Ǳ��뱣֤֪��ÿ����־���±����ж�������־��˳��
    //����Ϊ���鸳��ÿ����־
    for(int i=0;i<logsSize;i++)
    {
        arr[i].log=logs[i];
        arr[i].idx=i;
    }
    //qsort����  ע���ҵ�ÿ����������
    qsort(arr,logsSize,sizeof(struct arrlogs),cmp);
    char ** ret = (char **)malloc(sizeof(char *) * logsSize);  //malloc����Ȼ�����ź������־
    for (int i = 0; i < logsSize; i++) {
        ret[i] = arr[i].log;
    }
    *returnSize=logsSize;
    free(arr);
    return ret;
}


