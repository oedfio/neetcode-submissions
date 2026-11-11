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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, *cur = nullptr;
        int v_l1 = 0, v_l2 = 0, c = 0;
        while (l1 != nullptr || l2 != nullptr) {
            v_l1 = l1 == nullptr ? 0 : l1->val;
            v_l2 = l2 == nullptr ? 0 : l2->val;

            ListNode* tmp = new ListNode((v_l1 + v_l2 + c) % 10);
            c = (v_l1 + v_l2 + c) / 10;

            if (cur == nullptr) {
                cur = tmp;
                head = cur;
            } 
            else {
                cur->next = tmp;
                cur = tmp;
            }

            v_l1 = 0;
            v_l2 = 0;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }

        if (c != 0) {
            cur->next = new ListNode(c);
        }

        return head;
    }
};
