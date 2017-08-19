TreeNode* Convert(TreeNode* pRootOfTree) {
    if (pRootOfTree == NULL) return NULL;

    TreeNode* head;
    TreeNode* left = Convert(pRootOfTree->left);
    if (left) {
        head = left;
        TreeNode* cur = left;
        while (cur->right) {
            cur = cur->right;
        }
        cur->right = pRootOfTree;
        pRootOfTree->left = cur;
    }
    else {
        pRootOfTree->left = NULL;
        head = pRootOfTree;
    }


    TreeNode* right = Convert(pRootOfTree->right);
    if (right) {
        pRootOfTree->right = right;
        right->left = pRootOfTree;
    }
    else 
        pRootOfTree->right = NULL;

    return head;
}