class Solution {
public:
int dfs(TreeNode* root,int val)
{
    if(root==nullptr)
    return 0;
    val=(val<<1)|root->val;
    if(root->left==nullptr&&root->right==nullptr)
    {
        return val;
    }
    return dfs(root->left,val)+dfs(root->right,val);
}
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};


//相当于后序遍历 
