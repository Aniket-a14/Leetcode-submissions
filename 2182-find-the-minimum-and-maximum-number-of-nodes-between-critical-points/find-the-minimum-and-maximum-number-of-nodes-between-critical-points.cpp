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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;

        ListNode* first = head;
        ListNode* second = head->next;
        if(second->next==NULL) return {-1,-1};
        ListNode* third = head->next->next;

        int count = 1;

        while(third){
            if(second->val>first->val && second->val>third->val){
                ans.push_back(count);
            }else if(second->val<first->val && second->val<third->val){
                ans.push_back(count);
            }

            third = third->next;
            second = second->next;
            first = first->next;
            count++;
        }

        if(ans.size()<2) return {-1,-1};

        int maxi = ans[ans.size()-1]-ans[0];
        int mini = INT_MAX;

        for(int i=1;i<ans.size();i++){
            mini = min(mini,ans[i]-ans[i-1]);
        }

        return {mini,maxi};
    }
};