#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* Clone(RandomListNode* pHead) {
    if (pHead == NULL) return NULL;
    if (pHead->next == NULL) {    //如果只有头结点，只需复制头结点
        RandomListNode* p = new RandomListNode(pHead->label);
        p->next = pHead->next;
        p->random = pHead->random;
        return p;
    }

    RandomListNode* cur = pHead;
    // 1. 复制每个结点，将复制的节点接在原节点后面，random节点设为空
    while (cur) {
        RandomListNode* p = new RandomListNode(cur->label);
        p->next = cur->next;
        p->random = NULL;
        cur->next = p;
        cur = p->next;
    }

    cur = pHead;
    // 2. 设置random指针
    while (cur) {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    // 3. 拆成两个链表
    RandomListNode* res = pHead->next;
    RandomListNode* pClone = res;
    cur = pHead;
    while (cur) {
        cur->next = pClone->next;
        cur = cur->next;
        if (cur)
            pClone->next = cur->next;
        else pClone->next = NULL;
        pClone = pClone->next;
    }

    return res;

}

int main() {
    RandomListNode* root = new RandomListNode(0);
    root->next = new RandomListNode(1);
    root->next->next = new RandomListNode(2);

    RandomListNode* clone = Clone(root);
    RandomListNode* cur = clone;
    while (cur) {
        cout << cur->label << " ";
        cur = cur->next;
    }
    cout << endl;

}