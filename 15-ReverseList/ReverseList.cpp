ListNode* ReverseList(ListNode* pListHead) {
    if (pListHead == NULL) return NULL;
    if (pListHead->next == NULL) return pListHead;

    ListNode* pPre =  NULL;
    ListNode* pCur = pListHead;
    ListNode* pNext;

    while (pCur) {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;

        pCur = pNext;
    }

    return pPre;
}