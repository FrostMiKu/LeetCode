/**
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 * 好久没有遇到一看就会一写就错的题了（
 * 列表有序，所以二分列表，中点是根，左边是左子树，右边是右子树
 * 递归建树就行了...
 * ps:用快慢指针确定链表中点
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* fastSlowPointer(ListNode* left, ListNode* right){
        if(left == right) return nullptr;

        ListNode *slow = left,*fast = left;

        while(fast != right && fast->next != right){
            slow = slow->next;
            fast = fast->next->next;
        }

        return new TreeNode(slow->val,fastSlowPointer(left,slow),fastSlowPointer(slow->next,right));
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return fastSlowPointer(head,nullptr);      
    }
};