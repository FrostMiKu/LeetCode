/**
 * https://leetcode-cn.com/problems/recover-binary-search-tree/
 * 中序遍历有真相，发现自己递归写多了不会写迭代了QAQ
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pre = nullptr;

        while(!s.empty()||root!=nullptr){
            while (root!=nullptr){
                s.push(root);
                root=root->left;
            }
            root = s.top();
            s.pop();
            if(pre!=nullptr&&pre->val>root->val){
                y=root;
                if(x==nullptr){
                    x=pre;
                }
                else break;
            }
            pre = root;
            root = root->right;
        }
        swap(x->val,y->val);
    }
};