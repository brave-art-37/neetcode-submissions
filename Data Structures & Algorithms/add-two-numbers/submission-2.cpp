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
//infLoops N
//idxErr N
//oneOff N
//edgeVals N
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr, *curr=head;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        else if(l2==nullptr) return l1;
        ListNode* l3 = nullptr, *curr=nullptr;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr){
            int sum=carry;
            if(l1!=nullptr) sum+=l1->val, l1=l1->next;
            if(l2!=nullptr) sum+=l2->val, l2=l2->next;
            carry = sum/10;
            sum=sum%10;
            //create new Node and add to existing list
            ListNode* newNode = new ListNode(sum);
            if(l3==nullptr) l3=newNode;
            else curr->next = newNode;
            curr = newNode;
        }
        if(carry!=0){
            ListNode* newNode = new ListNode(carry);
            if(l3==nullptr) l3=newNode;
            else curr->next = newNode;
            curr = newNode;
        }
        return l3;
    }
};
