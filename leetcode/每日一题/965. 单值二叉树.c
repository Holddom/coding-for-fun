/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool search(struct TreeNode* root , int same)
{
    if(root==NULL)
    return true;
    if(root->val!=same)
    return false;
    
    return search(root->left,same)&&search(root->right,same);

}
bool isUnivalTree(struct TreeNode* root){
    int same=root->val;
    return search(root,same);
}

