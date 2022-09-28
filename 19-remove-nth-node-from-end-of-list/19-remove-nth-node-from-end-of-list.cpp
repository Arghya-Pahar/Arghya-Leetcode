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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end=head;
        
        int len=1;
        while(end->next!=NULL)
        {
            end=end->next;
            len++;
        }
        end=head;
        int remv=len-n+1;
        if(remv==1)
        {
            head=head->next;
            return head;
        }
        ListNode* prev,*update;
        for(int i=1;i<remv-1;i++)
        {
            end=end->next;
        }
        prev=end;
        update=prev->next->next;
        prev->next=update;
        return head;
        
        
    }
};