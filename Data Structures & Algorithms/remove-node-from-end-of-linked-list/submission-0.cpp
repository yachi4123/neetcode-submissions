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

    int find(ListNode* temp){
        int len = 0;
        while(temp!=nullptr){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = find(temp);
        int node = len-n+1;
        ListNode* prev = nullptr;
        ListNode* temp2 = head;
        for(int i = 1;i<node;i++){
            prev = temp2;
            temp2 = temp2->next;
        }
        if(temp2==head){
            return temp2->next;
        }
        prev->next = temp2->next;
        temp2->next = nullptr;
        return head;
    }
};
