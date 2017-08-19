bool isSameTree(TreeNode* t1, TreeNode* t2) {
    if (t2 == NULL) return true;
    if (t1 == NULL) return false;

    if (t1 && t2 && (t1->val == t2->val))
        return (isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right));
    else 
        return false;
}


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == NULL) return false;
    if (pRoot1 == NULL) return false;

    bool res = false;
    if (pRoot1->val == pRoot2->val)
        res = isSameTree(pRoot1, pRoot2);
    if (!res)
        res = HasSubtree(pRoot1->left, pRoot2);
    if (!res)
        res = HasSubtree(pRoot1->right, pRoot2);
    
    return res;
}