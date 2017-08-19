/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if (pNode->right) {
        TreeLinkNode* cur = pNode->right;
        while (cur->left) cur = cur->left;
        return cur;
    }
    else {
        TreeLinkNode* father = pNode->next;
        if (father) {
            if (pNode == father->left) return father;
            else {
                TreeLinkNode* cur = father;
                while (cur->next) {
                    father=cur->next;
                    if (father && cur == father->left) return father;
                    else cur = father;
                }
                return NULL;
            }
        }
        else return NULL;
    }
}