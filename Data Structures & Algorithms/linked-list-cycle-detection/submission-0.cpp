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
    bool hasCycle(ListNode* head) {
        if(head==nullptr || head->next == nullptr || head->next->next==nullptr) return false;
        ListNode* rabbit = head;
        ListNode* tortoise = head;
        rabbit = rabbit->next->next;
        tortoise = tortoise->next;
        while(rabbit!=tortoise && rabbit!=nullptr && tortoise!=nullptr){
            if(rabbit->next==nullptr) return false;
            rabbit = rabbit->next->next;
            tortoise = tortoise->next;
        }
        if(rabbit==nullptr||tortoise==nullptr) return false;
        return true;
    }
};
