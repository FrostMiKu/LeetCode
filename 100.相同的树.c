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