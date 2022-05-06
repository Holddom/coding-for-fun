typedef struct {
    int rear;
    int front;
    int *queue;
    int count;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj=(RecentCounter*)malloc(sizeof(RecentCounter));
    obj->rear=0;
    obj->front=0;
    obj->queue=(int*)malloc(sizeof(int)*10000);
    obj->count=0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    //先将请求入队
    obj->queue[obj->rear]=t;
    obj->rear=(obj->rear+1);
    obj->count++;
    if(t-obj->queue[obj->front]<=3000)
    {
        ;  //空语句
    }
    else
    {
        //出队到直到头指针的t值符合条件
        while(  obj->front<=obj->rear
                    &&
        t-obj->queue[obj->front]>3000 )
        {
            obj->front=(obj->front+1);
            obj->count--;
        }
    }
    return obj->count;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/



