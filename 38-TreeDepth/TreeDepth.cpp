int TreeDepth(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    else return max(TreeDepth(root-left), TreeDepth(root-right))+1;
}