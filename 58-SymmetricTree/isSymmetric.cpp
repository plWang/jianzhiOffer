#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

bool isSymmetric(TreeNode* pRoot) {
    queue<TreeNode*> q;
    q.push(pRoot);
    q.push(pRoot);
    while (!q.empty()) {
        TreeNode* p1 = q.front();
        q.pop();
        TreeNode* p2 = q.front();
        q.pop();
        if (p1->val == p2->val) {
            if (p1->left && p2->right) {
                q.push(p1->left);
                q.push(p2->right);
            }
            else if (p1->left || p2->right) return false;

            if (p1->right && p2->left) {
                q.push(p1->right);
                q.push(p2->left);
            }
            else if (p1->right || p2->left) return false;

        }
    }

    return true;
}

int main() {
    return 0;
}