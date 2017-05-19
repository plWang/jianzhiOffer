RandomListNode* Clone(RandomListNode* pHead) {
    if (pHead == NULL) return NULL;
    if (pHead->next == NULL) {
        RandomListNode* p = new RandomListNode(pHead->label);
        p->next = pHead->next;
        p->random = pHead->random;
        return p;
    }

    RandomListNode* cur = pHead;
    while (cur) {
        RandomListNode* p = new RandomListNode(cur->label);
        p->next = cur->next;
        p->random = NULL;
        cur = p->next;
    }

    cur = pHead;
    RandomListNode* res = pHead->next;
    
    while (cur) {
        RandomListNode* p = cur->next;
        if (cur->random)
            p->random = cur->random->next;
        cur = p->next;
    }

    RandomListNode* pClone = res;
    cur = pClone->next;
    while (cur) {
        pClone->next = cur->next;
        pClone = pClone->next;
        cur->next = pClone->next;
        cur = cur->next;

    }

    return res;

}