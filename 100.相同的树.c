/**
 * https://leetcode-cn.com/problems/same-tree/
 * 休闲简单题，今天的题依旧是电风扇呢...
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr){
            if(q==nullptr){
                return true;
            }else{
                return false;
            }
        }else{
            if(q==nullptr) return false;
        }
        if((p->left==nullptr&&p->right==nullptr)&&(q->left==nullptr&&q->right==nullptr)){
            if(p->val == q->val){
                return true;
            }else{
                return false;
            }
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && q->val==p->val;
    }
};

// 有点丑优化一下代码
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr) return q==nullptr;
        return q!=nullptr && q->val==p->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

// 注意到上面那一行可以用三目运算符代替，一行解决
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return p==nullptr?q==nullptr:q!=nullptr && q->val==p->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};