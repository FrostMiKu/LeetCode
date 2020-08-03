/**
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define nullptr 0

struct TreeNode* last = nullptr;

void dg(struct TreeNode* root){
    if (root == nullptr) return;
    dg(root->right);
    dg(root->left);
    root->right = last;
    root->left = nullptr;
    last = root;
}

void flatten(struct TreeNode* root) {
    last = nullptr;
    dg(root);
}