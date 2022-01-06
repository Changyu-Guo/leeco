//
// Created by gcy on 2022/1/6.
//

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> generateTrees(int start, int end) {
    if (start > end) {
        return {nullptr};
    }
    vector<TreeNode*> allTrees;
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
        vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

        for (auto& left: leftTrees) {
            for (auto& right: rightTrees) {
                TreeNode* curTree = new TreeNode(i);
                curTree->left = left;
                curTree->right = right;
                allTrees.emplace_back(curTree);
            }
        }
    }
    return allTrees;
}

vector<TreeNode*> generateTrees(int n) {
    if (!n) {
        return {};
    }
    return generateTrees(1, n);
}

int main() {
    vector<TreeNode*> res;
    res = generateTrees(3);
    for (auto& x: res) {
        cout << x->val << endl;
    }
    return 0;
}
