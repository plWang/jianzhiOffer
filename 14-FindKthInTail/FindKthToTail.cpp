ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == NULL || k <= 0) return NULL;
    ListNode* pAhead = pListHead;
    ListNode* pBehind = pListHead;
    for (int i=0; i<k; i++) {
        if (pAhead) pAhead = pAhead->next;
        else return NULL;
    }

    while (pAhead) {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;

}