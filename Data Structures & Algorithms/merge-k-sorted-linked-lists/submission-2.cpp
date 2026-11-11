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
    static bool compare(ListNode* l1, ListNode* l2) {
        return l1->val < l2->val;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* cur = nullptr, *head = nullptr;

        vector<ListNode*> arr;

        for (auto l : lists) {
            if (l != nullptr) {
                arr.push_back(l);
            }
        }

        while (arr.size() != 0) {
            sort(arr.begin(), arr.end(), compare);
            int v = arr[0]->val;
            for (int i = 0; i < arr.size() && v == arr[i]->val; i++) {            
                ListNode* tmp = new ListNode(v);
                
                if (cur == nullptr) {
                    cur = tmp;
                    head = tmp;
                } 
                else {
                    cur->next = tmp;
                    cur = tmp;
                }

                if (arr[i]->next == nullptr) {
                    arr.erase(arr.begin() + i);
                    i--;
                }
                else {
                    arr[i] = arr[i]->next;
                }
            }
        }

        return head;
    }
};
