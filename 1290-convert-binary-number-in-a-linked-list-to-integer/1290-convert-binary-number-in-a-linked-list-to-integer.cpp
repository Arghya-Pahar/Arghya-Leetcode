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
    int getDecimalValue(ListNode* head) {
        int len=0;
        ListNode* head1=head;
        ListNode* head2=head;
        while(head2!=NULL)
        {
            len++;
            head2=head2->next;
        }
        int res=0;
        for(int i=len-1;i>=0;i--)
        {
            res=res+head1->val*pow(2,i);
            head1=head1->next;
        }
        return res;
    }
};