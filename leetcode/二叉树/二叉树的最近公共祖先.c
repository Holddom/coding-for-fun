/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == q || root == p)          //����ý��Ϊ�գ����߱�����q��p����ô����
        return root;                                    //����жϰ�����һ���������������������Ĺ������ȵ����
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);   // �����ýڵ�������� �п���������Ŀ���Ҷ�ӽڵ�
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)     //���������������һ�� ����Ϊ��������
        return root;


    return left != NULL ? left : right;  //������������ֻ��һ����Ŀ��ڵ� ��ô�����е��Ǹ�����  Ҳ�п��ܶ�û��

}
