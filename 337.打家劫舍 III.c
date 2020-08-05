/**
 * https://leetcode-cn.com/problems/house-robber-iii/
 * 第一次提交居然超时了（稍微剪一下支卡着时间过了 :(
 * 这小偷这么有才华怕不是去偷算法书的 （手动滑稽
 *
 * f(x):当前节点选中  g(x):当前节点不选
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define nullptr 0

int g(struct TreeNode* x);

int f(struct TreeNode* x){
    if(x == nullptr){
        return 0;
    }
    if(x->right==nullptr && x->left==nullptr) return x->val; //剪枝
    return g(x->left) + g(x->right) + x->val;
}

int g(struct TreeNode* x){
    if(x == nullptr || (x->right==nullptr && x->left==nullptr)){
        return 0;
    }
    return fmax(f(x->left),g(x->left)) + fmax(f(x->right),g(x->right));
}

int rob(struct TreeNode* root){
    return fmax(g(root),f(root));
}