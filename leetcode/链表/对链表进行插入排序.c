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
    newhead->next = head;  //虚拟头结点
    struct ListNode* pre = newhead;; //用于链表的插入
    struct ListNode* p = newhead->next;//用来维护已经排好序的链表
    struct ListNode* q = p->next;         //未排序的
    struct ListNode* m = q->next;         //保存未排序的链表
    p->next = NULL;  //断掉
    while (q)
    {
        q->next = NULL;  //断掉
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
