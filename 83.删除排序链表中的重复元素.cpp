/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* l = nullptr;
    ListNode* r = nullptr;

    ListNode* getNext(ListNode* n) {
        if (n->next == nullptr || (n->next->val != n->val))
        {
            return n->next;
        }
        return getNext(n->next);
    }

    ListNode* deleteDuplicates(ListNode* head) {
        l = r = head;
        while (r!=nullptr)
        {
            r = getNext(r);
            l->next = r;
            l = r;
        }
        return head;
    }
};
// @lc code=end

