class NumArray {

    vector<int> tree;
    vector<int> num;
    int n;
    int lowbit(int x)
    {
        return x&(-x);
    }
    int query(int x)
    {
        int ans=0;
        for(int i=x;i>0;i-=lowbit(i))   ans+=tree[i];
        return ans;
    }
    void add(int x,int val)
    {
        for(int i=x;i<=n;i+=lowbit(i))  tree[i]+=val;
    }
    public:
    NumArray(vector<int>& nums) {
        int len=nums.size();
        num=nums;
        n=len;
        tree.resize(len+1,0);
        for(int i=0;i<len;i++) add(i+1,nums[i]);
    }
    
    void update(int index, int val) {
        add(index+1,val-num[index]);
        num[index]=val;
    }
    
    int sumRange(int left, int right) {
        return query(right+1)-query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

