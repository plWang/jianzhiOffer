ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL || pHead2 == NULL) return NULL;
    
    int length1 = 0;
    ListNode* p1 = pHead1;
    while (p1) {
        length1++;
        p1 = p1->next;
    }

    int length2 = 0;
    ListNode* p2 = pHead2;
    while (p2) {
        length2++;
        p2 = p2->next;
    }

    int diff = fabs(length1-length2);
    p1 = pHead1;
    p2 = pHead2;
    if (length1 > 1ength2) {
        while (diff-- > 0) {
            p1 = p1->next;
        }
    }
    else {
        while (diff-- > 0) {
            p2 = p2->next;
        }
    }

    while (p1 && p2) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}