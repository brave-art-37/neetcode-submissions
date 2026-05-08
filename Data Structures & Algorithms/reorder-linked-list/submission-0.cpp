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
    ListNode* reverse(ListNode* head){
        if(!head) return nullptr;

        ListNode* prev=nullptr, *curr=head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int len(ListNode* head){
        if(!head) return 0;

        int cnt=0;
        while(head) head=head->next, cnt++;
        return cnt;
    }

    void reorderList(ListNode* head) {
        int n = len(head), m = n/2;
        if(n<3) return;

        ListNode* head1 = head, *head2 = head;

        //split into 2 halves
        while(head2 && (m-->0)) head2 = head2->next;
        ListNode* last=head2;
        if(head2) head2=head2->next;
        if(last) last->next = nullptr;

        head2 = reverse(head2);

        ListNode dummy(0);
        ListNode* curr=&dummy;
        for(int i=0;i<n;i++){
            if(i%2==0 && head1) curr->next = head1, head1=head1->next;
            else if(i%2==1 && head2) curr->next = head2, head2=head2->next;
            curr = (curr->next)?curr->next:curr;
        }
    }
};
