#include <iostream>
#include <stack>

int dfs(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    int leftHeight = dfs(root->left);
    int rightHeight = dfs(root->right);
    if (left == -1 || rightHeight == -1) return -1;
    if (fabs(leftHeight - rightHeight) > 1) return -1;
    else return max(leftHeight, rightHeight)+1;
}

bool IsBalanced_Solution(TreeNode* root) {
    if (root == NULL) return false;
    if (dfs(root) != -1) return true;
    else return false;
}