/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head) {

    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = head;  //����ͷ���
    struct ListNode* pre = newhead;; //��������Ĳ���
    struct ListNode* p = newhead->next;//����ά���Ѿ��ź��������
    struct ListNode* q = p->next;         //δ�����
    struct ListNode* m = q->next;         //����δ���������
    p->next = NULL;  //�ϵ�
    while (q)
    {
        q->next = NULL;  //�ϵ�
        pre = newhead;
        p = newhead->next;
        while (p != NULL && q->val > p->val)
        {
            pre = p;
            p = p->next;
        }
        pre->next = q;
        q->next = p;
        q = m;
        if (m != NULL)
            m = m->next;
    }
    return newhead->next;


}
