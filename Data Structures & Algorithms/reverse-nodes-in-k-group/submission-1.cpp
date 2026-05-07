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
//edgeCaseVals
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        
        ListNode* dummy = new ListNode(0,head);
        ListNode* lHp=dummy, *nHp=dummy, *newHd=head;
        bool reachEnd=0;
        while(!reachEnd){
            for(int i=0;i<k;i++){
                if(nHp!=nullptr) nHp=nHp->next;

                if(nHp==nullptr) {
                    reachEnd=1;
                    break;
                }
            }
            if(reachEnd) break;

            if(newHd==head) newHd=nHp; //first nHp
            ListNode* prev=nHp->next, *curr=lHp->next;
            for(int i=0;i<k;i++){
                ListNode* next=curr->next;
                curr->next = prev;
                prev=curr;
                curr=next;
            }

            ListNode* tmp = lHp->next;
            lHp->next = nHp;
            lHp = tmp, nHp=tmp;
        }
        return newHd;
    }
};
