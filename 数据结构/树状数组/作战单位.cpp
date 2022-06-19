const int N=1e5+10;
class Solution {
private:
    int tree[N];
    // Greater[x]记录a[i]=x左边有大于a[i]的元素个数，Lower[x]记录a[i]=x左边有小于a[i]的元素个数
    int Greater[N],Lower[N];
    // 树状数组3个函数默写
    // 返回二进制最低位1对应的十进制数
    int lowbit(int x){
        return x&-x;
    }

    // 前x项数的总和
    int sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=tree[i];
        return res;
    }

    // 在位置x上加上v
    void add(int x,int v)
    {
        for(int i=x;i<=N;i+=lowbit(i))
            tree[i]+=v;
    }

public:
    int numTeams(vector<int>& a) {
        int n=a.size();
        // 从左至右扫描
        memset(tree,0,sizeof tree);
        for(int i=1;i<=n;++i){
            int x=a[i-1];
            // 分别获得位置x左边小于ai的元素个数、大于ai的元素个数
            Lower[i]=sum(x-1),Greater[i]=sum(N-1)-sum(x);
            // 每处理一个数，就把ai加入到集合中去，相当于在ai这个位置上+1
            add(x,1);
        }

        memset(tree,0,sizeof tree);
        int res=0;
        // 从右向左扫描
        for(int i=n;i;i--){
            int x=a[i-1];
            // 分别获得位置x右边大于ai的元素个数、小于ai的元素个数
            res+=Lower[i]*(sum(N-1)-sum(x));
            res+=Greater[i]*sum(x-1);
            // 每处理一个数，就把ai加入到集合中去，相当于在ai这个位置上+1
            add(x,1);
        }
        return res;
    }


};
