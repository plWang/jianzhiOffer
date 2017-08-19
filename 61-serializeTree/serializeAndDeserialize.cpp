#include <iostream>
#include "stdio.h"
#include "string.h"
#include <string>

using namespace std;

// 先序遍历，递归的思想

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

string int2str(int num) {
    string s = "";
    int dvs = 10;
    int tmp = num;
    while (tmp/dvs != 0) {
        dvs *= 10;
    }
    dvs /= 10;

    while (dvs != 0) {
        int res = num/dvs;
        s.push_back(res + '0');
        num = num%dvs;
        dvs /= 10;
    }

    return s;
}

char* Serialize(TreeNode *root) {    //preorder travel
    if (root == NULL) return "#,";
    string s = int2str(root->val);
    s.push_back(',');
    char* left = Serialize(root->left);
    char* right = Serialize(root->right);
    char* result = new char[strlen(left)+strlen(right)+s.size()];
    strcpy(result, s.c_str());
    strcat(result, left);
    strcat(result, right);

    return result;
}

TreeNode* Deserialize(char *&str) {
    // if (*str == ',') str++;
    if (*str == '#') {
        str++;
        str++;
        return NULL;
    }
    char* begin = str;
    int num = 0;
    while (*(str)!=',' && *(str)!='\0') {
        num = num*10 + *(str++)-'0';
    }
    str++;
    TreeNode* t = new TreeNode(num);
    t->left = Deserialize(str);
    t->right = Deserialize(str);

    return t;
}

int main() {
    char* s = "8,6,#,#,10,#,#";
    TreeNode* root = Deserialize(s);
    char* str = Serialize(root);
    cout << str << endl;
    return 0;
}