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

    ListNode* find(ListNode* temp){
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(temp!=nullptr){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* hare = head;
        ListNode* tortoise = head;
        while(tortoise!=nullptr && tortoise->next!=nullptr && tortoise->next->next!=nullptr){
            tortoise = tortoise->next->next;
            hare = hare->next;
        }
        ListNode* head2 = find(hare->next);
        hare->next = nullptr;
        ListNode* head1 = head;
        bool check = true;
        ListNode* next = nullptr;
        while(head1!=nullptr || head2!=nullptr){
            // if true then connect head1 to head2
            if(check){
                next = head1->next;
                head1->next = head2;
                head1 = next;
            }
            // if false then connect head2 to head1
            else{
                next = head2->next;
                head2->next = head1;
                head2 = next;
            }
            check = !check;
        }

    }
};
