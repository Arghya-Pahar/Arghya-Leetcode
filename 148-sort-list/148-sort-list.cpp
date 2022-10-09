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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        ListNode *head;
        if(list1->val>list2->val)
        {
            swap(list1,list2);
        }
        head=list1;
        while(list1!=NULL &&list2!=NULL)
        {
            ListNode *temp=NULL;
            while(list1!=NULL && list1->val<=list2->val)
            {
                temp=list1;
                list1=list1->next;
                
            }
            temp->next=list2;
            swap(list1,list2);
        }
        return head;
        
            
        
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *temp=NULL;
        while(fast && fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        ListNode *answer=mergeTwoLists(l1,l2);
        return answer;
    }
};