const int N=1e5+10;
class Solution {
private:
    int tree[N];
    // Greater[x]��¼a[i]=x����д���a[i]��Ԫ�ظ�����Lower[x]��¼a[i]=x�����С��a[i]��Ԫ�ظ���
    int Greater[N],Lower[N];
    // ��״����3������Ĭд
    // ���ض��������λ1��Ӧ��ʮ������
    int lowbit(int x){
        return x&-x;
    }

    // ǰx�������ܺ�
    int sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=tree[i];
        return res;
    }

    // ��λ��x�ϼ���v
    void add(int x,int v)
    {
        for(int i=x;i<=N;i+=lowbit(i))
            tree[i]+=v;
    }

public:
    int numTeams(vector<int>& a) {
        int n=a.size();
        // ��������ɨ��
        memset(tree,0,sizeof tree);
        for(int i=1;i<=n;++i){
            int x=a[i-1];
            // �ֱ���λ��x���С��ai��Ԫ�ظ���������ai��Ԫ�ظ���
            Lower[i]=sum(x-1),Greater[i]=sum(N-1)-sum(x);
            // ÿ����һ�������Ͱ�ai���뵽������ȥ���൱����ai���λ����+1
            add(x,1);
        }

        memset(tree,0,sizeof tree);
        int res=0;
        // ��������ɨ��
        for(int i=n;i;i--){
            int x=a[i-1];
            // �ֱ���λ��x�ұߴ���ai��Ԫ�ظ�����С��ai��Ԫ�ظ���
            res+=Lower[i]*(sum(N-1)-sum(x));
            res+=Greater[i]*sum(x-1);
            // ÿ����һ�������Ͱ�ai���뵽������ȥ���൱����ai���λ����+1
            add(x,1);
        }
        return res;
    }


};
