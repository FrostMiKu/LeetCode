/**
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
    queue<TreeNode *> fifo;
    queue<TreeNode *> fifo_odd;
    bool bfs(bool is_odd){
        if(is_odd)
        {
            if(fifo_odd.empty()) return true;
            int val = 0;
            while(!fifo_odd.empty()){                
                TreeNode* node = fifo_odd.front();
                fifo_odd.pop();
                if(node == nullptr) continue;
                if((node->val&0x1) == 1 && val < node->val)
                {
                    val = node->val;
                    fifo.push(node->left);
                    fifo.push(node->right);
                }else return false;
            }
            return bfs(false);
        }else{
            if(fifo.empty()) return true;
            int val = 1000000+1;
            while(!fifo.empty()){
                TreeNode* node = fifo.front();
                fifo.pop();
                if(node == nullptr) continue;
                if((node->val&0x1) == 0 && val > node->val)
                {
                    val = node->val;
                    fifo_odd.push(node->left);
                    fifo_odd.push(node->right);
                }else return false;
            }
            return bfs(true);
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        fifo_odd.push(root);
        return bfs(true);
    }
};
