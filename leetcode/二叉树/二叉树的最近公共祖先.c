/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == q || root == p)          //如果该结点为空，或者本就是q，p，那么返回
        return root;                                    //这个判断包括了一个结点是他本身和他子树的公共祖先的情况
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);   // 搜索该节点的右子树 有可能搜索到目标或到叶子节点
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)     //如果左右子树各有一个 则其为公共祖先
        return root;


    return left != NULL ? left : right;  //若两个子树中只有一个有目标节点 那么返回有的那个子树  也有可能都没有

}
