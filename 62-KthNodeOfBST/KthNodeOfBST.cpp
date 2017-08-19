#include <iostream>
#include <stack>

using namespace std;

int count = 0;

// 先序遍历的思想，二叉搜索树的先序遍历序列是有序的
TreeNode* KthNode(TreeNode* pRoot, int k) {
    if (pRoot == NULL) return NULL;
    TreeNode* left = KthNode(pRoot->left, k);
    if (left) return left;
    if (++count == k) return pRoot;
    TreeNode* right = KthNode(pRoot->right, k);
    if (right) return right;
}