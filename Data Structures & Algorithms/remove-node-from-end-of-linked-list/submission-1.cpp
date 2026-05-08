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
//return N
//ptr N
//infLoop N
//idxErr N
//oneOff N
//edgeVals N
    int len(ListNode* head){
        int cnt=0;
        while(head) head=head->next, cnt++;
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = len(head);
        if(!head) return nullptr;
        else if(m==n) return head->next;
        
        ListNode* curr=head;
        int cnt=m-n-1;
        while(curr && (cnt-->0)) curr=curr->next;
        curr->next = (curr->next)?curr->next->next:nullptr;
        return head;
    }
};
