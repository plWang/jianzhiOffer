#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> result;
    if (root == NULL) return result;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
        result.push_back(cur->val);
    }

    return result;
}