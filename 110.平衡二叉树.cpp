/**
 * https://leetcode-cn.com/problems/balanced-binary-tree/
 * 递归就是归纳证明！不过下面这个是 自顶向下 递归的...不是好的解决方法！（自底向上合成明显更优
 * 简要说明一下 自顶向下 的归纳证明：
 * 对于 nullptr 显然是平衡的.
 * 如果一个 树 平衡，则它的 左子树 和 右子树 是平衡的。
 * ∎
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int height(TreeNode* node){
        if(node == nullptr) return 0;
        return fmax(height(node->left) ,height(node->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(abs(height(root->left)-height(root->right))<=1){
            return isBalanced(root->left)&&isBalanced(root->right);
        }
        return false;
    }
};