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
private: 
    pair<ListNode*, ListNode*> reverseGroup(ListNode* start, ListNode* end) {
        ListNode* next = start->next, *cur = start;
        start->next = nullptr; 

        while (next != end) {
            // cout << cur->val << " ";
            ListNode* tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        // cout << endl;
        next->next = cur;
        return {end, start};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevLast = nullptr, *res = nullptr;
        if (k == 1) return head;
        for (ListNode* cur = head; cur != nullptr;) {
            ListNode* start = cur;
            bool stoppedEarly = false;
            for (int i = 1; i < k; i++) {
                cur = cur->next;
                if (cur == nullptr) {
                    stoppedEarly = true;
                    break;
                }
            }
            if (stoppedEarly) {
                if (prevLast != nullptr) {
                    prevLast->next = start;
                    return res;
                }
                else {
                    return start;
                }
            }
            ListNode* end = cur; 
            ListNode* nextCur = end->next;
            
            auto[newStart, newEnd] = reverseGroup(start, end);
            
            // cout << "NEW VALUES: " << newStart->val << " " << newEnd->val << endl;
            
            if (prevLast != nullptr) {
                prevLast->next = newStart;
            }
            
            prevLast = newEnd;
            
            if (res == nullptr) {
                res = newStart;
            } 
            
            if (nextCur == nullptr) {
                return res;
            }
            
            cur = nextCur;
        }

        return head;
    }
};
