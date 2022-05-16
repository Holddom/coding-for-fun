//标志递归法 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//struct TreeNode* inordertraversal(struct TreeNode* root, struct TreeNode*p ,int flag)

int flag=0;
struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p){
    if(root==NULL)
    return NULL;
    struct TreeNode* ret=NULL;
    if(ret==NULL)
    ret=inorderSuccessor(root->left,p);
    if(root==p)
    {
        flag=1;
        if(root->right!=NULL)
        {
            struct TreeNode* node=root->right;
            while(node->left!=NULL)
            {
                node=node->left;
            }
            flag=0;
            return node;
        }
        else
        return NULL;
    }
    if(ret==NULL&&flag==0)
    ret=inorderSuccessor(root->right,p);
    if(flag==1)
    {
        if(p->val<root->val)
        {
            flag=0;
            return root;
        }
    }
    return ret;
}


//BST性质

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p){
    struct TreeNode* ret=NULL;
    if(p->right!=NULL)
    {
        struct TreeNode* node=p->right;
        while(node!=NULL)
        {
            ret=node;
            node=node->left;
        }
        return ret;
    }
    struct TreeNode* node=root;
    while(node!=NULL)
    {
        if(node->val>p->val)
        {
            ret=node;
            node=node->left;
        }
        else
        node=node->right;
    }
    return ret;
}

 
