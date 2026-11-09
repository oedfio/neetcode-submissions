/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* h = nullptr;

        Node* cur = nullptr;

        unordered_map<int, int> indexes;
        unordered_map<int, Node*> nodes;
        unordered_map<Node*, int> memory;

        int idx = 0;
        
        memory[nullptr] = -1;

        for (Node* i = head; i != nullptr; i = i->next) {
            memory[i] = idx++;
        }

        idx = 0;
        
        for (Node* i = head; i != nullptr; i = i->next) {
            if (!cur) {
                cur = new Node(i->val);
                h = cur;
            }
            else {
                Node* tmp = new Node(i->val);
                cur->next = tmp;
                cur = tmp;
            }
            indexes[idx] = memory[i->random];
            nodes[idx] = cur;
            idx++;
        }
        idx = 0;
        for (Node* i = h; i != nullptr; i = i->next) {
            i->random = indexes[idx] == -1 ? nullptr : nodes[indexes[idx]];
            idx++;
        }

        return h;
    }
};
