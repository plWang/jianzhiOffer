void Mirror(TreeNode* pRoot) {
    if (pRoot == NULL) return NULL;

    if (pRoot->left || pRoot->right) {
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
    }
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}