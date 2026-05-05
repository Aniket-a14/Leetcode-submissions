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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(k==0) return head;
        ListNode* temp = head;
        int total = 1;

        while(temp->next!=NULL){
            total++;
            temp = temp->next;
        }

        temp->next = head;

        k%=total;
        total -= k;

        temp = head;
        ListNode* curr = head;

        while(total--){
            temp = curr;
            curr = curr->next;
        }

        temp->next = NULL;
        return curr;
    }
};