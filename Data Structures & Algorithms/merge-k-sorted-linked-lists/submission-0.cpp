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
//return N
//ptr N
//infLoop ?
//idxErr N
//oneOff N
//edgeVals N
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr, *curr=head;
        bool update=1;
        while(update){
            int mini=INT_MAX;
            ListNode** mini_ptr=nullptr;
            for(auto &ptr:lists){
                if(ptr!=nullptr && ptr->val < mini) mini=ptr->val, mini_ptr=&ptr;
            }
            update = (mini_ptr!=nullptr);
            if(!update) break;


            //add in new list
            if(head==nullptr) head=*mini_ptr;
            else curr->next = *mini_ptr;
            curr=*mini_ptr;
            
            (*mini_ptr)=(*mini_ptr)->next; //increment ptr in orig list
        }
        return head;
    }
};