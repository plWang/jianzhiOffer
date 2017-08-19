// solution 1: 断链法 
// 只适用于允许改变链表结构的问题

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if (pHead == NULL || pHead->next == NULL) return NULL;
    ListNode* pAhead = pHead->next;
    ListNode* pBehind = pHead;
    while (pAhead != NULL) {
        pBehind->next = NULL;
        pBehind = pAhead;
        pAhead = pAhead->next;
    }

    return pBehind;
}

// solution 2:
// 不允许改变链表结构时，
// 使用两个指针，都从头节点开始， 一个指针p1每次走1步，指针p2每次走两步，两个节点相遇的点一定在环内。

// 设x为环之前的距离，c为环的长度，a为环的入口到两指针相遇节点的长度
// 那么p1指针走过的路程为sSlow = x + n*c + a
// p2指针走过的路程为 sFast = x + m*c + a
// 2*sSlow = sFast
// 2 * (x+n*c + a) = x + m*c + a
// x = (2*n-m)*c - a = (2*n-m-1)*c + c-a
// 也就是说环之前的路程x等于整数倍的环的路程加上c-a， c-a即相遇节点到环入口节点的长度

// 那么将p2指针指向头结点，p1指针不动，然后两个指针以同样速度前进，
// 当p1指针走到环入口节点时，p2指针也一定指向环入口节点

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL) return NULL;
    ListNode* p1 = pHead->next;
    ListNode* p2 = pHead->next->next;
    while (p1 != p2) {
        if (p1->next) 
            p1 = p1->next;
        else 
            return NULL;

        if (p2->next && p2->next->next) 
            p2 = p2->next->next;
        else 
            return NULL;
    }

    p2 = pHead;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}