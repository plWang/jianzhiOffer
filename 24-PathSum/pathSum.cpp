void backtrack(vector<vector<int> >& solutions, vector<int>& tempsol, int target, vector<TreeNode*>& path) {
    TreeNode* cur = path.back();
    if (cur->left == NULL && cur->right == NULL) {
        if (cur->val == target) {
            solutions.push_back(tempsol);
            return;
        }
        else {
            return;
        }
    }

    if (cur->left) {
        tempsol.push_back(cur->left->val);
        path.push_back(cur->left);
        backtrack(solutions, tempsol, target-cur->val, path);
        tempsol.pop_back();
        path.pop_back();
    }
    if (cur->right) {
        tempsol.push_back(cur->right->val);
        path.push_back(cur->right);
        backtrack(solutions, tempsol, target-cur->val, path);
        tempsol.pop_back();
        path.pop_back();
    }
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int> > solutions;
    if (root == NULL) return solutions;
    vector<int> tempsol;
    vector<TreeNode*> path;
    path.push_back(root);
    tempsol.push_back(root->val);
    backtrack(solutions, tempsol, expectNumber, path);

    return solutions;
}