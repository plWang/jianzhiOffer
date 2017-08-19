ListNode* deleteDuplication(ListNode* pHead) {
    ListNode* cur = pHead;
    ListNode* pre = new ListNode(0);
    pre->next = pHead;
    bool dup = false;
    while (cur) {
        dup = false;
        while (cur->next && cur->next->val == cur->val) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            dup = true;
        }
        if (dup) {
            ListNode* tmp = cur;
            pre->next = cur->next;
            if (cur == pHead) pHead = cur->next;
            cur = cur->next;
            delete tmp;
        }
        else {
            cur = cur->next;
            pre = pre->next;
        }
    }

    return pHead;
}