/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    int t[201] = {0};
    ListNode* l = nullptr;
    ListNode* r = nullptr;

    ListNode* getNext(ListNode* n) {
        if (n->next == nullptr || (n->next->val != n->val))
        {
            return n->next;
        }
        t[n->val + 100]++;
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
        l = r = head;
        while(r!=nullptr){
            if (t[r->val+100])
            {
                if(r == head){
                    head = r->next;
                    l = r = head;
                }else{
                    r = r->next;
                    l->next = r;
                }
            }else{
                l = r;
                r = r->next;
            }
            
        }
        return head;
    }
};
// @lc code=end

