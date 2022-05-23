static int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
typedef struct Tree{
    int x;
    int y;															//bfs�����ⷨ 
    int height;
}Tree;  //ÿ����������͸߶�
int cmp(void* pa, void* pb)//���ź���
{
    return ((Tree *)pa)->height - ((Tree *)pb)->height;
}

int bfs(int** forest,int row,int col,
        int now_x,int now_y,int tx,int ty)
{
    if(now_x==tx && now_y==ty)
    return 0;
    int step=0;  //����
    int* queue=(int*)malloc(sizeof(int)*row*col);//����
    int* visited=(int*)malloc(sizeof(int)*row*col);//�������
    memset(visited,0,sizeof(int)*row*col);
    int front=0;
    int rear=0;
    queue[rear++]=now_x*col+now_y;
    visited[now_x*col+now_y]=true;
    while(front!=rear)
    {
        step++;
        int sz=rear-front;
        for(int i=0;i<sz;i++)
        {
            int curx=queue[front]/col;
            int cury=queue[front]%col;
            front++;
            for(int j=0;j<4;j++)
            {
                int next_x=curx+dir[j][0];
                int next_y=cury+dir[j][1];
                if(next_x>=0 && next_x<row && next_y>=0 && next_y<col)
                {//�����һ��������Ϸ�
                    if(!visited[next_x*col+next_y]&&
                    forest[next_x][next_y]>0)
                    {//���û�з��ʹ��Ҳ����ϰ�
                        if(next_x == tx && next_y == ty)
                        {
                            free(queue);
                            free(visited);
                            return step;
                        }
                        queue[rear++]=next_x*col+next_y;
                        visited[next_x*col+next_y]=true;
                    }
                }
            }
        }
    }
     free(queue);
     free(visited);
    return -1;  //���ѭ������ ˵�����ܴﵽҪ������ ����-1
}

int cutOffTree(int** forest, int forestSize, int* forestColSize){
    int row=forestSize;
    int col=forestColSize[0];
    int trees=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(forest[i][j]>1)
            {
                trees++;  //��¼���Ŀ���
            }
        }
    }
    Tree* t=(Tree*)malloc(sizeof(Tree)*trees);
    int count=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(forest[i][j]>1)
            {
                t[count].x=i;
                t[count].y=j;
                t[count].height=forest[i][j];
                count++;
            }  //��ʼ�����ṹ
        }
    }
    //��������ĸ߶�����
    qsort(t,trees,sizeof(Tree),cmp);

    int now_x=0;
    int now_y=0;
    int ret=0;
    for(int i=0;i<trees;i++)
    {
        int step=bfs(forest,row,col,now_x,now_y,t[i].x,t[i].y);
        if(step == -1)
        {
            return -1;
        }
        ret+=step;
        now_x=t[i].x;  //ÿ����һ��bfs�� ���µ����Ҫ��������λ��
        now_y=t[i].y;
    }
    free(t);
    return ret;
}

