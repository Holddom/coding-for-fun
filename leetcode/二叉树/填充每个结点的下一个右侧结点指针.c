/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
void dfs(struct Node* left, struct Node* right)
{
    if (left == NULL || left->next == right)
        return;
    left->next = right;
    dfs(left->left, left->right);
    dfs(left->right, right->left);
    dfs(right->left, right->right);
}
struct Node* connect(struct Node* root) {
    if (root != NULL)
        dfs(root->left, root->right);
    return root;
}
